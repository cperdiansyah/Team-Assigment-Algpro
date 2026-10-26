/**
 * ============================================================================
 * Program      : tugas2a.c (STARTER TEMPLATE / BOOTSTRAP)
 * Studi Kasus  : Supermarket Nusantara Sejahtera
 * Topik        : Data Pegawai & Penentuan Gaji Pokok (Struct)
 * Mata Kuliah  : Algorithm and Programming (COMP6112036) - ACCA
 * Kelas        : ACCA - LAB
 * Kelompok     : Group 1
 * ============================================================================
 * MATERI YANG DITERAPKAN (SESUAI DOKUMEN DI ACCA/docs/):
 * 1. Formatted I/O         : printf(), scanf() (Modul LN02)
 * 2. Selection & String    : if - else if, strcmp() (Modul Praktikum 2 Hal. 6)
 * 3. Structures (Struct)   : struct Pegawai (Modul Praktikum 3 Hal. 3)
 *
 * ATURAN DAN PETUNJUK PENGERJAAN:
 * 1. Struct Pegawai harus memiliki 6 field input:
 *    NIP, Nama, Alamat, No HP, Jabatan, Golongan.
 * 2. Tentukan Gaji Pokok otomatis berdasarkan golongan:
 *    - D1 : Rp 3.000.000 (3000000)
 *    - D2 : Rp 2.500.000 (2500000)
 *    - D3 : Rp 2.000.000 (2000000)
 * 3. Tampilkan data pegawai lengkap beserta nominal gaji pokoknya.
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>

// Definisi Struktur Data Pegawai (Referensi: Modul Praktikum 3 Halaman 3)
typedef struct {
    char nip[20];
    char nama[50];
    char alamat[100];
    char no_hp[20];
    char jabatan[30];
    char golongan[5];       // "D1", "D2", atau "D3"
    int gaji_pokok;         // Ditentukan otomatis berdasarkan golongan
} Pegawai;

// Fungsi untuk menentukan gaji pokok berdasarkan golongan (Modul Praktikum 2)
int tentukan_gaji_pokok(const char *golongan) {
    // Petunjuk: Gunakan perbandingan string strcmp() seperti di Modul Praktikum 2
    // if (strcmp(golongan, "D1") == 0) return 3000000;
    // else if (strcmp(golongan, "D2") == 0) return 2500000;
    // else if (strcmp(golongan, "D3") == 0) return 2000000;
    (void)golongan;
    return 0; // Ganti dengan logika di atas
}

int main(void) {
    Pegawai p = {0};

    printf("===================================================\n");
    printf("   SISTEM DATA PEGAWAI & GAJI POKOK (TUGAS 2A)     \n");
    printf("===================================================\n");

    // TODO 1: Implementasikan input data pegawai
    // Catatan Materi LN02:
    // - Gunakan scanf("%s", ...) untuk satu kata atau scanf(" %[^\n]", ...) / fgets() untuk teks berspasi
    printf("[TODO: Minta input data pegawai (NIP, Nama, Alamat, No HP, Jabatan, Golongan)]\n");

    // TODO 2: Tentukan gaji pokok secara otomatis
    p.gaji_pokok = tentukan_gaji_pokok(p.golongan);

    // TODO 3: Tampilkan seluruh profil pegawai dan gaji pokoknya
    printf("\n=== DATA LENGKAP PEGAWAI ===\n");
    printf("[TODO: Tampilkan profil lengkap pegawai dan gaji pokok dengan printf]\n");

    return 0;
}
