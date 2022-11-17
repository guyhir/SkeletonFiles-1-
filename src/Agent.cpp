#include "Agent.h"
#include "../include/Coalition.h"
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
    myCoalition= Coalition( mAgentId,)
}
Agent :: Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, Coalition myCoalition): mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), myCoalition(myCoalition)
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

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
}
