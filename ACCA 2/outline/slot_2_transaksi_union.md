# 📙 Slot 2: Transaksi Penjualan & Union (Menu 7, Menu 2, Menu 4)
**PIC:** `[ ] Open Slot`  
**Tingkat Kesulitan:** Sedang (Logika Bisnis, Aritmatika, Union, & Array Manipulation)  
**Bobot Nilai Soal:** 35% (Menu 7: 15%, Menu 2: 10%, Menu 4: 10%)  

---

## 🎯 Deskripsi Tugas

Slot 2 bertanggung jawab atas siklus transaksi kasir dan histori penjualan toko buku, mencakup:
1. **Menu 7 — Input Transaksi Penjualan:** Menerima input kode buku dan jumlah buku yang dibeli, memvalidasi ketersediaan buku melalui fungsi pencarian, menghitung total harga (`jumlah * harga`), memilih metode pembayaran memanfaatkan fitur C `union`, dan menyimpan transaksi ke riwayat.
2. **Menu 2 — View History Transaksi:** Menampilkan seluruh rekam jejak transaksi penjualan yang pernah dilakukan.
3. **Menu 4 — Delete History:** Menampilkan riwayat transaksi, meminta input nomor indeks ($1 \le \text{idx} \le N$), menghapus data riwayat via *array shifting*, dan mencetak pesan resmi: `"Data Successfully delete.."`.

---

## 🧩 Struktur Data & Union Acuan

Sesuai materi silabus **Week 7 (Structures and Union)**:

```c
// Metode Pembayaran
typedef enum {
    PAYMENT_CASH = 1,
    PAYMENT_QRIS = 2
} PaymentType;

// Union (Week 7): Menghemat memori dengan berbagi ruang memori yang sama
typedef union {
    double cashReceived;        // Uang tunai yang diserahkan pembeli
    char transactionRef[25];    // Nomor referensi digital QRIS / Transfer
} PaymentDetail;

// Struktur Riwayat Transaksi
typedef struct {
    char bookCode[10];          // Kode buku yang dibeli
    int quantity;               // Jumlah eksemplar yang dibeli
    double totalPrice;          // Total harga = quantity * price
    PaymentType payType;        // Jenis pembayaran (Cash / QRIS)
    PaymentDetail detail;       // Detail pembayaran via Union
} TransactionHistory;
```

---

## 🛠️ Kontrak Antarmuka Fungsi (Function Prototypes)

```c
// 1. Mencatat transaksi baru (memeriksa ketersediaan buku & menghitung total)
void inputTransaction(const Book *books, int bookCount, 
                      TransactionHistory **histories, int *historyCount, int *historyCapacity);

// 2. Menampilkan seluruh data histori transaksi penjualan
void viewAllHistory(const TransactionHistory *histories, int historyCount);

// 3. Menghapus riwayat transaksi tertentu berdasarkan indeks pilihan pengguna
void deleteHistoryByIndex(TransactionHistory *histories, int *historyCount);
```

---

## 📝 Spesifikasi Logika & Algoritma

### 1. Menu 7: Input Transaksi Penjualan
* **Alur Eksekusi:**
  1. Tampilkan pesan meminta input: **Kode Buku** (misal: `BK001`) dan **Jumlah Terjual** (integer $> 0$).
  2. Cari apakah kode buku tersebut terdaftar di katalog menggunakan fungsi pencarian (Slot 4).
     * Jika **tidak ditemukan**: Tampilkan pesan `[ERROR] Kode buku tidak ditemukan di katalog!` dan batalkan transaksi.
  3. Jika ditemukan, ambil harga satuannya ($P$), lalu hitung:
     $$\text{Total Harga} = \text{Jumlah Terjual} \times P$$
  4. **Penerapan Union (Metode Bayar):**
     * Tanyakan metode pembayaran: (1) Tunai, (2) QRIS/Transfer.
     * Jika Tunai: Input nominal uang diterima, simpan ke `detail.cashReceived`. Jika uang cukup, tampilkan kembalian.
     * Jika QRIS: Input ID referensi transaksi, simpan ke `detail.transactionRef`.
  5. Tambahkan data ke daftar `histories` (lakukan *realloc* jika kapasitas penuh).
  6. Segera lakukan sinkronisasi / append ke `history.txt`.
  7. Tampilkan pesan sukses sesuai dokumen soal:
     `Transaksi berhasil dicatat.`

### 2. Menu 2: View History Transaksi
* Cek apakah histori transaksi kosong (`historyCount == 0`). Jika ya, tampilkan pesan:
  `[INFO] Belum ada transaksi penjualan yang dicatat.`
* Jika ada, cetak dalam bentuk tabel rapi:
  ```text
  +====+===========+===========+================+=============+
  | NO | KODE BUKU | JML TERJUAL| TOTAL HARGA    | METODE      |
  +====+===========+===========+================+=============+
  |  1 | BK001     |         2 |   170000.00    | TUNAI       |
  |  2 | BK003     |         1 |    95000.00    | QRIS        |
  +====+===========+===========+================+=============+
  ```
* *Fitur Tambahan Nilai:* Di bagian bawah tabel, tampilkan akumulasi total omzet yang dihitung menggunakan fungsi rekursif dari Slot 4.

### 3. Menu 4: Delete History
* Tampilkan daftar histori transaksi beserta nomor urutnya (1 s.d. $N$).
* Minta input nomor urut riwayat yang ingin dihapus.
* Validasi input: $1 \le \text{input} \le \text{historyCount}$.
* Lakukan pergeseran array (*array shifting*) ke kiri dari posisi yang dihapus:
  ```c
  int targetIndex = inputIdx - 1;
  for (int i = targetIndex; i < *historyCount - 1; i++) {
      histories[i] = histories[i + 1];
  }
  (*historyCount)--;
  ```
* Cetak pesan sukses persis seperti dokumen soal:
  `Data Successfully delete..`

---

## ⚠️ Checklist Pengujian Mandiri
- [ ] Transaksi gagal secara aman jika user memasukkan kode buku yang tidak terdaftar.
- [ ] Perhitungan `total = jumlah * harga` menghasilkan angka desimal yang akurat.
- [ ] Struktur `union PaymentDetail` terisi dengan benar sesuai metode bayar tanpa merusak data memori lain.
- [ ] View history menampilkan data yang cocok dengan apa yang diinputkan.
- [ ] Hapus history berhasil memotong array dan memperbarui total transaksi.
