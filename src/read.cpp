#include <station.cpp>
#include <map>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

/* characters to correct
 * Á, á, Â, â, Ã, ã, À, à
 * É, é, Ê, ê
 * Í, í
 * Ó, ó, Õ, õ
 * Ú, ú
 * Ç, ç
 * each one is actually interpreted as 2 characters,
 * and the code of the first one is always -61
 * the function below finds the code -61 then manually
 * changes them to its 'normal' version, without the accent or tilde,
 * depending on the second character's code
 */

string correct(string& s){
    if(s.empty()) return s;
    string current;
    for(int i=0; i<s.size()-1; i++) {
        if (s[i] == -61) {
            // A
            if (s[i + 1] == -125 || s[i+1] ==-126 || s[i + 1] == -127 || s[i+1] == -128)
                current += "A";
            // a
            if (s[i + 1] == -93 || s[i + 1] == -94 || s[i + 1] == -95 || s[i + 1] == -96)
                current += "a";
            // E
            if (s[i + 1] == -119 || s[i + 1] == -118)
                current += "E";
            // e
            if (s[i + 1] == -87 || s[i + 1] == -86)
                current += "e";
            // I
            if (s[i + 1] == -115)
                current += "I";
            // i
            if (s[i + 1] == -83)
                current += "i";
            // O
            if (s[i + 1] == -109 || s[i + 1] == -107)
                current += "O";
            // o
            if (s[i + 1] == -77 || s[i + 1] == -75)
                current += "o";
            // U
            if (s[i + 1] == -102)
                current += "U";
            // u
            if (s[i + 1] == -70)
                current += "u";
        } else if (int(s[i]) > 0) current += s[i];
    }
    return int(s[s.size()-1]) > 0 ? current+s[s.size()-1] : current;
}

vector<string> split(string& s){
    vector<string> result, result2;
    stringstream sstream(s);
    while(sstream.good()){
        string sub;
        getline(sstream,sub,',');
        result.push_back(sub);
    }
    // correct commas that don't count
    int found = 0;
    for(auto i: result){
        string current;
        for(auto c : i){
            if(c=='"'){
                if(found==0) found=1;
                else {
                    current+=i;
                    found=0;
                }
            }
            if(current.empty()) result2.push_back(i);
            else if(found==0) result.push_back(current);
        }
    }
    return result;
}

map<string, Station> readstations(){
    int counter = 0;
    map<string, Station> stations;
    ifstream file;
    string l;
    string name, municipality, district, township, line;

    file.open(R"(C:\Users\pedro\Desktop\feup-da\feup-da-project\Project1Data\stations.csv)");

    getline(file, l);
    getline(file, l);

    while(l.size()>0){
        auto s = split(l);

        name = correct(s[0]);
        municipality = correct(s[1]);
        district = correct(s[2]);
        township = correct(s[3]);
        line = correct(s[4]);

        stations[name] = Station(name, district, municipality, township, line);
        getline(file, l);
    }
    file.close();

    return stations;
}
