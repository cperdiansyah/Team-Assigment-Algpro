/**
 * ============================================================================
 * Program      : tugas2b.c (STARTER TEMPLATE / BOOTSTRAP)
 * Studi Kasus  : Supermarket Nusantara Sejahtera
 * Topik        : Hitung Total Gaji Bulanan dan Jam Lembur
 * Mata Kuliah  : Algorithm and Programming (COMP6112036) - ACCA
 * Kelompok     : Group 1
 * ============================================================================
 * PETUNJUK PENGERJAAN:
 * 1. Menerima input: NIP Pegawai, Golongan (D1, D2, D3), dan Jam Lembur.
 * 2. Tentukan tarif lembur per jam sesuai golongan:
 *    - D1 : Rp 15.000 / jam
 *    - D2 : Rp 10.000 / jam
 *    - D3 : Rp 5.000 / jam
 * 3. Hitung total gaji bulanan:
 *    Total Gaji = Gaji Pokok + (Jam Lembur * Tarif Lembur)
 * 4. Tampilkan NIP, Golongan, Jam Lembur, dan Total Gaji Bulan Ini.
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char nip[20];
    char golongan[5];
    int jam_lembur = 0;
    double gaji_pokok = 0.0;
    double tarif_lembur = 0.0;
    double total_gaji = 0.0;

    printf("===================================================\n");
    printf("   SISTEM PENGGAJIAN BULANAN PEGAWAI (TUGAS 2B)    \n");
    printf("===================================================\n");

    // TODO 1: Ambil input NIP, Golongan, dan Jam Lembur
    printf("[TODO: Minta input NIP, Golongan, dan Jam Lembur]\n");

    // TODO 2: Tentukan gaji pokok dan tarif lembur berdasarkan golongan
    // Petunjuk:
    // D1: Gaji pokok 3.000.000, Tarif lembur 15.000
    // D2: Gaji pokok 2.500.000, Tarif lembur 10.000
    // D3: Gaji pokok 2.000.000, Tarif lembur 5.000

    // TODO 3: Hitung total gaji bulan ini
    // total_gaji = gaji_pokok + (jam_lembur * tarif_lembur);

    // TODO 4: Tampilkan rincian penghasilan pegawai
    printf("\n=== RINCIAN PENGGAJIAN BULAN INI ===\n");
    printf("[TODO: Tampilkan NIP, Golongan, Jam Lembur, dan Total Gaji]\n");

    // Placeholder sementara
    (void)nip; (void)golongan; (void)jam_lembur;
    (void)gaji_pokok; (void)tarif_lembur; (void)total_gaji;

    return 0;
}
