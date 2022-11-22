#include "Party.h"
#include "Agent.h"
#include "../include/JoinPolicy.h"
#include "Simulation.h"
#include "Coalition.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), timer{}, offers{}
{
    // You can change the implementation of the constructor, but not the signature!
    //maybe we need to initate offers
}    

 Party::Party()  : mId{}, mName{}, mMandates{}, mJoinPolicy{}, mState(Waiting), timer{}, offers{}
{

 }

//copy constructor
 Party:: Party(const Party &other) : mId(other.mId),mName(other.mName),mMandates(other.mMandates),mJoinPolicy((other.mJoinPolicy)->clone()),mState(other.mState),
timer(other.timer),offers(other.offers)
 { 
    
//mJoinPolicy=(other.mJoinPolicy)->clone();
 }

//destructor
Party::~Party() //maybe we need to add virtual
{
    if (mJoinPolicy) delete mJoinPolicy;
    mJoinPolicy = nullptr;
}

//assignment operator
 Party& Party:: operator=(const Party &other)
{
     mId= other.mId;
     mName=other.mName;
     mMandates=other.mMandates;
     *mJoinPolicy=(*(other.mJoinPolicy));
     mState=other.mState;
     timer=other.timer;
     offers=other.offers;
return *this;
}

//move constructor
Party::Party(Party &&other) : mId(other.mId), mName(other.mName),
mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy),mState(other.mState),
timer(other.timer),offers(other.offers)
{
    other.mJoinPolicy=nullptr;
     
}


//move assignment operator
Party& Party::operator=( Party &&other){
    if (mJoinPolicy)
        delete mJoinPolicy;
     mId= other.mId;
     mName=other.mName;
     mMandates=other.mMandates;
     mJoinPolicy=other.mJoinPolicy;
     other.mJoinPolicy=nullptr;
     mState=other.mState;
     timer=other.timer;
     offers=other.offers;
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
    if (getState()==CollectingOffers) {
        timer++;
        if(timer==3){ //join some coalition
          int coalitionId =(*mJoinPolicy).join(offers,s);
            s.getCoalition(coalitionId).addMandates(mMandates);
            Agent a = s.getAgents()[coalitionId]; //we only need information from this agent, we dont use it or change it otherwise
           //d- is it ok to only take a copy of agent a? beacue getAgents() is Const
            s.cloneAgent(mId,a);
            setState(Joined);
        }
    }

}

void Party:: AddOffer(int coalitionId)
{
offers.push_back(coalitionId);

}

