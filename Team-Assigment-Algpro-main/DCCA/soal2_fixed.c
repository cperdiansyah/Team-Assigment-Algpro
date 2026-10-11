/**
 * ============================================================================
 * Program      : soal2_fixed.c (STARTER TEMPLATE / BOOTSTRAP)
 * Studi Kasus  : Perpustakaan Digital Lentera Nusantara
 * Topik        : Debugging dan Analisis Program Sorting
 * Mata Kuliah  : Algorithm and Programming (COMP6112036) - DCCA
 * Kelas        : DCCA - LEC
 * Kelompok     : Group 1
 * ============================================================================
 * MATERI YANG DITERAPKAN (SESUAI SILABUS BINUS):
 * - Modul Praktikum 3 Halaman 5: "Bubble Sort Implementation"
 *
 * PETUNJUK PENGERJAAN:
 * Di bawah ini adalah kode fungsi sorting lama milik Ibu Arini yang masih ada bug.
 * Tugas PIC Soal 2:
 * 1. Analisis mengapa potongan loop 'for (j = 0; j < n; j++)' dan kondisi
 *    'if (arr[j] > arr[i])' menghasilkan urutan yang keliru.
 * 2. Perbaiki fungsi sort() di bawah menggunakan algoritma Bubble Sort yang valid
 *    (Lihat referensi Modul Praktikum 3 Halaman 5).
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

// TODO: Perbaiki fungsi sort di bawah ini menggunakan Bubble Sort yang valid
// Referensi: Modul Praktikum 3 Halaman 5:
// for (int i = 0; i < n - 1; i++) {
//     for (int j = 0; j < n - i - 1; j++) {
//         if (arr[j] > arr[j + 1]) {
//             int temp = arr[j];
//             arr[j] = arr[j + 1];
//             arr[j + 1] = temp;
//         }
//     }
// }
void sort(int arr[], int n) {
    int i, j, temp;

    // [Tuliskan kode perbaikan logika Bubble Sort kalian di sini]

    (void)i; (void)j; (void)temp; (void)arr; (void)n; // Placeholder bebas warning
}

void cetak_array(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    // Array tahun terbit koleksi perpustakaan sesuai soal
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
