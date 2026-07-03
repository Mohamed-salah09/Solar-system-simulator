#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
class Planet
{
private:
    string name;
    float radius;
    float orbit_radius;
    float angle;
    float speed;
    sf::CircleShape shape;
    sf::Color color;

public:
    Planet(string name, float radius, float orbit_radius, float angle, float speed, const sf::Color &color);
    void update(float delta_time, float centerx, float centery);
    void draw(sf::RenderWindow &window);
    void draw_orbit(sf::RenderWindow &window, float centerx, float centery);
    void set_name(sf::RenderWindow &window, sf::Font &font);
};