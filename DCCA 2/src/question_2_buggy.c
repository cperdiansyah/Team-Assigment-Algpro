/**
 * ============================================================================
 * Program      : question_2_buggy.c
 * Deskripsi    : Potongan kode asli dari soal Tugas 2 yang mengandung kesalahan
 *                manajemen alokasi memori dinamis.
 * ============================================================================
 * 
 * TUGAS UNTUK ANGGOTA 5:
 * 1. Analisis mengapa kode ini bermasalah (minimal 4-5 poin kesalahan).
 * 2. Perbaiki kode ini dan simpan kodenya di file `question_2_fix.c`.
 * 3. Buat flowchart alur proses yang benar.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *grades;
    int numStudents, i;

    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    // KESALAHAN 1: Alokasi memori tanpa validasi numStudents (bisa <= 0 atau integer overflow)
    // KESALAHAN 2: Hasil malloc tidak dicek apakah NULL
    grades = malloc(numStudents * sizeof(int));  // Memory allocation

    for(i = 0; i < numStudents; i++) {
        printf("Enter grade for student %d: ", i + 1);
        scanf("%d", &grades[i]);
    }

    // KESALAHAN 3: Memory leak, tidak ada pemanggilan free(grades)
    // KESALAHAN 4: Pointer tidak diset ke NULL (potensi dangling pointer jika kode diperpanjang)
    return 0;
}
