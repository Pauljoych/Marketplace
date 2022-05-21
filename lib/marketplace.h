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

  int voucherListIndex;
  float redeemVoucher;
  Voucher voucherList[255];

  int itemsListIndex;
  ItemList itemsList[255];

  int userChartIndex;
  Cart userCart[255];

  int userKurirId;
  bool userKurirProtection;
  string kurirList[3];

  string userName;
  string userAddress;

  void init()
  {
    voucherListIndex = 0;
    redeemVoucher = 0.0;
    itemsListIndex = 0;
    userChartIndex = 0;
    userKurirId = 0;
    userKurirProtection = false;
    kurirList[0] = "J&T";
    kurirList[1] = "SiCepat";
    kurirList[2] = "AnterAja";
  }

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

  void redeemVoucherToken(int token)
  {
    bool isValid = false;

    for (int i = 0; i < voucherListIndex; i++)
    {
      if (voucherList[i].voucherToken == token)
      {
        isValid = true;
        redeemVoucher += voucherList[i].voucherDiscount;
      }
    }
  }
};