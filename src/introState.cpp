/*
   Copyright 20010 Patrick Winkler

   This file is part of Tank Battle

   Tank Battle software is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   Tank Battle software is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/

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
