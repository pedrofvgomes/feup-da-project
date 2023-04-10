#include "Network.h"

#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <random>
#include <unordered_map>

using namespace std;

// -------------------- Constructor -------------------- //

Network::Network() {
    trainPrices = pair<int,int>(-1,-1);
    stations = vector<Station*>();
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

void Network::createNetwork(const string &path) {
    cout << endl << readStations(path)
         << endl << readConnections(path);
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
    file.open(fileLocation + "stations.csv", ios::in);
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

    fstream file;
    file.open(fileLocation + "network.csv", ios::in);
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

bool Network::doesStationExist(const std::string& input, Station*& stationPtr) {
    stationPtr = findStation(input);
    return stationPtr == nullptr ? false : true;
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

unsigned int Network::edmondsKarp(Station *source, Station *target) {
    // Reset the flows
    for (auto v : stations) {
        for (auto e: v->getConnections()) {
            e->setFlow(0);
        }
    }
    // Loop to find augmentation paths
    while( findAugmentingPath(source, target) ) {
        unsigned int f = findMinResidualAlongPath(source, target);
        augmentFlowAlongPath(source, target, f);
    }

    unsigned int maxFlow = 0;
    for (auto connection : source->getConnections()){
        maxFlow += connection->getFlow();
    }

    return maxFlow;
}

std::vector<std::pair<std::string,std::string>> Network::mostTrains() {
    unsigned int max = 0;
    std::vector<std::pair<std::string,std::string>> most;

    for (auto it1 = stations.begin(); it1 != stations.end(); it1++) {
        for (auto it2 = it1 + 1; it2 != stations.end(); it2++) {
            unsigned int flow = edmondsKarp((*it1), (*it2));
            if (flow > max) {
                max = flow;
                most.clear();
                most.push_back(std::make_pair((*it1)->getName(), (*it2)->getName()));
            }
            else if (flow == max) {
                most.push_back(std::make_pair((*it1)->getName(), (*it2)->getName()));
            }
        }
    }

    return most;
}

bool sortbysec(const pair<std::string, unsigned int> &a, const pair<std::string ,unsigned int> &b) {
    return (a.second > b.second);
}

std::vector<std::pair<std::string, unsigned int>> Network::topKMunicipalities(unsigned int k) {

    std::vector<std::pair<std::string, unsigned int>> topK;
    std::unordered_map<std::string, unsigned int> municipalityFlow;

    // Get the sum of flows for each municipality
    for (auto it1 = stations.begin(); it1 != stations.end(); it1++) {
        for (auto it2 = it1 + 1; it2 != stations.end(); it2++) {
            unsigned int flow = edmondsKarp((*it1), (*it2));
            if (municipalityFlow.contains((*it1)->getMunicipality())) {
                municipalityFlow[(*it1)->getMunicipality()] += flow;
            }
            else {
                municipalityFlow[(*it1)->getMunicipality()] = flow;
            }
        }
    }

    // Sort the flows
    std::vector<std::pair<std::string, unsigned int>> sorted;
    for (auto pair : municipalityFlow) {
        sorted.push_back(pair);
    }
    std::sort(sorted.begin(), sorted.end(), sortbysec);

    // Get the top-k municipalities
    for (int i = 0; i < k; i++) {
        topK.push_back(make_pair(sorted.begin()->first, sorted.begin()->second));
        sorted.erase(sorted.begin());
    }

    return topK;
}

std::vector<std::pair<std::string, unsigned int>> Network::topKDistricts(unsigned int k) {

    std::vector<std::pair<std::string, unsigned int>> topK;
    std::unordered_map<std::string, unsigned int> districtsFlow;

    // Get the sum of flows for each municipality
    for (auto it1 = stations.begin(); it1 != stations.end(); it1++) {
        for (auto it2 = it1 + 1; it2 != stations.end(); it2++) {
            auto flow = edmondsKarp((*it1), (*it2));
            if (districtsFlow.contains((*it1)->getDistrict())) {
                districtsFlow[(*it1)->getDistrict()] += flow;
            }
            else {
                districtsFlow[(*it1)->getDistrict()] = flow;
            }
        }
    }

    // Sort the flows
    std::vector<std::pair<std::string, unsigned int>> sorted;
    for (auto pair : districtsFlow) {
        sorted.push_back(pair);
    }
    std::sort(sorted.begin(), sorted.end(), sortbysec);

    // Get the top-k municipalities
    for (int i = 0; i < k; i++) {
        topK.push_back(make_pair(sorted.begin()->first, sorted.begin()->second));
        sorted.erase(sorted.begin());
    }

    return topK;
}

std::vector<Station *> Network::BFS(Station *source) {
    // Set stations to unvisited
    for (auto station : stations) {
        station->setVisited(false);
    }

    std::vector<Station *> visited;
    std::queue<Station *> queue;
    queue.push(source);
    source->setVisited(true);

    while (!queue.empty()) {
        auto n = queue.front();
        queue.pop();

        for (auto connection : n->getConnections()) {
            if (!connection->getDestination()->isVisited()) {
                connection->getDestination()->setVisited(true);
                queue.push(connection->getDestination());
                visited.push_back(connection->getDestination());
            }
        }
    }
    return visited;
}

unsigned int Network::maxTrainsToStation(Station *station) {

    std::vector<Station *> tree;
    tree = BFS(station);

    // Add the new SuperStation
    auto superStation = new Station("temp", "temp", "temp", "temp", "temp");
    stations.push_back(superStation);
    for (auto node : tree) {
        node->addBidirectionalConnection(superStation, INT_MAX, (string &) "temp");
    }

    unsigned int most = edmondsKarp(superStation, station);

    // Removing the SuperStation
    for (auto connection : superStation->getConnections()) {
        connection->getDestination()->removeConnection(superStation);
        superStation->removeConnection(connection->getDestination());
    }
    delete superStation;

    return most;
}

bool Network::removeBidirectionalConnection(Station *source, Station *destination) {
    for (auto connection : source->getConnections()) {
        if (connection->getDestination() == destination) {
            connection->getDestination()->removeConnection(destination);
            destination->removeConnection(connection->getDestination());
            return true;
        }
    }
    return false;
}

bool Network::randomGenerateRailway(int n) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> src(0, stations.size());

    int nSrc, nDst;
    vector<int> numberList;
    while (n != 0) {
        do {
            nSrc = src(mt);
        } while (find(numberList.begin(), numberList.end(), nSrc) != numberList.end());
        Station *source = stations[nSrc];

        uniform_int_distribution<int> dst(0, source->getConnections().size());

        nDst = dst(mt);
        Station *destination = source->getConnections()[nDst]->getDestination();

        if (removeBidirectionalConnection(source, destination)) { n--; }
        else return false;
    }

    return true;
}

std::unordered_map<Station *, unsigned int> Network::maxFlowPerStation() {
    std::unordered_map<Station *, unsigned int> flows;

    for (auto it1 = stations.begin(); it1 != stations.end(); it1++) {
        unsigned int sum = 0;
        for (auto it2 = it1 + 1; it2 != stations.end(); it2++) {
            unsigned int flow = edmondsKarp(*it1, *it2);
            sum += flow;
        }
        flows[*it1] = sum;
    }

    return flows;
}

bool comparevp(const Station* s1, const Station* s2){
    return s1->getDist() < s2->getDist();
}

void Network::dijkstra(Station* source){
    std::vector<Station*> q;

    for(auto s : stations){
        s->setPath(nullptr);

        if(s==source) s->setDist(0);
        else s->setDist(INT64_MAX);

        s->setVisited(false);

        q.push_back(s);
    }

    while(!q.empty()){
        std::sort(q.begin(), q.end(), comparevp);
        auto t = q.front();
        q.erase(q.begin());
        t->setVisited(true);

        for(auto c:t->getConnections()){
            int cost;
            if(c->getService() == "STANDARD") cost = 2;
            else cost = 4;
            int temp = t->getDist() + cost;
            c->setFlow(0);
            if(temp < c->getDestination()->getDist()){
                c->getDestination()->setDist(temp);
                c->getDestination()->setPath(c);
            }
        }
    }
}

std::pair<unsigned int, unsigned int> Network::maxFlowMinCost(Station* source, Station* target){
    dijkstra(source);

    int maxflow = findMinResidualAlongPath(source, target);

    int cost = target->getDist();

    return std::make_pair(maxflow, cost);
}

// ---------------------- Getters ---------------------- //

const std::pair<int, int> &Network::getTrainPrices() const {
    return trainPrices;
}

const std::vector<Station *> &Network::getStations() const {
    return stations;
}

// ---------------------- Setters ---------------------- //

void Network::setTrainPrices(const std::pair<int, int> &trainPrices) {
    Network::trainPrices = trainPrices;
}

void Network::setStations(const std::vector<Station *> &stations) {
    Network::stations = stations;
}


// -------------------- END OF FILE -------------------- //
