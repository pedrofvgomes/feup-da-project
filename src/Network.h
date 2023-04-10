#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

#include "StationConnection.h"

/**
 * @brief Represents a network of train stations and their connections.
 */
class Network {
public:
    /**
     * @brief Constructs an empty Network object.
     */
    Network();

    /**
     * @brief Returns the prices of the train tickets.
     *
     * @return A pair of integers representing the prices of the STANDARD and ALFA tickets, respectively.
     *
     * @note Time Complexity : O(1)
     */
    const std::pair<int, int> &getTrainPrices() const;

    /**
     * @brief Returns the list of stations in the network.
     *
     * @return A vector of pointers to Station objects.
     *
     * @note Time Complexity : O(1)
     */

    const std::vector<Station *> &getStations() const;

    /**
     * @brief Sets the prices of the train tickets.
     *
     * @param trainPrices A pair of integers representing the prices of the STANDARD and ALFA tickets, respectively.
     *
     * @note Time Complexity : O(1)
     */
    void setTrainPrices(const std::pair<int, int> &trainPrices);

    /**
     * @brief Sets the list of stations in the network.
     *
     * @param stations A vector of pointers to Station objects.
     *
     * @note Time Complexity : O(1)
     */
    void setStations(const std::vector<Station *> &stations);

    /**
     * @brief Finds a station by name.
     *
     * @param name The name of the station to find.
     *
     * @return A pointer to the Station object with the given name, or nullptr if not found.
     *
     * @note Time Complexity : O(n)
     */
    Station * findStation(const std::string &name) const;

    /**
     * @brief Adds a new station to the network.
     *
     * @param name The name of the station.
     *
     * @param district The name of the district where the station is located.
     *
     * @param municipality The name of the municipality where the station is located.
     *
     * @param township The name of the township where the station is located.
     *
     * @param line The name of the train line that serves the station.
     *
     * @note Time Complexity : O(1)
     */
    void addStation(const std::string &name, const std::string &district, const std::string &municipality, const std::string &township, const std::string &line);

    /**
     * @brief Adds a bidirectional connection between two stations.
     *
     * @param source The name of the source station.
     *
     * @param destination The name of the destination station.
     *
     * @param capacity The capacity of the connection.
     *
     * @param service The name of the train service that uses the connection.
     *
     * @note Time Complexity : O(n)
     */
    void addBidirectionalConnection(const std::string &source, const std::string &destination, unsigned int capacity, std::string service);

    /**
     * @brief Creates the network from a file.
     *
     * @param path The path to the file containing the stations and connections.
     */
    void createNetwork(const std::string &path);

    /**
     * @brief Reads the list of stations from a file.
     *
     * @param fileLocation The path to the file containing the stations.
     *
     * @return The number of stations read from the file.
     */
    unsigned int readStations(const std::string &fileLocation);

    /**
     * @brief Reads the list of connections from a file.
     *
     * @param fileLocation The path to the file containing the connections.
     *
     * @return The number of connections read from the file.
     */
    unsigned int readConnections(const std::string &fileLocation);

    Station * findStation(std::string name);

    /**
     * @brief Check if a station exists in the network given its name.
     *
     * @param input The name of the station to search for.
     *
     * @param stationPtr A pointer to a Station pointer that will be set to point to the
     * found station if it exists, or remain unchanged if it doesn't
     *
     * @return true if a station with the given name exists, false otherwise.
     *
     * @note Time Complexity : O(n)
     */
    bool doesStationExist(const std::string& input, Station*& stationPtr);

    /**
     * @brief Test if a connection can be used and visit the station on the other side.
     *
     * @param q A reference to the queue of stations to be processed.
     *
     * @param e A pointer to the connection being tested.
     *
     * @param w A pointer to the station on the other side of the connection.
     *
     * @param residual The amount of flow that can still be sent through the connection.
     *
     * @note Time Complexity : O(1)
     */
    void testAndVisit(std::queue< Station*> &q, Connection *e, Station *w, unsigned int residual);

    /**
     * @brief Find an augmenting path from the source to the target station.
     *
     * @param s A pointer to the source station.
     *
     * @param t A pointer to the target station.
     *
     * @return true if an augmenting path is found, false otherwise.
     *
     * @note Time Complexity : O(n + m) (n - number of stations, m - number of connections)
     */
    bool findAugmentingPath(Station* s, Station* t);

    /**
     * @brief Find the minimum residual capacity along an augmenting path.
     *
     * @param s A pointer to the source station.
     *
     * @param t A pointer to the target station.
     *
     * @return The minimum residual capacity along the augmenting path.
     *
     * @note Time Complexity : O(n)
     */
    unsigned int findMinResidualAlongPath(Station* s, Station* t);

    /**
     * @brief Augment the flow along a certain path.
     *
     * @param s A pointer to the source station.
     *
     * @param t A pointer to the target station.
     *
     * @param f The amount to increment the flow by.
     *
     * @note Time Complexity : O(n)
     */
    void augmentFlowAlongPath(Station *s, Station *t, unsigned int f);

    /**
     * @brief Implementation of the Edmonds-Karp algorithm to find the max flow in the graph, which in
     * this context corresponds to the maximum amount of trains that can simultaneously travel between
     * two specific stations.
     *
     * @param source A pointer to the source station.
     *
     * @param target A pointer to the target station.
     *
     * @return The maximum amount of trains that can travel between stations "source" and "target".
     *
     * @note Time Complexity : O(n * m^2) (n - number of stations, m - number of connections)
     */
    unsigned int edmondsKarp(Station *source, Station *target);

    /**
     * @brief Returns the top K municipalities with the most flow in the network.
     *
     * @param k The number of municipalities to return.
     *
     * @return A vector of pairs, where each pair consists of the name of a municipality and
     * its total flow.
     *
     * @note Time Complexity : O(n^3 * log(n))
     */
    std::vector<std::pair<std::string, unsigned int>> topKMunicipalities(unsigned int k);

    /**
     * @brief Returns the top K districts with the most flow in the network.
     *
     * @param k The number of districts to return.
     *
     * @return A vector of pairs, where each pair consists of the name of a district and
     * its total flow.
     *
     * @note Time Complexity : O(n^3 * log(n))
     */
    std::vector<std::pair<std::string, unsigned int>> topKDistricts(unsigned int k);
    std::vector<std::pair<std::string,std::string>> mostTrains();

    /**
     * @brief Performs a breadth-first search starting at the specified station and returns
     * the stations visited.
     *
     * @param source A pointer to the source station.
     *
     * @return A vector of pointers to Station objects representing the stations visited in
     * the order they were visited.
     *
     * @note Time Complexity : O(n + m) (n - number of stations, m - number of connections)
     */
    std::vector<Station *> BFS(Station *source);

    /**
     * @brief Returns the maximum number of trains that can arrive at the specified station
     * at the same time.
     *
     * @param station Pointer to a station.
     *
     * @return The maximum amount of trains.
     *
     * @note Time Complexity : O(n^3)
     */
    unsigned int maxTrainsToStation(Station* station);

    /**
     * @brief Removes a bidirectional connection between two stations.
     *
     * @param source The name of the source station.
     *
     * @param destination The name of the destination station.
     */
    bool removeBidirectionalConnection(Station *source, Station *destination);

    /**
     * @brief Creates the secondary railway removing random connections.
     *
     * Generates a random pair of directly linked stations and removes the connection between them.
     * Repeats the algorithm for <b>n</b> times.
     *
     * @param n The number of connections to be removed.
     *
     * @return A boolean value informing of the operation success.
     */
    bool randomGenerateRailway(int n);

    /**
     * @brief Returns the max flow of each station in the current network.
     *
     * @return An unordered map that associates stations to their corresponding max flow value.
     */
    std::unordered_map<Station *, unsigned int> maxFlowPerStation();

    /**
     * @brief Implementation of the Dijkstra algorithm.
     * @param source A pointer to the source station.
     */
    void dijkstra(Station* source);

    /**
     * @brief Calculates the maximum amount of trains that can simultaneously travel
     * between two specific stations with minimum cost for the company.
     *
     * @param source A pointer to the source station.
     *
     * @param target A pointer to the target station
     *
     * @return A pair with the maximum amount of trains and the respective cost for the company.
     */
    std::pair<unsigned int, unsigned int> maxFlowMinCost(Station* source, Station* target);

private:

    std::pair<int,int> trainPrices;
    std::vector<Station *> stations;

};

#endif //NETWORK_H
