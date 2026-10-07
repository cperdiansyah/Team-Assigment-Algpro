/**
 * ============================================================================
 * Program      : soal1.c (STARTER TEMPLATE / BOOTSTRAP)
 * Studi Kasus  : Perpustakaan Digital Lentera Nusantara
 * Topik        : Desain dan Analisis Struct dan Union
 * Mata Kuliah  : Algorithm and Programming (COMP6112036) - DCCA
 * Kelas        : DCCA - LEC
 * Kelompok     : Group 1
 * ============================================================================
 * MATERI YANG DITERAPKAN (SESUAI SILABUS BINUS):
 * - Modul Praktikum 3 Halaman 3-4: "Structures and Unions Declaration & Usage"
 *
 * PETUNJUK PENGERJAAN:
 * 1. Struct 'ItemKatalog' menyimpan data umum (Judul, Tahun Terbit, Jenis Media).
 * 2. Union 'DetailMedia' menyimpan data spesifik (InfoBuku atau InfoMajalah)
 *    agar menghemat ruang memori.
 * 3. Lengkapi fungsi input_item() dan tampilkan_item() menggunakan operator titik (.).
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>

// Definisi enum/konstanta untuk penanda tipe media
typedef enum {
    MEDIA_BUKU = 1,
    MEDIA_MAJALAH = 2
} JenisMedia;

// Struktur khusus untuk atribut Buku
typedef struct {
    char penulis[50];
    int jumlah_halaman;
} InfoBuku;

// Struktur khusus untuk atribut Majalah
typedef struct {
    int nomor_edisi;
    char bulan_terbit[20];
} InfoMajalah;

// UNION: Berbagi alokasi memori yang sama (Modul Praktikum 3 Hal. 4)
typedef union {
    InfoBuku buku;
    InfoMajalah majalah;
} DetailMedia;

// STRUCT UTAMA: Mewakili satu item katalog perpustakaan (Modul Praktikum 3 Hal. 3)
typedef struct {
    char judul[100];
    int tahun_terbit;
    JenisMedia tipe;
    DetailMedia detail;
} ItemKatalog;

// Fungsi untuk input data koleksi
void input_item(ItemKatalog *item) {
    (void)item;
    // TODO 1: Implementasikan input Judul, Tahun Terbit, dan Pilihan Jenis Media
    printf("=== FORM INPUT KOLEKSI PERPUSTAKAAN ===\n");
    printf("[TODO: Minta input judul, tahun terbit, dan jenis media dari pengguna]\n");

    // Petunjuk:
    // Gunakan 'if (item->tipe == MEDIA_BUKU)' untuk input atribut buku
    // Gunakan 'else' untuk input atribut majalah
}

// Fungsi untuk menampilkan data koleksi
void tampilkan_item(const ItemKatalog *item) {
    (void)item;
    // TODO 2: Tampilkan informasi item berdasarkan tipe medianya
    printf("\n=== DETAIL KOLEKSI PERPUSTAKAAN ===\n");
    printf("[TODO: Tampilkan judul, tahun terbit, serta detail buku/majalah]\n");
}

int main(void) {
    ItemKatalog item;

    printf("===================================================\n");
    printf(" SISTEM KATALOG PERPUSTAKAAN LENTERA NUSANTARA     \n");
    printf("===================================================\n");

    // TODO 3: Panggil fungsi input_item dan tampilkan_item
    input_item(&item);
    tampilkan_item(&item);

    return 0;
}
