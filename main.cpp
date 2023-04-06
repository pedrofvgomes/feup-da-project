#include "src/Network.h"
#include <iostream>

int main() {
    Network railway;

    std::cout << "Flow: " << railway.edmondsKarp("Arentim", "Esgueira") << std::endl;


    return 0;
}