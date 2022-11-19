#include "Agent.h"
#include "../include/Coalition.h"
#include "Simulation.h"
#include "Party.h"
#include "SelectionPolicy.h"
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(agentId), isActive(true), partyOptions(0)
{
    // You can change the implementation of the constructor, but not the signature!
    
}
Agent :: Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int mCoalitionId): mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(mCoalitionId), isActive(true)
{ 
}
Agent::~Agent() //maybe we need to add virtual
{
    if (mSelectionPolicy) delete mSelectionPolicy;
}

//copy constructor
Agent::Agent(const Agent &other){
    mAgentId= other.mAgentId; 
    mPartyId= other.mPartyId; 
    mSelectionPolicy= new SelectionPolicy(*(other.mSelectionPolicy));
    mCoalitionId= other.mCoalitionId; 
    isActive= other.isActive;
    partyOptions= other.partyOptions;
}

//move constructor
Agent::Agent(Agent &&other) {
    mAgentId= other.mAgentId; 
    mPartyId= other.mPartyId; 
    mSelectionPolicy= other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    mCoalitionId= other.mCoalitionId; 
    isActive= other.isActive;
    partyOptions= other.partyOptions;
}

//copy assignment operator
 Agent& Agent::operator=(const Agent& other) {
    if (this!=&other) {
        if (mSelectionPolicy)
            delete mSelectionPolicy;
    mAgentId= other.mAgentId; 
    mPartyId= other.mPartyId; 
    *mSelectionPolicy= (*(other.mSelectionPolicy));
    mCoalitionId= other.mCoalitionId; 
    isActive= other.isActive;
    partyOptions= other.partyOptions;
    }
 }


//move assignment operator
Agent& Agent::operator=(Agent &&other){
    if (mSelectionPolicy)
        delete mSelectionPolicy;
    mAgentId= other.mAgentId; 
    mPartyId= other.mPartyId; 
    mSelectionPolicy= other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    mCoalitionId= other.mCoalitionId; 
    isActive= other.isActive;
    partyOptions= other.partyOptions;
    return *this;
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
    if (isActive) {
        Party p = (*mSelectionPolicy).select(partyOptions,sim.getGraph(),mPartyId);
        Coalition c = sim.getCoalition(mCoalitionId);
        c.addOfferedParties(p.getId());
        p.setState(CollectingOffers);
        p.AddOffer(c);
    }



}



void Agent::updateOptions(Simulation &sim)
{    Coalition currCoalition=sim.getCoalition(mCoalitionId);
    for (int i=0;i<partyOptions.size();i++)
    {
        if (partyOptions[i].getState()==Joined)
             partyOptions.erase(partyOptions.begin()+i);
        if(currCoalition.isOfferedAlready(partyOptions[i].getId()))
            partyOptions.erase(partyOptions.begin()+i);
    }
    partyOptions.shrink_to_fit();
    if (partyOptions.size()==0)
        isActive=false;
}