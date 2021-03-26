#include <iostream>
#include <vector>

using namespace std;

class Account {    
public:
    string username;
    string password;
    double balance;

    bool operator==(const Account& lhs)
    {
        if (lhs.username == this->username && lhs.password == this->password)
            return true;
        else
            return false;
    }    
};

class Bank {       
private:
    vector<Account> _accountList;
public:             
    Bank()
    {
        Account account1;
        account1.username = "test";
        account1.password = "test";
        account1.balance = 1000;

        Account account2;
        account2.username = "hesap2";
        account2.password = "parola";
        account2.balance = 2000;

        Account account3;
        account3.username = "hesap3";
        account3.password = "1234";
        account3.balance = 3000;

        _accountList.push_back(account1);
        _accountList.push_back(account2);
        _accountList.push_back(account3);
    }

    Account FindAccount(string username , string password)
    {
        Account search;
        search.username = username;
        search.password = password;

        vector<Account>::iterator it;       

        it = find(_accountList.begin(), _accountList.end(), search);
        
        Account finded;
        /*finded.username = it->username;
        finded.password = it->password;*/

        finded = *it;

        return finded;
    }

    bool Deposit(string username, string password,double pay)
    {
        vector<Account>::iterator it;
        for (it = _accountList.begin(); it != _accountList.end(); it++)
        {
            if (username == it->username && password == it->password)
            {
                it->balance += pay;
                return true;
            }
        }
        return false;
    }

    bool Withdraw(string username, string password, double pay)
    {
        vector<Account>::iterator it;
        for (it = _accountList.begin(); it != _accountList.end(); it++)
        {
            if (username == it->username && password == it->password)
            {
                //if balance is enough
                if (it->balance >pay)
                {
                    it->balance -= pay;
                    return true;
                }                
            }
        }
        return false;
    }

    double GetBalance(string username, string password, double balance)
    {
        Account newAccount;
        newAccount.username = username;
        newAccount.password = password;
        newAccount.balance = balance;


        vector<Account>::iterator it;
        for (it = _accountList.begin(); it != _accountList.end(); it++)
        {
            if (username == it->username && password == it->password)
            {
                return false;
            }
            else
            {
                _accountList.push_back(newAccount);
                return true;
            }
        }
        return false;
    }    

    void PrintDatabase()
    {
        vector<Account>::iterator it;
        for (it = _accountList.begin(); it != _accountList.end(); it++)
        {
            cout << "\nusername : " << (*it).username;
            cout << "\npassword : " << (*it).password;
            cout << "\nbalance : " << (*it).balance;
            cout << "\n--------------------------------";
        }
    }
};

int main()
{
    Bank bank;
    bool result;

    result = bank.Deposit("test", "test",500);
    Account account = bank.FindAccount("test", "test");
    result = bank.Withdraw("test", "test", 1000);
    result = bank.GetBalance("test3", "test3", 1000);
    bank.PrintDatabase();

    cout << "";

    return 0;
}