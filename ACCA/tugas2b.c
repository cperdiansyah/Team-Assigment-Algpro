/**
 * ============================================================================
 * Program      : tugas2b.c (STARTER TEMPLATE / BOOTSTRAP)
 * Studi Kasus  : Supermarket Nusantara Sejahtera
 * Topik        : Hitung Total Gaji Bulanan dan Upah Lembur
 * Mata Kuliah  : Algorithm and Programming (COMP6112036) - ACCA
 * Kelas        : ACCA - LAB
 * Kelompok     : Group 1
 * ============================================================================
 * MATERI YANG DITERAPKAN (SESUAI DOKUMEN DI ACCA/docs/):
 * 1. Formatted I/O         : printf(), scanf() (Modul LN02)
 * 2. Selection & String    : if - else if, strcmp() (Modul Praktikum 2 Hal. 6)
 * 3. Operator Aritmatika   : Perkalian (*), Penjumlahan (+) (Modul Week 4)
 *
 * ATURAN STUDI KASUS:
 * 1. Input: NIP Pegawai, Golongan (D1, D2, D3), dan Jumlah Jam Lembur.
 * 2. Tarif Lembur per Jam:
 *    - D1 : Gaji Pokok Rp 3.000.000, Lembur Rp 15.000 / jam
 *    - D2 : Gaji Pokok Rp 2.500.000, Lembur Rp 10.000 / jam
 *    - D3 : Gaji Pokok Rp 2.000.000, Lembur Rp 5.000 / jam
 * 3. Rumus: Total Gaji = Gaji Pokok + (Jam Lembur * Tarif Lembur)
 * 4. Format Output Sesuai Template Soal:
 *    NIP = ...
 *    Golongan = ...
 *    Lembur = ... jam
 *    Total Gaji Bulan Ini = Rp xxxxxx
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char nip[20] = "";
    char golongan[5] = "";
    int jam_lembur = 0;
    int gaji_pokok = 0;
    int tarif_lembur = 0;
    int total_gaji = 0;

    printf("===================================================\n");
    printf("   SISTEM PENGGAJIAN BULANAN PEGAWAI (TUGAS 2B)    \n");
    printf("===================================================\n");

    // TODO 1: Ambil input NIP, Golongan, dan Jam Lembur via scanf()
    // Contoh:
    // printf("Masukkan NIP: "); scanf("%s", nip);
    // printf("Masukkan Golongan (D1/D2/D3): "); scanf("%s", golongan);
    // printf("Masukkan Jumlah Jam Lembur: "); scanf("%d", &jam_lembur);
    printf("[TODO: Minta input NIP, Golongan, dan Jam Lembur]\n");

    // TODO 2: Tentukan gaji pokok dan tarif lembur berdasarkan golongan (Modul Praktikum 2)
    // Petunjuk:
    // if (strcmp(golongan, "D1") == 0) { gaji_pokok = 3000000; tarif_lembur = 15000; }
    // else if (strcmp(golongan, "D2") == 0) { gaji_pokok = 2500000; tarif_lembur = 10000; }
    // else if (strcmp(golongan, "D3") == 0) { gaji_pokok = 2000000; tarif_lembur = 5000; }

    // TODO 3: Hitung total gaji bulan ini (Modul Week 4)
    // total_gaji = gaji_pokok + (jam_lembur * tarif_lembur);

    // TODO 4: Tampilkan output sesuai format resmi dokumen soal
    printf("\n=== OUTPUT PENGGAJIAN BULANAN ===\n");
    printf("NIP                  = %s\n", nip);
    printf("Golongan             = %s\n", golongan);
    printf("Lembur               = %d jam\n", jam_lembur);
    printf("Total Gaji Bulan Ini = Rp %d\n", total_gaji);

    // Placeholder sementara agar bebas warning
    (void)gaji_pokok; (void)tarif_lembur;

    return 0;
}
