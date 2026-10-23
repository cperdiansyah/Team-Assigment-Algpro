# 📘 PANDUAN PENGERJAAN TUGAS KELOMPOK KE-3 (TK3)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** DCCA - LEC (Computer Science)  
**Dosen Pengampu:** D5816 - ERIC GUNAWAN, S.Kom., M.TI  
**Minggu Perkuliahan:** Week 9 (Sesi 22 - R3)  
**Topik Pembelajaran:** Functions, Recursion, Structures, and File Processing with Searching  
**Koordinator Kelompok (PIC):** Chandra Perdiansyah (NIM: 3002887011)

---

## 🏛️ Skenario Studi Kasus & Konteks Proyek

> **Institusi / Skenario:**  
> Tim pengembang algoritma di **Unit Penelitian Algoritma Komputasi Universitas Bina Nusantara** baru saja memperoleh proyek dari **Museum Sains dan Matematika Indonesia**.
> 
> **Tujuan Proyek:**  
> Merancang dan membangun simulasi visual algoritma klasik untuk perangkat layar sentuh interaktif (*touchscreen kiosk*) di area pameran edukasi. Simulasi ini dirancang khusus guna mendukung literasi algoritma dan pola pikir komputasional (*computational thinking*) bagi siswa sekolah menengah melalui demonstrasi interaktif langkah demi langkah.

---

## 🎯 Target Learning Outcomes (LO) & Relevansi Materi

| Kode LO | Deskripsi Learning Outcome | Relevansi Modul Tugas |
| :---: | :---| :---|
| **LO 1** | **Apply syntax and functions in the C language**<br>*(Menerapkan sintaks dan fungsi dalam bahasa C)* | Perancangan fungsi rekursif Towers of Hanoi, kalkulator faktorial perbaikan, dan modularisasi pembacaan file data siswa. |
| **LO 2** | **Analyzing a program to solve problems using the C language**<br>*(Menganalisis program untuk menyelesaikan masalah menggunakan bahasa C)* | Analisis akar masalah (*Root Cause Analysis*) kesalahan logika `infinite recursion` & *stack overflow* pada fungsi faktorial rekursif. |
| **LO 3** | **Evaluate the kind of algorithms, syntax, and function for problem-solving**<br>*(Mengevaluasi jenis algoritma, sintaks, dan fungsi untuk penyelesaian masalah)* | Evaluasi efisiensi kompleksitas waktu $O(2^n)$ vs $O(n)$, analisis perbandingan Linear Search ($N=10, 100, 1.000$), serta rekomendasi optimasi sistem skala besar. |

### Matriks Relevansi Materi Kuliah:
- **Week 6 (Function and Recursion):** Digunakan dalam perancangan algoritma rekursif Towers of Hanoi (Soal 1) dan analisis fungsi faktorial (Soal 2).
- **Week 7 (Structures & Union):** Digunakan dalam desain struktur data `array of struct` untuk menampung data siswa di memori (Soal 3).
- **Week 9 (File Processing and Searching):** Digunakan untuk membaca basis data teks `siswa.txt` dan mengeksekusi algoritma *Linear Search* (Soal 3).

---

## 👥 Katalog 5 Slot Tugas Tim (Silakan Pilih Slot Masing-Masing)

> 💡 **Petunjuk Alur Kerja Anggota Tim:**  
> 1. Diskusikan di grup WhatsApp dan pilih salah satu slot yang masih berstatus `[ ] Belum Dipilih / Open Slot`.
> 2. Buka berkas template kerja terarah yang sesuai di dalam folder [`outline/`](./outline/).
> 3. Kerjakan draf jawaban kalian langsung pada file template tersebut, lalu laporkan ke PIC (Chandra) untuk digabungkan ke laporan akhir.

| Slot | Fokus Soal | Modul yang Dikerjakan | File Template Kerja | Kategori Tugas | Status Pemilihan |

| :---: | :---: | :---| :---| :---: | :---: |
| **Slot 1** | **Soal 1** *(Hanoi Part 1)* | **Soal 1A & 1B:** Pseudo code Towers of Hanoi (4 cakram) + Penjelasan detail alur rekursi, *base case* ($n=1$), dan tabel 15 langkah perpindahan cakram. | [`outline/slot_1_soal1_hanoi_algoritma.md`](./outline/slot_1_soal1_hanoi_algoritma.md) | Logika Algoritma | `[ ] Open Slot (TBD)` |
| **Slot 2** | **Soal 1** *(Hanoi Part 2)* | **Soal 1C & Diagram:** Penurunan matematis persamaan rekurensi $T(n) = 2T(n-1) + 1 \implies \mathcal{O}(2^n)$ dan ruang $\mathcal{O}(n)$ + Menggambar *flowchart* Towers of Hanoi. | [`outline/slot_2_soal1_hanoi_teori_flowchart.md`](./outline/slot_2_soal1_hanoi_teori_flowchart.md) | Teori & Visual | `[ ] Open Slot (TBD)` |
| **Slot 3** | **Soal 2** *(Faktorial Full)* | **Soal 2A, 2B & 2C:** Analisis akar penyebab (*RCA*) *bug* `infinite recursion` & *stack overflow* pada faktorial + Pseudo code perbaikan + *Flowchart* faktorial rekursif yang benar. | [`outline/slot_3_soal2_faktorial_full.md`](./outline/slot_3_soal2_faktorial_full.md) | Analisis & Visual | `[ ] Open Slot (TBD)` |
| **Slot 4** | **Soal 3** *(Siswa Part 1)* | **Soal 3A & 3C:** Pseudo code pembacaan berkas `siswa.txt` & Linear Search + Analisis evaluasi perbandingan data (10, 100, 1.000 data) & rekomendasi optimasi skala besar. | [`outline/slot_4_soal3_siswa_desain_analisis.md`](./outline/slot_4_soal3_siswa_desain_analisis.md) | Desain & Analisis | `[ ] Open Slot (TBD)` |
| **Slot 5** | **Soal 3** *(Siswa Part 2 & PIC)* | **Soal 3B & Kompilasi:** Implementasi program C `search_siswa.c` (*array of struct* + *Linear Search*), pengelolaan berkas `siswa.txt`, penyusunan referensi formal, dan kompilasi laporan akhir Word. | [`outline/slot_5_soal3_siswa_koding_pic.md`](./outline/slot_5_soal3_siswa_koding_pic.md) | Koding C & Integrasi | `[x] Chandra Perdiansyah (PIC)` |

---

## 📂 Struktur Direktori Proyek

```text
DCCA 3/
├── README.md                        # [File Ini] Panduan utama, pembagian tugas, & deskripsi soal
│
├── outline/                         # [Folder Kerja Tim] Lembar kerja template per soal untuk masing-masing slot
│   ├── README.md                    # Panduan ringkas alur pengerjaan tim
│   ├── haicola/                     # [Referensi HAICOLA] Dokumentasi resmi Human-AI Collaboration & prompt acuan
│   │   ├── README.md                # Katalog panduan HAICOLA
│   │   ├── haicola-soal1-hanoi.md   # Studi kasus & prompt AI Soal 1 (Towers of Hanoi)
│   │   ├── haicola-soal2-factorial.md # Studi kasus & prompt AI Soal 2 (Faktorial Rekursif)
│   │   └── haicola-soal3-search-siswa.md # Studi kasus & prompt AI Soal 3 (File Processing)
│   ├── slot_1_soal1_hanoi_algoritma.md       # Lembar kerja Slot 1 (Soal 1A & 1B)
│   ├── slot_2_soal1_hanoi_teori_flowchart.md # Lembar kerja Slot 2 (Soal 1C & Flowchart Hanoi)
│   ├── slot_3_soal2_faktorial_full.md        # Lembar kerja Slot 3 (Soal 2A, 2B, 2C Full)
│   ├── slot_4_soal3_siswa_desain_analisis.md # Lembar kerja Slot 4 (Soal 3A & 3C)
│   └── slot_5_soal3_siswa_koding_pic.md      # Catatan pengerjaan Slot 5 (PIC - Soal 3B & Integrasi)
│
├── docs/
│   └── TK3-W9-S22-R3.docx           # Berkas instruksi soal resmi dari Binus
│
└── src/
    └── siswa.txt                    # Berkas sampel data teks siswa ([Nama] [Umur] [No_Reg])
```

---

## 📋 Deskripsi Rinci Penugasan (Berdasarkan Soal Resmi Binus)

### 🧩 Soal 1: Desain dan Analisis Fungsi Rekursif - Towers of Hanoi (Bobot 40%)
- **Deskripsi Masalah:**  
  Merancang fungsi rekursif untuk menyelesaikan Towers of Hanoi dengan **4 cakram**. Menampilkan langkah-langkah perpindahan dari **Tiang A (Source)** ke **Tiang C (Destination)** dengan **Tiang B (Auxiliary)** sebagai tiang penyangga sementara.
- **Deliverables yang Diharapkan:**
  1. *Pseudo code* untuk fungsi rekursif Towers of Hanoi (dikerjakan di **Slot 1**).
  2. Penjelasan detail kondisi dasar (*base case* saat $n=1$), cara pemecahan sub-masalah ($n-1$), dan tabel rincian 15 langkah perpindahan cakram (dikerjakan di **Slot 1**).
  3. Menggambar diagram alir (*flowchart*) rekursif Towers of Hanoi (dikerjakan di **Slot 2**).
  4. Analisis penurunan persamaan rekurensi waktu $T(n) = 2T(n-1) + 1$ yang menghasilkan kompleksitas $\mathcal{O}(2^n)$ dan ruang $\mathcal{O}(n)$ (dikerjakan di **Slot 2**).

---

### 🔍 Soal 2: Analisis Kesalahan Fungsi Rekursif Faktorial (Bobot 30%)
- **Deskripsi Masalah:**  
  Ditemukan cuplikan *pseudo code* kalkulator faktorial rekursif yang mengandung galat logika (*bug*):
  ```text
  Function factorial(n):
      if n == 0:
          return 1
      else:
          return n * factorial(n)
  ```
- **Deliverables yang Diharapkan:**
  1. Identifikasi dan penjelasan kesalahan logika: Mengapa pemanggilan `factorial(n)` pada blok `else` menyebabkan *infinite recursion* dan *call stack overflow* (dikerjakan di **Slot 3**).
  2. Versi perbaikan *pseudo code* yang benar (mengubah argumen menjadi `n - 1` serta penanganan bilangan negatif) (dikerjakan di **Slot 3**).
  3. Menggambar diagram alir (*flowchart*) rekursif yang benar (dikerjakan di **Slot 3**).

---

### 🗄️ Soal 3: Implementasi dan Analisis Pencarian Data Siswa dari File (Bobot 30%)
- **Deskripsi Masalah:**  
  Fitur direktori pencarian nama siswa dari berkas teks `siswa.txt` dengan format: `[Nama] [Umur] [Nomor_Registrasi]`.
- **Contoh Sampel Data (`siswa.txt`):**
  ```text
  Andi 17 230101
  Budi 16 230102
  Citra 17 230103
  ```
- **Deliverables yang Diharapkan:**
  1. *Pseudo code* pembacaan data berkas teks dan pencarian berdasarkan nama (dikerjakan di **Slot 4**).
  2. Analisis perbandingan konseptual waktu pencarian jika file berisi **10 data, 100 data, dan 1.000 data** ($\mathcal{O}(n)$), serta rekomendasi optimasi (*Sorting + Binary Search*, *Hash Table*, atau *Trie*) jika data semakin membesar (dikerjakan di **Slot 4**).
  3. Implementasi algoritma pencarian C *Linear Search* (`strcmp`) serta penanganan validasi jika nama siswa tidak ditemukan di `search_siswa.c` (dikerjakan di **Slot 5 - PIC**).
  4. Penyusunan daftar referensi formal dan kompilasi seluruh draf ke dokumen Word/SharePoint akhir (dikerjakan di **Slot 5 - PIC**).

---


## 📐 Standar Penulisan & Format Akademik Bersama

Agar hasil draf dari masing-masing slot seragam dan mudah dikompilasi ke Word:

### 1. Standar Penulisan Pseudocode
- Tuliskan kata kunci kontrol menggunakan **HURUF KAPITAL**: `BEGIN`, `END`, `IF`, `THEN`, `ELSE`, `ENDIF`, `WHILE`, `DO`, `FOR`, `CALL`, `RETURN`, `PRINT`.
- Cantumkan deklarasi `INPUT:` dan `OUTPUT:` di bagian awal algoritma.

### 2. Standar Pembuatan Flowchart
- Gunakan simbol standar ISO:
  - **Oval / Terminator:** Mulai (*Start*) dan Selesai (*End / Return*).
  - **Jajaran Genjang:** Operasi masukan/keluaran (*Input / Output*).
  - **Persegi Panjang:** Langkah komputasi/proses (*Process*).
  - **Belah Ketupat:** Titik percabangan keputusan (*Decision*).
- Boleh digambar memakai alat bantu diagram (misalnya **draw.io**, **Visio**, **Canva**) lalu disimpan berupa file gambar di folder `docs/`, ATAU ditulis langsung menggunakan sintaks diagram **Mermaid (`flowchart TD`)**.

### 3. Format Wajib Penulisan Referensi (Wajib Ditaati)
Dosen menetapkan format baku sitasi:
$$\text{Nama sumber, Tautan (jika ada), diakses pada [Tanggal Akses]}$$

*Contoh:*
- `Deitel, P. J., & Deitel, H. M., C How to Program: With an Introduction to C++ (8th Edition), Pearson Education, diakses pada 23 Oktober 2026.`
- `GeeksforGeeks, Tower of Hanoi - Recursion Algorithm and Complexity Analysis, https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/, diakses pada 23 Oktober 2026.`

---

## ⏱️ Target & Alur Koordinasi Tim

1. **Pemilihan Slot:** Kalau bisa selesai minggu malam.
2. **Pengerjaan Draf:** Isi berkas template masing-masing di folder `outline/`. Jika ada kendala konsep rekursi atau pencarian, segera diskusikan di grup.
3. **Kompilasi Akhir:** Seluruh draf dari Slot 1 s/d Slot 4 akan direview dan disatukan dalam dokumen Word laporan resmi.
