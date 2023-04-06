#include "StationConnection.h"

// -------------------- Constructor -------------------- //

Station::Station(std::string name, std::string district, std::string municipality, std::string township, std::string line) {
    Station::name = name;
    Station::district = district;
    Station::municipality = municipality;
    Station::township = township;
    Station::line = line;
}


Connection::Connection(Station *origin, Station *destination, unsigned int capacity, std::string service) {
    Connection::origin = origin;
    Connection::destination = destination;
    Connection::capacity = capacity;
    Connection::service = service;
}

Connection *Station::addConnection(Station *destination, int capacity, std::string service) {
    auto newConnection = new Connection(this, destination, capacity, service);
    connections.push_back(newConnection);
    destination->incoming.push_back(newConnection);
    return newConnection;
}

// ---------------------- Getters ---------------------- //
std::string Station::getName() const {
    return name;
}

std::string Station::getDistrict() const {
    return district;
}

std::string Station::getMunicipality() const {
    return municipality;
}

std::string Station::getTownship() const {
    return township;
}

std::string Station::getLine() const {
    return line;
}

std::vector<Connection *> Station::getConnections() const {
    return connections;
}

bool Station::isVisited() const {
    return visited;
}

Connection *Station::getPath() const {
    return path;
}

std::vector<Connection *> Station::getIncoming() const {
    return incoming;
}

Station *Connection::getOrigin() const {
    return origin;
}

Station *Connection::getDestination() const {
    return destination;
}

unsigned int Connection::getCapacity() const {
    return capacity;
}

std::string Connection::getService() const {
    return service;
}

unsigned int Connection::getFlow() const {
    return flow;
}

bool Connection::isSelected() const {
    return selected;
}

Connection *Connection::getReverse() const {
    return reverse;
}


// ---------------------- Setters ---------------------- //
void Station::setName(std::string name) {
    Station::name = name;
}

void Station::setDistrict(std::string district) {
    Station::district = district;
}

void Station::setMunicipality(std::string municipality) {
    Station::municipality = municipality;
}

void Station::setTownship(std::string township) {
    Station::township = township;
}

void Station::setLine(std::string line) {
    Station::line = line;
}

void Station::setVisited(bool visited) {
    Station::visited = visited;
}

void Station::setPath(Connection *path) {
    Station::path = path;
}

void Connection::setFlow(unsigned int flow) {
    Connection::flow = flow;
}

void Connection::setSelected(bool selected) {
    Connection::selected = selected;
}

void Connection::setReverse(Connection *reverse) {
    Connection::reverse = reverse;
}
// -------------------- END OF FILE -------------------- //
