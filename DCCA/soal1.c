/**
 * ============================================================================
 * Program      : soal1.c (STARTER TEMPLATE / BOOTSTRAP)
 * Studi Kasus  : Perpustakaan Digital Lentera Nusantara
 * Topik        : Desain dan Analisis Struct dan Union
 * Mata Kuliah  : Algorithm and Programming (COMP6112036) - DCCA
 * Kelompok     : Group 1
 * ============================================================================
 * PETUNJUK PENGERJAAN UNTUK ANGGOTA TIM:
 * 1. Lengkapi struktur data 'union' dan 'struct' di bawah ini.
 * 2. Pastikan satu entri katalog bisa membedakan Buku atau Majalah.
 * 3. Lengkapi fungsi input_item() dan tampilkan_item().
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>

// TODO 1: Definisikan enum / konstanta untuk jenis media (1: Buku, 2: Majalah)
typedef enum {
    MEDIA_BUKU = 1,
    MEDIA_MAJALAH = 2
} JenisMedia;

// TODO 2: Definisikan atribut khusus untuk Buku (penulis, jumlah halaman)
typedef struct {
    char penulis[50];
    int jumlah_halaman;
} InfoBuku;

// TODO 3: Definisikan atribut khusus untuk Majalah (nomor edisi, bulan terbit)
typedef struct {
    int nomor_edisi;
    char bulan_terbit[20];
} InfoMajalah;

// TODO 4: Gunakan UNION untuk menggabungkan InfoBuku dan InfoMajalah agar hemat memori
typedef union {
    InfoBuku buku;
    InfoMajalah majalah;
} DetailMedia;

// TODO 5: Definisikan struct utama untuk item katalog perpustakaan
typedef struct {
    char judul[100];
    int tahun_terbit;
    JenisMedia tipe;
    DetailMedia detail;
} ItemKatalog;

// Fungsi untuk input data
void input_item(ItemKatalog *item) {
    (void)item; // Placeholder agar compile tanpa warning sebelum dilengkapi
    // TODO 6: Implementasikan input Judul, Tahun Terbit, dan Pilihan Jenis Media
    printf("=== FORM INPUT KOLEKSI PERPUSTAKAAN ===\n");
    printf("[TODO: Minta input judul, tahun terbit, dan jenis media dari pengguna]\n");

    // Petunjuk:
    // Gunakan 'if (item->tipe == MEDIA_BUKU)' untuk input field buku
    // Gunakan 'else' untuk input field majalah
}

// Fungsi untuk menampilkan data
void tampilkan_item(const ItemKatalog *item) {
    (void)item; // Placeholder agar compile tanpa warning sebelum dilengkapi
    // TODO 7: Tampilkan informasi item berdasarkan tipe medianya
    printf("\n=== DETAIL KOLEKSI PERPUSTAKAAN ===\n");
    printf("[TODO: Tampilkan judul, tahun terbit, serta detail buku/majalah]\n");
}

int main(void) {
    ItemKatalog item;

    printf("===================================================\n");
    printf(" SISTEM KATALOG PERPUSTAKAAN LENTERA NUSANTARA     \n");
    printf("===================================================\n");

    // TODO 8: Panggil fungsi input_item dan tampilkan_item
    input_item(&item);
    tampilkan_item(&item);

    return 0;
}
