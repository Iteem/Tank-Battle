#ifndef IMAGEMANAGER_HPP_INCLUDED
#define IMAGEMANAGER_HPP_INCLUDED

#include "baseResourceManager.hpp"

///the imagemanager
class ImageManager : public BaseResourceManager<sf::Image>
{
    public:
        ImageManager(void) {};
        virtual ~ImageManager(){};
    private:
        virtual sf::Image *load(const std::string &path)
        {
            sf::Image *tmp = new sf::Image;
            if(!tmp->LoadFromFile(path))
            {
                //failed to load image, clean up and return NULL
                delete tmp;
                return NULL;
            }
            return tmp;
        }
};

#endif // IMAGEMANAGER_HPP_INCLUDED
