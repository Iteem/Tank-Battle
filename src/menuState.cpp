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
#include <SFGUI/Align.hpp>

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

	app.ShowMouseCursor(false);

    //create GUI
    myGUI = new sfg::GUI(sf::FloatRect(0,0,myShared.videoMode.Width,myShared.videoMode.Height));
    myGUI->LoadSkinFromFile("data/menu/skins/black.skin");

    //create Buttons
    quitButton  = sfg::Button::Create(sf::FloatRect(0, 0, 80, 35), "Quit" );
    startButton = sfg::Button::Create(sf::FloatRect(0, 0, 80, 35), "Start");

    quitButton->Clicked  = sfg::Slot<sfg::Button::ClickSlot>(&MenuState::onQuitClicked,  this);
    startButton->Clicked = sfg::Slot<sfg::Button::ClickSlot>(&MenuState::onStartClicked, this);

    sfg::AlignWidgetInRect(
		*quitButton,
		sf::FloatRect(myGUI->GetRect()),
		sfg::AlignCenter | sfg::AlignBottom,
		sf::Vector2f( 0, myShared.videoMode.Height / 20.f )
	);
    sfg::AlignWidgetInRect(
		*startButton,
		sf::FloatRect(myGUI->GetRect()),
		sfg::AlignCenter | sfg::AlignTop,
		sf::Vector2f( 0, myShared.videoMode.Height / 20.f )
	);

	//and add them to the GUI
	myGUI->AddWidget(quitButton);
	myGUI->AddWidget(startButton);
}

void MenuState::destroy(void)
{
    app.ShowMouseCursor(true);
    delete myGUI;
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
    while(app.GetEvent(event)){
        if(event.Type == sf::Event::Closed){
            return State::Quit;
        }
        if(event.Type == sf::Event::KeyPressed){
            if(event.Key.Code == sf::Key::Escape){
                return State::Quit;
            }
        }

        //update the GUI
        myGUI->HandleEvent(event);
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

    myGUI->Render(app);
}

void MenuState::onQuitClicked(sfg::Widget::Ptr widget)
{
    quit = true;
}

void MenuState::onStartClicked(sfg::Widget::Ptr widget)
{
    start = true;
}
