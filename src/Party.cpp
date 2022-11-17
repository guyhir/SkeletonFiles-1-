#include "Party.h"
#include "Agent.h"
#include "../include/JoinPolicy.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
    timer=0;
     
}

//  Party::Party( Party &aparty) : mId(aparty.mId), mName(aparty.mName), mMandates(), mJoinPolicy(jp), mState(Waiting) 
// {
    

// } 
  Party::~Party() //maybe we need to add virtual
{
    if (mJoinPolicy) delete mJoinPolicy;
}

// Party & operator=(const Party &aparty)
// {
//     mId= aparty.get
// }
State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{   
    if (getState()==CollectingOffers)
    {
        timer++;
        if(timer==3)
        {
        Agent a= (*mJoinPolicy).join(offers);
        a.cloneAgent(mId,s.getAgents(),mMandates);
        }
    }
    

    
    // TODO: implement this method
}

