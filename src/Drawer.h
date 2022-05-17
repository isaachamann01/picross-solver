#ifndef DRAWER_H
#define DRAWER_H

#include <SFML/Graphics.hpp>
#include <vector>

class Drawer {
    public:
        Drawer(int _width, int _height, sf::RenderWindow& _window);
        void update_shape_list(std::vector<sf::Shape> _shape_list);
        void draw();
    private:
        int width;
        int height;
        sf::RenderWindow* window;
        std::vector<sf::Shape> shape_list;
};


#endif