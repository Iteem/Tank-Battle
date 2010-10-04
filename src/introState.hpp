#ifndef INTROSTATE_HPP_INCLUDED
#define INTROSTATE_HPP_INCLUDED

#include "state.hpp"
#include "imageManager.hpp"

#include <SFML/Graphics.hpp>

///class for the intro
class IntroState : public State
{
    public:
        IntroState(Shared &shared);
        virtual ~IntroState();

        virtual void init(void);     //load resources
        virtual void destroy(void);  //free resources

        virtual void pause(void);
        virtual void resume(void);

        virtual Next update(void);       //update the state, return the next state
        virtual void draw(void) const;   //draw everything
    private:
        ImageManager IM;
        sf::Sprite logoSFML, logoSFGUI, logoLua;
        sf::Clock m_Clock;
};

#endif // INTROSTATE_HPP_INCLUDED
