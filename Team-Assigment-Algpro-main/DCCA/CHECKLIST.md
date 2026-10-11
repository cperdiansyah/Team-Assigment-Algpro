# ✅ Checklist & Action Plan — Modul DCCA (LEC)
**Mata Kuliah:** Algorithm and Programming (COMP6112036) — Kelas DCCA  
**Studi Kasus:** Perpustakaan Digital Lentera Nusantara  
**Dokumen Laporan Live:** [Word Online SharePoint DCCA](https://binusianorg-my.sharepoint.com/personal/chandra_perdiansyah_binus_ac_id/_layouts/15/guestaccess.aspx?share=IQAT74haa2EvTK_6WGCo91GhAU4SjPmNGDBg92X-XnNqohQ&e=ZqP1tV)

Gunakan berkas ini untuk melacak perkembangan tugas, checklist pengerjaan kode C, perancangan flowchart, analisis memori, serta kelengkapan laporan kelompok.

---

## 👥 Ringkasan PIC & Status Tugas DCCA

| Sub-Tugas | File Deliverable | PIC (Anggota) | Status Pengerjaan |
|---|---|:---:|:---:|
| **Soal 1 — Kode C** | `DCCA/soal1.c` | *[Paket B / Role 2]* | 🟡 Menunggu Pengerjaan |
| **Soal 1 — Flowchart** | Diagram Gambar (Word) | *[Paket B / Role 2]* | 🟡 Menunggu Pengerjaan |
| **Soal 1 — Analisis Memori** | Teks Analisis (Word) | *[Paket D / Role 4]* | 🟡 Menunggu Pengerjaan |
| **Soal 2 — Analisis RCA Bug** | Teks Analisis (Word) | *[Paket C / Role 3]* | 🟡 Menunggu Pengerjaan |
| **Soal 2 — Kode C Perbaikan** | `DCCA/soal2_fixed.c` | *[Paket C / Role 3]* | 🟡 Menunggu Pengerjaan |
| **Soal 2 — Flowchart Sorting** | Diagram Gambar (Word) | *[Paket D / Role 4]* | 🟡 Menunggu Pengerjaan |
| **Laporan & Referensi DCCA** | Lembar Word SharePoint | *[Paket E / Role 5]* | 🟡 Menunggu Pengerjaan |
| **AI Declaration Form & QA** | `AI_Usage...docx` | *[Paket A & E]* | 🟡 Menunggu Finalisasi |

---

## 📌 Checklist Rinci Per Sub-Tugas

### 1. Soal 1: Desain & Analisis Struct dan Union (Bobot 60%)
*PIC: Paket B (Role 2) & Paket D (Role 4)*

- [ ] **Koding C (`DCCA/soal1.c`):**
  - [ ] Definisikan `struct InfoBuku` (penulis, jumlah halaman) dan `struct InfoMajalah` (nomor edisi, bulan terbit).
  - [ ] Definisikan `union DetailMedia` yang membungkus `InfoBuku` dan `InfoMajalah`.
  - [ ] Definisikan `struct ItemKatalog` yang memuat judul, tahun terbit, jenis media (`enum`), dan `DetailMedia`.
  - [ ] Lengkapi fungsi `input_item()` untuk menerima data dari user (percabangan input sesuai jenis media).
  - [ ] Lengkapi fungsi `tampilkan_item()` untuk mencetak rincian katalog sesuai jenis media.
  - [ ] Uji kompilasi: `gcc -Wall -Wextra soal1.c -o soal1.exe` (harus 0 warning / 0 error).
- [ ] **Laporan Word Online (SharePoint):**
  - [ ] Tuliskan penjelasan konsep struktur data yang diusulkan dan alasan pemisahan `struct`/`union`.
  - [ ] Buat dan tempelkan gambar **Flowchart Soal 1** (alur input $\rightarrow$ selection media $\rightarrow$ cetak output).
  - [ ] Tuliskan analisis efisiensi memori:
    - Hitung ukuran byte `sizeof(InfoBuku)`, `sizeof(InfoMajalah)`, dan `sizeof(DetailMedia)`.
    - Bandingkan total ukuran memori jika menggunakan `struct` biasa vs `union` (tunjukkan persentase/penghematan byte).
  - [ ] Salin source code `soal1.c` ke lembar jawaban.

---

### 2. Soal 2: Debugging & Analisis Sorting Koleksi (Bobot 40%)
*PIC: Paket C (Role 3) & Paket D (Role 4)*

- [ ] **Koding C & Analisis Bug (`DCCA/soal2_fixed.c`):**
  - [ ] Lakukan Root Cause Analysis (RCA) pada fungsi sorting lama milik Ibu Arini:
    - Identifikasi bug perulangan inner: `for (j = 0; j < n; j++)` (menyebabkan redundant pass dan merusak urutan elemen sebelumnya).
    - Identifikasi bug perbandingan elemen: `if (arr[j] > arr[i])` (tidak konsisten untuk perbandingan Bubble Sort / Selection Sort standar).
  - [ ] Perbaiki fungsi `sort()` menggunakan Bubble Sort yang benar (misal: inner loop `j = 0; j < n - 1 - i` dan bandingkan tetangga `arr[j] > arr[j + 1]`).
  - [ ] Uji coba fungsi dengan array yang diberikan di soal: `{64, 34, 25, 12, 22}`.
  - [ ] Pastikan output terurut ascending secara tepat: `{12, 22, 25, 34, 64}`.
  - [ ] Uji kompilasi: `gcc -Wall -Wextra soal2_fixed.c -o soal2_fixed.exe` (harus 0 warning).
- [ ] **Laporan Word Online (SharePoint):**
  - [ ] Tuliskan narasi penjelasan letak bug dan dampaknya terhadap array.
  - [ ] Buat dan tempelkan gambar **Flowchart Sorting Soal 2** (diagram alur Bubble Sort yang telah diperbaiki).
  - [ ] Lampirkan screenshot output terminal eksekusi `soal2_fixed.exe`.
  - [ ] Salin source code `soal2_fixed.c` ke lembar jawaban.

---

### 3. Administrasi & Finalisasi Modul DCCA
*PIC: Paket A (Role 1) & Paket E (Role 5)*
- [ ] Cantumkan referensi resmi materi lecture (`DCCA/docs/LN04`, `LN05`, `LN06`, `LN07`).
- [ ] Lengkapi tabel pemanfaatan AI pada `AI_Usage_Declaration_Form_EN.docx` (pemanfaatan ~10–15% untuk brainstorming RCA).
- [ ] Quality Review seluruh isi dokumen Word dan kompilasi akhir oleh Project Coordinator.
- [ ] Penandatanganan formulir AI dan persiapan berkas pengumpulan.
