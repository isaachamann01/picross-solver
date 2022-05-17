#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Drawer.h";

int main()
{
    //We initiate in fullscreen, can add other support later but fullscreen + AltF4 works fine for now.
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!", sf::Style::Fullscreen);

    //Get Width and Height of fullscreen mode. (Resolution of computer)
    auto temp = sf::VideoMode::getDesktopMode();
    unsigned int width = temp.width;  
    unsigned int height = temp.height;

    Drawer Drawer(width, height, window);
    std::vector<sf::Shape> shapes; 

    //TESTING IF DRAWING WORKS 
    for (auto i = 0; i < 5; i++) {
        sf::RectangleShape rectangle(sf::Vector2f(float(width)/5,10));
        rectangle.setFillColor(sf::Color(150,50,250));
        rectangle.setPosition(0 + float(width)/5 * i,height - i*100);
    }

    Drawer.update_shape_list(shapes);

    //Create our clock object, measure framerate and ensure that we are showing each iteration of the algorithm.
    sf::Clock Clock;


    //Main sfml loop
    while (window.isOpen())
    {
        //Check if window is closed.
        float Framerate = 1.f / Clock.getElapsedTime().asSeconds();
        Clock.restart();
        std::cout << Framerate << std::endl;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Drawer.draw();
    }

    return 0;
}