#include <iostream>
#include "src/read.cpp"

using namespace std;

int main(){
    vector<string> v = {"Â","â","Á", "á", "Ã", "ã", "À", "à", "É", "é", "Ê", "ê", "Í", "í", "Ó", "ó", "Õ", "õ", "Ú", "ú"};

    auto stations = readstations();

    string c = "çÇ";
    cout << c[0][0] << c[0][1]
}