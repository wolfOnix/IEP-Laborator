#include <iostream>
#include <memory>
#include "deviceResource.cpp"
// #include "smartdevice.cpp"

using namespace device;
using namespace device_resource;
using namespace locker;
// using namespace smartdevice;

Device *createDevice(const std::string &manufacturer, const std::string &model, float displaySize, bool mobile) { // Create an instance of the Device class
    std::cout << "Create instance:\n";
    return (new Device(manufacturer, model, displaySize, mobile));
}

void printCount(std::shared_ptr<Device> &sp, int index) {
    std::cout << "Shared pointer counter (*p" << index << "): " << sp.use_count() << '\n';
}

void sharedPointers() {
    std::cout << "\n\tSMART POINTERS\n\n";
    // *p1
    std::shared_ptr<Device> pDevice1(createDevice("Samsung", "DX7200", 45, false));
    std::cout << "*p1: "; pDevice1->printObject();
    pDevice1->setModel("JE33"); std::cout << " - *p1 model modified\n";
    std::cout << "*p1: "; pDevice1->printObject();

    // *p2
    std::shared_ptr<Device> pDevice2(pDevice1); std::cout << "*p1 copied to *p2\n";
    std::cout << "*p2: "; pDevice2->printObject();
    //std::cout << "Shared pointer counter (*p1): " << pDevice1.use_count() << '\n'; // get the number of shared_ptr objects referring to the same managed object
    printCount(pDevice1, 1);
    printCount(pDevice2, 2);

    // *p3
    std::shared_ptr<Device> pDevice3 = move(pDevice1); std::cout << "Ownership transfered from *p1 to *p3\n";
    printCount(pDevice1, 1);
    printCount(pDevice2, 2);
    printCount(pDevice3, 3);

    pDevice2->setManufacturer("Sony"); std::cout << " - *p2 manufacturer modified\n";
    // std::cout << "*p1: "; pDevice1->printObject(); // won't work, as pDevice1 is null
    std::cout << "*p2: "; pDevice2->printObject();
    std::cout << "*p3: "; pDevice3->printObject();
}

void manageResources() {
    std::cout << "\n\tRESOURCE MANAGEMENT\n\n";
    DeviceResource devRes1(Device("Apple", "MacBook Pro", 16, true));
    devRes1.lockState();
    Locker *lockedDevice = new Locker(devRes1);
    devRes1.lockState();
    delete lockedDevice;
    devRes1.lockState();
}

int main() {
    sharedPointers();
    manageResources();
}