#include <iostream>

using namespace std;

class Complex {
private:
    double real;  // 复数的实部
    double imag;  // 复数的虚部

public:
    // 构造函数
    Complex(double real = 0.0, double imag = 0.0) : real(real), imag(imag) {}

    // 重载运算符+
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 重载运算符-
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // 重载运算符*
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // 重载运算符/
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    // 友元函数重载运算符<<
    friend ostream& operator<<(ostream& os, const Complex& c) {
        if (c.imag >= 0) {
            os << c.real << "+" << c.imag << "i";
        } else {
            os << c.real << c.imag << "i";
        }
        return os;
    }

    // 友元函数重载运算符>>
    friend istream& operator>>(istream& is, Complex& c) {
        cout << "请输入复数的实部：";
        is >> c.real;
        cout << "请输入复数的虚部：";
        is >> c.imag;
        return is;
    }
};

int main() {
    Complex c1, c2, c3;
    cout << "c1: " << endl;
    cin >> c1;
    cout << "c2: " << endl;
    cin >> c2;
    cout << "c1=" << c1 << endl;
    cout << "c2=" << c2 << endl;
    c3 = c1 + c2;
    cout << "c1+c2=" << c3 << endl;
    c3 = c1 - c2;
    cout << "c1-c2=" << c3 << endl;
    c3 = c1 * c2;
    cout << "c1*c2=" << c3 << endl;
    c3 = c1 / c2;
    cout << "c1/c2=" << c3 << endl;
    return 0;
}
