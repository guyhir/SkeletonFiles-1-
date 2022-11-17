#include "../include/Coalition.h"
 Coalition:: Coalition(int id, int mandates, vector<int>alreadyOffered) : cId(id), cMandates(mandates),alreadyOffered(alreadyOffered)
 {

 }
    int Coalition::getMandates() const
    {
        return cMandates;
    }
     void Coalition:: addMandates(int toAdd) 
     {
     cMandates=cMandates+toAdd;
     }
     void Coalition :: addOfferedParties(int partyId)
     {
        alreadyOffered.push_back(partyId);
     }
    