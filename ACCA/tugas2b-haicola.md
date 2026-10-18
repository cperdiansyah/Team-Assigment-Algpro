# 🤖 DOKUMENTASI HAICOLA — TUGAS 2B (TOTAL GAJI BULANAN & LEMBUR)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** ACCA - LAB  
**Kelompok:** Group 1  
**Topik Evaluasi:** Validasi Jam Lembur Non-Negatif/Non-Angka, Portabilitas String Normalisasi (`toupper`), dan Format Mata Uang Rupiah (Tugas 2B)  

---

> 📌 **Catatan untuk Rekan Tim:**  
> Berkas ini berisi dokumentasi resmi sesi **HAICOLA (Human-AI Collaboration)** untuk modul **Tugas 2B**. Dokumen ini siap digunakan sebagai lampiran pembuktian transparansi AI dan pengisian berkas `AI_Usage_Declaration_Form_EN.docx`.

---

### 1. ⚠️ Potongan Kode Sebelum Konsultasi AI (Mengandung Potensi Bug)

Pada penulisan awal logika perhitungan lembur dan total gaji di `tugas2b.c`, perhitungan dilakukan tanpa memeriksa batasan jam kerja dan menggunakan fungsi non-standar yang memicu compiler warning:

```c
// ========================================================
// KODE SEBELUM KONSULTASI AI (Tugas 2B - Lembur Pegawai)
// ========================================================
#include <stdio.h>
#include <string.h>

int main(void) {
    char nip[20];
    char golongan[5];
    int jam_lembur;
    int gaji_pokok = 0;
    int tarif_lembur = 0;
    int total_gaji = 0;

    printf("Masukkan NIP: "); scanf("%s", nip);
    printf("Masukkan Golongan: "); scanf("%s", golongan);
    printf("Masukkan Jam Lembur: "); scanf("%d", &jam_lembur);

    // MASALAH 1: Tidak ada validasi angka negatif atau input non-angka (misal 'abc')
    // Jika kasir salah input -5, gaji pokok berkurang drastis

    // MASALAH 2: Menggunakan strcasecmp() yang tidak standar ANSI C
    // Menimbulkan warning 'implicit declaration of function' di Windows/MSVC
    if (strcasecmp(golongan, "D1") == 0) {
        gaji_pokok = 3000000; tarif_lembur = 15000;
    } else if (strcasecmp(golongan, "D2") == 0) {
        gaji_pokok = 2500000; tarif_lembur = 10000;
    } else if (strcasecmp(golongan, "D3") == 0) {
        gaji_pokok = 2000000; tarif_lembur = 5000;
    } else {
        printf("Golongan tidak valid!\n", golongan);
    }

    total_gaji = gaji_pokok + (jam_lembur * tarif_lembur);
    printf("Total Gaji: Rp %d\n", total_gaji);
    return 0;
}
```

#### Masalah / Gejala Bug pada Kode Awal:
1. **Tidak Ada Validasi Jam Lembur Negatif atau Huruf/String:** Jika pengguna tidak sengaja memasukkan nilai negatif (misal `-5`) atau teks huruf (`abc`), program tetap melanjutkan perhitungan aritmatika atau membaca data sampah memori.
2. **Compiler Warning Fungsi `strcasecmp`:** Fungsi POSIX `strcasecmp` tidak didefinisikan dalam pustaka standar ANSI C `<string.h>` pada Windows/MSVC, menghasilkan peringatan *warning: implicit declaration of function*.
3. **Eksekusi Tetap Berjalan saat Input Gagal:** Program tetap menghitung total gaji meskipun input golongan salah.
4. **Format Cetak Mata Uang Tanpa Pemisah Titik:** Total gaji hanya dicetak angka mentah (`Rp 2550000`), tidak mengikuti format Rupiah standar (`Rp2.550.000`).

---

### 2. 💬 Prompt / Pertanyaan yang Diajukan ke AI Assistant

```text
"Halo, saya sedang mengerjakan Tugas 2B bahasa C untuk menghitung total gaji bulanan pegawai dengan rumus: Total Gaji = Gaji Pokok + (Jam Lembur * Tarif Lembur), di mana tarif lembur per jam adalah D1: Rp 15.000, D2: Rp 10.000, D3: Rp 5.000.

Bagaimana cara terbaik mengganti strcasecmp agar kompatibel dan portabel di semua compiler C (bebas warning di Windows/MSVC)? Serta bagaimana cara memvalidasi scanf agar menolak input negatif maupun non-angka (seperti 'abc'), dan memformat output total gaji ke format Rupiah bertitik sesuai contoh gambar di soal (image4)?"
```

---

### 3. 🧠 Jawaban dan Evaluasi dari AI Code Assistant

> **Evaluasi AI:**
> 1. **Portabilitas Perbandingan String (`toupper` + `strcmp`):**  
>    Alih-alih menggunakan ekstensi POSIX `strcasecmp()`, lakukan konversi huruf besar menggunakan fungsi standar C `toupper()` dari `<ctype.h>` pada setiap karakter string `golongan`. Setelah itu, lakukan perbandingan dengan `strcmp()`. Solusi ini 100% portabel di GCC, Clang, maupun MSVC.
> 
> 2. **Penerapan Defensive Input Validation (`scanf != 1 || jam_lembur < 0`):**  
>    Gunakan evaluasi: `if (scanf("%d", &jam_lembur) != 1 || jam_lembur < 0)` untuk menangkap input non-angka (seperti `abc`) sekaligus menolak angka negatif secara instan.
> 
> 3. **Penghentian Program Secara Tepat (*Early Exit*):**  
>    Jika golongan tidak terdaftar pada blok `else`, akhiri fungsi dengan `return 1;` agar program tidak mencetak rincian gaji kosong yang membingungkan.
> 
> 4. **Fungsi Sederhana Cetak Rupiah Bertitik (`cetak_rupiah`):**  
>    Gunakan fungsi `cetak_rupiah(int n)` yang mengubah angka ke teks via `sprintf` dan menyisipkan tanda titik setiap kelipatan 3 digit dari kanan sehingga menghasilkan `Rp2.550.000` sesuai dengan tangkapan layar dosen (`image4.png`).

---

### 4. ✅ Perubahan Nyata pada Kode Setelah Konsultasi AI (Hasil Perbaikan)

Berikut adalah kode yang telah disempurnakan dan diterapkan pada berkas `ACCA/tugas2b.c`:

```c
// ========================================================
// KODE SESUDAH KONSULTASI AI (Telah Diperbaiki & Sesuai)
// ========================================================
// untuk menghandle fungsi input output seperti scanf dan printf
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Mencetak nominal dengan format Rupiah bertitik, contoh: Rp2.550.000
void cetak_rupiah(int n) {
    char buf[16];
    int len = sprintf(buf, "%d", n);
    printf("Rp");
    for (int i = 0; i < len; i++) {
        printf("%c", buf[i]);
        int sisa = len - i - 1;
        if (sisa > 0 && sisa % 3 == 0) printf(".");
    }
}

int main(void) {
    // menyimpan nip sebesar 19 karena pada tipe variable selalu menyimpan karakter null di akhir
    // ="" digunakan untuk menentukan array tersebut string kosong
    char nip[20] = "";
    char golongan[5] = "";

    // inisialisasi nilai awal dari integer
    int jam_lembur = 0;
    int gaji_pokok = 0;
    int tarif_lembur = 0;
    int total_gaji = 0;

    // input data sesuai spesifikasi soal
    printf("Masukkan NIP                : ");
    scanf(" %19[^\n]", nip);

    printf("Masukkan Golongan (D1/D2/D3): ");
    scanf(" %4s", golongan);

    // normalisasi input golongan ke huruf kapital (misal d2 -> D2) agar portabel di semua compiler
    for (int i = 0; golongan[i] != '\0'; i++) {
        golongan[i] = (char)toupper((unsigned char)golongan[i]);
    }

    printf("Masukkan Jam Lembur         : ");
    // validasi jika input jam lembur kurang dari 0 atau bukan angka
    if (scanf("%d", &jam_lembur) != 1 || jam_lembur < 0) {
        printf("\nError: jam lembur tidak boleh kurang dari 0 atau bukan angka.\n");
        return 1;
    }

    // menggunakan if selection untuk menentukan gaji pokok dan tarif lembur dari inputan user
    if (strcmp(golongan, "D1") == 0) {
        gaji_pokok = 3000000;
        tarif_lembur = 15000;
    } else if (strcmp(golongan, "D2") == 0) {
        gaji_pokok = 2500000;
        tarif_lembur = 10000;
    } else if (strcmp(golongan, "D3") == 0) {
        gaji_pokok = 2000000;
        tarif_lembur = 5000;
    } else {
        printf("\nInputan tidak valid! Golongan '%s' tidak ditemukan (mohon pilih D1/D2/D3).\n", golongan);
        return 1;
    }

    // menghitung total gaji dari gaji pokok yang ditambah tarif lembur perjam dikali jam lembur
    total_gaji = gaji_pokok + (jam_lembur * tarif_lembur);

    // menampilkan output ringkasan penggajian sesuai format soal (image4)
    printf("\nNIP = %s\n", nip);
    printf("Golongan = %s\n", golongan);
    printf("Lembur = %d jam\n", jam_lembur);
    printf("Total Gaji Bulan Ini = "); cetak_rupiah(total_gaji); printf("\n");

    return 0;
}
```

#### Ringkasan Perbaikan yang Diterapkan:
* `+` Mengganti `strcasecmp()` dengan normalisasi `toupper()` dan `strcmp()` standar agar portabel di semua compiler C (bebas warning di Windows/MSVC).
* `+` Menambahkan validasi guard clause `if (scanf("%d", ...) != 1 || jam_lembur < 0)` untuk menolak nilai negatif maupun input bukan angka (`abc`).
* `+` Menerapkan *early exit* (`return 1`) saat input salah agar program tidak memproses kalkulasi dengan data tidak valid.
* `+` Mengintegrasikan fungsi format Rupiah bertitik (`cetak_rupiah`) pada total gaji akhir agar tampilan penggajian bersih dan sesuai format soal (`image4.png`).

---

### 5. 📝 Refleksi Singkat (4 Kalimat)

> Melalui konsultasi dengan AI Code Assistant, kami mempelajari pentingnya menjaga portabilitas kode standar C dengan mengganti fungsi non-standar seperti `strcasecmp` menggunakan kombinasi `toupper()` dan `strcmp()`. Kami juga menyadari bahwa pengecekan nilai kembalian `scanf` sangat vital untuk menangkal input non-angka selain memblokir nilai jam lembur negatif. Sebagai perbaikan konkret pada `tugas2b.c`, kami menerapkan normalisasi huruf besar portabel, memperketat validasi input jam lembur, dan memformat nominal total gaji ke standar Rupiah bertitik via `cetak_rupiah()`. Bantuan AI ini secara nyata meningkatkan ketahanan (*robustness*), portabilitas compiler, dan kepatuhan kode terhadap spesifikasi studi kasus.
