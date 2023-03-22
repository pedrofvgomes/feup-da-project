#include "Network.h"
#include <stack>
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