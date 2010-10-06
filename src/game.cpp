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

#include "game.hpp"
#include "shared.hpp"
#include "state.hpp"

#include "introState.hpp"
#include "menuState.hpp"
#include "gameState.hpp"

Game::Game(int argc, char **argv)
{
}

Game::~Game()
{
}

int Game::run(void)
{
    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Bla");
    Shared shared(app);
    State *state;

    state = new IntroState(shared);
    state->init();

    while(true)
    {
        switch(state->update())
        {
            case State::NoChange:
                break;

            case State::Menu:
                state->destroy();
                delete state;
                state = new MenuState(shared);
                state->init();
                break;

            case State::Game:
                state->destroy();
                delete state;
                state = new GameState(shared);
                state->init();
                break;

            default:
                delete state;
                return 0;
        }

        state->draw();

        app.Display();
    }
}
