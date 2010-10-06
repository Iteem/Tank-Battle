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
