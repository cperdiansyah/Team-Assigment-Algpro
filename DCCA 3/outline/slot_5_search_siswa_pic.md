# 📝 PANDUAN KERJA SLOT 5: SOAL 3A, 3B & KOMPILASI DOKUMEN (PIC)
**Penanggung Jawab (PIC):** Chandra Perdiansyah  
**NIM:** 3002887011  
**Modul:** Soal 3A (Pseudo Code File & Search), Soal 3B (Implementasi C Linear Search + Array of Struct), dan Final Merge / Kompilasi Laporan  
**Bobot Bagian:** 20% + Tugas Integrasi Sistem  

---

## 🎯 Target Deliverables PIC

1. **Soal 3A (Pseudo code & Flowchart File Handling + Linear Search):**  
   - Merancang alur pembacaan data teks berformat `[Nama] [Umur] [Nomor_Registrasi]` dari `siswa.txt`.
   - Mengalokasikan array of struct untuk menampung rekod di memori.
   - Merancang alur pencarian nama siswa dengan validasi jika tidak ditemukan.
2. **Soal 3B (Implementasi Program C):**  
   - Menulis kode C yang bersih dan lolos kompilasi tanpa warning (`src/search_siswa.c`).
   - Menyediakan data sampel representatif di `src/siswa.txt`.
3. **Kompilasi Laporan Akhir:**  
   - Mengumpulkan seluruh draf dari Slot 1, Slot 2, Slot 3, dan Slot 4.
   - Melakukan cross-check dan memastikan format laporan akhir (`docs/JAWABAN_TK3.md`) siap disalin ke berkas resmi Word / SharePoint kelompok.

---

## ✍️ RANGKUMAN PENGERJAAN SLOT 5

### 1. Pseudo Code Pembacaan File & Linear Search (Soal 3A)
```text
ALGORITHM PencarianDataSiswa
    INPUT:
        File "siswa.txt", string kata kunci (queryNama)
    OUTPUT:
        Detail profil siswa atau notifikasi data tidak ditemukan

BEGIN
    DEFINE STRUCT Siswa (nama, umur, no_reg)
    DECLARE ARRAY daftarSiswa[100] OF Siswa
    DECLARE totalSiswa = 0
    DECLARE FILE fp

    // 1. Membaca file fisik
    OPEN fp = fopen("siswa.txt", "r")
    IF fp IS NULL THEN
        PRINT "Galat: File siswa.txt tidak ditemukan!"
        EXIT PROGRAM
    ENDIF

    WHILE totalSiswa < 100 AND fscanf(fp) BERHASIL DO
        totalSiswa = totalSiswa + 1
    ENDWHILE
    CLOSE fp

    // 2. Input pengguna
    PROMPT "Masukkan nama siswa yang dicari: "
    READ queryNama

    // 3. Pencarian Linear
    foundIndex = -1
    FOR i = 0 TO totalSiswa - 1 DO
        IF strcmp(daftarSiswa[i].nama, queryNama) == 0 THEN
            foundIndex = i
            BREAK
        ENDIF
    ENDFOR

    // 4. Validasi hasil
    IF foundIndex != -1 THEN
        PRINT "Data Ditemukan: " + daftarSiswa[foundIndex].nama
    ELSE
        PRINT "Validasi: Maaf, siswa tidak terdaftar dalam database."
    ENDIF
END
```

### 2. Status Implementasi Kode C & Data Fisik (Soal 3B)
- [x] Kode program C telah dibuat di [`../src/search_siswa.c`](../src/search_siswa.c).
- [x] Basis data contoh telah dibuat di [`../src/siswa.txt`](../src/siswa.txt).
- [x] Telah diuji kompilasi dengan GCC 15.2.0 (`gcc -Wall -Wextra -std=c11 search_siswa.c`).
- [x] Telah diuji skenario *validasi sukses* (`Citra`) dan *validasi gagal* (`Zul`).


### 3. Integrasi & Review Laporan
Sebagai koordinator tim, PIC akan mengompilasi draf jawaban dari Slot 1, Slot 2, Slot 3, dan Slot 4 ke dalam template dokumen resmi laporan Word/SharePoint kelompok setelah semua anggota mengumpulkan tugasnya.

