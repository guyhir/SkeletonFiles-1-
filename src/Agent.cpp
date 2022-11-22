#include "Agent.h"
#include "../include/Coalition.h"
#include "Simulation.h"
#include "Party.h"
#include "SelectionPolicy.h"
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(agentId), partyOptions{}, isActive(true)
{
    // You can change the implementation of the constructor, but not the signature!

    // daniel- how do we initialize partyOptions (vector <Party>) when its supooesed to be empty in the beginning?
}

// clone agent
Agent::Agent(int agentId, int partyId, Agent &other) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy((other.mSelectionPolicy)->clone()), mCoalitionId(other.mCoalitionId), partyOptions{}, isActive(true)
{
   
}

Agent::~Agent() // maybe we need to add virtual
{
    if (mSelectionPolicy)
        delete mSelectionPolicy;
    mSelectionPolicy = nullptr;
}

// copy constructor
Agent::Agent(const Agent &other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy((other.mSelectionPolicy)->clone()), mCoalitionId(other.mCoalitionId), partyOptions(other.partyOptions), isActive(other.isActive)

{
}

// move constructor
Agent::Agent(Agent &&other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy), mCoalitionId(other.mCoalitionId), partyOptions(other.partyOptions), isActive(other.isActive)
{

    other.mSelectionPolicy = nullptr;
}

// copy assignment operator
Agent &Agent::operator=(const Agent &other)
{
    if (this != &other)
    {
        if (mSelectionPolicy)
            delete mSelectionPolicy;
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        *mSelectionPolicy = (*(other.mSelectionPolicy));
        mCoalitionId = other.mCoalitionId;
        isActive = other.isActive;
        partyOptions = other.partyOptions;
    }
    return *this;
}

// move assignment operator
Agent &Agent::operator=(Agent &&other)
{
    if (mSelectionPolicy)
        delete mSelectionPolicy;
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    mCoalitionId = other.mCoalitionId;
    isActive = other.isActive;
    partyOptions = other.partyOptions;
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
    if (isActive & (partyOptions.size() == 0))
    {
        // const Graph &g =sim.getGraph();
        // d- how can we keep a refrence object in a value object.
        // d-is the getGraph need to return a refrence.
        partyOptions = (sim.getGraph()).getNeighborsOf(mPartyId);
        // D told us to do a vector of pointers
        // d- we dont know how to save the parties in party options and in GetNeigbours()
    }
    if (isActive)
        updateOptions(sim);
    if (isActive)
    {
        int selectedPartyId = mSelectionPolicy->select(partyOptions, sim.getGraph(), mPartyId);
        // d - is it ok that we send a refrence when the function expect a graph value
        // d - does p needs to be a refrence
        Coalition &c = sim.getCoalition(mCoalitionId);
        c.addOfferedParties(selectedPartyId);
        // d- do we need to push pointers to the vector?
        sim.getGraph().getParty(selectedPartyId).setState(CollectingOffers);
        sim.getGraph().getParty(selectedPartyId).AddOffer(mCoalitionId);
    }
}

void Agent::updateOptions(Simulation &sim)
{
    Coalition &currCoalition = sim.getCoalition(mCoalitionId);
    int j = 0;
    // d- do we need to keep it as refrence?
    for (int partyId : partyOptions)
    {
        if (sim.getGraph().getParty(partyId).getState() == Joined)
            partyOptions.erase(partyOptions.begin() + j);
        // d- is the erase function forrect here?
        else if (currCoalition.isOfferedAlready(partyId))
            partyOptions.erase(partyOptions.begin() + j);

        else
            j++;
    }

    if (partyOptions.size() == 0)
        isActive = false;
}
 int Agent::getCoalitionId() const
 {
    return mCoalitionId;
 }