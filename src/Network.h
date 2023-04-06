#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <unordered_map>

#include "Station.h"
#include "Connection.h"

class Network {
public:
    Network();

    const std::pair<int, int> &getTrainPrices() const;
    const std::unordered_map<std::string, Station> &getStations() const;
    void setTrainPrices(const std::pair<int, int> &trainPrices);
    void setStations(const std::unordered_map<std::string, Station> &stations);

    void addStation(const Station &newStation);
    void addConnection(const Connection &newConnection);
    void createNetwork(const std::string &path);
    int readStations(const std::string &fileLocation);
    int readConnections(const std::string &fileLocation);
    void dfs(std::string& s);
    bool doesStationExist(const std::string& input, Station*& stationPtr);

private:
    std::pair<int,int> trainPrices;
    std::unordered_map<std::string, Station> stations;
};

#endif //NETWORK_H
