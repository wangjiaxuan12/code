 
#include <fstream>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
 
class Student
{
public:
    Student(){};
    Student(int n, string nam, double c, double m, double e):num(n),name(nam),cpp(c),math(m),english(e){total=c+m+e;}
    void set_value(int n,string nam, double c, double m, double e);
    string get_name(){return name;}
    double get_cpp(){return cpp;}
    double get_math(){return math;}
    double get_english(){return english;}
    double get_total(){return total;}
    void set_cpp(double c){cpp=c;}
    void set_math(double m){math=m;}
    void set_english(double e){english=e;}
    void set_total(double t){total=t;}
    friend  ostream& operator<<(ostream&, Student&);
private:
    int num;
    string name;
    double cpp;
    double math;
    double english;
    double total;
};
 
void Student::set_value(int n,string nam, double c, double m, double e)
{
    num=n;
    name=nam;
    cpp=c;
    math=m;
    english=e;
    total=c+m+e;
}
 
ostream& operator<<(ostream& out, Student& s)
{
    out<<s.num<<" "<<s.name<<" "<<s.cpp<<" "<<s.math<<" "<<s.english<<" "<<s.total<<endl;
    return out;
}
 
int main( )
{
    Student stud[100]; 
    int i,n;
    string sname;
    double scpp, smath, senglish;

    ifstream infile("score.dat",ios::in); 
    if(!infile) 
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(i=0;i<100;i++)
    {
        infile>>n>>sname>>scpp>>smath>>senglish;
        stud[i].set_value(n,sname, scpp, smath, senglish);
    }
    infile.close();

    ofstream outfile("binary_score.dat",ios::out|ios::binary);
    if(!outfile)
    {
        cerr<<"error!"<<endl;
        exit(1);
    }
    for(i=0;i<100;i++)
    {
        outfile.write((char*)&stud[i], sizeof(stud[i]));
    }

    cout<<"输入信息：";
    cin>>n>>sname>>scpp>>smath>>senglish;
    Student me(n,sname, scpp, smath, senglish);
    outfile.write((char*)&me, sizeof(me));
    outfile.close();

    Student s;
    ifstream infile2("binary_score.dat",ios::in|ios::binary);
    if(!infile2)
    {
        cerr<<"error!"<<endl;
        exit(1);
    }
    while(true)
    {
        infile2.read((char*)&s, sizeof(s));
        if(infile2.eof()) break;
        cout<<s;
    }
    infile2.close();
 
    return 0;
}
