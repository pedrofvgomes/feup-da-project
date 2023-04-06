#include "Menu.h"

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

// -------------------- Constructor -------------------- //

Menu::Menu() {
    this->dataPath = "";
    setUpMenu();
}

// ----------------------- SetUp ----------------------- //

void Menu::setUpMenu() {
    int input;

    setUpPrinter(0);

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option: ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                dataPath = "../data/";
                railway.createNetwork(dataPath);
                mainMenu(true);
                return;
            case 2:
                setUpCustom();
                railway.createNetwork(dataPath);
                mainMenu(true);
                return;
            default:
                cout << endl << "   Please select a valid option: ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option: ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::setUpCustom() {
    string input;

    cout << endl << "   Please enter the data file's path: ";

    getline(cin >> ws, input);

    do {
        if (input.back() != '/')
            input.push_back('/');
        std::replace(input.begin(), input.end(), '\\', '/');
        ifstream testNetwork(input + "network.csv");
        ifstream testStations(input + "stations.csv");
        if (testStations.good() && testNetwork.good()) {
            dataPath = input;
            return;
        }
        cout << endl << "   Please enter a valid path: ";
        getline(cin >> ws, input);
    }
    while(true);
}

void Menu::setUpTrainPricesMenu() {
    int input;

    setUpPrinter(1);

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option: ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                railway.setTrainPrices(pair<int,int>(2,4));
                costOptimizationMenu();
                return;
            case 2:
                railway.setTrainPrices(getUserTrainPrices());
                costOptimizationMenu();
                return;
            default:
                cout << endl << "   Please select a valid option: ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option: ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

pair<int,int> Menu::getUserTrainPrices() {
    int input;
    pair<int,int> res(0,0);

    setUpPrinter(2);
    while (!(cin >> input)) {
        cout << endl << "   Please enter a valid price : ";
        cin.clear(); cin.ignore(10000, '\n');
    }
    res.first = input;

    setUpPrinter(3);
    while (!(cin >> input)) {
        cout << endl << "   Please enter a valid price : ";
        cin.clear(); cin.ignore(10000, '\n');
    }
    res.second = input;

    return res;
}

void Menu::setUpPrinter(int flag) {
    switch (flag) {
        case 0:
            cout << endl
                 << "   Please select the data file's location:" << endl << endl
                 << "     1. Data folder" << endl << endl
                 << "     2. Custom path" << endl << endl
                 << "   Select your option: ";
            break;
        case 1:
            system("cls");
            cout << endl
                 << "   Please select the desired train prices:" << endl << endl
                 << "     1. Default prices" << endl << endl
                 << "     2. Custom prices" << endl << endl
                 << "   Select your option: ";
            break;
        case 2:
            system("cls");
            cout << endl << "   -> Train Prices <-" << endl
                 << endl << "   STANDARD service : ";
            break;
        case 3:
            cout << endl << "   ALFA PENDULAR service : ";
            break;
        default:
            throw invalid_argument("Invalid option selected.");
    }
}

// --------------------- Main Menu --------------------- //

void Menu::mainMenu(bool isLoading) {
    int input;

    mainMenuOptions(isLoading);

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option : ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                basicServiceMenu();
                return;
            case 2:
                setUpTrainPricesMenu();
                return;
            case 3:
                lineFailuresMenu();
                return;
            default:
                cout << endl << "   Please select a valid option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::mainMenuOptions(bool isLoading) {
    system("cls");
    if (isLoading) {
        cout << endl
             << "   Railway Network Manager                 A.Neves | E.Miranda | P.Gomes" << endl
             << "   ---------------------------------------------------------------------" << endl;
    }
    else
        cout << endl
             << "   Main Menu" << endl
             << "   ---------------------------------------------------------------------" << endl;

    cout << "   Please select your desired option by typing it on the selector intake" << endl << endl
         << "     1. Basic Service Metrics" << endl << endl
         << "     2. Operation Cost Optimization" << endl << endl
         << "     3. Reliability and Sensitivity to Line Failures" << endl << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

// ------------------- Basic Service ------------------- //

void Menu::basicServiceMenu() {
    int input;

    basicServiceMenuPrinter();

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option : ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                basicMaxFlow();
                return;
            case 2:
                basicMostBusy();
                return;
            case 3:
                basicMostImportant();
                return;
            case 4:
                basicMaxFlowIntireGrid();
                return;
            case 9:
                mainMenu(false);
                return;
            default:
                cout << endl << "   Please select a valid option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::basicServiceMenuPrinter() {
    system("cls");
    cout << endl
         << "                                                   Basic Service Metrics" << endl
         << "   ---------------------------------------------------------------------" << endl
         << "   Please select your desired option by typing it on the selector intake" << endl << endl
         << "     1. Flow of trains between two stations" << endl << endl
         << "     2. Busiest connections of the grid" << endl << endl
         << "     3. Most important municipalities/districts" << endl << endl
         << "     4. Manage arrivals at given station" << endl << endl << endl
         << "     9. Return to Main Menu" << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

void Menu::basicMaxFlow() { //TODO

}

void Menu::basicMostBusy() { //TODO

}

void Menu::basicMostImportant() { //TODO

}

void Menu::basicMaxFlowIntireGrid() { //TODO

}

// ----------------- Cost Optimization ----------------- //

void Menu::costOptimizationMenu() { //TODO
    costOptimizationMenuPrinter();
}

void Menu::costOptimizationMenuPrinter() { //TODO

}

// ------------------- Line Failures ------------------- //

void Menu::lineFailuresMenu() { //TODO
    int input;

    lineFailuresMenuPrinter();

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option : ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                failuresMaxFlow();
                return;
            case 2:
                failuresReport();
                return;
            case 9:
                mainMenu(false);
                return;
            default:
                cout << endl << "   Please select a valid option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::lineFailuresMenuPrinter() {
    system("cls");
    cout << endl
         << "                            Reliability and Sensitivity to Line Failures" << endl
         << "   ---------------------------------------------------------------------" << endl
         << "   Please select your desired option by typing it on the selector intake" << endl << endl
         << "     1. Flow of trains between two stations with reduced connectivity." << endl << endl
         << "     2. Stations affected by a segment failure." << endl << endl << endl
         << "     9. Return to Main Menu" << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

void Menu::failuresMaxFlow() { //TODO

}

void Menu::failuresReport() { //TODO

}

// ----------------- Auxiliar Functions ---------------- //

Station* Menu::receiveStation(bool type) {
    string input;
    Station* stationptr;

    system("cls");
    if (type)
        cout << endl << "   -> SOURCE <-" << endl;
    else
        cout << endl << "   -> DESTINATION <-" << endl;

    cout << endl << "   Please enter a valid station name : ";

    getline(cin >> ws, input);

    do {
        if (railway.doesStationExist(input, stationptr)) {
            if (isStationOutputSafe(stationptr))
                cout << endl << "   ! FOUND !" << endl
                     << endl << "   You've selected the " << stationptr->getName() << " station located in "
                     << stationptr->getMunicipality() << ", " << stationptr->getDistrict() << "." << endl;
            else
                cout << endl << "   ! FOUND !" << endl
                     << endl << "   You've selected the " << stationptr->getName() << " station." << endl;
            if (confirmChoice()) return stationptr;
        }
        cout << endl << "   Please enter a valid station name : ";
        getline(cin >> ws, input);
    }
    while(true);
}

bool Menu::confirmChoice() {
    int input;

    cout << endl
         << "     1. Confirm choice and proceed" << endl << endl
         << "     2. Go back and make changes" << endl << endl
         << "   Select your option : ";

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option : ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 1:
                return true;
            case 2:
                return false;
            default:
                cout << endl << "   Please select a valid option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

bool Menu::isStationOutputSafe(Station* stationptr) {
    return !stationptr->getMunicipality().empty() && !stationptr->getDistrict().empty();
}

// -------------------- END OF FILE -------------------- //
