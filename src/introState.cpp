/*
   Copyright 2010 Patrick Winkler

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
    sf::Vector2f factor = sf::Vector2f( myShared.videoMode.Width / 800.f,
                                        myShared.videoMode.Height / 600.f);

    sf::Texture *tmp;

    tmp = IM.get("data/intro/sfmllogo.jpg");
    tmp->SetSmooth(true);
    if(tmp != NULL){
        logoSFML.SetTexture(*tmp);
    }
    logoSFML.SetPosition(150 * factor.x, 400 * factor.y);
    logoSFML.SetScale(0.75 * factor.x, 0.75 * factor.y);

    tmp = IM.get("data/intro/sfguilogo.png");
    tmp->SetSmooth(true);
    if(tmp != NULL){
        logoSFGUI.SetTexture(*tmp);
    }
    logoSFGUI.SetPosition(400 * factor.x, 150 * factor.y);
    logoSFGUI.SetScale(1 * factor.x, 1 * factor.y);


    tmp = IM.get("data/intro/luabind.png");
    tmp->SetSmooth(true);
    if(tmp != NULL){
        logoLua.SetTexture(*tmp);
    }
    logoLua.SetPosition(50 * factor.x, 50 * factor.y);
    logoLua.SetScale(1 * factor.x, 1 * factor.y);

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
    while(app.PollEvent(event))
    {
        if(event.Type == sf::Event::Closed){
            return State::Quit;
        }
        if(event.Type == sf::Event::KeyPressed){
            if(event.Key.Code == sf::Keyboard::Escape){
                return State::Quit;
            }else{
                return State::Menu;
            }
        }
    }

    if(m_Clock.GetElapsedTime() > 2000.f){
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
