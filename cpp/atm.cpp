#include <iostream>
using namespace std;
class ID{
    public:
        ID(){
            money = 0;
        }
        void revise(int x){
            if(money+x<0){
                cout << "error" << endl;
            }else{
                money += x;   
            }
            
        }
        void show(){
            cout << money << endl;
        }
    private:
        int money;
};
class ATM {
    public:
        ATM(){}
        void regist(int x){
            id = x;
            cout << id << "登录成功\n";
        }
        void show(){
            menber[id].show();
        }
        void save(int x){
            menber[id].revise(x);
        }
        void withdraw(int x){
            menber[id].revise(-x);
        }
        void exit(){
            cout << "已退出" << endl;
        }
    private:
        ID menber[10];
        int id;
};
int main(){
    ATM A;
    int id;
    cout << "请输入账号:";
    cin >> id;
    A.regist(id);
    A.show();
    A.save(100);
    A.withdraw(10);
    A.show();
    A.exit();
}
