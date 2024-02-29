#include <iostream>

using namespace std;

template <typename T>
class Complex {
private:
    T real_;
    T imag_;
public:
    Complex(T real=0, T imag=0): real_(real), imag_(imag) {}
    
    Complex operator+(const Complex& other) const {
        return Complex(real_ + other.real_, imag_ + other.imag_);
    }
    
    Complex operator-(const Complex& other) const {
        return Complex(real_ - other.real_, imag_ - other.imag_);
    }
    
    Complex operator*(const Complex& other) const {
        return Complex(real_ * other.real_ - imag_ * other.imag_, 
                       real_ * other.imag_ + imag_ * other.real_);
    }
    
    Complex operator/(const Complex& other) const {
        T denominator = other.real_ * other.real_ + other.imag_ * other.imag_;
        return Complex((real_ * other.real_ + imag_ * other.imag_)/denominator, 
                       (imag_ * other.real_ - real_ * other.imag_)/denominator);
    }
    
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real_;
        if(c.imag_ > 0) {
            out << "+" << c.imag_ << "i";
        } else if(c.imag_ < 0) {
            out << "-" << -c.imag_ << "i";
        }
        return out;
    }
    
    friend istream& operator>>(istream& in, Complex& c) {
        char ch;
        in >> c.real_ >> ch;
        if(ch == 'i') {
            c.imag_ = 1;
        } else {
            in >> c.imag_ >> ch;
        }
        if(ch == '-') {
            c.imag_ = -c.imag_;
        }
        return in;
    }
};

int main() {
    Complex<double> c1, c2, c3;
    cout << "c1: " << endl;;
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
