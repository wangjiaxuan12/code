#include <iostream>
#include <string>

class Comparison {
public:
    int Compare(int a, int b) {
        return a > b ? a : b;
    }
    
    int Compare(char a, char b) {
        return std::abs(a - b);
    }
    
    std::string Compare(const std::string& a, const std::string& b) {
        return a.length() > b.length() ? a : b;
    }
};

int main() {
    Comparison c;
    
    int int1 = 20, int2 = 25;
    std::cout << c.Compare(int1, int2) << std::endl;  
    
    char char1 = 'A', char2 = 'C';
    std::cout << c.Compare(char1, char2) << std::endl; 
    
    std::string str1 = "hello", str2 = "world";
    std::cout << c.Compare(str1, str2) << std::endl;  
    
    return 0;
}
