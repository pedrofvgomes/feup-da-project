#ifndef STATIONCONNECTION_H
#define STATIONCONNECTION_H

#include <string>
#include <vector>

class Connection;

/**
 * @brief Class representing a station in the railway network.
 */
class Station {
public:
    friend class Network;

    /**
     * @brief Constructor for the Station class.
     */
    Station(const std::string &name, const std::string &district, const std::string &municipality, const std::string &township, const std::string &line);

    /**
     * @brief Getter method for the name field.
     *
     * @return The name of the station.
     */
    const std::string &getName() const;
    /**
     *@brief Getter method for the district field.
     *
     *@return The district where the station is located.
     */
    const std::string &getDistrict() const;
    /**
     * @brief Getter method for the municipality field.
     *
     * @return The municipality where the station is located.
     */
    const std::string &getMunicipality() const;
    /**
     * @brief Getter method for the township field.
     *
     * @return The township where the station is located.
     */
    const std::string &getTownship() const;
    /**
     * @brief Getter method for the line field.
     *
     * @return The railway line that the station is part of.
     */
    const std::string &getLine() const;
    /**
     * @brief Getter method for the connections field.
     *
     * @return A vector containing pointers to all connections from the station.
     */
    const std::vector<Connection *> &getConnections() const;
    /**
     * @brief Getter method for the incoming field.
     *
     * @return A vector containing pointers to all connections leading to the station.
     */
    const std::vector<Connection *> &getIncoming() const;
    /**
     * @brief Getter method for the visited field.
     *
     * @return A boolean indicating whether the station has been visited during a search.
     */
    bool isVisited() const;
    /**
     * @brief Getter method for the path field.
     *
     * @return A pointer to the connection that was used to reach the station during a search.
     */
    Connection *getPath() const;

    /**
     * @brief Getter method for the dist field.
     *
     * @return An unsigned integer indicating the distance to the source station.
     */
    unsigned int getDist() const;

    /**
     * @brief Setter method for the name field.
     *
     * @param name The new name of the station.
     */
    void setName(const std::string &name);
    /**
     * @brief Setter method for the district field.
     *
     * @param district The new district where the station is located.
     */
    void setDistrict(const std::string &district);
    /**
     * @brief Setter method for the municipality field.
     *
     * @param municipality The new municipality where the station is located.
     */
    void setMunicipality(const std::string &municipality);
    /**
     * @brief Setter method for the township field.
     *
     * @param township The new township where the station is located.
     */
    void setTownship(const std::string &township);
    /**
     * @brief Setter method for the line field.
     *
     * @param line The new railway line that the station is part of.
     */
    void setLine(const std::string &line);
    /**
     * @brief Setter method for the visited field.
     *
     * @param visited A boolean indicating whether the station has been visited during a search.
     */
    void setVisited(bool visited);
    /**
     * @brief Setter method for the path field.
     *
     * @param path A pointer to the connection that was used to reach the station during a search.
     */
    void setPath(Connection *path);
    /**
     * @brief Setter method for the dist field.
     *
     * @param d An unsigned integer indicating the distance to the source station.
     */
     void setDist(unsigned int d);
    /**
     * @brief Sets the connections of the Station.
     *
     * @param connections The vector of connections to set.
     */
    void setConnections(const std::vector<Connection *> &connections);
    /**
     * @brief Sets the incoming connections of the Station.
     *
     * @param incoming The vector of incoming connections to set.
     */
    void setIncoming(const std::vector<Connection *> &incoming);

    /**
     * @brief Creates a new Connection and adds it to the respective stations.
     *
     * @param destination A pointer to the destination station.
     *
     * @param capacity The capacity of the new connection.
     *
     * @param service The service provided by the new connection.
     *
     * @return A pointer to the newly created Connection object.
     *
     * @note Time Complexity : O(1)
     */
    Connection *addConnection(Station *destination, int capacity, std::string &service);
    /**
     * @brief Adds a bidirectional connection between the current station and the provided destination station.
     *
     * @param destination A pointer to the destination station.
     *
     * @param capacity The capacity of the connection.
     *
     * @param service The type of service provided by the connection.
     *
     * @note Time Complexity : O(1)
    */
    void addBidirectionalConnection(Station *destination, int capacity, std::string& service);
    /**
     * @brief Removes the connection from this station to the given destination station.
     *
     * @param destination The destination station of the connection to remove.
     *
     * @return True if the connection was successfully removed, False otherwise.
     *
     * @note Time Complexity : O(n^2)
     */
    bool removeConnection(Station *destination);

private:

    std::string name;
    std::string district;
    std::string municipality;
    std::string township;
    std::string line;
    std::vector<Connection *> connections;
    std::vector<Connection *> incoming;

    bool visited = false;
    Connection *path = nullptr;
    unsigned int dist;

};

/**
 * @brief Class representing a connection between two stations.
 */
class Connection {
public:
    friend class Network;

    /**
     * @brief Constructor for the Connection class.
     */
    Connection(Station *origin, Station *destination, unsigned int capacity, std::string &service);

    /**
     * @brief Getter method for the origin field.
     *
     * @return Pointer to the origin station.
    */
    Station *getOrigin() const;
    /**
     * @brief Getter method for the destination field.
     *
     * @return Pointer to the destination station.
    */
    Station *getDestination() const;
    /**
     * @brief Getter method for the capacity field.
     *
     * @return The connection's maximum capacity.
    */
    unsigned int getCapacity() const;
    /**
     * @brief Getter method for the service field.
     *
     * @return The connection's service type.
    */
    const std::string &getService() const;
    /**
     * @brief Getter method for the flow field.
     *
     * @return The current connection flow used in our algorithms.
    */
    unsigned int getFlow() const;
    /**
     * @brief Getter method for the selected field.
     *
     * @return True if the connection is selected, False otherwise.
    */
    bool isSelected() const;
    /**
     * @brief Getter method for the reverse field.
     *
     * @return Pointer to the reverse connection.
    */
    Connection *getReverse() const;

    /**
     * @brief Sets the origin station of the connection.
     *
     * @param origin A pointer to the new origin station.
    */
    void setOrigin(Station *origin);
    /**
     * @brief Sets the destination station of the connection.
     *
     * @param destination A pointer to the new destination station.
    */
    void setDestination(Station *destination);
    /**
     * @brief Sets the connection's maximum capacity.
     *
     * @param capacity The new maximum capacity of the connection.
    */
    void setCapacity(unsigned int capacity);
    /**
     * @brief Sets the name of the connection's service.
     *
     * @param service The new connection's service type.
    */
    void setService(const std::string &service);
    /**
     * @brief Sets the current connection flow.
     *
     * @param flow The new flow of the connection.
    */
    void setFlow(unsigned int flow);
    /**
     * @brief Sets the selection status of the connection for a given algorithm
     *
     * @param selected True if the connection should be selected, False otherwise.
    */
    void setSelected(bool selected);
    /**
     * @brief Sets the reverse connection
     *
     * @param reverse A pointer to the reverse connection.
    */
    void setReverse(Connection *reverse);

private:

    Station *origin;
    Station *destination;
    unsigned int capacity;
    std::string service;

    unsigned int flow = 0;
    bool selected = false;
    Connection *reverse = nullptr;

};

#endif //STATIONCONNECTION_H
