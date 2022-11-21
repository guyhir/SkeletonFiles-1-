#include "../include/Coalition.h"
#include "../include/Agent.h"
#include "../include/SelectionPolicy.h"

 Coalition:: Coalition(int id, int mandates): cId(id), cMandates(mandates), alreadyOffered{}
 {
   //add null vector to alreadyOffered 
 }
   Coalition:: Coalition() : cId{}, cMandates{}, alreadyOffered{}
   {
    
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
     
         bool Coalition:: isOfferedAlready(int partyId)
         { 
            for(int pId : alreadyOffered)
                 {
                      if (partyId == pId) return true;
        
                 }
        return false;    
         }

    