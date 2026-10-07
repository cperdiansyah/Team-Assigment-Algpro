# 📚 Team Assignment: Algorithm & Programming (COMP6112036)
**BINUS University — Semester Ganjil 2026/2027 Periode 1**  
**Dosen Pengampu (Lecture - DCCA):** D5816 - ERIC GUNAWAN, S.Kom., M.TI  
**Teaching Assistant / Aslab (Lab - ACCA):** CS015 - ACHMAD ALIF NASRULLOH  
**Kelompok:** Group 1  

---

## 👥 Anggota Kelompok (Group 1)

| No | Nama Lengkap | NIM | Program Studi | Status Pemilihan Peran |
|:---:|---|:---:|:---:|:---:|
| 1 | **Chandra Perdiansyah** | `3002887011` | Computer Science | *[Pilih Slot / TBD]* |
| 2 | **Farizan Sidqi** | `3002915305` | Computer Science | *[Pilih Slot / TBD]* |
| 3 | **Abram Januar Putra Wibowo** | `3002885750` | Computer Science | *[Pilih Slot / TBD]* |
| 4 | **Arsyan Qasthari** | `3002924032` | Computer Science | *[Pilih Slot / TBD]* |
| 5 | **Mudianto** | `2702358821` | Computer Science | *[Pilih Slot / TBD]* |

> 💡 **Petunjuk untuk Anggota Tim:**  
> Tugas dibagi menjadi **5 Paket Peran (Role 1 s/d Role 5)** yang dirancang seimbang dan adil. Setiap paket mencakup 1 porsi tugas teori (DCCA) dan 1 porsi tugas praktikum (ACCA). Silakan diskusikan di grup dan pilih peran yang kalian minati, lalu cantumkan nama kalian di tabel di bawah!

---

## 🌐 Live Collaboration — Lembar Jawaban Cloud (SharePoint)

Untuk mencegah konflik saat mengedit berkas Word secara offline di Git, penulisan laporan resmi dilakukan secara **real-time dan kolaboratif via Cloud (Word Online / SharePoint)**:

| Modul Tugas | Sesi Perkuliahan | Tautan Lembar Jawaban Cloud (Live Collaboration) |
|:---:|:---:|---|
| **DCCA** | Lecture (Teori) | 🔗 [**Buka Lembar Jawaban DCCA di Word Online**](https://binusianorg-my.sharepoint.com/personal/chandra_perdiansyah_binus_ac_id/_layouts/15/guestaccess.aspx?share=IQAT74haa2EvTK_6WGCo91GhAU4SjPmNGDBg92X-XnNqohQ&e=ZqP1tV) |
| **ACCA** | Lab (Praktikum) | 🔗 [**Buka Lembar Jawaban ACCA di Word Online**](https://binusianorg-my.sharepoint.com/personal/chandra_perdiansyah_binus_ac_id/_layouts/15/guestaccess.aspx?share=IQDlFVz24AVrRrV23UQVi01wAd2XouL18Zle9THxrp1UASs&e=Urmhib) |

> 📌 **Ketentuan Kolaborasi Tim:**  
> - **Source Code C:** Dikelola di repository Git ini menggunakan branch masing-masing.  
> - **Laporan Tulisan & Dokumentasi:** Langsung ditulis dan dilengkapi bersama-sama di tautan SharePoint di atas!

---

## 🏛️ Arsitektur Repository (Monorepo)

```text
Team-Assigment-Algpro/
├── README.md                                  # [INI] Portal utama, link cloud doc, & katalog peran
│
├── DCCA/                                      # [Sesi Lecture / Teori] - Kelas DCCA - LEC
│   ├── TK1-W7-S15-R3.docx                     # Panduan soal resmi teori
│   ├── docs/                                  # Modul PDF resmi Lecture (LN04, LN05, LN06, LN07)
│   ├── AI_Usage_Declaration_Form_EN.docx      # Formulir deklarasi AI resmi DCCA
│   ├── DRAFT_LAPORAN_DCCA.md                  # Panduan template isi laporan DCCA
│   ├── soal1.c                                # Starter code Struct & Union katalog buku/majalah
│   ├── soal2_fixed.c                          # Starter code perbaikan algoritma sorting
│   └── readme.md                              # Dokumentasi teknis & tautan cloud DCCA
│
└── ACCA/                                      # [Sesi Lab / Praktikum] - Kelas ACCA - LAB
    ├── Tugas Praktikum 2 (Kelompok)...docx   # Panduan soal resmi praktikum
    ├── docs/                                  # Modul PDF resmi Binus (LN01, LN02, Praktikum 2 & 3)
    ├── AI_Usage_Declaration_Form_EN.docx      # Formulir deklarasi AI resmi ACCA
    ├── DRAFT_LAPORAN_ACCA.md                  # Panduan template isi laporan ACCA
    ├── tugas2a.c                              # Starter code Data Pegawai & Gaji Pokok (Struct)
    ├── tugas2b.c                              # Starter code Total Gaji Bulanan + Lembur
    ├── tugas2c.c                              # Starter code Diskon 5% & Kupon Hadiah Belanja
    └── README.md                              # Dokumentasi teknis & tautan cloud ACCA
```

> 📖 **Pedoman Silabus (Anti-Overengineered):**  
> Seluruh anggota tim diimbau untuk menulis kode bahasa C yang **murni merujuk pada materi di folder `ACCA/docs/`** (`printf`, `scanf`, `if-else`, `struct`, `strcmp`). Jangan menggunakan trik sintaks rumit yang belum diajarkan agar nilai tugas dinilai wajar dan natural oleh dosen/aslab!

---

## 📋 Katalog 5 Paket Peran (Job Description Detail)

Berikut adalah 5 opsi peran yang siap dipilih oleh masing-masing anggota:

---

### 🔹 Paket A (Role 1): Project Coordinator & Lead Integrator
* **Karakter Peran:** Cocok untuk yang teliti, menyukai koordinasi tim, penggabungan berkas, dan review kualitas kode.
* **Tanggung Jawab di DCCA (Perpustakaan):**
  - Melakukan review akhir (*Quality Check*) untuk jawaban Soal 1 dan Soal 2 sebelum dijadikan dokumen final.
  - Memverifikasi format berkas `TK1-W7-S15-R3 - Jawab.docx`.
* **Tanggung Jawab di ACCA (Supermarket):**
  - Melakukan code review menyeluruh pada `tugas2a.c`, `tugas2b.c`, dan `tugas2c.c` (memastikan bebas error/warning `gcc -Wall`).
  - Mengintegrasikan dokumen laporan akhir praktikum ACCA.
* **Administrasi Bersama:**
  - Bertindak sebagai penandatangan resmi berkas `AI_Usage_Declaration_Form_EN.docx` (selaku Group Coordinator).
  - Melakukan packaging file kompresi `.zip` untuk pengumpulan di LMS.
* **PIC Saat Ini:** `[ Tersedia / Siap Dipilih ]`

---

### 🔹 Paket B (Role 2): Core Developer (Data Structure Specialist)
* **Karakter Peran:** Cocok untuk yang ingin fokus mendalami implementasi `struct`, `union`, dan manipulasi data entitas di bahasa C.
* **Tanggung Jawab di DCCA (Perpustakaan):**
  - **Soal 1 (Koding C):** Menulis program C (`soal1.c`) untuk struktur data katalog buku & majalah menggunakan kombinasi `struct` dan `union`.
  - **Soal 1 (Flowchart):** Membuat diagram alir (*flowchart*) proses input data judul, tahun terbit, pemilihan jenis media (buku/majalah), dan display data.
* **Tanggung Jawab di ACCA (Supermarket):**
  - **Tugas 2A (`tugas2a.c`):** Mengembangkan program C berbasis `struct` untuk menerima 6 input data pegawai (NIP, Nama, Alamat, No HP, Jabatan, Golongan) dan menentukan Gaji Pokok otomatis sesuai golongan (`D1`, `D2`, `D3`).
* **PIC Saat Ini:** `[ Tersedia / Siap Dipilih ]`

---

### 🔹 Paket C (Role 3): Algorithm & Logic Specialist
* **Karakter Peran:** Cocok untuk yang menyukai problem solving, analisis debugging/tracing kode, dan kalkulasi aritmatika bertingkat.
* **Tanggung Jawab di DCCA (Perpustakaan):**
  - **Soal 2 (Root Cause Analysis):** Menganalisis potongan kode sorting Ibu Arini dan menuliskan penjelasan letak kesalahan logika (kenapa `for (j=0; j<n; j++)` dan `arr[j] > arr[i]` menghasilkan urutan salah).
  - **Soal 2 (Perbaikan Koding C):** Menulis kode perbaikan algoritma sorting di file `soal2_fixed.c` (misal Bubble Sort / Selection Sort yang benar).
* **Tanggung Jawab di ACCA (Supermarket):**
  - **Tugas 2B (`tugas2b.c`):** Mengembangkan modul C untuk menghitung total gaji bulanan pegawai dengan tambahan jam lembur sesuai golongan (`D1: 15rb`, `D2: 10rb`, `D3: 5rb` per jam).
* **PIC Saat Ini:** `[ Tersedia / Siap Dipilih ]`

---

### 🔹 Paket D (Role 4): Logic Design & Customer Flow Specialist
* **Karakter Peran:** Cocok untuk yang menyukai visualisasi alur program (flowchart), perancangan logika bisnis (diskon/kupon), dan analisis teoritis memori.
* **Tanggung Jawab di DCCA (Perpustakaan):**
  - **Soal 1 (Analisis Memori):** Menyusun penjelasan teoritis & analisis keunggulan `union` dibanding `struct` dalam hal penghematan alokasi memori (*memory footprint*).
  - **Soal 2 (Flowchart Sorting):** Membuat diagram alir (*flowchart*) untuk algoritma sorting yang sudah diperbaiki agar mudah dipahami alur iterasi dan pertukaran nilainya.
* **Tanggung Jawab di ACCA (Supermarket):**
  - **Tugas 2C (`tugas2c.c`):** Mengembangkan program C perhitungan kupon undian (kelipatan Rp 100.000 dengan pembulatan ke bawah) dan diskon 5% jika total belanja minimal Rp 100.000.
* **PIC Saat Ini:** `[ Tersedia / Siap Dipilih ]`

---

### 🔹 Paket E (Role 5): Technical Writer & AI Ethics Officer
* **Karakter Peran:** Cocok untuk yang menyukai dokumentasi teknis, pengujian interaksi dengan AI (Prompt Engineering), penyusunan refleksi, dan kepatuhan akademik.
* **Tanggung Jawab di DCCA (Perpustakaan):**
  - Mengompilasi seluruh jawaban Soal 1 dan Soal 2 ke dalam naskah laporan `TK1-W7-S15-R3 - Jawab.docx`.
  - Memastikan format referensi/sitasi akademik sesuai ketentuan (*Nama Sumber, Tautan, Tanggal Akses*).
* **Tanggung Jawab di ACCA (Supermarket):**
  - **Soal 2D HAICOLA (AI Prompting & Reflection):**
    1. Melakukan 1 sesi interaksi uji coba / validasi logika dengan AI (pada `tugas2a.c` / `2b.c` / `2c.c`).
    2. Mendokumentasikan potongan kode yang ditanyakan, prompt yang dipakai, dan jawaban AI.
    3. Menyusun narasi refleksi singkat (2–5 kalimat) mengenai pembelajaran dan perbaikan nyata setelah konsultasi AI.
* **Administrasi Bersama:**
  - Mengisi tabel rincian penggunaan AI pada berkas `AI_Usage_Declaration_Form_EN.docx` (di DCCA dan ACCA).
* **PIC Saat Ini:** `[ Tersedia / Siap Dipilih ]`

---

## 🎯 Tabel Pemilihan & Penetapan Peran (Slot Assignment)

> *Silakan isi nama anggota pada baris peran yang dipilih setelah diskusi kelompok:*

| Slot Peran | Nama Anggota (PIC) | NIM | Tanggung Jawab DCCA | Tanggung Jawab ACCA |
|:---:|---|:---:|---|---|
| **Paket A (Role 1)** | *[Isi Nama]* | *[Isi NIM]* | Final Review Soal 1 & 2 | QA & Integration `tugas2a-c`, TTD AI Form |
| **Paket B (Role 2)** | *[Isi Nama]* | *[Isi NIM]* | Koding `soal1.c` & Flowchart Soal 1 | Program `tugas2a.c` (Struct Pegawai) |
| **Paket C (Role 3)** | *[Isi Nama]* | *[Isi NIM]* | Analisis Bug & Koding `soal2_fixed.c` | Program `tugas2b.c` (Total Gaji + Lembur) |
| **Paket D (Role 4)** | *[Isi Nama]* | *[Isi NIM]* | Analisis Memori Union & Flowchart Soal 2 | Program `tugas2c.c` (Diskon & Kupon Belanja) |
| **Paket E (Role 5)** | *[Isi Nama]* | *[Isi NIM]* | Kompilasi Laporan & Referensi DCCA | Modul 2D HAICOLA & Draft AI Form |

---

## 💻 Panduan Kompilasi & Menjalankan Kode C

Gunakan compiler `gcc`:

### Modul DCCA:
```bash
# Kompilasi dan jalankan Soal 1 (Katalog Buku/Majalah)
gcc -Wall -Wextra DCCA/soal1.c -o DCCA/soal1.exe
./DCCA/soal1.exe

# Kompilasi dan jalankan Soal 2 (Sorting Koleksi Tahun Terbit)
gcc -Wall -Wextra DCCA/soal2_fixed.c -o DCCA/soal2_fixed.exe
./DCCA/soal2_fixed.exe
```

### Modul ACCA:
```bash
# Kompilasi Tugas 2A (Data Pegawai)
gcc -Wall -Wextra ACCA/tugas2a.c -o ACCA/tugas2a.exe
./ACCA/tugas2a.exe

# Kompilasi Tugas 2B (Gaji Bulanan & Lembur)
gcc -Wall -Wextra ACCA/tugas2b.c -o ACCA/tugas2b.exe
./ACCA/tugas2b.exe

# Kompilasi Tugas 2C (Diskon Belanja & Kupon)
gcc -Wall -Wextra ACCA/tugas2c.c -o ACCA/tugas2c.exe
./ACCA/tugas2c.exe
```

---

## 🌿 Pedoman Kolaborasi Git untuk Pemula (Step-by-Step)

Bagi teman-teman yang baru pertama kali menggunakan Git, jangan khawatir! Git berfungsi sebagai "mesin waktu" dan penyimpan riwayat tugas kelompok kita. Agar pekerjaan tidak saling menimpa (*merge conflict*), ikuti panduan praktis berikut:

---

### 🛑 3 Aturan Emas Kolaborasi Git (Anti-Pusing):
1. **DILARANG KERJA LANGSUNG DI BRANCH `main`:**  
   Cabang `main` hanya untuk kode yang sudah final dan diuji. Selalu buat cabang fitur baru (*feature branch*) saat hendak mengerjakan tugas.
2. **SELALU PULL SEBELUM MULAI KERJA:**  
   Sebelum mulai mengetik atau membuat branch baru, biasakan menarik (*pull*) update terbaru agar repositori lokal kalian tidak ketinggalan zaman.
3. **COMMIT SESERING MUNGKIN DENGAN PESAN JELAS:**  
   Simpan progres kalian secara bertahap dengan pesan yang mendeskripsikan apa yang baru saja kalian selesaikan.

---

### 💻 Pilihan 1: Alur Kerja Menggunakan JetBrains CLion (GUI)

Jika kalian menggunakan CLion:

1. **Tarik Update Terbaru (Update Project):**
   - Tekan ikon panah biru ke bawah di pojok kanan atas atau gunakan shortcut: `Ctrl + T`.
   - Pilih *Merge incoming changes into current branch* $\rightarrow$ Klik **OK**.
2. **Buat Branch Baru untuk Tugasmu:**
   - Di pojok kanan bawah jendela CLion, klik tulisan branch saat ini (misal: `main`).
   - Pilih **+ New Branch**.
   - Beri nama sesuai format: `feat/acca-tugas2a-farizan` atau `feat/dcca-soal2-abram`.
   - Centang opsi *Checkout branch* $\rightarrow$ Klik **Create**.
3. **Simpan Perubahan (Commit):**
   - Setelah selesai mengoding/mengedit berkas, buka tab **Commit** di bilah kiri (atau tekan shortcut `Ctrl + K`).
   - Centang berkas yang kalian ubah saja (misal: `tugas2a.c`).
   - Tulis pesan commit di kotak bawah, contoh: `feat(acca): implementasi struct pegawai dan gaji pokok`.
   - Klik tombol panah kecil di samping tombol **Commit** $\rightarrow$ pilih **Commit and Push...** (atau klik **Commit** dulu, lalu nanti tekan `Ctrl + Shift + K` untuk **Push**).
4. **Push ke GitHub:**
   - Pada jendela pop-up Push, periksa cabang tujuan $\rightarrow$ Klik **Push**.

---

### 💻 Pilihan 2: Alur Kerja Menggunakan Visual Studio Code (GUI)

Jika kalian menggunakan VS Code:

1. **Tarik Update Terbaru (Pull):**
   - Buka tab **Source Control** di bilah kiri (`Ctrl + Shift + G`).
   - Klik tombol **...** (titik tiga di atas) $\rightarrow$ pilih **Pull**.
2. **Buat Branch Baru:**
   - Klik nama branch di pojok kiri bawah status bar (yang bertuliskan `main`).
   - Pilih **+ Create new branch...** di menu atas.
   - Ketik nama branch, contoh: `feat/acca-tugas2c-arsyan` $\rightarrow$ Tekan **Enter**.
3. **Stage & Commit:**
   - Di tab **Source Control**, klik tanda tambah (`+`) di samping nama berkas yang telah diubah (*Stage Changes*).
   - Tulis pesan commit di kotak teks, contoh: `feat(acca): logika kupon belanja dan diskon 5%`.
   - Klik tombol centang biru **Commit**.
4. **Publish / Push Branch:**
   - Klik tombol **Publish Branch** (atau klik titik tiga **...** $\rightarrow$ **Push**).

---

### 💻 Pilihan 3: Alur Kerja Menggunakan Terminal / Git Bash (CLI)

Bagi yang terbiasa menggunakan command line:

```bash
# 1. Pastikan berada di branch main dan sinkronkan dengan repo online
git checkout main
git pull origin main

# 2. Buat branch baru dan langsung berpindah ke branch tersebut
# Format: feat/[modul]-[tugas]-[nama]
git checkout -b feat/acca-tugas2b-abram

# 3. Setelah coding selesai, periksa status berkas yang berubah
git status

# 4. Tambahkan berkas yang diubah ke daftar staging
git add ACCA/tugas2b.c

# 5. Simpan commit dengan pesan deskriptif
git commit -m "feat(acca): kalkulasi jam lembur golongan D1-D3"

# 6. Kirim (push) branch kalian ke GitHub untuk pertama kali
git push -u origin feat/acca-tugas2b-abram
```

---

### 🚀 Langkah Terakhir: Membuat Pull Request (PR) di GitHub

Setelah branch berhasil kalian *push* ke GitHub:
1. Buka halaman repositori di web browser GitHub.
2. Akan muncul banner kuning dengan tulisan: **"Compare & pull request"**. Klik tombol tersebut!
3. Tulis deskripsi singkat tentang apa saja yang telah dikerjakan di kotak teks PR.
4. Klik **Create pull request**.
5. Beri tahu di grup WhatsApp: *"Halo teman-teman, kodingan Tugas 2A sudah selesai dan PR sudah dibuat, tolong dicek ya!"*
6. Project Coordinator atau rekan tim akan meninjau kodenya, lalu me-merge ke `main`.