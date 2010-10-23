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

#include "terrain.hpp"


#include <iostream>
#include <luabind/luabind.hpp>


Terrain::Terrain(lua_State *ls) :
L(ls)
{
}

Terrain::~Terrain()
{
}

bool Terrain::registerFunctions(lua_State *L)
{
    luabind::module(L)
    [
        luabind::class_<Terrain>("Terrain")
            .def("setPixel", &Terrain::SetPixel)
    ];
    return true;
}

bool Terrain::loadFromFile(const std::string &path)
{
    //create the image
    image.Create(800, 600, sf::Color(0, 0, 0, 0));
    sprite.SetImage(image);
    sprite.Resize(image.GetWidth(), image.GetHeight()); //manual update of the sprite-size

    if(luaL_dofile(L, "data/game/terrain.lua"))
    {
        return false;
    }

    try
    {
        luabind::call_function<void>(L, "create", boost::ref(*this));
    }
    catch(luabind::error &e)
    {
        std::cout << e.what() << ": " << lua_tostring(L, -1) << std::endl;
    }
    return true;
}

void Terrain::Render(sf::RenderTarget& target, sf::Renderer& renderer) const
{
    target.Draw(sprite);
}

void Terrain::SetPixel(int x, int y, sf::Color col)
{
    image.SetPixel(x, y, col);
}
