#include "../include/Coalition.h"
#include "../include/Agent.h"
#include "../include/SelectionPolicy.h"

 Coalition:: Coalition(int id, int mandates, SelectionPolicy *selectionPolicy): cId(id), cMandates(mandates), sp(selectionPolicy)
 {
   //add null vector to alreadyOffered 
 }
    int Coalition::getMandates() const
    {
        return cMandates;
    }
     int Coalition::getId() const
    {
        return cId;
    }
     void Coalition:: addMandates(int toAdd) 
     {
     cMandates=cMandates+toAdd;
     }
     void Coalition::addOfferedParties(int partyId)
     {
        alreadyOffered.push_back(partyId);
     }
     SelectionPolicy *Coalition::getSelectionPolicy() 
     {
        return sp;
     }
         bool Coalition:: isOfferedAlready(int partyId)
         { 
            for (int i=0; i<alreadyOffered.size();i++)
                 {
                      if (partyId == alreadyOffered[i]) return true;
        
                 }
        return false;    
         }

    