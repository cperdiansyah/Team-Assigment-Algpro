# 📓 Slot 5: Sistem Menu, Sanitasi Buffer & Integrasi HAICOLA
**PIC:** `[ ] Open Slot`  
**Tingkat Kesulitan:** Sedang (Integrasi Antarmuka Konsol, Sanitasi Input & Dokumentasi AI)  
**Bobot Nilai Soal:** 20% (Menu 6 Exit: 10% + HAICOLA AI Requirement: 10% + Peluang Bonus 10%)  

---

## 🎯 Deskripsi Tugas

Slot 5 bertanggung jawab atas pengalaman pengguna (*user experience*) di terminal dan kepatuhan terhadap regulasi etika pemanfaatan AI:
1. **Loop Menu Utama (Week 4: Selection & Repetition):** Menampilkan menu utama 1 s.d. 8 dengan tampilan estetis, rapi, dan mudah dinavigasi.
2. **Sanitasi Buffer Input (Anti-Bug Input C):** Menyediakan fungsi pembersih buffer keyboard agar program terhindar dari *newline trap* (`\n`) dan input liar.
3. **Menu 6 — Exit & Commit:** Memastikan saat user memilih tombol 6, seluruh data buku dan transaksi tersimpan rapi ke file, memori heap dibebaskan, dan program selesai.
4. **HAICOLA AI Integration & Reflection:** Menyusun dokumentasi konsultasi AI untuk debugging masalah teknis riil sesuai template formal Binus.

---

## 🛠️ Kontrak Antarmuka Fungsi (Function Prototypes)

```c
// 1. Sanitasi Buffer Keyboard
void clearInputBuffer(void);
void readStringSafe(char *dest, int maxLen);
int readIntegerSafe(const char *prompt);
double readDoubleSafe(const char *prompt);

// 2. Tampilan Header & Navigasi
void printBanner(void);
void printMainMenu(void);

// 3. Eksekusi Menu Utama
void runApplication(void);
```

---

## 📝 Spesifikasi Teknis

### 1. Helper Sanitasi Input Konsol
* **`clearInputBuffer()`:** Membuang sisa karakter `\n` dan karakter tak valid yang tertinggal di `stdin` setelah pemanggilan `scanf()`.
* **`readStringSafe(dest, maxLen)`:** Menggunakan `fgets()` dan memangkas karakter newline `\n` di ujung string agar tidak terbawa ke penyimpanan data.
* **`readIntegerSafe(prompt)` & `readDoubleSafe(prompt)`:** Memastikan input angka valid, jika user memasukkan huruf atau karakter aneh, minta input ulang tanpa membuat program looping tak berujung.

### 2. Tampilan Menu Utama
Menu utama menyajikan 8 opsi fungsional:
```text
======================================================================
               LITERASI NUSANTARA JAYA - SISTEM KASIR
======================================================================
  [1] Input Data Buku Baru
  [2] View History Transaksi Penjualan
  [3] View Buku (Seluruh Data Buku yang Tersedia)
  [4] Delete History (Hapus Histori Penjualan Tertentu)
  [5] Delete Buku (Hapus Data Buku Tertentu)
  [6] Exit (Simpan Data & Selesai)
  [7] Input Transaksi Penjualan
  [8] Sort Buku (Berdasarkan Nama & Harga)
======================================================================
Pilihan Menu [1-8]: 
```

---

## 🤖 Draf Integrasi AI (HAICOLA Framework)

Sesuai instruksi soal, mahasiswa wajib menyertakan bukti pemanfaatan AI yang relevan dengan aspek teknis:

### Kasus yang Dikonsultasikan:
**"Penanganan Newline Buffer Trap pada Input Nama Buku Setelah Scanf Integer di Bahasa C"**

1. **Potongan Kode yang Dikonsultasikan (10 Baris):**
   ```c
   printf("Masukkan Jumlah Terjual: ");
   scanf("%d", &qty);
   
   printf("Masukkan Nama Pembeli: ");
   fgets(buyerName, sizeof(buyerName), stdin);
   ```
2. **Prompt yang Diajukan ke AI:**
   > *"Mengapa ketika fungsi fgets dijalankan setelah pemanggilan scanf untuk integer, program saya langsung melompati input nama pembeli tanpa menunggu ketikan user? Bagaimana cara membersihkan buffer stdin yang benar dan aman di C99?"*
3. **Ringkasan Jawaban AI:**
   > `scanf("%d", ...)` hanya membaca karakter angka dan meninggalkan karakter newline (`\n`) yang dihasilkan tombol Enter di stream `stdin`. Saat `fgets()` berikutnya dieksekusi, ia langsung membaca karakter `\n` tersebut sebagai string kosong. Solusi standarnya adalah mengonsumsi sisa karakter di buffer hingga bertemu `\n` atau `EOF` menggunakan loop `int c; while ((c = getchar()) != '\n' && c != EOF);`.
4. **Refleksi Singkat (4–6 Kalimat Standar Binus):**
   > *Melalui konsultasi ini, kami mengidentifikasi bahwa bug skipping input disebabkan oleh karakter newline residu yang tertinggal di stream stdin setelah operasi pembacaan numerik scanf. Insight penting dari AI adalah bahwa fgets tidak menunggu input baru apabila masih terdapat karakter newline di buffer antrean. Kami segera memperbaiki kode dengan mengimplementasikan fungsi helper pembersih buffer khusus, clearInputBuffer(), setelah setiap kali pembacaan input angka dilakukan. Pembelajaran teknis yang diperoleh adalah pentingnya memahami mekanisme kerja I/O stream tingkat rendah pada bahasa C untuk mencegah perilaku undefined behavior dan memastikan program berjalan dengan stabil.*

---

## ⚠️ Checklist Pengujian Mandiri
- [ ] Pilihan menu selain angka 1 s.d. 8 ditangani dengan pesan kesalahan tanpa menyebabkan crash.
- [ ] Input string nama buku tidak terpotong atau terlewat saat diinputkan setelah angka.
- [ ] Pilihan nomor 6 (Exit) memicu penyimpanan berkas dan pembebasan memori heap secara tuntas.
- [ ] Laporan HAICOLA terisi lengkap dengan snippet kode, prompt, jawaban, dan refleksi 4–6 kalimat.
