/**
 * ========================================================================================
 * SLOT 1: MANAJEMEN KATALOG BUKU (MENU 1, MENU 3, MENU 5)
 * PIC: Arsyan Qasthari
 *
 * PANDUAN PENGERJAAN UNTUK ANGGOTA TIM:
 * Modul ini bertugas mengelola katalog buku toko "Literasi Nusantara Jaya".
 * Silakan lengkapi logika fungsi di bawah ini sesuai petunjuk TODO masing-masing.
 * ========================================================================================
 */

#include <stdio.h>
#include <string.h>

/**
 * MENU 1: INPUT DATA BUKU BARU
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Auto-generate kode buku dengan format: BK001, BK002, dst.
 *    Rumus: int nextId = *bookCount + 1;
 *           snprintf(books[*bookCount].bookCode, sizeof(books[*bookCount].bookCode), "BK%03d", nextId);
 *    Tampilkan kode otomatis tersebut ke layar console.
 * 2. Minta input Nama Buku (gunakan readStringSafe agar aman dari spasi).
 * 3. Minta input Jenis Buku (Komputer, Novel, Sains, dll).
 * 4. Minta input Harga Buku (validasi harga harus > 0 menggunakan loop).
 * 5. Tambahkan jumlah buku: (*bookCount)++;
 * 6. Tampilkan pesan sukses: "Data buku berhasil ditambahkan ke sistem!"
 */
void handleInputBook(Book books[], int *bookCount) {
    printf("\n=======================================================\n");
    printf("               INPUT DATA BUKU BARU\n");
    printf("=======================================================\n");

    // TODO1 : Tulis kodinganmu di sini...
    int nextId = *bookCount + 1;
    snprintf(books[*bookCount].bookCode, sizeof(books[*bookCount].bookCode), "BK%03d", nextId);
    printf("Kode Buku Otomatis : %s\n", books[*bookCount].bookCode);

    printf("Masukkan Nama Buku : ");
    getchar();
    fgets(books[*bookCount].title, sizeof(books[*bookCount].title), stdin);
    books[*bookCount].title[strcspn(books[*bookCount].title, "\n")] = 0;

    printf("Masukkan Jenis Buku: ");
    fgets(books[*bookCount].category, sizeof(books[*bookCount].category), stdin);
    books[*bookCount].category[strcspn(books[*bookCount].category, "\n")] = 0;

    do {
        printf("Masukkan Harga Buku: ");
        if (scanf("%lf", &books[*bookCount].price) != 1) {
            printf("[ERROR] Masukkan angka yang valid!\n");
            while (getchar() != '\n');
            books[*bookCount].price = -1;
        } else if (books[*bookCount].price <= 0) {
            printf("[ERROR] Harga haruslebih besar dari 0!\n");
        }
    } while (books[*bookCount].price <= 0);
    (*bookCount)++;
    printf("\nData buku berhasil ditambahkan ke sistem!\n");
}

/**
 * MENU 3: VIEW BUKU (SELURUH DATA BUKU YANG TERSEDIA)
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Cek apakah daftar buku masih kosong (bookCount == 0).
 *    Jika kosong, tampilkan pesan:
 *    ">> [INFO] Belum ada data buku yang terdaftar di sistem."
 * 2. Jika ada, cetak dalam bentuk tabel rapi menggunakan printf dengan format specifier lebar:
 *    Contoh format: | %-3d | %-10s | %-30s | %-15s | Rp %10.2f |
 * 3. Tampilkan total koleksi buku di bagian bawah tabel.
 */
void handleViewBooks(const Book books[], int bookCount) {
    (void)books;
    (void)bookCount;
    printf("\n========================================================================================\n");
    printf("                       DAFTAR BUKU TOKO LITERASI NUSANTARA JAYA\n");
    printf("========================================================================================\n");

    if (bookCount == 0) {
        printf(">> [INFO] Belum ada data buku yang terdaftar di sistem.\n");
        printf("========================================================================================\n");
        return;
    }

    // TODO: Tulis kodingan looping cetak tabel buku di sini...
    printf("\n+-----+------------+--------------------------------+-------------------+-----------------+\n");
    printf("| NO  | KODE       | NAMA BUKU                      | JENIS             | HARGA (RP)      |\n");
    printf("+-----+------------+--------------------------------+-------------------+-----------------+\n");
    for (int i = 0; i < bookCount; i++) {
        printf("| %-3d | %-10s | %-30s | %-17s | Rp %10.2f |\n", 
               i + 1, 
               books[i].bookCode, 
               books[i].title, 
               books[i].category, 
               books[i].price);
    }

    printf("+-----+------------+--------------------------------+-------------------+-----------------+\n");
    printf("[INFO] Total Koleksi Buku: %d Buku\n", bookCount);
}

/**
 * MENU 5: DELETE BUKU (HAPUS DATA BUKU TERTENTU)
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Cek apakah ada data buku (*bookCount == 0). Jika kosong, tampilkan pesan info.
 * 2. Tampilkan terlebih dahulu daftar buku (panggil handleViewBooks) agar user tahu nomor indeksnya.
 * 3. Minta input nomor indeks yang ingin dihapus (1 sampai *bookCount).
 * 4. Validasi indeks: pastikan input berada di antara 1 dan *bookCount.
 *    Jika salah, cetak error dan batalkan.
 * 5. Lakukan pergeseran array (Array Shifting) ke kiri dari indeks yang dihapus:
 *    int targetIdx = idx - 1;
 *    for (int i = targetIdx; i < *bookCount - 1; i++) {
 *        books[i] = books[i + 1];
 *    }
 *    (*bookCount)--;
 * 6. Tampilkan pesan sukses persis sesuai teks soal:
 *    "Data Successfully delete.."
 */
void handleDeleteBook(Book books[], int *bookCount) {
    (void)books;
    (void)bookCount;
    printf("\n=======================================================\n");
    printf("                  HAPUS DATA BUKU\n");
    printf("========================================================\n");

    if (*bookCount == 0) {
        printf(">> [INFO] Belum ada data buku untuk dihapus.\n");
        return;
    }

    // TODO: Tulis kodingan hapus buku di sini...
    // 2. Tampilkan terlebih dahulu daftar buku
    handleViewBooks(books, *bookCount);

    int deleteIdx;
    // 3. Minta input nomor urut yang ingin dihapus
    printf("\nMasukkan nomor urut buku yang ingin dihapus (1 - %d): ", *bookCount);
    if (scanf("%d", &deleteIdx) != 1) {
        printf("[ERROR] Input tidak valid!\n");
        while (getchar() != '\n');
        return;
    }

    // 4. Validasi indeks: pastikan dalam rentang 1 s.d. *bookCount
    if (deleteIdx < 1 || deleteIdx > *bookCount) {
        printf("[ERROR] Indeks tidak valid! Pilih nomor antara 1 dan %d.\n", *bookCount);
        return;
    }

    // 5. Lakukan pergeseran array (Array Shifting) ke kiri
    int targetIdx = deleteIdx - 1; // Konversi ke 0-based index
    for (int i = targetIdx; i < *bookCount - 1; i++) {
        books[i] = books[i + 1];
    }
    (*bookCount)--;
    // 6. Tampilkan pesan sukses persis sesuai teks soal
    printf("Data Successfully delete..\n");
}
