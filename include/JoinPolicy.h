
#pragma once
#include <vector>

using std::vector;
class Agent;
class Coalition;

class JoinPolicy
 {
    public:
            JoinPolicy();
            virtual JoinPolicy* clone()=0;
            virtual Coalition &join(vector<Coalition*> &CoalitionOffers)=0;
            virtual ~JoinPolicy()=default;
 };


class MandatesJoinPolicy : public JoinPolicy 
{
    public:
    MandatesJoinPolicy();
         MandatesJoinPolicy* clone() override;
        Coalition &join(vector<Coalition*> &coalitionOffers);
          virtual ~MandatesJoinPolicy()=default;
};

class LastOfferJoinPolicy : public JoinPolicy
 { 
     public:
     LastOfferJoinPolicy();
      LastOfferJoinPolicy* clone() override;
             Coalition &join(vector<Coalition*> &coalitionOffers);
               virtual ~LastOfferJoinPolicy()=default;

 };