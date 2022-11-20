#pragma once
#include <vector>
#include "../include/Agent.h"
class SelectionPolicy;


using std::vector;

class Coalition
{
public:
    Coalition(int id, int mandates);
    Coalition ();
    int getMandates() const;
    int getId() const;
    void addMandates(int toAdd) ;
    void addOfferedParties(int partyId);
  
    bool isOfferedAlready(int partyId);
    

private:
    int cId;
    int cMandates;
   
    vector<int> alreadyOffered;
};