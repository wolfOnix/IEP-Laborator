#pragma once

#include <iostream>
//#include "device.hpp"

namespace device {

    class Device {

        private:
        
        std::string manufacturer;
        std::string model;
        float displaySize;
        bool mobile;

        public:

        Device() {
            std::cout << " + Empty Device created\n";
        }

        Device(const std::string &_manufacturer, const std::string &_model, float _displaySize, bool _mobile) :
            manufacturer(_manufacturer),
            model(_model),
            displaySize(_displaySize),
            mobile(_mobile) {
            std::cout << " + Device created\n";
        }

        /* OLD VERSION FOR ABOVE ->
        
        Device(const std::string &manufacturer, const std::string &model, float displaySize, bool mobile) {
            this->manufacturer = manufacturer;
            this->model = model;
            this->displaySize = displaySize;
            this->mobile = mobile;
            std::cout << " + Device created\n";
        }

        <- */

        Device(const Device &device) {
            this->manufacturer = device.manufacturer;
            this->model = device.model;
            this->displaySize = device.displaySize;
            this->mobile = device.mobile;
            std::cout << " + Device copied\n";
        }

        ~Device() {
            std::cout << " - Device destructred\n";
        }

        void printInfo() {
            std::cout << "Device:\n\tManufacturer: " << this->manufacturer << "\n\tModel: " << this->model << "\n\tDisplay size: " << this->displaySize << "\n\tMobile: " << this->mobile << "\n";
        }

    };

}
