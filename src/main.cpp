#include <iostream>
#include "device.cpp"
//#include "smartdevice.cpp"

using namespace device;
//using namespace smart_device;

int main() {
    Device tv1 = Device("Samsung", "DX7200", 45, false);

    std::cout << "tv1 - ";
    tv1.printObject();

    /*
    Device tv2; // NOT POSSIBLE DUE TO DISABLED EMPTY CONSTRUCTOR
    tv2 = Device(tv1);
    */

    /* ^ */ Device tv2 = Device(tv1);

    std::cout << "tv2 - "; tv2.printObject();
    tv2.setModel("WR8433");
    std::cout << "tv2 - "; tv2.printObject();
    std::cout << "tv1 model is: " << tv1.getModel() << "\n";

    /*
    Device phone1; // NOT POSSIBLE DUE TO DISABLED EMPTY CONSTRUCTOR
    phone1 = tv2;
    */

    /* ^ */ Device phone1(tv2);
    phone1 = Device(tv1);

    phone1.setManufacturer("Apple");
    phone1.setModel("iPhone 13 Pro Max");
    phone1.setDisplaySize(6.7);
    phone1.setMobile(true);
    std::cout << "phone1 - "; phone1.printObject();

    Device phone2 = Device(phone1);
    phone2.setModel("iPhone 11 Pro");
    phone2.setDisplaySize(5.85);
    std::cout << "phone2 - "; phone2.printObject();
}