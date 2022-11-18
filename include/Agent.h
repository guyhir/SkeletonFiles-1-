#pragma once

#include <vector>
#include "Graph.h"
#include "Coalition.h"
class SelectionPolicy;
class Simulation;
class Party;
class Agent

{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int myCoalitionId);


    int getPartyId() const;
    int getMandates() const;
    int getId() const;
    void step(Simulation &);
    SelectionPolicy *getSelectionPolicy();


private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int myCoalitionId;
    vector<Party> partyOptions;
    bool isActive;
    void updateOptions(Simulation &sim);
};
