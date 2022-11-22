
#pragma once
#include <vector>

using std::vector;
class Agent;
class Coalition;
class Simulation;

class JoinPolicy
 {
    public:
            JoinPolicy();
            virtual JoinPolicy* clone()=0;
            virtual int join(vector<int> CoalitionOffers,Simulation &sim)=0;
            virtual ~JoinPolicy()=default;
 };


class MandatesJoinPolicy : public JoinPolicy 
{
    public:
    MandatesJoinPolicy();
         MandatesJoinPolicy* clone() override;
        int join(vector<int> coalitionOffers,Simulation &sim);
          virtual ~MandatesJoinPolicy()=default;
};

class LastOfferJoinPolicy : public JoinPolicy
 { 
     public:
     LastOfferJoinPolicy();
      LastOfferJoinPolicy* clone() override;
             int join(vector<int> coalitionOffers,Simulation &sim);
               virtual ~LastOfferJoinPolicy()=default;

 };