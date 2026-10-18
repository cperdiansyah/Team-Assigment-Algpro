**TEMPLATE PENGERJAAN OPERASI (TUGAS 1)**
**Nama Anggota:** Arsyan Qasthari
**NIM:** 3002924032 
**Operasi yang Dikerjakan:** Hapus Data Siswa

//Deskripsi Alur Operasi
//Operasi ini menerima masukan dari pengguna berupa nomor registrasi siswa (target_noreg) yang ingin dihapus. Sistem kemudian membuka file asli siswa.txt untuk dibaca dan membuat file sementara temp_siswa.txt untuk menyalin data yang tidak dihapus. Apabila nomor registrasi ditemukan, baris tersebut dilewati, file diperbarui menggunakan metode rename, dan sistem menampilkan pesan keberhasilan penghapusan

ALGORITHM HapusSiswa
INPUT: target_noreg (string)
OUTPUT: Pesan status keberhasilan atau kegagalan penghapusan data

BEGIN
    // 1. Tampilkan judul operasi
    DISPLAY "--- HAPUS DATA SISWA ---"

    // 2. Input data yang akan dihapus
    PROMPT "Masukkan Nomor Registrasi siswa yang akan dihapus: "
    READ target_noreg

    // 3. Operasi file (buka file asli & file sementara)
    source_file = OPEN("siswa.txt", "r")
    temp_file = OPEN("temp_siswa.txt", "w")

    IF source_file IS NULL THEN
        DISPLAY "Database siswa.txt kosong atau belum tersedia."
        CLOSE temp_file
        REMOVE("temp_siswa.txt")
        RETURN
    ENDIF

    DECLARE found = FALSE
    DECLARE buffer[256]

    // 4. Proses membaca dan menyaring data baris demi baris
    WHILE READ_LINE(source_file, buffer) DO
        // Ekstrak noreg dari buffer sebelum delimiter '|'
        EXTRACT noreg FROM buffer USING delimiter '|'

        IF noreg == target_noreg THEN
            found = TRUE
            // Baris dilewati (tidak ditulis ke temp_file)
        ELSE
            WRITE_LINE(temp_file, buffer)
        ENDIF
    ENDWHILE

    // 5. Tutup file
    CLOSE source_file
    CLOSE temp_file

    // 6. Pembaruan file fisik
    IF found == TRUE THEN
        REMOVE("siswa.txt")
        RENAME("temp_siswa.txt", "siswa.txt")
        DISPLAY "Data siswa dengan Nomor Registrasi tersebut berhasil dihapus."
    ELSE
        REMOVE("temp_siswa.txt")
        DISPLAY "Data siswa dengan Nomor Registrasi tersebut tidak ditemukan."
    ENDIF
END


//Flowchart
 Start([Mulai: Hapus Siswa]) --> Input[Input target_noreg]
    Input --> OpenFiles[Buka siswa.txt r & temp_siswa.txt w]
    OpenFiles --> CheckNull{Source File == NULL?}
    
    CheckNull -- Ya --> ErrorMsg[Tampilkan Pesan Database Kosong] --> CloseTemp[Tutup & Hapus temp_siswa.txt] --> End([Selesai])
    CheckNull -- Tidak --> SetFlag[Set found = FALSE]
    
    SetFlag --> ReadLine{Baca baris berikutnya?}
    ReadLine -- Selesai EOF --> CloseBoth[Tutup siswa.txt & temp_siswa.txt]
    
    ReadLine -- Masih ada data --> Extract[Ekstrak noreg dari baris]
    Extract --> MatchCheck{noreg == target_noreg?}
    
    MatchCheck -- Ya --> SetTrue[Set found = TRUE <br/> Lewati baris] --> ReadLine
    MatchCheck -- Tidak --> WriteTemp[Tulis baris ke temp_siswa.txt] --> ReadLine
    
    CloseBoth --> StatusCheck{found == TRUE?}
    
    StatusCheck -- Ya --> ReplaceFile[Hapus siswa.txt <br/> Rename temp_siswa.txt jadi siswa.txt] --> SuccessMsg[Tampilkan: Data berhasil dihapus] --> End
    StatusCheck -- Tidak --> DeleteTemp[Hapus temp_siswa.txt] --> NotFoundMsg[Tampilkan: Data tidak ditemukan] --> End