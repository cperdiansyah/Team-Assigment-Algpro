# 🤖 DOKUMENTASI HAICOLA — TUGAS 2C (HADIAH BELANJA & DISKON)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** ACCA - LAB  
**Kelompok:** Group 1  
**Topik Evaluasi:** Validasi Logika Pembulatan Kupon Undian (*Floor Division*) & Diskon Belanja 5% (Tugas 2C)  

---

> 📌 **Catatan untuk Rekan Tim:**  
> Berkas ini berisi dokumentasi lengkap sesi **HAICOLA (Human-AI Collaboration)** untuk modul **Tugas 2C**. Kalian tinggal menyalin (*copy-paste*) isi di bawah ini ke lembar jawaban Word Online di bagian **Soal 2D HAICOLA**.

---

### 1. ⚠️ Potongan Kode Sebelum Konsultasi AI (Mengandung Potensi Bug)

Pada penulisan awal logika perhitungan kupon dan diskon di `tugas2c.c`, kode ditulis sederhana tanpa validasi batas input dan pembulatan yang rentan:

```c
// ========================================================
// KODE SEBELUM KONSULTASI AI (Tugas 2C - Hadiah & Diskon)
// ========================================================
float total_belanja;
float kupon;
float diskon;
float total_bayar;

printf("Input total belanja: ");
scanf("%f", &total_belanja);

// Menghitung kupon dan diskon secara langsung
kupon = total_belanja / 100000;
diskon = total_belanja * 0.05;
total_bayar = total_belanja - diskon;

printf("Jumlah kupon: %.1f lembar\n", kupon);
printf("Diskon: Rp %.2f\n", diskon);
printf("Total dibayar: Rp %.2f\n", total_bayar);
```

#### Masalah / Gejala Bug pada Kode Awal:
1. **Kupon Berbentuk Pecahan Desimal:** Penggunaan tipe data `float` menghasilkan output kupon berupa pecahan desimal (misal: belanja Rp 250.000 menghasilkan `2.5 lembar`), padahal kupon fisik harus bilangan bulat utuh yang dibulatkan ke bawah (*floor* $\rightarrow$ 2 lembar).
2. **Diskon Tetap Diberikan Walau Belanja di Bawah Rp 100.000:** Diskon langsung dikalikan $5\%$ tanpa mengecek syarat minimum belanja ($\ge$ Rp 100.000). Jika belanja hanya Rp 50.000, diskon tetap terpotong Rp 2.500.
3. **Tidak Ada Validasi Input Negatif:** Jika kasir salah mengetik angka negatif (misal `-100000`), program tetap berjalan dan menghasilkan kupon negatif.

---

### 2. 💬 Prompt / Pertanyaan yang Diajukan ke AI Assistant

```text
"Halo, saya sedang mengerjakan Tugas di bahasa C untuk menghitung kupon undian dan diskon belanja supermarket. Ketentuan studi kasus adalah:
1. Kupon undian diberikan 1 lembar per kelipatan Rp 100.000,00 dengan pembulatan ke bawah (floor).
2. Diskon 5% hanya diberikan jika total pembelian minimal Rp 100.000,00.

Ini potongan kode saya:
kupon = total_belanja / 100000;
diskon = total_belanja * 0.05;

Mengapa kupon saya menghasilkan nilai pecahan desimal, dan bagaimana perbaikan ekspresi perhitungannya di bahasa C agar pembagian kupon selalu membulat ke bawah secara konsisten tanpa library tambahan? Serta bagaimana penanganan syarat diskon 5% dan validasi jika ada input bernilai negatif?"
```

---

### 3. 🧠 Jawaban dan Evaluasi dari AI Code Assistant

> **Evaluasi AI:**
> 1. **Perilaku Integer Division di C (Pengganti `floor()`):**  
>    Jika menggunakan tipe `float`, operator `/` akan menghasilkan pembagian riil desimal (`250000.0 / 100000.0 = 2.5`). Namun di bahasa C, jika kedua operan bertipe integer (`int / int`), pembagian otomatis melakukan **pemotongan desimal ke arah nol (*truncation towards zero*)**. Untuk semua angka positif, ini identik dengan pembulatan ke bawah (*floor*). Cukup deklarasikan variabel sebagai `int`, maka `250000 / 100000` otomatis menghasilkan `2`.
>
> 2. **Penerapan Syarat Percabangan (`if-else`):**  
>    Diskon 5% tidak boleh langsung dihitung tanpa syarat. Harus dibungkus dengan kontrol seleksi: `if (total_pembelian >= 100000)` agar pembeli dengan transaksi di bawah Rp 100.000 mendapatkan diskon `0`.
>
> 3. **Validasi Input Non-Negatif:**  
>    Tambahkan pemeriksaan `if (scanf("%d", &total_pembelian) != 1 || total_pembelian < 0)` di awal untuk mencegah angka negatif merusak perhitungan kupon.

---

### 4. ✅ Perubahan Nyata pada Kode Setelah Konsultasi AI (Hasil Perbaikan)

Berikut adalah kode yang telah disempurnakan dan diterapkan ke berkas `ACCA/tugas2c.c`:

```c
// ========================================================
// KODE SESUDAH KONSULTASI AI (Telah Diperbaiki & Sesuai)
// ========================================================
#include <stdio.h>

int main(void) {
    // 1. Menggunakan integer untuk menjamin bilangan bulat murni
    int total_pembelian = 0;
    int jumlah_kupon = 0;
    int diskon = 0;
    int total_dibayar = 0;

    printf("Input total belanja: ");
    
    // 2. Validasi input: Menolak input non-angka dan angka negatif
    if (scanf("%d", &total_pembelian) != 1 || total_pembelian < 0) {
        printf("Input tidak valid! Harap masukkan nominal angka positif.\n");
        return 1;
    }

    // 3. Integer division otomatis melakukan pembulatan ke bawah (floor)
    jumlah_kupon = total_pembelian / 100000;

    // 4. Seleksi if-else: Diskon 5% hanya jika belanja >= 100.000
    if (total_pembelian >= 100000) {
        diskon = (int)(total_pembelian * 0.05);
    } else {
        diskon = 0;
    }

    // 5. Hitung total yang harus dibayar
    total_dibayar = total_pembelian - diskon;

    // 6. Cetak struk belanja rapi
    printf("\nOutput:\n");
    printf("Total pembelian     : Rp %d\n", total_pembelian);
    printf("Jumlah kupon undian : %d lembar\n", jumlah_kupon);
    printf("Diskon              : Rp %d\n", diskon);
    printf("Total dibayar       : Rp %d\n", total_dibayar);

    return 0;
}
```

#### Ringkasan Perbaikan yang Diterapkan:
* `+` Mengubah tipe data dari `float` ke `int` sehingga ekspresi `total_pembelian / 100000` otomatis menghasilkan pembulatan ke bawah (*floor*) tanpa perlu memanggil library `<math.h>`.
* `+` Menambahkan struktur kontrol `if (total_pembelian >= 100000)` agar diskon 5% tidak diberikan pada pembelian di bawah Rp 100.000.
* `+` Menambahkan validasi `total_pembelian < 0` agar program menolak input negatif yang tidak realistis.

---

### 5. 📝 Refleksi Singkat (4 Kalimat)

> Melalui konsultasi bersama AI Code Assistant, kami memahami bahwa operasi pembagian integer (`int / int`) pada bahasa C secara alami melakukan pemotongan desimal (*truncation*) yang berfungsi setara dengan operasi *floor* untuk bilangan positif. Kami juga menyadari pentingnya menambahkan struktur kendali percabangan `if-else` agar aturan minimum belanja Rp 100.000 untuk memperoleh diskon 5% terpenuhi dengan benar. Sebagai perbaikan konkret pada `tugas2c.c`, kami mengganti tipe variabel menjadi integer murni serta menambahkan validasi input untuk menolak nominal belanja negatif. Penggunaan AI ini sangat membantu kami menguji ketahanan logika program (*edge case validation*) tanpa mengambil alih proses penulisan kode mandiri.
