#ifndef feup_da_project_stations_h
#define feup_da_project_stations_h
#include <string>
using namespace std;

class Station{
    string name;
    string district;
    string municipality;
    string township;
    string line;
public:
    Station();
    Station(string name, string district, string municipality, string township, string line);
    string getname();
    string getdistrict();
    string getmunicipality();
    string gettownship();
    string getline();
};

#endif