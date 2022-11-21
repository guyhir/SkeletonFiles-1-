#include "../include/SelectionPolicy.h"
#include "../include/Party.h"
#include "../include/Graph.h"

 SelectionPolicy:: SelectionPolicy(){}
 //  virtual  Party& SelectionPolicy::  select(vector<Party> partyOptions,Graph mGraph,int PartyId) =0;
MandatesSelectionPolicy::MandatesSelectionPolicy() {}

 
Party *MandatesSelectionPolicy::select(vector<int> partyOptions, Graph mGraph,int PartyId)
{ 
    int max = 0;
    Party *temp = &(mGraph.getParty(partyOptions[0]));
    for (int i: partyOptions) {
        if (mGraph.getParty(i).getMandates()>max) {
            max = mGraph.getParty(i).getMandates();
            temp = &(mGraph.getParty(i));
        //we need to make a equal sign operator constructor to Party class
        }
    }
    return temp;
}
MandatesSelectionPolicy* MandatesSelectionPolicy::clone()
{
    return  new MandatesSelectionPolicy();
}
EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy() {}

Party *EdgeWeightSelectionPolicy::select(vector<int> partyOptions, Graph mGraph,int PartyId)
{       
    int maxWeight = 0;
    Party *temp = &(mGraph.getParty(partyOptions[0]));
    for (int i: partyOptions)
    {             int tempEdgeWight=mGraph.getEdgeWeight(PartyId,i);
        if (tempEdgeWight>maxWeight)
        {
            temp = &(mGraph.getParty(i));                
            maxWeight=tempEdgeWight;
        }
        
    }
    return temp;
}

EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone()
{
    return  new EdgeWeightSelectionPolicy();
}
