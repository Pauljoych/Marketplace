#include <iostream>
#include <string>
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
  bool userLogin()
  {
    bool isRegister = false;
    string tempUserName;
    int tempUserPassword;

    cout << "Username : ";
    getline(cin, tempUserName);
    cout << "Password : ";
    cin >> tempUserPassword;

    for (int i = 0; i < userDataIndex; i++)
    {
      if (userData[i].userName == tempUserName)
      {
        if (userData[i].userPassword == tempUserPassword)
        {
          isRegister = true;
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

    cout << "Username : ";
    getline(cin, tempUserName);
    cout << "Password : ";
    cin >> tempUserPassword;

    for (int i = 0; i < userDataIndex; i++)
    {
      if (userData[userDataIndex].userName == tempUserName)
      {
        isUserNameAvail = false;
      }
    }

    return isUserNameAvail;
  };
};
