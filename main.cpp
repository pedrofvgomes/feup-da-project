#include "src/Network.h"
#include <iostream>

int main(){

    Network railway;

    cout << railway.readStations("../data/stations.csv") << endl;
    cout << railway.readConnections("../data/network.csv") << endl;

    return 0;
}