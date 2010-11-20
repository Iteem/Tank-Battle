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

#ifndef BASERESOURCEMANAGER_HPP_INCLUDED
#define BASERESOURCEMANAGER_HPP_INCLUDED

#include <map>
#include <string>

#include <utility>

///virtual base-class for all resourcemanager
template<typename T>
class BaseResourceManager
{
    private:
        typedef std::pair<T *, int> res;
        typedef std::map<std::string, res> resMap;
    public:
        BaseResourceManager(void)
        {
        };

        virtual ~BaseResourceManager(void)
        {
            //delete all resources
            for(typename resMap::iterator it = m_resources.begin(); it != m_resources.end(); ++it){
                delete (it->second).first;
            }
        };

        T *get(const std::string &path)
        {
            typename resMap::iterator it(m_resources.find(path));

            if(it != m_resources.end()){
                (it->second).second++;
                return (it->second).first;
            }else{
                return NULL;
            }
        };

        void add(const std::string &path, T *res)
        {
            m_resources[path] = std::pair<T *, int>(res, 1);
        }

        void free(const std::string &path)
        {
            typename resMap::iterator it(m_resources.find(path));

            if(it != m_resources.end()){ //key found, delete the resource
                (it->second).second--;
                if((it->second).second < 1){
                    delete (it->second).first;
                    m_resources.erase(it);
                }
            }
        };

    private:
        resMap m_resources;
};

#endif // BASERESOURCEMANAGER_HPP_INCLUDED
