# 🛒 ACCA — Tugas Praktikum 2 (Team Assignment 1) - Week 7
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** ACCA - LAB  
**Teaching Assistant / Aslab:** CS015 - ACHMAD ALIF NASRULLOH  
**Kelompok:** Group 1  
**Topik Utama:** Struct, Selection, Arithmetic Operators, Function, dan Validasi AI (HAICOLA)  

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

## 🌐 Lembar Jawaban Cloud (Live Collaboration)

Laporan Praktikum ACCA dikerjakan bersama di Word Online untuk menghindari konflik file Word offline di Git:  
👉 🔗 [**Klik di Sini untuk Membuka Lembar Jawaban ACCA di Word Online (SharePoint)**](https://binusianorg-my.sharepoint.com/personal/chandra_perdiansyah_binus_ac_id/_layouts/15/guestaccess.aspx?share=IQDlFVz24AVrRrV23UQVi01wAd2XouL18Zle9THxrp1UASs&e=Urmhib)

---

## 📁 Struktur Berkas Modul ACCA

```text
ACCA/
├── Tugas Praktikum 2 (Kelompok)...docx   # Panduan soal resmi praktikum
├── AI_Usage_Declaration_Form_EN.docx      # Formulir deklarasi AI resmi ACCA
├── DRAFT_LAPORAN_ACCA.md                  # Template checklist & panduan isi laporan
├── tugas2a.c                              # Starter code data pegawai (Struct)
├── tugas2b.c                              # Starter code gaji bulanan + jam lembur
├── tugas2c.c                              # Starter code diskon belanja 5% & kupon undian
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
