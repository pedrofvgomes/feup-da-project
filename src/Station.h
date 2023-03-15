#ifndef feup_da_project_stations_h
#define feup_da_project_stations_h

#include <string>
#include <vector>
#include "Connection.h"
using namespace std;

class Station {
public:
    Station();
    Station(string name, string district, string municipality, string township, string line);
    string getName() const;
    string getDistrict() const;
    string getMunicipality() const;
    string getTownship() const;
    string getLine() const;
    vector<Connection> getConnections() const;

    void addConnection(Connection newConnection);

protected:

    string name;
    string district;
    string municipality;
    string township;
    string line;

    vector<Connection> connections;
};

#endif