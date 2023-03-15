#include "Network.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

unordered_map<string, Station> Network::getStations() {return stations;}

void Network::addStation(Station station) {
    stations.insert(make_pair(station.getName(), station));
}

void Network::addConnection(Connection newConnection) {
    stations[newConnection.getSource()].addConnection(newConnection);
}

int Network::readStations(string fileLocation) {

    fstream file;
    file.open(fileLocation, ios::in);
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

int Network::readConnections(string fileLocation) {

    fstream file;
    file.open(fileLocation, ios::in);
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

        stations[Source].addConnection({Source, Destination, static_cast<unsigned int>(stoul(Capacity)), Service});

        n++;
    }
    file.close();
    return n;
}

