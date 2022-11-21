#include "../include/JoinPolicy.h"
#include "../include/Agent.h"
#include "../include/Coalition.h"
JoinPolicy::JoinPolicy(){}
MandatesJoinPolicy::MandatesJoinPolicy() {}

Coalition &MandatesJoinPolicy::join(vector<Coalition*> &coalitionOffers){ 
    int maxMandates=0;
    Coalition *currentBestCoalition=coalitionOffers[0];
    for (Coalition *c : coalitionOffers){
        if (c->getMandates()>maxMandates){
            maxMandates=c->getMandates();
            currentBestCoalition=c;
            }//we need to make a equal sign operator constructor to Coalition class
    }
    return *currentBestCoalition;
}

MandatesJoinPolicy* MandatesJoinPolicy::clone()
{
    return  new MandatesJoinPolicy();
}

LastOfferJoinPolicy::LastOfferJoinPolicy() {}

Coalition &LastOfferJoinPolicy::join(vector<Coalition*> &coalitionOffers)
{       
    return *(coalitionOffers.back());
}

LastOfferJoinPolicy* LastOfferJoinPolicy::clone()
{
    return  new LastOfferJoinPolicy();
}

