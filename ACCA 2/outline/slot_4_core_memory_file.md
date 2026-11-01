# 📕 Slot 4: Core Engine, File Persistence & Algoritma Rekursif
**PIC:** `[x] Chandra`  
**Status:** `✅ SELESAI (100% Lulus Uji Validasi Soal)`  
**Tingkat Kesulitan:** **Tinggi (Fondasi Arsitektur Berkas, Cold-Start & Rekursi)**  
**Topik Silabus:** Week 6 (*Recursion*), Week 9 (*File Processing & Searching*)  

---

## 🎯 Deskripsi Tugas

Slot 4 merupakan tulang punggung (*backbone*) teknis dari aplikasi Toko Buku "Literasi Nusantara Jaya". Modul ini memastikan program berjalan dengan performa tinggi, bebas dari memory leak/crash, dan tangguh dalam menangani berkas teks (*fault-tolerant*).

Tanggung jawab utama:
1. **Fault-Tolerant File Engine (Week 9):** Membaca dan menulis berkas `databuku.txt` dan `history.txt`. Menangani kondisi saat file **belum ada pada awal program dijalankan** (kondisi *cold start*) tanpa menyebabkan program crash (menginisialisasi `count = 0`).
2. **Penyimpanan Berkas (Menu 6 & Menu 7):**
   * Menyimpan data buku dan riwayat ke disk saat user keluar (Menu 6).
   * Menambahkan baris transaksi baru seketika dengan mode append `"a"` (Menu 7).
   * Menulis ulang histori saat ada baris riwayat yang dihapus (Menu 4).
3. **Implementasi Rekursi (Week 6 Compliance):**
   * **Rekursi Akumulator Omzet:** Menghitung total omzet kumulatif toko dari data histori penjualan.
   * **Recursive Linear Search:** Mencari data buku berdasarkan kode secara rekursif saat transaksi kasir.

---

## 🛠️ Kontrak Antarmuka Fungsi (Function Prototypes)

```c
// ==========================================
// 1. PEMROSESAN BERKAS / FILE I/O (WEEK 9)
// ==========================================
void loadBooksFromFile(const char *filename, Book books[], int *count);
void saveBooksToFile(const char *filename, const Book books[], int count);
void loadHistoryFromFile(const char *filename, TransactionHistory histories[], int *count);
void appendTransactionToFile(const char *filename, const TransactionHistory *trans);
void saveAllHistoryToFile(const char *filename, const TransactionHistory histories[], int count);

// ==========================================
// 2. FUNGSI REKURSIF (WEEK 6)
// ==========================================
// Menghitung total nilai omzet seluruh transaksi secara rekursif
double calculateTotalRevenueRecursive(const TransactionHistory histories[], int n);

// Mencari indeks buku berdasarkan kode secara rekursif
int searchBookByCodeRecursive(const Book books[], int currentIndex, int totalBooks, const char *targetCode);
```

---

## 📝 Spesifikasi Teknis Mendalam

### 1. Format Serialisasi & Penanganan Berkas (File Engine)
* **Format Delimiter Berkas:** Menggunakan karakter pipa (`|`) agar nama buku atau jenis yang mengandung spasi tidak terpotong:
  * `databuku.txt`: `Kode|Nama Buku|Kategori|Harga`
    ```text
    BK001|Dasar Pemrograman C|Komputer|85000.00
    BK002|Algoritma Lanjut|Komputer|115000.00
    ```
  * `history.txt`: `Kode|Qty|TotalPrice|PayType|Detail`
    ```text
    BK001|2|170000.00|1|170000.00
    BK002|1|115000.00|2|TRX-INV-9901
    ```
* **Penanganan First-Run / Cold-Start (Wajib):**
  ```c
  FILE *fp = fopen(filename, "r");
  if (!fp) {
      // File belum ada di disk (Kondisi Run Pertama)
      // JANGAN CRASH! Inisialisasi count = 0
      *count = 0;
      return;
  }
  ```
* **Penyimpanan Berkas (Menu 6 & Menu 7):**
  * `saveBooksToFile`: Menimpa berkas dengan mode `"w"`.
  * `appendTransactionToFile`: Menambahkan baris baru seketika dengan mode `"a"`.
  * `saveAllHistoryToFile`: Menulis ulang seluruh histori saat ada data yang dihapus (Menu 4).

### 2. Implementasi Rekursi (Week 6)
* **Akumulasi Finansial (Total Omzet):**
  ```c
  double calculateTotalRevenueRecursive(const TransactionHistory histories[], int n) {
      if (n <= 0) return 0.0; // Base case
      return histories[n - 1].totalPrice + calculateTotalRevenueRecursive(histories, n - 1);
  }
  ```
* **Pencarian Kode Buku (Recursive Linear Search):**
  ```c
  int searchBookByCodeRecursive(const Book books[], int currentIndex, int totalBooks, const char *targetCode) {
      if (currentIndex >= totalBooks) return -1; // Base case: tidak ditemukan
      if (strcmp(books[currentIndex].bookCode, targetCode) == 0) return currentIndex; // Base case: ditemukan
      return searchBookByCodeRecursive(books, currentIndex + 1, totalBooks, targetCode); // Recursive step
  }
  ```

---

## ⚠️ Checklist Pengujian Mandiri
- [x] Program dapat dijalankan dari folder bersih (tanpa berkas `databuku.txt` dan `history.txt`) tanpa crash.
- [x] Berkas tersimpan dengan format delimiter yang konsisten dan dapat dimuat kembali pada sesi berikutnya.
- [x] Fungsi rekursi akumulasi omzet memberikan nilai yang sama persis dengan penjumlahan iteratif.
- [x] Pencarian rekursi dapat menemukan kode buku di awal, tengah, dan akhir array, serta mengembalikan `-1` jika tidak ada.
- [x] Penanganan data buku yang mengandung spasi atau karakter khusus terbaca dan tertulis sempurna.
