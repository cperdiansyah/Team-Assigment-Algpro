# 📋 PANDUAN OUTLINE & WORKFLOW PENGERJAAN TIM (TK3)
**Mata Kuliah:** Algorithm and Programming (COMP6112036) — Kelas DCCA  
**Minggu Perkuliahan:** Week 9 (Sesi 22 - R3)  

---

## 💡 Alur Pengerjaan untuk Anggota Tim

Halo teman-teman! Agar pengerjaan tugas kelompok ini **adil, jelas, dan tidak ada yang bingung harus menulis apa**, folder `outline/` ini sudah menyiapkan modul dan template khusus untuk masing-masing slot.

> [!IMPORTANT]
> **Prinsip Utama Pengerjaan:**
> 1. Berdasarkan soal resmi di `docs/TK3-W9-S22-R3.docx`, mayoritas soal **hanya meminta *pseudo code*, penjelasan, dan *flowchart*** (tidak diwajibkan menulis kode C rumit dari nol, kecuali pada Soal 3 yang sudah dicover oleh PIC).
> 2. Pilih salah satu slot di bawah ini yang paling kalian minati, lalu salin (*copy*) file templatenya atau langsung kerjakan pada file template tersebut.
> 3. Jika kalian menemui kendala atau bingung di bagian tertentu, silakan tanyakan dan koordinasikan langsung di grup WhatsApp kelompok.


---

## 🎯 Pembagian 5 Paket Slot Tugas

| Slot | Fokus Soal | Modul yang Dikerjakan | File Template Kerja | Kategori Kerja | Status |
| :---: | :---: | :---| :---| :---: | :---: |
| **Slot 1** | **Soal 1** *(Hanoi Part 1)* | **Soal 1A & 1B:** Pseudo code Towers of Hanoi (4 cakram) + Penjelasan alur rekursi, *base case* ($n=1$), dan tabel 15 langkah perpindahan cakram. | [`slot_1_soal1_hanoi_algoritma.md`](./slot_1_soal1_hanoi_algoritma.md) | Logika Algoritma | `[ ] Open Slot (TBD)` |
| **Slot 2** | **Soal 1** *(Hanoi Part 2)* | **Soal 1C & Diagram:** Penurunan matematis persamaan rekurensi $T(n) = 2T(n-1) + 1 \implies \mathcal{O}(2^n)$ dan ruang $\mathcal{O}(n)$ + Menggambar *flowchart* Towers of Hanoi. | [`slot_2_soal1_hanoi_teori_flowchart.md`](./slot_2_soal1_hanoi_teori_flowchart.md) | Teori & Visual | `[ ] Open Slot (TBD)` |
| **Slot 3** | **Soal 2** *(Faktorial Full)* | **Soal 2A, 2B & 2C:** Analisis akar penyebab (*RCA*) *bug* `infinite recursion` & *stack overflow* pada faktorial + Pseudo code perbaikan + *Flowchart* faktorial rekursif yang benar. | [`slot_3_soal2_faktorial_full.md`](./slot_3_soal2_faktorial_full.md) | Analisis & Visual | `[ ] Open Slot (TBD)` |
| **Slot 4** | **Soal 3** *(Siswa Part 1)* | **Soal 3A & 3C:** Pseudo code pembacaan berkas `siswa.txt` & Linear Search + Analisis perbandingan data (10, 100, 1.000 data) & rekomendasi optimasi skala besar. | [`slot_4_soal3_siswa_desain_analisis.md`](./slot_4_soal3_siswa_desain_analisis.md) | Desain & Analisis | `[ ] Open Slot (TBD)` |
| **Slot 5** | **Soal 3** *(Siswa Part 2 & PIC)* | **Soal 3B & Kompilasi:** Implementasi program C `search_siswa.c` (*array of struct* + *Linear Search*), pengelolaan berkas `siswa.txt`, penyusunan referensi formal, dan kompilasi laporan akhir Word. | [`slot_5_soal3_siswa_koding_pic.md`](./slot_5_soal3_siswa_koding_pic.md) | Koding C & Integrasi | `[x] Chandra` |



---

## 🤖 Butuh Referensi Tambahan & Inspirasi Prompting? Cek Folder HAICOLA!

Jika kalian ingin memahami konsep lebih dalam atau butuh inspirasi bagaimana cara menyusun prompt AI yang menghasilkan draf jawaban berkualitas tinggi, kalian bisa membuka folder:
📁 [**`haicola/`**](./haicola/README.md)
- [**`haicola/haicola-soal1-hanoi.md`**](./haicola/haicola-soal1-hanoi.md): Studi kasus & prompt AI untuk Towers of Hanoi (Slot 1 & Slot 2).
- [**`haicola/haicola-soal2-factorial.md`**](./haicola/haicola-soal2-factorial.md): Studi kasus & prompt AI untuk Faktorial Rekursif (Slot 3).
- [**`haicola/haicola-soal3-search-siswa.md`**](./haicola/haicola-soal3-search-siswa.md): Studi kasus & prompt AI untuk File Processing & Linear Search (Slot 4 & Slot 5).

---

## 🚀 3 Langkah Mudah Memulai

1. **Klaim Slot:** Buka obrolan grup kelompok dan pilih salah satu slot yang masih `[ ] Open Slot`.
2. **Buka Template:** Buka file `.md` yang sesuai di folder `outline/`. Di dalam file sudah ada instruksi jelas, pertanyaan pemandu, cheat sheet prompt AI, dan format jawaban yang tinggal kalian lengkapi.
3. **Kirim / Push:** Setelah selesai mengisi template kalian, laporkan ke grup agar terdokumentasi.

