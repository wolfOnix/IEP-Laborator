#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>

namespace Device {
    
    class Device {

        private:
        std::string manufacturer;
        std::string model;
        float displaySize;
        bool mobile;

        public:
        Device();
        Device(const std::string &manufacturer, const std::string &model, float displaySize, bool mobile);
        Device(const Device &device);
        ~Device();
        void printInfo();

    };

}

#endif
