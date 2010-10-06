#ifndef GAMESTATE_HPP_INCLUDED
#define GAMESTATE_HPP_INCLUDED

#include "state.hpp"

///class for the game
class GameState : public State
{
    public:
        GameState(Shared &shared);
        virtual ~GameState();

        virtual void init(void);     //load resources
        virtual void destroy(void);  //free resources

        virtual void pause(void);
        virtual void resume(void);

        virtual Next update(void);       //update the state, return the next state
        virtual void draw(void) const;   //draw everything
};

#endif // GAMESTATE_HPP_INCLUDED
