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

#include "gameState.hpp"
#include "terrain.hpp"

#include <exception>
#include <iostream>
#include <luabind/luabind.hpp>

GameState::GameState(Shared &shared) :
State(shared)
{
}
GameState::~GameState()
{
}

void GameState::init(void)
{
    L = lua_open();
    if(L == NULL){
        throw std::runtime_error("Could not open luastate");
    }
    luaL_openlibs(L);
    luabind::open(L);

    luabind::module(L)
    [
        luabind::class_<sf::Color>("Color")
            .def(luabind::constructor<int, int, int, int>())
            .def_readwrite("r", &sf::Color::r)
            .def_readwrite("g", &sf::Color::g)
            .def_readwrite("b", &sf::Color::b)
            .def_readwrite("a", &sf::Color::a)

    ];

    Terrain::registerFunctions(L);
    myTerrain = new Terrain(sf::Vector2i(myShared.videoMode.Width, myShared.videoMode.Height));

    if(luaL_dofile(L, "data/game/terrain.lua")){
        throw std::runtime_error("Not able to load the script for terrain-generating.");
    }

    try{
        luabind::call_function<void>(L, "create", boost::ref(myTerrain), myShared.videoMode.Width, myShared.videoMode.Height);
    }catch(luabind::error &e){
        std::cout << e.what() << ": " << lua_tostring(L, -1) << std::endl;
    }

    background.AddPoint(sf::Vector2f(0, 0), sf::Color::Black);
    background.AddPoint(sf::Vector2f(myShared.videoMode.Width,  0), sf::Color::Black);
    background.AddPoint(sf::Vector2f(myShared.videoMode.Width, myShared.videoMode.Height), sf::Color(0, 190, 255));
    background.AddPoint(sf::Vector2f(0, myShared.videoMode.Height), sf::Color(0, 190, 255));
}

void GameState::destroy(void)
{
    lua_close(L);
    delete myTerrain;
}

void GameState::pause(void)
{
}

void GameState::resume(void)
{
}

State::Next GameState::update(void)
{
    sf::Event event;
    while(app.GetEvent(event)){
        if(event.Type == sf::Event::Closed){
            return State::Quit;
        }
        if(event.Type == sf::Event::KeyPressed){
            if(event.Key.Code == sf::Key::Escape){
                return State::Menu;
            }
        }
    }

    return State::NoChange;
}

void GameState::draw(void) const
{
    app.Clear(sf::Color::White);

    app.Draw(background);
    app.Draw(*myTerrain);
}
