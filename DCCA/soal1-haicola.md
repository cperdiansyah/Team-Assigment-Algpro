# 🤖 DOKUMENTASI HAICOLA — SOAL 1 DCCA (DESAIN STRUCT & UNION KATALOG MEDIA)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** DCCA - LEC  
**Kelompok:** Group 1  
**Topik Evaluasi:** Penerapan Tagged Union (`struct` + `union` + `enum`), Validasi Seleksi Media, dan Analisis Efisiensi *Memory Footprint* (Soal 1 DCCA)  

---

> 📌 **Catatan untuk Rekan Tim:**  
> Berkas ini berisi dokumentasi resmi sesi **HAICOLA (Human-AI Collaboration)** untuk modul **DCCA Soal 1**. Dokumen ini siap digunakan sebagai lampiran pembuktian transparansi AI dan pengisian berkas `AI_Usage_Declaration_Form_EN.docx`.

---

### 1. ⚠️ Potongan Kode Sebelum Konsultasi AI (Mengandung Pemborosan Memori & Kelemahan Validasi)

Pada perancangan awal struktur data sistem katalog perpustakaan, seluruh atribut Buku dan Majalah digabungkan dalam satu `struct` besar, serta tidak ada proteksi jika user memasukkan pilihan tipe media yang salah:

```c
// ========================================================
// KODE SEBELUM KONSULTASI AI (Desain Struct Monolitik)
// ========================================================
#include <stdio.h>

// STRUKTUR DATA TIDAK EFISIEN: Semua atribut digabung ke struct
typedef struct {
    char judul[100];
    int tahun_terbit;
    int jenis_media;          // 1: Buku, 2: Majalah
    
    // Atribut Buku
    char penulis[50];
    int jumlah_halaman;
    
    // Atribut Majalah
    int nomor_edisi;
    char bulan_terbit[20];
} ItemKatalogBiasa;

void input_item(ItemKatalogBiasa *item) {
    printf("Masukkan Judul: "); scanf(" %[^\n]", item->judul);
    printf("Masukkan Tahun: "); scanf("%d", &item->tahun_terbit);
    printf("Pilih Media (1. Buku, 2. Majalah): ");
    
    // MASALAH: Tanpa validasi pilihan
    scanf("%d", &item->jenis_media);
    
    if (item->jenis_media == 1) {
        printf("Penulis: "); scanf(" %[^\n]", item->penulis);
        printf("Halaman: "); scanf("%d", &item->jumlah_halaman);
    } else {
        // Jika user ketik angka 3 atau 9, otomatis dianggap majalah!
        printf("Edisi  : "); scanf("%d", &item->nomor_edisi);
        printf("Bulan  : "); scanf(" %[^\n]", item->bulan_terbit);
    }
}
```

#### Masalah / Gejala pada Kode Awal:
1. **Pemborosan Alokasi Memori (*Wasted Memory Allocation*):** Setiap item katalog memesan ruang untuk atribut Buku **DAN** Majalah sekaligus. Jika perpustakaan menyimpan 10.000 item buku, ruang untuk nomor edisi dan bulan terbit majalah tetap teralokasi sia-sia di RAM server.
2. **Ketiadaan Validasi Seleksi Jenis Media:** Pemilihan media hanya menggunakan `if-else`. Jika pengguna memasukkan angka `3`, `0`, atau `-1`, program secara keliru mengeksekusi blok Majalah.
3. **Risiko Buffer Overflow:** Input string tidak memiliki batasan pembacaan karakter.

---

### 2. 💬 Prompt / Pertanyaan yang Diajukan ke AI Assistant

```text
"Halo, saya sedang merancang struktur data katalog perpustakaan digital di bahasa C (Soal 1 DCCA) untuk menyimpan Judul, Tahun Terbit, serta Jenis Media (Buku atau Majalah). 
Studi kasus mensyaratkan agar struktur data dirancang sehemat mungkin menggunakan union karena kapasitas server awal sangat terbatas.

1. Bagaimana arsitektur 'Tagged Union' yang ideal di bahasa C menggunakan kombinasi struct, enum, dan union sesuai materi LN07 Binus?
2. Bagaimana cara menghitung penghematan byte memori (sizeof) secara teoritis antara struct biasa vs union?
3. Bagaimana menambahkan validasi input agar pengguna hanya bisa memilih opsi 1 (Buku) atau 2 (Majalah) secara aman?"
```

---

### 3. 🧠 Jawaban dan Evaluasi dari AI Code Assistant

> **Evaluasi AI:**
> 1. **Penerapan Konsep Tagged Union (*Variant Record*):**  
>    Gunakan pendekatan berlapis:
>    - Buat `struct InfoBuku` (penulis, jumlah halaman) dan `struct InfoMajalah` (nomor edisi, bulan terbit).
>    - Bungkus keduanya ke dalam `union DetailMedia`. Karena buku dan majalah tidak pernah ada bersamaan dalam satu entitas fisik, memori yang dialokasikan oleh `union` hanyalah sebesar ukuran anggota terbesarnya: $\max(\text{sizeof}(InfoBuku), \text{sizeof}(InfoMajalah))$.
>    - Bungkus ke dalam `struct ItemKatalog` yang memuat data umum (judul, tahun terbit, tag `enum JenisMedia`, dan `union DetailMedia`).
> 
> 2. **Perhitungan Analisis Efisiensi Memori (*Memory Footprint*):**  
>    - `sizeof(InfoBuku)` = $50\text{ byte} + 4\text{ byte} = \mathbf{54\text{ byte}}$
>    - `sizeof(InfoMajalah)` = $4\text{ byte} + 20\text{ byte} = \mathbf{24\text{ byte}}$
>    - Jika menggunakan `struct` biasa: Memori media = $54 + 24 = \mathbf{78\text{ byte}}$.
>    - Jika menggunakan `union`: Memori media = $\max(54, 24) = \mathbf{54\text{ byte}}$.
>    - **Efisiensi:** Menghemat $\mathbf{24\text{ byte}}$ ($\approx 30.7\%$) untuk setiap item koleksi.
> 
> 3. **Validasi Loop Input dengan Pembersihan Buffer:**  
>    Gunakan perulangan `while (scanf("%d", &pilihan) != 1 || (pilihan != MEDIA_BUKU && pilihan != MEDIA_MAJALAH))` disertai pembersihan sisa buffer `while (getchar() != '\n');` agar input non-angka atau angka salah tidak menyebabkan loop tak terhingga (*infinite loop*).

---

### 4. ✅ Perubahan Nyata pada Kode Setelah Konsultasi AI (Hasil Perbaikan)

Berikut adalah kode yang telah disempurnakan dan diterapkan pada berkas `DCCA/question_1.c`:

```c
// ========================================================
// KODE SESUDAH KONSULTASI AI (Telah Diperbaiki & Sesuai)
// ========================================================
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

// 1. UNION: Mengalokasikan memori sebesar anggota terbesarnya (54 byte)
typedef union {
    InfoBuku buku;
    InfoMajalah majalah;
} DetailMedia;

// 2. STRUCT UTAMA (Tagged Union)
typedef struct {
    char judul[100];
    int tahun_terbit;
    JenisMedia tipe;
    DetailMedia detail;
} ItemKatalog;

void input_item(ItemKatalog *item) {
    printf("=== FORM INPUT KOLEKSI PERPUSTAKAAN ===\n");
    printf("Masukkan Judul Buku/Majalah : ");
    scanf(" %99[^\n]", item->judul);
    printf("Masukkan Tahun Terbit       : ");
    scanf("%d", &item->tahun_terbit);
    
    // 3. Validasi ketat pemilihan jenis media
    printf("Pilih Jenis Media (1. Buku, 2. Majalah): ");
    int pilihan = 0;
    while (scanf("%d", &pilihan) != 1 || (pilihan != MEDIA_BUKU && pilihan != MEDIA_MAJALAH)) {
        printf("Pilihan tidak valid! Masukkan 1 untuk Buku atau 2 untuk Majalah: ");
        while (getchar() != '\n'); // Bersihkan sisa newline
    }
    item->tipe = (JenisMedia)pilihan;

    // 4. Input atribut spesifik sesuai media yang aktif
    if (item->tipe == MEDIA_BUKU) {
        printf("Masukkan Nama Penulis       : ");
        scanf(" %49[^\n]", item->detail.buku.penulis);
        printf("Masukkan Jumlah Halaman     : ");
        scanf("%d", &item->detail.buku.jumlah_halaman);
    } else if (item->tipe == MEDIA_MAJALAH) {
        printf("Masukkan Nomor Edisi        : ");
        scanf("%d", &item->detail.majalah.nomor_edisi);
        printf("Masukkan Bulan Terbit       : ");
        scanf(" %19[^\n]", item->detail.majalah.bulan_terbit);
    }
}

void tampilkan_item(const ItemKatalog *item) {
    printf("\n=== DETAIL KOLEKSI PERPUSTAKAAN ===\n");
    printf("Judul         : %s\n", item->judul);
    printf("Tahun Terbit  : %d\n", item->tahun_terbit);
    
    if (item->tipe == MEDIA_BUKU) {
        printf("Tipe Media    : Buku\n");
        printf("Penulis       : %s\n", item->detail.buku.penulis);
        printf("Jumlah Halaman: %d\n", item->detail.buku.jumlah_halaman);
    } else {
        printf("Tipe Media    : Majalah\n");
        printf("Nomor Edisi   : %d\n", item->detail.majalah.nomor_edisi);
        printf("Bulan Terbit  : %s\n", item->detail.majalah.bulan_terbit);
    }
}

int main(void) {
    ItemKatalog item;
    input_item(&item);
    tampilkan_item(&item);
    return 0;
}
```

#### Ringkasan Perbaikan yang Diterapkan:
* `+` Mengganti desain struct monolitik menjadi arsitektur Tagged Union (`struct` + `union` + `enum`) yang menghemat memori media sebesar 30.7%.
* `+` Menambahkan kontrol perulangan `while` dengan verifikasi input angka 1 dan 2 untuk mencegah input tidak valid.
* `+` Melindungi formatted string `scanf` dengan field width specifier guna menjamin integritas memori.

---

### 5. 📝 Refleksi Singkat (4 Kalimat)

> Melalui konsultasi bersama AI Code Assistant, kami memahami keunggulan arsitektur *Tagged Union* di mana tipe `union` secara efisien membagi blok memori yang sama untuk struktur data yang bersifat saling eksklusif (*mutually exclusive*). Kami mampu membuktikan penghematan memori secara kuantitatif sebesar 24 byte (sekitar 30,7%) per entri koleksi karena memori media hanya dialokasikan sebesar atribut terbesar yaitu `InfoBuku`. Sebagai perbaikan konkret pada `question_1.c`, kami merestrukturisasi deklarasi data dengan membungkus atribut spesifik ke dalam `union DetailMedia` serta menambahkan validasi loop seleksi jenis media yang ketat. Pemahaman ini sangat membantu kami dalam merancang sistem katalog yang hemat memori sekaligus kebal terhadap input pengguna yang salah.
