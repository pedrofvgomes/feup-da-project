#include "Menu.h"

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

    setUpPrinter(true);

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option: ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                railway.createNetwork("../data/");
                mainMenu(true);
                return;
            case 2:
                railway.createNetwork(setUpCustom());
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

std::string Menu::setUpCustom() {
    string input;

    setUpPrinter(false);

    getline(cin >> ws, input);

    do {
        if (input.back() != '/')
            input.push_back('/');
        std::replace(input.begin(), input.end(), '\\', '/');
        ifstream testNetwork(input + "network.csv");
        ifstream testStations(input + "stations.csv");
        if (testStations.good() && testNetwork.good())
            return input;
        cout << endl << "   Please enter a valid path: ";
        getline(cin >> ws, input);
    }
    while(true);
}

void Menu::setUpPrinter(bool flag) {
    if (!flag) //setUpCustom() call
        cout << endl << "   Please enter the data file's path: ";
    else //setUpMenu() call
        cout << endl
             << "   Please select the data file's location:" << endl << endl
             << "     1. Data folder" << endl << endl
             << "     2. Custom path" << endl << endl
             << "   Select your option: ";
}

// --------------------- Main Menu --------------------- //

void Menu::mainMenu(bool isLoading) { //TODO
    int input;

    mainMenuOptions(isLoading);

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option" << endl
             << endl << "   Select your option : ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                return;
            case 2:
                return;
            case 9:
                //helpMenu();
                return;
            default:
                cout << endl << "   Please select a valid option" << endl
                     << endl << "   Select your option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option" << endl
                         << endl << "   Select your option : ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::mainMenuOptions(bool isLoading) { //TODO
    if (isLoading) {
        cout << endl << endl
             << "   -------------------------------------------------------------------------------" << endl
             << "   Railway Network Manager                           A.Neves | E.Miranda | P.Gomes" << endl
             << "   -------------------------------------------------------------------------------" << endl;
    }
    else
        cout << endl
             << "   -------------------------------------------------------------------------------" << endl
             << "                                      MAIN MENU                                   " << endl
             << "   -------------------------------------------------------------------------------" << endl;

    cout << "   Please select your desired option by typing it on the selector intake" << endl << endl
         << "     1. " << endl << endl
         << "     2. " << endl << endl << endl
         << "     9. I need a hand" << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

/*

// ----------------- Find Flights Menu ----------------- //

void Menu::findFlightFirstMenu() {
    int input;

    findFlightFirstMenuOptions();

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option" << endl;
        Sleep(350);
        cout << endl << "   Select your option : ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                findFlightSecondMenu(findFlightEnterString());
                return;
            case 2:
                findFlightSecondMenu(findFlightEnterCoordinates());
                return;
            case 9:
                mainMenu(false);
                return;
            default:
                cout << endl << "   Please select a valid option" << endl;
                Sleep(350);
                cout << endl << "   Select your option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option" << endl;
                    Sleep(350);
                    cout << endl << "   Select your option : ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::findFlightFirstMenuOptions() {
    cout << endl
         << "   ---------------------------------------------------------------------" << endl
         << "                               Find a Flight                            " << endl
         << "   ---------------------------------------------------------------------" << endl
         << "   So, are you trying to use the main functionality of this program?" << endl
         << "   Sure, but first you need to provide a starting point." << endl
         << "   You can either provide a city, an airport, or a pair of coordinates:" << endl << endl
         << "     1. Provide an Airport/City" << endl << endl
         << "     2. Provide Coordinates"<< endl << endl << endl
         << "     9. Return to Main Menu" << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

void Menu::findFlightSecondMenu(string code) {
    int input;

    findFlightSecondMenuOptions();

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option" << endl;
        Sleep(350);
        cout << endl << "   Select your option : ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                findFlightThirdMenu(code,findFlightEnterString());
                return;
            case 2:
                findFlightThirdMenu(code,findFlightEnterCoordinates());
                return;
            case 9:
                mainMenu(false);
                return;
            default:
                cout << endl << "   Please select a valid option" << endl;
                Sleep(350);
                cout << endl << "   Select your option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option" << endl;
                    Sleep(350);
                    cout << endl << "   Select your option : ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::findFlightSecondMenuOptions() {
    cout << endl
         << "   ---------------------------------------------------------------------" << endl << endl
         << "   You now need to choose your destination." << endl
         << "   Again, either provide a city, an airport, or a pair of coordinates" << endl << endl
         << "     1. Provide an Airport/City" << endl << endl
         << "     2. Provide Coordinates"<< endl << endl << endl
         << "     9. Return to Main Menu" << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

void Menu::findFlightThirdMenu(string code1, string code2) {
    int input;

    findFlightThirdMenuOptions();

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option" << endl;
        Sleep(350);
        cout << endl << "   Select your option : ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                findFlightFinalMenu(code1,code2,findFlightPickAirlines(true),false);
                return;
            case 2:
                findFlightFinalMenu(code1,code2,findFlightPickAirlines(false),false);
                return;
            case 3:
                findFlightFinalMenu(code1,code2,findFlightPickAirlines(false),true);
                return;
            case 9:
                mainMenu(false);
                return;
            default:
                cout << endl << "   Please select a valid option" << endl;
                Sleep(350);
                cout << endl << "   Select your option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option" << endl;
                    Sleep(350);
                    cout << endl << "   Select your option : ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::findFlightThirdMenuOptions() {
    cout << endl
         << "   ---------------------------------------------------------------------" << endl << endl
         << "   You're one step away from finding your perfect flight." << endl
         << "   You now need to pick the airlines that you desire." << endl
         << "   You can choose every airline, choose just some or even discard unwanted ones." << endl << endl
         << "     1. Use all available airlines." << endl << endl
         << "     2. Pick a few airlines"<< endl << endl
         << "     3. Discard some airlines"<< endl << endl << endl
         << "     9. Return to Main Menu" << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

void Menu::findFlightFinalMenu(string code1, string code2, vector<string> airlines, bool avoid) {
    int input;

    vector<string> path = data.flighBFSCaller(code1,code2,airlines,avoid);

    if (path.size() != 0) {
        findFlightFinalMenuOptions(1); int countFlight = 1;
        for (int i = path.size() - 1; i > 0; i--) {
            Airport *airport1 = data.getAirport(path[i]);
            Airport *airport2 = data.getAirport(path[i-1]);
            Airline *airline = data.getAirlineCaller(airport1->getIndex(),airport2->getIndex(),airlines,avoid);
            cout << endl << "   " << countFlight << numbers[countFlight] << " Flight" << "       ";
            cout << airline->getCode() << " " << airline->getName() << endl << endl;
            cout << "   Departure from : " << airport1->getCode() << " " << airport1->getName() << endl
                 << "                    " << airport1->getCity() << ", " << airport1->getCountry() << endl
                 << "   Arrival in :     " << airport2->getCode() << " " << airport2->getName() << endl
                 << "                    " << airport2->getCity() << ", " << airport2->getCountry() << endl;
            countFlight++;
        }
    }

    if (path.size() == 0)
        findFlightFinalMenuOptions(0);
    else
        findFlightFinalMenuOptions(2);

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option" << endl;
        Sleep(350);
        cout << endl << "   Select your option : ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 8:
                findFlightFirstMenu();
                return;
            case 9:
                mainMenu(false);
                return;
            default:
                cout << endl << "   Please select a valid option" << endl;
                Sleep(350);
                cout << endl << "   Select your option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option" << endl;
                    Sleep(350);
                    cout << endl << "   Select your option : ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::findFlightFinalMenuOptions(int option) { // CODE: 0-NOT_FOUND 1-FOUND 2-EXIT
    switch (option) {
        case 0:
            cout << endl
                 << "   ---------------------------------------------------------------------" << endl
                 << "                               Find a Flight                            " << endl
                 << "   ---------------------------------------------------------------------" << endl
                 << "   Wow! You have managed to search for an inexistent flight." << endl
                 << "   Next time please check if the flight is possible before searching." << endl << endl
                 << "     8. Search for another flight" << endl << endl
                 << "     9. Return to Main Menu" << endl
                 << "     0. Exit application" << endl << endl
                 << "   Select your option : ";
            break;
        case 1:
            cout << endl
                 << "   ---------------------------------------------------------------------" << endl
                 << "                               Find a Flight                            " << endl
                 << "   ---------------------------------------------------------------------" << endl
                 << "   Here is the result of your search." << endl << endl
                 << "   --------------------------------------------" << endl;
            break;
        case 2:
            cout << endl
                 << "   --------------------------------------------" << endl << endl
                 << "     8. Search for another flight" << endl << endl
                 << "     9. Return to Main Menu" << endl
                 << "     0. Exit application" << endl << endl
                 << "   Select your option : ";
            break;
    }
}

// ---------------- Find Flights Inputs ---------------- //

string Menu::findFlightEnterString() {
    string input;

    findFlightEnterStringPrinter();

    getline(cin >> ws, input);

    do {
        if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos) {
            if (input.size() == 3) {
                if (data.doesAirportCodeExist(input)) {
                    input = data.toUpper(input);
                    cout << endl << "   You've selected " << data.getAirport(input)->getCode() << " | "
                         << data.getAirport(input)->getName() << "." << endl;
                    return input;
                }
            }
            else {
                auto searchResult = data.doesAirportExist(input);
                if (searchResult.first) {
                    cout << endl << "   You've selected " << data.getAirport(searchResult.second)->getCode() << " | "
                         << data.getAirport(searchResult.second)->getName() << "." << endl;
                    return searchResult.second;
                }
            }
        }
        cout << endl << "   Please enter a valid code/name." << endl;
        Sleep(350);
        cout << endl << "   Please enter the desired Airport/City : ";
        getline(cin >> ws, input);
    }
    while(true);
}

void Menu::findFlightEnterStringPrinter() {
    cout << endl << "   ---------------------------------------------------------------------" << endl << endl
         << "   Please enter the desired Airport/City : ";
}

string Menu::findFlightEnterCoordinates() {
    string inputLat,inputLon; double lat,lon;

    cout << endl << "   ---------------------------------------------------------------------" << endl << endl
         << "   Please enter the desired latitude : "; getline(cin >> ws, inputLat);
    findFlightEnterCoordinatesPrinter(false); getline(cin >> ws, inputLon);

    do {
        try {
            lat = stod(inputLat); lon = stod(inputLon);
            string searchResult = data.doesAirportCoordinatesExist(lat,lon);
            cout << endl << "   You've selected " << data.getAirport(searchResult)->getCode() << " | " << data.getAirport(searchResult)->getName() << "." << endl;
            return searchResult;
        }
        catch(invalid_argument) {}
        cout << endl << endl << "   ! Please enter a valid coordinates pair. !" << endl;
        Sleep(350);
        findFlightEnterCoordinatesPrinter(true); getline(cin >> ws, inputLat);
        findFlightEnterCoordinatesPrinter(false); getline(cin >> ws, inputLon);
    }
    while(true);
}

void Menu::findFlightEnterCoordinatesPrinter(bool first) {
    if(first)
        cout << endl << endl
             << "   Please enter the desired latitude : ";
    else
        cout << endl << endl
             << "   Please enter the desired longitude : ";
}

vector<string> Menu::findFlightPickAirlines(bool empty) {
    string input; vector<string> result;

    if(empty) return result;

    findFlightPickAirlinesPrinter(true);

    getline(cin >> ws, input);

    do {
        if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos) {
            if (data.toUpper(input) == "NEXT")
                return result;
            if ((input.size() == 3) && (data.doesAirlineCodeExist(input))) {
                input = data.toUpper(input);
                cout << endl << "   You've selected " << data.getAirlineInMap(input)->getCode() << " | "
                     << data.getAirlineInMap(input)->getName() << "." << endl;
                result.push_back(input);
            }
            else {
                auto searchResult = data.doesAirlineExist(input);
                if (searchResult.first) {
                    cout << endl << "   You've selected " << data.getAirport(searchResult.second)->getCode() << " | "
                         << data.getAirport(searchResult.second)->getName() << "." << endl;
                    result.push_back(searchResult.second);
                }
            }
        }
        else {
            cout << endl << "   Please enter a valid input." << endl;
            Sleep(350);
        }
        cout << endl << "   Please enter the Airline descriptor : ";
        getline(cin >> ws, input);
    }
    while(true);
}

void Menu::findFlightPickAirlinesPrinter(bool first) {
    if (first) {
        cout << endl
             << "   ---------------------------------------------------------------------" << endl << endl
             << "   To advance to the result page, please type \"NEXT\"." << endl;
    }
    cout << endl << "   Please enter the Airline descriptor : ";
}

// ----------------- Airport Info Menu ----------------- //

void Menu::airportInfoMenu() {
    string input; bool clear; int n, inputNumber, inputSec, airCode; vector<string> temp;

    cout << endl
         << "   ---------------------------------------------------------------------" << endl
         << "                               AIRPORT INFO                             " << endl
         << "   ---------------------------------------------------------------------" << endl << endl
         << "   Please enter the desired airport's code or name : "; getline(cin >> ws, input);

    do {
        clear = false;
        if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos) {
            if (input.size() == 3)
                if (data.doesAirportCodeExist(input)) {
                    input = data.toUpper(input);
                    clear = true;
                }
                else {
                    auto searchResult = data.doesAirportExist(input);
                    if (searchResult.first)
                        input = searchResult.second;
                    clear = true;
                }
        }
        if (!clear) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << endl << "   Please enter a valid Airport descriptor : "; getline(cin >> ws, input);
        }
    }
    while (!(clear)); clear = false;

    Airport *airport = data.getAirport(input); airCode = airport->getIndex();

    cout << endl
         << "   --> " << airport->getCode() << " | " << airport->getName() << " <--" << endl << endl
         << "   You've selected " << airport->getCode() << " most commonly known as " << airport->getName() << "." << endl << endl
         << "   It's located in the city of " << airport->getCity() << " in " << airport->getCountry() << "." << endl << endl;

    cout << "   Info Menu :" << endl << endl
         << "     1. See how many Flights are available in the Airport." << endl
         << "     2. Check the different Airline companies that operate in the Airport" << endl
         << "     3. Countries reachable with X Flights" << endl
         << "     4. Cities reachable with X Flights" << endl
         << "     5. Airports reachable with X Flights" << endl << endl
         << "     9. Return to Main Menu" << endl
         << "     0. Exit application" << endl << endl;

    do {
        cout << "   Select your option : ";
        while (!(cin >> inputNumber)) {
            cout << endl << "   Please select a valid option" << endl;
            Sleep(350);
            cout << endl << "   Select your option : ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        switch (inputNumber) {
            case 0:
                return;
            case 1:
                n = data.numberFlightsAirportCaller(airCode);
                cout << endl << "   This Airport has " << n << " different flights." << endl << endl;
                break;
            case 2:
                temp = data.differentAirlinesCaller(airCode);
                cout << endl << "   This Airport works with " << temp.size() << " different airline companies."
                     << endl << "   Press 1 to display them all, 2 to ignore :";
                while (!(cin >> inputSec)) {
                    cout << endl << "   Please select a number." << endl;
                    Sleep(350);
                    cout << endl << "   Select your option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
                if (inputSec == 1) {
                    cout << endl <<"   " << airport->getCode() << " Airline List :" << endl;
                    for(string s : temp)
                        cout << "     "<< s << endl;
                }
                cout << endl;
                break;
            case 3:
                cout << endl << "   This feature allow you to see which countries are achieveble"
                     << endl << "   with a certain numbers of flights starting in this Airport."
                     << endl << "   To continue please enter the number you desire :";
                while (!(cin >> inputSec)) {
                    cout << endl << "   Please select a number." << endl;
                    Sleep(350);
                    cout << endl << "   Select your option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
                temp = data.reachableCountriesCaller(input,inputSec);
                cout << "   This Airport flies to " << temp.size() << " different countries."
                     << endl << "   Press 1 to display them all, 2 to ignore :";
                while (!(cin >> inputSec)) {
                    cout << endl << "   Please select a number." << endl;
                    Sleep(350);
                    cout << endl << "   Select your option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
                if (inputSec == 1) {
                    cout << endl <<"   " << airport->getCode() << " Countries List :" << endl;
                    for(string s : temp)
                        cout << "     "<< s << endl;
                }
                cout << endl;
                break;
            case 4:
                cout << endl << "   This feature allow you to see which cities are achieveble"
                     << endl << "   with a certain numbers of flights starting in this Airport."
                     << endl << "   To continue please enter the number you desire :";
                while (!(cin >> inputSec)) {
                    cout << endl << "   Please select a number." << endl;
                    Sleep(350);
                    cout << endl << "   Select your option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
                temp = data.reachableCitiesCaller(input,inputSec);
                cout << endl << "   This Airport flies to " << temp.size() << " different cities."
                     << endl << "   Press 1 to display them all, 2 to ignore :";
                while (!(cin >> inputSec)) {
                    cout << endl << "   Please select a number." << endl;
                    Sleep(350);
                    cout << endl << "   Select your option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
                if (inputSec == 1) {
                    cout << endl <<"   " << airport->getCode() << " Cities List :" << endl;
                    for(string s : temp)
                        cout << "     "<< s << endl;
                }
                cout << endl;
                break;
            case 5:
                cout << endl << "   This feature allow you to see which airports are achieveble"
                     << endl << "   with a certain numbers of flights starting in this Airport."
                     << endl << "   To continue please enter the number you desire :";
                while (!(cin >> inputSec)) {
                    cout << endl << "   Please select a number." << endl;
                    Sleep(350);
                    cout << endl << "   Select your option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
                temp = data.reachableAirportsCaller(input,inputSec);
                cout << endl << "   This Airport flies to " << temp.size() << " different airports."
                     << endl << "   Press 1 to display them all, 2 to ignore :";
                while (!(cin >> inputSec)) {
                    cout << endl << "   Please select a number." << endl;
                    Sleep(350);
                    cout << endl << "   Select your option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
                if (inputSec == 1) {
                    cout << endl <<"   " << airport->getCode() << " Airport Connection List :" << endl;
                    for(string s : temp)
                        cout << "     "<< s << endl;
                }
                cout << endl;
                break;
            case 9:
                mainMenu(false);
                return;
            default:
                cout << endl << "   Please select a valid option" << endl;
                Sleep(350);
                cout << endl << "   Select your option : ";
                while (!(cin >> inputNumber)) {
                    cout << endl << "   Please select a valid option" << endl;
                    Sleep(350);
                    cout << endl << "   Select your option : ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

// --------------------- Help Menu --------------------- //

void Menu::helpMenu() {
    int input;

    helpMenuOptions();

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option" << endl;
        Sleep(350);
        cout << endl << "   Select your option : ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 9:
                mainMenu(false);
                return;
            default:
                cout << endl << "   Please select a valid option" << endl;
                Sleep(350);
                cout << endl << "   Select your option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option" << endl;
                    Sleep(350);
                    cout << endl << "   Select your option : ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::helpMenuOptions() {
    cout << endl
         << "   ---------------------------------------------------------------------" << endl
         << "                                 HELP MENU                              " << endl
         << "   ---------------------------------------------------------------------" << endl << endl
         << "   -> Find a Flight <-" << endl << endl
         << "   The Find a Flight option allows you to search our database to find\n"
         << "   the best flight for your needs. Using graphs to process the data\n"
         << "   efficiently, it assures you the best bang for your buck. Exploring the\n"
         << "   depths of the mountain of data shows you the details of the selected\n"
         << "   flight. If you're planning a weekend in a foreign city, or you're\n"
         << "   just crazy enough to fly to whichever coordinates, we got you covered.\n"
         << "   Even if you are on a tight budget, it can guarantee you a safe flight.\n"
         << "   You can choose which air companies are used to achieve that goal." << endl << endl
         << "   -> Airport Information <-" << endl <<  endl
         << "   The \"Airport Information\" option presents you all the\n"
         << "   available information about a given airport. It gives you the\n"
         << "   possibility to analise all the essential information before\n"
         << "   planning your next flight." << endl << endl
         << "     9. Return to Main Menu" << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

*/

// -------------------- END OF FILE -------------------- //
