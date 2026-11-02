#include <stdio.h>
#include <math.h>

int main() {
    int kode_menu;
    float waktu_masuk, waktu_keluar;
    int jam_masuk, menit_masuk, jam_keluar, menit_keluar;
    int total_menit_masuk, total_menit_keluar, selisih_menit;
    int lama_parkir_bulat;
    int total_biaya = 0;
    char pilihan;

    printf("=== SISTEM PARKIR WISATA MALIOBORO ===\n\n");

    while (1) {
        // 1. Pilih jenis kendaraan
        printf("Pilih Kendaraan (1:Motor, 2:Mobil, 3:Bus): ");
        scanf("%d", &kode_menu);

        // 2. INPUT WAKTU (Hanya 2 kali input menggunakan format desimal titik)
        printf("Masukkan Waktu Masuk (contoh 09.15) : ");
        scanf("%f", &waktu_masuk);

        printf("Masukkan Waktu Keluar (contoh 12.45): ");
        scanf("%f", &waktu_keluar);

        // 3. Memisahkan Jam dan Menit dari nilai input desimal
        jam_masuk = (int)waktu_masuk;
        menit_masuk = (int)((waktu_masuk - jam_masuk) * 100 + 0.5);

        jam_keluar = (int)waktu_keluar;
        menit_keluar = (int)((waktu_keluar - jam_keluar) * 100 + 0.5);

        // 4. Hitung durasi total menit dan bulatkan ke atas dalam satuan jam
        total_menit_masuk = (jam_masuk * 60) + menit_masuk;
        total_menit_keluar = (jam_keluar * 60) + menit_keluar;
        selisih_menit = total_menit_keluar - total_menit_masuk;

        // Pembulatan ke atas (jika ada sisa menit, dihitung 1 jam penuh)
        lama_parkir_bulat = ceil((double)selisih_menit / 60.0);

        // 5. Perhitungan Tarif Menggunakan switch-case
        switch (kode_menu) {
            case 1: // Motor
                if (lama_parkir_bulat <= 1) total_biaya = 2000;
                else total_biaya = 2000 + ((lama_parkir_bulat - 1) * 1000);
                break;

            case 2: // Mobil
                if (lama_parkir_bulat <= 1) total_biaya = 5000;
                else total_biaya = 5000 + ((lama_parkir_bulat - 1) * 3000);
                break;

            case 3: // Bus Pariwisata
                if (lama_parkir_bulat <= 2) total_biaya = 15000;
                else total_biaya = 15000 + ((lama_parkir_bulat - 2) * 5000);
                break;

            default:
                total_biaya = 0;
                lama_parkir_bulat = 0;
                break;
        }

        // 6. LANGSUNG MEMUNCUKKAN HASIL NOMINAL
        printf("\n>>> HASIL PERHITUNGAN <<<\n");
        printf("Lama Parkir : %d jam (dibulatkan)\n", lama_parkir_bulat);
        printf("TOTAL BIAYA : Rp %d\n", total_biaya);
        printf("======================================\n");

        // Konfirmasi untuk mengulang perulangan
        printf("Ada data pengunjung lain? (y/n): ");
        scanf(" %c", &pilihan);
        printf("\n");

        if (pilihan == 'n' || pilihan == 'N') {
            break;
        }
    }

    return 0;
}
