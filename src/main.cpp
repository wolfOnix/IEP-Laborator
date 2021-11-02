#include <iostream>
#include "device.cpp"
//#include "smartdevice.cpp"

using namespace device;
//using namespace smart_device;

int main() {
    Device tv = Device("Samsung", "DX7200", 45, false);
    tv.printInfo();
}