# Soal 4 - Debugging
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** ACCA - LAB  
**Kelompok:** Group 1  
**Topik:** Validasi Logika Pembulatan Kupon, Percabangan Diskon 5%, dan Format Cetak Rupiah (Tugas 2C)

---

### 1. Potongan Kode Sebelum Konsultasi AI (Mengandung Potensi Bug)

Pada penulisan awal logika perhitungan kupon dan diskon belanja di `tugas2c.c`, kode ditulis dengan variabel bertipe desimal, perhitungan diskon tanpa pengujian syarat batas belanja, serta pencetakan angka mentah:

```c
// Kode awal sebelum perbaikan
float total_belanja;
float kupon;
float diskon;
float total_bayar;

printf("Input total belanja: ");
scanf("%f", &total_belanja);

// Masalah 1: Kupon menghasilkan nilai desimal (misal 2.5 lembar)
kupon = total_belanja / 100000;

// Masalah 2: Diskon langsung dihitung tanpa validasi minimum belanja Rp 100.000
diskon = total_belanja * 0.05;

total_bayar = total_belanja - diskon;

// Masalah 3: Format output belum sesuai standar Rupiah bertitik
printf("\nOutput:\n");
printf("Total pembelian     : Rp %.0f\n", total_belanja);
printf("Jumlah kupon undian : %.1f lembar\n", kupon);
printf("Diskon              : Rp %.0f\n", diskon);
printf("Total dibayar       : Rp %.0f\n", total_bayar);
```

#### Masalah / Gejala pada Kode Awal:
1. **Kupon Pecahan Desimal:** Pembagian tipe `float` menghasilkan kupon berupa pecahan desimal (misal belanja Rp 250.000 menghasilkan `2.5 lembar`), padahal kupon fisik wajib bilangan bulat yang dibulatkan ke bawah (*floor* $\rightarrow$ 2 lembar).
2. **Diskon Tanpa Syarat Batas Minimal:** Diskon 5% langsung diberikan meskipun total belanja di bawah Rp 100.000 (misal belanja Rp 50.000 tetap terpotong diskon Rp 2.500).
3. **Format Angka Rupiah:** Output nominal belum memiliki tanda titik pemisah ribuan (`Rp250.000`, `Rp12.500`, `Rp237.500`) sesuai contoh tampilan studi kasus.

---

### 2. Prompt / Pertanyaan ke AI Assistant

```text
"Halo, saya sedang membuat program C untuk Tugas 2C (perhitungan kupon undian dan diskon belanja supermarket). Ketentuan soal:
1. Kupon undian diberikan 1 lembar per kelipatan Rp 100.000,00 dengan pembulatan ke bawah (floor).
2. Diskon 5% hanya diberikan jika total belanja minimal Rp 100.000,00.

Pada kode saya saat ini, kupon undian menghasilkan pecahan desimal (2.5 lembar) dan diskon tetap terpotong walau belanja di bawah Rp 100.000. 
Bagaimana cara memperbaiki logika pembagian di bahasa C agar otomatis membulat ke bawah tanpa pecahan, bagaimana menerapkan seleksi kondisi diskon yang tepat, dan bagaimana cara memformat cetak Rupiah dengan pemisah titik (misal Rp250.000) agar persis seperti contoh tampilan soal?"
```

---

### 3. Jawaban dan Evaluasi dari AI Code Assistant

> **Evaluasi AI:**
> 1. **Perilaku Integer Division di C (Otomatis *Floor*):**  
>    Gantilah tipe data `total_pembelian` dan `jumlah_kupon` menjadi `int`. Di bahasa C, operasi pembagian bilangan bulat (`int / int`) secara otomatis melakukan pemotongan angka di belakang koma (*truncation towards zero*). Untuk semua nilai positif, operasi ini bekerja identik dengan fungsi pembulatan ke bawah (*floor*), sehingga `250000 / 100000` otomatis menghasilkan `2` lembar tanpa memerlukan library eksternal `<math.h>`.
> 
> 2. **Penerapan Struktur Seleksi `if-else` untuk Diskon:**  
>    Perhitungan diskon wajib dibungkus dalam blok percabangan `if (total_pembelian >= 100000)`. Jika kondisi terpenuhi, diskon dihitung 5% dari total belanja awal. Jika tidak terpenuhi, diskon diset bernilai `0`. Disarankan menggunakan rumus aritmatika integer `(total_pembelian * 5) / 100` agar perhitungan bebas dari galat presisi *floating-point*.
> 
> 3. **Validasi Input Non-Negatif:**  
>    Tambahkan evaluasi `if (scanf("%d", &total_pembelian) != 1 || total_pembelian < 0)` untuk menolak angka negatif atau input yang bukan angka.
> 
> 4. **Fungsi Pemformatan Rupiah Bertitik (`cetak_rupiah`):**  
>    Buat fungsi helper ringkas yang mengonversi integer ke string via `sprintf`, lalu mencetak prefiks `Rp` dan menyisipkan karakter titik `.` setiap sisa 3 digit dari kanan agar menghasilkan format resmi seperti `Rp250.000`.

---

### 4. Kode Sesudah Konsultasi AI (Hasil Perbaikan Nyata)

Berikut adalah kode yang telah disempurnakan dan diimplementasikan pada berkas `ACCA/tugas2c.c`:

```c
#include <stdio.h>

// Mencetak nominal dengan format Rupiah bertitik, contoh: Rp250.000
void cetak_rupiah(int n) {
    char buf[16];
    int len = sprintf(buf, "%d", n);   // ubah angka jadi teks
    printf("Rp");
    for (int i = 0; i < len; i++) {
        printf("%c", buf[i]);
        int sisa = len - i - 1;        // sisa digit di kanan
        if (sisa > 0 && sisa % 3 == 0) printf(".");
    }
}

int main(void) {
    // Deklarasi variabel menggunakan integer murni
    int total_pembelian = 0;
    int jumlah_kupon = 0;
    int diskon = 0;
    int total_dibayar = 0;

    // 1. Input data total pembelian dengan validasi
    printf("Input total belanja: ");
    if (scanf("%d", &total_pembelian) != 1 || total_pembelian < 0) {
        printf("Input tidak valid! Harap masukkan nominal angka positif.\n");
        return 1;
    }

    // 2. Hitung jumlah kupon undian (pembagian integer otomatis membulatkan ke bawah)
    jumlah_kupon = total_pembelian / 100000;

    // 3. Hitung diskon 5% dengan percabangan (hanya jika belanja >= Rp 100.000)
    if (total_pembelian >= 100000) {
        diskon = (total_pembelian * 5) / 100; // 5% dari total awal via integer math
    } else {
        diskon = 0;
    }

    // 4. Hitung total yang harus dibayar
    total_dibayar = total_pembelian - diskon;

    // 5. Tampilkan rincian output sesuai format studi kasus
    printf("\nOutput:\n");
    printf("Total pembelian     : "); cetak_rupiah(total_pembelian); printf("\n");
    printf("Jumlah kupon undian : %d lembar\n", jumlah_kupon);
    printf("Diskon              : "); cetak_rupiah(diskon); printf("\n");
    printf("Total dibayar       : "); cetak_rupiah(total_dibayar); printf("\n");

    return 0;
}
```

---

### 5. Refleksi Singkat

> Melalui interaksi dengan AI Code Assistant, saya memahami bahwa operasi pembagian integer (`int / int`) pada bahasa C secara alami memotong angka desimal (*truncation*) yang berfungsi setara dengan pembulatan ke bawah (*floor*) untuk bilangan positif. Saya juga belajar pentingnya menerapkan struktur kendali `if-else` untuk menjamin syarat minimal transaksi Rp 100.000 terpenuhi sebelum mendiskon belanja, serta menggunakan aritmatika integer murni `(total * 5 / 100)` guna menghindari galat konversi *floating-point*. Sebagai perbaikan konkret pada `tugas2c.c`, saya mengganti tipe variabel menjadi integer, menambahkan validasi batas minimal belanja, serta membuat fungsi `cetak_rupiah()` untuk menyisipkan tanda titik ribuan. Penggunaan AI ini sangat membantu saya mengidentifikasi celah logika program dan menyempurnakan format keluaran agar presisi sesuai rubrik penilaian.
