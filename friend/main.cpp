#include <iostream>
#include <string>
using namespace std;

class Building;
class GoodGay
{
public:
    GoodGay();
    ~GoodGay();
    Building *building;
    void visit();
    void visit2();
};


class Building
{
    friend void GoodGay::visit();
public:
    string sitting_room;
    Building();
    ~Building();
private:
    string bedroom;
};
Building::Building(){
    sitting_room = "客厅";
    bedroom = "卧室";
}
Building::~Building() {
    cout << "Building对象已销毁！" << endl;
}

GoodGay::GoodGay(){
    building = new Building;
};
GoodGay::~GoodGay(){
    delete building;
    cout << "GoodGay对象已销毁！" << endl;
}
void GoodGay::visit() {
    cout << "visit1 访问公共变量：" << building->sitting_room << endl;
    cout << "visit1 访问私有变量：" << building->bedroom << endl;
}
void GoodGay::visit2() {
    cout << "visit2 访问公共变量：" << building->sitting_room << endl;
//    cout << "visit2 访问私有变量：" << building->bedroom << endl;
}

void test01(){
    GoodGay gg;
    gg.visit();
    gg.visit2();
}
int main() {
    test01();
    return 0;
}
