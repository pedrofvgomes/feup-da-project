#include "Connection.h"

using namespace std;

// -------------------- Constructor -------------------- //

Connection::Connection(std::string &src, std::string &dest, unsigned int cap, std::string &type) {
    this->source = src;
    this->destination = dest;
    this->capacity = cap;
    this->service = type;
}

// ---------------------- Getters ---------------------- //

const string &Connection::getSource() const {
    return source;
}

const string &Connection::getDestination() const {
    return destination;
}

unsigned int Connection::getCapacity() const {
    return capacity;
}

const string &Connection::getService() const {
    return service;
}

// ---------------------- Setters ---------------------- //

void Connection::setSource(const string &src) {
    Connection::source = src;
}

void Connection::setDestination(const string &dest) {
    Connection::destination = dest;
}

void Connection::setCapacity(unsigned int cap) {
    Connection::capacity = cap;
}

void Connection::setService(const string &type) {
    Connection::service = type;
}

// -------------------- END OF FILE -------------------- //
