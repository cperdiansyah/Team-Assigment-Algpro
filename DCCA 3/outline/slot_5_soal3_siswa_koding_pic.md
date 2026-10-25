# 📝 LEMBAR KERJA SLOT 5: SOAL 3B & KOMPILASI DOKUMEN (PIC)
**Fokus Soal:** Soal 3 (Implementasi Program C) & Integrator Proyek  
**Modul:** Soal 3B (Implementasi C Linear Search + Array of Struct), Manajemen Berkas `siswa.txt`, Format Referensi Formal, dan Kompilasi Laporan Akhir  
**Penanggung Jawab (PIC):** Chandra Perdiansyah  
**NIM:** 3002887011  
**Bobot Bagian:** 20% + Peran Integrasi Tim  

---

## 🎯 Target Deliverables PIC

1. **Soal 3B (Implementasi Program C):**  
   - Menulis kode program C yang bersih, modular, dan lolos kompilasi tanpa warning (`gcc -Wall -Wextra -std=c11`).
   - Menerapkan pembacaan `siswa.txt` ke dalam `array of struct`.
   - Mengimplementasikan algoritma *Linear Search* (`strcmp`) serta penanganan validasi informatif jika data siswa tidak ditemukan.
   - Menyediakan berkas data sampel di `docs/siswa.txt`.
2. **Format Daftar Referensi:**  
   - Memastikan seluruh sumber yang digunakan tim mematuhi format wajib BINUS:  
     $$\text{Nama sumber, Tautan (jika ada), diakses pada [Tanggal Akses]}$$
3. **Kompilasi Laporan Akhir:**  
   - Mengumpulkan seluruh draf dari Slot 1, Slot 2, Slot 3, dan Slot 4.
   - Menggabungkan ke template resmi laporan Word / SharePoint kelompok.

---

## ✍️ RANGKUMAN PENGERJAAN SLOT 5

### 1. Implementasi Kode Program C (`src/search_siswa.c`)
- [x] Kode program C telah dibuat di [`../src/search_siswa.c`](../src/search_siswa.c).
- [x] Berkas sampel data teks siswa telah dibuat di [`../docs/siswa.txt`](../docs/siswa.txt).
- [x] Telah diuji kompilasi dengan GCC 15.2.0 (`gcc -Wall -Wextra -std=c11 search_siswa.c -o search_siswa.exe`).
- [x] Validasi data berhasil diuji untuk skenario data ditemukan (`Citra`) dan skenario data tidak ditemukan (`Zul`).

### 2. Standar Format Daftar Referensi Wajib
1. Deitel, P. J., & Deitel, H. M., *C How to Program: With an Introduction to C++* (8th Edition), Pearson Education, diakses pada 23 Oktober 2026.
2. Kernighan, B. W., & Ritchie, D. M., *The C Programming Language* (2nd Edition), Prentice Hall Software Series, diakses pada 23 Oktober 2026.
3. Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C., *Introduction to Algorithms* (3rd Edition), MIT Press, https://mitpress.mit.edu/9780262033848/introduction-to-algorithms/, diakses pada 23 Oktober 2026.
4. GeeksforGeeks, *Tower of Hanoi - Recursion Algorithm and Complexity Analysis*, https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/, diakses pada 23 Oktober 2026.
5. GNU Operating System, *The GNU C Library Reference Manual: Searching and Sorting Functions*, Free Software Foundation, https://www.gnu.org/software/libc/manual/, diakses pada 23 Oktober 2026.
6. BINUS University, *Lecture Notes 06: Function and Recursion - Algorithm and Programming*, Binus Online Learning, diakses pada 23 Oktober 2026.
7. BINUS University, *Lecture Notes 07: Structures & Union - Algorithm and Programming*, Binus Online Learning, diakses pada 23 Oktober 2026.
8. BINUS University, *Lecture Notes 09: File Processing and Searching Techniques*, Binus Online Learning, diakses pada 23 Oktober 2026.

---

## 📚 Referensi Pendukung
- Buka dokumen studi kasus HAICOLA Soal 3 di [`./haicola/haicola-soal3-search-siswa.md`](./haicola/haicola-soal3-search-siswa.md).
- Berkoordinasi dengan pemegang **Slot 4** yang merancang pseudo code dan analisis data.
