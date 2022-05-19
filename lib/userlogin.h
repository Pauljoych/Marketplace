#include <iostream>
using namespace std;

class UserLogin
{
private:
  string name;
  int nim;
public:
  void login(){
    cout << "=================\n";
    cout << "User = ";
    cin >> name;
    cout << "=================\n";
    cout << "Password = ";
    cin >> nim;
    cout << "=================\n";
};
