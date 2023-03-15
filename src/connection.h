#ifndef FEUP_DA_PROJECT_CONNECTION_H
#define FEUP_DA_PROJECT_CONNECTION_H

#include <string>
using namespace std;

class Connection{
public:
    Connection(string source, string destination, unsigned int capacity, string service);
    string getSource();
    string getDestination();
    unsigned int getCapacity();
    string getService();
protected:
    string source;
    string destination;
    unsigned int capacity;
    string service;
};

#endif