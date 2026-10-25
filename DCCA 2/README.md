# 📘 PANDUAN & INSTRUKSI TUGAS KELOMPOK KE-2 (TK2)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** DCCA - LEC  
**Dosen Pengampu:** D5816 - ERIC GUNAWAN, S.Kom., M.TI  
**Minggu Kuliah:** Week 8 (Sesi 21 - R3)  
**Topik Pembelajaran:** File Handling (I/O) & Dynamic Memory Allocation  
**Koordinator Kelompok:** Chandra Perdiansyah (Chan)

---

## 🚀 Halo Tim! (Wajib Dibaca Sebelum Mengerjakan)

Dokumen ini adalah **panduan utama (Single Source of Truth)** untuk pengerjaan TK2.  
Tujuan dibuatnya panduan ini adalah agar kita semua punya **standar desain yang seragam**, pembagian tugas yang **adil dan jelas**, serta tidak ada bagian yang bentrok saat digabungkan nanti.

> [!IMPORTANT]
> **Prinsip Utama:** Setiap anggota bertanggung jawab penuh atas modul/bagiannya masing-masing. Silakan kerjakan draf kalian menggunakan template yang sudah disiapkan di folder `templates/`.

---

## 📂 Struktur Folder Proyek

```text
DCCA 2/
├── README.md                           <-- (File ini) Panduan & instruksi lengkap untuk tim
├── TK2-W8-S21-R3 - Jawaban Lengkap.md   <-- File laporan akhir yang akan di-merge oleh Chan
├── tugas1-haicola.md                   <-- Dokumentasi resmi sesi HAICOLA Tugas 1 (File I/O)
├── tugas2-haicola.md                   <-- Dokumentasi resmi sesi HAICOLA Tugas 2 (Dynamic Memory)
├── siswa.txt                           <-- Contoh file database fisik data siswa (sample data)
│
├── 📁 templates/                       <-- Tempat kalian mengerjakan tugas masing-masing
│   ├── template_tugas1_operasi.md      <-- Template untuk Anggota 2 (Tambah), 3 (Cari), 4 (Hapus)
│   └── template_tugas2_memory.md       <-- Template untuk Anggota 5 (Tugas 2 Alokasi Memori)
│
├── 📁 src/                             <-- Folder kode C
│   ├── question_2_buggy.c              <-- Kode asli bermasalah dari soal (untuk dikerjakan Anggota 5)
│   └── question_2_fix.c                <-- Kode C perbaikan yang aman & tervalidasi (bebas leak)
│
└── 📁 docs/                            <-- Dokumen soal asli & tempat naruh gambar flowchart
    └── TK2-W8-S21-R3 (1).docx
```

---

## 👥 Pembagian Tugas 5 Orang

| No | Anggota | Peran / Bagian | File Tempat Mengerjakan | Deliverable yang Diharapkan |
|:--:|:---|:---|:---|:---|
| 1 | **Chandra (Chan)** | **System Architect & Lead** | `TK2-W8-S21-R3 - Jawaban Lengkap.md` | • Standar desain arsitektur & format file<br>• Bab Analisis Pengelolaan Memori<br>• Review silang, final merge, & sitasi |
| 2 | **Anggota 2** | **Module: Tambah Data** | Salin `templates/template_tugas1_operasi.md` $\to$ beri nama `tugas1_tambah.md` | • Pseudocode Operasi Tambah Siswa<br>• Flowchart Operasi Tambah Siswa |
| 3 | **Anggota 3** | **Module: Cari Data** | Salin `templates/template_tugas1_operasi.md` $\to$ beri nama `tugas1_cari.md` | • Pseudocode Operasi Cari Siswa (by NoReg)<br>• Flowchart Operasi Cari Siswa |
| 4 | **Anggota 4** | **Module: Hapus Data** | Salin `templates/template_tugas1_operasi.md` $\to$ beri nama `tugas1_hapus.md` | • Pseudocode Operasi Hapus Siswa (metode Temp File)<br>• Flowchart Operasi Hapus Siswa |
| 5 | **Anggota 5** | **Module: Tugas 2 (Memori)**| `templates/template_tugas2_memory.md` & `src/question_2_fix.c` | • Analisis Root Cause (RCA) 5 bug kode asli<br>• Kode C perbaikan yang aman & tervalidasi<br>• Flowchart alur alokasi memori yang benar |

---

## 📐 Standar Desain Bersama (Wajib Diikuti)

Agar pseudocode dan flowchart kalian saling cocok satu sama lain, semua modul harus mengacu pada kontrak berikut:

### 1. Model Data Siswa (Struct)
```c
typedef struct {
    char noreg[16]; // Nomor Registrasi Unik (String agar angka 0 di depan tidak hilang)
    char nama[50];  // Nama Lengkap Siswa
    int umur;       // Umur Siswa dalam Tahun
} Siswa;
```

### 2. Format Penyimpanan File
* **Nama File Database:** `siswa.txt`
* **Format Tiap Baris:** `noreg|nama|umur\n`
* **Pemisah (*Delimiter*):** Karakter pipa (`|`).  
  *(Alasan: Delimiter `|` aman dari nama yang mengandung tanda koma atau gelar seperti "Budi, S.Kom" dan nama yang berspasi).*
* **Contoh Data Fisik pada File:**
  ```text
  2024001|Chandra Perdiansyah|20
  2024002|Budi Santoso|22
  2024003|Siti Rahmawati|19
  ```
* **Kondisi File Awal:** Jika file `siswa.txt` belum ada, sistem menganggap database masih kosong (bukan pesan crash).

### 3. Standar Penulisan Pseudocode
* Tulis kata kunci kontrol menggunakan **HURUF KAPITAL**: `BEGIN`, `END`, `IF`, `THEN`, `ELSE`, `ENDIF`, `WHILE`, `DO`, `ENDWHILE`, `PROMPT`, `READ`, `DISPLAY`.
* Tuliskan deklarasi `INPUT:` dan `OUTPUT:` di awal fungsi/algoritma.
* Sebutkan fungsi I/O file secara eksplisit: `OPEN(nama_file, MODE)`, `READ_LINE`, `WRITE_LINE`, `CLOSE`.

### 4. Standar Pembuatan Flowchart
* Gunakan simbol flowchart standar ISO (Oval = Start/End, Jajaran Genjang = Input/Output, Persegi = Proses, Belah Ketupat = Decision).
* Boleh digambar memakai alat bantu diagram (misalnya **draw.io**, **Lucidchart**, **Visio**) dan diekspor ke gambar `.png` (simpan di folder `docs/`), **ATAU** dibuat langsung memakai sintaks **Mermaid (`flowchart TD`)** di dalam markdown.

---

## 🎯 Instruksi Khusus per Anggota

---

### 🔹 Instruksi untuk Anggota 2: Operasi Tambah Data Siswa
**Tujuan:** Menambahkan entri siswa baru ke dalam file database `siswa.txt`.

**Langkah Logika yang Harus Dibuat:**
1. Minta pengguna menginput:
   * `noreg` (Nomor Registrasi)
   * `nama` (Nama Lengkap)
   * `umur` (Umur Siswa)
2. **Validasi Input:**
   * Cek apakah `noreg` sudah pernah terdaftar di file `siswa.txt`. Jika sudah ada, tampilkan pesan peringatan dan minta input ulang.
   * Cek apakah umur logis (misal: $1 \le \text{umur} \le 120$).
3. **Penyimpanan ke File:**
   * Buka file `siswa.txt` dengan mode *Append* (`"a"`). *(Jangan pakai mode `"w"` karena akan menimpa data lama).*
   * Tulis baris baru dengan format: `noreg|nama|umur`.
   * Tutup file (`CLOSE`) agar data langsung tertulis ke disk fisik.
4. Tampilkan pesan berhasil kepada pengguna.
5. Buat **Pseudocode** dan **Flowchart** dari alur di atas.

---

### 🔹 Instruksi untuk Anggota 3: Operasi Cari Data Siswa
**Tujuan:** Mencari dan menampilkan informasi detail siswa berdasarkan Nomor Registrasi.

**Langkah Logika yang Harus Dibuat:**
1. Minta pengguna menginput nomor registrasi yang dicari (`target_noreg`).
2. Buka file `siswa.txt` dengan mode *Read* (`"r"`).
   * Jika file tidak ditemukan atau pointer bernilai `NULL`, beri tahu bahwa database masih kosong.
3. Lakukan penelusuran baris demi baris (*sequential scan*):
   * Baca satu baris dari file.
   * Pisahkan (*parse*) data menjadi `noreg`, `nama`, dan `umur` menggunakan pemisah `|`.
   * Bandingkan apakah `noreg` sama dengan `target_noreg`.
   * Jika sama: Tampilkan data siswa secara lengkap ke layar, tandai variabel *flag* `found = TRUE`, lalu hentikan perulangan (*BREAK*).
4. Jika perulangan selesai sampai akhir file dan `found == FALSE`:
   * Tampilkan pesan bahwa siswa dengan nomor registrasi tersebut tidak ditemukan.
5. Tutup file (`CLOSE`).
6. Buat **Pseudocode** dan **Flowchart** dari alur di atas.

---

### 🔹 Instruksi untuk Anggota 4: Operasi Hapus Data Siswa
**Tujuan:** Menghapus data siswa berdasarkan Nomor Registrasi dari file database.

> [!TIP]
> **Metode Rekomendasi:** Gunakan **Metode File Sementara (*Safe Temporary File Filter*)**. Ini adalah cara standar dan paling aman untuk menghapus data pada file teks di bahasa C.

**Langkah Logika yang Harus Dibuat:**
1. Minta pengguna menginput nomor registrasi siswa yang akan dihapus (`target_noreg`).
2. Buka file asli `siswa.txt` dengan mode *Read* (`"r"`), dan buat file sementara `temp_siswa.txt` dengan mode *Write* (`"w"`).
3. Baca baris demi baris dari `siswa.txt`:
   * Ambil data `noreg` pada baris tersebut.
   * **Jika `noreg == target_noreg`:** Jangan tulis baris ini ke file sementara (lewati), dan set tanda `found = TRUE`.
   * **Jika `noreg != target_noreg`:** Tulis baris ini apa adanya ke file `temp_siswa.txt`.
4. Tutup kedua file (`CLOSE source`, `CLOSE temp`).
5. **Pembaruan File:**
   * Jika `found == TRUE`: Hapus file asli (`remove("siswa.txt")`) dan ganti nama file sementara menjadi nama file asli (`rename("temp_siswa.txt", "siswa.txt")`). Beri notifikasi bahwa data berhasil dihapus.
   * Jika `found == FALSE`: Hapus file sementara (`remove("temp_siswa.txt")`), dan beri notifikasi bahwa data tidak ditemukan.
6. Buat **Pseudocode** dan **Flowchart** dari alur di atas.

---

### 🔹 Instruksi untuk Anggota 5: Tugas 2 (Analisis Alokasi Memori Dinamis)
**Tujuan:** Mengaudit kode bermasalah pada soal, menjelaskan kesalahannya, memperbaiki kodenya, dan membuat flowchart proses yang benar.

**Kode Asli Bermasalah (Lihat `src/question_2_buggy.c`):**
```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int *grades;
    int numStudents, i;
    printf("Enter number of students: ");
    scanf("%d", &numStudents);
    grades = malloc(numStudents * sizeof(int));  // Memory allocation
    for(i = 0; i < numStudents; i++) {
        printf("Enter grade for student %d: ", i + 1);
        scanf("%d", &grades[i]);
    }
    // Memory leak, no free call
    return 0;
}
```

**Tiga Tugas yang Wajib Dikerjakan:**
1. **Analisis Kesalahan (RCA):**
   Jelaskan secara mendalam minimal 4 poin berikut:
   * **Memory Leak:** Mengapa ketiadaan fungsi `free(grades)` berbahaya bagi sistem?
   * **Unchecked `malloc` (NULL Pointer Dereference):** Apa yang terjadi jika sistem kehabisan memori dan `grades` bernilai `NULL` saat diakses `grades[i]`? (Jelaskan sinyal `SIGSEGV` / Segmentation Fault).
   * **Unvalidated `numStudents`:** Apa akibatnya jika pengguna memasukkan angka $\le 0$, atau angka raksasa yang memicu *integer overflow* pada `numStudents * sizeof(int)`?
   * **Kerapuhan `scanf`:** Apa dampaknya jika user memasukkan karakter bukan angka?
   * **Dangling Pointer:** Mengapa disarankan melakukan `grades = NULL` setelah pemanggilan `free`?
2. **Perbaiki Kode C:**
   Tulis kode C perbaikan di file `src/question_2_fix.c` yang memiliki:
   * Validasi input jumlah siswa (> 0 dan tidak melampaui batas wajar).
   * Pengecekan `if (grades == NULL)` setelah pemanggilan `malloc`.
   * Loop input nilai siswa dengan validasi rentang nilai akademik ($0 - 100$).
   * Pembebasan memori `free(grades)` dan `grades = NULL` sebelum program berakhir.
3. **Buat Flowchart:**
   Gambarkan diagram alir alokasi memori yang benar dari awal proses hingga pembebasan memori.

---

## ⏰ Jadwal & Checkpoint Tim

* **Hari Ini (Kickoff):** Pahami instruksi masing-masing dan mulai kerjakan draf di folder `templates/`.
* **H-2 Deadline (Checkpoint Draf):** Semua anggota wajib mengumpulkan draf pekerjaan pertamanya ke Chan untuk direview bersama. *(Khusus Anggota 5 yang di luar negeri, tolong sesuaikan waktu agar checkpoint ini tidak terlewat).*
* **H-1 Deadline (Merging & Review Akhir):** Chan menggabungkan seluruh modul ke file laporan akhir `TK2-W8-S21-R3 - Jawaban Lengkap.md` dan melakukan pengecekan sitasi/format.
* **H-0 (Submission):** Laporan final di-submit ke portal Binus.

---

## 🤖 Dokumentasi HAICOLA (Human-AI Collaboration)

Sesuai ketentuan integritas akademik Universitas Bina Nusantara dan pengisian formulir `AI_Usage_Declaration_Form_EN.docx`, sesi konsultasi AI untuk perancangan arsitektur dan debugging kode telah didokumentasikan secara transparan:
* 📄 [**HAICOLA Tugas 1 — Sistem Manajemen File Database Siswa**](tugas1-haicola.md)  
  *Mendokumentasikan evolusi desain file I/O, eliminasi risiko data loss pada operasi hapus melalui Safe Temporary File Filter, dan analisis memory footprint streaming $O(1)$.*
* 📄 [**HAICOLA Tugas 2 — Debugging & Alokasi Memori Dinamis**](tugas2-haicola.md)  
  *Mendokumentasikan Root Cause Analysis (RCA) 5 bug pada kode asli soal, pencegahan sinyal SIGSEGV, mitigasi integer overflow, serta implementasi `free()` dan defensive nullification.*

---

## 💡 Ada Pertanyaan / Kendala?
Jika ada alur yang membingungkan atau butuh bantuan logika pemrograman C, langsung tanyakan di grup chat. Mari kita selesaikan tugas ini dengan kompak dan dapat nilai maksimal! 🔥
