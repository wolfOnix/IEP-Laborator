#pragma once

#include <iostream>
//#include "device.hpp"

//using namespace device;

namespace device {

    class Device {

        private:
        
        std::string manufacturer;
        std::string model;
        float displaySize;
        bool mobile;

        public:

        /*Device::*/Device() {
            std::cout << " + Empty Device created\n";
        }

        /*Device::*/Device(const std::string &manufacturer, const std::string &model, float displaySize, bool mobile) {
            this->manufacturer = manufacturer;
            this->model = model;
            this->displaySize = displaySize;
            this->mobile = mobile;
            std::cout << " + Device created\n";
        }

        /*Device::*/Device(const Device &device) {
            this->manufacturer = device.manufacturer;
            this->model = device.model;
            this->displaySize = device.displaySize;
            this->mobile = device.mobile;
            std::cout << " + Device copied\n";
        }

        /*Device::*/~Device() {
            std::cout << " - Device destructred\n";
        }

        void /*Device::*/printInfo() {
            std::cout << "Manufacturer: " << this->manufacturer << " - Model: " << this->model << " - Display size: " << this->displaySize << " - Mobile: " << this->mobile << "\n";
        }

    };

}
