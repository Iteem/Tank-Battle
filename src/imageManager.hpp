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

#ifndef IMAGEMANAGER_HPP_INCLUDED
#define IMAGEMANAGER_HPP_INCLUDED

#include "resourceManager.hpp"

///the imagemanager
class ImageManager : public ResourceManager<sf::Image>
{
    public:
        ImageManager(void) {};
        virtual ~ImageManager(){};
    private:
        virtual sf::Image *load(const std::string &path)
        {
            sf::Image *tmp = new sf::Image;
            if(!tmp->LoadFromFile(path)){
                //failed to load image, clean up and return NULL
                delete tmp;
                return NULL;
            }
            return tmp;
        }
};

#endif // IMAGEMANAGER_HPP_INCLUDED
