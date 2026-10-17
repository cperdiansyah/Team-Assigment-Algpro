
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

// Fungsi mencetak nominal dengan format Rupiah bertitik, contoh: Rp2.500.000
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

// Fungsi untuk menentukan gaji pokok berdasarkan golongan (Modul Praktikum 2)
int tentukan_gaji_pokok(const char *golongan) {
    if (strcmp(golongan, "D1") == 0 || strcmp(golongan, "d1") == 0) return 3000000;
    else if (strcmp(golongan, "D2") == 0 || strcmp(golongan, "d2") == 0) return 2500000;
    else if (strcmp(golongan, "D3") == 0 || strcmp(golongan, "d3") == 0) return 2000000;
    
    return 0; // Golongan tidak valid
}

int main(void) {
    Pegawai p = {0};

    // 1. Input data pegawai
    printf("Masukkan NIP        : "); scanf(" %19[^\n]", p.nip);
    printf("Masukkan Nama       : "); scanf(" %49[^\n]", p.nama);
    printf("Masukkan Alamat     : "); scanf(" %99[^\n]", p.alamat);
    printf("Masukkan No HP      : "); scanf(" %19[^\n]", p.no_hp);
    printf("Masukkan Jabatan    : "); scanf(" %29[^\n]", p.jabatan);
    printf("Masukkan Golongan (D1/D2/D3) : "); scanf(" %4s", p.golongan);

    // Normalisasi input golongan agar huruf kapital (misal d2 -> D2)
    for (int i = 0; p.golongan[i] != '\0'; i++) {
        p.golongan[i] = (char)toupper((unsigned char)p.golongan[i]);
    }

    // 2. Tentukan gaji pokok secara otomatis
    p.gaji_pokok = tentukan_gaji_pokok(p.golongan);
    if (p.gaji_pokok == 0) {
        printf("\nPeringatan: Golongan '%s' tidak valid! Harap masukkan D1, D2, atau D3.\n", p.golongan);
        return 1;
    }

    // 3. Tampilkan seluruh profil pegawai dan gaji pokoknya
    printf("\n=== DATA LENGKAP PEGAWAI ===\n");
    printf("NIP = %s\n", p.nip);
    printf("Nama = %s\n", p.nama);
    printf("Alamat = %s\n", p.alamat);
    printf("No HP = %s\n", p.no_hp);
    printf("Jabatan = %s\n", p.jabatan);
    printf("Golongan = %s\n", p.golongan);
    printf("\n");
    printf("Gaji Pokok Anda: "); cetak_rupiah(p.gaji_pokok); printf("\n");

    return 0;
}