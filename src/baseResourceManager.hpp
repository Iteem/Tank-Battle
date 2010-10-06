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

#ifndef BASERESOURCEMANAGER_HPP_INCLUDED
#define BASERESOURCEMANAGER_HPP_INCLUDED

#include <map>
#include <string>

///virtual base-class for all resourcemanager
template<typename T>
class BaseResourceManager
{
    private:
        typedef std::map<std::string, T *> resMap;
    public:
        BaseResourceManager(void)
        {
        };

        virtual ~BaseResourceManager(void)
        {
            freeAll();
        };

        T *get(const std::string &path)
        {
            typename resMap::iterator it(m_resources.find(path));

            if(it != m_resources.end()) //key found
            {
                return it->second;
            }
            else //key not found, load resource
            {
                T *tmp = load(path);
                if(tmp == NULL) //failed to load resource
                {
                    return NULL;
                }
                else
                {
                    //add the loaded resource to the map and return it
                    m_resources[path] = tmp;
                    return tmp;
                }
            }
        };

        void free(const std::string &path)
        {
            typename resMap::iterator it(m_resources.find(path));

            if(it != m_resources.end()) //key found, delete the resource
            {
                delete it->second;
                m_resources.erase(it);
            }
        };

        void freeAll(void)
        {
             //delete all resources
            for(typename resMap::iterator it = m_resources.begin(); it != m_resources.end(); ++it)
            {
                delete it->second;
            }
            m_resources.clear();
        };

    private:
        //the function to load the resource, must be redefined for each type
        virtual T *load(const std::string &path) = 0;

        resMap m_resources;
};

#endif // BASERESOURCEMANAGER_HPP_INCLUDED
