#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;
class JoinPolicy;
class Simulation;
class Agent;
class Coalition;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party();
    Party(int id, string name, int mandates, JoinPolicy *); 
    Party(const Party &aparty);
    Party( Party &&aparty);
    Party & operator=(const Party &aparty);
    Party & operator=( Party &&aparty);
    virtual ~Party();
    State getState() const;
    void setState(State state);
    int getMandates() const;
    int getId() const;
    void step(Simulation &s);
    const string &getName() const;
    void AddOffer(Coalition c);

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int timer;
    vector<Coalition> offers;
};
