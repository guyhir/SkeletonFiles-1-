#include "../include/SelectionPolicy.h"
#include "../include/Party.h"
#include "../include/Graph.h"

 SelectionPolicy:: SelectionPolicy(){}
 //  virtual  Party& SelectionPolicy::  select(vector<Party> partyOptions,Graph mGraph,int PartyId) =0;
MandatesSelectionPolicy::MandatesSelectionPolicy() {}

 
int MandatesSelectionPolicy::select(vector<int> partyOptions, Graph mGraph,int PartyId)
{ 
    int max = 0;
   int currentBestpartyId;
    for (int i: partyOptions) {
        if (mGraph.getParty(i).getMandates()>max) {
            max = mGraph.getParty(i).getMandates();
            currentBestpartyId = i;
        //we need to make a equal sign operator constructor to Party class
        }
    }
    return currentBestpartyId;
}
MandatesSelectionPolicy* MandatesSelectionPolicy::clone()
{
    return  new MandatesSelectionPolicy();
}
EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy() {}

int EdgeWeightSelectionPolicy::select(vector<int> partyOptions, Graph mGraph,int PartyId)
{       
    int maxWeight = 0;
    int currentBestpartyId;
    for (int i: partyOptions)
    {             int tempEdgeWight=mGraph.getEdgeWeight(PartyId,i);
        if (tempEdgeWight>maxWeight)
        {
            currentBestpartyId = i;                
            maxWeight=tempEdgeWight;
        }
        
    }
    return currentBestpartyId;
}

EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone()
{
    return  new EdgeWeightSelectionPolicy();
}
