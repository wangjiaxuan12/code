#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    Point(int x, int y) : x(x), y(y) {}
    Point() : x(0), y(0) {}
    ~Point() {}

    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    int getX() const { return x; }
    int getY() const { return y; }

private:
    int x;
    int y;
};

class Circle : public Point {
public:
    Circle(int x, int y, int radius) : Point(x, y), radius(radius) {}
    Circle() : Point(), radius(0) {}
    ~Circle() {}

    friend ostream& operator<<(ostream& os, const Circle& c) {
        os << "圆心" << static_cast<const Point&>(c) << "，半径" << c.radius;
        return os;
    }

    int getRadius() const { return radius; }

    bool operator>(const Circle& other) const {
        return calculateArea() > other.calculateArea();
    }

    bool operator<(const Circle& other) const {
        return calculateArea() < other.calculateArea();
    }

    bool operator>=(const Circle& other) const {
        return calculateArea() >= other.calculateArea();
    }

    bool operator<=(const Circle& other) const {
        return calculateArea() <= other.calculateArea();
    }

    bool operator==(const Circle& other) const {
        return calculateArea() == other.calculateArea();
    }

    bool operator!=(const Circle& other) const {
        return calculateArea() != other.calculateArea();
    }

private:
    int radius;

    double calculateArea() const {
        return M_PI * radius * radius;
    }
};

int locate(const Point& p, const Circle& c) {
    int distanceSquare = (p.getX() - c.getX()) * (p.getX() - c.getX()) +
                         (p.getY() - c.getY()) * (p.getY() - c.getY());
    int radiusSquare = c.getRadius() * c.getRadius();
    if (distanceSquare < radiusSquare) {
        return -1; // 圆内
    } else if (distanceSquare == radiusSquare) {
        return 0; // 圆上
    } else {
        return 1; // 圆外
    }
}

int main( )
{
Circle c1(3,2,4),c2(4,5,5); //c2 应该大于 c1
Point p1(1,1),p2(3,-2),p3(7,3); //分别位于 c1 内、上、外
cout<<"圆 c1: "<<c1;
cout<<"点 p1: "<<p1;
cout<<"点 p1 在圆 c1 之"<<((locate(p1, c1)>0)?"外":((locate(p1, c1)<0)?" 内":"上"))<<endl;
cout<<"点 p2: "<<p2;
cout<<"点 p2 在圆 c1 之"<<((locate(p2, c1)>0)?"外":((locate(p2, c1)<0)?" 内":"上"))<<endl;
cout<<"点 p3: "<<p3;
cout<<"点 p3 在圆 c1 之"<<((locate(p3, c1)>0)?"外":((locate(p3, c1)<0)?" 内":"上"))<<endl;
cout<<endl;
cout<<"圆 c1: "<<c1;
if(c1>c2) cout<<"大于"<<endl;
if(c1<c2) cout<<"小于"<<endl;
if(c1>=c2) cout<<"大于等于"<<endl;
if(c1<=c2) cout<<"小于等于"<<endl;
if(c1==c2) cout<<"等于"<<endl;
if(c1!=c2) cout<<"不等于"<<endl;
cout<<"圆 c2: "<<c1;
cout<<endl;
return 0;
}