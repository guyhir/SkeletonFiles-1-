#include "../include/SelectionPolicy.h"
#include "../include/Party.h"
#include "../include/Graph.h"

 SelectionPolicy:: SelectionPolicy(){}
 //  virtual  Party& SelectionPolicy::  select(vector<Party> partyOptions,Graph mGraph,int PartyId) =0;
MandatesSelectionPolicy::MandatesSelectionPolicy() {}

 
Party *MandatesSelectionPolicy::select(vector<Party*> partyOptions, Graph mGraph,int PartyId)
{ 
    int max = 0;
    Party *temp = partyOptions[0];
    for (Party *p: partyOptions) {
        if (p->getMandates()>max) {
            max = p->getMandates();
            temp = p;
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

Party *EdgeWeightSelectionPolicy::select(vector<Party*> partyOptions, Graph mGraph,int PartyId)
{       int maxWeight = 0;
      Party *temp = partyOptions[0];
    for (Party *p: partyOptions)
    { int tempEdgeWight=mGraph.getEdgeWeight(PartyId,p->getId());
        if (tempEdgeWight>maxWeight)
        {
            temp = p;
            maxWeight=tempEdgeWight;
        }
        
    }
    return temp;
}

EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone()
{
    return  new EdgeWeightSelectionPolicy();
}
