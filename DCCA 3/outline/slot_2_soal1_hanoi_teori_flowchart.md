# 📝 LEMBAR KERJA SLOT 2: SOAL 1C & DIAGRAM (TOWERS OF HANOI — TEORI & VISUAL)
**Fokus Soal:** Soal 1 (Towers of Hanoi 4 Cakram)  
**Modul:** Soal 1C (Analisis Kompleksitas Waktu & Ruang) & Diagram Alir (*Flowchart*) Towers of Hanoi  
**Nama Anggota:** [Tulis Nama Lengkap Anda di sini]  
**NIM:** [Tulis NIM Anda di sini]  
**Bobot Bagian:** 20% dari total nilai tugas  

---

## 🎯 Instruksi Pengerjaan (Berdasarkan Soal Resmi Binus)
> *"Gambarkan flowchart untuk fungsi rekursif Towers of Hanoi.*  
> *Analisis dan sebutkan kompleksitas waktu algoritma berdasarkan jumlah cakram."*

**Tugas Anda:**
1. Gambarkan diagram alur (*flowchart*) rekursif Towers of Hanoi (menggunakan sintaks Mermaid atau ekspor gambar dari draw.io).
2. Tuliskan analisis penurunan matematis persamaan rekurensi $T(n) = 2T(n-1) + 1$ hingga terbukti $\mathcal{O}(2^n)$.
3. Jelaskan kompleksitas ruang (*space complexity*) pada tumpukan memori (*call stack*).

---

## 🤖 Cheat Sheet Prompt AI (Tinggal Salin ke ChatGPT / Claude / Gemini)

> 💡 **Cara Cepat & Praktis:**  
> Anda bisa langsung menyalin (*copy-paste*) prompt di bawah ini ke AI (ChatGPT, Claude, atau Gemini) untuk mendapatkan penurunan rumus matematis dan kode diagram Mermaid yang siap pakai:

```text
Bertindaklah sebagai asisten dosen mata kuliah Algorithm and Programming (COMP6112036) BINUS University.
Saya memiliki tugas untuk menganalisis kompleksitas waktu dan menggambar flowchart fungsi rekursif Towers of Hanoi (n cakram).

Tolong buatkan:
1. Diagram alur (Flowchart) menggunakan sintaks Mermaid (flowchart TD) untuk fungsi SolveHanoi(n, source, dest, aux) yang mencakup:
   - Terminator Start
   - Percabangan Base Case (n == 1)
   - Langkah Rekursif 1: SolveHanoi(n-1, source, aux, dest)
   - Langkah Utama: Cetak pemindahan cakram n dari source ke dest
   - Langkah Rekursif 2: SolveHanoi(n-1, aux, dest, source)
   - Terminator Return
2. Penurunan matematis formal persamaan rekurensi waktu:
   T(n) = 2T(n-1) + 1 dengan kondisi awal T(1) = 1 menggunakan metode substitusi berulang (repeated substitution method) hingga menghasilkan rumus tertutup T(n) = 2^n - 1 dan notasi Big-O: O(2^n).
3. Penjelasan analisis kompleksitas ruang (Space Complexity) O(n) berdasarkan kedalaman call stack rekursi maksimum.
Gunakan bahasa Indonesia yang jelas, formal, dan akademis.
```

Setelah AI memberikan jawaban, silakan baca, pahami, dan tempelkan hasilnya pada lembar jawaban di bawah ini!

---

## ✍️ LEMBAR JAWABAN ANDA

### 1. Diagram Alir (Flowchart) Rekursif Towers of Hanoi

*Anda dapat menyertakan kode Mermaid di bawah ini, ATAU menyisipkan tangkapan layar gambar hasil draw.io:*

```mermaid
flowchart TD
    Start([MULAI: SolveHanoi n, Source, Dest, Aux]) --> CheckBase{Apakah n == 1 ?}
    
    CheckBase -- Ya (Kondisi Dasar) --> MoveBase[// TODO: Tulis aksi pemindahan cakram 1]
    MoveBase --> RetBase([RETURN])
    
    CheckBase -- Tidak (Divide & Conquer) --> Step1[// TODO: Tulis pemanggilan rekursi 1]
    Step1 --> Step2[// TODO: Tulis aksi pemindahan cakram n]
    Step2 --> Step3[// TODO: Tulis pemanggilan rekursi 2]
    Step3 --> RetMain([RETURN])
```

*Jika menggunakan gambar dari draw.io, simpan file gambar di folder `docs/` (misal: `docs/flowchart_hanoi.png`):*  
> `![Flowchart Hanoi](../docs/flowchart_hanoi.png)`

---

### 2. Analisis Kompleksitas Waktu Towers of Hanoi (Soal 1C)

*Jawab dan lengkapi analisis penurunan matematis berikut:*

1. **Bentuk Persamaan Rekurensi:**  
   > $$T(n) = 2T(n-1) + 1, \quad \text{dengan kondisi dasar } T(1) = 1$$

2. **Penurunan Menggunakan Metode Substitusi Berulang (Repeated Substitution):**  
   *(Tuliskan langkah-langkah ekspansi substitusi):*  
   > $$\begin{aligned}
   > T(n) &= 2T(n-1) + 1 \\
   > &= 2(2T(n-2) + 1) + 1 = 2^2 T(n-2) + 2 + 1 \\
   > &= 2^3 T(n-3) + 2^2 + 2^1 + 2^0 \\
   > &\dots \\
   > &= \dots
   > \end{aligned}$$

3. **Kesimpulan Notasi Asimptotik Big-O:**  
   - **Kompleksitas Waktu:** $\mathcal{O}(\dots)$ *(Jelaskan mengapa eksponensial)*
   - **Kompleksitas Ruang (*Space Complexity*):** $\mathcal{O}(\dots)$ *(Jelaskan peran kedalaman call stack)*

---

## 📚 Referensi Pendukung
- Buka dokumen studi kasus HAICOLA Soal 1 di [`./haicola/haicola-soal1-hanoi.md`](./haicola/haicola-soal1-hanoi.md) untuk melihat penurunan matematis lengkap.
- Anda dapat berkoordinasi dengan rekan pemegang **Slot 1** yang sama-sama mengerjakan topik Towers of Hanoi.
