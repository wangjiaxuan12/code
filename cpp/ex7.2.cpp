#include <iostream>
using namespace std;

class SalesPerson {
private:
    int num;  
    int quantity; 
    double price; 
    static double discount; 
    static double sum; 
    static int n; 

public:
    SalesPerson(int num, int quantity, double price) {
        this->num = num;
        this->quantity = quantity;
        this->price = price;
        sum += price * quantity * discount; 
        n += quantity; 
    }

    static void setDiscount(double d) {
        discount = d;
    }

    static double average() {
        if (n == 0) {
            return 0;
        }
        return sum / n; 
    }

    static void display() {
        cout << "Sum: " << sum << endl;
        cout << "Average: " << average() << endl;
    }
};

double SalesPerson::discount = 1.0; 
double SalesPerson::sum = 0.0; 
int SalesPerson::n = 0; 

int main() {
    int m; 
    cin >> m; 
    int num, quantity;
    double price;
    for (int i = 0; i < m; i++) {
        cin >> num >> quantity >> price; 
        SalesPerson sp(num, quantity, price);
    }
    double discount;
    cin >> discount; 
    SalesPerson::setDiscount(discount); 
    SalesPerson::display(); 
    return 0;
}
