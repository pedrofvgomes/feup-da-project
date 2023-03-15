#ifndef FEUP_DA_PROJECT_NETWORK_H
#define FEUP_DA_PROJECT_NETWORK_H

#include <unordered_map>
#include <string>
#include "station.h"
using namespace std;

class Network{
public:
    unordered_map<string, Station> getStations() const;
    void addStation(Station station);
protected:
    unordered_map<string, Station> stations;
};

#endif