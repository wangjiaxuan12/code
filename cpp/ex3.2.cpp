#include<iostream>
using namespace std;
class SavingsAccount
{
  int id;
  double balance;
  double rate;
  int lastDate;
  double accumulation;
  double accumulate(int date)
  {
    accumulation+=(date-lastDate)*balance;
    lastDate=date;
    return accumulation;
  }
   public:
      SavingsAccount(int date,int id,double rate)
      {
          this->id=id;
          this->rate=rate;
          lastDate=date;
      }
      void  deposit(int date,double amount)
      {
        accumulate(date);
        balance+=amount;
      }
      void withdraw(int date,double amount)
      {
        accumulate(date);
        balance-=amount;
      }
      void settle(int date)
      {
        accumulate(date);
        balance+=(accumulation/(date-1))*rate;
      }
      void show()
      {
        cout<<"id:"<<id<<endl;
        cout<<"balance:"<<balance<<endl;

      }
      int getID(){return id;}
      double getBalance(){return balance;}
      double getRate(){return rate;}
};
int main() {
    SavingsAccount s0(1, 0, 0.015);
    SavingsAccount s1(1, 1, 0.015);
    s0.deposit(6,5000);
    s0.deposit(46, 5500);
    s1.deposit(26, 10000);
    s1.withdraw(61, 4000);
    s0.settle(91);
    s1.settle(91);
    s0.show();
    s1.show();
}
