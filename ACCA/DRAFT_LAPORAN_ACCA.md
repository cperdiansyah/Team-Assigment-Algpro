# 📋 TEMPLATE PANDUAN LAPORAN TUGAS PRAKTIKUM 2 (WEEK 7) — ACCA
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** ACCA - LAB  
**Teaching Assistant / Aslab:** CS015 - ACHMAD ALIF NASRULLOH  
**Kelompok:** Group 1  

> 💡 **Petunjuk Penggunaan:**  
> File ini adalah *starter template / outline* panduan penyusunan laporan praktikum ACCA. Anggota tim dapat mengisi setiap bagian berikut setelah menyelesaikan kodingan di `tugas2a.c`, `tugas2b.c`, dan `tugas2c.c`, lalu memindahkannya ke berkas resmi `Tugas Praktikum 2 (Kelompok) - Week 7 - Jawab.docx`.

---

## TUGAS 2A: DATA PEGAWAI & GAJI POKOK (Bobot 30%)
*(PIC: Core Developer / Penanggung Jawab Tugas 2A)*

### 1. Penjelasan Program (`tugas2a.c`)
- [ ] Jelaskan struktur `struct Pegawai` dan 6 field input yang digunakan (NIP, Nama, Alamat, No HP, Jabatan, Golongan).
- [ ] Jelaskan logika penentuan otomatis gaji pokok berdasarkan golongan:
  - Golongan `D1` $\rightarrow$ Rp 3.000.000
  - Golongan `D2` $\rightarrow$ Rp 2.500.000
  - Golongan `D3` $\rightarrow$ Rp 2.000.000

### 2. Tangkapan Layar (Screenshot) / Log Eksekusi Terminal
- [ ] Jalankan program `tugas2a.exe` di terminal/CLion.
- [ ] Tempelkan screenshot hasil input dan output data pegawai lengkap di sini.

---

## TUGAS 2B: TOTAL GAJI BULANAN & JAM LEMBUR (Bobot 30%)
*(PIC: Algorithm Specialist / Penanggung Jawab Tugas 2B)*

### 1. Penjelasan Program (`tugas2b.c`)
- [ ] Jelaskan input yang diminta: NIP, Golongan, dan Jumlah Jam Lembur.
- [ ] Jelaskan tarif lembur per jam sesuai golongan:
  - Golongan `D1` $\rightarrow$ Rp 15.000 / jam
  - Golongan `D2` $\rightarrow$ Rp 10.000 / jam
  - Golongan `D3` $\rightarrow$ Rp 5.000 / jam
- [ ] Jelaskan rumus perhitungan total gaji:  
  $$\text{Total Gaji} = \text{Gaji Pokok} + (\text{Jam Lembur} \times \text{Tarif Lembur})$$

### 2. Tangkapan Layar (Screenshot) / Log Eksekusi Terminal
- [ ] Jalankan program `tugas2b.exe`.
- [ ] Tempelkan screenshot hasil rincian gaji dan kalkulasi lembur di sini.

---

## TUGAS 2C: PROGRAM HADIAH BELANJA & DISKON (Bobot 30%)
*(PIC: Customer Module Specialist / Penanggung Jawab Tugas 2C)*

### 1. Penjelasan Program (`tugas2c.c`)
- [ ] Jelaskan input yang diminta: Total Pembelian (Rp).
- [ ] Jelaskan mekanisme perhitungan kupon undian:
  - 1 kupon per kelipatan **Rp 100.000,00** dengan pembulatan ke bawah (*floor / integer division*).
- [ ] Jelaskan mekanisme perhitungan diskon:
  - Diskon **5%** jika total pembelian minimal **Rp 100.000,00** (dihitung dari total pembelian awal).
- [ ] Jelaskan kalkulasi total yang harus dibayar ($\text{Total Awal} - \text{Diskon}$).

### 2. Tangkapan Layar (Screenshot) / Log Eksekusi Terminal
- [ ] Jalankan program `tugas2c.exe` dengan contoh uji belanja (misal: Rp 250.000).
- [ ] Tempelkan screenshot struk rincian pembelian di sini.

---

## SOAL 2D: HAICOLA — PEMANFAATAN AI UNTUK VALIDASI LOGIKA & DEBUGGING (Bobot 10%)
*(PIC: AI Ethics Officer & Penanggung Jawab Dokumentasi)*

> ⚠️ **Catatan Penting Binus:** AI digunakan sebagai *asisten debugging & analisis logika*, bukan untuk membuat seluruh program dari awal!

### 1. Potongan Kode yang Dikonsultasikan ke AI
- [ ] Pilih salah satu potongan kode dari Tugas 2A, 2B, atau 2C (misal: bagian percabangan golongan atau rumus kupon/diskon) lalu tempelkan di sini.

### 2. Prompt / Pertanyaan yang Diajukan ke AI
- [ ] Tuliskan prompt asli yang diajukan ke AI.  
  *Contoh topik:* Validasi ekspresi pembulatan kupon, penanganan input negatif, atau presisi tipe data `double` untuk currency.

### 3. Jawaban dan Evaluasi dari AI
- [ ] Tempelkan jawaban atau screenshot respons dari AI terkait logika kode tersebut.

### 4. Refleksi Singkat (2–5 Kalimat)
*(Wajib berisi: apa yang dipelajari dan perbaikan nyata apa yang dilakukan pada program setelah konsultasi)*
- [ ] Tuliskan refleksi 2–5 kalimat di sini.

---

## 📑 DAFTAR LAMPIRAN & REFERENSI
1. Berkas Formulir `AI_Usage_Declaration_Form_EN.docx` (Diisi dan ditandatangani oleh Chandra Perdiansyah).
2. Tiga berkas source code: `tugas2a.c`, `tugas2b.c`, dan `tugas2c.c`.
3. **Referensi Materi Kuliah (ACCA/docs):**
   - Binus Online. (2026). *LN02: Formatted Input and Output*. Algorithm and Programming (COMP6112036).
   - Binus Online. (2026). *Modul Praktikum 2: Program Control, Selection, Repetition & Pointer*.
   - Binus Online. (2026). *Modul Praktikum 3: Structures, Union, Function, Searching & Sorting*.
   - Deitel, P., & Deitel, H. (2022). *C How to Program (9th Edition)*. Pearson Education.
