/**
 * ========================================================================================
 * SLOT 2: TRANSAKSI PENJUALAN & IMPLEMENTASI UNION (MENU 7, MENU 2, MENU 4)
 *
 * MODE 1 - STANDALONE (default, untuk uji sendiri):
 *     gcc slot_2_transaksi_full.c -o slot_2_transaksi
 *
 * MODE 2 - DIGABUNG KE PROYEK TIM (tipe & fungsi slot lain sudah ada):
 *     gcc -DPROJECT_BUILD *.c -o toko_buku
 *   -> Bagian "STANDALONE" di bawah otomatis dilewati.
 * ========================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX_HISTORY
#define MAX_HISTORY 1000
#endif

/* ========================================================================================
 *  BAGIAN STANDALONE  (dilewati bila -DPROJECT_BUILD)
 * ====================================================================================== */
#ifndef PROJECT_BUILD

typedef enum { PAYMENT_CASH = 1, PAYMENT_QRIS = 2 } PaymentType;

typedef union {
    double cashReceived;
    char   transactionRef[25];
} PaymentDetail;

typedef struct {
    char          bookCode[10];
    int           quantity;
    double        totalPrice;
    PaymentType   payType;
    PaymentDetail detail;
} TransactionHistory;

/* Asumsi struct Book - sesuaikan dengan milik tim */
typedef struct {
    char   code[10];
    char   title[50];
    double price;
    int    stock;
} Book;

/* --- Pengganti fungsi slot lain --- */
int searchBookByCodeRecursive(const Book books[], int index, int size, const char *code) {
    if (index >= size) return -1;
    if (strcmp(books[index].code, code) == 0) return index;
    return searchBookByCodeRecursive(books, index + 1, size, code);
}

double calculateTotalRevenueRecursive(const TransactionHistory h[], int n) {
    if (n <= 0) return 0.0;
    return h[n - 1].totalPrice + calculateTotalRevenueRecursive(h, n - 1);
}

static void writeRecord(FILE *fp, const TransactionHistory *h) {
    fprintf(fp, "%s|%d|%.2f|%d|", h->bookCode, h->quantity, h->totalPrice, (int)h->payType);
    if (h->payType == PAYMENT_CASH) fprintf(fp, "%.2f\n", h->detail.cashReceived);
    else                            fprintf(fp, "%s\n", h->detail.transactionRef);
}

void appendTransactionToFile(const char *path, const TransactionHistory *h) {
    FILE *fp = fopen(path, "a");
    if (!fp) { printf("[WARNING] Gagal membuka %s untuk ditulis.\n", path); return; }
    writeRecord(fp, h);
    fclose(fp);
}

void saveAllHistoryToFile(const char *path, const TransactionHistory h[], int n) {
    FILE *fp = fopen(path, "w");
    if (!fp) { printf("[WARNING] Gagal menulis ulang %s.\n", path); return; }
    for (int i = 0; i < n; i++) writeRecord(fp, &h[i]);
    fclose(fp);
}

void loadHistoryFromFile(const char *path, TransactionHistory h[], int *count) {
    FILE *fp = fopen(path, "r");
    if (!fp) return;
    char line[256];
    while (*count < MAX_HISTORY && fgets(line, sizeof line, fp)) {
        TransactionHistory t;
        memset(&t, 0, sizeof t);
        int type;
        char detailStr[64] = "";
        if (sscanf(line, "%9[^|]|%d|%lf|%d|%63[^\n]",
                   t.bookCode, &t.quantity, &t.totalPrice, &type, detailStr) < 4)
            continue;
        t.payType = (PaymentType)type;
        if (t.payType == PAYMENT_CASH) t.detail.cashReceived = atof(detailStr);
        else strncpy(t.detail.transactionRef, detailStr, sizeof t.detail.transactionRef - 1);
        h[(*count)++] = t;
    }
    fclose(fp);
}

#endif /* PROJECT_BUILD */

/* ========================================================================================
 *  HELPER INPUT (static)
 * ====================================================================================== */
static void s2ReadLine(const char *prompt, char *buf, size_t size) {
    printf("%s", prompt);
    if (!fgets(buf, (int)size, stdin)) { buf[0] = '\0'; return; }
    buf[strcspn(buf, "\n")] = '\0';
}

static int s2ReadInt(const char *prompt, int *out) {
    char line[64], extra;
    s2ReadLine(prompt, line, sizeof line);
    return sscanf(line, "%d %c", out, &extra) == 1;
}

static int s2ReadDouble(const char *prompt, double *out) {
    char line[64], extra;
    s2ReadLine(prompt, line, sizeof line);
    return sscanf(line, "%lf %c", out, &extra) == 1;
}

/* ========================================================================================
 *  MENU 7: INPUT TRANSAKSI PENJUALAN
 * ====================================================================================== */
void handleInputTransaction(const Book books[], int bookCount,
                            TransactionHistory histories[], int *historyCount) {
    printf("\n=======================================================\n");
    printf("               INPUT TRANSAKSI PENJUALAN\n");
    printf("=======================================================\n");

    if (bookCount == 0) {
        printf("[ERROR] Belum ada data buku di katalog! Silakan input buku terlebih dahulu di Menu 1.\n");
        return;
    }
    if (*historyCount >= MAX_HISTORY) {
        printf("[ERROR] Kapasitas riwayat transaksi penuh (%d)!\n", MAX_HISTORY);
        return;
    }

    /* Input kode buku & pencarian */
    char targetCode[32];
    s2ReadLine("Kode Buku (contoh: BK001) : ", targetCode, sizeof targetCode);

    int idx = searchBookByCodeRecursive(books, 0, bookCount, targetCode);
    if (idx == -1) {
        printf("[ERROR] Kode buku tidak ditemukan di katalog!\n");
        return;
    }
    const Book *selectedBook = &books[idx];

    /* Input jumlah */
    int qty;
    if (!s2ReadInt("Jumlah Terjual           : ", &qty) || qty < 1) {
        printf("[ERROR] Jumlah harus bilangan bulat >= 1! Transaksi dibatalkan.\n");
        return;
    }

    double total = (double)qty * selectedBook->price;
    printf("Total Harga               : %.2f\n", total);

    /* Siapkan record (memset agar union bersih) */
    TransactionHistory trans;
    memset(&trans, 0, sizeof trans);
    TransactionHistory *newTrans = &trans;

    strncpy(newTrans->bookCode, selectedBook->code, sizeof newTrans->bookCode - 1);
    newTrans->quantity   = qty;
    newTrans->totalPrice = total;

    /* Metode pembayaran (UNION) */
    int method;
    printf("Metode Pembayaran:\n  [1] Tunai (Cash)\n  [2] Non-Tunai / QRIS\n");
    if (!s2ReadInt("Pilih metode [1-2]       : ", &method) || (method != 1 && method != 2)) {
        printf("[ERROR] Metode pembayaran tidak valid! Transaksi dibatalkan.\n");
        return;
    }

    if (method == PAYMENT_CASH) {
        double cash;
        newTrans->payType = PAYMENT_CASH;
        while (1) {
            if (!s2ReadDouble("Uang diterima (0=batal)   : ", &cash) || cash < 0) {
                printf("[ERROR] Input nominal tidak valid.\n");
                continue;
            }
            if (cash == 0) {
                printf("Transaksi dibatalkan.\n");
                return;
            }
            if (cash < total) {
                printf("[ERROR] Uang kurang %.2f. Silakan coba lagi.\n", total - cash);
                continue;
            }
            break;
        }
        newTrans->detail.cashReceived = cash;
        printf("Kembalian                 : %.2f\n", cash - total);
    } else {
        char ref[64];
        newTrans->payType = PAYMENT_QRIS;
        s2ReadLine("Kode Ref Transaksi        : ", ref, sizeof ref);
        if (ref[0] == '\0') {
            printf("[ERROR] Kode referensi tidak boleh kosong! Transaksi dibatalkan.\n");
            return;
        }
        strncpy(newTrans->detail.transactionRef, ref,
                sizeof newTrans->detail.transactionRef - 1);
    }

    /* Simpan ke riwayat & file */
    histories[*historyCount] = trans;
    (*historyCount)++;
    appendTransactionToFile("history.txt", &histories[*historyCount - 1]);

    printf("Transaksi berhasil dicatat.\n");
}

/* ========================================================================================
 *  MENU 2: VIEW HISTORY TRANSAKSI PENJUALAN
 * ====================================================================================== */
void handleViewHistory(const TransactionHistory histories[], int historyCount) {
    printf("\n========================================================================================\n");
    printf("                        HISTORI TRANSAKSI PENJUALAN\n");
    printf("========================================================================================\n");

    if (historyCount == 0) {
        printf(">> [INFO] Belum ada transaksi penjualan yang tercatat pada sistem.\n");
        printf("========================================================================================\n");
        return;
    }

    const char *line = "+====+===========+=============+================+=============+\n";
    printf("%s", line);
    printf("| NO | KODE BUKU | JML TERJUAL | TOTAL HARGA    | METODE      |\n");
    printf("%s", line);
    for (int i = 0; i < historyCount; i++) {
        printf("| %2d | %-9s | %11d | %14.2f | %-11s |\n",
               i + 1, histories[i].bookCode, histories[i].quantity,
               histories[i].totalPrice,
               histories[i].payType == PAYMENT_CASH ? "TUNAI" : "QRIS");
    }
    printf("%s", line);

    double grandTotal = calculateTotalRevenueRecursive(histories, historyCount);
    printf("Total Omzet : %.2f\n", grandTotal);
}

/* ========================================================================================
 *  MENU 4: DELETE HISTORY
 * ====================================================================================== */
void handleDeleteHistory(TransactionHistory histories[], int *historyCount) {
    printf("\n=======================================================\n");
    printf("               HAPUS HISTORI TRANSAKSI\n");
    printf("=======================================================\n");

    if (*historyCount == 0) {
        printf(">> [INFO] Belum ada data histori untuk dihapus.\n");
        return;
    }

    handleViewHistory(histories, *historyCount);

    int idx;
    if (!s2ReadInt("Nomor riwayat yang dihapus : ", &idx) ||
        idx < 1 || idx > *historyCount) {
        printf("[ERROR] Nomor tidak valid! Masukkan angka 1 sampai %d.\n", *historyCount);
        return;
    }

    /* Array shifting ke kiri */
    int targetIdx = idx - 1;
    for (int i = targetIdx; i < *historyCount - 1; i++) {
        histories[i] = histories[i + 1];
    }
    (*historyCount)--;

#ifndef PROJECT_BUILD
    saveAllHistoryToFile("history.txt", histories, *historyCount);
#endif

    printf("Data Successfully delete..\n");
}

/* ========================================================================================
 *  MAIN DEMO (hanya mode standalone)
 * ====================================================================================== */
#ifndef PROJECT_BUILD
int main(void) {
    Book books[] = {
        {"BK001", "Pemrograman C", 85000.0, 10},
        {"BK002", "Struktur Data", 70000.0,  5},
        {"BK003", "Algoritma",     95000.0,  8},
    };
    int bookCount = (int)(sizeof books / sizeof books[0]);

    static TransactionHistory histories[MAX_HISTORY];
    int historyCount = 0;
    loadHistoryFromFile("history.txt", histories, &historyCount);

    int choice;
    do {
        printf("\n===== DEMO SLOT 2 =====\n");
        printf("7. Input Transaksi\n2. View History\n4. Delete History\n0. Keluar\n");
        if (!s2ReadInt("Pilih menu: ", &choice)) choice = -1;
        switch (choice) {
            case 7: handleInputTransaction(books, bookCount, histories, &historyCount); break;
            case 2: handleViewHistory(histories, historyCount); break;
            case 4: handleDeleteHistory(histories, &historyCount); break;
            case 0: printf("Keluar.\n"); break;
            default: printf("Menu tidak valid.\n");
        }
    } while (choice != 0);

    return 0;
}
#endif