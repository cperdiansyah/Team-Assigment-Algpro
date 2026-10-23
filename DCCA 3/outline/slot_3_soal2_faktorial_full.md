# 📝 LEMBAR KERJA SLOT 3: SOAL 2 FULL (ANALISIS KESALAHAN & PERBAIKAN FAKTORIAL)
**Fokus Soal:** Soal 2 (Kalkulator Faktorial Rekursif)  
**Modul:** Soal 2A (Analisis Kesalahan Logika), Soal 2B (Pseudo Code Perbaikan), & Soal 2C (Flowchart Rekursif)  
**Nama Anggota:** [Tulis Nama Lengkap Anda di sini]  
**NIM:** [Tulis NIM Anda di sini]  
**Bobot Bagian:** 30% dari total nilai tugas  

---

## 🎯 Instruksi Pengerjaan (Berdasarkan Soal Resmi Binus)
> *"Pada modul lain, Anda menemukan pseudo code perhitungan faktorial rekursif yang tidak sempurna:*  
> ```text
> Function factorial(n):
>     if n == 0:
>         return 1
>     else:
>         return n * factorial(n)
> ```  
> *1. Identifikasi dan jelaskan kesalahan dalam pseudo code yang diberikan.*  
> *2. Berikan perbaikan yang benar pada pseudo code.*  
> *3. Gambarkan flowchart yang menunjukkan fungsi rekursif yang benar untuk menghitung faktorial."*

---

## 🤖 Cheat Sheet Prompt AI (Tinggal Salin ke ChatGPT / Claude / Gemini)

> 💡 **Cara Cepat & Praktis:**  
> Anda bisa langsung menyalin (*copy-paste*) prompt di bawah ini ke AI (ChatGPT, Claude, atau Gemini) untuk mendapatkan jawaban komplit Soal 2:

```text
Bertindaklah sebagai asisten pengajar mata kuliah Algorithm and Programming (COMP6112036) BINUS University.
Saya diminta menganalisis dan memperbaiki cuplikan pseudo code kalkulator faktorial rekursif yang mengandung bug berikut:

Function factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n)

Tolong buatkan:
1. Analisis mendalam (Root Cause Analysis - RCA):
   - Di mana letak kesalahan utama logika pemanggilan rekursifnya?
   - Mengapa menyebabkan infinite recursion (rekursi tanpa henti)?
   - Apa dampaknya pada memori komputer (call stack overflow / stack frame exhaustion)?
   - Apa kelemahan jika pengguna memasukkan bilangan negatif (n < 0)?
2. Pseudo code perbaikan yang benar (FactorialSafe(n)) dengan kata kunci kapital (BEGIN, END, IF, THEN, ELSE, RETURN) yang menangani guard clause n < 0, base case n == 0 atau n == 1, dan dekremen (n - 1).
3. Diagram alur (Flowchart) menggunakan sintaks Mermaid (flowchart TD) yang mencerminkan alur rekursif yang benar dan kokoh tersebut.
Gunakan bahasa Indonesia yang jelas, formal, dan akademis.
```

Setelah AI memberikan jawaban, silakan baca, pahami, dan tempelkan hasilnya pada lembar jawaban di bawah ini!

---

## ✍️ LEMBAR JAWABAN ANDA

### 1. Identifikasi & Analisis Kesalahan Logika (Soal 2A)

*Jawab pertanyaan pemandu berikut:*

1. **Pada baris mana letak kesalahan utama kode tersebut dan apa yang keliru?**  
   > *Jawaban Anda:*  
   > [Tuliskan analisis Anda di sini...]

2. **Mengapa kesalahan tersebut menyebabkan *Infinite Recursion* (Rekursi Tanpa Henti)?**  
   > *Jawaban Anda:*  
   > [Tuliskan analisis Anda di sini...]

3. **Apa akibat pemanggilan tanpa henti tersebut terhadap memori komputer (*Call Stack Overflow*)?**  
   > *Jawaban Anda:*  
   > [Tuliskan analisis Anda di sini...]

4. **Apakah ada kelemahan lain pada kode asli jika pengguna memasukkan angka negatif ($n < 0$)?**  
   > *Jawaban Anda:*  
   > [Tuliskan analisis Anda di sini...]

---

### 2. Pseudo Code Versi Perbaikan yang Benar (Soal 2B)

*Lengkapi bagian `// TODO` pada pseudo code perbaikan di bawah ini:*

```text
ALGORITHM FactorialSafe(n)
    INPUT:
        n : Bilangan bulat
    OUTPUT:
        Hasil faktorial (n!) atau nilai penanda error jika input tidak valid

BEGIN
    // TODO 1: Validasi Input Negatif (Guard Clause)
    IF [Kondisi n negatif] THEN
        PRINT "Pesan error: Bilangan negatif tidak terdefinisi..."
        RETURN -1
    ENDIF

    // TODO 2: Kondisi Dasar (Base Case)
    IF [Kondisi base case: n == 0 atau n == 1] THEN
        RETURN 1
    ELSE
        // TODO 3: Langkah Rekursif yang Benar
        RETURN [Rumus rekursif dengan parameter n - 1]
    ENDIF
END
```

---

### 3. Diagram Alir (Flowchart) Faktorial Rekursif yang Benar (Soal 2C)

*Sertakan sintaks Mermaid di bawah ini ATAU sematkan tangkapan layar dari draw.io:*

```mermaid
flowchart TD
    Start([MULAI: FactorialSafe n]) --> CekNegatif{Apakah n < 0 ?}
    
    CekNegatif -- Ya --> OutputError[Tampilkan Pesan Galat]
    OutputError --> ReturnError([RETURN -1])
    
    CekNegatif -- Tidak --> CekBase{Apakah n == 0 atau n == 1 ?}
    
    CekBase -- Ya (Kondisi Dasar) --> ReturnOne([RETURN 1])
    
    CekBase -- Tidak (Langkah Rekursif) --> CallSub[// TODO: Panggil FactorialSafe n - 1]
    CallSub --> CalcMult[// TODO: Kalikan n * hasil]
    CalcMult --> ReturnResult([RETURN Hasil Akhir])
```

---

## 📚 Referensi Pendukung
- Buka dokumen studi kasus HAICOLA Soal 2 di [`./haicola/haicola-soal2-factorial.md`](./haicola/haicola-soal2-factorial.md) untuk melihat analisis bug memori stack frame secara lengkap.
