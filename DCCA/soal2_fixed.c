/**
 * ============================================================================
 * Program      : soal2_fixed.c (STARTER TEMPLATE / BOOTSTRAP)
 * Studi Kasus  : Perpustakaan Digital Lentera Nusantara
 * Topik        : Debugging dan Analisis Program Sorting
 * Mata Kuliah  : Algorithm and Programming (COMP6112036) - DCCA
 * Kelompok     : Group 1
 * ============================================================================
 * PETUNJUK PENGERJAAN:
 * Di bawah ini adalah kode fungsi sorting lama milik Ibu Arini yang masih ada bug.
 * Tugas PIC Soal 2:
 * 1. Analisis mengapa potongan loop 'for (j = 0; j < n; j++)' dan kondisi
 *    'if (arr[j] > arr[i])' menghasilkan urutan yang keliru.
 * 2. Perbaiki fungsi sort() di bawah agar array tahun terbit terurut menaik (Ascending).
 * ============================================================================
 */

#include <stdio.h>

// KODE LAMA MILIK IBU ARINI (MASIH MENGANDUNG BUG):
// void sort(int arr[], int n) {
//     int i, j, temp;
//     for (i = 0; i < n-1; i++) {
//         for (j = 0; j < n; j++) {
//             if (arr[j] > arr[i]) {
//                 temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

// TODO: Perbaiki fungsi sort di bawah ini (misal menggunakan Bubble Sort atau Selection Sort yang valid)
void sort(int arr[], int n) {
    int i, j, temp;

    // Petunjuk Bubble Sort:
    // Outer loop  : for (i = 0; i < n - 1; i++)
    // Inner loop  : for (j = 0; j < n - 1 - i; j++)
    // Perbandingan: if (arr[j] > arr[j + 1]) -> swap

    // [Tuliskan kode perbaikan logika sorting kalian di sini]
    (void)i; (void)j; (void)temp; (void)arr; (void)n; // Placeholder agar compile tanpa warning
}

void cetak_array(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    // Array tahun terbit koleksi sesuai soal
    int arr[] = {64, 34, 25, 12, 22};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum sorting : ");
    cetak_array(arr, n);

    // Jalankan fungsi sort yang sudah kalian perbaiki
    sort(arr, n);

    printf("Array setelah sorting : ");
    cetak_array(arr, n);

    return 0;
}
