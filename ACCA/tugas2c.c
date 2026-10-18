
#include <stdio.h>

// Mencetak nominal dengan format Rupiah bertitik, contoh: Rp250.000
void cetak_rupiah(int n) {
    char buf[16];
    int len = sprintf(buf, "%d", n);   // ubah angka jadi teks
    printf("Rp");
    for (int i = 0; i < len; i++) {
        printf("%c", buf[i]);
        int sisa = len - i - 1;        // sisa digit di kanan
        if (sisa > 0 && sisa % 3 == 0) printf(".");
    }
}

int main(void) {
    // Deklarasi variabel sesuai materi dasar tipe data C
    int total_pembelian = 0;
    int jumlah_kupon = 0;
    int diskon = 0;
    int total_dibayar = 0;

    // 1. Input data total pembelian menggunakan formatted input scanf()
    printf("Input total belanja: ");
    if (scanf("%d", &total_pembelian) != 1 || total_pembelian < 0) {
        printf("Input tidak valid! Harap masukkan nominal angka positif.\n");
        return 1;
    }

    // 2. Hitung jumlah kupon undian
    // Sesuai materi: Pembagian integer (total_pembelian / 100000) otomatis membulatkan ke bawah (floor)
    jumlah_kupon = total_pembelian / 100000;

    // 3. Hitung diskon 5% menggunakan percabangan if-else (Modul Praktikum 2)
    // Diskon hanya diberikan jika total pembelian minimal Rp 100.000,00
    if (total_pembelian >= 100000) {
        diskon = (total_pembelian * 5) / 100; // 5% dari total pembelian awal via aritmatika integer
} else {
        diskon = 0;
    }

    // 4. Hitung total yang harus dibayar
    total_dibayar = total_pembelian - diskon;

    // 5. Tampilkan rincian output sesuai format studi kasus
    printf("\nOutput:\n");
    printf("Total pembelian     : "); cetak_rupiah(total_pembelian); printf("\n");
    printf("Jumlah kupon undian : %d lembar\n", jumlah_kupon);
    printf("Diskon              : "); cetak_rupiah(diskon); printf("\n");
    printf("Total dibayar       : "); cetak_rupiah(total_dibayar); printf("\n");

    return 0;
}
