#include "stations.h"
#include <string>
using namespace std;

Station::Station() {
    name = district = municipality = township = line = "";
}

Station::Station(string name, string district, string municipality, string township, string line) {
    this->name = name;
    this->district = district;
    this->municipality = municipality;
    this->township = township;
    this->line = line;
}

string Station::getname() {return name;}
string Station::getdistrict() {return district;}
string Station::getmunicipality() {return municipality;}
string Station::gettownship() {return township;}
string Station::getline() {return line;}
