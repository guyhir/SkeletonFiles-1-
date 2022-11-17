
#pragma once
#include <vector>

using std::vector;
class Agent;

class JoinPolicy
 {
    public:
            JoinPolicy();
            virtual Agent join(vector<Agent> agentOffers);



 };


class MandatesJoinPolicy : public JoinPolicy 
{
    public:
        Agent join(vector<Agent> agentOffers);
};

class LastOfferJoinPolicy : public JoinPolicy
 { 
     public:
              Agent join(vector<Agent> agentOffers);

 };