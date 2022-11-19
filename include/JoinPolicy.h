
#pragma once
#include <vector>

using std::vector;
class Agent;
class Coalition;

class JoinPolicy
 {
    public:
            JoinPolicy();
            virtual Coalition join(vector<Coalition> CoalitionOffers);
 };


class MandatesJoinPolicy : public JoinPolicy 
{
    public:
        Coalition join(vector<Coalition> coalitionOffers);
};

class LastOfferJoinPolicy : public JoinPolicy
 { 
     public:
             Coalition join(vector<Coalition> coalitionOffers);

 };