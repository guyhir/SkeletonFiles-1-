#pragma once
#include <vector>


using std::vector;

class Coalition
{
public:
    Coalition(int id, int mandates, vector<int>alreadyOffered);
    int getMandates() const;
     void addMandates(int toAdd) ;
     void addOfferedParties(int partyId);
    

private:
    int cId;
    int cMandates;
    vector<int> alreadyOffered;
};