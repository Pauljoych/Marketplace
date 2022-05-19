#include <iostream>
using namespace std;

class MarketPlace
{
private:
  struct ItemList
  {
    string itemName;
    float itemPrice;
  };

  int itemsListIndex = 0;
  ItemList itemsList[255];

public:
  void addItem(string _itemName, float _itemPrice)
  {
    itemsList[itemsListIndex].itemName = _itemName;
    itemsList[itemsListIndex].itemPrice = _itemPrice;
    itemsListIndex++;
  }
};