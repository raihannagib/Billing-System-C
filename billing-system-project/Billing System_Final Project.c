#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

// program ini dibuat untuk mempermudah kasir dalam menghitung biaya yang harus dikeluarkan oleh pembeli

struct informasi {
	int totalPembelian;
	float hargaTotal;
	float hargaFinal;
	float uang;
	float totalDiskon;
	float kembalian;
};

// prototype fungsi untuk mencetak nota/struk
void headerNota (char (*namaPelanggan)[100], char (*hari)[100], char (*tanggal)[100]);
void bodiNota (int (*hargaPerItem)[100], char (*namaItem)[50][100], int (*jumlahPembelian)[100], int (*bonus)[100]);
void keuanganNota (struct informasi *perhitungan);
void jamTransaksi ();
void infoDiskon ();

int main () {
	system ("COLOR 70"); 
	
	struct informasi data; // struct untuk menampung variabel yang mewakili bagian keuangan

	data.totalPembelian = 0;
	data.hargaTotal = 0;
	data.hargaFinal = 0;
	data.uang = 0;
	data.totalDiskon = 0;
	
	// inisialisasi variabel untuk input daftar menu dan informasi umum pada transaksi
	int i, k;
	int daftarMenu = 0;
	int pilihanMenu = 0;
	char kodeItem[5];
	char hari[100];
	char tanggal[100];
	char namaPelanggan[100];
	
	// inisialisasi variabel untuk membuat login sistem
	int j = 0;
	char username[20];
	char password[20];
	char ch;

	// inisialisasi variabel untuk input informasi khusus mengenai transaksi
	char namaItem[50][100] = {0};
	int jumlahPembelian[100] = {0};
	int hargaPerItem[100] = {0};
	int bonus[100] = {0};

	// login sistem dengan menggunakan string comparison sebagai pembanding input dengan data yang ada	
	printf ("\t\t\t====== TOKO MAKMUR BILLING MACHINE ======\n\n");
	printf ("Login System\n");
	printf ("Masukkan username	: ");
	gets (username);
	printf ("Masukkan password	: ");
	while (1) {
		ch = getch();
		if (ch == 13) {
			password[j] = '\0';
			break;
		} else {
			password[j] = ch;
			j++;
			printf ("*");
		}
	}

	if (strcmp (username, "tokomakmur") == 0) {
		if (strcmp (password, "murahmeriah") == 0) { // jika username dan password benar
			printf ("\nLogin berhasil...\n");
			printf ("Loading...\n");
			sleep(3);
			system ("cls");

			printf ("\n\n\n\n\n\n\n\n\n\n\n");
			printf ("\t\t\t\t\t==============================================\n");
			printf ("\t\t\t\t\t==============================================\n");
			printf ("\t\t\t\t\t==============================================\n");
			printf ("\t\t\t\t\t================ TOKO MAKMUR =================\n");
			printf ("\t\t\t\t\t==============================================\n");
			printf ("\t\t\t\t\t==============================================\n");
			printf ("\t\t\t\t\t==============================================\n");

			for (k = 1; k <= 3; k++) {
				system ("COLOR 21");
				system ("COLOR 32");
				system ("COLOR 43");
				system ("COLOR 54");
				system ("COLOR 65");
				system ("COLOR 76");
				system ("COLOR 70");
			}

			system ("cls");

			printf ("\t\t\t======Selamat Datang di Program Billing System TOKO MAKMUR======\n\n\n");

			while (1) {
				daftarMenu :
				printf ("Berikut ini daftar menu yang bisa Anda pilih :\n");
				printf ("1. Perhitungan Bill\n");
				printf ("2. Info Diskon\n");
				printf ("3. Keluar\n");

				printf ("Pilih menu yang Anda inginkan : ");
				pilihanMenu = scanf ("%d", &daftarMenu);
				
				// error handling input char/string
				while (pilihanMenu != 1) {
					printf ("\n  >> Input tidak valid, silahkan memilih kembali!\n\n");
					scanf ("%*[^\n]");
					printf ("Berikut ini daftar menu yang bisa Anda pilih :\n");
					printf ("1. Perhitungan Bill\n");
					printf ("2. Info Diskon\n");
					printf ("3. Keluar\n");

					printf ("Pilih menu yang Anda inginkan : ");
					pilihanMenu = scanf ("%d", &daftarMenu);
				}

				// error handling input selain angka 1, 2, atau 3
				while (daftarMenu < 1 || daftarMenu > 3) {
					printf ("\n  >> Input tidak valid, silakan memilih kembali!\n\n");
					scanf ("%*[^\n]");
					printf ("Berikut ini daftar menu yang bisa Anda pilih :\n");
					printf ("1. Perhitungan Bill\n");
					printf ("2. Info Diskon\n");
					printf ("3. Keluar\n");

					printf ("Pilih menu yang Anda inginkan : ");
					pilihanMenu = scanf ("%d", &daftarMenu);
				}
				
				// penyeleksian kondisi jika dipilih menu input = 1
				if (daftarMenu == 1) {
					printf ("\n\nBerikut ini merupakan list barang yang dijual :\n");

					// daftar produk yang dijual
					printf ("----------------------------------------------------------------------\n");
					printf ("Kode Item \t Nama Item \t\t\t\t Harga\n");
					printf ("----------------------------------------------------------------------\n");
					
					printf ("   1. \t\t Beras Fortune (1 kg)			Rp 11.000,00\n");
					printf ("   2. \t\t Minyak Goreng Bimoli (1 liter)		Rp 11.500,00\n");
					printf ("   3. \t\t Telur (1 kg)  				Rp 20.000,00\n");
					printf ("   4. \t\t Tahu (1 bungkus 10 potong) 		Rp 7.500,00\n");
					printf ("   5. \t\t Tempe (1 bungkus 10 potong)		Rp 9.500,00\n");
					printf ("   6. \t\t Daging Sapi (1 kg) 	 		Rp 45.000,00\n");
					printf ("   7. \t\t Daging Ayam (1 kg)			Rp 19.000,00\n");
					printf ("   8. \t\t Gula Rose Brand (1 kg)			Rp 15.000,00\n");
					printf ("   9. \t\t Garam Dolpin (1 kg) 			Rp 10.000,00\n");
					printf ("   10. \t\t Indomie/pcs  				Rp 2.500,00\n");
					printf ("   11. \t\t Gas LPG 3 kg/tabung  			Rp 20.000,00\n");
					printf ("   12. \t\t Gas LPG 9 kg/tabung  			Rp 95.000,00\n");
					printf ("   13. \t\t Gas LPG 12 kg/tabung  			Rp 126.000,00\n");
					printf ("   14. \t\t Gas LPG 14 kg/tabung 			Rp 148.000,00\n");
					printf ("   15. \t\t Tepung Terigu Sania (1kg)		Rp 10.000,00\n");
					printf ("   16. \t\t Tepung Maizena Maizenaku (1kg) 	Rp 26.000,00\n");
					printf ("   17. \t\t Tepung Beras Rose Brand (1kg)		Rp 15.000,00\n");
					printf ("   18. \t\t Tepung Tapioka Cap Bambu (1kg) 	Rp 10.000,00\n");

					printf ("----------------------------------------------------------------------\n\n");

					// panduan pemberian input untuk item yang dibeli oleh pembeli
					printf ("\t\t\tPANDUAN BELANJA\n\n");
					printf ("1. Ketik 0 untuk berhenti berbelanja\n");
					printf ("2. Untuk pembelian produk tertentu, masukkan kode barang seperti yang ada di atas\n");
					printf ("3. Jika input kode barang selain 1-18, maka input tersebut akan diabaikan\n");
					printf ("4. Jika input jumlah pembelian barang sebanyak 0 atau kurang, maka input tersebut akan diabaikan\n\n");
					
					// input hari transaksi
					printf ("Hari\t\t: ");
					scanf (" %255[^\n]s", &hari);
					fflush(stdin);

					// input tanggal transaksi
					printf ("Tanggal\t\t: ");
					scanf (" %255[^\n]s", &tanggal);
					fflush(stdin);
					
					// input nama pelanggan (dapat berupa inisial, misal pelanggan 1, pelanggan 2, dst.) sebagai data riwayat pembelian
					printf ("Nama pelanggan\t: ");
					scanf (" %255[^\n]s", &namaPelanggan);
					fflush(stdin);

					printf ("------------------------------------------------------------------\n");
					printf ("Kode Item \t Nama item \t\t Jumlah pembelian\n");
					printf ("------------------------------------------------------------------\n");

					for (i = 1; i != 0; i++) {

						printf ("    ");
						fgets (kodeItem, 5, stdin); // meminta input kode item

						// bagian penentuan diskon dari total belanja
						if (strcmp (kodeItem, "1\n") == 0) { 
							printf (" \t\t Beras Fortune \t\t\t"); // mencetak nama item untuk kode item tertentu
							strcpy (namaItem[i], "Beras Fortune"); // copy nama item untuk digunakan saat mencetak nota/struk
							scanf ("%d", &jumlahPembelian[i]);
							getchar(); // membuat enter sebagai sebuah input juga agar program dapat berfungsi dengan baik

							if (jumlahPembelian[i] <= 0) { // error handling jika input jumlah pembelian item 0 atau kurang, sekaligus error handling char/string input
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							// mengupdate nilai pada variabel totalPembelian, hargaPerItem, dan hargaTotal (sebelum ada diskon)
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 11000;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "2\n") == 0) {
							printf (" \t\t Minyak Goreng Bimoli \t\t");
							strcpy (namaItem[i], "Minyak Goreng Bimoli");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 11500;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "3\n") == 0) {
							printf (" \t\t Telur \t\t\t\t");
							strcpy (namaItem[i], "Telur");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 20000;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "4\n") == 0) {
							printf (" \t\t Tahu \t\t\t\t");
							strcpy (namaItem[i], "Tahu");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 7500;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "5\n") == 0) {
							printf (" \t\t Tempe \t\t\t\t");
							strcpy (namaItem[i], "Tempe");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 9500;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "6\n") == 0) {
							printf (" \t\t Daging Sapi \t\t\t");
							strcpy (namaItem[i], "Daging Sapi");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 45000;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "7\n") == 0) {
							printf (" \t\t Daging Ayam \t\t\t");
							strcpy (namaItem[i], "Daging Ayam");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 19000;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "8\n") == 0) {
							printf (" \t\t Gula Rose Brand \t\t");
							strcpy (namaItem[i], "Gula Rose Brand");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 15000;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "9\n") == 0) {
							printf (" \t\t Garam Dolpin \t\t\t");
							strcpy (namaItem[i], "Garam Dolpin");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 10000;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "10\n") == 0) {
							printf (" \t\t Indomie \t\t\t");
							strcpy (namaItem[i], "Indomie");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");

							// mengupdate nilai pada variabel bonus ketika jumlah pembelian Indomie sebanyak 5 atau lebih untuk menunjang fitur beli 5 gratis 1
							if (jumlahPembelian[i] >= 5) {
								bonus[i] = floor(jumlahPembelian[i]/5);
							}

							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 2500;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "11\n") == 0) {
							printf (" \t\t Gas LPG 3 kg \t\t\t");
							strcpy (namaItem[i], "Gas LPG 3 kg");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 20000;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "12\n") == 0) {
							printf (" \t\t Gas LPG 9 kg \t\t\t");
							strcpy (namaItem[i], "Gas LPG 9 kg");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 95000;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "13\n") == 0) {
							printf (" \t\t Gas LPG 12 kg \t\t\t");
							strcpy (namaItem[i], "Gas LPG 12 kg");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 126000;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "14\n") == 0) {
							printf (" \t\t Gas LPG 14 kg \t\t\t");
							strcpy (namaItem[i], "Gas LPG 14 kg");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 148000;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "15\n") == 0) {
							printf (" \t\t Tepung Terigu Sania \t\t");
							strcpy (namaItem[i], "Tepung Terigu Sania");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 10000;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "16\n") == 0) {
							printf (" \t\t Tepung Maizena Maizenaku \t");
							strcpy (namaItem[i], "Tepung Maizena Maizenaku");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 26000;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "17\n") == 0) {
							printf (" \t\t Tepung Beras Rose Brand \t");
							strcpy (namaItem[i], "Tepung Beras Rose Brand");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 15000;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "18\n") == 0) {
							printf (" \t\t Tepung Tapioka Cap Bambu \t");
							strcpy (namaItem[i], "Tepung Tapioka Cap Bambu");
							scanf ("%d", &jumlahPembelian[i]);
							getchar();

							if (jumlahPembelian[i] <= 0) {
								printf ("\t\t====== Input tidak valid ======\n");
								printf ("------------------------------------------------------------------\n");
								jumlahPembelian[i] = 0;
								continue;
							}

							printf ("------------------------------------------------------------------\n");
							data.totalPembelian += jumlahPembelian[i];
							hargaPerItem[i] = jumlahPembelian[i] * 10000;
							data.hargaTotal += hargaPerItem[i];
						}

						else if (strcmp (kodeItem, "0\n") == 0) { // penyeleksian kondisi untuk memberhentikan proses meminta input data pembelian
							printf ("\t\t================ END ================\n");
							printf ("------------------------------------------------------------------\n");
							i = -1;
						}

						else { // error handling ketika input selain angka 0-18 dan juga error handling char/string input
							printf ("\t\t====== Input tidak valid ======\n");
							printf ("------------------------------------------------------------------\n");
						}
					}

					
					printf("\n\nBanyak Barang \t\t: %d\n", data.totalPembelian); // mencetak total barang yang dibeli
					printf("Total Harga	\t: Rp %.2f\n", data.hargaTotal); // mencetak harga total sebelum diberi diskon

					for (i = 0; i <= 29; i++) { // mencetak jumlah bonus Indomie yang didapatkan oleh pembeli
						if (bonus[i] > 0) {
							printf ("Bonus Indomie \t\t: %d pcs\n", bonus[i]);
						}
					}
					
					// penyeleksia kondisi untuk semua kemungkinan diskon yang bisa didapat oleh pembeli
					if (data.hargaTotal < 100000) { // penyeleksian kondisi ketika hargaTotal sebesar sekian (kurang dari Rp 100.000)
						printf ("Diskon \t\t\t: -\n");
						if (strcmp (hari, "Senin") == 0 || strcmp (hari, "senin") == 0) { // penyeleksian kondisi ketika transaksi dilakukan di hari senin
							data.hargaFinal =  0.975 * data.hargaTotal; // mengupdate variabel harga final yang harus dibayar oleh pembeli
							data.totalDiskon = 2.5; // mengupdate variabel total diskon yang yang didapat oleh pembeli
							printf ("Diskon hari Senin \t: 2,5 persen\n"); // mencetak total diskon yang didapat oleh pembeli
							printf ("Total Tagihan \t\t: Rp %.2f\n", data.hargaFinal); // mencetak harga final yang harus dibayarkan oleh pembeli
						} 
						
						else {
							data.hargaFinal = data.hargaTotal;
							data.totalDiskon = 0.0;
							printf ("Total Tagihan \t\t: Rp %.2f\n", data.hargaFinal);
						}
					}

					else if (data.hargaTotal >= 100000 && data.hargaTotal <= 249999) {
						printf ("Diskon \t\t\t: 2,5 persen\n");
						if (strcmp (hari, "Senin" ) == 0 || strcmp (hari, "senin") == 0) {
							data.hargaFinal = 0.95 * data.hargaTotal;
							data.totalDiskon = 5.0;
							printf ("Diskon hari Senin \t: 2,5 persen\n");
							printf ("Total Tagihan \t\t: Rp %.2f\n", data.hargaFinal);
						} 
						
						else {
							data.hargaFinal = 0.975 * data.hargaTotal;
							data.totalDiskon = 2.5;
							printf ("Total Tagihan \t\t: Rp %.2f\n", data.hargaFinal);
						}
					}

					else if (data.hargaTotal >= 250000 && data.hargaTotal <= 499999) {
						printf ("Diskon \t\t\t: 5 persen\n");
						if (strcmp (hari, "Senin") == 0 || strcmp (hari, "senin") == 0) {
							data.hargaFinal = 0.925 * data.hargaTotal;
							data.totalDiskon = 7.5;
							printf ("Diskon hari Senin \t: 2,5 persen\n");
							printf ("Total Tagihan \t\t: Rp %.2f\n", data.hargaFinal);
						} 
						
						else {
							data.hargaFinal = 0.95 * data.hargaTotal;
							data.totalDiskon = 5.0;
							printf ("Total Tagihan \t\t: Rp %.2f\n", data.hargaFinal);
						}
					}

					else {
						printf ("Diskon \t\t\t: 10 persen\n");
						if (strcmp (hari, "Senin" ) == 0 || strcmp (hari, "senin") == 0) {
							data.hargaFinal = 0.875 * data.hargaTotal;
							data.totalDiskon = 12.5;
							printf ("Diskon hari Senin \t: 2,5 persen\n");
							printf ("Total Tagihan \t\t: Rp %.2f\n", data.hargaFinal);
						} 
						
						else {
							data.hargaFinal = 0.9 * data.hargaTotal;
							data.totalDiskon = 10.0;
							printf ("Total Tagihan \t\t: Rp %.2f\n", data.hargaFinal);
						}
					}
					
					// menerima input nilai uang yang diberikan oleh pembeli
					errorHandling : 
					printf("Uang Yang Diterima \t: Rp ");
					scanf("%f", &data.uang);

					if (data.uang < data.hargaFinal) { // error handling ketika uang tidak cukup (misal ketika salah ketik atau kesalahan lainnya)
						printf("Uang yang diterima kurang.\n");
						goto errorHandling;
					}

					data.kembalian = data.uang - data.hargaFinal;

					printf("Kembalian \t\t: %.2f\n", data.kembalian); // mencetak nilai kembalian yang dari proses transaksi

					// PRINT NOTA
					headerNota (&namaPelanggan, &hari, &tanggal);

					bodiNota (&hargaPerItem, &namaItem, &jumlahPembelian, &bonus);

					keuanganNota (&data);
				}
	
				// penyeleksian kondisi jika dipilih menu input = 2
				else if (daftarMenu == 2) {
					system ("cls");
					infoDiskon ();
					goto daftarMenu;
				}
				
				// penyeleksian kondisi jika dipilih menu input = 2
				else if (daftarMenu == 3) {
					system ("cls");
					printf ("\nTerima kasih telah menggunakan program ini");
					exit(0);
				}
			}
		}


		else { // jika username benar dan password salah
			printf ("\nLoading...\n");
			sleep (3);
			printf ("Password yang Anda masukkan salah\n");
			sleep (1);
			system ("cls");
			main ();
		}
	}

	else { // jika username dan password salah
		printf ("\nLoading...\n");
		sleep(3);
		printf ("Username atau password yang Anda masukkan salah\n");
		sleep(1);
		system ("cls");
		main ();
	}

	getch();

	system ("pause");

	return 0;
}

void infoDiskon () { // mencetak info diskon dan bonus yang sedang tersedia pada Toko Makmur
	printf("\n=====INFO DISKON UNTUK PEMBELI=====\n\n");
	printf (">>> Diskon 2,5 persen untuk pembelian di hari Senin\n");
	printf (">>> Beli 5 Indomie gratis 1\n");
	printf (">>> Total pembelian hingga Rp 100.000,00 akan mendapatkan diskon sebesar 2,5 persen\n");
	printf (">>> Total pembelian hingga Rp 250.000,00 akan mendapatkan diskon sebesar 5 persen\n");
	printf (">>> Total pembelian di atas Rp 500.000,00 akan mendapatkan diskon sebesar 10 persen\n\n\n");
}

void headerNota (char (*namaPelanggan)[100], char (*hari)[100], char (*tanggal)[100]) {
	// mencetak header dari  nota/struk
	printf ("\n\n\n\t\t\t-------------------------------\n");
	printf ("\t\t\t========= TOKO MAKMUR =========\n");
	printf ("\t\t\t-------------------------------\n\n");
	printf ("JL. BASUKI RAHMAT NO.20\n");
	printf ("\t DEPOK, 68202\n\n");
	printf ("Nama \t\t\t: %s\n", *namaPelanggan);
	printf ("Hari, Tanggal \t\t: %s, %s\n", *hari, *tanggal);
	jamTransaksi ();
	printf ("---------------------------------------------------------------\n");
	printf ("     Item \t\t       Jumlah\t\t Total\n");
	printf ("---------------------------------------------------------------\n");
}

void bodiNota (int (*hargaPerItem)[100], char (*namaItem)[50][100], int (*jumlahPembelian)[100], int (*bonus)[100]) {
	int i;
	// mencetak bodi/isi dari nota
	for (i = 1; i <= 50; i++) {
		if ((*hargaPerItem)[i] != 0) { // penyeleksian kondisi dimana yang dicetak hanya jika nilai hargaPerItem != 0 (sebelumnya variabel hargaPerItem dideklarasikan sama dengan 0 untuk semua indeks)
			if (strcmp ((*namaItem)[i], "Beras Fortune") == 0) {
				printf ("%s \t\t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Minyak Goreng Bimoli") == 0) {
				printf ("%s \t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Telur") == 0) {
				printf ("%s \t\t\t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Tahu") == 0) {
				printf ("%s \t\t\t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Tempe") == 0) {
				printf ("%s \t\t\t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Daging Sapi") == 0) {
				printf ("%s \t\t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Daging Ayam") == 0) {
				printf ("%s \t\t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Gula Rose Brand") == 0) {
				printf ("%s \t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Garam Dolpin") == 0) {
				printf ("%s \t\t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Indomie") == 0) {
				if (bonus[i] > 0) {
					printf ("%s \t\t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i] + (*bonus)[i], (*hargaPerItem)[i]); // khusus indomie, nilai jumlahPembelian akan ditambah dengan jumlah bonus
				}
				else {
					printf ("%s \t\t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
				}
				
			}

			else if (strcmp ((*namaItem)[i], "Gas LPG 3 kg") == 0) {
				printf ("%s \t\t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Gas LPG 9 kg") == 0) {
				printf ("%s \t\t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Gas LPG 12 kg") == 0) {
				printf ("%s \t\t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Gas LPG 14 kg") == 0) {
				printf ("%s \t\t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Tepung Terigu Sania") == 0) {
				printf ("%s \t\t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Tepung Maizena Maizenaku") == 0) {
				printf ("%s \t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Tepung Beras Rose Brand") == 0) {
				printf ("%s \t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}

			else if (strcmp ((*namaItem)[i], "Tepung Tapioka Cap Bambu") == 0) {
				printf ("%s \t %d \t\t %d\n", (*namaItem)[i], (*jumlahPembelian)[i], (*hargaPerItem)[i]);
			}
		}
	}
}

void keuanganNota (struct informasi *perhitungan) { // parameter fungsi adalah semua variabel pada struct informasi
	// mencetak bagian keuangan dari nota/struk
	printf ("---------------------------------------------------------------\n");

	printf ("Sub Total \t\t\t\t\t %.2f\n", perhitungan->hargaTotal);
	printf ("Diskon Total \t\t\t\t\t %.2f persen\n", perhitungan->totalDiskon);
	printf ("Total Tagihan \t\t\t\t\t %.2f\n", perhitungan->hargaFinal);
	printf ("Pajak \t\t\t\t\t\t -\n");
	printf ("Uang Pemberian \t\t\t\t\t %.2f\n", perhitungan->uang);
	printf ("Kembalian \t\t\t\t\t %.2f\n", perhitungan->kembalian);

	printf ("---------------------------------------------------------------\n\n\n");

	printf ("\t Terima kasih telah belanja di toko kami\n");
	printf ("\t\t Have a Nice Day!:)\n\n");

	printf (" WA : 08123456789	HP : 08123456789	Ig : @toko_makmur\n\n\n");
}

void jamTransaksi () { // fungsi untuk mengakses waktu real time pada sistem komputer
	int jam, menit, detik;

	time_t sekarang;

	time (&sekarang);

	struct tm *local = localtime(&sekarang);

	jam = local->tm_hour;
	menit = local->tm_min;
	detik = local->tm_sec;

	printf ("Jam Transaksi \t\t: %02d:%02d:%02d\n", jam, menit, detik);
}
