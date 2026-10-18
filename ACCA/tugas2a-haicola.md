# 🤖 DOKUMENTASI HAICOLA — TUGAS 2A (DATA PEGAWAI & GAJI POKOK)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** ACCA - LAB  
**Kelompok:** Group 1  
**Topik Evaluasi:** Validasi Perbandingan String Golongan (`strcmp()`), Penanganan Normalisasi Huruf (`toupper`), dan Format Tampilan Data Lengkap Pegawai (Tugas 2A)  

---

> 📌 **Catatan untuk Rekan Tim:**  
> Berkas ini berisi dokumentasi resmi sesi **HAICOLA (Human-AI Collaboration)** untuk modul **Tugas 2A**. Dokumen ini siap digunakan sebagai lampiran pembuktian transparansi AI dan pengisian berkas `AI_Usage_Declaration_Form_EN.docx`.

---

### 1. ⚠️ Potongan Kode Sebelum Konsultasi AI (Mengandung Potensi Bug)

Pada penulisan awal logika struktur pegawai dan penentuan gaji pokok di `tugas2a.c`, kode ditulis dengan membandingkan string menggunakan operator kesetaraan `==` dan `scanf` tanpa batas karakter:

```c
// ========================================================
// KODE SEBELUM KONSULTASI AI (Tugas 2A - Data Pegawai)
// ========================================================
#include <stdio.h>

typedef struct {
    char nip[20];
    char nama[50];
    char alamat[100];
    char no_hp[20];
    char jabatan[30];
    char golongan[5];
    int gaji_pokok;
} Pegawai;

int tentukan_gaji_pokok(char golongan[]) {
    // BUG LOGIKA: Membandingkan array string dengan operator ==
    if (golongan == "D1") return 3000000;
    else if (golongan == "D2") return 2500000;
    else if (golongan == "D3") return 2000000;
    return 0;
}

int main(void) {
    Pegawai p;
    // VULNERABILITAS: scanf string tanpa batas lebar (buffer overflow)
    printf("Masukkan NIP    : "); scanf("%s", p.nip);
    printf("Masukkan Nama   : "); scanf(" %[^\n]", p.nama);
    printf("Masukkan Golongan: "); scanf("%s", p.golongan);

    p.gaji_pokok = tentukan_gaji_pokok(p.golongan);
    printf("Gaji Pokok: Rp %d\n", p.gaji_pokok);
    return 0;
}
```

#### Masalah / Gejala Bug pada Kode Awal:
1. **Gaji Pokok Selalu Menghasilkan Rp 0:** Evaluasi `if (golongan == "D1")` selalu bernilai `false` meskipun pengguna mengetik `"D1"`. Di bahasa C, operator `==` membandingkan alamat memori pointer, bukan konten teks string.
2. **Potensi Kerentanan *Buffer Overflow*:** Penggunaan format specifier `%s` dan `%[^\n]` tanpa batasan ukuran karakter rentan mengalami kebocoran buffer memori jika pengguna memasukkan karakter yang melebihi kapasitas array.
3. **Ketiadaan Validasi Golongan Tidak Dikenal:** Jika user menginput golongan di luar D1, D2, atau D3, program tidak memberikan peringatan kesalahan.
4. **Data Pegawai Lengkap Belum Ditampilkan:** Soal meminta untuk menampilkan data pegawai lengkap dari struct beserta gaji pokoknya, namun kode awal hanya mencetak gaji tanpa profil pegawai.
5. **Format Cetak Mata Uang Tidak Standar:** Angka gaji hanya dicetak angka mentah (`Rp 2500000`), tidak memiliki pemisah ribuan titik (`Rp2.500.000`).

---

### 2. 💬 Prompt / Pertanyaan yang Diajukan ke AI Assistant

```text
"Halo, saya sedang membuat program C (Tugas 2A) untuk mengelola data struct Pegawai dan menentukan gaji pokok otomatis berdasarkan golongan (D1: Rp 3.000.000, D2: Rp 2.500.000, D3: Rp 2.000.000).

Mengapa fungsi penentuan gaji pokok saya selalu mengembalikan angka 0 padahal input sudah benar 'D1'? Apakah salah membandingkan string dengan 'golongan == "D1"' di bahasa C? 
Bagaimana cara perbaikan yang sesuai dengan silabus dasar C (mengacu pada Modul Praktikum 2 & 3 Binus)? Selain itu, bagaimana cara mengamankan scanf dari risiko buffer overflow, menormalkan huruf kecil (d2 -> D2) secara portabel, menampilkan profil pegawai lengkap dari struct, serta memformat tampilan output Rupiah dengan pemisah titik (misal: 'Rp2.500.000')?"
```

---

### 3. 🧠 Jawaban dan Evaluasi dari AI Code Assistant

> **Evaluasi AI:**
> 1. **Mekanisme Perbandingan String di C (`strcmp`):**  
>    Pada bahasa C, tipe string adalah array karakter (`char[]`). Operator `==` hanya membandingkan alamat memori dasar array dengan literal string, bukan isi karakternya. Untuk membandingkan isi string secara leksikografis, gunakan fungsi `strcmp()` dari library `<string.h>` (diajarkan pada Modul Praktikum 2 Halaman 6). Jika `strcmp(golongan, "D1") == 0`, berarti kedua string bernilai sama persis.
> 
> 2. **Normalisasi String Portabel (`toupper`):**  
>    Hindari fungsi non-standar seperti `strcasecmp` karena tidak tersedia di compiler Windows/MSVC. Cara standar ANSI C adalah melakukan perulangan pada string golongan dan mengonversi tiap karakter dengan `toupper((unsigned char)golongan[i])` sebelum perbandingan string.
> 
> 3. **Pencegahan Buffer Overflow (*Field Width Specifier*):**  
>    Array seperti `char nip[20]` hanya dapat menampung 19 karakter teks ditambah 1 karakter null-terminator `\0`. Pada `scanf`, tambahkan batas lebar field: `%19[^\n]`, `%49[^\n]`, `%99[^\n]` agar input berlebih tidak menimpa variabel lain di memori.
> 
> 4. **Penyajian Data Pegawai Lengkap:**  
>    Sesuai instruksi soal "Menampilkan data pegawai lengkap berikut gaji pokok", tampilkan seluruh atribut dari struct (`p.nip`, `p.nama`, `p.alamat`, `p.no_hp`, `p.jabatan`, `p.golongan`, `p.gaji_pokok`).
> 
> 5. **Fungsi Sederhana Cetak Rupiah Bertitik (`cetak_rupiah`):**  
>    Gunakan fungsi `cetak_rupiah(int n)` yang mengubah angka ke teks via `sprintf` dan menyisipkan tanda titik setiap kelipatan 3 digit dari kanan sehingga menghasilkan `Rp2.500.000` sesuai dengan tangkapan layar dosen (`image1.png`).

---

### 4. ✅ Perubahan Nyata pada Kode Setelah Konsultasi AI (Hasil Perbaikan)

Berikut adalah kode yang telah disempurnakan dan diterapkan pada berkas `ACCA/tugas2a.c`:

```c
// ========================================================
// KODE SESUDAH KONSULTASI AI (Telah Diperbaiki & Sesuai)
// ========================================================
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
    printf("Masukkan Golongan   : "); scanf(" %4s", p.golongan);

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
```

#### Ringkasan Perbaikan yang Diterapkan:
* `+` Mengganti evaluasi kesetaraan string dari operator `==` menjadi fungsi leksikografis `strcmp()` dari `<string.h>`.
* `+` Menambahkan normalisasi `toupper()` sehingga input huruf kecil (misal `d2`) otomatis menjadi `D2` secara portabel di semua sistem operasi/compiler.
* `+` Membatasi panjang pembacaan `scanf` (`%19[^\n]`, `%49[^\n]`, dll) untuk mencegah kerentanan fatal *buffer overflow*.
* `+` Menampilkan data profil pegawai lengkap dari struct (`p.nip`, `p.nama`, `p.alamat`, dll) sekaligus baris `Gaji Pokok Anda:` untuk memenuhi seluruh spesifikasi soal.
* `+` Menambahkan fungsi helper `cetak_rupiah()` untuk menghasilkan format mata uang bertitik (`Rp2.500.000`).

---

### 5. 📝 Refleksi Singkat (4 Kalimat)

> Melalui konsultasi dengan AI Code Assistant, kami menyadari bahwa perbandingan string pada bahasa C harus menggunakan fungsi leksikografis `strcmp()` serta didukung normalisasi karakter `toupper()` agar kode bersifat portabel di berbagai compiler tanpa mengandalkan ekstensi non-standar. Kami juga memahami pentingnya membatasi lebar buffer pada `scanf` demi mencegah terjadinya *buffer overflow*. Sebagai perbaikan konkret pada `tugas2a.c`, kami menerapkan fungsi `strcmp()`, menormalkan huruf golongan, menampilkan seluruh field struct pegawai secara lengkap, serta memformat output nominal ke standar Rupiah bertitik via fungsi `cetak_rupiah()`. Bantuan AI ini terbukti sangat bernilai dalam memperkuat keandalan memori, portabilitas lintas platform, dan kepatuhan penuh terhadap rubrik studi kasus.
