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
| **Soal 1 — Flowchart** | Diagram Gambar (Word) | *[Paket B / Role 2]* | 🟡 Menunggu Pembuatan |
| **Soal 1 — Analisis Memori** | Teks Analisis (Word) | *[Paket D / Role 4]* | 🟡 Menunggu Pembuatan |
| **Soal 2 — Analisis RCA Bug** | Teks Analisis (Word) | *[Paket C / Role 3]* | 🟢 Selesai di Word (Perlu Koreksi Minor) |
| **Soal 2 — Kode C Perbaikan** | `question_2_fixed.c` | *[Paket C / Role 3]* | 🟢 Selesai (Sinkron di Git) |
| **Soal 2 — Flowchart Sorting** | Diagram Gambar (Word) | *[Paket D / Role 4]* | 🟢 Selesai di Word (Link Canva) |
| **Laporan & Referensi DCCA** | Lembar Word SharePoint | *[Paket E / Role 5]* | 🟡 Soal 2 Terisi, Soal 1 Masih Kosong |
| **AI Declaration Form & QA** | `AI_Usage...docx` | *[Paket A & E]* | 🟡 Menunggu Finalisasi |

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
  - [ ] Uji kompilasi: `gcc -Wall -Wextra soal1.c -o soal1.exe` (harus 0 warning / 0 error).
- [ ] **Laporan Word Online (SharePoint):**
  - [ ] Tuliskan penjelasan konsep struktur data yang diusulkan dan alasan pemisahan `struct`/`union`.
  - [ ] Buat dan tempelkan gambar **Flowchart Soal 1** (alur input $\rightarrow$ selection media $\rightarrow$ cetak output).
  - [ ] Tuliskan analisis efisiensi memori:
    - Hitung ukuran byte `sizeof(InfoBuku)`, `sizeof(InfoMajalah)`, dan `sizeof(DetailMedia)`.
    - Bandingkan total ukuran memori jika menggunakan `struct` biasa vs `union` (tunjukkan persentase/penghematan byte).
  - [ ] Salin source code `question_1.c` ke lembar jawaban.

---

### 2. Soal 2: Debugging & Analisis Sorting Koleksi (Bobot 40%)
*PIC: Paket C (Role 3) & Paket D (Role 4)*

- [x] **Koding C & Analisis Bug (`question_2_fixed.c`):**
  - [x] Lakukan Root Cause Analysis (RCA) pada fungsi sorting lama milik Ibu Arini:
    - Tracing manual kegagalan array pada iterasi terakhir: array menjadi `[12, 25, 34, 64, 22]`.
  - [x] Perbaiki fungsi `sort()` menggunakan Bubble Sort yang benar (`for i=0..n-1`, `for j=0..n-1-i`, `arr[j] > arr[j+1]`).
  - [x] Uji coba fungsi dengan array yang diberikan di soal: `{64, 34, 25, 12, 22}` $\rightarrow$ `{12, 22, 25, 34, 64}`.
- [x] **Laporan Word Online (SharePoint):**
  - [x] Tuliskan narasi penjelasan letak bug dan dampaknya terhadap array (sudah di Word).
  - [x] Buat dan tempelkan gambar **Flowchart Sorting Soal 2** (link Canva sudah di Word).
  - [x] Lampirkan screenshot output terminal eksekusi `soal2_fixed.exe` (sudah di Word).
  - [x] Salin source code `question_2_fixed.c` ke lembar jawaban (sudah di Word).
  - [ ] *Action:* Koreksi salah ketik konsep di Word ("nilai dikiri lebih kecil" -> "lebih besar").

---

### 3. Administrasi & Finalisasi Modul DCCA
*PIC: Paket A (Role 1) & Paket E (Role 5)*
- [ ] Cantumkan referensi resmi materi lecture (`DCCA/docs/LN04`, `LN05`, `LN06`, `LN07`).
- [ ] Lengkapi tabel pemanfaatan AI pada `AI_Usage_Declaration_Form_EN.docx` (pemanfaatan ~10–15% untuk brainstorming RCA).
- [ ] Quality Review seluruh isi dokumen Word dan kompilasi akhir oleh Project Coordinator.
- [ ] Penandatanganan formulir AI dan persiapan berkas pengumpulan.
