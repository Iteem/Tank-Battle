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
