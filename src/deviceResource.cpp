#pragma once

#include <iostream>
#include <memory>
#include "device.cpp"

using namespace device;

namespace device_resource {

    class DeviceResource {

        private:

        bool locked = false;
        Device device = Device();

        public:

        // Empty constructor
        DeviceResource() {
            std::cout << "\033[36m _ Resource created with empty Device: \033[35m" << this << "\033[0m\n";
        }

        // Constructor
        DeviceResource(const Device &_device) :
            device(_device) {
            std::cout << "\033[36m + Resource created: \033[35m" << this << "\033[0m\n";
        }

        // Copy constructor
        DeviceResource(const DeviceResource &resource) {
            device = resource.device;
            locked = resource.locked;
            std::cout << "\033[36m + Resource created via copy constructor: \033[35m" << this << "\033[0m\n";
        }

        // Destructor
        ~DeviceResource() {
            std::cout << "\033[36m ~ Resource destructred: \033[35m" << this << "\033[0m\n";
        }

        bool isLocked() {
            return locked;
        }

        void setLock(bool _locked) {
            locked = _locked;
        }

        void lockState() {
            if (this->isLocked()) {
                std::cout << "Device resource is locked\n";
            } else {
                std::cout << "Device resource is unlocked\n";
            }
        }

    };

}

namespace locker {

    using namespace device_resource;

    void lock(DeviceResource &dr) {
        dr.setLock(true);
        std::cout << "\033[36m |&| Resource was locked: \033[35m" << &dr << "\033[0m\n";
    }

    void unlock(DeviceResource &dr) {
        dr.setLock(false);
        std::cout << "\033[36m  &  Resource was unlocked: \033[35m" << &dr << "\033[0m\n";
    }

    class Locker {

        private:

        DeviceResource &deviceResource;

        public:

        explicit Locker(DeviceResource &dr) :
            deviceResource(dr) {
            lock(deviceResource);
        }
        
        ~Locker() {
            unlock(deviceResource);
        }

    };

}
