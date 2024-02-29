#include <iostream>

class CBuilding {
protected:
    int numFloors;
    int numRooms;
    double totalArea;
public:
    CBuilding(int nf, int nr, double ta) : numFloors(nf), numRooms(nr), totalArea(ta) {}
};

class CHousing : public CBuilding {
private:
    int numBedrooms;
    int numBathrooms;
public:
    CHousing(int nf, int nr, double ta, int nb, int nbh) : CBuilding(nf, nr, ta), numBedrooms(nb), numBathrooms(nbh) {}
    void display() {
        std::cout << "CH1\n";
        std::cout << "楼房层数：" << numFloors << std::endl;
        std::cout << "房间数：" << numRooms << std::endl;
        std::cout << "总面积：" << totalArea << std::endl;
        std::cout << "卧室数：" << numBedrooms << std::endl;
        std::cout << "浴室数：" << numBathrooms << std::endl;
    }
};

class COfficBuilding : public CBuilding {
private:
    int numExtinguishers;
    int numPhones;
public:
    COfficBuilding(int nf, int nr, double ta, int ne, int np) : CBuilding(nf, nr, ta), numExtinguishers(ne), numPhones(np) {}
    void display() {
        std::cout << "CH2\n";
        std::cout << "楼房层数：" << numFloors << std::endl;
        std::cout << "房间数：" << numRooms << std::endl;
        std::cout << "总面积：" << totalArea << std::endl;
        std::cout << "存储灭火器数：" << numExtinguishers << std::endl;
        std::cout << "电话数：" << numPhones << std::endl;
    }
};

int main() {
    CHousing ch1(5, 10, 200.5, 3, 2);
    ch1.display();
    
    COfficBuilding ch2(10, 20, 500.5, 15, 8);
    ch2.display();

    return 0;
}
