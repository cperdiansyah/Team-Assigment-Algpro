# 🤖 DOKUMENTASI HAICOLA — TUGAS 2 DCCA 2 (DEBUGGING & ALOKASI MEMORI DINAMIS)
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** DCCA - LEC  
**Kelompok:** Group 1  
**Topik Evaluasi:** Security Auditing, Root Cause Analysis (RCA) 5 Bug Memori Dinamis, Pencegahan Null Pointer Dereference (`SIGSEGV`), Mitigasi Integer Overflow, Penanganan Memory Leak via `free()`, dan Pencegahan Dangling Pointer (Tugas 2 TK2)  

---

> 📌 **Catatan untuk Rekan Tim:**  
> Berkas ini berisi dokumentasi resmi sesi **HAICOLA (Human-AI Collaboration)** untuk modul **DCCA 2 Tugas 2**. Dokumen ini siap digunakan sebagai lampiran pembuktian transparansi pemanfaatan AI dan pengisian formulir resmi `AI_Usage_Declaration_Form_EN.docx`.

---

### 1. ⚠️ Potongan Kode Sebelum Konsultasi AI (Kode Asli Bermasalah dari Soal)

Potongan kode asli yang diberikan pada soal Tugas 2 (`src/question_2_buggy.c`):

```c
// ========================================================
// KODE ASLI DARI SOAL (Mengandung 5 Celah Keamanan & Bug)
// ========================================================
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *grades;
    int numStudents, i;

    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    // KESALAHAN 1 & 2: Tanpa validasi numStudents dan tanpa cek NULL
    grades = malloc(numStudents * sizeof(int));  // Memory allocation

    for(i = 0; i < numStudents; i++) {
        printf("Enter grade for student %d: ", i + 1);
        scanf("%d", &grades[i]);
    }

    // KESALAHAN 3 & 4: Memory leak fatal (tidak ada free) & potensi dangling pointer
    return 0;
}
```

#### Masalah / Gejala pada Kode Awal:
1. **Critical Memory Leak (Tanpa Pemanggilan `free()`):**  
   Blok memori di Heap yang dipesan melalui `malloc()` tidak pernah dibebaskan sebelum program berakhir. Jika pola kode ini diintegrasikan ke dalam sistem layanan backend atau loop server yang berjalan tanpa henti (*daemon/microservice*), konsumsi RAM akan membengkak terus-menerus hingga server kehabisan memori (*Out of Memory / OOM crash*).
2. **Ketiadaan Validasi Pointer `NULL` (*Null Pointer Dereference Risk*):**  
   Fungsi `malloc()` dapat mengembalikan `NULL` apabila kapasitas RAM fisik habis atau kuota memori proses terlampaui. Menulis data ke `grades[i]` saat `grades == NULL` akan memicu pelanggaran akses memori virtual (*hardware fault*) dan sinyal OS `SIGSEGV` (*Segmentation Fault*), mematikan program seketika.
3. **Ketiadaan Validasi Batas Input `numStudents` (*Integer Overflow Risk*):**  
   Jika pengguna memasukkan angka negatif (misal `-5`), perkalian `numStudents * sizeof(int)` akan dikonversi menjadi bilangan unsigned raksasa. Jika pengguna menginput angka sangat besar (misal $2^{30}$), terjadi *arithmetic multiplication overflow* yang menghasilkan angka kecil semu, memicu *heap-based buffer overflow*.
4. **Kerapuhan Input Stream `scanf()`:**  
   Jika pengguna memasukkan karakter non-numerik (misal huruf `"abc"`), fungsi `scanf` gagal mengonversi input, karakter tertahan di buffer `stdin`, dan variabel `numStudents` tetap berisi nilai sampah (*garbage value*).
5. **Risiko Dangling Pointer:**  
   Tanpa menyetel pointer ke `NULL` setelah deallokasi, pointer tetap memegang alamat memori yang sudah tidak valid, berisiko memicu celah keamanan *Use-After-Free* (UAF) atau *Double Free* jika program dikembangkan lebih lanjut.

---

### 2. 💬 Prompt / Pertanyaan yang Diajukan ke AI Assistant

```text
"Halo, kelompok kami sedang menganalisis potongan kode bahasa C pada Tugas 2 DCCA 2 (Dynamic Memory Allocation). Kode tersebut mengalokasikan array dinamis untuk mencatat nilai siswa, namun mengandung komentar '// Memory leak, no free call'.

Pertanyaan audit kami:
1. Mohon jelaskan Root Cause Analysis (RCA) secara mendalam dari minimal 4-5 kelemahan pada kode tersebut, baik dari sudut pandang arsitektur memori OS (Heap vs Stack, Virtual Memory, sinyal SIGSEGV), maupun keamanan perangkat lunak (Secure Coding)?
2. Bagaimana cara merefaktor kode ini agar memenuhi standar ISO C dan CERT C Secure Coding, termasuk validasi input jumlah siswa (1 s.d. kapasitas wajar), pengecekan NULL setelah malloc, validasi rentang nilai siswa (0 - 100), dan pembersihan buffer stdin?
3. Mengapa setelah pemanggilan free(grades) sangat disarankan untuk melakukan grades = NULL?
4. Bagaimana bentuk flowchart diagram alir proses manajemen alokasi dan dealokasi memori dinamis yang benar?"
```

---

### 3. 🧠 Jawaban dan Evaluasi dari AI Code Assistant

> **Evaluasi AI:**
> 1. **Dinamika Heap vs Stack & Pembebasan Memori:**  
>    Memori stack dibersihkan secara otomatis saat stack frame fungsi kembali (*return*). Namun alokasi Heap yang dipesan oleh `malloc()` dikelola secara manual oleh runtime allocator (seperti `glibc` atau Windows MSVCRT). Selama `free()` tidak dipanggil, memori tersebut tetap terdaftar sebagai "in use", menyebabkan kebocoran progresif (*memory leak*).
>
> 2. **Mekanisme Virtual Memory & *Null Pointer Dereference*:**  
>    Sistem operasi modern menggunakan Virtual Memory Management (VMM). Alamat `0x0` (`NULL`) sengaja dipetakan ke *unmapped/inaccessible page*. Saat CPU mencoba mengeksekusi instruksi penyimpanan ke `*(NULL + offset)`, unit MMU mendeteksi *page fault* dan OS mengirim sinyal terminasi paksa `SIGSEGV` (*Segmentation Fault*). Oleh sebab itu, pengecekan `if (grades == NULL)` adalah syarat mutlak keamanan program.
>
> 3. **Pembersihan Buffer Input Stdin (*Input Flushing*):**  
>    Saat `scanf("%d", ...)` gagal membaca angka, karakter tersebut tetap tersisa di *standard input stream*. Gunakan fungsi pembantu pembersih buffer:
>    ```c
>    void flush_input_buffer() {
>        int c;
>        while ((c = getchar()) != '\n' && c != EOF);
>    }
>    ```
>
> 4. **Pencegahan Dangling Pointer (*Defensive Nullification*):**  
>    Memanggil `free(grades)` hanya memberi tahu *heap manager* bahwa blok memori tersebut boleh dialokasikan ke proses lain, namun **variabel pointer `grades` masih menyimpan alamat fisik yang sama** (*dangling pointer*). Dengan menyetel `grades = NULL`, program akan aman dari eksploitasi memori *Double Free* atau modifikasi data liar tak terduga.

---

### 4. ✅ Perubahan Nyata pada Kode Setelah Konsultasi AI (Hasil Perbaikan)

Berikut adalah kode perbaikan lengkap dan teruji yang telah diterapkan pada berkas `DCCA 2/src/question_2_fix.c`:

```c
// ========================================================
// KODE SESUDAH KONSULTASI AI (question_2_fix.c — Aman & Robust)
// ========================================================
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 10000 // Batas atas kapasitas logis (mencegah overflow)

// Fungsi pembantu untuk membersihkan buffer keyboard secara bersih
void flush_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int *grades = NULL;
    int numStudents = 0;
    int i;
    int sum = 0;
    double average = 0.0;

    printf("====================================================\n");
    printf("   PROGRAM PENCATATAN NILAI SISWA (ALOKASI DINAMIS) \n");
    printf("====================================================\n");

    // 1. Validasi Input Jumlah Siswa (Pencegahan Angka Negatif & Non-Angka)
    while (1) {
        printf("Masukkan jumlah siswa (1 - %d): ", MAX_STUDENTS);
        if (scanf("%d", &numStudents) != 1) {
            printf("[!] Error: Input harus berupa bilangan bulat positif!\n");
            flush_input_buffer();
            continue;
        }
        flush_input_buffer();

        if (numStudents <= 0) {
            printf("[!] Error: Jumlah siswa harus lebih besar dari 0!\n");
            continue;
        }

        if (numStudents > MAX_STUDENTS) {
            printf("[!] Error: Jumlah siswa melebihi batas maksimal (%d)!\n", MAX_STUDENTS);
            continue;
        }

        break; // Input jumlah siswa valid
    }

    // 2. Alokasi Memori Dinamis di Heap
    grades = (int *)malloc(numStudents * sizeof(int));

    // 3. Verifikasi Keberhasilan Alokasi Memori (NULL Pointer Check)
    if (grades == NULL) {
        fprintf(stderr, "\n[FATAL ERROR] Alokasi memori sebesar %zu byte gagal!\n",
                (size_t)numStudents * sizeof(int));
        fprintf(stderr, "              Sistem kehabisan memori RAM fisik.\n");
        return EXIT_FAILURE;
    }

    printf("[✓] Sukses mengalokasikan %zu byte memori di Heap.\n\n",
           (size_t)numStudents * sizeof(int));

    // 4. Input Nilai Siswa dengan Validasi Rentang Akademik (0 - 100)
    for (i = 0; i < numStudents; i++) {
        while (1) {
            printf("Masukkan nilai untuk siswa ke-%d (0 - 100): ", i + 1);
            if (scanf("%d", &grades[i]) != 1) {
                printf("[!] Error: Nilai harus berupa bilangan bulat!\n");
                flush_input_buffer();
                continue;
            }
            flush_input_buffer();

            if (grades[i] < 0 || grades[i] > 100) {
                printf("[!] Error: Nilai akademik harus berada dalam rentang 0 s.d. 100!\n");
                continue;
            }

            break; // Nilai siswa valid
        }
        sum += grades[i];
    }

    // 5. Pengolahan Data & Penampilan Statistik
    average = (double)sum / numStudents;
    printf("\n----------------------------------------------------\n");
    printf("RINGKASAN DATA NILAI SISWA:\n");
    printf("----------------------------------------------------\n");
    for (i = 0; i < numStudents; i++) {
        printf("Siswa ke-%-3d : %d\n", i + 1, grades[i]);
    }
    printf("----------------------------------------------------\n");
    printf("Total Siswa    : %d orang\n", numStudents);
    printf("Nilai Rata-rata: %.2f\n", average);
    printf("----------------------------------------------------\n");

    // 6. Pembebasan Memori Dinamis (Eliminasi Memory Leak)
    free(grades);

    // 7. Nullifikasi Pointer (Eliminasi Dangling Pointer)
    grades = NULL;

    printf("\n[✓] Memori Heap berhasil dibebaskan (free) dan pointer disetel ke NULL.\n");
    printf("[✓] Program selesai dengan aman tanpa memory leak.\n");

    return EXIT_SUCCESS;
}
```

---

### 5. 📊 Rangkuman Perbandingan Keamanan Memori

| Aspek Pengujian | Kode Asli Soal | Kode Perbaikan Tim (Final) | Keterangan & Manfaat Keamanan |
| :--- | :--- | :--- | :--- |
| **Pengecekan Alokasi Heap** | ❌ Diabaikan | ✅ `if (grades == NULL)` | Menghilangkan risiko *Segmentation Fault* (`SIGSEGV`) |
| **Status Memori Pasca-Eksekusi**| ❌ *Memory Leak* permanen | ✅ `free(grades)` dipanggil | Memori dikembalikan utuh ke sistem operasi |
| **Mitigasi Dangling Pointer** | ❌ Pointer dibiarkan liar | ✅ `grades = NULL` | Mencegah bug *Use-After-Free* & *Double Free* |
| **Sanitasi Batas Jumlah Siswa** | ❌ Menerima $\le 0$ & angka raksasa | ✅ Dibatasi $1 \le N \le 10.000$ | Menangkal *Arithmetic Integer Overflow* |
| **Validasi Rentang Nilai** | ❌ Menerima angka sembarang | ✅ Validasi nilai $0 - 100$ | Integritas data akademik terjaga |
| **Ketahanan Input Stream** | ❌ Rusak jika input huruf | ✅ Sanitasi `flush_input_buffer()` | Kebal terhadap error format dan *infinite loop* |
