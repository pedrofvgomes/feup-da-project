#ifndef MENU_H
#define MENU_H

#include "Network.h"

/**
 * @brief Manages the application's interface.
 *
 * This class manages the application's interface by receiving user inputs and sending commands to the <b>Network</b> class to perform the requested tasks.
 */
class Menu {
public:
    /**
     * @brief Constructor for the Menu class.
     *
     * This constructor initializes the program by calling the <em>setUpMenu()</em> function.
     */
    Menu();

    /**
     * @brief Organizes the creation of the program's main railway.
     *
     * This function asks the user to specify whether the data files are located in the default location or if the user prefers to provide a custom path.
     * Based on the user's input, the program's main railway are set up accordingly.
     */
    void setUpMenu();
    /**
     * @brief Handles user input for the location of the data file.
     *
     * Prompts the user to specify the location of the data and verifies the validity of the path provided.
     * Defines the <b>dataPath</b> variable with the validated input.
     */
    void setUpCustom();
    /**
     * @brief Organizes the creation of the network's train prices.
     *
     * This function asks the user to specify whether the train prices to be used will be the default or if the user prefers to provide different values.
     * Based on the user's input, the function calls the respective functions.
     */
    void setUpTrainPricesMenu();
    /**
     * @brief Handles user input for the custom train prices.
     *
     * Prompts the user to specify the train prices to be used and sends the information back to the <em>setUpTrainPricesMenu</em> function.
     *
     * @return The train prices defined by the user.
     */
    static std::pair<int,int> getUserTrainPrices();
    /**
     * @brief Organizes the creation of the program's secondary railway.
     *
     * This function asks the user to specify wich method is to be used to generate the secondary railway.
     * Based on the user's input, the program's calls the respective functions.
     */
    void setUpSubRailway();
    /**
     * @brief Prints the Set Up Menu options to the terminal.
     *
     * Outputs the Set Up options based on the flag that is passed as a parameter, which can modify the output.
     *
     * @param flag A boolean value that indicates the context in which this function is being called.
     */
    static void setUpPrinter(int flag);

    /**
     * @brief Organizes the creation of the Main Menu.
     *
     * This function is responsible for handling user input for selecting menus and verifying if the input is valid or not.
     * Once a valid input is received, it calls the respective functions associated with the selected menu.
     *
     * @param isLoading A boolean flag indicating if the program is starting or already running.
     */
    void mainMenu(bool isLoading);
    /**
     * @brief Prints the Main Menu options on the terminal.
     *
     * This function prints the Main Menu options on the terminal based on the value of the <em>isLoading</em> flag.
     *
     * @param isLoading A boolean flag indicating if the program is starting or already running.
     */
    static void mainMenuOptions(bool isLoading);

    /**
     * @brief Organizes the creation of the Basic Service Metrics Menu.
     *
     * This function is responsible for handling user input for selecting menus and verifying if the input is valid or not.
     * Once a valid input is received, it calls the respective functions associated with the selected menu.
     */
    void basicServiceMenu();
    /**
     * @brief Prints the Basic Service Metrics Menu options on the terminal.
     *
     * This function prints the Basic Service Metrics Menu options on the terminal.
     */
    static void basicServiceMenuPrinter();
    /**
     * @brief Organizes the display of the Max Number Of Trains In A Segment Functionality.
     *
     * This function is responsible for handling the displaying of the requested information.
     * Once a valid input is received, it calls the respective functions and displays the information in a user-friendly way.
     */
    void basicMaxFlow();
    /**
     * @brief Organizes the display of the Busiest Line Segments Functionality.
     *
     * This function is responsible for handling the displaying of the requested information.
     * Once a valid input is received, it calls the respective functions and displays the information in a user-friendly way.
     */
    void basicMostBusy();
    /**
     * @brief Organizes the display of the Top K Districts/Municipalities Functionality.
     *
     * This function is responsible for handling the displaying of the requested information.
     * Once a valid input is received, it calls the respective functions and displays the information in a user-friendly way.
     */
    void basicMostImportant();
    /**
     * @brief Organizes the display of the Station Arrivals Functionality.
     *
     * This function is responsible for handling the displaying of the requested information.
     * Once a valid input is received, it calls the respective functions and displays the information in a user-friendly way.
     */
    void basicMaxFlowIntireGrid();

    /**
     * @brief Organizes the display of the Max Number Of Trains With Min Cost Functionality.
     *
     * This function is responsible for handling the displaying of the minimum cost travel between 2 stations.
     * Once a valid input is received, it calls the respective functions and displays the information in a user-friendly way.
     */
    void costOptimizationDisplay();

    /**
     * @brief Organizes the creation of the Reliability and Sensitivity to Line Failures Menu.
     *
     * This function is responsible for handling user input for selecting menus and verifying if the input is valid or not.
     * Once a valid input is received, it calls the respective functions associated with the selected menu.
     */
    void lineFailuresMenu();
    /**
     * @brief Prints the Reliability and Sensitivity to Line Failures Menu options on the terminal.
     *
     * This function prints the Reliability and Sensitivity to Line Failures Menu options on the terminal.
     */
    static void lineFailuresMenuPrinter();
    /**
     * @brief Organizes the display of the Max Number Of Trains In A Segment - Reduced Connectivity Functionality.
     *
     * This function is responsible for handling the displaying of the requested information.
     * Once a valid input is received, it calls the respective functions and displays the information in a user-friendly way.
     */
    void failuresMaxFlow();
    /**
     * @brief Organizes the display of the Top K Stations Most Affected Functionality.
     *
     * This function is responsible for handling the displaying of the requested information.
     * Once a valid input is received, it calls the respective functions and displays the information in a user-friendly way.
     */
    void failuresReport();

    /**
     * @brief Creates the secondary railway removing random connections.
     *
     * Prompts the user to specify the amount of connections to remove.
     * Once a valid input is received, it calls the Networks' <em>randomGenerateRailway</em> function to proceed the operation.
     */
    void randomGenerateRailway();
    /**
     * @brief Creates the secondary railway removing user specified connections.
     *
     * Prompts the user to specify the amount of connections to remove.
     * Once a valid input is received, it prompts the user to specify the name of the connecting stations to remove.
     */
    void removeConnectionsRailway();

    /**
     * @brief Searches the user specified station.
     *
     * Prompts the user to specify the the name of a desired station.
     * Searches the graph for the station and returns the station's adress.
     *
     * @param flag A boolean value that indicates the context in which this function is being called.
     *
     * @return A Station pointer containing the user typed station's memory adress.
     */
    Station* receiveStation(bool type);
    /**
     * @brief A simple function to prompt a confirmation.
     *
     * This function prompts the user to confirm an action, collecting its input and acting accordingly.
     * Once a valid input is received, it returns a flag with the user's choice.
     *
     * @return True if the user confirmed, False otherwise.
     */
    static bool confirmChoice();
    /**
     * @brief A simple function to prompt an action.
     *
     * This function prompts the user to press ENTER to advance the program's execution.
     */
    static void pressEnterToReturn();
    /**
     * @brief A simple function to prompt an action.
     *
     * This function prompts the user to press ENTER to advance the program's execution.
     */
    static void pressEnterToContinue();
    /**
     * @brief A simple function to check a Station's information.
     *
     * This function checks a Station's information and determines the type of displaying to be done when handlying with this Station.
     *
     * @param stationptr A pointer to the Station.
     *
     * @return True if the Station municipality and district aren't empty, False otherwise.
     */
    static bool isStationOutputSafe(Station* stationptr);
    /**
     * @brief Compare two pairs of string and unsigned int by value.
     *
     * This function is used for sorting pairs in descending order by their second value.
     *
     * @param a A reference to the first pair to be compared.
     *
     * @param b A reference to the second pair to be compared.
     *
     * @return True if the second value of pair a is greater than the second value of pair b, False otherwise.
     */
    static bool sortByValue(const std::pair<std::string, unsigned int> &a, const std::pair<std::string ,unsigned int> &b);

private:

    Network railway;
    Network subrailway;
    std::string dataPath;

};

#endif //MENU_H
