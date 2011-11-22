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

#include "menuState.hpp"

MenuState::MenuState(Shared &shared) :
State(shared)
{
}
MenuState::~MenuState()
{
}

void MenuState::init(void)
{
    quit = false;
	start = false;

    //create Buttons
    quitButton  = sfg::Button::Create("Quit");
    startButton = sfg::Button::Create("Start");

    quitButton->OnClick.Connect(&MenuState::onQuitClicked,  this);
    startButton->OnClick.Connect(&MenuState::onStartClicked, this);

    startButton->SetPosition(sf::Vector2f(450, 200.));
    quitButton->SetPosition(sf::Vector2f(450, 400.));
}

void MenuState::destroy(void)
{
    app.ShowMouseCursor(true);
}

void MenuState::pause(void)
{
}

void MenuState::resume(void)
{
}

State::Next MenuState::update(void)
{
    sf::Event event;
    while(app.PollEvent(event)){
        if(event.Type == sf::Event::Closed){
            return State::Quit;
        }
        if(event.Type == sf::Event::KeyPressed){
            if(event.Key.Code == sf::Keyboard::Escape){
                return State::Quit;
            }
        }

        //update the GUI
        quitButton->HandleEvent(event);
        startButton->HandleEvent(event);
    }

    //check if we need to quit or start the game
    if(start){
        return State::Game;
    }
    if(quit){
        return State::Quit;
    }

    return State::NoChange;
}

void MenuState::draw(void) const
{
    app.Clear(sf::Color::White);

	quitButton->Expose(app);
	startButton->Expose(app);
}

void MenuState::onQuitClicked()
{
    quit = true;
}

void MenuState::onStartClicked()
{
    start = true;
}
