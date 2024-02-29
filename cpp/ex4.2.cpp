#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    char gender;
    string address;
    string phone;

public:
    void input_info() {
        cout << "姓名：";
        getline(cin, name);
        cout << "年龄：";
        cin >> age;
        while (age < 0) {
            cout << "年龄不能小于0，请重新输入：";
            cin >> age;
        }
        cout << "性别（M/F）：";
        cin >> gender;
        while (gender != 'M' && gender != 'F') {
            cout << "性别输入有误，请重新输入（M/F）：";
            cin >> gender;
        }
        cin.ignore();  // 忽略前面输入的回车
        cout << "地址：";
        getline(cin, address);
        cout << "电话：";
        getline(cin, phone);
    }
};

class Teacher : virtual public Person {
protected:
    string title;

public:
    void input_title() {
        cout << "职称：";
        getline(cin, title);
    }

    void display() {
        cout << "姓名：" << name << endl;
        cout << "年龄：" << age << endl;
        cout << "性别：" << gender << endl;
        cout << "职称：" << title << endl;
        cout << "地址：" << address << endl;
        cout << "电话：" << phone << endl;
    }
};

class Cadre : virtual public Person {
protected:
    string post;

public:
    void input_post() {
        cout << "职务：";
        getline(cin, post);
    }

    void display() {
        cout << "姓名：" << name << endl;
        cout << "年龄：" << age << endl;
        cout << "性别：" << gender << endl;
        cout << "职务：" << post << endl;
        cout << "地址：" << address << endl;
        cout << "电话：" << phone << endl;
    }
};

class Teacher_Cadre : public Teacher, public Cadre {
protected:
    double wages;

public:
    void input_wages() {
        cout << "工资：";
        cin >> wages;
    }

    void show() {
        Teacher::display();
        cout << "职务：" << Cadre::post << endl;
        cout << "工资：" << wages << endl;
    }
};

int main() {
    Teacher_Cadre tc;
    tc.input_info();
    tc.input_title();
    tc.input_post();
    tc.input_wages();
    cout << endl;
    tc.show();
    return 0;
}
