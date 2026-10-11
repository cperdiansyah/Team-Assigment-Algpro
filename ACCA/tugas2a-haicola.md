# 🤖 DOKUMENTASI HAICOLA — TUGAS 2A (DATA PEGAWAI & GAJI POKOK)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** ACCA - LAB  
**Kelompok:** Group 1  
**Topik Evaluasi:** Validasi Perbandingan String Golongan (`strcmp()`) & Pencegahan *Buffer Overflow* pada Input `struct` (Tugas 2A)  

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

---

### 2. 💬 Prompt / Pertanyaan yang Diajukan ke AI Assistant

```text
"Halo, saya sedang membuat program C (Tugas 2A) untuk mengelola data struct Pegawai dan menentukan gaji pokok otomatis berdasarkan golongan (D1: Rp 3.000.000, D2: Rp 2.500.000, D3: Rp 2.000.000).

Mengapa fungsi penentuan gaji pokok saya selalu mengembalikan angka 0 padahal input sudah benar 'D1'? Apakah salah membandingkan string dengan 'golongan == "D1"' di bahasa C? 
Bagaimana cara perbaikan yang sesuai dengan silabus dasar C (mengacu pada Modul Praktikum 2 & 3 Binus)? Selain itu, bagaimana cara mengamankan scanf dari risiko buffer overflow dan memvalidasi jika input golongan tidak valid?"
```

---

### 3. 🧠 Jawaban dan Evaluasi dari AI Code Assistant

> **Evaluasi AI:**
> 1. **Mekanisme Perbandingan String di C (`strcmp`):**  
>    Pada bahasa C, tipe string adalah array karakter (`char[]`). Operator `==` hanya membandingkan alamat memori dasar array dengan literal string, bukan isi karakternya. Untuk membandingkan isi string secara leksikografis, gunakan fungsi `strcmp()` dari library `<string.h>` (diajarkan pada Modul Praktikum 2 Halaman 6). Jika `strcmp(golongan, "D1") == 0`, berarti kedua string bernilai sama persis.
> 
> 2. **Pencegahan Buffer Overflow (*Field Width Specifier*):**  
>    Array seperti `char nip[20]` hanya dapat menampung 19 karakter teks ditambah 1 karakter null-terminator `\0`. Pada `scanf`, tambahkan batas lebar field: `%19s`, `%49[^\n]`, `%99[^\n]` agar input berlebih tidak menimpa variabel lain di memori.
> 
> 3. **Validasi Nilai Balik (*Graceful Handling*):**  
>    Fungsi `tentukan_gaji_pokok()` dapat mengembalikan `0` sebagai penanda bahwa golongan tidak dikenali, dan fungsi `main()` harus memeriksa jika nilai tersebut `0` untuk memberikan pesan peringatan ke pengguna.

---

### 4. ✅ Perubahan Nyata pada Kode Setelah Konsultasi AI (Hasil Perbaikan)

Berikut adalah kode yang telah disempurnakan dan diterapkan pada berkas `ACCA/tugas2a.c`:

```c
// ========================================================
// KODE SESUDAH KONSULTASI AI (Telah Diperbaiki & Sesuai)
// ========================================================
#include <stdio.h>
#include <string.h>

typedef struct {
    char nip[20];
    char nama[50];
    char alamat[100];
    char no_hp[20];
    char jabatan[30];
    char golongan[5];       // "D1", "D2", atau "D3"
    int gaji_pokok;
} Pegawai;

int tentukan_gaji_pokok(const char *golongan) {
    // 1. Menggunakan strcmp() standar sesuai Modul Praktikum 2
    if (strcmp(golongan, "D1") == 0) return 3000000;
    else if (strcmp(golongan, "D2") == 0) return 2500000;
    else if (strcmp(golongan, "D3") == 0) return 2000000;
    
    return 0; // Mengindikasikan golongan tidak valid
}

int main(void) {
    Pegawai p = {0};

    printf("===================================================\n");
    printf("   SISTEM DATA PEGAWAI & GAJI POKOK (TUGAS 2A)     \n");
    printf("===================================================\n");

    // 2. Proteksi buffer overflow menggunakan field width specifier
    printf("Masukkan NIP    : "); scanf(" %19s", p.nip);
    printf("Masukkan Nama   : "); scanf(" %49[^\n]", p.nama);
    printf("Masukkan Alamat : "); scanf(" %99[^\n]", p.alamat);
    printf("Masukkan No HP  : "); scanf(" %19s", p.no_hp);
    printf("Masukkan Jabatan: "); scanf(" %29[^\n]", p.jabatan);
    printf("Masukkan Golongan (D1/D2/D3): "); scanf(" %4s", p.golongan);

    // 3. Tentukan gaji pokok dan validasi hasilnya
    p.gaji_pokok = tentukan_gaji_pokok(p.golongan);
    if (p.gaji_pokok == 0) {
        printf("\nPeringatan: Golongan '%s' tidak valid! Harap masukkan D1, D2, atau D3.\n", p.golongan);
        return 1;
    }

    // 4. Tampilkan data lengkap
    printf("\n=== DATA LENGKAP PEGAWAI ===\n");
    printf("NIP         = %s\n", p.nip);
    printf("Nama        = %s\n", p.nama);
    printf("Alamat      = %s\n", p.alamat);
    printf("No HP       = %s\n", p.no_hp);
    printf("Jabatan     = %s\n", p.jabatan);
    printf("Golongan    = %s\n", p.golongan);
    printf("Gaji Pokok  = Rp %d\n", p.gaji_pokok);

    return 0;
}
```

#### Ringkasan Perbaikan yang Diterapkan:
* `+` Mengganti evaluasi kesetaraan string dari operator `==` menjadi fungsi leksikografis `strcmp()` dari `<string.h>`.
* `+` Membatasi panjang pembacaan `scanf` (`%19s`, `%49[^\n]`, dll) untuk mencegah kerentanan fatal *buffer overflow*.
* `+` Menambahkan penanganan kondisi jika golongan yang dimasukkan di luar `D1`, `D2`, atau `D3`.

---

### 5. 📝 Refleksi Singkat (4 Kalimat)

> Melalui konsultasi dengan AI Code Assistant, kami menyadari bahwa perbandingan string pada bahasa C harus menggunakan fungsi leksikografis `strcmp()` karena operator `==` hanya mengevaluasi kesamaan alamat memori pointer. Kami juga memperoleh pemahaman mendalam mengenai pentingnya *field width specifier* pada formatted input `scanf` guna melindungi memori struct dari ancaman *buffer overflow*. Sebagai wujud perbaikan konkret pada `tugas2a.c`, kami menerapkan fungsi `strcmp()`, membatasi lebar karakter input, serta menambahkan validasi penolakan jika golongan yang dimasukkan tidak terdaftar. Pemanfaatan AI ini sangat bermanfaat untuk memperkuat keamanan memori dan keakuratan logika branching program kami.
