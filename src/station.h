#ifndef feup_da_project_stations_h
#define feup_da_project_stations_h
#include <string>
using namespace std;

class Station{
public:
    Station();
    Station(string name, string district, string municipality, string township, string line);
    string getName();
    string getDistrict();
    string getMunicipality();
    string getTownship();
    string getLine();
protected:
    string name;
    string district;
    string municipality;
    string township;
    string line;
};

#endif