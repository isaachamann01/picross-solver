#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Drawer.h"
#include "Picross.h"

int main()
{
    //We initiate in fullscreen, can add other support later but fullscreen + AltF4 works fine for now.
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!", sf::Style::Fullscreen);

    //Get Width and Height of fullscreen mode. (Resolution of computer)
    auto temp = sf::VideoMode::getDesktopMode();
    unsigned int width = temp.width;  
    unsigned int height = temp.height;

    Drawer Drawer(width, height, &window);
    std::vector<sf::RectangleShape> shapes; 

    //TESTING IF DRAWING WORKS 
    for (auto i = 0; i < 5; i++) {
        sf::RectangleShape rectangle(sf::Vector2f(100,100));
        rectangle.setFillColor(sf::Color(150,50,250));
        rectangle.setPosition(100,100);
        shapes.push_back(rectangle);
    }

    Drawer.update_shape_list(shapes);

    //Create our clock object, measure framerate and ensure that we are showing each iteration of the algorithm.
    sf::Clock Clock;

    std::vector<std::vector<int>> x_conditions = {{3,1},{3,1},{3,2},{2,1},{5,1},{2,3},{2,3,1},{3,2,1},{3,2,1},{2,1}};
    std::vector<std::vector<int>> y_conditions = {{5},{10},{5,2},{3,3},{6},{5},{4},{1},{1},{3}};
    Picross algorithm = Picross(x_conditions, y_conditions);

    //Main sfml loop
    while (window.isOpen())
    {
        //Check if window is closed.
        float Framerate = 1.f / Clock.getElapsedTime().asSeconds();
        Clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);

        //Solve the Picross Algorithm 
        algorithm.solve();

        //Convert the picross ns to shapes;

        Drawer.update_shape_list(Drawer.matrix_to_shape_list(algorithm.getAns()));

        Drawer.draw();
        window.display();
    }

    return 0;
}