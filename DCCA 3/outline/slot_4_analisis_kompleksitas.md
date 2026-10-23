# 📝 LEMBAR KERJA SLOT 4: SOAL 1C & 3C (ANALISIS TEORI & KOMPLEKSITAS)
**Nama Anggota:** [Tulis Nama Lengkap Anda di sini]  
**NIM:** [Tulis NIM Anda di sini]  
**Modul:** Soal 1C (Kompleksitas Waktu Towers of Hanoi) & Soal 3C (Perbandingan Waktu Pencarian Data Siswa & Rekomendasi)  
**Bobot Bagian:** 25% dari total nilai tugas  
**Karakteristik Tugas:** *Murni Teks Analisis (Tidak membutuhkan koding C dan tidak membutuhkan gambar diagram)*  

---

## 🎯 Instruksi Pengerjaan (Berdasarkan Soal Resmi Binus)
> *1. Soal 1C: "Analisis dan sebutkan kompleksitas waktu algoritma berdasarkan jumlah cakram."*  
> *2. Soal 3C: "Bandingkan secara konseptual waktu pencarian jika file berisi 10 data, 100 data, dan 1000 data. Apa rekomendasi Anda jika datanya semakin besar?"*

---

## 🤖 Cheat Sheet Prompt AI (Tinggal Salin ke ChatGPT / Claude / Gemini)

> 💡 **Cara Cepat & Praktis:**  
> Tugas ini murni analisis teks teoretis. Anda bisa langsung menyalin (*copy-paste*) prompt di bawah ini ke AI (ChatGPT, Claude, atau Gemini) untuk mendapatkan penurunan rumus dan analisis yang presisi:

```text
Bertindaklah sebagai dosen mata kuliah Algorithm and Programming (COMP6112036) BINUS University.
Tolong bantu saya menyusun analisis teoretis algoritma:
1. Penurunan matematis persamaan rekurensi Towers of Hanoi:
   T(n) = 2T(n-1) + 1 dengan T(1) = 1 menggunakan metode substitusi berulang (repeated substitution) hingga terbukti kompleksitas waktunya O(2^n) dengan total langkah 2^n - 1, serta jelaskan kompleksitas ruang O(n) (call stack depth).
2. Analisis performa konseptual algoritma Linear Search (pencarian nama siswa) jika file berisi:
   - 10 data
   - 100 data
   - 1.000 data
   Sertakan tabel perbandingan Best Case O(1), Average Case O(n/2), dan Worst Case O(n) beserta evaluasi kelayakannya untuk layar sentuh interaktif museum.
3. Tiga rekomendasi optimasi jika basis data berkembang hingga ratusan ribu data (Sorting + Binary Search O(log n), Hash Table O(1), dan Trie / Prefix Tree).
Jelaskan dengan bahasa Indonesia yang runut, akademis, dan profesional.
```

Setelah AI memberikan jawaban, silakan baca, pahami, dan tempelkan hasilnya pada lembar jawaban di bawah ini!

---

## ✍️ LEMBAR JAWABAN ANDA


### 1. Analisis Kompleksitas Waktu Towers of Hanoi (Soal 1C)

*Jawab dan lengkapi analisis penurunan matematis berikut:*

1. **Bagaimana bentuk persamaan rekurensi untuk memindahkan $n$ cakram?**  
   *(Petunjuk: Setiap pemindahan $n$ cakram membutuhkan 2 kali pemanggilan rekursif berukuran $(n - 1)$ ditambah 1 langkah pemindahan cakram terbesar)*  
   > $$T(n) = \dots \quad \text{dengan kondisi dasar } T(1) = 1$$

2. **Penurunan Menggunakan Metode Substitusi Berulang (Repeated Substitution):**  
   *(Tuliskan langkah-langkah ekspansi dari $T(n)$ menuju kondisi dasar $T(1)$):*  
   > $$\begin{aligned}
   > T(n) &= 2T(n-1) + 1 \\
   > &= 2(2T(n-2) + 1) + 1 = \dots \\
   > &\dots \\
   > &= \dots
   > \end{aligned}$$

3. **Kesimpulan Notasi Big-O:**  
   - Kompleksitas Waktu asimptotik Towers of Hanoi: $\mathcal{O}(\dots)$  
   - Kompleksitas Ruang (*Space Complexity* / kedalaman call stack): $\mathcal{O}(\dots)$

---

### 2. Analisis Perbandingan Waktu Pencarian Linear Search (Soal 3C - Bagian 1)

Pada algoritma Linear Search sekuensial:
- **Best Case:** Elemen ditemukan pada indeks pertama (1 kali perbandingan).
- **Worst Case:** Elemen berada pada indeks terakhir atau tidak ditemukan ($n$ kali perbandingan).
- **Average Case:** Rata-rata elemen ditemukan di tengah ($\approx n / 2$ perbandingan).

*Lengkapi tabel perbandingan konseptual berikut:*

| Ukuran Data ($N$) | Best Case | Average Case | Worst Case | Analisis & Kelayakan untuk Kiosk Layar Sentuh Museum |
| :---: | :---: | :---: | :---: | :---|
| **$N = 10$ Data** | 1 perbandingan | [Isi...] | [Isi...] | [Tuliskan evaluasi responsivitas...] |
| **$N = 100$ Data** | 1 perbandingan | [Isi...] | [Isi...] | [Tuliskan evaluasi responsivitas...] |
| **$N = 1.000$ Data** | 1 perbandingan | [Isi...] | [Isi...] | [Tuliskan evaluasi responsivitas...] |
| **$N \ge 100.000$ Data** | 1 perbandingan | [Isi...] | [Isi...] | [Tuliskan evaluasi responsivitas...] |

---

### 3. Rekomendasi Solusi Jika Data Semakin Besar (Soal 3C - Bagian 2)

Jika data pengunjung museum berkembang menjadi ratusan ribu atau jutaan baris, algoritma Linear Search menjadi tidak efisien.  
*Jelaskan minimal 2 atau 3 rekomendasi optimasi berikut dengan bahasa Anda sendiri:*

1. **Rekomendasi 1: Sorting + Binary Search ($\mathcal{O}(\log n)$)**  
   > *Penjelasan Anda:*  
   > [Jelaskan cara kerja dan efisiensi perbandingannya dibandingkan linear search...]

2. **Rekomendasi 2: Hash Table / Hash Map ($\mathcal{O}(1)$ Rata-rata)**  
   > *Penjelasan Anda:*  
   > [Jelaskan keunggulan pencarian waktu konstan dengan fungsi hash...]

3. **Rekomendasi 3: Struktur Data Trie (Prefix Tree) atau Database Index**  
   > *Penjelasan Anda:*  
   > [Jelaskan mengapa cocok untuk fitur auto-complete pada layar sentuh museum...]

---

## ✅ Checklist Sebelum Mengumpulkan ke PIC
- [ ] Penurunan matematis rumus $O(2^n)$ sudah ditulis.
- [ ] Tabel perbandingan 10, 100, dan 1.000 data terisi lengkap.
- [ ] Rekomendasi optimasi skala besar sudah dijelaskan.
- [ ] Laporkan ke PIC (Chandra) via grup WhatsApp.
