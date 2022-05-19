#include <iostream>
#include <fstream>
#include <lib/marketplace.h>
#include <lib/userlogin.h>

using namespace std;

int main()
{
  UserLogin x;
  x.userlogin();
  
  cout << "========================\n";
  cout << "Input Nama Barang = ";
  cin >> itemName;
  cout << "Input Harga Barang = ";
  cin >> itemPrice;
  
  cout << "========================\n";
  cout << "Kurir : " << endl;
  cout << "J&T" << endl;
  cout << "SiCepat" << endl;
  cout << "AnterAja" << endl;
  cout << "========================\n";
  cout << "Input Kurir = ";
  cin >> kurirList;
  
  ofstream txt("invoice.txt");
  txt << "+-----------------------------------------------+\n";
  txt << "|\t\tBukti Pembayaran\t\t|\n";
  txt << "+-----------------------------------------------+\n";
  txt << "| Nama Pelanggan	: EKO\t\t\t|\n";
  txt << "| Alamat tujuan 	: alamat\t\t|\n";
  txt << "| Asuransi produk	: ya\t\t\t|\n";
  txt << "| Ekspedisi		: JNE\t\t\t|\n";
  txt << "+-----------------------------------------------+\n";
  txt << "| Nama barang	: alpro\t\t\t\t|\n";
  txt << "| Jumlah barang	: 0\t\t\t\t|\n";
  txt << "+-----------------------------------------------+\n";
  txt << "| Diskon	: Rp.0\t\t\t\t|\n";
  txt << "| Total bayar	: p\t\t\t\t|\n";
  txt << "+-----------------------------------------------+\n";
  txt << "|\tHarap simpan bukti pembayaran\t\t|\n";
  txt << "|\t\tTerimakasih\t\t\t|\n";
  txt << "+-----------------------------------------------+\n";
  txt.close();
}
