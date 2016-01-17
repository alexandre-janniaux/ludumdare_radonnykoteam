#pragma once
#include "state.hpp"
//#include "cpp_std_11.hpp"


class StateStack : private sf::NonCopyable
{
    public:
        enum Action
        {
            Push,
            Pop,
            Clear,
        };
    public:
        StateStack(StateContext context);
        template <typename T>
        void registerState(States::ID stateID);
        void update(sf::Time dt);
        void draw();
        void handleEvent(const sf::Event& event);
        void pushState(States::ID stateID);
        void popState();
        void clearStates();
        bool isEmpty() const;
    private:
        State::Ptr createState(States::ID stateID);
        void applyPendingChanges();
    private:
        struct PendingChange
        {

            Action action;
            States::ID stateID;
        };
    private:
        std::vector<State::Ptr> mStack;
        std::vector<PendingChange> mPendingList;
        StateContext mContext;
        std::map<States::ID, std::function<State::Ptr()>> mFactories;
};

template <typename T>
void StateStack::registerState(States::ID stateID)
{
    mFactories[stateID] = [this] ()
    {
        return State::Ptr(new T(*this, mContext));
    };
}

