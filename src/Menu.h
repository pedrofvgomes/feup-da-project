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
     *
     * @note a simple test note.
     */
    Menu();

    /**
     * @brief Organizes the creation of the program's data structures.
     *
     * This function asks the user to specify whether the data files are located in the default location or if the user prefers to provide a custom path.
     * Based on the user's input, the program's data structures are set up accordingly.
     */
    void setUpMenu();
    /**
     * @brief Handles user input for the location of the data file.
     *
     * Prompts the user to specify the location of the data and verifies the validity of the path provided.
     *
     * @return The verified path of the data files.
     */
    void setUpCustom();
    void setUpTrainPricesMenu();
    static std::pair<int,int> getUserTrainPrices();
    /**
     * @brief Prints the Set Up Menu options to the terminal.
     *
     * Outputs the Set Up options based on the flag that is passed as a parameter, which can modify the output.
     *
     * @param flag A boolean value that indicates the context in which this function is being called.
     */
    inline static void setUpPrinter(int flag);

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
    inline static void mainMenuOptions(bool isLoading);

    void basicServiceMenu();
    inline static void basicServiceMenuPrinter();
    void basicMaxFlow();
    void basicMostBusy();
    void basicMostImportant();
    void basicMaxFlowIntireGrid();

    void costOptimizationMenu();
    inline static void costOptimizationMenuPrinter();

    void lineFailuresMenu();
    inline static void lineFailuresMenuPrinter();
    void failuresMaxFlow();
    void failuresReport();

    Station* receiveStation(bool type);
    static bool confirmChoice();
    inline static bool isStationOutputSafe(Station* stationptr);

private:

    std::string dataPath;
    Network railway;

};

#endif //MENU_H
