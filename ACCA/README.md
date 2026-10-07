# 🛒 ACCA — Tugas Praktikum 2 (Team Assignment 1) - Week 7
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** ACCA - LAB  
**Dosen Pengampu:** CS015 - ACHMAD ALIF NASRULLOH (Teaching Assistant / Aslab)  
**Kelompok:** Group 1  
**Topik Utama:** Struct, Selection, Arithmetic Operators, Function, dan Validasi AI (HAICOLA)  

---

## 📚 Pedoman Koding Sesuai Silabus (Anti-Overengineered)
Seluruh pengerjaan tugas ACCA **wajib merujuk pada materi resmi perkuliahan** yang ada di folder [`ACCA/docs/`](docs):
1. **Modul LN02:** Formatted Input/Output (`printf()`, `scanf()`, format specifier `%d`, `%s`, `%f`).
2. **Modul Praktikum 2:** Kontrol seleksi (`if`, `else if`, `else`) dan perbandingan string (`strcmp()`).
3. **Modul Praktikum 3:** Deklarasi dan pemanggilan `struct` sederhana menggunakan operator titik (`.`).
4. **Modul Week 4:** Operasi aritmatika dasar (`/` integer division untuk pembulatan kupon, `*` perkalian upah lembur/diskon).
> ⚠️ **Catatan Penting:** Hindari menggunakan fungsi rumit/eksternal yang belum diajarkan di kelas (misal: regex, custom string formatting ribet) agar kode dinilai natural dan sesuai capaian pembelajaran (LO).

---

## 📖 Ringkasan Studi Kasus
**Studi Kasus: Supermarket Nusantara Sejahtera**  
Supermarket Nusantara Sejahtera membutuhkan pengembangan dua sistem:
1. **Program Hadiah & Diskon Pelanggan:** Perhitungan kupon undian per kelipatan belanja Rp 100.000 (pembulatan ke bawah) dan diskon 5% untuk transaksi minimal Rp 100.000.
2. **Sistem Penggajian Bulanan Pegawai:** Pengelolaan data pegawai berbasis `struct`, penentuan gaji pokok otomatis berbasis golongan (`D1: 3jt`, `D2: 2.5jt`, `D3: 2jt`), dan kalkulasi upah lembur bulanan (`D1: 15rb`, `D2: 10rb`, `D3: 5rb` per jam).

---

## 📝 Pembagian & Spesifikasi Tugas

### 1. Tugas 2A: Data Pegawai & Gaji Pokok (Bobot 30%)
* **Nama Berkas:** `tugas2a.c`
* **Spesifikasi:**
  - Input `struct`: NIP, Nama, Alamat, No HP, Jabatan, Golongan (`D1`/`D2`/`D3`).
  - Penentuan Gaji Pokok otomatis sesuai golongan.
  - Tampilkan data pegawai lengkap berikut nominal gaji pokoknya.

### 2. Tugas 2B: Hitung Total Gaji Bulanan + Lembur (Bobot 30%)
* **Nama Berkas:** `tugas2b.c`
* **Spesifikasi:**
  - Input: NIP, Golongan, Jumlah Jam Lembur.
  - Hitung upah lembur per jam sesuai golongan.
  - Rumus: $\text{Total Gaji} = \text{Gaji Pokok} + (\text{Jam Lembur} \times \text{Tarif Lembur})$.
  - Tampilkan: NIP, Golongan, Jam Lembur, dan Total Gaji Bulan Ini.

### 3. Tugas 2C: Program Hadiah Belanja & Diskon (Bobot 30%)
* **Nama Berkas:** `tugas2c.c`
* **Spesifikasi:**
  - Input: Total Pembelian (Rupiah).
  - Ketentuan:
    - 1 kupon per kelipatan Rp 100.000 (integer division / pembulatan ke bawah).
    - Diskon 5% jika total pembelian $\ge$ Rp 100.000.
  - Tampilkan: Total Pembelian Awal, Jumlah Kupon, Nominal Diskon, dan Total yang Harus Dibayar.

### 4. Soal 2D: HAICOLA — Pemanfaatan AI untuk Validasi Logika & Debugging (Bobot 10%)
* **Spesifikasi:**
  - Melakukan 1 interaksi konsultasi validasi logika / debugging dengan AI.
  - Dokumentasikan: potongan kode yang ditanyakan, prompt yang diajukan, jawaban AI, dan **refleksi singkat (2–5 kalimat)** mengenai apa yang dipelajari dan perbaikan nyata yang dilakukan.
  - Mengisi berkas **`AI_Usage_Declaration_Form_EN.docx`**.

---

## 👥 Pemetaan Tanggung Jawab Modul ACCA

> *Tabel ini merujuk pada Paket Peran di `README.md` utama. Silakan cantumkan nama setelah peran disepakati:*

| Sub-Tugas ACCA | Deskripsi Deliverable | Role Terkait | PIC (Nama Anggota) | Status |
|---|---|:---:|:---:|:---:|
| **Tugas 2A — Program C** | Penulisan kode `tugas2a.c` (Struct data pegawai & gaji pokok) | **Paket B (Role 2)** | *[Open Slot]* | [ ] Belum |
| **Tugas 2B — Program C** | Penulisan kode `tugas2b.c` (Kalkulasi gaji bulanan & jam lembur) | **Paket C (Role 3)** | *[Open Slot]* | [ ] Belum |
| **Tugas 2C — Program C** | Penulisan kode `tugas2c.c` (Kalkulasi diskon 5% & kupon belanja) | **Paket D (Role 4)** | *[Open Slot]* | [ ] Belum |
| **Tugas 2D — HAICOLA** | Eksekusi sesi tanya AI, dokumentasi prompt/respons, & refleksi | **Paket E (Role 5)** | *[Open Slot]* | [ ] Belum |
| **Draft AI Declaration Form** | Pengisian tabel pemanfaatan AI di `AI_Usage...docx` ACCA | **Paket E (Role 5)** | *[Open Slot]* | [ ] Belum |
| **QA, Review & Sign-off** | Code review seluruh program C (`-Wall`), integrasi, & TTD AI Form | **Paket A (Role 1)** | *[Open Slot]* | [ ] Belum |

---

## ✅ Action Checklist & TODO Tim ACCA

Checklist langkah kerja teknis dan pemantauan deliverable modul ACCA telah dipisahkan ke berkas khusus agar README tetap ringkas dan fokus:  
👉 📋 [**Buka Checklist & Action Plan ACCA (CHECKLIST.md)**](CHECKLIST.md)

---

## 🌐 Lembar Jawaban Cloud (Live Collaboration)

Laporan Praktikum ACCA dikerjakan bersama di Word Online untuk menghindari konflik file Word offline di Git:  
👉 🔗 [**Klik di Sini untuk Membuka Lembar Jawaban ACCA di Word Online (SharePoint)**](https://binusianorg-my.sharepoint.com/personal/chandra_perdiansyah_binus_ac_id/_layouts/15/guestaccess.aspx?share=IQDlFVz24AVrRrV23UQVi01wAd2XouL18Zle9THxrp1UASs&e=Urmhib)

---

## 📁 Struktur Berkas Modul ACCA

```text
ACCA/
├── Tugas Praktikum 2 (Kelompok)...docx   # Panduan soal resmi praktikum
├── docs/                                  # Modul PDF resmi Binus (LN01, LN02, Praktikum 2 & 3)
├── AI_Usage_Declaration_Form_EN.docx      # Formulir deklarasi AI resmi ACCA
├── CHECKLIST.md                           # Checklist & action plan detail per sub-tugas
├── tugas2c-haicola.md                     # Dokumentasi lengkap sesi HAICOLA Tugas 2C (Siap Copy)
├── tugas2a.c                              # Starter code data pegawai (Struct)
├── tugas2b.c                              # Starter code gaji bulanan + jam lembur
├── tugas2c.c                              # Program selesai: diskon belanja 5% & kupon undian
└── README.md                              # Dokumentasi teknis & tautan cloud ACCA ini
```

---

## 🚀 Panduan Menjalankan Program ACCA

```bash
# 1. Jalankan Tugas 2A
gcc -Wall -Wextra tugas2a.c -o tugas2a.exe
./tugas2a.exe

# 2. Jalankan Tugas 2B
gcc -Wall -Wextra tugas2b.c -o tugas2b.exe
./tugas2b.exe

# 3. Jalankan Tugas 2C
gcc -Wall -Wextra tugas2c.c -o tugas2c.exe
./tugas2c.exe
```
