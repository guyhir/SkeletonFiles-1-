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
    const Coalition &getCoalition(int cId) const;
    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    const Graph &getGraph() const;
    void cloneAgent(int partyId, int coalitionID,  SelectionPolicy *selectionPolicy );
    

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> mCoalition;
};
