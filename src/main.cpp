#include <iostream>
#include "device.cpp"

using namespace device;

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
    phone1.setDisplaySize(6.7);

    phone1 += phone1 += Device("Apple", "iPhone 13 Pro Max", 1.0, true);

    std::cout << "phone1 - "; phone1.printObject();

    Device phone2 = phone1;
    phone2.setModel("iPhone 11 Pro");
    phone2.setDisplaySize(5.85);
    std::cout << "phone2 - "; phone2.printObject();

    phone2 = phone2;
}