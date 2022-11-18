#pragma once
#include <vector>
#include "../include/Agent.h"
class SelectionPolicy;


using std::vector;

class Coalition
{
public:
    Coalition(int id, int mandates, SelectionPolicy *selectionPolicy);
    int getMandates() const;
    int getId() const;
    void addMandates(int toAdd) ;
    void addOfferedParties(int partyId);
    SelectionPolicy *getSelectionPolicy();
    bool isOfferedAlready(int partyId);
    

private:
    int cId;
    int cMandates;
    SelectionPolicy *sp;
    vector<int> alreadyOffered;
};