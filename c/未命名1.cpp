#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string a;
    cin>>a;
    transform(a.begin(),a.end(),a.begin(),::tolower);
    string b[1000000];
    int f[1000000]={0};
    int i=0;
    int count=0,begin_b=0;
    char c;
    while(i<1000000)
    {
        cin>>b[i];
        transform(b[i].begin(),b[i].end(),b[i].begin(),::tolower);
        if(a==b[i])
        {
           f[i]=1;
        }
        count+=f[i];
        if(count==1&&f[i]==1)
        {
            begin_b=i;
        }
        if((c=getchar())!='\n')
        {
            break;
        }
        i++;
    }
    if(count>0)
    {
        cout<<count<<begin_b;
        
    }
    if(count==0)
    {
        cout<<EOF;
    }
    return 0;
}