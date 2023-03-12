#include <stations.cpp>
#include <map>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string s){
    vector<string> result;
    stringstream sstream(s);
    while(sstream.good()){
        string sub;
        getline(sstream,sub,',');
        result.push_back(sub);
    }
    return result;
}

map<string, Station> readstations(){
    map<string, Station> stations;
    ifstream file;
    string l;
    string name, municipality, district, township, line;

    file.open("C:\\Users\\pedro\\Desktop\\feup-da\\feup-da-project\\Project1Data\\stations.csv");

    getline(file, l);
    getline(file, l);

    while(l.size()>0){
        auto s = split(l);

        name = s[0];
        municipality = s[1];
        district = s[2];
        township = s[3];
        line = s[4];

        stations[name] = Station(name, municipality, district, township, line);

        getline(file, l);
    }
    file.close();

    return stations;
}
