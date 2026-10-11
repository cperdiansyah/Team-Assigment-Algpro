/**
 * ============================================================================
 * Program      : tugas2c.c
 * Studi Kasus  : Supermarket Nusantara Sejahtera
 * Topik        : Perhitungan Hadiah Belanja dan Diskon untuk Pelanggan
 * Mata Kuliah  : Algorithm and Programming (COMP6112036) - ACCA
 * Kelas        : ACCA - LAB
 * Kelompok     : Group 1
 * ============================================================================
 * MATERI YANG DITERAPKAN (SESUAI MODUL PRAKTIKUM BINUS):
 * 1. Formatted Input & Output  : scanf() dan printf() (Modul LN02)
 * 2. Operator & Aritmatika     : Integer division (/) dan perkalian (*) (Modul Week 4)
 * 3. Kontrol Program (Seleksi) : Percabangan if - else (Modul Praktikum 2)
 *
 * ATURAN STUDI KASUS:
 * 1. Input total pembelian (dalam Rupiah).
 * 2. Kupon undian: 1 kupon per kelipatan Rp 100.000,00 (pembulatan ke bawah via integer division).
 * 3. Diskon: 5% jika total pembelian minimal Rp 100.000,00.
 * 4. Total yang harus dibayar: Total pembelian - diskon.
 * ============================================================================
 */

#include <stdio.h>

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
        diskon = (int)(total_pembelian * 0.05); // 5% dari total pembelian awal
    } else {
        diskon = 0;
    }

    // 4. Hitung total yang harus dibayar
    total_dibayar = total_pembelian - diskon;

    // 5. Tampilkan rincian output sesuai format studi kasus
    printf("\nOutput:\n");
    printf("Total pembelian     : Rp %d\n", total_pembelian);
    printf("Jumlah kupon undian : %d lembar\n", jumlah_kupon);
    printf("Diskon              : Rp %d\n", diskon);
    printf("Total dibayar       : Rp %d\n", total_dibayar);

    return 0;
}
