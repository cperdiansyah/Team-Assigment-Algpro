# 📝 LEMBAR KERJA SLOT 3: SOAL 2C & DAFTAR REFERENSI
**Nama Anggota:** [Tulis Nama Lengkap Anda di sini]  
**NIM:** [Tulis NIM Anda di sini]  
**Modul:** Soal 2C (Flowchart Rekursif Faktorial) & Bagian Tambahan Wajib (Daftar Referensi)  
**Bobot Bagian:** 15% dari total nilai tugas  

---

## 🎯 Instruksi Pengerjaan (Berdasarkan Soal Resmi Binus)
> *"Gambarkan flowchart yang menunjukkan fungsi rekursif yang benar untuk menghitung faktorial.*  
> *Pastikan untuk mencantumkan referensi jika menggunakan sumber dari internet atau bantuan GPT.*  
> *Format wajib referensi: `Nama sumber, Tautan (jika ada), diakses pada [Tanggal Akses]`"*

---

## 🤖 Cheat Sheet Prompt AI (Tinggal Salin ke ChatGPT / Claude / Gemini)

> 💡 **Cara Cepat & Praktis:**  
> Salin (*copy-paste*) prompt di bawah ini ke AI (ChatGPT, Claude, atau Gemini) untuk mendapatkan diagram Mermaid dan daftar referensi baku yang siap pakai:

```text
Bertindaklah sebagai asisten mata kuliah Algorithm and Programming (COMP6112036) BINUS University.
Tolong buatkan:
1. Diagram alur (Flowchart) menggunakan sintaks Mermaid (flowchart TD) untuk fungsi rekursif faktorial yang sudah diperbaiki (FactorialSafe(n)). Diagram harus mencakup:
   - Simbol Terminator Start
   - Percabangan validasi input negatif (n < 0 -> return -1)
   - Percabangan base case (n == 0 atau n == 1 -> return 1)
   - Langkah rekursif (panggil FactorialSafe(n - 1) lalu kalikan n -> return hasil)
   - Simbol Terminator End
2. Buatkan 4 referensi buku teks resmi dan modul Binus terkait topik Rekursi dan Algoritma dalam format wajib:
   Nama sumber, Tautan (jika ada), diakses pada 23 Oktober 2026.
Pastikan sintaks Mermaid valid dan rapi.
```

Setelah AI memberikan jawaban, silakan tempelkan kodenya pada lembar jawaban di bawah ini!

---

## ✍️ LEMBAR JAWABAN ANDA


### 1. Diagram Alir (Flowchart) Faktorial Rekursif yang Benar (Soal 2C)

*Anda dapat menggambar flowchart menggunakan salah satu dari dua cara berikut:*

#### Pilihan A: Menggambar dengan Tools (draw.io / Canva / Visio)
1. Buka [draw.io](https://app.diagrams.net/) atau software diagram lainnya.
2. Gambarkan alur fungsi faktorial yang mencakup:
   - Simbol Terminator: Mulai (*Start: FactorialSafe(n)*).
   - Simbol Decision: Cek apakah input negatif ($n < 0$).
   - Simbol Decision: Cek kondisi dasar (*Base Case: apakah $n == 0$ atau $n == 1$*).
   - Simbol Process: Langkah rekursif ($n \times \text{FactorialSafe}(n - 1)$).
   - Simbol Terminator: Nilai kembali (*Return*).
3. Ekspor ke format gambar `.png` / `.jpg`, simpan di folder `docs/` (misal: `docs/flowchart_faktorial.png`), dan tautkan di bawah ini:
   > `![Flowchart Faktorial](../docs/flowchart_faktorial.png)`

#### Pilihan B: Menggunakan Sintaks Diagram Mermaid
*Lengkapi sintaks Mermaid di bawah ini:*

```mermaid
flowchart TD
    Start([MULAI: FactorialSafe n]) --> CekNegatif{Apakah n < 0 ?}
    
    CekNegatif -- Ya --> OutputError[Tampilkan Pesan Galat]
    OutputError --> ReturnError([RETURN -1])
    
    CekNegatif -- Tidak --> CekBase{Apakah n == 0 atau n == 1 ?}
    
    CekBase -- Ya --> ReturnOne([RETURN 1])
    
    CekBase -- Tidak --> CallSub[// TODO: Lengkapi langkah pemanggilan rekursif n - 1]
    CallSub --> CalcMult[// TODO: Lengkapi operasi perkalian n * hasil rekursi]
    CalcMult --> ReturnResult([RETURN Hasil Akhir])
```

---

### 2. Bagian Tambahan Wajib: Daftar Referensi

*Format Wajib Dosen:*  
$$\text{Nama sumber, Tautan (jika ada), diakses pada [Tanggal Akses]}$$

*Tuliskan minimal 3-5 sumber referensi akademik/buku/situs terpercaya yang digunakan kelompok kita:*

1. [Tuliskan Referensi 1 di sini...]
2. [Tuliskan Referensi 2 di sini...]
3. [Tuliskan Referensi 3 di sini...]
4. [Tuliskan Referensi 4 di sini...]

*(Contoh format baku: `Deitel, P. J., & Deitel, H. M., C How to Program: With an Introduction to C++ (8th Edition), Pearson Education, diakses pada 23 Oktober 2026.`)*

---

## ✅ Checklist Sebelum Mengumpulkan ke PIC
- [ ] Diagram alur memuat percabangan input negatif, base case, dan pemanggilan rekursif.
- [ ] Format seluruh referensi sudah 100% mengikuti aturan: `Nama sumber, Tautan (jika ada), diakses pada [Tanggal Akses]`.
- [ ] Laporkan ke PIC (Chandra) via grup WhatsApp.
