
#include <stdio.h>

int main() {
    char nama_barang[50];
    int berat;
    char pilihan;
    
    // Variabel penghitung jumlah paket per kategori
    int mini = 0;
    int reguler = 0;
    int jumbo = 0;

    printf("=== APLIKASI TRANSKU CARGO ===\n\n");

    // LOGIKA PERULANGAN
    while (1) {
        printf("Jenis barang apa ini : ");
        scanf("%s", nama_barang);

        printf("Berapa berat nya (kg): ");
        scanf("%d", &berat);

        // Logika klasifikasi kategori (Menggunakan operator logika)
        int is_mini = (berat > 0) && (berat <= 3);
        int is_reguler = (berat >= 4) && (berat <= 7);
        int is_jumbo = (berat >= 8) && (berat <= 15);

        // Akumulasi paket dimasukkan ke manifes kargo
        mini += is_mini;
        reguler += is_reguler;
        jumbo += is_jumbo;

        // Tampilan status singkat di terminal Android
        if (berat > 15) {
            printf("[!] Barang ditolak (Lebih dari 15 kg)\n");
        } else {
            printf("[+] %s berhasil dicatat!\n", nama_barang);
        }

        // FITUR BARU: Konfirmasi kelanjutan input
        printf("\nApakah ada yang ingin Anda kirimkan lagi? (y/n): ");
        scanf(" %c", &pilihan); // Spasi sebelum %c penting untuk membersihkan sisa input sebelumnya
        printf("\n");

        // Jika pengguna menekan 'n' atau 'N', keluar dari perulangan
        if (pilihan == 'n' || pilihan == 'N') {
            break;
        }
    }

    // LOGIKA PERHITUNGAN (Harga & Diskon sesuai aturan soal)
    int total_mini = mini * 15000;
    int total_reguler = reguler * 28000;
    int total_jumbo = jumbo * 50000;

    // Diskon otomatis menggunakan operator logika (Clue Soal)
    double diskon_mini = total_mini * ((mini > 4) * 0.05);
    double diskon_reguler = total_reguler * ((reguler > 2) * 0.12);
    double diskon_jumbo = total_jumbo * ((jumbo > 1) * 0.18);

    double total_diskon = diskon_mini + diskon_reguler + diskon_jumbo;
    double total_bayar = (total_mini + total_reguler + total_jumbo) - total_diskon;

    // TAMPILAN NOTA AKHIR
    printf("=== RINCIAN PEMBAYARAN ===\n");
    printf("Kargo Mini   : %d paket\n", mini);
    printf("Kargo Reguler: %d paket\n", reguler);
    printf("Kargo Jumbo  : %d paket\n", jumbo);
    printf("---------------------------\n");
    printf("Total Diskon : Rp %.0f\n", total_diskon);
    printf("TOTAL BAYAR  : Rp %.0f\n", total_bayar);
    printf("===========================\n");

    return 0;
}
