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

#ifndef LIBLUAGAME_HPP_INCLUDED
#define LIBLUAGAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include <luabind/luabind.hpp>
#include <iostream>

class Terrain;
class Shared;

class LibLuaGame
{
    public:
        LibLuaGame(Terrain *t, Shared &s);
        ~LibLuaGame();

        bool registerFunctions(lua_State *L);
    private:
        Terrain *myTerrain;
        Shared &myShared;

        sf::VideoMode *myVideoMode;
};

#endif // LIBLUAGAME_HPP_INCLUDED
