#include <iostream>
using namespace std;

class MarketPlace
{
private:
public:
  struct ItemList
  {
    string itemName;
    float itemPrice;
  };

  struct Cart
  {
    string itemName;
    int itemPrice;
  };

  struct Voucher
  {
    int voucherToken;
    float voucherDiscount;
  };

  int voucherListIndex = 0;
  float redeemVoucher = 0.0;
  Voucher voucherList[255];

  int itemsListIndex = 0;
  ItemList itemsList[255];

  int userChartIndex = 0;
  Cart userCart[255];

  int userKurirId = 0;
  bool userKurirProtection = false;
  string kurirList[3] = {"J&T", "SiCepat", "AnterAja"};

  string userName;
  string userAddress;

  ItemList *getItemlist()
  {
    return itemsList;
  }

  Cart *getUserCart()
  {
    return userCart;
  }

  string *getKurisList()
  {
    return kurirList;
  }

  string getKurir()
  {
    return kurirList[userKurirId];
  }

  bool getKurisProtection()
  {
    return userKurirProtection;
  }

  float getCartTotal()
  {
    float tempTotal = 0;
    for (int i = 0; i < userChartIndex; i++)
    {
      tempTotal += userCart[i].itemPrice;
    }

    return tempTotal;
  }

  float getDiscount()
  {
    return getCartTotal() * redeemVoucher;
  }

  void addItem(string _itemName, float _itemPrice)
  {
    itemsList[itemsListIndex].itemName = _itemName;
    itemsList[itemsListIndex].itemPrice = _itemPrice;
    itemsListIndex++;
  }

  void setVoucherList(int token, float discount)
  {
    voucherList[voucherListIndex].voucherToken = token;
    voucherList[voucherListIndex].voucherDiscount = discount;
    voucherListIndex++;
  }

  void setKurirProtection(bool kurirProtection)
  {
    userKurirProtection = kurirProtection;
  }

  void setOrderItemById(int itemId)
  {
    userCart[userChartIndex].itemName = itemsList[itemId].itemName;
    userCart[userChartIndex].itemPrice = itemsList[itemId].itemPrice;
    userChartIndex++;
  }

  void setKurirById(int kurirId)
  {
    userKurirId = kurirId;
  }
};