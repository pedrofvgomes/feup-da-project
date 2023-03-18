#ifndef STATION_H
#define STATION_H

#include <vector>
#include <string>

#include "Connection.h"

class Station {
public:
    Station(std::string &name, std::string &district, std::string &municipality, std::string &township, std::string &line);
    const std::string &getName() const;
    const std::string &getDistrict() const;
    const std::string &getMunicipality() const;
    const std::string &getTownship() const;
    const std::string &getLine() const;
    const std::vector<Connection> &getConnections() const;
    void setName(const std::string &name);
    void setDistrict(const std::string &district);
    void setMunicipality(const std::string &municipality);
    void setTownship(const std::string &township);
    void setLine(const std::string &line);
    void setConnections(const std::vector<Connection> &connections);
    void addConnection(const Connection& newConnection);
private:
    std::string name;
    std::string district;
    std::string municipality;
    std::string township;
    std::string line;
    std::vector<Connection> connections;
};

#endif // STATION_H
