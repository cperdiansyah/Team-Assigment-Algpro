# 🤖 DOKUMENTASI HAICOLA — TUGAS 2C (HADIAH BELANJA & DISKON)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** ACCA - LAB  
**Kelompok:** Group 1  
**Topik Evaluasi:** Validasi Logika Pembulatan Kupon Undian (*Floor Division*), Diskon Belanja 5%, dan Format Mata Uang Rupiah (Tugas 2C)  

---

> 📌 **Catatan untuk Rekan Tim:**  
> Berkas ini berisi dokumentasi lengkap sesi **HAICOLA (Human-AI Collaboration)** untuk modul **Tugas 2C**. Dokumen ini siap disalin ke lembar jawaban Word pada bagian **Soal 2D HAICOLA**.

---

### 1. ⚠️ Potongan Kode Sebelum Konsultasi AI (Mengandung Potensi Bug)

Pada penulisan awal logika perhitungan kupon dan diskon di `tugas2c.c`, kode ditulis sederhana tanpa validasi batas input, pembulatan yang rentan, serta tanpa format Rupiah:

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
4. **Format Cetak Mata Uang Tanpa Titik Pemisah:** Output nilai Rupiah tidak menggunakan pemisah ribuan titik (`Rp 250000` alih-alih `Rp250.000` seperti pada contoh soal `image5.png`).

---

### 2. 💬 Prompt / Pertanyaan yang Diajukan ke AI Assistant

```text
"Halo, saya sedang mengerjakan Tugas 2C di bahasa C untuk menghitung kupon undian dan diskon belanja supermarket. Ketentuan studi kasus adalah:
1. Kupon undian diberikan 1 lembar per kelipatan Rp 100.000,00 dengan pembulatan ke bawah (floor).
2. Diskon 5% hanya diberikan jika total pembelian minimal Rp 100.000,00.

Ini potongan kode saya:
kupon = total_belanja / 100000;
diskon = total_belanja * 0.05;

Mengapa kupon saya menghasilkan nilai pecahan desimal, dan bagaimana perbaikan ekspresi perhitungannya di bahasa C agar pembagian kupon selalu membulat ke bawah secara konsisten tanpa library tambahan? Serta bagaimana penanganan syarat diskon 5%, validasi jika ada input negatif, dan fungsi cetak Rupiah dengan titik pemisah agar persis seperti contoh tampilan struk di soal (image5: Rp250.000, Rp12.500, Rp237.500)?"
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
>
> 4. **Fungsi Sederhana Cetak Rupiah Bertitik (`cetak_rupiah`):**  
>    Gunakan fungsi `cetak_rupiah(int n)` yang mengubah angka ke teks via `sprintf` dan menyisipkan tanda titik setiap kelipatan 3 digit dari kanan sehingga menghasilkan `Rp250.000`, `Rp12.500`, dan `Rp237.500` sesuai dengan tangkapan layar dosen (`image5.png`).

---

### 4. ✅ Perubahan Nyata pada Kode Setelah Konsultasi AI (Hasil Perbaikan)

Berikut adalah kode yang telah disempurnakan dan diterapkan ke berkas `ACCA/tugas2c.c`:

```c
// ========================================================
// KODE SESUDAH KONSULTASI AI (Telah Diperbaiki & Sesuai)
// ========================================================
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
    int total_pembelian = 0;
    int jumlah_kupon = 0;
    int diskon = 0;
    int total_dibayar = 0;

    // 1. Input data total pembelian menggunakan formatted input scanf()
    printf("Input total belanja: ");
    if (scanf("%d", &total_pembelian) != 1 || total_pembelian < 0) {
        printf("Input tidak valid! Harap masukkan nominal angka positif.\n");
        return 1;
    }

    // 2. Hitung jumlah kupon undian
    // Pembagian integer (total_pembelian / 100000) otomatis membulatkan ke bawah (floor)
    jumlah_kupon = total_pembelian / 100000;

    // 3. Hitung diskon 5% menggunakan percabangan if-else (Modul Praktikum 2)
    // Diskon hanya diberikan jika total pembelian minimal Rp 100.000,00
    if (total_pembelian >= 100000) {
        diskon = (int)(total_pembelian * 0.05); // 5% dari total pembelian awal
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

#### Ringkasan Perbaikan yang Diterapkan:
* `+` Mengubah tipe data dari `float` ke `int` sehingga ekspresi `total_pembelian / 100000` otomatis menghasilkan pembulatan ke bawah (*floor*) tanpa perlu memanggil library `<math.h>`.
* `+` Menambahkan struktur kontrol `if (total_pembelian >= 100000)` agar diskon 5% tidak diberikan pada pembelian di bawah Rp 100.000.
* `+` Menambahkan validasi `total_pembelian < 0` agar program menolak input negatif yang tidak realistis.
* `+` Menambahkan fungsi `cetak_rupiah()` untuk mencetak format Rupiah bertitik (`Rp250.000`, `Rp12.500`, `Rp237.500`) persis sesuai contoh keluaran studi kasus (`image5.png`).

---

### 5. 📝 Refleksi Singkat (4 Kalimat)

> Melalui konsultasi bersama AI Code Assistant, kami memahami bahwa operasi pembagian integer (`int / int`) pada bahasa C secara alami melakukan pemotongan desimal (*truncation*) yang berfungsi setara dengan operasi *floor* untuk bilangan positif. Kami juga menyadari pentingnya menambahkan struktur kendali percabangan `if-else` agar aturan minimum belanja Rp 100.000 untuk memperoleh diskon 5% terpenuhi dengan benar. Sebagai perbaikan konkret pada `tugas2c.c`, kami mengganti tipe variabel menjadi integer murni, menambahkan validasi penolakan belanja negatif, serta menerapkan pemformatan Rupiah bertitik via fungsi `cetak_rupiah()`. Penggunaan AI ini sangat membantu kami menguji ketahanan logika program (*edge case validation*) sekaligus memastikan format tampilan output akhir akurat 100%.
