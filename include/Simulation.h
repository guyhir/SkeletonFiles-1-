#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"
#include "Party.h"
#include "Coalition.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;
    Coalition &getCoalition(int cId) ;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    const Graph &getGraph() const;
    void cloneAgent(int partyId, Agent &a );

    //daniel- when do we need to return a refrence in a function
    

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> mCoalition;
};
