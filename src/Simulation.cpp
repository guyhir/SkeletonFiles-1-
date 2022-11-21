#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), mCoalition(0) 
{
    // You can change the implementation of the constructor, but not the signature!

    for (Agent a : mAgents){
       //d- is the assignent currect or making a copy?
        Coalition currCoalition= Coalition(a.getId(),graph.getMandates(a.getPartyId()));
        mCoalition.push_back(currCoalition);
        //d- do we need to keep it in the stack or on the heap
        //d -if we keep objects in the stack, does it gets deleted whrn the functions ends???
    }
}

void Simulation::step()
{
    for (int i=0; i<mGraph.getNumVertices();i++)
        mGraph.getParty(i).step(*this);
     for (Agent a : mAgents)
       a.step(*this);
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    for(Coalition c : mCoalition)
    {
        if (c.getMandates()>60) return true;
    }
    for (int i=0; i<mGraph.getNumVertices();i++)
    { 
        if(mGraph.getParty(i).getState()!=Joined)
            return false;
    }
    return true;
}

void Simulation::cloneAgent(int partyId,  Agent &a ){
   
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

 Graph &Simulation::getGraph() 
{
    return mGraph;
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return vector<vector<int>>();
}
