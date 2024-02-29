#include <iostream>
#include <cmath>
using namespace std;

class CSolid {
public:
    virtual double getArea() const = 0; // 纯虚函数，求表面积
    virtual double getVolume() const = 0; // 纯虚函数，求体积
};

class CCube : public CSolid {
private:
    double m_edge; // 正方体的棱长
public:
    CCube(double edge) : m_edge(edge) {}
    double getArea() const {
        return 6 * m_edge * m_edge;
    }
    double getVolume() const {
        return m_edge * m_edge * m_edge;
    }
};

class CBall : public CSolid {
private:
    double m_radius; // 球体的半径
public:
    CBall(double radius) : m_radius(radius) {}
    double getArea() const {
        return 4 * M_PI * m_radius * m_radius;
    }
    double getVolume() const {
        return 4 * M_PI * m_radius * m_radius * m_radius / 3;
    }
};

class CCylinder : public CSolid {
private:
    double m_radius; // 圆柱体的底面半径
    double m_height; // 圆柱体的高
public:
    CCylinder(double radius, double height) : m_radius(radius), m_height(height) {}
    double getArea() const {
        return 2 * M_PI * m_radius * m_height + 2 * M_PI * m_radius * m_radius;
    }
    double getVolume() const {
        return M_PI * m_radius * m_radius * m_height;
    }
};

int main() {
    CCube cube(2);
    CBall ball(3);
    CCylinder cylinder(2, 4);
    CSolid *p;

    p = &cube;
    cout << "正方体表面积：" << p->getArea() << "，体积：" << p->getVolume() << endl;

    p = &ball;
    cout << "球体表面积：" << p->getArea() << "，体积：" << p->getVolume() << endl;

    p = &cylinder;
    cout << "圆柱体表面积：" << p->getArea() << "，体积：" << p->getVolume() << endl;

    return 0;
}
