# 📋 TEMPLATE PANDUAN LAPORAN TUGAS KELOMPOK KE-1 (WEEK 7) — DCCA
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** DCCA - LEC  
**Dosen Pengampu:** D5816 - ERIC GUNAWAN, S.Kom., M.TI  
**Kelompok:** Group 1  

> 💡 **Petunjuk Penggunaan:**  
> File ini adalah *starter template / outline* panduan penyusunan laporan. Anggota tim yang memegang peran terkait dapat mengisi setiap bagian di bawah ini sesuai hasil pengerjaan, lalu memindahkannya ke berkas resmi `TK1-W7-S15-R3 - Jawab.docx`.

---

## SOAL 1: DESAIN DAN ANALISIS STRUCT DAN UNION (Bobot 60%)

### 1.1 Penjelasan Konsep Struktur Data yang Diusulkan
*(Diisi oleh PIC Soal 1)*
- [ ] Jelaskan mengapa dibuat `struct ItemKatalog` yang menampung atribut umum (`judul`, `tahun_terbit`).
- [ ] Jelaskan atribut spesifik Buku (`penulis`, `jumlah_halaman`) dan Majalah (`nomor_edisi`, `bulan_terbit`).
- [ ] Jelaskan peran **`union DetailMedia`** sebagai pembungkus yang efisien (karena 1 item perpustakaan hanya bisa berupa buku ATAU majalah, tidak pernah keduanya sekaligus).
- [ ] Tempelkan potongan deklarasi `struct` dan `union` dari berkas `DCCA/soal1.c`.

### 1.2 Analisis Keunggulan & Efisiensi Memori (`union` vs `struct`)
*(Diisi oleh PIC Analisis Memori)*
- [ ] Tuliskan perhitungan ukuran byte:
  - `sizeof(InfoBuku)` = ... byte
  - `sizeof(InfoMajalah)` = ... byte
- [ ] Bandingkan jika menggunakan **`struct` biasa**:
  - Ukuran = `sizeof(InfoBuku)` + `sizeof(InfoMajalah)` = ... byte
- [ ] Bandingkan jika menggunakan **`union`**:
  - Ukuran = `max(sizeof(InfoBuku), sizeof(InfoMajalah))` = ... byte
- [ ] Simpulkan berapa byte yang berhasil dihemat per item katalog dan dampaknya jika ada ribuan koleksi pada server yang memorinya terbatas.

### 1.3 Flowchart Logika Soal 1
*(Diisi oleh PIC Flowchart)*
- [ ] Gambarkan diagram alir (Flowchart) alur sistem:
  1. Input judul dan tahun terbit.
  2. Percabangan (*Decision*): Apakah jenis media = Buku atau Majalah?
  3. Input atribut spesifik sesuai cabang (Buku $\rightarrow$ penulis & halaman; Majalah $\rightarrow$ edisi & bulan).
  4. Output tampilan detail katalog.
- [ ] Tempelkan gambar flowchart di sini / di dokumen Word.

### 1.4 Implementasi Kode Sumber C
- [ ] Tempelkan kode C lengkap yang sudah selesai dikerjakan dari `DCCA/soal1.c`.

---

## SOAL 2: DEBUG DAN ANALISIS PROGRAM SORTING PERPUSTAKAAN (Bobot 40%)

### 2.1 Analisis Letak Kesalahan (Bug) pada Kode Asli Ibu Arini
*(Diisi oleh PIC Analisis Bug)*
Kode asli Ibu Arini:
```c
void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n; j++) {
            if (arr[j] > arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
```
- [ ] Jelaskan **Bug 1 pada Inner Loop**: Mengapa `for (j = 0; j < n; j++)` salah dan merusak elemen yang sudah terurut?
- [ ] Jelaskan **Bug 2 pada Logika Perbandingan/Swapping**: Mengapa membandingkan `arr[j] > arr[i]` dan menukar ke indeks `i` menghasilkan urutan yang kacau/inkonsisten?

### 2.2 Kode Sorting yang Diperbaiki
*(Diisi oleh PIC Koding Soal 2)*
- [ ] Tempelkan fungsi `sort()` yang sudah diperbaiki (misal: Bubble Sort yang membandingkan `arr[j] > arr[j + 1]` dengan batas `n - 1 - i`).
- [ ] Tampilkan hasil pengujian array `{64, 34, 25, 12, 22}` sebelum dan sesudah diurutkan.

### 2.3 Flowchart Logika Sorting yang Benar
*(Diisi oleh PIC Flowchart)*
- [ ] Gambarkan flowchart perulangan outer loop `i`, inner loop `j`, kondisi `arr[j] > arr[j+1]`, dan proses swap data.

---

## 📚 DAFTAR REFERENSI
*(Diisi oleh PIC Dokumentasi — disesuaikan dengan materi di DCCA/docs/)*:
1. Pambudi, P. D. L. (2026). *LN07: Structures and Union*. Lecture Notes Algorithm and Programming (COMP6112036). Binus Online.
2. Binus Online. (2026). *LN05: Pointers and Array*. Algorithm and Programming (COMP6112036).
3. Binus Online. (2026). *LN04: Program Control: Selection and Repetition*. Algorithm and Programming (COMP6112036).
4. Deitel, P. J., & Deitel, H. (2022). *C How to Program (9th Edition)*. Pearson Education. Chapter 10: Structures, Unions, Bit Manipulation and Enumerations.
