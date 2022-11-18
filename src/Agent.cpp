#include "Agent.h"
#include "../include/Coalition.h"
#include "Simulation.h"
#include "Party.h"
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), myCoalitionId(agentId), isActive(true)
{
    // You can change the implementation of the constructor, but not the signature!
}
Agent :: Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int myCoalitionId): mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), myCoalitionId(myCoalitionId), isActive(true)
{ 
}


int Agent::getId() const
{
    return mAgentId;
}
int Agent::getMandates() const
{

}
int Agent::getPartyId() const
{
    return mPartyId;
}

SelectionPolicy *Agent::getSelectionPolicy() 
{
    return mSelectionPolicy;
}

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
    if (isActive&partyOptions.size()==0) {
        Graph g = sim.getGraph();
        partyOptions = g.getNeighborsOf(mPartyId);
    }
    if (isActive)
        updateOptions(sim);
    

}



void Agent::updateOptions(Simulation &sim)
{    Coalition currCoalition=sim.getCoalition(myCoalitionId);
    for (int i=0;i<partyOptions.size();i++)
    {
        if (partyOptions[i].getState()==Joined)
            partyOptions.erase(i);
    
   
        if(currCoalition.isOfferedAlready(partyOptions[i].getId()))
        partyOptions.erase(i);
    }

}