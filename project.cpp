#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

typedef struct
{
	string jenis;
	char ukuran;
	float harga;

}susu;

typedef struct
{
	int no_penjualan;
	string jenis;
	char ukuran;
	float harga;
	int qty;
	float discount;
	float total;

}penjualan;

susu data_susu[100];
penjualan data_penjualan[100];
int jml_data_susu = 0;
int jml_data_penjualan = 0;

void menu()
{
	cout<<"\033[2J\033[1;1H";
	cout<<"===============================\n";
	cout<<"Aplikasi Penjualan Susu\n";
	cout<<"===============================\n";
	cout<<"1. Input Penjualan\n";
	cout<<"2. Tampil Penjualan\n";
	cout<<"3. Cek Penjualan\n";
	cout<<"4. Urutkan Penjualan\n";
	cout<<"5. Export\n";
	cout<<"6. Import\n";
}

int searchHarga(string jenis, char ukuran)
{

	data_susu[0].jenis = "Dancow";
	data_susu[0].ukuran = 'B';
	data_susu[0].harga = 25000;

	data_susu[1].jenis = "Dancow";
	data_susu[1].ukuran = 'S';
	data_susu[1].harga = 20000;

	data_susu[2].jenis = "Dancow";
	data_susu[2].ukuran = 'K';
	data_susu[2].harga = 15000;

	data_susu[3].jenis = "Bendera";
	data_susu[3].ukuran = 'B';
	data_susu[3].harga = 20000;

	data_susu[4].jenisa = "Bendera";
	data_susu[4].ukuran = 'S';
	data_susu[4].harga = 17500;

	data_susu[5].jenis = "Bendera";
	data_susu[5].ukuran = 'K';
	data_susu[5].harga = 13500;

	data_susu[6].jenis = "SGM";
	data_susu[6].ukuran = 'B';
	data_susu[6].harga = 22000;

	data_susu[7].jenis = "SGM";
	data_susu[7].ukuran = 'S';s
	data_susu[7].harga = 18500;

	data_susu[8].jenis = "SGM";
	data_susu[8].ukuran = 'K';
	data_susu[8].harga = 15000;

	int i = 0;
	while(i < 9){
		if(jenis == data_susu[i].jenis && ukuran == data_susu[i].ukuran) return data_susu[i].harga;
		i++;
	}
}

int cekDiscount(int qty, char ukuran, float harga)
{
	float total_discount = 0;

	if(qty > 10 && ukuran == 'B' || ukuran == 'S'){
		// 10%
		total_discount = 0;
		return total_discount;
	}

	else if(qty > 5 && ukuran == 'B'){
		// 5%
		total_discount = 0; 
		return total_discount;
	}

	else if(qty > 10 && ukuran == 'K'){
		// 2%
		total_discount = 0;
		return total_discount;
	}
	else{
		return total_discount;
	}
}

void input_penjualan()
{
	char tambah_lagi = 'y';
	int a = jml_data_penjualan;
	do
	{
		cout<<"\033[2J\033[1;1H";
		cout<<"INPUT PENJUALAN\n";
		cout<<"No Penjualan : ";cin>>data_penjualan[a].no_penjualan;
		cout<<"Jenis : "; cin>>data_penjualan[a].jenis;
		cout<<"Ukuran (B/K/S) : "; cin>>data_penjualan[a].ukuran;
		cout<<"Qty : "; cin>>data_penjualan[a].qty;

		// Cek Harga
		data_penjualan[a].harga = searchHarga(data_penjualan[a].jenis, data_penjualan[a].ukuran);
		cout<<"Harga : Rp. "<<data_penjualan[a].harga<<endl;
		
		// Cek Discount
		data_penjualan[a].discount = cekDiscount(data_penjualan[a].qty, data_penjualan[a].ukuran, data_penjualan[a].harga);
		cout<<data_penjualan[a].discount;
		cout<<"Discount : Rp. "<<data_penjualan[a].discount<<endl;


		data_penjualan[a].total = data_penjualan[a].harga * data_penjualan[a].qty - data_penjualan[a].discount;


		cout<<"\nTotal : Rp. "<<data_penjualan[a].total<<endl;
		 
		
		cout<<"\nData Berhasil Ditambahkan\n";
		a++;
		cout<<"\nTambah Lagi (y/n) : "; cin>>tambah_lagi;
		
	}
 	while(tambah_lagi == 'y' || tambah_lagi == 'Y');
	jml_data_penjualan += a;
}

void tampil_penjualan()
{
	cout<<"\033[2J\033[1;1H";
	cout<<"NO_PENJUALAN\tJENIS\tUKURAN\tQTY\tDISCOUNT\tTOTAL\n";
	for(int a = 0; a < jml_data_penjualan; a++)
	{
		cout<<data_penjualan[a].no_penjualan<<"\t";
		cout<<data_penjualan[a].jenis<<"\t";
		cout<<data_penjualan[a].ukuran<<"\t";
		cout<<data_penjualan[a].qty<<"\t";
		cout<<data_penjualan[a].discount<<"\t";
		cout<<data_penjualan[a].total<<"\t\n";
		cout<<endl;
	}

	
}

int searchDataPenjualan(int no_penjualan)
{
	int i = 0;
	while(i < jml_data_penjualan){
		if(no_penjualan == data_penjualan[i].no_penjualan) return i;
		i++;
	}
}

void cari_penjualan()
{
	int index;
	int no_penjualan;
	cout<<"\033[2J\033[1;1H";
	cout<<"CARI DATA PENJUALAN\n";
	cout<<"Masukan Nomor Penjualan : "; cin>>no_penjualan;
	cout<<endl;
	index = searchDataPenjualan(no_penjualan);

	
		cout<<"NO_PENJUALAN\tJENIS\tUKURAN\tQTY\tDISCOUNT\tTOTAL\n";
		cout<<data_penjualan[index].no_penjualan<<"\t";
		cout<<data_penjualan[index].jenis<<"\t";
		cout<<data_penjualan[index].ukuran<<"\t";
		cout<<data_penjualan[index].qty<<"\t";
		cout<<data_penjualan[index].discount<<"\t";
		cout<<data_penjualan[index].total<<"\t\n";
	
}

void urutkan_penjualan()
{
	int by;
	cout<<"\033[2J\033[1;1H";
	cout<<"Urutkan Penjualan\n";
	cout<<"1. Total Terbesar - Terkecil\n";
	cout<<"2. Total Terkecil - Terbesar\n";
	cout<<"3. Qty Terbesar - Terkecil\n";
	cout<<"4. Qty Terkecil - Terbesar\n";
	cout<<"Urutkan Berdasarkan : "; cin>>by;
}

int main()
{
	int pilihMenu;
	char backToMenu = 'y';

	do
	{
		menu();
		cout<<"Pilih menu (1-7) : "; cin>>pilihMenu;

		switch(pilihMenu)
		{
			case 1 : input_penjualan(); break;
			case 2 : tampil_penjualan(); break;
			case 3 : cari_penjualan(); break;
			case 4 : urutkan_penjualan(); break;
			// case 5 : export_data(); break;
			// case 5 : import_data(); break;
			default : cout<<"\nKeyword yang anda masukan salah!\n";
		}
		cout<<"Kembali ke menu (y/n) : "; cin>>backToMenu;
	}
	while(backToMenu == 'Y' || backToMenu == 'y');

}

 