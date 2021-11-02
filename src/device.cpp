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

        // Empty constructor
        Device() {
            std::cout << " _ Empty Device created\n";
        }

        // Constructor
        Device(const std::string &_manufacturer, const std::string &_model, float _displaySize, bool _mobile) :
            manufacturer(_manufacturer),
            model(_model),
            displaySize(_displaySize),
            mobile(_mobile) {
            std::cout << " + Device created\n";
        }

        /* ALTERNATIVE FOR THE ABOVE ->
        
        Device(const std::string &manufacturer, const std::string &model, float displaySize, bool mobile) {
            this->manufacturer = manufacturer;
            this->model = model;
            this->displaySize = displaySize;
            this->mobile = mobile;
            std::cout << " + Device created\n";
        }

        <- */

        // Copy constructor
        Device(const Device &device) {
            manufacturer = device.manufacturer;
            model = device.model;
            displaySize = device.displaySize;
            mobile = device.mobile;
            std::cout << " + Device created via copy constructor\n";
        }

        // Copy assignment operator
        Device &operator = (const Device &device) {
            manufacturer = device.manufacturer;
            model = device.model;
            displaySize = device.displaySize;
            mobile = device.mobile;
            std::cout << " = Device overwritten via copy assignment operator\n";
        }

        // Destructor
        ~Device() {
            std::cout << " ~ Device destructred\n";
        }

        void setManufacturer(const std::string &_manufacturer) {
            manufacturer = _manufacturer;
        }

        const std::string &getManufacturer() {
            return manufacturer;
        }

        void setModel(const std::string &_model) {
            model = _model;
        }

        const std::string &getModel() {
            return model;
        }

        void setDisplaySize(float _displaySize) {
            displaySize = _displaySize;
        }

        float getDisplaySize() {
            return displaySize;
        }

        void setMobile(bool _mobile) {
            mobile = _mobile;
        }

        bool getMobile() {
            return mobile;
        }

        void printObject() {
            std::cout << "Device:\n\tManufacturer: " << this->manufacturer << "\n\tModel: " << this->model << "\n\tDisplay size: " << this->displaySize << "\n\tMobile: " << this->mobile << "\n";
        }

    };

}
