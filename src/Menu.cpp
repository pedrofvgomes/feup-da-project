#include "Menu.h"

#include <limits>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

// -------------------- Constructor -------------------- //

Menu::Menu() {
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
        replace(input.begin(), input.end(), '\\', '/');
        ifstream testNetwork(input + "network.csv");
        ifstream testStations(input + "stations.csv");
        if (testStations.good() && testNetwork.good()) {
            dataPath = input; return;
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
                costOptimizationDisplay();
                return;
            case 2:
                railway.setTrainPrices(getUserTrainPrices());
                costOptimizationDisplay();
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

void Menu::setUpSubRailway() {
    int input;

    setUpPrinter(4);

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option: ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                subrailway = railway;
                lineFailuresMenu();
                return;
            case 2:
                subrailway = railway;
                randomGenerateRailway();
                lineFailuresMenu();
                return;
            case 3:
                subrailway = railway;
                removeConnectionsRailway();
                lineFailuresMenu();
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
            system("clear || cls");
            cout << endl
                 << "   Please select the desired train prices:" << endl << endl
                 << "     1. Default prices" << endl << endl
                 << "     2. Custom prices" << endl << endl
                 << "   Select your option: ";
            break;
        case 2:
            system("clear || cls");
            cout << endl << "   -> Train Prices <-" << endl
                 << endl << "   STANDARD service : ";
            break;
        case 3:
            cout << endl << "   ALFA PENDULAR service : ";
            break;
        case 4:
            system("clear || cls");
            cout << endl
                 << "   Please select how you want to create the new sub railway:" << endl << endl
                 << "     1. Use the full railway" << endl << endl
                 << "     2. Random generate using a seed" << endl << endl
                 << "     3. Pick connections to remove" << endl << endl
                 << "   Select your option: ";
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
                setUpSubRailway();
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
    system("clear || cls");
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
    system("clear || cls");
    cout << endl
         << "   Basic Service Metrics" << endl
         << "   ---------------------------------------------------------------------" << endl
         << "   Please select your desired option by typing it on the selector intake" << endl << endl
         << "     1. Max number of trains between two stations" << endl << endl
         << "     2. Busiest connections of the grid" << endl << endl
         << "     3. Most important municipalities/districts" << endl << endl
         << "     4. Max number of trains arriving at a given station" << endl << endl << endl
         << "     9. Return to Main Menu" << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

void Menu::basicMaxFlow() {
    Station* source = receiveStation(true);
    Station* destination = receiveStation(false);
    unsigned int maxFlow = railway.edmondsKarp(source, destination);

    system("clear || cls");
    cout << endl
         << "   | MAX NUMBER OF TRAINS IN A SEGMENT |" << endl << endl;

    if (isStationOutputSafe(source))
        cout << "   SOURCE -> \"" << source->getName() << "\" station located in "
             << source->getMunicipality() << ", " << source->getDistrict() << "." << endl << endl;
    else
        cout << "   SOURCE -> \"" << source->getName() << "\" station." << endl << endl;

    if (isStationOutputSafe(destination))
        cout << "   DESTINATION -> \"" << destination->getName() << "\" station located in "
             << destination->getMunicipality() << ", " << destination->getDistrict() << "." << endl << endl;
    else
        cout << "   DESTINATION -> \"" << destination->getName() << "\" station." << endl << endl;

    cout << "   The maximum number of trains that can simultaneously travel between this two specific stations is of " << maxFlow << "." << endl;

    pressEnterToReturn();
    basicServiceMenu();
}

void Menu::basicMostBusy() {
    int input;
    auto stationList = railway.mostTrains();

    system("clear || cls");
    cout << endl
         << "   | BUSIEST LINE SEGMENTS |" << endl << endl
         << "   Please enter the number of pairs you wish to see : ";

    while (!(cin >> input)) {
        cout << endl << "   Please enter the number of pairs you wish to see : ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    auto it = stationList.begin();

    system("clear || cls");
    cout << endl << "   | BUSIEST LINE SEGMENTS |" << endl << endl;
    while (it != stationList.end() && input != 0) {
        cout << "   " << it->first << " - " << it->second << endl;
        it++; input--;
    }

    pressEnterToReturn();
    basicServiceMenu();
}

void Menu::basicMostImportant() {
    int input;

    system("clear || cls");
    cout << endl
         << "   | TOP K DISTRICTS/MUNICIPALITIES |" << endl << endl
         << "   Please enter the number of items you wish to see : ";

    while (!(cin >> input)) {
        cout << endl << "   Please enter the number of items you wish to see : ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    auto topDis = railway.topKDistricts(input);
    auto topMun = railway.topKMunicipalities(input);

    system("clear || cls");
    cout << endl << "   | DISTRICTS |" << endl << endl;
    for (const auto& p : topDis) { cout << "   " << p.second << " - " << p.first << endl; }

    cout << endl << "   | MUNICIPALITIES |" << endl << endl;
    for (const auto& p : topMun) { cout << "   " << p.second << " - " << p.first << endl; }

    pressEnterToReturn();
    basicServiceMenu();
}

void Menu::basicMaxFlowIntireGrid() {
    Station* station = receiveStation(false);
    unsigned int maxFlow = railway.maxTrainsToStation(station);

    system("clear || cls");
    cout << endl
         << "   | STATION ARRIVALS |" << endl;

    if (isStationOutputSafe(station))
        cout << endl << "   You've selected the " << station->getName() << " station located in "
             << station->getMunicipality() << ", " << station->getDistrict() << "." << endl;
    else
        cout << endl << "   You've selected the " << station->getName() << " station." << endl;

    cout << endl << "   Considering the entire grid, the maximum number of trains that can" << endl
         << endl << "     simultaneously travel between these two specific stations is of " << maxFlow << "." << endl;

    pressEnterToReturn();
    basicServiceMenu();
}

// ----------------- Cost Optimization ----------------- //

void Menu::costOptimizationDisplay() {
    Station* source = receiveStation(true);
    Station* destination = receiveStation(false);
    auto minCosts = railway.maxFlowMinCost(source, destination);

    system("clear || cls");
    cout << endl
         << "   | MAX NUMBER OF TRAINS WITH MIN COST |" << endl << endl;

    if (isStationOutputSafe(source))
        cout << "   SOURCE -> \"" << source->getName() << "\" station located in "
             << source->getMunicipality() << ", " << source->getDistrict() << "." << endl << endl;
    else
        cout << "   SOURCE -> \"" << source->getName() << "\" station." << endl << endl;

    if (isStationOutputSafe(destination))
        cout << "   DESTINATION -> \"" << destination->getName() << "\" station located in "
             << destination->getMunicipality() << ", " << destination->getDistrict() << "." << endl << endl;
    else
        cout << "   DESTINATION -> \"" << destination->getName() << "\" station." << endl << endl;

    cout << "   The optimized number of trains that can simultaneously travel between this two specific stations is of " << minCosts.first << " having a cost of " << minCosts.second << "€." << endl;

    pressEnterToReturn();
    mainMenu(false);
}

// ------------------- Line Failures ------------------- //

void Menu::lineFailuresMenu() {
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
    system("clear || cls");
    cout << endl
         << "   Reliability and Sensitivity to Line Failures" << endl
         << "   ---------------------------------------------------------------------" << endl
         << "   Please select your desired option by typing it on the selector intake" << endl << endl
         << "     1. Max flow between two stations with reduced connectivity." << endl << endl
         << "     2. Stations most affected by a segment failure." << endl << endl << endl
         << "     9. Return to Main Menu" << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

void Menu::failuresMaxFlow() {
    Station* source = receiveStation(true);
    Station* destination = receiveStation(false);
    unsigned int maxFlow = subrailway.edmondsKarp(source, destination);

    system("clear || cls");
    cout << endl
         << "   | MAX NUMBER OF TRAINS IN A SEGMENT - REDUCED CONNECTIVITY |" << endl << endl;

    if (isStationOutputSafe(source))
        cout << "   SOURCE -> \"" << source->getName() << "\" station located in "
             << source->getMunicipality() << ", " << source->getDistrict() << "." << endl << endl;
    else
        cout << "   SOURCE -> \"" << source->getName() << "\" station." << endl << endl;

    if (isStationOutputSafe(destination))
        cout << "   DESTINATION -> \"" << destination->getName() << "\" station located in "
             << destination->getMunicipality() << ", " << destination->getDistrict() << "." << endl << endl;
    else
        cout << "   DESTINATION -> \"" << destination->getName() << "\" station." << endl << endl;

    cout << endl << "   Considering the segment failures, the maximum number of trains that can" << endl
         << endl << "          simultaneously travel between these two specific stations is of " << maxFlow << "." << endl;

    pressEnterToReturn();
    lineFailuresMenu();
}

void Menu::failuresReport() {
    int input;

    system("clear || cls");
    cout << endl
         << "   | TOP K STATIONS MOST AFFECTED |" << endl << endl
         << "   Please enter the number of stations you wish to see : ";

    while (!(cin >> input)) {
        cout << endl << "   Please enter the number of items you wish to see : ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    vector<pair<string, unsigned int>> diff;
    auto railwayFlows = railway.maxFlowPerStation();
    auto subRailwayFlows = subrailway.maxFlowPerStation();

    for (auto station1 : railwayFlows) {
        if (station1.second != subRailwayFlows[station1.first]) {
            diff.push_back(make_pair(station1.first->getName(), station1.second - subRailwayFlows[station1.first]));
        }
    }
    sort(diff.begin(), diff.end(), sortByValue);

    auto it = diff.begin();

    system("clear || cls");
    cout << endl << "   | TOP K STATIONS MOST AFFECTED |" << endl << endl;
    while (it != diff.end() && input != 0) {
        cout << "   " << it->first << " - " << it->second << endl;
        it++; input--;
    }

    pressEnterToReturn();
    lineFailuresMenu();
}

// ----------------- Subrailway Manager ---------------- //

void Menu::randomGenerateRailway() {
    int n;

    system("clear || cls");
    cout << endl << "   | RANDOM GENERATOR |" << endl
         << endl << "   Please enter the number of connections you wish to remove : ";

    while (!(cin >> n)) {
        cout << endl << "   Please enter the number of connections you wish to remove : ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    if (subrailway.randomGenerateRailway(n))
        cout << endl << "   ! ALL CONNECTION SUCCESSFULLY REMOVED !" << endl;
    else
        cout << endl << "   ! ERROR !" << endl;
}

void Menu::removeConnectionsRailway() {
    int n;

    system("clear || cls");
    cout << endl << "   | REMOVE CONNECTIONS |" << endl
         << endl << "   Please enter the number of connections you wish to remove : ";

    while (!(cin >> n)) {
        cout << endl << "   Please enter the number of connections you wish to remove : ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    while (n != 0) {
        Station *source = receiveStation(true);
        Station *destination = receiveStation(false);
        if (subrailway.removeBidirectionalConnection(source, destination)) {
            n--;
            cout << endl << "   ! Connection removed successfully !" << endl
                 << endl << "   SOURCE -> " << source->getName() << endl
                 << endl << "   DESTINATION -> " << destination->getName() << endl;
        } else
            cout << endl << "   ! ERROR: STATIONS ARE NOT DIRECTLY CONNECTED !" << endl
                 << endl << "   SOURCE -> " << source->getName() << endl
                 << endl << "   DESTINATION -> " << destination->getName() << endl;
        pressEnterToContinue();
    }
}

// ----------------- Auxiliar Functions ---------------- //

Station* Menu::receiveStation(bool type) {
    string input;
    Station* stationptr;

    system("clear || cls");

    if (type)
        cout << endl << "   -> SOURCE <-" << endl
             << endl << "   Please enter a valid station name : ";
    else
        cout << endl << "   -> DESTINATION <-" << endl
             << endl << "   Please enter a valid station name : ";

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

void Menu::pressEnterToReturn() {
    cout << endl << "   Press ENTER to return...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void Menu::pressEnterToContinue() {
    cout << endl << "   Press ENTER to continue...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

bool Menu::isStationOutputSafe(Station* stationptr) {
    return !stationptr->getMunicipality().empty() && !stationptr->getDistrict().empty();
}

bool Menu::sortByValue(const pair<string, unsigned int> &a, const pair<string ,unsigned int> &b) {
    return (a.second > b.second);
}

// -------------------- END OF FILE -------------------- //