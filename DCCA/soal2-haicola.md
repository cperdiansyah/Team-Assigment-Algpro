# 🤖 DOKUMENTASI HAICOLA — SOAL 2 DCCA (DEBUGGING & SORTING KOLEKSI)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** DCCA - LEC  
**Kelompok:** Group 1  
**Topik Evaluasi:** Root Cause Analysis (RCA) Bug Algoritma Sorting Ibu Arini & Implementasi Bubble Sort Terverifikasi  

---

> 📌 **Catatan untuk Rekan Tim:**  
> Berkas ini berisi dokumentasi resmi sesi **HAICOLA (Human-AI Collaboration)** untuk modul **DCCA Soal 2**. Dokumen ini siap digunakan sebagai lampiran pembuktian transparansi AI dan pengisian berkas `AI_Usage_Declaration_Form_EN.docx`.

---

### 1. ⚠️ Potongan Kode Sebelum Konsultasi AI (Mengandung Bug Logika)

Potongan kode fungsi sorting lama milik Ibu Arini yang bermasalah dalam mengurutkan array tahun terbit `{64, 34, 25, 12, 22}`:

```c
// ========================================================
// KODE SEBELUM KONSULTASI AI (Fungsi sort() Lama Ibu Arini)
// ========================================================
void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {         // Bug 1: Batas inner loop tetap sampai n
            if (arr[j] > arr[i]) {       // Bug 2: Membandingkan j dengan i
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
```

#### Masalah / Gejala Bug pada Kode Awal:
1. **Hasil Pengurutan Gagal (Salah Posisi):** Saat dijalankan pada array `{64, 34, 25, 12, 22}`, hasil akhirnya adalah `{12, 25, 34, 64, 22}`. Angka `22` tertinggal di posisi paling akhir dan gagal diurutkan ke posisi yang seharusnya (antara 12 dan 25).
2. **Pertukaran Destruktif (*Destructive Swapping*):** Kondisi `if (arr[j] > arr[i])` membandingkan elemen `j` dengan indeks tetap `i`. Ketika terjadi pertukaran, nilai `arr[i]` berubah seketika, sehingga perbandingan pada iterasi `j` berikutnya tidak lagi konsisten terhadap elemen awal yang ingin diurutkan.
3. **Redundansi Iterasi Loop Dalam:** Batas inner loop selalu berjalan penuh (`j < n`), padahal elemen yang sudah berada di posisi tepat tidak perlu diproses ulang.

---

### 2. 💬 Prompt / Pertanyaan yang Diajukan ke AI Assistant

```text
"Halo, saya sedang menganalisis kode fungsi sorting di bahasa C untuk mengurutkan array tahun terbit koleksi perpustakaan: {64, 34, 25, 12, 22}. 
Kode lama yang diberikan adalah:

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

Mengapa fungsi di atas menghasilkan output salah [12, 25, 34, 64, 22] di mana angka 22 tertinggal di ujung? 
Mohon jelaskan Root Cause Analysis (RCA) letak kesalahan logikanya secara runut, dan bagaimana bentuk algoritma Bubble Sort yang benar dan valid sesuai silabus dasar C agar array terurut sempurna menjadi [12, 22, 25, 34, 64]?"
```

---

### 3. 🧠 Jawaban dan Evaluasi dari AI Code Assistant

> **Evaluasi AI:**
> 1. **Akar Masalah (*Root Cause*) Perbandingan `arr[j] > arr[i]`:**  
>    Algoritma ini mencoba mengombinasikan konsep Selection Sort dan Bubble Sort secara keliru. Dalam Selection Sort murni, kita mencari indeks elemen terkecil/terbesar terlebih dahulu lalu melakukan **1 kali pertukaran per putaran**. Namun pada kode ini, pertukaran langsung dilakukan setiap kali kondisi terpenuhi. Akibatnya, nilai pada indeks `i` berganti-ganti di tengah jalan (*mutating reference*), merusak elemen yang sebelumnya sudah tersusun rapi.
> 
> 2. **Penyebab Tertinggalnya Angka `22`:**  
>    Pada putaran terakhir (`i = 3`), nilai `arr[3]` adalah 64. Ketika `j = 4` (`arr[4] = 22`), evaluasi `arr[4] > arr[3]` bernilai salah (`22 > 64` adalah FALSE). Akibatnya nilai 22 tidak pernah ditukar dan terisolasi di indeks terakhir.
> 
> 3. **Perbaikan dengan Bubble Sort Standar:**  
>    Bubble Sort bekerja dengan membandingkan **dua elemen bersebelahan (*adjacent pairs*)** yaitu `arr[j]` dan `arr[j + 1]`. Jika elemen sebelah kiri lebih besar daripada elemen sebelah kanan (`arr[j] > arr[j + 1]`), lakukan pertukaran (*swap*). Batas perulangan dalam disusutkan menjadi `j < n - i - 1` karena pada setiap putaran `i`, satu elemen terbesar dijamin telah "mengapung" ke posisi akhir.

---

### 4. ✅ Perubahan Nyata pada Kode Setelah Konsultasi AI (Hasil Perbaikan)

Berikut adalah kode yang telah disempurnakan dan diterapkan pada berkas `question_2_fixed.c`:

```c
// ========================================================
// KODE SESUDAH KONSULTASI AI (Bubble Sort Valid & Teruji)
// ========================================================
#include <stdio.h>

void sort(int arr[], int n) {
    int i, j, temp;

    // 1. Loop luar mengontrol jumlah putaran (n - 1 kali)
    for (i = 0; i < n - 1; i++) {
        // 2. Loop dalam menyusut (n - i - 1) melewati elemen kanan yang sudah terurut
        for (j = 0; j < n - i - 1; j++) {
            // 3. Perbandingan bertetangga: tukar jika elemen kiri > elemen kanan
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void cetak_array(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int arr[] = {64, 34, 25, 12, 22};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum sorting : ");
    cetak_array(arr, n);

    sort(arr, n);

    printf("Array setelah sorting : ");
    cetak_array(arr, n);

    return 0;
}
```

#### Ringkasan Perbaikan yang Diterapkan:
* `+` Mengubah mekanisme perbandingan dari indeks acak `arr[j] > arr[i]` menjadi perbandingan pasangan tetangga `arr[j] > arr[j + 1]`.
* `+` Mengoptimalkan rentang loop dalam dari `j < n` menjadi `j < n - i - 1` untuk mencegah operasi perbandingan berlebih pada elemen yang sudah urut.
* `+` Memastikan array uji `{64, 34, 25, 12, 22}` berhasil terurut menjadi `{12, 22, 25, 34, 64}` secara sempurna dan stabil.

---

### 5. 📝 Refleksi Singkat (4 Kalimat)

> Melalui interaksi bersama AI Code Assistant, kami dapat membedah letak cacat logika (*root cause analysis*) pada kode sorting lama Ibu Arini yang melakukan pertukaran nilai referensi secara prematur sehingga merusak keterurutan elemen array. Kami mempelajari bahwa algoritma Bubble Sort yang valid harus mengevaluasi dua elemen bertetangga (`arr[j]` dan `arr[j + 1]`) serta memperpendek batas iterasi loop dalam (`n - i - 1`) di setiap putaran. Sebagai perbaikan konkret pada `question_2_fixed.c`, kami merestrukturisasi nested loop dan kondisi percabangan sehingga array `{64, 34, 25, 12, 22}` berhasil terurut sempurna menjadi `{12, 22, 25, 34, 64}`. Pemanfaatan AI ini sangat efektif dalam mempercepat penelusuran alur tracing bug logika tanpa menggantikan proses implementasi kode mandiri oleh tim.
