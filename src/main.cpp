#include <iostream>
#include "device.cpp"
//#include "smartdevice.cpp"

using namespace device;
//using namespace smart_device;

int main() {
    Device tv1 = Device("Samsung", "DX7200", 45, false);

    std::cout << "tv1 - ";
    tv1.printInfo();

    Device tv2;
    tv2 = Device(tv1);
    // OR Device tv2 = Device(tv1);

    std::cout << "tv2 - "; tv2.printInfo();
    tv2.setModel("WR8433");
    std::cout << "tv2 - "; tv2.printInfo();
    std::cout << "tv1 model is: " << tv1.getModel() << "\n";
}