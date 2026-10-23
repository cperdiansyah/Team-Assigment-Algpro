# 🤖 DOKUMENTASI HAICOLA — SOAL 1 DCCA 3 (DESAIN & ANALISIS REKURSIF TOWERS OF HANOI)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** DCCA - LEC  
**Kelompok:** Group 1  
**Topik Evaluasi:** Desain Fungsi Rekursif, Paradigma *Divide and Conquer*, Pembuktian Kondisi Dasar (*Base Case* $n=1$), Simulasi Fisik 15 Langkah (4 Cakram), Penurunan Persamaan Rekurensi Waktu $T(n) = 2T(n-1) + 1 \implies \mathcal{O}(2^n)$, dan Kompleksitas Ruang Call Stack $\mathcal{O}(n)$.  

---

> 📌 **Catatan untuk Rekan Tim:**  
> Berkas ini berisi dokumentasi sesi **HAICOLA (Human-AI Collaboration)** untuk **Soal 1 (Towers of Hanoi)**. Dokumen ini dapat kalian jadikan referensi utama dalam memahami logika rekursi, cara penurunan matematis Big-O, serta lampiran resmi untuk pengisian formulir `AI_Usage_Declaration_Form_EN.docx`.

---

### 1. ⚠️ Rancangan & Pemahaman Awal Sebelum Konsultasi AI (Permasalahan Konseptual)

Pada perancangan awal simulasi visual Towers of Hanoi untuk anjungan museum (*kiosk*), tim menghadapi beberapa kendala konseptual:
1. **Kebingungan Menentukan Posisi Tiang Pembantu (*Auxiliary Peg*):**  
   Banyak mahasiswa keliru saat menukar tiang parameter. Pada pemanggilan rekursif pertama, tiang tujuan akhir (`C`) harus dijadikan tiang pembantu, sedangkan pada pemanggilan rekursif kedua, tiang asal (`A`) yang menjadi tiang pembantu.
2. **Ketidakjelasan Pembuktian Matematis Kompleksitas Waktu:**  
   Mengetahui rumus langkah $2^n - 1$ dari hafalan tanpa memahami cara menurunkan persamaan rekurensi secara formal menggunakan metode ekspansi berulang (*repeated substitution*).
3. **Simulasi Rantai 15 Langkah:**  
   Kesulitan memetakan urutan perpindahan fisik cakram secara manual tanpa terjadi pelanggaran aturan dasar (cakram besar tidak boleh menimpa cakram kecil).

---

### 2. 💬 Prompt / Pertanyaan yang Diajukan ke AI Assistant

```text
"Halo, kelompok kami sedang merancang modul simulasi visual edukasi interaktif untuk Museum Sains dan Matematika Indonesia menggunakan bahasa C (Tugas Kelompok 3 Week 9 - Algorithm and Programming BINUS).

Teka-teki yang harus kami selesaikan adalah Towers of Hanoi dengan 4 cakram yang harus dipindahkan dari Tiang A (Source) ke Tiang C (Destination) menggunakan Tiang B (Auxiliary) sebagai tiang bantuan sementara.

Pertanyaan dan bantuan yang kami butuhkan:
1. Bagaimana merancang fungsi rekursif yang elegan dan benar dalam bahasa C sesuai paradigma Divide and Conquer?
2. Bagaimana penjelasan detail mengenai kondisi dasar (base case saat n = 1) dan cara pemecahan sub-masalah berukuran (n - 1)?
3. Bisakah Anda memberikan daftar sekuensial lengkap 15 langkah perpindahan cakram untuk n = 4 agar kami dapat memverifikasi visualisasi langkah demi langkahnya di layar sentuh museum?
4. Bagaimana pembuktian matematis penurunan persamaan rekurensi waktu T(n) = 2T(n-1) + 1 dengan metode substitusi berulang hingga menghasilkan O(2^n), serta jelaskan kompleksitas ruangnya?"
```

---

### 3. 🧠 Jawaban dan Evaluasi Teknis dari AI Code Assistant

> **Evaluasi & Rekomendasi Solusi AI:**
> 
> 1. **Pola Dekomposisi *Divide and Conquer* Tiga Fase:**  
>    Towers of Hanoi diselesaikan dengan 3 fase berulang:
>    - **Fase 1 (Sub-masalah A):** Pindahkan $(n - 1)$ cakram dari tiang `Source` ke tiang `Auxiliary` (menggunakan tiang `Destination` sebagai perantara).
>    - **Fase 2 (Langkah Utama):** Pindahkan cakram terbesar ke-$n$ langsung dari `Source` ke `Destination`.
>    - **Fase 3 (Sub-masalah B):** Pindahkan kembali $(n - 1)$ cakram dari `Auxiliary` ke `Destination` (menggunakan `Source` sebagai perantara).
> 
> 2. **Peran Vital *Base Case* ($n = 1$):**  
>    Saat $n = 1$, cakram tidak memiliki beban di atasnya sehingga langsung dipindahkan ke tiang tujuan tanpa percabangan. Ini adalah titik terminasi yang mencegah rekursi tanpa henti.
> 
> 3. **Penurunan Matematis Persamaan Rekurensi:**  
>    Persamaan: $T(n) = 2T(n-1) + 1, \quad T(1) = 1$  
>    $$\begin{aligned}
>    T(n) &= 2(2T(n-2) + 1) + 1 = 2^2 T(n-2) + 2 + 1 \\
>    &= 2^3 T(n-3) + 2^2 + 2 + 1 \\
>    &= 2^{n-1} T(1) + \sum_{i=0}^{n-2} 2^i = 2^{n-1}(1) + (2^{n-1} - 1) = 2^n - 1
>    \end{aligned}$$
>    Sehingga kompleksitas waktu adalah $\mathcal{O}(2^n)$ (Eksponensial).  
>    Kompleksitas ruang adalah $\mathcal{O}(n)$ karena tumpukan memori (*call stack*) hanya bertumbuh sedalam $n$ frame secara bersamaan.

---

### 4. 🚀 Desain Solusi & Rincian 15 Langkah Hasil Validasi AI

#### A. Tabel Rincian 15 Langkah Perpindahan Fisik (4 Cakram)

| No. Langkah | Cakram | Dari Tiang | Ke Tiang | Catatan Logika Perpindahan |
| :---: | :---: | :---: | :---: | :---|
| **1** | Cakram 1 | **A** | **B** | Membuka jalan untuk Cakram 2 |
| **2** | Cakram 2 | **A** | **C** | Menaruh cakram 2 di tiang tujuan |
| **3** | Cakram 1 | **B** | **C** | Cakram 1 menumpuk di atas Cakram 2 di C |
| **4** | Cakram 3 | **A** | **B** | Memindahkan cakram 3 ke tiang bantuan B |
| **5** | Cakram 1 | **C** | **A** | Mengembalikan cakram 1 ke tiang transit A |
| **6** | Cakram 2 | **C** | **B** | Menumpuk cakram 2 di atas Cakram 3 di B |
| **7** | Cakram 1 | **A** | **B** | Menumpuk cakram 1 di atas Cakram 2 di B (3 cakram ada di B) |
| **8** | **Cakram 4** | **A** | **C** | **Puncak Transisi:** Cakram terbesar berhasil menempati dasar Tiang C! |
| **9** | Cakram 1 | **B** | **C** | Menaruh cakram 1 di atas cakram 4 di C |
| **10** | Cakram 2 | **B** | **A** | Menyiapkan cakram 2 di tiang transit A |
| **11** | Cakram 1 | **C** | **A** | Menumpuk cakram 1 di atas cakram 2 di A |
| **12** | Cakram 3 | **B** | **C** | Menumpuk cakram 3 di atas cakram 4 di C |
| **13** | Cakram 1 | **A** | **B** | Menyingkirkan sementara cakram 1 ke tiang B |
| **14** | Cakram 2 | **A** | **C** | Menumpuk cakram 2 di atas cakram 3 di C |
| **15** | Cakram 1 | **B** | **C** | Selesai! Semua 4 cakram tersusun sempurna di Tiang C. |

#### B. Pseudo Code Terstandar ISO
```text
ALGORITHM SolveHanoi(n, sourceRod, destinationRod, auxiliaryRod)
BEGIN
    IF n == 1 THEN
        PRINT "Pindahkan Cakram 1 dari Tiang " + sourceRod + " ke Tiang " + destinationRod
        RETURN
    ENDIF

    CALL SolveHanoi(n - 1, sourceRod, auxiliaryRod, destinationRod)
    PRINT "Pindahkan Cakram " + n + " dari Tiang " + sourceRod + " ke Tiang " + destinationRod
    CALL SolveHanoi(n - 1, auxiliaryRod, destinationRod, sourceRod)
END
```

---

### 5. 🎓 Dampak Pembelajaran & Manfaat Kolaborasi Manusia-AI

1. **Pemahaman Mendalam tentang *Parameter Swapping*:**  
   Mahasiswa memahami bahwa pergantian posisi parameter `(source, auxiliary, destination)` pada pemanggilan rekursif adalah inti dari strategi delegasi tugas pada teka-teki Hanoi.
2. **Keterampilan Pembuktian Matematis:**  
   Mahasiswa mampu menjelaskan bahwa sifat eksponensial $O(2^n)$ terjadi karena setiap pertambahan 1 cakram melipatgandakan jumlah pekerjaan komputasi ($2 \times T(n-1) + 1$).
3. **Pengalaman Praktis Antarmuka Museum:**  
   Visualisasi langkah demi langkah yang tervalidasi memudahkan tim merancang antarmuka layar sentuh yang tidak membingungkan pengunjung siswa sekolah menengah.
