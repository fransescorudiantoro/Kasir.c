#include <stdio.h>

int main() {
    // Tahap Awal: Inisialisasi variabel sesuai soal
    // Stok awal = 7, Transaksi awal = 2
    int stok = 7;
    int transaksi = 2;
    
    printf("=== TAHAP AWAL ===\n");
    printf("Stok Barang: %d unit | Jumlah Transaksi: %d\n\n", stok, transaksi);

    // Tahap 1: Ada 1 transaksi penjualan baru (Transaksi bertambah, Stok berkurang)
    // Menggunakan POST-INCREMENT dan POST-DECREMENT
    stok--;        // Stok berkurang 1 karena barang terjual
    transaksi++;   // Transaksi bertambah 1 karena ada aktivitas penjualan
    
    printf("=== TAHAP 1 (Ada 1 Penjualan Barang) ===\n");
    printf("Stok Barang: %d unit | Jumlah Transaksi: %d\n\n", stok, transaksi);

    // Tahap 2: Pembatalan 1 transaksi terakhir oleh pelanggan (Transaksi berkurang, Stok kembali)
    // Menggunakan PRE-DECREMENT dan PRE-INCREMENT untuk variasi
    --transaksi;   // Jumlah transaksi dibatalkan (berkurang 1)
    ++stok;        // Barang dikembalikan ke rak (stok bertambah 1)
    
    printf("=== TAHAP 2 (1 Transaksi Dibatalkan Pelanggan) ===\n");
    printf("Stok Barang: %d unit | Jumlah Transaksi: %d\n\n", stok, transaksi);

    // Tahap 3: Toko menerima pasokan besar dari gudang pusat (Operasi Penugasan)
    // Menggunakan operasi penugasan += untuk menambah stok secara instan
    stok += 10;    // Sama saja dengan: stok = stok + 10;
    
    printf("=== TAHAP 3 (Toko Menambah Pasokan +10 Unit) ===\n");
    printf("Stok Barang: %d unit | Jumlah Transaksi: %d\n\n", stok, transaksi);

    // Tahap Akhir: Menampilkan nilai final dari kedua variabel
    printf("================ NILAI AKHIR ================\n");
    printf("Total Stok Akhir     : %d unit\n", stok);
    printf("Total Transaksi Akhir: %d kali\n", transaksi);

    return 0;
}
