#pragma once

#include <iostream>
#include "device.cpp"

using namespace device;

namespace smartdevice {

    class SmartDevice : public Device {

        private:

        std::string type;
        bool wifi;

        public:

        // Constructor
        SmartDevice(const std::string &_manufacturer, const std::string &_model, float _displaySize, bool _mobile, const std::string &_type, bool _wifi) :
            Device(_manufacturer, _model, _displaySize, _mobile),
            type(_type),
            wifi(_wifi) {
            std::cout << "\033[36m + SmartDevice created: \033[35m" << this << "\033[0m\n";
        }

        // Copy constructor
        SmartDevice(const SmartDevice &smartdevice) : Device(smartdevice) {
            std::cout << "\033[36m + SmartDevice created via copy constructor: \033[35m" << this << "\033[0m\n";
        }

        // Copy assignment operator
        SmartDevice &operator = (const SmartDevice &smartdevice) {
            if (this == &smartdevice) {
                std::cout << "\033[36m ! SAME OBJECT for copy assignment operator: \033[35m" << this << "\033[0m\n";
                return *this;
            }
            Device::operator=(smartdevice);
            std::cout << "\033[36m = SmartDevice overwritten via standard copy assignment operator: \033[35m" << this << "\033[0m\n";
            return *this;
        }

        void printObject() {
            Device::printObject();
            std::cout << "\tType: " << this->type
                << "\n\tWifi: " << this->wifi << "\n";
        }

    };

}