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
    Agent(int agentId, int partyId, Agent& other);
    Agent(const Agent &other);
    Agent(Agent &&other);
    Agent& operator= (const Agent& other);
    virtual ~Agent();
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    SelectionPolicy *getSelectionPolicy();
    Agent& operator=(Agent &&other);
    int getCoalitionId() const;


private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalitionId;
    vector<int> partyOptions;
    bool isActive;
    void updateOptions(Simulation &sim);
};
