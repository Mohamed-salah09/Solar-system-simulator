#include <SFML/Graphics.hpp>
#include "../header/planet.h"
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    sf::Font font;

    if (!font.openFromFile("../assets/Montserrat/Montserrat-Italic-VariableFont_wght.ttf"))
    {
        return -1;
    }
    sf::RenderWindow window(sf::VideoMode({1400, 900}), "Solar System", sf::Style::Close);
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<sf::CircleShape> stars;

    for (int i = 0; i < 200; i++)
    {
        sf::CircleShape star;

        float radius = static_cast<float>(std::rand() % 3 + 1);

        star.setRadius(radius);
        star.setFillColor(sf::Color::White);

        float x = static_cast<float>(std::rand() % 1400);
        float y = static_cast<float>(std::rand() % 900);

        star.setPosition({x, y});

        stars.push_back(star);
    }

    sf::CircleShape sun(50.f);
    sun.setFillColor(sf::Color::Yellow);
    sun.setOrigin({50.f, 50.f});
    sun.setPosition({700.f, 450.f});
    Planet Earth("Earth", 8.f, 150.f, 0.f, 1.f, sf::Color::Blue);
    Planet Mercury("Mercury", 5.f, 100.f, 0.f, 1.8f, sf::Color(169, 169, 169));
    Planet Venus("Venus", 7.f, 125.f, 45.f, 1.2f, sf::Color::Yellow);
    Planet Mars("Mars", 6.f, 180.f, 180.f, 0.8f, sf::Color::Red);
    Planet Jupiter("Jupiter", 20.f, 250.f, 270.f, 0.4f, sf::Color(255, 165, 0));
    Planet Saturn("Saturn", 18.f, 320.f, 225.f, 0.3f, sf::Color(210, 180, 140));
    Planet Uranus("Uranus", 12.f, 380.f, 270.f, 0.2f, sf::Color::Cyan);
    Planet Neptune("Neptune", 12.f, 450.f, 315.f, 0.15f, sf::Color(0, 0, 255));
    sf::Clock clock;

    while (window.isOpen())
    {
        float deltatime = clock.restart().asSeconds();
        while (auto event = window.pollEvent())
        {
            // if the event is closed then close
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        // or  complete as you are
        Earth.update(deltatime, 700.f, 450.f);
        Mercury.update(deltatime, 700.f, 450.f);
        Venus.update(deltatime, 700.f, 450.f);
        Mars.update(deltatime, 700.f, 450.f);
        Jupiter.update(deltatime, 700.f, 450.f);
        Saturn.update(deltatime, 700.f, 450.f);
        Uranus.update(deltatime, 700.f, 450.f);
        Neptune.update(deltatime, 700.f, 450.f);
        window.clear(sf::Color::Black);
        for (auto &star : stars)
        {
            window.draw(star);
        }
        window.draw(sun);
        // ORBITS
        Earth.draw_orbit(window, 700.f, 450.f);
        Mercury.draw_orbit(window, 700.f, 450.f);
        Venus.draw_orbit(window, 700.f, 450.f);
        Mars.draw_orbit(window, 700.f, 450.f);
        Jupiter.draw_orbit(window, 700.f, 450.f);
        Saturn.draw_orbit(window, 700.f, 450.f);
        Uranus.draw_orbit(window, 700.f, 450.f);
        Neptune.draw_orbit(window, 700.f, 450.f);

        // set name
        Earth.set_name(window, font);
        Mercury.set_name(window, font);
        Venus.set_name(window, font);
        Mars.set_name(window, font);
        Jupiter.set_name(window, font);
        Saturn.set_name(window, font);
        Uranus.set_name(window, font);
        Neptune.set_name(window, font);
        // DRAW
        Earth.draw(window);
        Mercury.draw(window);
        Venus.draw(window);
        Mars.draw(window);
        Jupiter.draw(window);
        Saturn.draw(window);
        Uranus.draw(window);
        Neptune.draw(window);

        window.display();
    }

    return 0;
}