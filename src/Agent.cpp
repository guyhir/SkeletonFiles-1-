#include "Agent.h"
#include "../include/Coalition.h"
#include "Simulation.h"
#include "Party.h"
#include "SelectionPolicy.h"
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(agentId),  partyOptions{},isActive(true)
{
    // You can change the implementation of the constructor, but not the signature!
    
    //daniel- how do we initialize partyOptions (vector <Party>) when its supooesed to be empty in the beginning?
}

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int mCoalitionId): mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(mCoalitionId),  partyOptions{},isActive(true)
{ 
}

Agent::~Agent() //maybe we need to add virtual
{
    if (mSelectionPolicy) delete mSelectionPolicy;
    mSelectionPolicy = nullptr;

}

//copy constructor
Agent::Agent(const Agent &other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy ((other.mSelectionPolicy)->clone()) ,mCoalitionId( other.mCoalitionId),partyOptions(other.partyOptions), isActive(other.isActive)

{

    
  
}

//move constructor
Agent::Agent(Agent &&other) : mAgentId( other.mAgentId), mPartyId(other.mPartyId),mSelectionPolicy(other.mSelectionPolicy) ,mCoalitionId( other.mCoalitionId),partyOptions(other.partyOptions), isActive(other.isActive) 
{
   
    other.mSelectionPolicy = nullptr;
   
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
    return *this;
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
    if (isActive&(partyOptions.size()==0)) { 
       // const Graph &g =sim.getGraph();
        //d- how can we keep a refrence object in a value object. 
        // d-is the getGraph need to return a refrence.
        partyOptions = (sim.getGraph()).getNeighborsOf(mPartyId);
        //D told us to do a vector of pointers
        //d- we dont know how to save the parties in party options and in GetNeigbours()
    }
    if (isActive)
        updateOptions(sim);
    if (isActive) {
        Party *p = mSelectionPolicy->select(partyOptions,sim.getGraph(),mPartyId);
        //d - is it ok that we send a refrence when the function expect a graph value
        //d - does p needs to be a refrence
        Coalition &c = sim.getCoalition(mCoalitionId);
        c.addOfferedParties(p->getId());
        //d- do we need to push pointers to the vector?
        p->setState(CollectingOffers);
        p->AddOffer(c);
    }
}



void Agent::updateOptions(Simulation &sim)
{    Coalition &currCoalition=sim.getCoalition(mCoalitionId);
    //d- do we need to keep it as refrence?
    int i=0;
    for(Party* p : partyOptions)
    {
        if (p->getState()==Joined)
             partyOptions.erase(partyOptions.begin()+i);
             //d- is the erase function forrect here?
        if(currCoalition.isOfferedAlready(partyOptions[i]->getId()))
            partyOptions.erase(partyOptions.begin()+i);
    
    i++;
    }
    partyOptions.shrink_to_fit();
    if (partyOptions.size()==0)
        isActive=false;
}