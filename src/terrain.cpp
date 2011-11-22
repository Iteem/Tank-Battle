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

#include <luabind/luabind.hpp>


Terrain::Terrain(sf::Vector2i dimension) :
needReload(false)
{
    //create the image
    image.Create(dimension.x, dimension.y, sf::Color(0, 0, 0, 0));
    tex.SetSmooth(true);
    tex.LoadFromImage(image);
    sprite.SetTexture(tex);
}

Terrain::~Terrain()
{
}

bool Terrain::registerFunctions(lua_State *L)
{
    luabind::module(L)
    [
        luabind::class_<Terrain>("Terrain")
            .def("setPixel", &Terrain::setPixel)
            .def("fill", &Terrain::fill)
    ];
    return true;
}


void Terrain::Render(sf::RenderTarget& target, sf::Renderer& renderer) const
{
	if(needReload){
		tex.LoadFromImage(image);
		needReload = false;
	}
    target.Draw(sprite);
}

void Terrain::setPixel(int x, int y, sf::Color col)
{
    image.SetPixel(x, y, col);
    needReload = true;
}

void Terrain::fill(int x, int h, sf::Color col)
{
    for(unsigned int i = h; i < image.GetHeight() - 1; i++){
        image.SetPixel(x, i, col);
    }
}
