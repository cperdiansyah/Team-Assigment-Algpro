# 📘 Slot 1: Manajemen Katalog Buku (Menu 1, Menu 3, Menu 5)
**PIC:** `[ ] Open Slot`  
**Tingkat Kesulitan:** Sedang (Operasi CRUD Dasar & Manipulasi Array of Struct)  
**Bobot Nilai Soal:** 30% (Menu 1: 10%, Menu 3: 10%, Menu 5: 10%)  

---

## 🎯 Deskripsi Tugas

Slot 1 bertanggung jawab atas siklus hidup entitas **Buku** dalam memori program, mencakup:
1. **Menu 1 — Input Data Buku Baru:** Menambahkan buku baru ke memori dan menghasilkan kode buku otomatis bergaya `BK001`, `BK002`, dst.
2. **Menu 3 — View Buku:** Menampilkan seluruh daftar katalog buku yang tersedia dalam bentuk tabel konsol rapi.
3. **Menu 5 — Delete Buku:** Menampilkan katalog, meminta input indeks 1-based ($1 \le \text{idx} \le N$), menghapus data dengan pergeseran (*array shifting*), dan menampilkan pesan konfirmasi resmi: `"Data Successfully delete.."`.

---

## 🧩 Struktur Data Acuan

```c
typedef struct {
    char bookCode[10];      // Contoh: "BK001", "BK002"
    char title[100];        // Nama buku (bisa mengandung spasi)
    char category[50];      // Jenis / Kategori buku
    double price;           // Harga buku (double untuk presisi desimal)
} Book;
```

---

## 🛠️ Kontrak Antarmuka Fungsi (Function Prototypes)

```c
// 1. Menambahkan buku baru dan auto-generate kode buku
void inputNewBook(Book **books, int *bookCount, int *bookCapacity);

// 2. Menampilkan seluruh data buku dalam format tabel
void viewAllBooks(const Book *books, int bookCount);

// 3. Menghapus data buku berdasarkan indeks pilihan pengguna
void deleteBookByIndex(Book *books, int *bookCount);
```

---

## 📝 Spesifikasi Logika & Algoritma

### 1. Menu 1: Input Data Buku Baru
* **Auto-Generated Kode Buku:**
  * Sesuai ketentuan dosen: *Kode buku dibuat berdasarkan jumlah data buku yang sudah ada ditambah 1*.
  * Format: `BK%03d` (Contoh: Buku pertama `BK001`, jika sudah ada 5 buku maka buku baru mendapat `BK006`).
  * Rumus: `int newId = *bookCount + 1; sprintf(newCode, "BK%03d", newId);`
* **Input Data:**
  * Nama Buku: String (gunakan `readStringSafe` agar dapat membaca spasi).
  * Jenis Buku: String (contoh: Novel, Komputer, Ensiklopedia).
  * Harga Buku: Numerik desimal (`double`), validasi harga harus $> 0$.
* **Alokasi Kapasitas:**
  * Jika `*bookCount >= *bookCapacity`, panggil fungsi ekspansi memori (*realloc*) yang disediakan oleh Slot 4.

### 2. Menu 3: View Buku
* Cek apakah data buku kosong (`bookCount == 0`). Jika kosong, tampilkan pesan:
  `[INFO] Belum ada data buku yang tersedia.`
* Jika data ada, cetak tabel dengan format rapi menggunakan format specifier lebar:
  ```text
  +========+================================+=====================+==============+
  | KODE   | NAMA BUKU                      | JENIS               | HARGA (RP)   |
  +========+================================+=====================+==============+
  | BK001  | Dasar Pemrograman C            | Komputer            |     85000.00 |
  | BK002  | Struktur Data Lanjut           | Komputer            |    120000.00 |
  +========+================================+=====================+==============+
  ```

### 3. Menu 5: Delete Buku
* Tampilkan terlebih dahulu seluruh daftar buku beserta nomor urutnya (1 s.d. $N$).
* Minta input nomor urut yang ingin dihapus.
* **Validasi Ketat:** Pastikan input berada dalam rentang $1 \le \text{input} \le \text{bookCount}$.
  Jika salah, tampilkan pesan: `[ERROR] Indeks tidak valid! Pilih nomor antara 1 dan N.`
* **Array Shifting:**
  Geser elemen dari indeks yang dihapus ke kiri:
  ```c
  int targetIndex = inputIdx - 1; // Konversi ke 0-based
  for (int i = targetIndex; i < *bookCount - 1; i++) {
      books[i] = books[i + 1];
  }
  (*bookCount)--;
  ```
* Tampilkan pesan sukses persis sesuai teks soal:
  `Data Successfully delete..`

---

## ⚠️ Checklist Pengujian Mandiri
- [ ] Program dapat menerima nama buku yang mengandung spasi tanpa error.
- [ ] Kode buku ter-generate otomatis dengan urutan `BK001`, `BK002`, dst.
- [ ] View buku menampilkan data dalam kolom tabel yang rata dan rapi.
- [ ] Hapus data buku pada elemen pertama, tengah, dan terakhir berfungsi normal tanpa merusak sisa array.
- [ ] Input nomor hapus di luar rentang (misal 0 atau 99) ditolak secara aman dengan pesan kesalahan.
