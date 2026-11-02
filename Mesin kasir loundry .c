#include <stdio.h>

int main() {
    char nama[50]; 
    double barang = 0.0; 
    int harga_awal = 0, harga_akhir = 0;
    int pembayaran = 0; 
    
    // VARIABEL BARU: Menyimpan opsi minyak wangi (y/x) dan biaya tambahan minyak wangi
    char opsi_pewangi;
    int biaya_pewangi = 0;
    
    // Flag status untuk memastikan semua validasi sukses (0 = gagal, 1 = sukses)
    int status_validasi = 1; 

    // INPUT NAMA
    printf("Siapa nama Anda: ");
    if (scanf("%49s", nama) != 1) {
        printf("[Error] Gagal membaca input nama!\n");
        status_validasi = 0;
    }

    // 1. VALIDASI INPUT BARANG (KG)
    if (status_validasi) {
        while (1) {
            printf("Berapa kg cucian yang Anda cuci (bisa desimal): ");
            if (scanf("%lf", &barang) != 1) { 
                printf("[Error] Input harus berupa angka desimal atau bulat!\n\n");
                while (getchar() != '\n'); 
                status_validasi = 0;
                break;
            }

            if (barang > 0.0) { 
                break; 
            } else {
                printf("[Error] Input tidak valid! Berat cucian harus di atas 0 kg.\n\n");
            }
        }
    }
    
    // 2. VALIDASI INPUT OPSI MINYAK WANGI (y/x)
    if (status_validasi) {
        while (1) {
            printf("Apakah Anda ingin memakai minyak wangi? (y = Ya / x = Tidak): ");
            // Menggunakan spasi sebelum %c (" %c") untuk membersihkan sisa enter/buffer sebelumnya
            if (scanf(" %c", &opsi_pewangi) != 1) {
                printf("[Error] Gagal membaca input opsi!\n\n");
                while (getchar() != '\n');
                status_validasi = 0;
                break;
            }

            // Validasi apakah input yang dimasukkan benar-benar 'y' atau 'x'
            if (opsi_pewangi == 'y' || opsi_pewangi == 'x') {
                if (opsi_pewangi == 'y') {
                    biaya_pewangi = 3000; // Biaya tambahan minyak wangi sebesar Rp 5
                } else {
                    biaya_pewangi = 0;
                }
                break;
            } else {
                printf("[Error] Input tidak valid! Harap masukkan huruf 'y' atau 'x' kecil.\n\n");
            }
        }
    }
    
    // 3. PERHITUNGAN HARGA
    if (status_validasi) {
        harga_awal = (int)(barang * 7000); 
        // Total akhir sekarang dihitung dari harga awal ditambah biaya minyak wangi
        harga_akhir = harga_awal + biaya_pewangi;

        // Tampilkan ringkasan tagihan sementara
        printf("\nHalo %s, berikut rincian tagihan Anda:\n", nama);
        printf("- Berat Cucian                 : %.2lf kg\n", barang);
        printf("- Harga Awal                   : Rp %d\n", harga_awal);
        printf("- Biaya Minyak Wangi           : Rp %d\n", biaya_pewangi);
        printf("- Total Akhir Tagihan         : Rp %d\n", harga_akhir);
        printf("-----------------------------------------\n");
    }

    // 4. VALIDASI PEMBAYARAN
    if (status_validasi) {
        while (1) {
            printf("Masukkan nominal pembayaran Anda: Rp ");
            if (scanf("%d", &pembayaran) != 1) {
                printf("[Error] Input pembayaran harus berupa angka!\n\n");
                while (getchar() != '\n');
                status_validasi = 0;
                break;
            }
           
            if (pembayaran >= harga_akhir) { 
                break; 
            } else {
                int kurang = harga_akhir - pembayaran;
                printf("[Error] Uang Anda kurang Rp %d! Mohon bayar dengan uang pas/lebih.\n\n", kurang);
            }
        }
    }
    
    // 5. LOGIKA UTAMA: CETAK STRUK
    if (status_validasi && barang > 0.0 && harga_akhir > 0 && pembayaran >= harga_akhir) {
        
        printf("\n=========================================\n");
        printf("           STRUK BELANJA TOKO            \n");
        printf("=========================================\n");
        printf(" Nama Pelanggan : %s\n", nama);
        printf(" Jumlah Berat   : %.2lf kg\n", barang); 
        printf("-----------------------------------------\n");
        printf(" Harga Total    : Rp %d\n", harga_awal);
        
        // Menampilkan status opsi minyak wangi di struk
        if (opsi_pewangi == 'y') {
            printf(" Minyak Wangi   : Rp %d (Ya)\n", biaya_pewangi);
        } else {
            printf(" Minyak Wangi   : Rp 0 (Tidak)\n");
        }
        
        printf(" Total Tagihan  : Rp %d\n", harga_akhir);
        printf("-----------------------------------------\n");
        printf(" Pembayaran     : Rp %d\n", pembayaran);
        
        if (pembayaran > harga_akhir) {
            printf(" Kembalian      : Rp %d\n", pembayaran - harga_akhir);
        } else {
            printf(" Kembalian      : Rp 0 (Uang Pas)\n");
        }
        printf("=========================================\n");
        printf("    Terima Kasih Telah Berbelanja!       \n");
        printf("=========================================\n");
        
    } else {
        printf("\n[FATAL ERROR] Transaksi Gagal! Struk tidak dapat dicetak karena data tidak valid atau belum terisi dengan benar.\n");
    }

    return 0;
}
    
