#include "StationConnection.h"

using namespace std;

// -------------------- Constructor -------------------- //

Station::Station(string &name, string &district, string &municipality, string &township, string &line) {
    Station::name = name;
    Station::district = district;
    Station::municipality = municipality;
    Station::township = township;
    Station::line = line;
}

Connection::Connection(Station *origin, Station *destination, unsigned int capacity, string &service) {
    Connection::origin = origin;
    Connection::destination = destination;
    Connection::capacity = capacity;
    Connection::service = service;
}

// ---------------------- Methods ---------------------- //

Connection* Station::addConnection(Station *destination, int capacity, string &service) {
    auto newConnection = new Connection(this, destination, capacity, service);
    connections.push_back(newConnection);
    destination->incoming.push_back(newConnection);
    return newConnection;
}

void Station::addBidirectionalConnection(Station *destination, int capacity, string &service) {
    auto newConnection = addConnection(destination, capacity, service);
    destination->addConnection(newConnection->getOrigin(), capacity, service);
}

bool Station::removeConnection(Station *destination) {
    for (auto it1 = connections.begin(); it1 != connections.end(); it1++) {
        if ((*it1)->getDestination() == destination) {
            connections.erase(it1);
            for (auto it2 = destination->incoming.begin(); it2 != destination->incoming.end(); it2++) {
                if ((*it2)->getOrigin()->getName() == name) {
                    destination->incoming.erase(it2);
                    return true;
                }
            }
        }
    }
    return false;
}

// ---------------------- Getters ---------------------- //

// STATION

const string& Station::getName() const {
    return name;
}

const string& Station::getDistrict() const {
    return district;
}

const string& Station::getMunicipality() const {
    return municipality;
}

const string& Station::getTownship() const {
    return township;
}

const string& Station::getLine() const {
    return line;
}

const vector<Connection *>& Station::getConnections() const {
    return connections;
}

const vector<Connection *>& Station::getIncoming() const {
    return incoming;
}

bool Station::isVisited() const {
    return visited;
}

Connection *Station::getPath() const {
    return path;
}

// CONNECTION

Station *Connection::getOrigin() const {
    return origin;
}

Station *Connection::getDestination() const {
    return destination;
}

unsigned int Connection::getCapacity() const {
    return capacity;
}

const string &Connection::getService() const {
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

// STATION

void Station::setName(const string& name) {
    Station::name = name;
}

void Station::setDistrict(const string& district) {
    Station::district = district;
}

void Station::setMunicipality(const string& municipality) {
    Station::municipality = municipality;
}

void Station::setTownship(const string& township) {
    Station::township = township;
}

void Station::setLine(const string& line) {
    Station::line = line;
}

void Station::setConnections(const vector<Connection *> &connections) {
    Station::connections = connections;
}

void Station::setIncoming(const vector<Connection *> &incoming) {
    Station::incoming = incoming;
}

void Station::setVisited(bool visited) {
    Station::visited = visited;
}

void Station::setPath(Connection *path) {
    Station::path = path;
}

// CONNECTION

void Connection::setOrigin(Station *origin) {
    Connection::origin = origin;
}

void Connection::setDestination(Station *destination) {
    Connection::destination = destination;
}

void Connection::setCapacity(unsigned int capacity) {
    Connection::capacity = capacity;
}

void Connection::setService(const string &service) {
    Connection::service = service;
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
