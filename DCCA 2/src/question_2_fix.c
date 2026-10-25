/**
 * ============================================================================
 * Program      : question_2_fix.c (SOLUSI PERBAIKAN TUGAS 2 DCCA 2)
 * Deskripsi    : Program Pencatatan Nilai Siswa Menggunakan Alokasi Memori Dinamis
 *                yang Aman dari Memory Leak, Null Pointer Dereference, dan
 *                Integer Overflow (Sesuai Pedoman Secure Coding).
 * Mata Kuliah  : Algorithm and Programming (COMP6112036) - Kelas DCCA
 * Kelompok     : Group 1
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 10000 // Batasan kapasitas maksimum logis untuk mencegah overflow

/**
 * Membersihkan sisa karakter di buffer standard input (stdin)
 * Mencegah karakter newline '\n' atau string invalid merusak input berikutnya.
 */
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

    // 1. Validasi Input Jumlah Siswa (Pencegahan Angka Negatif, Nol, & Non-Angka)
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

        break; // Input valid
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
