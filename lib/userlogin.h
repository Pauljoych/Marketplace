#include <iostream>
#include <string>
using namespace std;

class UserLogin
{
private:
public:
  struct User
  {
    int userId;
    string userName;
    int userPassword;
    int userBalance;
  };

  int userDataIndex;
  User userData[255];

  string curentUserName;
  int currentBalance;

  void init()
  {
    currentBalance = 0;
    userDataIndex = 0;
  }

  bool userLogin()
  {
    bool isRegister = false;
    string tempUserName;
    int tempUserPassword;

    cout << "Login" << endl;
    cout << "====================" << endl;
    cout << "Username : ";
    cin >> tempUserName;
    cout << "Password : ";
    cin >> tempUserPassword;

    for (int i = 0; i < userDataIndex; i++)
    {
      if (userData[i].userName == tempUserName)
      {
        if (userData[i].userPassword == tempUserPassword)
        {
          isRegister = true;
          curentUserName = tempUserName;
          currentBalance = userData[i].userBalance;
        }
      }
    }

    return isRegister;
  };

  bool userRegister()
  {
    bool isUserNameAvail = true;
    string tempUserName;
    int tempUserPassword;
    int tempBalance;

    cout << "Register" << endl;
    cout << "====================" << endl;
    cout << "Username : ";
    cin >> tempUserName;
    cout << "Password : ";
    cin >> tempUserPassword;
    cout << "Saldo Awal : ";
    cin >> tempBalance;

    for (int i = 0; i < userDataIndex; i++)
    {
      if (userData[userDataIndex].userName == tempUserName)
      {
        isUserNameAvail = false;
      }
    }

    if (isUserNameAvail)
    {
      userData[userDataIndex].userId = userDataIndex;
      userData[userDataIndex].userName = tempUserName;
      userData[userDataIndex].userPassword = tempUserPassword;
      userData[userDataIndex].userBalance = tempBalance;
      userDataIndex++;
    }

    return isUserNameAvail;
  };
};
