#include<iostream>
using namespace std;
class Person
{
 int id;
 string name;
 public:
    Person(){}
    Person(int id,string name)
    {
      this->id=id;
      this->name=name;
    }
    ~Person(){}
    void display(){
        cout<<"name:"<<name<<endl;
        cout<<"id:"<<id<<endl;
    }
};
class CollegeStu:public Person
{
   double score;
   string major;
      public:
      CollegeStu(){}
      CollegeStu(int id,string name,double score,string major):Person(id,name)
      {
        this->major=major;
        this->score=score;
      }
      ~CollegeStu(){
	  }
      void display(){
        Person::display();
        cout<<"C++'s score:"<<score<<endl;
        cout<<"major:"<<major<<endl;
      }
};
int main(){
    CollegeStu Cstu1(13,"wjx",200,"ai");
    Cstu1.display();
    return 0; 
}
