# 🤖 DOKUMENTASI HAICOLA — TUGAS 1 DCCA 2 (SISTEM MANAJEMEN FILE DATABASE SISWA)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** DCCA - LEC  
**Kelompok:** Group 1  
**Topik Evaluasi:** Arsitektur File Handling I/O (`fopen`, `fgets`, `fprintf`, `fclose`), Operasi CRUD Teks Delimited (`|`), Strategi Hapus *Safe Temporary File Filter*, dan Efisiensi *Line-by-Line Streaming Buffer* vs *Full Dynamic Array Load* (Tugas 1 TK2)  

---

> 📌 **Catatan untuk Rekan Tim:**  
> Berkas ini berisi dokumentasi resmi sesi **HAICOLA (Human-AI Collaboration)** untuk modul **DCCA 2 Tugas 1**. Dokumen ini siap digunakan sebagai lampiran pembuktian transparansi pemanfaatan AI dan pengisian formulir resmi `AI_Usage_Declaration_Form_EN.docx`.

---

### 1. ⚠️ Potongan Kode / Desain Sebelum Konsultasi AI (Rancangan Naif & Berisiko Data Loss)

Pada perancangan awal sistem database siswa berbasis file teks, terdapat pendekatan naif di mana seluruh isi file dibaca ke dalam memori (*in-memory array*), dan operasi penghapusan dilakukan dengan membuka file langsung menggunakan mode *write* (`"w"`):

```c
// ========================================================
// KODE SEBELUM KONSULTASI AI (Desain Naif & Rawan Bencana)
// ========================================================
#include <stdio.h>
#include <string.h>

// MASALAH 1: Format CSV berbasis koma (rentan crash jika nama mengandung gelar koma)
// MASALAH 2: Menggunakan in-memory array fixed capacity (boros RAM & rentan buffer overflow)
typedef struct {
    char noreg[20];
    char nama[50];
    int umur;
} Siswa;

Siswa daftar_siswa[1000];
int total = 0;

void hapus_siswa_naif(const char *target_noreg) {
    FILE *fp;
    int i;
    
    // BACA SEMUA KE MEMORI
    fp = fopen("siswa.txt", "r");
    total = 0;
    while (fscanf(fp, "%[^,],%[^,],%d\n", daftar_siswa[total].noreg, 
                  daftar_siswa[total].nama, &daftar_siswa[total].umur) == 3) {
        total++;
    }
    fclose(fp);

    // KESALAHAN FATAL: Membuka file dengan mode "w" sebelum data aman
    // Jika sistem mati lampu / crash di sini, seluruh data SISWA.TXT HILANG TOTAL!
    fp = fopen("siswa.txt", "w");
    for (i = 0; i < total; i++) {
        if (strcmp(daftar_siswa[i].noreg, target_noreg) != 0) {
            fprintf(fp, "%s,%s,%d\n", daftar_siswa[i].noreg, 
                    daftar_siswa[i].nama, daftar_siswa[i].umur);
        }
    }
    fclose(fp);
}
```

#### Masalah / Gejala pada Kode Awal:
1. **Risiko Kehilangan Data Total (*Catastrophic Data Loss Risk*):**  
   Membuka file asli langsung dengan mode `"w"` seketika memotong isi file menjadi 0 byte (*truncate*). Jika sistem operasi mengalami pemadaman daya (*blackout*), aplikasi *crash*, atau kehabisan memori sebelum loop penulisan selesai, seluruh rekaman database siswa musnah permanen.
2. **Tabrakan Delimiter (*Delimiter Collision*):**  
   Penggunaan koma (`,`) sebagai pemisah rentan rusak ketika membaca nama siswa yang memiliki gelar atau tanda koma (contoh data nyata: `"Siti Nurhaliza, S.Kom"` atau `"Putri Wulandari, S.T."`).
3. **Pemborosan Memori dan Keterbatasan Skalabilitas ($O(N)$ Space):**  
   Menampung seluruh basis data ke dalam array di RAM membatasi kapasitas maksimum data dan memicu *heap exhaustion* / *Out of Memory* (OOM) saat ukuran file mencapai ribuan rekaman.
4. **Ketiadaan Validasi File Pointer:**  
   Tidak ada pengecekan `if (fp == NULL)`, sehingga jika file belum ada atau terkunci oleh proses lain, program langsung memicu sinyal `SIGSEGV` (*Segmentation Fault*).

---

### 2. 💬 Prompt / Pertanyaan yang Diajukan ke AI Assistant

```text
"Halo, kelompok kami sedang merancang sistem manajemen data siswa berbasis file teks di bahasa C untuk Tugas 1 DCCA 2 (File Handling). Sistem harus mendukung 3 operasi utama:
1. Menambah data siswa (noreg, nama lengkap, umur).
2. Mencari data siswa berdasarkan nomor registrasi unik.
3. Menghapus data siswa berdasarkan nomor registrasi.

Pertanyaan kami:
1. Bagaimana pola perancangan file I/O yang paling aman di bahasa C untuk operasi penghapusan data teks tanpa risiko kehilangan data jika sistem mati di tengah jalan (Safe Temporary File Pattern)?
2. Karakter pemisah (delimiter) apa yang paling aman digunakan agar nama siswa yang memiliki gelar akademik berkoma tidak merusak parsing data?
3. Mengapa pendekatan pembacaan 'Line-by-Line Streaming' (O(1) memory) jauh lebih unggul dibandingkan meload seluruh file ke memory array (O(N) memory), dan bagaimana perbandingannya secara teknis?
4. Bagaimana arsitektur Pseudocode dan Flowchart berstandar ISO untuk ketiga modul tersebut?"
```

---

### 3. 🧠 Jawaban dan Evaluasi dari AI Code Assistant

> **Evaluasi AI:**
> 1. **Penerapan Pola *Safe Temporary File Filter Pattern*:**  
>    Jangan pernah membuka file database utama dengan mode `"w"` saat memodifikasi atau menghapus record. Pola terbaik adalah:
>    - Buka file sumber `siswa.txt` dalam mode baca `"r"`.
>    - Buka file sementara `temp_siswa.txt` dalam mode tulis `"w"`.
>    - Alirkan data baris demi baris: lewati baris yang nomor registrasinya cocok dengan target, dan salin baris lainnya ke file sementara.
>    - Tutup kedua file (`fclose`), lalu gunakan operasi atomik OS: `remove("siswa.txt")` dan `rename("temp_siswa.txt", "siswa.txt")`. Jika proses crash di tengah jalan, file asli tetap utuh 100%.
>
> 2. **Standardisasi Delimiter Karakter Pipa (`|`):**  
>    Gunakan pemisah pipa (`|`) dengan struktur `noreg|nama|umur\n`. Karakter ini sangat jarang digunakan dalam penulisan nama orang, gelar akademik, maupun alamat, sehingga parsing dengan `sscanf()` atau `strtok()` dijamin bebas konflik.
>
> 3. **Efisiensi Arsitektur *Line-by-Line Streaming* ($O(1)$ Space):**  
>    - **Pola In-Memory Array:** Membutuhkan memori $O(N)$. Untuk $1.000.000$ siswa, program memakan puluhan megabyte RAM dan rentan crash.
>    - **Pola Line-by-Line Streaming:** Hanya membutuhkan buffer lokal sebesar satu baris (misal `char line[256]` di Stack). Kompleksitas memori menjadi konstan $\mathbf{O(1)}$ terlepas dari apakah file berisi 10 baris atau 10 juta baris.
>
> 4. **Manajemen Buffer I/O C Runtime:**  
>    Pemanggilan `fopen()` mengalokasikan internal buffer (`BUFSIZ`). Pemanggilan `fclose()` wajib dilakukan untuk memicu *buffer flushing* ke disk fisik.

---

### 4. ✅ Perubahan Nyata pada Desain & Kode Setelah Konsultasi AI (Hasil Perbaikan)

Berdasarkan konsultasi di atas, seluruh modul Tugas 1 distandardisasi menggunakan arsitektur *Safe Temporary File* dan *Line-by-Line Streaming* dengan pemisah pipa `|`.

Berikut adalah implementasi fungsi inti yang telah disempurnakan:

```c
// ========================================================
// KODE SESUDAH KONSULTASI AI (Robust, Aman, & Hemat Memori)
// ========================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_FILE "siswa.txt"
#define TEMP_FILE "temp_siswa.txt"
#define MAX_LINE 256

typedef struct {
    char noreg[16];
    char nama[50];
    int umur;
} Siswa;

// 1. OPERASI TAMBAH DATA (Mode "a" / Append Persisten)
int tambah_siswa(const Siswa *s) {
    FILE *fp = fopen(DB_FILE, "a");
    if (fp == NULL) {
        perror("[!] Gagal membuka file database untuk penambahan");
        return 0;
    }
    // Tulis baris dengan delimiter pipa |
    fprintf(fp, "%s|%s|%d\n", s->noreg, s->nama, s->umur);
    fclose(fp); // Flush buffer seketika ke disk
    return 1;
}

// 2. OPERASI CARI DATA (Line-by-Line Streaming, O(1) Memory)
int cari_siswa(const char *target_noreg, Siswa *hasil) {
    FILE *fp = fopen(DB_FILE, "r");
    char line[MAX_LINE];
    char curr_noreg[16], curr_nama[50];
    int curr_umur;
    int found = 0;

    if (fp == NULL) return 0; // Database kosong atau belum ada

    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parsing aman delimited |
        if (sscanf(line, "%15[^|]|%49[^|]|%d", curr_noreg, curr_nama, &curr_umur) == 3) {
            if (strcmp(curr_noreg, target_noreg) == 0) {
                strcpy(hasil->noreg, curr_noreg);
                strcpy(hasil->nama, curr_nama);
                hasil->umur = curr_umur;
                found = 1;
                break; // Stop sekuensial setelah primary key cocok
            }
        }
    }
    fclose(fp);
    return found;
}

// 3. OPERASI HAPUS DATA (Safe Temporary File Filter Pattern)
int hapus_siswa(const char *target_noreg) {
    FILE *src = fopen(DB_FILE, "r");
    FILE *temp = fopen(TEMP_FILE, "w");
    char line[MAX_LINE];
    char curr_noreg[16];
    int found = 0;

    if (src == NULL || temp == NULL) {
        if (src) fclose(src);
        if (temp) fclose(temp);
        return 0;
    }

    while (fgets(line, sizeof(line), src) != NULL) {
        if (sscanf(line, "%15[^|]|", curr_noreg) == 1) {
            if (strcmp(curr_noreg, target_noreg) == 0) {
                found = 1; // Lewati penulisan ke temp_file
                continue;
            }
        }
        fputs(line, temp);
    }

    fclose(src);
    fclose(temp);

    if (found) {
        remove(DB_FILE);               // Hapus file lama
        rename(TEMP_FILE, DB_FILE);     // Ganti nama temp menjadi nama asli
        return 1;
    } else {
        remove(TEMP_FILE);             // Bersihkan temp jika tidak ada yang cocok
        return 0;
    }
}
```

---

### 5. 📊 Rangkuman Dampak Optimasi AI pada Tugas 1

| Indikator Evaluasi | Desain Awal Tim | Solusi Rekomendasi AI (Final) | Dampak & Manfaat Nyata |
| :--- | :--- | :--- | :--- |
| **Metode Penghapusan** | *Direct Write Truncate* (`"w"`) | *Safe Temporary File Filter* | **Eliminasi 100% risiko data hilang** jika sistem mati mendadak |
| **Delimiter Kolom** | Koma (`,`) | Karakter Pipa (`\|`) | **Aman dari konflik parsing nama bergelar** (`"Siti, S.Kom"`) |
| **Konsumsi Memori RAM** | $O(N)$ (Array besar di RAM) | $O(1)$ (Stack buffer 256 B) | **Jejak RAM stabil konstan**, mencegah *Out of Memory* |
| **Integritas Transaksi** | Tidak ada rollback | Operasi atomik `remove()` + `rename()` | Konsistensi data setara database komersial |
