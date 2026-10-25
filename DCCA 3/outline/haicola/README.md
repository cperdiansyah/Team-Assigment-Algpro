# 🤖 PUSAT DOKUMENTASI HAICOLA (HUMAN-AI COLLABORATION) — TK3 (WEEK 9)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** DCCA - LEC (Computer Science)  
**Dosen Pengampu:** D5816 - ERIC GUNAWAN, S.Kom., M.TI  
**Minggu Perkuliahan:** Week 9 (Sesi 22 - R3)  
**Kelompok:** Group 1  
**Koordinator (PIC):** Chandra Perdiansyah  

---

## 📌 Apa Itu Dokumen HAICOLA?

Dokumen **HAICOLA (Human-AI Collaboration)** adalah dokumentasi transparansi resmi yang mencatat interaksi kolaboratif antara mahasiswa dan asisten kecerdasan buatan (*AI Code Assistant*).

Dokumen ini disusun untuk:
1. **Referensi Belajar Mandiri:** Membantu teman-teman anggota kelompok memahami konsep mendasar dari masing-masing soal (kenapa kodenya begitu, apa logikanya, bagaimana cara kerjanya).
2. **Panduan Prompting Terarah:** Mencontohkan struktur *prompt* terbaik yang dapat diajukan ke AI agar mendapatkan hasil analisis tingkat tinggi.
3. **Kepatuhan Kebijakan Integritas Akademik:** Menjadi lampiran resmi untuk pengisian formulir `AI_Usage_Declaration_Form_EN.docx` sesuai regulasi BINUS University.

---

## 📂 Katalog Berkas Referensi HAICOLA per Soal

| Berkas Dokumentasi | Relevansi Soal | Topik Utama yang Dibahas |
| :---| :---: | :---|
| [**`haicola-soal1-hanoi.md`**](./haicola-soal1-hanoi.md) | **Soal 1** (Slot 1 & Slot 2) | Desain fungsi rekursif Towers of Hanoi (4 cakram), pembuktian kondisi dasar (*base case* $n=1$), pemecahan sub-masalah ($n-1$), tabel 15 langkah perpindahan, dan penurunan persamaan rekurensi $T(n) = 2T(n-1) + 1 \implies \mathcal{O}(2^n)$. |
| [**`haicola-soal2-factorial.md`**](./haicola-soal2-factorial.md) | **Soal 2** (Slot 3) | Debugging & Root Cause Analysis (RCA) kesalahan logika faktorial rekursif asli, analisis kehabisan memori tumpukan (*Call Stack Overflow*), desain pseudo code aman, dan pemodelan diagram alur (*Flowchart*) ISO. |
| [**`haicola-soal3-search-siswa.md`**](./haicola-soal3-search-siswa.md) | **Soal 3** (Slot 4 & Slot 5) | Pemrosesan stream berkas teks `siswa.txt`, pemodelan struktur data `struct Siswa`, algoritma *Linear Search* (`strcmp`), validasi data tidak ditemukan, analisis perbandingan data (10, 100, 1.000 data), dan arsitektur optimasi skala besar (*Binary Search*, *Hash Map*, *Trie*). |

---

## 💡 Cara Teman-Teman Menggunakan Folder Ini

1. Buka berkas HAICOLA yang sesuai dengan slot tugas yang kalian ambil.
2. Pelajari bagian **"2. Prompt yang Diajukan ke AI"** dan **"3. Jawaban & Evaluasi Teknis AI"**.
3. Pahami konsepnya, lalu gunakan wawasan tersebut untuk melengkapi berkas lembar kerja kalian di folder `../` (misal: [`../slot_1_soal1_hanoi_algoritma.md`](../slot_1_soal1_hanoi_algoritma.md)).
4. Kalian bisa memodifikasi atau mengembangkan prompt tersebut di ChatGPT/Claude/Gemini untuk menghasilkan draf jawaban versi kalian sendiri!

