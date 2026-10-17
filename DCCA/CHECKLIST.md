# ✅ Checklist & Action Plan — Modul DCCA (LEC)
**Mata Kuliah:** Algorithm and Programming (COMP6112036) — Kelas DCCA  
**Studi Kasus:** Perpustakaan Digital Lentera Nusantara  
**Dokumen Laporan Live:** [Word Online SharePoint DCCA](https://binusianorg-my.sharepoint.com/personal/chandra_perdiansyah_binus_ac_id/_layouts/15/guestaccess.aspx?share=IQAT74haa2EvTK_6WGCo91GhAU4SjPmNGDBg92X-XnNqohQ&e=ZqP1tV)

Gunakan berkas ini untuk melacak perkembangan tugas, checklist pengerjaan kode C, perancangan flowchart, analisis memori, serta kelengkapan laporan kelompok.

---

## 👥 Ringkasan PIC & Status Tugas DCCA

| Sub-Tugas | File Deliverable | PIC (Anggota) | Status Pengerjaan |
|---|---|:---:|:---:|
| **Soal 1 — Kode C** | `question_1.c` | *[Paket B / Role 2]* | 🟢 Selesai (Kode di Git) |
| **Soal 1 — Flowchart & Desain** | Teks & Diagram (Word) | *[Paket B / Role 2]* | 🟢 Selesai (Diinjeksikan ke Word) |
| **Soal 1 — Analisis Memori** | Teks Analisis (Word) | *[Paket D / Role 4]* | 🟢 Selesai (Diinjeksikan ke Word) |
| **Soal 2 — Analisis RCA Bug** | Teks Analisis (Word) | *[Paket C / Role 3]* | 🟢 Selesai (Sudah Dikoreksi) |
| **Soal 2 — Kode C Perbaikan** | `question_2_fixed.c` | *[Paket C / Role 3]* | 🟢 Selesai (Sinkron di Git) |
| **Soal 2 — Flowchart Sorting** | Diagram Gambar (Word) | *[Paket D / Role 4]* | 🟢 Selesai di Word (Link Canva) |
| **Laporan & Referensi DCCA** | `TK1-W7-S15-R3 - Jawab (1).docx` | *[Paket E / Role 5]* | 🟢 **100% LENGKAP (Soal 1 & 2)** |
| **AI Declaration Form & QA** | `AI_Usage...docx` | *[Paket A & E]* | 🟡 Menunggu TTD & Submisi |

---

## 📌 Checklist Rinci Per Sub-Tugas

### 1. Soal 1: Desain & Analisis Struct dan Union (Bobot 60%)
*PIC: Paket B (Role 2) & Paket D (Role 4)*

- [x] **Koding C (`question_1.c`):**
  - [x] Definisikan `struct InfoBuku` (penulis, jumlah halaman) dan `struct InfoMajalah` (nomor edisi, bulan terbit).
  - [x] Definisikan `union DetailMedia` yang membungkus `InfoBuku` dan `InfoMajalah`.
  - [x] Definisikan `struct ItemKatalog` yang memuat judul, tahun terbit, jenis media (`enum`), dan `DetailMedia`.
  - [x] Lengkapi fungsi `input_item()` untuk menerima data dari user (percabangan input sesuai jenis media).
  - [x] Lengkapi fungsi `tampilkan_item()` untuk mencetak rincian katalog sesuai jenis media.
  - [x] Uji kompilasi: `gcc -Wall -Wextra question_1.c -o question_1.exe` (0 warning / 0 error).
- [x] **Laporan Word (`TK1-W7-S15-R3 - Jawab (1).docx`):**
  - [x] Tuliskan penjelasan konsep struktur data yang diusulkan dan alasan pemisahan `struct`/`union`.
  - [x] Tuliskan narasi alur **Flowchart Soal 1** (alur input $\rightarrow$ selection media $\rightarrow$ cetak output).
  - [x] Tuliskan analisis efisiensi memori kuantitatif:
    - Ukuran byte `sizeof(InfoBuku)` (54 B), `sizeof(InfoMajalah)` (24 B), dan `sizeof(DetailMedia)` (54 B).
    - Perbandingan memori struct biasa (78 B) vs union (54 B) -> penghematan 24 B (~30.77%) per item.
    - Simulasi penghematan 240 KB RAM untuk 10.000 item koleksi.
  - [x] Salin source code `question_1.c` lengkap dengan blok kode monospace dan sitasi referensi LN07.

---

### 2. Soal 2: Debugging & Analisis Sorting Koleksi (Bobot 40%)
*PIC: Paket C (Role 3) & Paket D (Role 4)*

- [x] **Koding C & Analisis Bug (`question_2_fixed.c`):**
  - [x] Lakukan Root Cause Analysis (RCA) pada fungsi sorting lama milik Ibu Arini:
    - Tracing manual kegagalan array pada iterasi terakhir: array menjadi `[12, 25, 34, 64, 22]`.
  - [x] Perbaiki fungsi `sort()` menggunakan Bubble Sort yang benar (`for i=0..n-1`, `for j=0..n-1-i`, `arr[j] > arr[j+1]`).
  - [x] Uji coba fungsi dengan array yang diberikan di soal: `{64, 34, 25, 12, 22}` $\rightarrow$ `{12, 22, 25, 34, 64}`.
- [x] **Laporan Word (`TK1-W7-S15-R3 - Jawab (1).docx`):**
  - [x] Tuliskan narasi penjelasan letak bug dan dampaknya terhadap array (sudah di Word).
  - [x] Buat dan tempelkan gambar **Flowchart Sorting Soal 2** (link Canva sudah di Word).
  - [x] Lampirkan screenshot output terminal eksekusi `soal2_fixed.exe` (sudah di Word).
  - [x] Salin source code `question_2_fixed.c` ke lembar jawaban (sudah di Word).
  - [x] *Action Selesai:* Koreksi typo konsep di Word ("nilai dikiri lebih kecil" -> "lebih besar") & "j > n" -> "j < n".

---

### 3. Administrasi & Finalisasi Modul DCCA
*PIC: Paket A (Role 1) & Paket E (Role 5)*
- [ ] Cantumkan referensi resmi materi lecture (`DCCA/docs/LN04`, `LN05`, `LN06`, `LN07`).
- [ ] Lengkapi tabel pemanfaatan AI pada `AI_Usage_Declaration_Form_EN.docx` (pemanfaatan ~10–15% untuk brainstorming RCA).
- [ ] Quality Review seluruh isi dokumen Word dan kompilasi akhir oleh Project Coordinator.
- [ ] Penandatanganan formulir AI dan persiapan berkas pengumpulan.
