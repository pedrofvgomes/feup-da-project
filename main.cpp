#include "src/Network.h"
#include <iostream>

int main() {
    Network railway;


    for (auto pair : railway.mostTrains()) {
        std::cout << pair.first << "\t\t\t" << pair.second << std::endl;
    }


    return 0;
}