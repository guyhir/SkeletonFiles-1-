#pragma once
#include <vector>
using std::vector;
class Party;
class Graph;
class SelectionPolicy { 

    public:
            SelectionPolicy();
            virtual Party& select(vector<Party> partyOptions,Graph mGraph,int PartyId);



 };


class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
             Party &select(vector<Party> partyOptions,Graph mGraph,int PartyId);
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
     public:
             Party &select(vector<Party> partyOptions,Graph mGraph, int PartyId);
 };