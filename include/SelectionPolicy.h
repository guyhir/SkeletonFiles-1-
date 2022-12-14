#pragma once
#include <vector>
using std::vector;
class Party;
class Graph;
class SelectionPolicy { 

    public:
            SelectionPolicy();
             virtual SelectionPolicy* clone()=0;
            virtual int select(vector<int> partyOptions,Graph mGraph,int PartyId)=0;
            virtual ~SelectionPolicy()=default;
 };

class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
             MandatesSelectionPolicy() ;
               MandatesSelectionPolicy* clone();
             int select(vector<int> partyOptions,Graph mGraph,int PartyId);
              virtual ~MandatesSelectionPolicy()=default;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
     public: 
        EdgeWeightSelectionPolicy ();
          EdgeWeightSelectionPolicy* clone();
            int select(vector<int> partyOptions,Graph mGraph, int PartyId);
              virtual ~EdgeWeightSelectionPolicy()=default;
 };