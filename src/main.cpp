#include <iostream>
#include "smartdevice.cpp"

using namespace device;
using namespace smartdevice;

int main() {
    Device tv1 = Device("Samsung", "DX7200", 45, false);

    std::cout << "tv1 - "; tv1.printObject();

    Device tv2;
    tv2 = Device(tv1);
    tv2.setModel("WR8433");

    std::cout << "tv2 - "; tv2.printObject();

    Device tv3;

    tv3 += Device("LG", "X224", 20, false) += tv2 += tv1;

    std::cout << "Display sizes:\n\ttv1: " << tv1.getDisplaySize()
        << "\n\ttv2: " << tv2.getDisplaySize()
        << "\n\ttv3: " << tv3.getDisplaySize() << "\n";

    Device phone1(tv2);
    phone1 = tv1;
    phone1.setDisplaySize(2.1);
    phone1 += phone1 += Device("Sony Ericsson", "W595", 0.1, true);
    std::cout << "phone1 - "; phone1.printObject();

    SmartDevice phone2 = SmartDevice("Samsung", "Galaxy S9", 6.2, true, "Smartphone", true);
    std::cout << "phone2 - "; phone2.printObject();
    phone2 = phone2;

    SmartDevice phone3 = phone2;
    phone3.setModel("Galaxy S10");
    std::cout << "phone3 - "; phone3.printObject();
}