# 🤖 DOKUMENTASI HAICOLA — TUGAS 2B (TOTAL GAJI BULANAN & LEMBUR)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** ACCA - LAB  
**Kelompok:** Group 1  
**Topik Evaluasi:** Validasi Logika Jam Lembur Non-Negatif, Pemilihan Tarif Lembur Per Golongan, dan Pencegahan *Unused Argument Warning* (Tugas 2B)  

---

> 📌 **Catatan untuk Rekan Tim:**  
> Berkas ini berisi dokumentasi resmi sesi **HAICOLA (Human-AI Collaboration)** untuk modul **Tugas 2B**. Dokumen ini siap digunakan sebagai lampiran pembuktian transparansi AI dan pengisian berkas `AI_Usage_Declaration_Form_EN.docx`.

---

### 1. ⚠️ Potongan Kode Sebelum Konsultasi AI (Mengandung Potensi Bug)

Pada penulisan awal logika perhitungan lembur dan total gaji di `tugas2b.c`, perhitungan dilakukan tanpa memeriksa batasan jam kerja dan terdapat kesalahan format specifier:

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

    // MASALAH 1: Tidak ada validasi angka negatif
    // Jika kasir salah input -5, gaji pokok berkurang drastis

    if (strcmp(golongan, "D1") == 0) {
        gaji_pokok = 3000000; tarif_lembur = 15000;
    } else if (strcmp(golongan, "D2") == 0) {
        gaji_pokok = 2500000; tarif_lembur = 10000;
    } else if (strcmp(golongan, "D3") == 0) {
        gaji_pokok = 2000000; tarif_lembur = 5000;
    } else {
        // MASALAH 2: Format string tidak memiliki %s (compiler warning)
        printf("Golongan tidak valid!\n", golongan);
    }

    total_gaji = gaji_pokok + (jam_lembur * tarif_lembur);
    printf("Total Gaji: Rp %d\n", total_gaji);
    return 0;
}
```

#### Masalah / Gejala Bug pada Kode Awal:
1. **Tidak Ada Validasi Jam Lembur Negatif:** Jika pengguna tidak sengaja memasukkan nilai negatif (misal `-10 jam`), program tetap melanjutkan perhitungan aritmatika dan memotong gaji pokok secara tidak logis.
2. **Compiler Warning pada Format String `printf`:** Pada blok `else`, variabel `golongan` dipassing ke `printf` padahal string formatnya tidak menyertakan specifier `%s`, menghasilkan peringatan *warning: too many arguments for format*.
3. **Eksekusi Tetap Berjalan saat Input Gagal:** Program tetap menghitung total gaji meskipun input golongan salah.

---

### 2. 💬 Prompt / Pertanyaan yang Diajukan ke AI Assistant

```text
"Halo, saya sedang mengerjakan Tugas 2B bahasa C untuk menghitung total gaji bulanan pegawai dengan rumus: Total Gaji = Gaji Pokok + (Jam Lembur * Tarif Lembur), di mana tarif lembur per jam adalah D1: Rp 15.000, D2: Rp 10.000, D3: Rp 5.000.

Bagaimana cara terbaik menambahkan validasi agar program langsung menolak dan menghentikan proses jika pengguna menginput jam lembur bernilai negatif? Serta bagaimana cara merapikan blok seleksi if-else agar tidak menimbulkan compiler warning saat menampilkan pesan error golongan yang tidak valid?"
```

---

### 3. 🧠 Jawaban dan Evaluasi dari AI Code Assistant

> **Evaluasi AI:**
> 1. **Penerapan Defensive Input Validation (`jam_lembur < 0`):**  
>    Jam lembur secara fisik tidak mungkin bernilai negatif. Segera setelah `scanf("%d", &jam_lembur)`, lakukan pengecekan defensif:  
>    `if (jam_lembur < 0) { printf("Error: Jam lembur tidak boleh minus!\n"); return 1; }` untuk mencegah perusakan kalkulasi aritmatika.
> 
> 2. **Perbaikan Format Specifier `printf`:**  
>    Setiap argumen variabel yang diberikan ke `printf` harus memiliki pasangan specifier yang sesuai. Jika ingin mencetak nama golongan yang keliru, gunakan format `%s`:  
>    `printf("Golongan '%s' tidak valid!\n", golongan);` agar bebas dari peringatan kompilasi `-Wall -Wextra`.
> 
> 3. **Penghentian Program Secara Tepat (*Early Exit*):**  
>    Jika golongan tidak terdaftar pada blok `else`, akhiri fungsi dengan `return 1;` agar program tidak mencetak rincian gaji kosong yang membingungkan.

---

### 4. ✅ Perubahan Nyata pada Kode Setelah Konsultasi AI (Hasil Perbaikan)

Berikut adalah kode yang telah disempurnakan dan diterapkan pada berkas `ACCA/tugas2b.c`:

```c
// ========================================================
// KODE SESUDAH KONSULTASI AI (Telah Diperbaiki & Sesuai)
// ========================================================
#include <stdio.h>
#include <string.h>

int main(void) {
    char nip[20] = "";
    char nama[30] = "";
    char alamat[40] = "";
    char no_HP[20] = "";
    char jabatan[20] = "";
    char golongan[5] = "";

    int jam_lembur = 0;
    int gaji_pokok = 0;
    int tarif_lembur = 0;
    int total_gaji = 0;

    printf("SISTEM PENGGAJIAN BULANAN PEGAWAI (TUGAS 2B)\n");

    printf("Masukkan NIP: ");
    scanf(" %19[^\n]", nip);

    printf("Masukkan Nama: ");
    scanf(" %29[^\n]", nama);

    printf("Masukkan Alamat: ");
    scanf(" %39[^\n]", alamat);

    printf("Masukkan No HP: ");
    scanf(" %19[^\n]", no_HP);

    printf("Masukkan Jabatan: ");
    scanf(" %19[^\n]", jabatan);
    
    printf("Masukkan Golongan (D1/D2/D3): ");
    scanf(" %4[^\n]", golongan);

    printf("Masukkan Jumlah Jam Lembur: ");
    scanf("%d", &jam_lembur);

    // 1. Validasi jam lembur non-negatif
    if (jam_lembur < 0) {
        printf("\nError: Jumlah jam lembur tidak boleh kurang dari 0 atau minus.\n");
        return 1;
    }

    // 2. Seleksi golongan dan tarif lembur dengan penanganan error bersih
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

    // 3. Hitung total gaji bulanan
    total_gaji = gaji_pokok + (jam_lembur * tarif_lembur);

    // 4. Tampilkan output penggajian rapi
    printf("\n=== OUTPUT PENGGAJIAN BULANAN ===\n");
    printf("NIP                  = %s\n", nip);
    printf("Golongan             = %s\n", golongan);
    printf("Lembur               = %d jam\n", jam_lembur);
    printf("Total Gaji Bulan Ini = Rp %d\n", total_gaji);

    return 0;
}
```

#### Ringkasan Perbaikan yang Diterapkan:
* `+` Menambahkan validasi guard clause `if (jam_lembur < 0)` untuk menolak nilai negatif yang merusak perhitungan upah.
* `+` Memperbaiki penulisan `printf` pada percabangan `else` dengan menambahkan specifier `%s` yang sesuai.
* `+` Menerapkan *early exit* (`return 1`) saat input salah agar program tidak memproses kalkulasi dengan data tidak valid.

---

### 5. 📝 Refleksi Singkat (4 Kalimat)

> Melalui konsultasi dengan AI Code Assistant, kami mempelajari pentingnya menerapkan validasi input defensif sebelum menjalankan operasi aritmatika, khususnya untuk memblokir angka jam lembur yang bernilai negatif. Kami juga menyadari bahwa setiap pemanggilan fungsi `printf` dengan argumen tambahan harus menyertakan penentu format yang tepat agar kode terbebas dari peringatan kompilasi. Sebagai perbaikan konkret pada `tugas2b.c`, kami menambahkan pengecekan batas jam lembur, menyelaraskan specifier format pada blok error golongan, serta memastikan program berhenti secara aman saat mendeteksi anomali data. Bantuan AI ini secara nyata meningkatkan ketahanan (*robustness*) dan kebersihan kode program yang kami buat.
