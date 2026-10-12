// untuk menghandle fungsi input output seperti scanf dan printf
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Mencetak nominal dengan format Rupiah bertitik, contoh: Rp2.550.000
void cetak_rupiah(int n) {
    char buf[16];
    int len = sprintf(buf, "%d", n);
    printf("Rp");
    for (int i = 0; i < len; i++) {
        printf("%c", buf[i]);
        int sisa = len - i - 1;
        if (sisa > 0 && sisa % 3 == 0) printf(".");
    }
}

int main(void) {
    // menyimpan nip sebesar 19 karena pada tipe variable selalu menyimpan karakter null di akhir
    // ="" digunakan untuk menentukan array tersebut string kosong
    char nip[20] = "";
    char golongan[5] = "";

    // inisialisasi nilai awal dari integer
    int jam_lembur = 0;
    int gaji_pokok = 0;
    int tarif_lembur = 0;
    int total_gaji = 0;

    // input data sesuai spesifikasi soal
    printf("Masukkan NIP                : ");
    scanf(" %19[^\n]", nip);

    printf("Masukkan Golongan (D1/D2/D3): ");
    scanf(" %4s", golongan);

    // normalisasi input golongan ke huruf kapital (misal d2 -> D2) agar portabel di semua compiler
    for (int i = 0; golongan[i] != '\0'; i++) {
        golongan[i] = (char)toupper((unsigned char)golongan[i]);
    }

    printf("Masukkan Jam Lembur         : ");
    // validasi jika input jam lembur kurang dari 0 atau bukan angka
    if (scanf("%d", &jam_lembur) != 1 || jam_lembur < 0) {
        printf("\nError: jam lembur tidak boleh kurang dari 0 atau bukan angka.\n");
        return 1;
    }

    // menggunakan if selection untuk menentukan gaji pokok dan tarif lembur dari inputan user
    if (strcmp(golongan, "D1") == 0) {
        gaji_pokok = 3000000;
        tarif_lembur = 15000;
    } else if (strcmp(golongan, "D2") == 0) {
        gaji_pokok = 2500000;
        tarif_lembur = 10000;
    } else if (strcmp(golongan, "D3") == 0) {
        gaji_pokok = 2000000;
        tarif_lembur = 5000;
    } else {
        printf("\nInputan tidak valid! Golongan '%s' tidak ditemukan (mohon pilih D1/D2/D3).\n", golongan);
        return 1;
    }

    // menghitung total gaji dari gaji pokok yang ditambah tarif lembur perjam dikali jam lembur
    total_gaji = gaji_pokok + (jam_lembur * tarif_lembur);

    // menampilkan output ringkasan penggajian sesuai format soal (image4)
    printf("\nNIP = %s\n", nip);
    printf("Golongan = %s\n", golongan);
    printf("Lembur = %d jam\n", jam_lembur);
    printf("Total Gaji Bulan Ini = "); cetak_rupiah(total_gaji); printf("\n");

    return 0;
}