#include "Station.h"

using namespace std;

// -------------------- Constructor -------------------- //

Station::Station(std::string &n, std::string &dis, std::string &mun, std::string &town, std::string &li) {
    this->name = n;
    this->district = dis;
    this->municipality = mun;
    this->township = town;
    this->line = li;
    this->connections = vector<Connection>();
}

// ---------------------- Methods ---------------------- //

void Station::addConnection(const Connection& newConnection) {
    connections.push_back(newConnection);
}

// ---------------------- Getters ---------------------- //

const string &Station::getName() const {
    return name;
}

const string &Station::getDistrict() const {
    return district;
}

const string &Station::getMunicipality() const {
    return municipality;
}

const string &Station::getTownship() const {
    return township;
}

const string &Station::getLine() const {
    return line;
}

const vector<Connection> &Station::getConnections() const {
    return connections;
}

// ---------------------- Setters ---------------------- //

void Station::setName(const string &n) {
    Station::name = n;
}

void Station::setDistrict(const string &dis) {
    Station::district = dis;
}

void Station::setMunicipality(const string &mun) {
    Station::municipality = mun;
}

void Station::setTownship(const string &town) {
    Station::township = town;
}

void Station::setLine(const string &li) {
    Station::line = li;
}

void Station::setConnections(const vector<Connection> &v) {
    Station::connections = v;
}

// -------------------- END OF FILE -------------------- //
