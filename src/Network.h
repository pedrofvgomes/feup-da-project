#ifndef FEUP_DA_PROJECT_NETWORK_H
#define FEUP_DA_PROJECT_NETWORK_H

#include <unordered_map>
#include <string>
#include "Station.h"
using namespace std;

class Network {
public:
    unordered_map<string, Station> getStations();
    void addStation(Station newStation);
    void addConnection(Connection newConnection);

    int readStations(string fileLocation);
    int readConnections(string fileLocation);

protected:
    unordered_map<string, Station> stations;
};

#endif