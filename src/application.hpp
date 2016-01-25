#pragma once
#include "state/statestack.hpp"

class Application
{
    public:
        Application(StateContext context);
        void registerStates();
        void processInput();
        void update(sf::Time dt);
        void render();
        int run();
    private:
        StateStack mStateStack;
        sf::RenderWindow* mWindow;
};
