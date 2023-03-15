#include "Station.h"
#include <string>
using namespace std;

#include <iostream>

Station::Station(string name, string district, string municipality, string township, string line) {
    this->name = name;
    this->district = district;
    this->municipality = municipality;
    this->township = township;
    this->line = line;
    this->connections = vector<Connection>();
}

Station::Station() = default;
string Station::getName() const {return name;}
string Station::getDistrict() const {return district;}
string Station::getMunicipality() const {return municipality;}
string Station::getTownship() const {return township;}
string Station::getLine() const {return line;}
vector<Connection> Station::getConnections() const {return connections;}

void Station::addConnection(Connection newConnection) {
    connections.push_back(newConnection);
}
