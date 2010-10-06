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

#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

#include "shared.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

///virtual base class for all states
class State
{
    public:
        enum Next
        {
            NoChange,
            Intro,
            Menu,
            Game,
            Quit
        };

        State(Shared &shared): myShared(shared), app(shared.app){};
        virtual ~State(){};

        virtual void init(void) = 0;     //load resources
        virtual void destroy(void) = 0;  //free resources

        virtual void pause(void) = 0;
        virtual void resume(void) = 0;

        virtual Next update(void) = 0;       //update the state, return the next state
        virtual void draw(void) const = 0;   //draw everything

    protected:
        Shared &myShared;
        sf::RenderWindow &app;
};

#endif // STATE_HPP_INCLUDED
