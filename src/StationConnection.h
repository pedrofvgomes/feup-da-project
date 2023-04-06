#ifndef STATIONCONNECTION_H
#define STATIONCONNECTION_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

class Connection;

class Station {
public:
    Station(std::string name, std::string district, std::string municipality, std::string township, std::string line);
    std::string getName() const;
    std::string getDistrict() const;
    std::string getMunicipality() const;
    std::string getTownship() const;
    std::string getLine() const;
    std::vector<Connection *> getConnections() const;
    bool isVisited() const;
    Connection * getPath() const;
    std::vector<Connection *> getIncoming() const;

    void setName(std::string name);
    void setDistrict(std::string district);
    void setMunicipality(std::string municipality);
    void setTownship(std::string township);
    void setLine(std::string line);
    void setVisited(bool visited);
    void setPath(Connection *path);
    Connection *addConnection(Station *destination, int capacity, std::string service);

protected:
    std::string name;
    std::string district;
    std::string municipality;
    std::string township;
    std::string line;
    std::vector<Connection *> connections;

    bool visited = false;
    Connection * path = nullptr;
    std::vector<Connection *> incoming;
};

class Connection {
public:
    Connection(Station *origin, Station *destination, unsigned int capacity, std::string service);

    Station * getOrigin() const;
    Station * getDestination() const;
    unsigned int getCapacity() const;
    std::string getService() const;
    unsigned int getFlow() const;
    bool isSelected() const;
    Connection * getReverse() const;

    void setFlow(unsigned int flow);
    void setSelected(bool selected);
    void setReverse(Connection *reverse);

protected:
    Station *origin;
    Station *destination;
    unsigned int capacity;
    std::string service;

    unsigned int flow;
    bool selected = false;
    Connection *reverse = nullptr;
};

#endif //STATIONCONNECTION_H
