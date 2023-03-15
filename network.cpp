#include "network.h"
using namespace std;

unordered_map<string, Station> Network::getStations() const {
    return stations;
}

void Network::addStation(Station station) {
    stations.insert(make_pair(station.getname(), station));
}