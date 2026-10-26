# ✅ Checklist & Action Plan — Modul ACCA (LAB)
**Mata Kuliah:** Algorithm and Programming (COMP6112036) — Kelas ACCA  
**Studi Kasus:** Supermarket Nusantara Sejahtera  
**Dokumen Laporan Live:** [Word Online SharePoint ACCA](https://binusianorg-my.sharepoint.com/personal/chandra_perdiansyah_binus_ac_id/_layouts/15/guestaccess.aspx?share=IQDlFVz24AVrRrV23UQVi01wAd2XouL18Zle9THxrp1UASs&e=Urmhib)

Gunakan berkas ini untuk melacak perkembangan tugas, checklist pengerjaan kode C, serta kelengkapan laporan praktikum kelompok.

---

## 👥 Ringkasan PIC & Status Tugas ACCA

| Sub-Tugas | File Deliverable | PIC (Anggota) | Status Pengerjaan |
|---|---|:---:|:---:|
| **Tugas 2A** (Struct Pegawai & Gaji) | `ACCA/tugas2a.c` + Laporan | *[Paket B / Role 2]* | 🟡 Menunggu Pengerjaan |
| **Tugas 2B** (Gaji Bulanan & Lembur) | `ACCA/tugas2b.c` + Laporan | *[Paket C / Role 3]* | 🟡 Menunggu Pengerjaan |
| **Tugas 2C** (Diskon 5% & Kupon) | `ACCA/tugas2c.c` + Laporan | Chandra / *[Paket D]* | 🟢 Selesai (Kode) / 🟡 Laporan |
| **Tugas 2D** (HAICOLA AI Session) | `ACCA/tugas2c-haicola.md` | Chandra / *[Paket E]* | 🟢 Selesai (Draft) / 🟡 Form |
| **AI Declaration Form & QA** | `AI_Usage...docx` | *[Paket A & E]* | 🟡 Menunggu Finalisasi |

---

## 📌 Checklist Rinci Per Sub-Tugas

### 1. Tugas 2A: Data Pegawai & Gaji Pokok (Bobot 30%)
*PIC: Paket B (Role 2)*
- [ ] **Koding (`ACCA/tugas2a.c`):**
  - [ ] Definisikan `struct Pegawai` dengan 6 field: `nip`, `nama`, `alamat`, `no_hp`, `jabatan`, `golongan`.
  - [ ] Implementasikan input data pegawai menggunakan `scanf` / `fgets`.
  - [ ] Implementasikan fungsi `tentukan_gaji_pokok()` dengan perbandingan string `strcmp()`:
    - Golongan `D1`: Rp 3.000.000
    - Golongan `D2`: Rp 2.500.000
    - Golongan `D3`: Rp 2.000.000
  - [ ] Tampilkan output data pegawai lengkap secara rapi menggunakan `printf()`.
  - [ ] Uji kompilasi: `gcc -Wall -Wextra tugas2a.c -o tugas2a.exe` (harus 0 warning / 0 error).
- [ ] **Laporan Word Online (SharePoint):**
  - [ ] Tuliskan deskripsi struktur data dan alur logika penentuan gaji pokok.
  - [ ] Tangkap layar (screenshot) hasil eksekusi terminal `tugas2a.exe`.
  - [ ] Salin source code `tugas2a.c` ke lembar jawaban.

---

### 2. Tugas 2B: Perhitungan Total Gaji Bulanan + Lembur (Bobot 30%)
*PIC: Paket C (Role 3)*
- [ ] **Koding (`ACCA/tugas2b.c`):**
  - [ ] Menerima input: NIP, Golongan (`D1`/`D2`/`D3`), dan Jumlah Jam Lembur.
  - [ ] Tambahkan validasi jam lembur tidak boleh bernilai negatif (`jam_lembur >= 0`).
  - [ ] Tentukan tarif lembur per jam sesuai golongan:
    - Golongan `D1`: Rp 15.000 / jam
    - Golongan `D2`: Rp 10.000 / jam
    - Golongan `D3`: Rp 5.000 / jam
  - [ ] Hitung total upah bulanan: $\text{Total Gaji} = \text{Gaji Pokok} + (\text{Jam Lembur} \times \text{Tarif Lembur})$.
  - [ ] Tampilkan rincian output sesuai format soal (NIP, Golongan, Jam Lembur, Total Gaji).
  - [ ] Uji kompilasi: `gcc -Wall -Wextra tugas2b.c -o tugas2b.exe` (harus 0 warning / 0 error).
- [ ] **Laporan Word Online (SharePoint):**
  - [ ] Tuliskan penjelasan logika perhitungan dan rumus upah lembur.
  - [ ] Tangkap layar (screenshot) hasil eksekusi terminal `tugas2b.exe`.
  - [ ] Salin source code `tugas2b.c` ke lembar jawaban.

---

### 3. Tugas 2C: Program Hadiah Belanja & Diskon Pelanggan (Bobot 30%)
*PIC: Chandra / Paket D (Role 4)*
- [x] **Koding (`ACCA/tugas2c.c`):** *(SELESAI)*
  - [x] Input total transaksi belanja (validasi nilai > 0).
  - [x] Perhitungan kupon undian kelipatan Rp 100.000 menggunakan pembulatan ke bawah (*integer division* `/ 100000`).
  - [x] Perhitungan diskon 5% untuk pembelian minimal Rp 100.000.
  - [x] Tampilkan struk/output rincian pembelian sesuai mockup soal.
  - [x] Kompilasi & testing: Lolos uji tanpa warning (`gcc -Wall -Wextra`).
- [ ] **Laporan Word Online (SharePoint):**
  - [ ] Tuliskan penjelasan mekanisme pembulatan ke bawah (*floor*) dan aturan diskon.
  - [ ] Tangkap layar hasil run `tugas2c.exe` (contoh: belanja Rp 250.000 -> 2 kupon, diskon Rp 12.500, bayar Rp 237.500).
  - [ ] Salin source code `tugas2c.c` ke lembar jawaban.

---

### 4. Tugas 2D: Sesi Validasi AI (HAICOLA) (Bobot 10%)
*PIC: Chandra / Paket E (Role 5)*
- [] **Dokumentasi Lengkap (`ACCA/tugas2c-haicola.md`):** *(SELESAI)*
  - [] Kode awal sebelum konsultasi AI (potongan pembulatan kupon & diskon).
  - [] Prompt pertanyaan ke AI.
  - [] Evaluasi dan saran perbaikan dari AI (penjelasan integer division C).
  - [] Kode hasil perbaikan setelah konsultasi.
  - [] Narasi refleksi 4 kalimat mengenai pembelajaran dan perbaikan nyata.
- [ ] **Penyalinan ke Lembar Jawaban Word Online:**
  - [ ] Salin seluruh bagian dari `tugas2c-haicola.md` ke bagian Soal 2D di lembar jawaban SharePoint.

---

### 5. Administrasi & Finalisasi Modul ACCA
*PIC: Paket A (Role 1) & Paket E (Role 5)*
- [ ] Cantumkan daftar referensi modul perkuliahan (`ACCA/docs/LN01`, `LN02`, `Modul Praktikum 2 & 3`).
- [ ] Lengkapi tabel penggunaan AI di `AI_Usage_Declaration_Form_EN.docx` (pemanfaatan AI ~10% untuk validasi Soal 2D).
- [ ] Quality Review kode C dan format laporan oleh Project Coordinator.
- [ ] Tanda tangan formulir AI dan persiapan file `.zip` submisi.
