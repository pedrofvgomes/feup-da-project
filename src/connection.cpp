#include "connection.h"

Connection::Connection(std::string source, std::string destination, unsigned int capacity, std::string service) {
    this->source = source;
    this->destination = destination;
    this->capacity = capacity;
    this->service = service;
}

string Connection::getSource() {
    return source;
}

string Connection::getDestination() {
    return destination;
}

unsigned int Connection::getCapacity() {
    return capacity;
}

string Connection::getService() {
    return service;
}