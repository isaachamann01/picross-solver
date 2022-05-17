#ifndef DRAWER_H
#define DRAWER_H

#include <SFML/Graphics.hpp>
#include <vector>

class Drawer {
    public:
        Drawer(int _width, int _height, sf::RenderWindow* _window);
        void update_shape_list(std::vector<sf::RectangleShape> _shape_list);
        void draw();
        std::vector<sf::RectangleShape> matrix_to_shape_list(std::vector<std::vector<int>> matrix);
    private:
        int width;
        int height;
        sf::RenderWindow* window;
        std::vector<sf::RectangleShape> shape_list;
};


#endif