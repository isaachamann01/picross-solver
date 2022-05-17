#include "Drawer.h"

Drawer::Drawer(int _width, int _height, sf::RenderWindow& _window) {
    width = _width;
    height = _height;
    window = &_window; 
}

void Drawer::draw() {
    //Draw each shape in shape list.
    for (auto shape : shape_list) {
        window->draw(shape);
    }
}

void Drawer::update_shape_list(std::vector<sf::Shape> _shape_list) {
    //Update shape list with a vector of new shapes.
    shape_list = _shape_list; 
}