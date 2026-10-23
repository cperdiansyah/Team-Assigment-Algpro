# 🤖 DOKUMENTASI HAICOLA — SOAL 3 DCCA 3 (FILE PROCESSING & SISTEM PENCARIAN SISWA)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** DCCA - LEC  
**Kelompok:** Group 1  
**Topik Evaluasi:** Pemrosesan Berkas Teks (`fopen`, `fscanf`, `fclose`), Pemodelan Struktur Data (`struct`), Algoritma Pencarian Sekuensial (*Linear Search* via `strcmp`), Validasi Galat Data Tidak Ditemukan, Evaluasi Kompleksitas Asimptotik ($N = 10, 100, 1.000$), dan Arsitektur Skalabilitas Tinggi (*Binary Search*, *Hash Map*, *Trie*).  

---

> 📌 **Catatan untuk Rekan Tim:**  
> Berkas ini berisi dokumentasi sesi **HAICOLA (Human-AI Collaboration)** untuk **Soal 3 (Pencarian Data Siswa dari File Teks)**. Dokumen ini dapat kalian jadikan referensi utama dalam memahami cara kerja pemrosesan file teks di C, analisis efisiensi linear search, serta lampiran resmi untuk pengisian formulir `AI_Usage_Declaration_Form_EN.docx`.

---

### 1. ⚠️ Rancangan & Potongan Kode Awal Sebelum Konsultasi AI (Desain Naif & Rawan Bug)

Pada perancangan awal sistem pencarian data siswa dari file `siswa.txt`, terdapat pendekatan naif yang tidak mematuhi kaidah keamanan file I/O:

```c
// ========================================================
// DESAIN AWAL SEBELUM KONSULTASI AI (Rancangan Naif)
// ========================================================
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char cari[50];
    char nama[50];
    int umur;
    char noreg[20];
    
    // MASALAH 1: Langsung membuka file tanpa validasi fp == NULL
    fp = fopen("siswa.txt", "r");
    
    printf("Masukkan nama: ");
    scanf("%s", cari);
    
    // MASALAH 2: Membaca file berulang-ulang dari disk setiap kali mencari (Boros I/O)
    // MASALAH 3: Tidak menggunakan struct (data tercecer sebagai variabel primitif lepas)
    while (fscanf(fp, "%s %d %s", nama, &umur, noreg) != EOF) {
        if (strcmp(nama, cari) == 0) {
            printf("Ditemukan: %s %d %s\n", nama, umur, noreg);
            break;
        }
    }
    // MASALAH 4: Tidak ada pesan penanganan jika nama TIDAK ditemukan
    fclose(fp);
    return 0;
}
```

#### Masalah / Gejala pada Kode Awal:
1. **Ketiadaan Validasi File Pointer (`NULL Dereference`):**  
   Jika berkas `siswa.txt` belum dibuat atau jalurnya salah, `fopen()` mengembalikan `NULL`. Melakukan `fscanf()` pada pointer `NULL` memicu crash instan (*Segmentation Fault*).
2. **Ketiadaan Abstraksi Struktur Data (`struct`):**  
   Data siswa (nama, umur, no.reg) tidak dibungkus dalam tipe data bentukan `struct`. Padahal topik perkuliahan Week 7 mewajibkan penerapan struktur data yang modular.
3. **Pemborosan I/O Disk (*Disk Thrashing*):**  
   Membaca langsung dari disk secara berulang sangat lambat dibandingkan memuat data satu kali ke RAM (*in-memory array of struct*).
4. **Ketiadaan Penanganan Kasus Data Tidak Ditemukan:**  
   Jika nama pengunjung tidak ada di dalam file, program selesai secara bisu (*silent exit*) tanpa memberikan pesan validasi ramah kepada pengunjung pameran museum.

---

### 2. 💬 Prompt / Pertanyaan yang Diajukan ke AI Assistant

```text
"Halo, kelompok kami sedang merancang fitur pencarian data siswa interaktif untuk kiosk layar sentuh Museum Sains dan Matematika Indonesia (Tugas 3 TK3 Week 9 - Algorithm and Programming BINUS).

Format data teks pada file 'siswa.txt' adalah: [Nama] [Umur] [Nomor_Registrasi]
Contoh:
Andi 17 230101
Budi 16 230102
Citra 17 230103

Pertanyaan dan bantuan yang kami butuhkan:
1. Bagaimana arsitektur program C yang paling bersih untuk membaca seluruh data siswa.txt ke dalam 'array of struct' secara aman (termasuk validasi file tidak ditemukan)?
2. Bagaimana perancangan algoritma Linear Search menggunakan strcmp beserta penanganan kondisi jika nama tidak ditemukan?
3. Bagaimana analisis konseptual perbandingan waktu pencarian untuk skala data 10 data, 100 data, dan 1.000 data (Best Case, Worst Case, Average Case O(n))?
4. Apa saja rekomendasi optimasi arsitektur komputasi jika basis data siswa pameran melonjak hingga ratusan ribu atau jutaan data pengunjung?"
```

---

### 3. 🧠 Jawaban dan Evaluasi Teknis dari AI Code Assistant

> **Evaluasi & Rekomendasi Solusi AI:**
> 
> 1. **Pola *In-Memory Array of Struct* yang Aman:**  
>    Pisahkan logika program menjadi 3 tahap sekuensial yang bersih:
>    - **Tahap 1 (Load):** Buka file, baca semua baris ke dalam `Siswa daftar[MAX_CAP]` sekali saja di awal, lalu segera tutup file (`fclose`).
>    - **Tahap 2 (Search):** Jalankan *Linear Search* di memori RAM (akses CPU berkecepatan nanodetik, bukan milidetik disk).
>    - **Tahap 3 (Display & Validation):** Gunakan flag/indeks `foundIndex = -1`. Jika setelah perulangan `foundIndex == -1`, cetak pesan validasi bahwa siswa tidak terdaftar.
> 
> 2. **Analisis Kompleksitas Waktu Linear Search:**  
>    - **Best Case ($\mathcal{O}(1)$):** Elemen berada di indeks ke-0 (1 perbandingan).
>    - **Worst Case ($\mathcal{O}(n)$):** Elemen berada di indeks terakhir atau tidak ada ($n$ perbandingan).
>    - **Average Case ($\mathcal{O}(n)$):** Rata-rata perbandingan adalah $\frac{n+1}{2}$.
> 
> 3. **Tabel Evaluasi Skala Data ($N = 10, 100, 1.000$):**
>    - Untuk $N = 10$ s/d $1.000$, Linear Search masih sangat layak karena waktu komputasi $< 0.1\text{ ms}$ (jauh di bawah batas persepsi visual manusia $100\text{ ms}$).
> 
> 4. **Rekomendasi Skalabilitas Masa Depan:**
>    - **Sorting + Binary Search ($\mathcal{O}(\log n)$):** Untuk $1.000.000$ data, hanya butuh maksimal $20$ kali perbandingan!
>    - **Hash Table ($\mathcal{O}(1)$):** Akses instan konstan berbasis kunci nama.
>    - **Trie (Prefix Tree):** Sangat ideal untuk *touchscreen display* karena mendukung fitur *Auto-Complete* saat pengguna mengetik huruf awal nama.

---

### 4. 🚀 Desain Solusi Final Hasil Validasi AI

#### A. Pseudo Code Pembacaan File & Linear Search Terstandar ISO
```text
ALGORITHM PencarianDataSiswa
BEGIN
    DEFINE STRUCT Siswa (nama, umur, no_reg)
    DECLARE ARRAY daftarSiswa[100] OF Siswa
    DECLARE totalSiswa = 0
    DECLARE FILE fp

    // 1. Pembacaan berkas teks
    OPEN fp = fopen("siswa.txt", "r")
    IF fp IS NULL THEN
        PRINT "Galat: Berkas siswa.txt tidak ditemukan!"
        EXIT PROGRAM
    ENDIF

    WHILE totalSiswa < 100 AND fscanf(fp) SUKSES DO
        totalSiswa = totalSiswa + 1
    ENDWHILE
    CLOSE fp

    // 2. Input pencarian pengguna
    PROMPT "Masukkan nama siswa yang dicari: "
    READ queryNama

    // 3. Algoritma Linear Search
    foundIndex = -1
    FOR i = 0 TO totalSiswa - 1 DO
        IF strcmp(daftarSiswa[i].nama, queryNama) == 0 THEN
            foundIndex = i
            BREAK
        ENDIF
    ENDFOR

    // 4. Validasi hasil pencarian
    IF foundIndex != -1 THEN
        PRINT "Data Ditemukan: " + daftarSiswa[foundIndex].nama
        PRINT "Umur: " + daftarSiswa[foundIndex].umur
        PRINT "No. Registrasi: " + daftarSiswa[foundIndex].no_reg
    ELSE
        PRINT "Validasi: Maaf, siswa dengan nama " + queryNama + " tidak terdaftar."
    ENDIF
END
```

#### B. Tabel Perbandingan Konseptual Waktu Pencarian ($O(n)$)

| Ukuran Data ($N$) | Best Case | Average Case | Worst Case | Evaluasi Responsivitas Layar Sentuh Museum |
| :---: | :---: | :---: | :---: | :---|
| **$N = 10$ Data** | 1 perbandingan | $\approx 5$ perbandingan | 10 perbandingan | **Sangat Baik:** Respon seketika (< 0.001 ms). |
| **$N = 100$ Data** | 1 perbandingan | $\approx 50$ perbandingan | 100 perbandingan | **Sangat Baik:** Tidak ada jeda visual sama sekali. |
| **$N = 1.000$ Data** | 1 perbandingan | $\approx 500$ perbandingan | 1.000 perbandingan | **Layak & Aman:** Beban CPU sangat ringan (< 0.1 ms). |
| **$N \ge 100.000$ Data** | 1 perbandingan | $\approx 50.000$ perbandingan | 100.000 perbandingan | **Mulai Menurun:** Membutuhkan optimasi Binary Search / Hash Table. |

---

### 5. 🎓 Dampak Pembelajaran & Manfaat Kolaborasi Manusia-AI

1. **Penerapan Tipe Bentukan C (`struct`):**  
   Mahasiswa menguasai cara mengorganisasi entitas dunia nyata (siswa dengan atribut nama, umur, dan nomor registrasi) ke dalam struktur data yang rapi dan terukur.
2. **Keterampilan Analisis Asimptotik Big-O:**  
   Mahasiswa mampu membedakan performa Best Case, Average Case, dan Worst Case dari algoritma pencarian sekuensial.
3. **Pola Pikir Arsitektur Skala Besar (*Scalable System Design*):**  
   Mahasiswa memahami kapan algoritma Linear Search $O(n)$ cukup digunakan dan kapan harus beralih ke struktur data tingkat lanjut seperti Binary Search ($O(\log n)$), Hash Table ($O(1)$), atau Trie untuk antarmuka interaktif.
