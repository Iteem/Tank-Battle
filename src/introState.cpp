#include "introState.hpp"

IntroState::IntroState(Shared &shared) :
State(shared)
{
}
IntroState::~IntroState()
{
}

void IntroState::init(void)
{
    sf::Image *tmp;

    tmp = IM.get("data/intro/sfmllogo.jpg");
    if(tmp != NULL)
    {
        logoSFML.SetImage(*tmp);
    }
    logoSFML.SetPosition(150, 400);
    logoSFML.SetScale(0.75, 0.75);

    tmp = IM.get("data/intro/sfguilogo.png");
    if(tmp != NULL)
    {
        logoSFGUI.SetImage(*tmp);
    }
    logoSFGUI.SetPosition(400, 150);


    tmp = IM.get("data/intro/luabind.png");
    if(tmp != NULL)
    {
        logoLua.SetImage(*tmp);
    }
    logoLua.SetPosition(50, 50);

    m_Clock.Reset();
}

void IntroState::destroy(void)
{
}

void IntroState::pause(void)
{
}

void IntroState::resume(void)
{
}

State::Next IntroState::update(void)
{
    sf::Event event;
    while(app.GetEvent(event))
    {
        if(event.Type == sf::Event::Closed)
        {
            return State::Quit;
        }
        if(event.Type == sf::Event::KeyPressed)
        {
            if(event.Key.Code == sf::Key::Escape)
            {
                return State::Quit;
            }
            else
            {
                return State::Menu;
            }
        }
    }

    if(m_Clock.GetElapsedTime() > 2.f)
    {
        return State::Menu;
    }

    return State::NoChange;
}

void IntroState::draw(void) const
{
    app.Clear(sf::Color::White);

    app.Draw(logoSFML);
    app.Draw(logoSFGUI);
    app.Draw(logoLua);
}
