#include <iostream>
#include "read.cpp"
using namespace std;

int main(){
    auto stations = readstations();
    for(auto &i : stations) cout << i.first << endl;
}