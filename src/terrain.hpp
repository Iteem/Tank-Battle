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

#ifndef TERRAIN_HPP_INCLUDED
#define TERRAIN_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <lua.hpp>
#include <string>

///class for the terrain
class Terrain : public sf::Drawable
{
    public:
        Terrain(sf::Vector2i dimension); //state need to be loaded by luabind and
                                         //registerFunctions must be called
        ~Terrain();

        static bool registerFunctions(lua_State *L);

        void setPixel(int x, int y, sf::Color col);
        void fill(int x, int h, sf::Color col);
    private:
        void Render(sf::RenderTarget& target, sf::Renderer& renderer) const;

        mutable bool needReload;

        sf::Image image;
        mutable sf::Texture tex;
        sf::Sprite sprite;
};

#endif // TERRAIN_HPP_INCLUDED
