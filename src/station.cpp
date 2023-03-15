#include "station.h"
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

string Station::getName() {return name;}
string Station::getDistrict() {return district;}
string Station::getMunicipality() {return municipality;}
string Station::getTownship() {return township;}
string Station::getLine() {return line;}
