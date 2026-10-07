# 🏛️ DCCA — Tugas Kelompok ke-1 (Week 7)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** DCCA - LEC  
**Dosen Pengampu (Instructor):** D5816 - ERIC GUNAWAN, S.Kom., M.TI  
**Kelompok:** Group 1  
**Topik Utama:** Structures and Union, Algorithm Debugging & Sorting  

---

## 📖 Ringkasan Studi Kasus
**Studi Kasus: Perpustakaan Digital Lentera Nusantara**  
Kepala perpustakaan, Ibu Arini, membutuhkan prototipe sistem katalog digital untuk mengelola koleksi **Buku** dan **Majalah**. Mengingat keterbatasan memori server awal, sistem harus dirancang sehemat mungkin menggunakan bahasa C, serta memperbaiki algoritma sorting lama yang bermasalah dalam mengurutkan tahun terbit koleksi.

---

## 📝 Pembagian & Rincian Soal

### 1. Soal 1: Desain dan Analisis `struct` dan `union` (Bobot 60%)
* **Deskripsi:** Merancang struktur data mini untuk menyimpan:
  - `Judul` (string)
  - `Tahun Terbit` (integer)
  - `Jenis Media` (Buku atau Majalah)
* **Kebutuhan Teknis:**
  - Jenis media **wajib** menggunakan `union` agar hemat memori karena satu entri item hanya bisa berupa salah satu tipe media pada satu waktu.
* **Deliverable Soal 1:**
  1. Penjelasan konsep arsitektur `struct` dan `union` yang diusulkan.
  2. Flowchart alur input data, percabangan pemilihan jenis media, dan tampilan output.
  3. Analisis teoritis keunggulan dan perhitungan penghematan memori (`memory footprint`) penggunaan `union` dibanding `struct` biasa.
  4. Implementasi kode bahasa C (`soal1.c`).

### 2. Soal 2: Debug dan Analisis Program Sorting Perpustakaan (Bobot 40%)
* **Deskripsi:** Menemukan bug, menganalisis, dan memperbaiki fungsi sorting lama milik Ibu Arini untuk mengurutkan tahun terbit:
  ```c
  void sort(int arr[], int n) {
      int i, j, temp;
      for (i = 0; i < n-1; i++) {
          for (j = 0; j < n; j++) {     // <-- Bug 1: Batas inner loop berlebih
              if (arr[j] > arr[i]) {   // <-- Bug 2: Perbandingan indeks tidak konsisten
                  temp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = temp;
              }
          }
      }
  }
  ```
* **Array Uji:** `{64, 34, 25, 12, 22}`
* **Deliverable Soal 2:**
  1. Penjelasan analisis letak kesalahan logika (Root Cause Analysis).
  2. Kode C fungsi sorting yang sudah diperbaiki secara benar (`soal2_fixed.c`).
  3. Flowchart logika alur sorting yang benar.

---

## 👥 Pemetaan Tanggung Jawab Modul DCCA

> *Tabel ini merujuk pada Paket Peran di `README.md` utama. Silakan cantumkan nama setelah peran disepakati:*

| Sub-Tugas DCCA | Deskripsi Deliverable | Role Terkait | PIC (Nama Anggota) | Status |
|---|---|:---:|:---:|:---:|
| **Soal 1 — Kode C** | Penulisan kode C `soal1.c` (Struct & Union katalog) | **Paket B (Role 2)** | *[Open Slot]* | [ ] Belum |
| **Soal 1 — Flowchart** | Diagram alir proses input, percabangan media, & output | **Paket B (Role 2)** | *[Open Slot]* | [ ] Belum |
| **Soal 1 — Analisis Memori** | Penjelasan teoritis efisiensi memori Union vs Struct biasa | **Paket D (Role 4)** | *[Open Slot]* | [ ] Belum |
| **Soal 2 — Analisis RCA Bug** | Penjelasan detail letak kesalahan logika sorting lama | **Paket C (Role 3)** | *[Open Slot]* | [ ] Belum |
| **Soal 2 — Kode C Perbaikan** | Penulisan kode C `soal2_fixed.c` (Sorting yang benar) | **Paket C (Role 3)** | *[Open Slot]* | [ ] Belum |
| **Soal 2 — Flowchart Sorting** | Diagram alir proses algoritma sorting yang benar | **Paket D (Role 4)** | *[Open Slot]* | [ ] Belum |
| **Kompilasi Laporan DCCA** | Pengisian laporan di Word Online (SharePoint) | **Paket E (Role 5)** | *[Open Slot]* | [ ] Belum |
| **Format Sitasi & Referensi** | Standardisasi format sitasi dan sumber referensi | **Paket E (Role 5)** | *[Open Slot]* | [ ] Belum |
| **Draft AI Declaration Form** | Pengisian tabel pemanfaatan AI di `AI_Usage...docx` | **Paket E (Role 5)** | *[Open Slot]* | [ ] Belum |
| **Final Review & Sign-off** | Quality check seluruh jawaban & TTD AI Declaration | **Paket A (Role 1)** | *[Open Slot]* | [ ] Belum |

---

## 🌐 Lembar Jawaban Cloud (Live Collaboration)

Laporan DCCA dikerjakan bersama di Word Online untuk menghindari konflik file Word offline di Git:  
👉 🔗 [**Klik di Sini untuk Membuka Lembar Jawaban DCCA di Word Online (SharePoint)**](https://binusianorg-my.sharepoint.com/personal/chandra_perdiansyah_binus_ac_id/_layouts/15/guestaccess.aspx?share=IQAT74haa2EvTK_6WGCo91GhAU4SjPmNGDBg92X-XnNqohQ&e=ZqP1tV)

---

## 📁 Struktur Berkas Modul DCCA

```text
DCCA/
├── TK1-W7-S15-R3.docx                 # Panduan soal resmi dari dosen
├── AI_Usage_Declaration_Form_EN.docx  # Formulir pernyataan pemanfaatan AI resmi
├── DRAFT_LAPORAN_DCCA.md              # Template checklist & panduan isi laporan
├── soal1.c                            # Starter code program katalog struct & union
├── soal2_fixed.c                      # Starter code program sorting yang diperbaiki
└── readme.md                          # Panduan modul DCCA ini
```

---

## 🚀 Panduan Menjalankan Program DCCA

```bash
# 1. Jalankan Program Katalog Struct & Union (Soal 1)
gcc -Wall soal1.c -o soal1.exe
./soal1.exe

# 2. Jalankan Program Sorting yang Diperbaiki (Soal 2)
gcc -Wall soal2_fixed.c -o soal2_fixed.exe
./soal2_fixed.exe
```