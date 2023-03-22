#ifndef MENU_H
#define MENU_H

#include "Network.h"

/**
 * \brief Manages the application's interface.
 *
 * This class manages the application's interface by receiving user inputs and sending commands to the <b>Network</b> class to perform the requested tasks.
 */
class Menu {
public:
    /**
     * \brief Constructor for the Menu class.
     *
     * This constructor initializes the program by calling the <em>setUpMenu()</em> function.
     */
    Menu();

    /**
     * \brief Organizes the creation of the program's data structures.
     *
     * This function asks the user to specify whether the data files are located in the default location or if the user prefers to provide a custom path.
     * Based on the user's input, the program's data structures are set up accordingly.
     */
    void setUpMenu();
    /**
     * \brief Handles user input for the location of the data file.
     *
     * Prompts the user to specify the location of the data and verifies the validity of the path provided.
     *
     * \return The verified path of the data files.
     */
    std::string setUpCustom();
    /**
     * \brief Prints the Set Up Menu options to the terminal.
     *
     * Outputs the Set Up options based on the flag that is passed as a parameter, which can modify the output.
     *
     * \param flag A boolean value that indicates the context in which this function is being called.
     */
    inline static void setUpPrinter(bool flag);

    /**
     * \brief Organizes the creation of the Main Menu.
     *
     * This function is responsible for handling user input for selecting menus and verifying if the input is valid or not.
     * Once a valid input is received, it calls the respective functions associated with the selected menu.
     *
     * \param isLoading A boolean flag indicating if the program is starting or already running.
     */
    void mainMenu(bool isLoading);
    /**
     * \brief Prints the Main Menu options on the terminal.
     *
     * This function prints the Main Menu options on the terminal based on the value of the <em>isLoading</em> flag.
     *
     * \param isLoading A boolean flag indicating if the program is starting or already running.
     */
    inline static void mainMenuOptions(bool isLoading);

    /*

    ///Organizes the creation of the "Find a Flight" first menu.
    void findFlightFirstMenu();
    ///Prints the options of the "Find a Flight" first menu on the terminal.
    static void findFlightFirstMenuOptions();
    ///Organizes the creation of the "Find a Flight" second menu.
    ///@param code Code of the first airport.
    void findFlightSecondMenu(std::string code);
    ///Prints the options of the "Find a Flight" second menu on the terminal.
    static void findFlightSecondMenuOptions();
    ///Organizes the creation of the "Find a Flight" third menu.
    ///@param code1 Code of the first airport.
    ///@param code2 Code of the second airport.
    void findFlightThirdMenu(std::string code1, std::string code2);
    ///Prints the options of the "Find a Flight" third menu on the terminal.
    static void findFlightThirdMenuOptions();
    ///Organizes the creation of the "Find a Flight" final menu.
    ///@param code1 Code of the first airport.
    ///@param code2 Code of the second airport.
    ///@param airlines A vector with the codes of selected Airlines.
    ///@param avoid A flag to signal if the airlines are to be specified of avoided.
    void findFlightFinalMenu(std::string code1, std::string code2, std::vector<std::string> airlines, bool avoid);
    ///Prints the options of the "Find a Flight" final menu on the terminal.
    ///@param option Code used in the function to select which part to display.
    static void findFlightFinalMenuOptions(int option);

    ///Helper method to take and validate a string input.
    ///@return Returns the Airport code once it is provided with a valid input.
    std::string findFlightEnterString();
    ///Helper method to print the instructions of the "findFlightEnterString" function on the terminal.
    static void findFlightEnterStringPrinter();
    ///Helper method to take and validate a pair of coordinates.
    ///@return Returns the Airport code once it is provided with a valid input.
    std::string findFlightEnterCoordinates();
    ///Helper method to print the instructions of the "findFlightEnterCoordinates" function on the terminal.
    ///@param first A flag to indicate if it is the first time running the function.
    static void findFlightEnterCoordinatesPrinter(bool first);
    ///Helper method to take and validate a string input.
    ///@param empty A flag to indicate if the output will be empty.
    ///@return Returns a vector of Airline codes to be processed in another function.
    std::vector<std::string> findFlightPickAirlines(bool empty);
    ///Helper method to print the instructions of the "findFlightPickAirlinesPrinter" function on the terminal.
    ///@param first A flag to indicate if it is the first time running the function.
    static void findFlightPickAirlinesPrinter(bool first);

    ///Organizes the creation of the "Airport Information" menu.
    void airportInfoMenu();

    ///Organizes the creation of the "Help" menu.
    void helpMenu();
    ///Prints the options of the "Help" menu on the terminal.
    static void helpMenuOptions();

    */

private:

    Network railway;

};

#endif //MENU_H