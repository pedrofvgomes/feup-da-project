#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>

class Connection {
public:
    Connection(std::string &src, std::string &dest, unsigned int cap, std::string &service);
    const std::string &getSource() const;
    const std::string &getDestination() const;
    unsigned int getCapacity() const;
    const std::string &getService() const;
    void setSource(const std::string &src);
    void setDestination(const std::string &dest);
    void setCapacity(unsigned int cap);
    void setService(const std::string &service);
private:
    std::string source;
    std::string destination;
    unsigned int capacity;
    std::string service;
};

#endif //CONNECTION_H
