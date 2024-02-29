#include<bits/stdc++.h>
#define  ll long long
#define endl "\n"
using namespace std;

int main (){
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '|'&& i!=s.length()-1){
            cout << "\n代码:";
            i++;
        }else if (s[i]>='0' && s[i]<='9'&&i<s.length()) {
            while (s[i]>='0' && s[i]<='9'){
                cout << s[i];
                i++;
            }
            cout << "名称:";
        }else {
            while(!(s[i]>='0' && s[i]<='9') && !(s[i] == '|') && i<s.length()){
                cout << s[i];
                i++;
            }
            if(i != s.length()-1)
            i--;
        }
    }
    return 0;
}