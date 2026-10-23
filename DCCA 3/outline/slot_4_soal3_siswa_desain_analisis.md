# 📝 LEMBAR KERJA SLOT 4: SOAL 3A & 3C (PENCARIAN DATA SISWA — DESAIN & ANALISIS)
**Fokus Soal:** Soal 3 (Pencarian Data Siswa dari Berkas Teks)  
**Modul:** Soal 3A (Pseudo Code File & Linear Search) & Soal 3C (Analisis Perbandingan Data & Rekomendasi Optimasi)  
**Nama Anggota:** [Tulis Nama Lengkap Anda di sini]  
**NIM:** [Tulis NIM Anda di sini]  
**Bobot Bagian:** 20% dari total nilai tugas  
**Karakteristik Tugas:** *Desain Algoritma & Analisis Teori (Koding C diimplementasikan oleh PIC di Slot 5)*  

---

## 🎯 Instruksi Pengerjaan (Berdasarkan Soal Resmi Binus)
> *1. Soal 3A: "Tulis pseudo code untuk membaca data dari file dan melakukan pencarian berdasarkan nama."*  
> *2. Soal 3C: "Bandingkan secara konseptual waktu pencarian jika file berisi 10 data, 100 data, dan 1000 data. Apa rekomendasi Anda jika datanya semakin besar?"*

---

## 🤖 Cheat Sheet Prompt AI (Tinggal Salin ke ChatGPT / Claude / Gemini)

> 💡 **Cara Cepat & Praktis:**  
> Anda bisa langsung menyalin (*copy-paste*) prompt di bawah ini ke AI (ChatGPT, Claude, atau Gemini) untuk mendapatkan draf pseudo code dan tabel perbandingan data yang presisi:

```text
Bertindaklah sebagai asisten pengajar mata kuliah Algorithm and Programming (COMP6112036) BINUS University.
Saya memiliki tugas untuk merancang fitur pencarian data siswa dari file teks 'siswa.txt' (format per baris: [Nama] [Umur] [Nomor_Registrasi]) untuk kiosk interaktif museum.

Tolong buatkan:
1. Pseudo code untuk membaca data dari file ke array of struct dan melakukan Linear Search berdasarkan nama dengan validasi jika nama tidak ditemukan (gunakan kata kunci kapital BEGIN, END, IF, THEN, WHILE, DO, FOR, PRINT).
2. Analisis performa konseptual algoritma Linear Search jika basis data berisi:
   - 10 data
   - 100 data
   - 1.000 data
   Sertakan tabel perbandingan Best Case O(1), Average Case O(n/2), dan Worst Case O(n) beserta evaluasi kelayakannya untuk layar sentuh museum.
3. Tiga rekomendasi optimasi jika basis data berkembang hingga ratusan ribu data (misal: Sorting + Binary Search O(log n), Hash Table O(1), dan Struktur Data Trie/Prefix Tree untuk fitur auto-complete).
Gunakan bahasa Indonesia yang jelas, formal, dan akademis.
```

Setelah AI memberikan jawaban, silakan baca, pahami, dan tempelkan hasilnya pada lembar jawaban di bawah ini!

---

## ✍️ LEMBAR JAWABAN ANDA

### 1. Pseudo Code Pembacaan File & Linear Search (Soal 3A)

*Lengkapi bagian `// TODO` pada template berikut:*

```text
ALGORITHM PencarianDataSiswa
    INPUT:
        File "siswa.txt", string nama yang dicari (queryNama)
    OUTPUT:
        Detail data siswa (Nama, Umur, No.Reg) atau notifikasi tidak ditemukan

BEGIN
    // TODO 1: Deklarasi STRUCT Siswa dan Array penampung di memori
    DEFINE STRUCT Siswa:
        nama   : STRING
        umur   : INTEGER
        no_reg : STRING
    END STRUCT

    DECLARE ARRAY daftarSiswa[100] OF Siswa
    DECLARE totalSiswa = 0
    DECLARE FILE fp

    // TODO 2: Tahap Pembacaan Berkas Teks (File Handling)
    OPEN fp = fopen("siswa.txt", "r")
    IF fp IS NULL THEN
        PRINT "Pesan error: Berkas tidak ditemukan..."
        EXIT PROGRAM
    ENDIF

    WHILE totalSiswa < 100 AND fscanf(fp) SUKSES DO
        // Simpan data ke daftarSiswa[totalSiswa]
        totalSiswa = totalSiswa + 1
    ENDWHILE
    CLOSE fp

    // TODO 3: Input Nama dari Pengunjung
    PROMPT "Masukkan nama siswa yang dicari: "
    READ queryNama

    // TODO 4: Algoritma Linear Search
    DECLARE foundIndex = -1
    FOR i = 0 TO totalSiswa - 1 DO
        IF [Kondisi nama cocok menggunakan strcmp] THEN
            foundIndex = i
            BREAK
        ENDIF
    ENDFOR

    // TODO 5: Validasi Hasil
    IF foundIndex != -1 THEN
        PRINT "Data Ditemukan: " + daftarSiswa[foundIndex].nama
    ELSE
        PRINT "Validasi: Maaf, siswa tidak ditemukan dalam database."
    ENDIF
END
```

---

### 2. Analisis Perbandingan Waktu Pencarian Linear Search (Soal 3C - Bagian 1)

*Lengkapi tabel perbandingan konseptual berikut:*

| Ukuran Data ($N$) | Best Case | Average Case | Worst Case | Evaluasi Kelayakan untuk Layar Sentuh Museum |
| :---: | :---: | :---: | :---: | :---|
| **$N = 10$ Data** | 1 perbandingan | [Isi...] | [Isi...] | [Tuliskan evaluasi responsivitas...] |
| **$N = 100$ Data** | 1 perbandingan | [Isi...] | [Isi...] | [Tuliskan evaluasi responsivitas...] |
| **$N = 1.000$ Data** | 1 perbandingan | [Isi...] | [Isi...] | [Tuliskan evaluasi responsivitas...] |
| **$N \ge 100.000$ Data** | 1 perbandingan | [Isi...] | [Isi...] | [Tuliskan evaluasi responsivitas...] |

---

### 3. Rekomendasi Solusi Jika Data Semakin Besar (Soal 3C - Bagian 2)

*Jelaskan 3 alternatif optimasi berikut dengan bahasa Anda sendiri:*

1. **Rekomendasi 1: Sorting + Binary Search ($\mathcal{O}(\log n)$)**  
   > *Penjelasan Anda:*  
   > [Jelaskan cara kerja dan efisiensi perbandingannya...]

2. **Rekomendasi 2: Hash Table / Hash Map ($\mathcal{O}(1)$ Rata-rata)**  
   > *Penjelasan Anda:*  
   > [Jelaskan keunggulan pencarian waktu konstan...]

3. **Rekomendasi 3: Struktur Data Trie (Prefix Tree)**  
   > *Penjelasan Anda:*  
   > [Jelaskan mengapa cocok untuk fitur auto-complete pada layar sentuh museum...]

---

## 📚 Referensi Pendukung
- Buka dokumen studi kasus HAICOLA Soal 3 di [`./haicola/haicola-soal3-search-siswa.md`](./haicola/haicola-soal3-search-siswa.md) untuk melihat analisis perbandingan skala data.
- Anda dapat berkoordinasi dengan **Slot 5 (PIC)** yang mengimplementasikan kode C `search_siswa.c`.
