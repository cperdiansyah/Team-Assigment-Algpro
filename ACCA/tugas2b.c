//untuk menghanlde fungsi input output seperti scanf dan printf
#include <stdio.h>
#include <string.h>

int main(void) {
    //menyimpan  nip sebesar 19 karena pada tipe variable selalu menyimpan karakter null di akhir
    // ="" digunakan untuk menentukan array tersebut string kosong
    char nip[20] = "";
    char nama[30] = "";
    char alamat[40] = "";
    char no_HP[20] = "";
    char jabatan[20] = "";
    char golongan[5] = "";

    // inisialisasi nilai awal dari integer
    int jam_lembur = 0;
    int gaji_pokok = 0;
    int tarif_lembur = 0;
    int total_gaji = 0;

    // menampilkan ke layar
    printf("SISTEM PENGGAJIAN BULANAN PEGAWAI (TUGAS 2B)\n");

    printf("Masukkan NIP: ");
    // "19" membatasi input hanya 19 karakter
    //  [^\n] membaca semua karakter sampai bertemu newline
    // memberikan space di depan "%19" membuat ruanng kosong dari input sebelumnya
    scanf(" %19[^\n]", nip);

    printf("Masukkan Nama: ");
    scanf(" %29[^\n]", nama);

    printf("Masukkan Alamat: ");
    scanf(" %39[^\n]", alamat);

    printf("Masukkan No HP: ");
    scanf(" %19[^\n]", no_HP);

    printf("Masukkan Jabatan: ");
    scanf(" %19[^\n]", jabatan);
    
    printf("Masukkan Golongan (D1/D2/D3): ");
    scanf(" %4[^\n]", golongan);

    printf("Masukkan Jumlah Jam Lembur: ");
    scanf("%d", &jam_lembur);

    // validasi jika inputan jam lembur kurang dari 0
    if (jam_lembur < 0) {
        printf("\ntidak boleh kurang dari 0 atau minus.\n");
        return 1;
    }

    // menggunakan if selection untuk menentuka gaji pokok dan lembur dari inputan user
    // menggunakna strcasecmp untuk mengahandle huruf kecil ataupun besar (tidak strict)
    if (strcasecmp(golongan, "D1") == 0) {
        gaji_pokok = 3000000;
        tarif_lembur = 15000;
    } else if (strcasecmp(golongan, "D2") == 0) {
        gaji_pokok = 2500000;
        tarif_lembur = 10000;
    } else if (strcasecmp(golongan, "D3") == 0) {
        gaji_pokok = 2000000;
        tarif_lembur = 5000;
    } else {
        printf("\ninputan tidak valid mohon memilih D1/D2/D3 .\n", golongan);
        return 1;
    }

    // menghitung total gaji dari gaji pokok yang ditambah tarif lembur perjam dikali jam lembur
    total_gaji = gaji_pokok + (jam_lembur * tarif_lembur);


    // menampilkan nip, golongan, total jam lembur dan total gaji yang sudah dijumlahkan
    printf("\n=== OUTPUT PENGGAJIAN BULANAN ===\n");
    printf("NIP                  = %s\n", nip);
    printf("Golongan             = %s\n", golongan);
    printf("Lembur               = %d jam\n", jam_lembur);
    printf("Total Gaji Bulan Ini = Rp %d\n", total_gaji);

    return 0;
}