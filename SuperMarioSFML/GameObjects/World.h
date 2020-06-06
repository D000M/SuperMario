/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   World.h
 * Author: D000M
 *
 * Created on June 5, 2020, 2:33 PM
 */

#ifndef WORLD_H
#define WORLD_H

#include <System/Vector2.hpp>
#include <Graphics/RenderWindow.hpp>
#include <Graphics/CircleShape.hpp>

#include "Snake.h"


class World {
public:
    World(const sf::Vector2u& windowSize);
    ~World();
    
    int getBlockSize();
    void respawnApple();
    
    void update(Snake& snake);
    void render(sf::RenderWindow& window);
private:
    
    sf::Vector2u mWindowSize;
    sf::Vector2i mItem;
    int mBlockSize;
    
    sf::CircleShape mAppleShape;
    std::array<sf::RectangleShape, 4> mBounds;

};

#endif /* WORLD_H */

