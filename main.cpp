#include <iostream>
#include <iomanip>
#include <fstream>
#include "lib/marketplace.h"
#include "lib/userlogin.h"

using namespace std;

template <typename T>
ostream &printElement(ostream &out, T t, const int &width)
{
  out << left << setw(width) << t;
  return out;
};

int main()
{
  struct Cart;
  struct ItemList;

  /* SCRIPT INIT */
  UserLogin login;
  MarketPlace market;

  login.init();
  market.init();

  market.addItem("Mouse", 100000);
  market.addItem("Keyboard", 500000);
  market.addItem("Dashcam", 500000);
  market.addItem("Webcam", 500000);
  market.setVoucherList(9090, 0.5);
  /* SCRIPT INIT */

  bool registerSuccess = login.userRegister();

back_to_login:

  bool loginSuccess = login.userLogin();
  if (!loginSuccess)
  {
    cout << "Username atau Password salah!" << endl;
    goto back_to_login;
  }

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
    goto back_to_buy;
  }

  cout << "====================" << endl;
  cout << "Input Alamat Pengirim : ";
  cin >> market.userAddress;

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

  int voucherToken;
  cout << "====================" << endl;
  cout << "Masukan Token Voucher Jika Tidak Ada 0" << endl;
  cout << "Voucher Token : ";
  cin >> voucherToken;
  market.redeemVoucherToken(voucherToken);

  ofstream txt("invoice.txt");
  txt << "========================================" << endl;
  printElement(txt, "Cart Invoice", 40) << endl;
  txt << "========================================" << endl;
  printElement(txt, "Nama Pelanggan", 20);
  printElement(txt, login.curentUserName, 20) << endl;
  printElement(txt, "Alamat Tujuan", 20);
  printElement(txt, market.userAddress, 20) << endl;
  txt << "========================================" << endl;
  string tempAsuransiString = "Tidak";
  if (market.getKurisProtection())
  {
    tempAsuransiString = "Ya";
  }
  printElement(txt, "Asuransi", 20);
  printElement(txt, tempAsuransiString, 20) << endl;
  printElement(txt, "Ekspedisi", 20);
  printElement(txt, market.getKurir(), 20) << endl;
  txt << "========================================" << endl;

  printElement(txt, "Nama barang", 20);
  printElement(txt, "Harga", 20) << endl;
  txt << "----------------------------------------" << endl;
  for (int i = 0; i < market.userChartIndex - 1; i++)
  {
    printElement(txt, market.userCart[i].itemName, 20);
    printElement(txt, market.userCart[i].itemPrice, 20) << endl;
  }
  txt << "========================================" << endl;
  printElement(txt, "Diskon", 20);
  printElement(txt, market.getDiscount(), 20) << endl;
  printElement(txt, "Ongkir", 20);
  printElement(txt, market.getOngkir(), 20) << endl;

  printElement(txt, "Total Bayar", 20);
  printElement(txt, market.getCartTotal() - market.getDiscount() + market.getOngkir(), 20) << endl;
  printElement(txt, "Saldo Akhir", 20);
  printElement(txt, login.currentBalance - (market.getCartTotal() - market.getDiscount() + market.getOngkir()), 20) << endl;
  txt << "========================================" << endl;

  txt.close();
}