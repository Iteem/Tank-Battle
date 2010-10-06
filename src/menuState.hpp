#ifndef MENUSTATE_HPP_INCLUDED
#define MENUSTATE_HPP_INCLUDED

#include "state.hpp"

#include <SFGUI/Gui.hpp>
#include <SFGUI/Button.hpp>

///class for the menu
class MenuState : public State
{
    public:
        MenuState(Shared &shared);
        virtual ~MenuState();

        virtual void init(void);     //load resources
        virtual void destroy(void);  //free resources

        virtual void pause(void);
        virtual void resume(void);

        virtual Next update(void);       //update the state, return the next state
        virtual void draw(void) const;   //draw everything
    private:
        sfg::GUI *myGUI;

        sfg::Button::Ptr quitButton;
        sfg::Button::Ptr startButton;

        void onQuitClicked (sfg::Widget::Ptr widget);
        void onStartClicked(sfg::Widget::Ptr widget);

        bool quit;
        bool start;
};

#endif // MENUSTATE_HPP_INCLUDED
