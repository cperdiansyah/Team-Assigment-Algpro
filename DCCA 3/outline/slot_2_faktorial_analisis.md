# 📝 LEMBAR KERJA SLOT 2: SOAL 2A & 2B (ANALISIS KESALAHAN FAKTORIAL)
**Nama Anggota:** [Tulis Nama Lengkap Anda di sini]  
**NIM:** [Tulis NIM Anda di sini]  
**Modul:** Soal 2A (Identifikasi Kesalahan Logika) & Soal 2B (Pseudo Code Perbaikan)  
**Bobot Bagian:** 20% dari total nilai tugas  

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
> *2. Berikan perbaikan yang benar pada pseudo code."*

---

## 🤖 Cheat Sheet Prompt AI (Tinggal Salin ke ChatGPT / Claude / Gemini)

> 💡 **Cara Cepat & Praktis:**  
> Anda bisa langsung menyalin (*copy-paste*) prompt di bawah ini ke AI (ChatGPT, Claude, atau Gemini) untuk mendapatkan draf analisis yang tajam dan akurat:

```text
Bertindaklah sebagai asisten pengajar mata kuliah Algorithm and Programming (COMP6112036) BINUS University.
Saya diminta menganalisis cuplikan pseudo code kalkulator faktorial rekursif yang mengandung bug berikut:

Function factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n)

Tolong jelaskan secara mendalam:
1. Di mana letak kesalahan utama logika pemanggilan rekursifnya?
2. Mengapa hal tersebut menyebabkan infinite recursion (rekursi tanpa henti)?
3. Apa dampaknya pada memori komputer (call stack overflow / stack frame exhaustion)?
4. Berikan pseudo code perbaikan yang benar (menggunakan parameter n - 1, base case 0! = 1 dan 1! = 1, serta penanganan guard clause jika n bernilai negatif). Format pseudo code dengan kata kunci kapital (BEGIN, END, IF, THEN, ELSE, RETURN).
Gunakan bahasa Indonesia yang formal dan akademis.
```

Setelah AI memberikan jawaban, silakan baca, pahami, dan tempelkan hasilnya pada lembar jawaban di bawah ini!

---

## ✍️ LEMBAR JAWABAN ANDA


### 1. Identifikasi & Analisis Kesalahan Logika (Soal 2A)

*Jawab pertanyaan pemandu berikut:*

1. **Pada baris mana letak kesalahan utama kode tersebut dan apa yang keliru?**  
   *(Petunjuk: Perhatikan argumen pemanggilan rekursif pada blok `else`)*  
   > *Jawaban Anda:*  
   > [Tuliskan analisis Anda di sini...]

2. **Mengapa kesalahan tersebut menyebabkan *Infinite Recursion* (Rekursi Tanpa Henti)?**  
   *(Petunjuk: Apakah nilai parameter $n$ bergerak mendekati kondisi dasar $n == 0$?)*  
   > *Jawaban Anda:*  
   > [Tuliskan analisis Anda di sini...]

3. **Apa akibat dari pemanggilan rekursif tanpa henti tersebut terhadap memori komputer (*Call Stack Overflow*)?**  
   *(Petunjuk: Jelaskan apa yang terjadi pada stack frame di memori saat fungsi terus dipanggil)*  
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
    // Dalam matematika, faktorial hanya terdefinisi untuk n >= 0
    IF [Kondisi n negatif] THEN
        PRINT "Pesan error..."
        RETURN -1
    ENDIF

    // TODO 2: Kondisi Dasar (Base Case)
    // Berapa nilai 0! dan 1!?
    IF [Kondisi base case] THEN
        RETURN [Nilai base case]
    ELSE
        // TODO 3: Langkah Rekursif yang Benar
        // Bagaimana argumen pemanggilan rekursif agar bergerak mendekati base case?
        RETURN [Rumus rekursif perbaikan]
    ENDIF
END
```

---

## ✅ Checklist Sebelum Mengumpulkan ke PIC
- [ ] Penjelasan letak kesalahan pemanggilan `factorial(n)` sudah diuraikan.
- [ ] Konsep *infinite recursion* dan ledakan memori stack (*stack overflow*) sudah dijelaskan.
- [ ] Pseudo code perbaikan sudah mencakup kondisi dasar dan langkah dekremen yang benar.
- [ ] Laporkan ke PIC (Chandra) via grup WhatsApp.
