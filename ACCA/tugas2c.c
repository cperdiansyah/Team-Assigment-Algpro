/**
 * ============================================================================
 * Program      : tugas2c.c (STARTER TEMPLATE / BOOTSTRAP)
 * Studi Kasus  : Supermarket Nusantara Sejahtera
 * Topik        : Program Hadiah Belanja & Diskon Pelanggan
 * Mata Kuliah  : Algorithm and Programming (COMP6112036) - ACCA
 * Kelompok     : Group 1
 * ============================================================================
 * PETUNJUK PENGERJAAN:
 * 1. Menerima input: Total Pembelian dalam Rupiah.
 * 2. Ketentuan:
 *    - Kupon Undian : 1 kupon per kelipatan Rp 100.000,00 (pembulatan ke bawah / floor).
 *    - Diskon       : 5% dari total belanja jika total pembelian minimal Rp 100.000,00.
 * 3. Tampilkan: Total Pembelian Awal, Jumlah Kupon, Nominal Diskon, dan Total Bayar.
 * ============================================================================
 */

#include <stdio.h>

int main(void) {
    double total_pembelian = 0.0;
    int kupon_undian = 0;
    double diskon = 0.0;
    double total_bayar = 0.0;

    printf("===================================================\n");
    printf("     PROGRAM HADIAH & DISKON PELANGGAN (2C)        \n");
    printf("===================================================\n");

    // TODO 1: Minta input total pembelian dari kasir/pelanggan
    printf("[TODO: Minta input total pembelian (Rp)]\n");

    // TODO 2: Hitung jumlah kupon undian
    // Petunjuk: Gunakan integer division atau floor division (total_pembelian / 100000.0)

    // TODO 3: Hitung diskon 5% jika total_pembelian >= 100000.0
    // Petunjuk: diskon = 0.05 * total_pembelian;

    // TODO 4: Hitung total bayar (total_pembelian - diskon)

    // TODO 5: Tampilkan struk rincian belanja
    printf("\n=== STRUK RINCIAN PEMBELIAN ===\n");
    printf("[TODO: Tampilkan Total Awal, Jumlah Kupon, Diskon, dan Total Bayar]\n");

    // Placeholder sementara
    (void)total_pembelian; (void)kupon_undian;
    (void)diskon; (void)total_bayar;

    return 0;
}
