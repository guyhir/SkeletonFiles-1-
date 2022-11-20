#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
    for (int i=0; i<mAgents.size();i++){
        Agent &aCurrent= mAgents[i];
        Coalition currCoalition= Coalition(i,graph.getMandates(aCurrent.getPartyId()));
        mCoalition.push_back(currCoalition);
    }
}

void Simulation::step()
{
    for (int i=0; i<mGraph.getNumVertices();i++)
        mGraph.getParty(i).step(*this);
    for (int i=0; i<mAgents.size();i++) 
        mAgents[i].step(*this);
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    return true;
}

void Simulation::cloneAgent(int partyId,  Agent &a ){
    int agentId = mAgents.size();
    Agent cAgent = Agent(mAgents.size(),partyId,a.getSelectionPolicy(),a.getId());
    mAgents.push_back(cAgent);
}
 Coalition &Simulation::getCoalition(int cId) 
{
    
    return mCoalition[cId];
}
const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return vector<vector<int>>();
}
