#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

#include "StationConnection.h"

class Network {
public:
    Network();

    const std::pair<int, int> &getTrainPrices() const;
    const std::vector<Station *> &getStations() const;
    void setTrainPrices(const std::pair<int, int> &trainPrices);
    void setStations(const std::vector<Station *> &stations);

    Station * findStation(const std::string &name) const;
    void addStation(const std::string &name, const std::string &district, const std::string &municipality, const std::string &township, const std::string &line);
    void addBidirectionalConnection(const std::string &source, const std::string &destination, unsigned int capacity, std::string service);
    void createNetwork(const std::string &path);
    unsigned int readStations(const std::string &fileLocation);
    unsigned int readConnections(const std::string &fileLocation);
    Station * findStation(std::string name);
    bool doesStationExist(const std::string& input, Station*& stationPtr);

    void testAndVisit(std::queue< Station*> &q, Connection *e, Station *w, unsigned int residual);
    bool findAugmentingPath(Station *s, Station *t);
    unsigned int findMinResidualAlongPath(Station *s, Station *t);
    void augmentFlowAlongPath(Station *s, Station *t, unsigned int f);
    unsigned int edmondsKarp(Station *source, Station *target);
    std::vector<std::pair<std::string, unsigned int>> topKMunicipalities(unsigned int k);
    std::vector<std::pair<std::string, unsigned int>> topKDistricts(unsigned int k);
    std::vector<std::pair<std::string,std::string>> mostTrains();
    std::vector<Station *> BFS(Station *source);
    unsigned int maxTrainsToStation(Station* station);
    bool removeBidirectionalConnection(Station *source, Station *destination);

private:

    std::pair<int,int> trainPrices;
    std::vector<Station *> stations;

};

#endif //NETWORK_H
