#include "../include/JoinPolicy.h"
#include "../include/Agent.h"
#include "../include/Coalition.h"
#include "../include/Simulation.h"
JoinPolicy::JoinPolicy(){}
MandatesJoinPolicy::MandatesJoinPolicy() {}

int MandatesJoinPolicy::join(vector<int> coalitionOffers,Simulation &sim){ 
    int maxMandates=0;
     int currentBestCoalitionId;
    //Coalition &currentBestCoalition=sim.getCoalition(0);
    for (int coalitionId : coalitionOffers){
        int tempMandates=sim.getCoalition(coalitionId).getMandates();
        if (tempMandates>maxMandates)
        {
            maxMandates=tempMandates;
            currentBestCoalitionId=coalitionId;
            }//we need to make a equal sign operator constructor to Coalition class
    }
    return currentBestCoalitionId;
}

MandatesJoinPolicy* MandatesJoinPolicy::clone()
{
    return  new MandatesJoinPolicy();
}

LastOfferJoinPolicy::LastOfferJoinPolicy() {}

int LastOfferJoinPolicy::join(vector<int> coalitionOffers,Simulation &sim)
{       
    return coalitionOffers.back();
}

LastOfferJoinPolicy* LastOfferJoinPolicy::clone()
{
    return  new LastOfferJoinPolicy();
}

