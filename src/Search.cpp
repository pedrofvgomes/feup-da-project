#include "Network.h"
#include <stack>
#include <queue>
using namespace std;

void Network::dfs(string& s){
    stack<string> stack;
    string current;

    for(auto station : this->stations)
        station.second.setVisited(false);

    stack.push(s);

    while(!stack.empty()){
        current = stack.top();
        stack.pop();

        this->stations[current].setVisited(true);

        for(auto connection : this->stations[current].getConnections()){
            if(!this->stations[connection.getDestination()].isVisited())
                stack.push(connection.getDestination());
        }
    }
}

void Network::bfs(std::string &s) {
    queue<string> q;
    string current;
    for(auto station: this->stations)
        station.second.setVisited(false);

    this->stations[s].setVisited(true);
    q.push(s);

    while(!q.empty()){
        current = q.front();
        q.pop();

        for(auto station: this->stations[current].getConnections()){
            if(!this->stations[station.getDestination()].isVisited()){
                this->stations[station.getDestination()].setVisited(true);
                q.push(station.getDestination());
            }
        }
    }
}