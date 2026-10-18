// Tugas 1 DCCA - Kelompok 1 (Struct & Union)

#include <stdio.h>
#include <string.h>

typedef enum {
    MEDIA_BUKU = 1,
    MEDIA_MAJALAH = 2
} JenisMedia;

typedef struct {
    char penulis[50];
    int jumlah_halaman;
} InfoBuku;

typedef struct {
    int nomor_edisi;
    char bulan_terbit[20];
} InfoMajalah;

typedef union {
    InfoBuku buku;
    InfoMajalah majalah;
} DetailMedia;

typedef struct {
    char judul[100];
    int tahun_terbit;
    JenisMedia tipe;
    DetailMedia detail;
} ItemKatalog;

void input_item(ItemKatalog *katalog) {
    int opt = 0;

    printf("\n-- Input Data Koleksi --\n");
    printf("Judul: ");
    scanf(" %99[^\n]", katalog->judul);
    printf("Tahun terbit: ");
    scanf("%d", &katalog->tahun_terbit);
    
    printf("Pilih jenis (1. Buku | 2. Majalah): ");
    while (scanf("%d", &opt) != 1 || (opt != MEDIA_BUKU && opt != MEDIA_MAJALAH)) {
        printf("Pilihan salah, masukkan 1 atau 2: ");
        while (getchar() != '\n');
    }
    katalog->tipe = (JenisMedia)opt;

    if (katalog->tipe == MEDIA_BUKU) {
        printf("Nama penulis: ");
        scanf(" %49[^\n]", katalog->detail.buku.penulis);
        printf("Jumlah halaman: ");
        scanf("%d", &katalog->detail.buku.jumlah_halaman);
    } else if (katalog->tipe == MEDIA_MAJALAH) {
        printf("Edisi ke: ");
        scanf("%d", &katalog->detail.majalah.nomor_edisi);
        printf("Bulan terbit: ");
        scanf(" %19[^\n]", katalog->detail.majalah.bulan_terbit);
    }
}

void tampilkan_item(const ItemKatalog *katalog) {
    printf("\n--- Info Koleksi ---\n");
    printf("Judul        : %s\n", katalog->judul);
    printf("Tahun        : %d\n", katalog->tahun_terbit);
    
    if (katalog->tipe == MEDIA_BUKU) {
        printf("Kategori     : Buku\n");
        printf("Penulis      : %s\n", katalog->detail.buku.penulis);
        printf("Jml Halaman  : %d\n", katalog->detail.buku.jumlah_halaman);
    } else {
        printf("Kategori     : Majalah\n");
        printf("No Edisi     : %d\n", katalog->detail.majalah.nomor_edisi);
        printf("Bulan Terbit : %s\n", katalog->detail.majalah.bulan_terbit);
    }
}

int main(void) {
    ItemKatalog data;

    printf("=========================================\n");
    printf("  Katalog Perpustakaan Lentera Nusantara \n");
    printf("=========================================\n");

    input_item(&data);
    tampilkan_item(&data);

    return 0;
}