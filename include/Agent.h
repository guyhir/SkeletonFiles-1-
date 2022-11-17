#pragma once

#include <vector>
#include "Graph.h"
#include "Coalition.h"
class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, Coalition myCoalition);


    int getPartyId() const;
     int getMandates() const;
    int getId() const;
    void step(Simulation &);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Coalition myCoalition;
};
