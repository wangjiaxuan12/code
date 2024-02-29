#include <iostream>
using namespace std;
int a[1010];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = 1; i < n; ++i) { 
        int min_pos = i;           
        for (int j = i + 1; j <= n; ++j) { 
            if (a[j] < a[min_pos]) {       
                min_pos = j;               
            }
        }
        swap(a[i], a[min_pos]);            
    }
    
    for (int i = 1; i <= n; ++i) 
        cout << a[i] << ' ';
    return 0;
}
