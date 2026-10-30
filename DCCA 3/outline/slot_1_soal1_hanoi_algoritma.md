# 📝 LEMBAR KERJA SLOT 1: SOAL 1A & 1B (TOWERS OF HANOI — BAGIAN ALGORITMA)
**Fokus Soal:** Soal 1 (Towers of Hanoi 4 Cakram)  
**Modul:** Soal 1A (Pseudo Code) & Soal 1B (Penjelasan Alur Rekursi, Base Case, dan 15 Langkah)  
**Nama Anggota:** Arsyan Qasthari  
**NIM:** 3002924032  
**Bobot Bagian:** 20% dari total nilai tugas  

---

## 🎯 Instruksi Pengerjaan (Berdasarkan Soal Resmi Binus)
> *"Buat pseudo code untuk fungsi rekursif Towers of Hanoi.*  
> *Jelaskan secara terperinci setiap langkah rekursi, termasuk kondisi dasar (base case) dan cara fungsi memecah masalah menjadi sub-masalah yang lebih kecil."*

**Tugas Anda:**
1. Lengkapi bagian *pseudo code* di bawah ini.
2. Jawab pertanyaan penjelasan konsep rekursi & *base case*.
3. Lengkapi tabel urutan 15 perpindahan cakram dari Tiang A ke Tiang C.

---

## 🤖 Cheat Sheet Prompt AI (Tinggal Salin ke ChatGPT / Claude / Gemini)

> 💡 **Cara Cepat & Praktis:**  
> Anda bisa langsung menyalin (*copy-paste*) prompt di bawah ini ke AI (ChatGPT, Claude, atau Gemini) untuk mendapatkan draf jawaban yang akurat, rapi, dan sesuai standar tugas:

```text
Bertindaklah sebagai asisten pengajar mata kuliah Algorithm and Programming (COMP6112036) BINUS University.
Saya memiliki tugas kelompok untuk merancang algoritma rekursif Towers of Hanoi dengan 4 cakram dari Tiang A (Source) ke Tiang C (Destination) dengan Tiang B (Auxiliary).

Tolong buatkan:
1. Pseudo code fungsi rekursif SolveHanoi(n, source, dest, aux) dengan format kata kunci kontrol huruf kapital (BEGIN, END, IF, THEN, CALL, PRINT).
2. Penjelasan konsep:
   - Apa kondisi dasar (base case) saat n = 1 dan mengapa rekursi berhenti?
   - Bagaimana cara pemecahan masalah besar menjadi sub-masalah (n - 1) cakram?
3. Tabel urutan lengkap 15 langkah perpindahan cakram (dari langkah 1 sampai 15) untuk n = 4 cakram dengan kolom:
   No Langkah | Cakram yang Dipindahkan | Dari Tiang | Menuju Tiang | Penjelasan Singkat Logika
Gunakan bahasa Indonesia yang jelas, formal, dan akademis.
```

Setelah AI memberikan jawaban, silakan baca, pahami, dan tempelkan hasilnya pada lembar jawaban di bawah ini!

---

## ✍️ LEMBAR JAWABAN ANDA

### 1. Pseudo Code Algoritma Rekursif Towers of Hanoi (Soal 1A)
*Lengkapi bagian `// TODO` pada template berikut:*

```text
ALGORITHM SolveHanoi(n, sourceRod, destinationRod, auxiliaryRod)
    INPUT:
        n              : Jumlah cakram yang akan dipindahkan (integer)
        sourceRod      : Label tiang asal (misal: 'A')
        destinationRod : Label tiang tujuan (misal: 'C')
        auxiliaryRod   : Label tiang pembantu sementara (misal: 'B')
    OUTPUT:
        Cetak urutan instruksi perpindahan cakram

BEGIN
    // TODO 1: Tuliskan Kondisi Dasar (Base Case)
    // Apa yang harus dilakukan jika hanya tersisa 1 cakram (n == 1)?
     IF n == 1 THEN
        PRINT "Pindahkan cakram 1 dari", sourceRod, "ke", destinationRod
        RETURN
    ENDIF

    // TODO 2: Tuliskan Pemanggilan Rekursif Pertama (Sub-masalah 1)
    // Pindahkan (n - 1) cakram dari sourceRod ke auxiliaryRod menggunakan destinationRod
    CALL SolveHanoi(n - 1, sourceRod, auxiliaryRod, destinationRod)

    // TODO 3: Tuliskan Langkah Pemindahan Cakram Terbesar (Langkah Utama)
    // Pindahkan cakram ke-n dari sourceRod langsung ke destinationRod
    PRINT "Pindahkan cakram", n, "dari", sourceRod, "ke", destinationRod

    // TODO 4: Tuliskan Pemanggilan Rekursif Kedua (Sub-masalah 2)
    // Pindahkan (n - 1) cakram dari auxiliaryRod ke destinationRod menggunakan sourceRod
    CALL SolveHanoi(n - 1, auxiliaryRod, destinationRod, sourceRod)
END
```

---

### 2. Penjelasan Detail Langkah Rekursi & Kondisi Dasar (Soal 1B)

*Jawab pertanyaan pemandu berikut secara ringkas dan jelas:*

1. **Apa itu Kondisi Dasar (*Base Case*) dalam algoritma ini dan mengapa saat $n = 1$ rekursi berhenti?**  
   > *Jawaban Anda:*  
   > Kondisi dasar (base case) adalah batas akhir dari fungsi rekursif agar program tidak mengalami infinite loop (pengulangan tanpa batas). Ketika $n = 1$, masalahnya sudah sangat sederhana sehingga cakram tinggal langsung dipindahkan dari tiang asal ke tiang tujuan tanpa butuh tiang bantuan lagi. Lalu fungsi dihentikan dengan perintah return

2. **Bagaimana fungsi memecah masalah besar menjadi sub-masalah yang lebih kecil ($n - 1$)?**  
   > *Jawaban Anda:*  
   > Fungsi memecah masalah besar dengan prinsip divide and conquer. Untuk memindahkan $n$ cakram dari tiang asal ke tiang tujuan, algoritma membaginya menjadi tiga tahap utama: (1) Memindahkan $n-1$ cakram teratas ke tiang pembantu agar tiang asal clean, (2) Memindahkan cakram terbesar ke-$n$ langsung ke tiang tujuan, dan (3) Memindahkan kembali $n-1$ cakram dari tiang pembantu ke atas tiang tujuan

---

### 3. Tabel Urutan 15 Langkah Perpindahan (Untuk $n = 4$ Cakram)

*Lengkapi tabel perpindahan fisik cakram dari Tiang A ke Tiang C berikut (Total $2^4 - 1 = 15$ langkah):*

| Langkah | Cakram yang Dipindahkan | Dari Tiang | Menuju Tiang | Penjelasan Singkat Logika |
| :---: | :---: | :---: | :---: | :---|
| **1** | Cakram 1 (Terkecil) | A | B | Memindahkan cakram 1 ke tiang pembantu (B) sebagai langkah awal membuka jalan |
| **2** | Cakram 2 | A | C | Memindahkan cakram 2 ke tiang tujuan (C) |
| **3** | Cakram 1 | B | C | Menumpuk kembali cakram 1 di atas cakram 2 pada tiang C |
| **4** | Cakram 3 | A | B | Memindahkan cakram 3 ke tiang pembantu (B) |
| **5** | Cakram 1 | C | A | Memindahkan cakram 1 sementara ke tiang A agar tiang C kosong |
| **6** | Cakram 2 | C | B | Menumpuk cakram 2 di atas cakram 3 pada tiang B |
| **7** | Cakram 1 | A | B | Menempatkan kembali cakram 1 di atas tumpukan tiang B |
| **8** | **Cakram 4 (Terbesar)** | **A** | **C** | **Cakram terbesar berhasil mendarat di tiang tujuan!** |
| **9** | Cakram 1 | B | C | Memindahkan cakram 1 ke tiang C untuk memulai penyusunan ulang |
| **10** | Cakram 2 | B | A | Memindahkan cakram 2 ke tiang asal (A) |
| **11** | Cakram 1 | C | A | Menumpuk cakram 1 di atas cakram 2 pada tiang A |
| **12** | Cakram 3 | B | C | Memindahkan cakram 3 ke tiang tujuan (C) di atas cakram 4 |
| **13** | Cakram 1 | A | B | Memindahkan cakram 1 sementara ke tiang B |
| **14** | Cakram 2 | A | C | Menumpuk cakram 2 di tiang tujuan (C) |
| **15** | Cakram 1 (Terkecil) | B | C | Selesai! Seluruh 4 cakram tersusun sempurna di Tiang C. |

---

## 📚 Referensi Pendukung
- Deitel, P. J., & Deitel, H. M., C How to Program: With an Introduction to C++ (8th Edition), Pearson Education, diakses pada 25 Oktober 2026
- GeeksforGeeks, Tower of Hanoi - Recursion Algorithm and Complexity Analysis, https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/, diakses pada 25 Oktober 2026
- Anda dapat berkoordinasi dengan rekan pemegang **Slot 2** yang sama-sama mengerjakan topik Towers of Hanoi.