#include "Drawer.h"
#include <iostream>

Drawer::Drawer(int _width, int _height, sf::RenderWindow* _window) {
    width = _width;
    height = _height;
    window = _window; 

}

void Drawer::draw() {
    //Draw each shape in shape list.
    for (auto shape : shape_list) {
        std::cout << "should be drawing now" << std::endl;
        std::cout << shape_list.size() << std::endl;
        window->draw(shape);
    }
}

void Drawer::update_shape_list(std::vector<sf::RectangleShape> _shape_list) {
    //Update shape list with a vector of new shapes.
    shape_list = _shape_list; 
}


std::vector<sf::RectangleShape> Drawer::matrix_to_shape_list(std::vector<std::vector<int>> matrix) {
    //We convert matrix to a shape list by initialising shape by position in array.
    //Use square matrix for now.
    //THESE ARE DUMMY PADDING AND SIZE VALUES FOR TESTING.

    int size = 50;

    float x_padding = width/2.f - size*matrix.size()/2.f ;
    float y_padding = height/2.f - size*matrix[0].size()/2.f ;
    
    std::vector<sf::RectangleShape> temp;
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        int m = matrix[i].size();
        for (int j = 0; j < m; j++) {
            sf::RectangleShape rectangle(sf::Vector2f(size,size));

            //1 Means that the square is proven to be filled in.
            //0 Means that the square is yet to be proven or unproven.
            //-1 Means that the square is proven to not be filled in.

            //1 = BLACK
            //0 = WHITE
            //-1 = YELLOW

            if (matrix[i][j] == 0) rectangle.setFillColor(sf::Color::White);
            else if (matrix[i][j] == 1) rectangle.setFillColor(sf::Color::Black);
            else if (matrix[i][j] == -1) rectangle.setFillColor(sf::Color::Yellow);

            rectangle.setPosition(x_padding + size*i, 0 + y_padding + size*j);

            rectangle.setOutlineThickness(1);
            rectangle.setOutlineColor(sf::Color::Black);
            temp.push_back(rectangle);
        }
    }
    return temp;
}