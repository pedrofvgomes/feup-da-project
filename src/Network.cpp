#include "Network.h"

#include <fstream>
#include <iostream>

using namespace std;

// -------------------- Constructor -------------------- //

Network::Network() {
    stations = unordered_map<std::string, Station>();
}

// ---------------------- Methods ---------------------- //

void Network::addStation(const Station& station) {
    stations.insert(make_pair(station.getName(), station));
}

void Network::addConnection(const Connection& newConnection) {
    stations.find(newConnection.getSource())->second.addConnection(newConnection);
}

void Network::createNetwork(const string &path) {
    cout << endl << readStations(path)
         << endl << readConnections(path);
}

int Network::readStations(const string& fileLocation) {

    fstream file;
    file.open(fileLocation + "stations.csv", ios::in);
    if (!file.is_open()) {
        cout << "ERROR - The function \"readStations\" could not read the data" << endl;
        return 0;
    }

    int n = 0;
    string Name;
    string District;
    string Municipality;
    string Township;
    string Line;

    getline(file, Name); // Skip fist line
    while (getline(file, Name, ',')) {
        getline(file, District, ',');
        getline(file, Municipality, ',');
        getline(file, Township, ',');
        getline(file, Line);

        stations.insert(make_pair(Name, Station(Name, District, Municipality, Township, Line)));

        n++;
    }

    file.close();
    return n;
}

int Network::readConnections(const string& fileLocation) {

    fstream file;
    file.open(fileLocation + "network.csv", ios::in);
    if (!file.is_open()) {
        cout << "ERROR - The function \"readConnections\" could not read the data" << endl;
        return 0;
    }

    int n = 0;
    string Source;
    string Destination;
    string Capacity;
    string Service;

    getline(file, Source); // Skip fist line
    while (getline(file, Source, ',')) {
        getline(file, Destination, ',');
        getline(file, Capacity, ',');
        getline(file, Service);

        stations.find(Source)->second.addConnection({Source, Destination, static_cast<unsigned int>(stoul(Capacity)), Service});

        n++;
    }
    file.close();
    return n;
}

// ---------------------- Getters ---------------------- //

const unordered_map<std::string, Station> &Network::getStations() const {
    return stations;
}

// ---------------------- Setters ---------------------- //

void Network::setStations(const unordered_map<std::string, Station> &unorderedMap) {
    Network::stations = unorderedMap;
}

// -------------------- END OF FILE -------------------- //
