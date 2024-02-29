#include <iostream> 
using namespace std;
class Integer
{
private:
int num;
public:
Integer(int n = 0): num(n){ }
void Set(int n) { num = n; }
int Get() const { return num; }
Integer operator++() { return num + 10 ; }
Integer operator++(int) { return num + 18; }
};
int main()
{
Integer i, j;
i.Set(6);
cout << i.Get() << endl;//6
j = i;++j;
cout << j.Get() << endl;//6
j = i++;
cout << j.Get() << endl;//24
j = ++i;
cout << j.Get() << endl;//16
cout << "end" << endl;
return 0; 
}
