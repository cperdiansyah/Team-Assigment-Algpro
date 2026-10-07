/**
 * ============================================================================
 * Program      : tugas2a.c (STARTER TEMPLATE / BOOTSTRAP)
 * Studi Kasus  : Supermarket Nusantara Sejahtera
 * Topik        : Data Pegawai & Penentuan Gaji Pokok (Struct)
 * Mata Kuliah  : Algorithm and Programming (COMP6112036) - ACCA
 * Kelompok     : Group 1
 * ============================================================================
 * PETUNJUK PENGERJAAN:
 * 1. Struct Pegawai harus memiliki 6 field input:
 *    NIP, Nama, Alamat, No HP, Jabatan, Golongan.
 * 2. Tambahkan field gaji pokok yang ditentukan otomatis sesuai golongan:
 *    - D1 : Rp 3.000.000
 *    - D2 : Rp 2.500.000
 *    - D3 : Rp 2.000.000
 * 3. Tampilkan data pegawai lengkap beserta gaji pokoknya.
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>

// Definisi Struktur Data Pegawai
typedef struct {
    char nip[20];
    char nama[50];
    char alamat[100];
    char no_hp[20];
    char jabatan[30];
    char golongan[5];       // "D1", "D2", atau "D3"
    double gaji_pokok;      // Ditentukan otomatis berdasarkan golongan
} Pegawai;

// TODO 1: Buat fungsi untuk menentukan besaran gaji pokok berdasarkan golongan
double tentukan_gaji_pokok(const char *golongan) {
    // Petunjuk: Gunakan if-else atau switch-case dengan strcmp()
    // Jika D1 -> 3000000
    // Jika D2 -> 2500000
    // Jika D3 -> 2000000
    (void)golongan;
    return 0.0; // Ganti dengan logika kalian
}

int main(void) {
    Pegawai p = {0};

    printf("===================================================\n");
    printf("   SISTEM DATA PEGAWAI & GAJI POKOK (TUGAS 2A)     \n");
    printf("===================================================\n");

    // TODO 2: Implementasikan input data pegawai (NIP, Nama, Alamat, No HP, Jabatan, Golongan)
    // Tips: Gunakan fgets() atau scanf() untuk membaca input string
    printf("[TODO: Minta input data pegawai di sini]\n");

    // TODO 3: Panggil fungsi untuk menentukan gaji pokok
    p.gaji_pokok = tentukan_gaji_pokok(p.golongan);

    // TODO 4: Tampilkan seluruh profil pegawai dan gaji pokok yang didapat
    printf("\n=== DATA LENGKAP PEGAWAI ===\n");
    printf("[TODO: Tampilkan profil pegawai dan gaji pokok di sini]\n");

    return 0;
}
