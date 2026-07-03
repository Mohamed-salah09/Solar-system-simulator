#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/planet.h"
#include <cmath>
using namespace std;
Planet::Planet(string name, float radius, float orbit_radius, float angle, float speed, const sf::Color &color)
{
    this->name = name;
    this->radius = radius;
    this->orbit_radius = orbit_radius;
    this->angle = angle;
    this->speed = speed;
    this->color = color;
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin({radius, radius});
}

void Planet::update(float delta_time, float centerx, float centery)
{
    // the rules that make  planets goes around the sun
    angle = angle + speed * delta_time;
    float x = centerx + orbit_radius * cos(angle);
    float y = centery + orbit_radius * sin(angle);
    shape.setPosition({x, y});
}

void Planet::draw(sf::RenderWindow &window)
{
    window.draw(shape);
}
void Planet::draw_orbit(sf::RenderWindow &window, float centerx, float centery)
{
    sf::CircleShape orbit(orbit_radius);
    orbit.setFillColor(sf::Color::Transparent);
    orbit.setOutlineColor(sf::Color(80, 80, 80));
    orbit.setOutlineThickness(1.f);

    orbit.setOrigin({orbit_radius, orbit_radius});

    orbit.setPosition({centerx, centery});

    window.draw(orbit);
}

void Planet::set_name(sf::RenderWindow &window, sf::Font &font)
{
    sf::Text text(font);

    text.setString(name);
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::White);

    text.setPosition({shape.getPosition().x + 10.f,
                      shape.getPosition().y - 10.f});

    window.draw(text);
}
