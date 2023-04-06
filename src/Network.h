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
    Station * findStation(const std::string &name) const;
    void addStation(const std::string &name, const std::string &district, const std::string &municipality, const std::string &township, const std::string &line);
    void addBidirectionalConnection(const std::string &source, const std::string &destination, unsigned int capacity, std::string service);
    std::vector<Station *> getStations() const;
    unsigned int readStations(const std::string &fileLocation);
    unsigned int readConnections(const std::string &fileLocation);
    Station * findStation(std::string name);

    void testAndVisit(std::queue< Station*> &q, Connection *e, Station *w, unsigned int residual);
    bool findAugmentingPath(Station *s, Station *t);
    unsigned int findMinResidualAlongPath(Station *s, Station *t);
    void augmentFlowAlongPath(Station *s, Station *t, unsigned int f);
    unsigned int edmondsKarp(std::string source, std::string target);
    std::vector<std::pair<std::string,std::string>> mostTrains();
    std::vector<Station *> BFS(Station *source);
    unsigned int maxTrainsToStation(std::string station);

private:
    std::vector<Station *> stations;

};

#endif //NETWORK_H
