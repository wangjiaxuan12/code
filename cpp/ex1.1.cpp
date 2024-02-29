#include <iostream>
using namespace std;

int main() {
	int m, n, r;
	cin >> m >> n;
	int s = m * n;
	r = m % n;
	while (r != 0) {
		m = n;
		n = r;
		r = m % n;
	}
	cout <<"最大公约数："<< n << endl;
	cout << "最小公倍数：" << s / n << endl;
}
