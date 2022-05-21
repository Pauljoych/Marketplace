#include <iostream>
#include <iomanip>
#include <fstream>
#include <lib/marketplace.h>
#include <lib/userlogin.h>

using namespace std;

template <typename T>
string printElement(T t, const int &width)
{
  return left << setw(width) << t;
}

int main()
{
  struct Cart;
  struct ItemList;

  UserLogin login;
  MarketPlace market;

  market.addItem("Mouse", 10000);
  market.addItem("Keyboard", 10000);

back_to_buy:

  int tempOrder;
  cout << "====================" << endl;
  cout << "1) Selesai" << endl;
  for (int i = 0; i < market.itemsListIndex; i++)
  {
    cout << i + 2 << ") " << market.itemsList[i].itemName << " " << market.itemsList[i].itemPrice << endl;
  }
  cin >> tempOrder;
  market.setOrderItemById(tempOrder - 2);

  if (tempOrder != 1)
  {
    cout << "\x1B[2J\x1B[H";
    goto back_to_buy;
  }

  cout << "====================" << endl;
  cout << "Input Alamat Pengirim : ";
  getline(cin, market.userAddress);

  int tempKurirId;
  cout << "====================" << endl;
  cout << "Kurir : " << endl;
  cout << "1) J&T" << endl;
  cout << "2) SiCepat" << endl;
  cout << "3) AnterAja" << endl;
  cout << "====================" << endl;
  cout << "Input Kurir : ";
  cin >> tempKurirId;
  market.setKurirById(tempKurirId - 1);

  int tempAsuransi;
  bool tempAsutasiBool = false;
  cout << "====================" << endl;
  cout << "Asuransi : " << endl;
  cout << "1) Ya" << endl;
  cout << "2) Tidak" << endl;
  cout << "====================" << endl;
  cout << "Input : ";
  cin >> tempAsuransi;
  if (tempAsuransi == 1)
  {
    tempAsutasiBool = true;
  }
  market.setKurirProtection(tempAsutasiBool);

  ofstream txt("invoice.txt");
  txt << "========================================" << endl;
  txt << printElement("Cart Invoice", 40) << endl;
  txt << "========================================" << endl;
  txt << printElement("Nama Pelanggan	:", 20);
  txt << printElement(login.curentUserName, 20) << endl;
  txt << printElement("Alamat tujuan	:", 20);
  txt << printElement(market.userAddress, 20) << endl;
  txt << "========================================" << endl;
  string tempAsuransiString = "Tidak";
  if (market.getKurisProtection())
  {
    tempAsuransiString = "Ya";
  }
  txt << printElement("Asuransi	:", 20);
  txt << printElement(tempAsuransiString, 20) << endl;
  txt << printElement("Ekspedisi	:", 20);
  txt << printElement(market.getKurir(), 20) << endl;
  txt << "========================================" << endl;

  txt << printElement("Nama barang", 20);
  txt << printElement("Harga", 20) << endl;
  txt << "----------------------------------------" << endl;
  for (int i = 0; i < market.userChartIndex; i++)
  {
    txt << printElement(market.userCart[i].itemName, 20);
    txt << printElement(market.userCart[i].itemPrice, 20) << endl;
  }
  txt << "========================================" << endl;
  txt << printElement("Diskon :", 20);
  txt << printElement(market.getDiscount(), 20) << endl;

  txt << printElement("Total Bayar :", 20);
  txt << printElement(market.getCartTotal() - market.getDiscount(), 20) << endl;
  txt << "========================================" << endl;

  txt.close();
}