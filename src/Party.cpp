#include "Party.h"
#include "Agent.h"
#include "../include/JoinPolicy.h"
#include "Simulation.h"
#include "Coalition.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), timer(0)
{
    // You can change the implementation of the constructor, but not the signature!
    //maybe we need to initate offers
}

//  Party::Party( Party &aparty) : mId(aparty.mId), mName(aparty.mName), mMandates(), mJoinPolicy(jp), mState(Waiting) 
// {
    

// } 
 Party:: Party(const Party &aparty)
 { 
    mId= aparty.mId;
     mName=aparty.mName;
     mMandates=aparty.mMandates;
     mJoinPolicy=new JoinPolicy (*(aparty.mJoinPolicy));
     mState=aparty.mState;
     timer=aparty.timer;
     offers=aparty.offers;
 }
  Party::~Party() //maybe we need to add virtual
{
    if (mJoinPolicy) delete mJoinPolicy;
}

 Party& Party:: operator=(const Party &aparty)
{
     mId= aparty.mId;
     mName=aparty.mName;
     mMandates=aparty.mMandates;
     *mJoinPolicy=(*(aparty.mJoinPolicy));
     mState=aparty.mState;
     timer=aparty.timer;
     offers=aparty.offers;
return *this;
}

//move constructor
Party::Party(Party &&aparty) {
  mId= aparty.mId;
     mName=aparty.mName;
     mMandates=aparty.mMandates;
     mJoinPolicy=aparty.mJoinPolicy;
     aparty.mJoinPolicy=nullptr;
     mState=aparty.mState;
     timer=aparty.timer;
     offers=aparty.offers;
}


//move assignment operator
Party& Party::operator=( Party &&aparty){
    if (mJoinPolicy)
        delete mJoinPolicy;

     mId= aparty.mId;
     mName=aparty.mName;
     mMandates=aparty.mMandates;
     mJoinPolicy=aparty.mJoinPolicy;
     aparty.mJoinPolicy=nullptr;
     mState=aparty.mState;
     timer=aparty.timer;
     offers=aparty.offers;
    return *this;
}
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

int Party::getId() const
{
    return mId;
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
        Coalition c= (*mJoinPolicy).join(offers);
        c.addMandates(mMandates);
        s.cloneAgent(mId,c.getId(),c.getSelectionPolicy());
        setState(Joined);
        }
    }

}

void Party:: AddOffer(Coalition c)
{
offers.push_back(c);

}

