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
  };
  int userDataIndex = 0;
  User userData[255];

  string curentUserName;

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
          curentUserName = tempUserName;
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

    if (isUserNameAvail)
    {
      userData[userDataIndex].userId = userDataIndex;
      userData[userDataIndex].userName = tempUserName;
      userData[userDataIndex].userPassword = tempUserPassword;
      userDataIndex++;
    }

    return isUserNameAvail;
  };
};
