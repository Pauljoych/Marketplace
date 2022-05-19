#include <iostream>
using namespace std;

class UserLogin
{
private:
  struct User
  {
    int userId;
    string userName;
    int userPassword;
  };
  int userDataIndex;
  User userData[255];

public:
  void userLogin()
  {
    string tempUserName;
    int tempUsePassword;

    cout << "=================\n";
    cout << "Username : ";
    cin >> tempUserName;
    cout << "=================\n";
    cout << "Password : ";
    cin >> tempUsePassword;
    cout << "=================\n";
  };

  void userRegister()
  {
    string tempUserName;
    int tempUserPassword;
  };
};
