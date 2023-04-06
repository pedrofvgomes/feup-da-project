#include "Network.h"

#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>
#include <iostream>
#include <limits>
#include <map>

// -------------------- Constructor -------------------- //

Network::Network() {
    std::cout << readStations("../data/stations.csv") << std::endl;
    std::cout << readConnections("../data/network.csv") << std::endl;
}

// ---------------------- Methods ---------------------- //
Station *Network::findStation(const std::string &name) const {
    for (auto station : stations) {
        if (station->getName() == name) {
            return station;
        }
    }
    return nullptr;
}

void Network::addStation(const std::string &name, const std::string &district, const std::string &municipality,
                         const std::string &township, const std::string &line) {

    stations.push_back(new Station(name, district, municipality, township, line));
}

void Network::addBidirectionalConnection(const std::string &source, const std::string &destination, unsigned int capacity, std::string service) {
    // Finding the stations
    Station * stationA = nullptr;
    Station * stationB = nullptr;
    for (auto station : stations) {
        if (stationA != nullptr && stationB != nullptr) {
            break;
        }
        if (station->getName() == source) {
            stationA = station;
        }
        else if (station->getName() == destination) {
            stationB = station;
        }
    }

    stationA->addConnection(stationB, capacity, service);
    stationB->addConnection(stationA, capacity, service);
}

unsigned int Network::readStations(const std::string &fileLocation) {

    std::fstream file;
    file.open(fileLocation, std::ios::in);
    if (!file.is_open()) {
        std::cout << "ERROR - The function \"readStations\" could not read the data" << std::endl;
        return 0;
    }

    int n = 0;
    std::string Name;
    std::string District;
    std::string Municipality;
    std::string Township;
    std::string Line;
    std::string temp;

    getline(file, Name); // Skip fist line
    while (getline(file, Name, ',')) {
        getline(file, District, ',');
        getline(file, Municipality, ',');
        getline(file, Township, ',');

        if(Township[0] == '"'){
            getline(file, temp, '"');
            Township += "," + temp;
            temp = "";
            for(int i=1; i<Township.size()-1; i++){
                temp+=Township[i];
            }
        }
        getline(file, Line);

        bool insert = true;
        for (auto station : stations) {
            if (station->getName() == Name) {
                insert = false;
                break;
            }
        }

        if (insert == true) {
            stations.push_back(new Station(Name, District, Municipality, Township, Line));
        }

        n++;
    }

    file.close();
    return n;
}

unsigned int Network::readConnections(const std::string &fileLocation) {

    std::fstream file;
    file.open(fileLocation, std::ios::in);
    if (!file.is_open()) {
        std::cout << "ERROR - The function \"readConnections\" could not read the data" << std::endl;
        return 0;
    }

    int n = 0;
    std::string Source;
    std::string Destination;
    std::string Capacity;
    std::string Service;

    getline(file, Source); // Skip fist line
    while (getline(file, Source, ',')) {
        getline(file, Destination, ',');
        getline(file, Capacity, ',');
        getline(file, Service);

        // Finding the stations
        Station * stationA = nullptr;
        Station * stationB = nullptr;
        for (auto station : stations) {
            if (stationA != nullptr && stationB != nullptr) {
                break;
            }
            if (station->getName() == Source) {
                stationA = station;
            }
            else if (station->getName() == Destination) {
                stationB = station;
            }
        }

        stationA->addConnection(stationB, stoul(Capacity), Service);
        stationB->addConnection(stationA, stoul(Capacity), Service);
        n++;
    }
    file.close();
    return n;
}

Station * Network::findStation(std::string name) {
    for (auto station : stations) {
        if (station->getName() == name) {
            return station;
        }
    }
    return nullptr;
}

// Edmonds-Karp Algorithm
void Network::testAndVisit(std::queue< Station*> &q, Connection *e, Station *w, unsigned int residual) {
    if (! w->isVisited() && residual > 0) {
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

bool Network::findAugmentingPath(Station *s, Station *t) {
    for(auto v : stations) {
        v->setVisited(false);
    }
    s->setVisited(true);
    std::queue<Station *> q;
    q.push(s);
    while( ! q.empty() && ! t->isVisited()) {
        auto v = q.front();
        q.pop();
        for(auto e: v->getConnections()) {
            testAndVisit(q, e, e->getDestination(), e->getCapacity() - e->getFlow());
        }
        for(auto e: v->getIncoming()) {
            testAndVisit(q, e, e->getOrigin(), e->getFlow());
        }
    }
    return t->isVisited();
}

unsigned int Network::findMinResidualAlongPath(Station *s, Station *t) {
    unsigned int f = INT_MAX;
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        if (e->getDestination() == v) {
            f = std::min(f, e->getCapacity() - e->getFlow());
            v = e->getOrigin();
        }
        else {
            f = std::min(f, e->getFlow());
            v = e->getDestination();
        }
    }
    return f;
}

void Network::augmentFlowAlongPath(Station *s, Station *t, unsigned int f) {
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        unsigned int flow = e->getFlow();
        if (e->getDestination() == v) {
            e->setFlow(flow + f);
            v = e->getOrigin();
        }
        else {
            e->setFlow(flow - f);
            v = e->getDestination();
        }
    }
}

unsigned int Network::edmondsKarp(std::string source, std::string target) {
    Station* s = findStation(source);
    Station* t = findStation(target);

    if (s == nullptr || t == nullptr || s == t)
        throw std::logic_error("Invalid source and/or target vertex");

    // Reset the flows
    for (auto v : stations) {
        for (auto e: v->getConnections()) {
            e->setFlow(0);
        }
    }
    // Loop to find augmentation paths
    while( findAugmentingPath(s, t) ) {
        unsigned int f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }

    unsigned int maxFlow = 0;
    for(auto connection : s->getConnections()){
        maxFlow += connection->getFlow();
    }

    return maxFlow;
}

unsigned int stationCapacity(Station* station){
    unsigned int capacity = 0;
    for(auto &connection : station->getConnections()){
        capacity += connection->getCapacity();
    }
    return capacity;
}

bool cmp(std::pair<std::string, unsigned int>& mun1, std::pair<std::string, unsigned int>& mun2) {
    if (mun2.second == mun1.second) return mun1.first < mun2.first;
    return mun2.second > mun1.second;
}

std::vector<std::string> Network::topKMunicipalitiesByCapacity(unsigned int k) {
    std::vector<std::string> topK;
    std::map<std::string, unsigned int> municipalityCapacity;
    std::vector<std::pair<std::string, unsigned int>> sorted;

    /* calculate each municipality's total capacity */

    for(auto &station : this->stations){
        municipalityCapacity[station->getMunicipality()] += stationCapacity(station);
    }

    /* pass the map values to a vector, so it can be sorted differently, and sort it */

    for(auto &i : municipalityCapacity) sorted.emplace_back(i);
    std::sort(sorted.begin(), sorted.end(), cmp);

    /* top K municipalities' name */

    for(int i=0; i<k; i++) topK.push_back(sorted[i].first);

    return topK;
}


// ---------------------- Getters ---------------------- //

std::vector<Station *> Network::getStations() const {
    return stations;
}

// ---------------------- Setters ---------------------- //

// -------------------- END OF FILE -------------------- //
