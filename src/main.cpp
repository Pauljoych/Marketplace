#include <iostream>
#include <fstream>
#include <lib/marketplace.h>
#include <lib/userlogin.h>

using namespace std;

int main()
{
  cout << "========================\n";
  cout << "Input User Name = ";
  getline(cin, tempUserName);
	
  cout << "========================\n";
  cout << "Input Banyak Barang Yang Ingin Dibeli = ";
  cin >> banyak;
  for(int i=1; i>=banyak; i++){
      cout << "========================\n";
      cout << "Input Nama Barang = ";
      cin >> itemName;
      cout << "Input Harga Barang = ";
      cin >> itemPrice;	
  }

  cout << "========================\n";
  cout << "Kurir : " << endl;
  cout << "J&T" << endl;
  cout << "SiCepat" << endl;
  cout << "AnterAja" << endl;
  cout << "========================\n";
  cout << "Input Kurir = ";
  cin >> list;
  if(list==1){
  	kurirList="J&T";
  }
  else if(list==2){
	kurirList="SiCepat";
  }
  else if(list==3){
	kurirList="AnterAja";
  }else{
	kurirList="-";
  }
  
  ofstream txt("invoice.txt");
  txt << "+-----------------------------------------------+\n";
  txt << "|\t\tBukti Pembayaran\t\t|\n";
  txt << "+-----------------------------------------------+\n";
  txt << "| Nama Pelanggan	: "<<tempUserName;<<"\t\t\t|\n";
  txt << "| Alamat tujuan 	: "<<userAddress<<"\t\t|\n";
  if(userKurirProtection==false){
  	userKurirProtection="Tidak";
  }
  else{
  	userKurirProtection="Ya";
  }
  txt << "| Asuransi produk	: "<<userKurirProtection<<"\t\t\t|\n";
  txt << "| Ekspedisi		: "<<kurirList<<"\t\t\t|\n";
  txt << "+-----------------------------------------------+\n";
  txt << "| Nama barang	: "<<itemName<<"\t\t\t\t|\n";
  txt << "| Jumlah barang	: "<<itemsListIndex<<"\t\t\t\t|\n";
  txt << "+-----------------------------------------------+\n";
  txt << "| Diskon	: Rp.0\t\t\t\t|\n";
  txt << "| Total bayar	: p\t\t\t\t|\n";
  txt << "+-----------------------------------------------+\n";
  txt << "|\tHarap simpan bukti pembayaran\t\t|\n";
  txt << "|\t\tTerimakasih\t\t\t|\n";
  txt << "+-----------------------------------------------+\n";
  txt.close();
}

