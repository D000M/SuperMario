/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Snake.h
 * Author: D000M
 *
 * Created on June 5, 2020, 1:27 PM
 */

#ifndef SNAKE_H
#define SNAKE_H

#include <System/Vector2.hpp>
#include <vector>
#include <Graphics/RenderWindow.hpp>
#include <Graphics/RectangleShape.hpp>


struct SnakeSegment {
    SnakeSegment(int x, int y) : mPosition{x, y} {}
    sf::Vector2i mPosition;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction {
    None,
    Up,
    Down,
    Left,
    Right
};

class Snake {
public:
    Snake(int blockSize);
    ~Snake();
    
    //Helper methods
    void setDirection(Direction newDir);
    Direction getDirection();
    Direction getPhysicalDirection();
    int getSpeed();
    sf::Vector2i getPosition();
    int getLives();
    int getScore();
    void increaseScore();
    bool hasLost();
    
    void lose();            //handle losing here
    void toggleLost();
    
    void extend();          //grow the snake
    void reset();           //reset to starting position
    
    void move();            //movement method
    void tick();            //update method
    
    void cut(int segments);  //Method for cutting snake
    void render(sf::RenderWindow& window);
    
private:

    void checkCollision();
    
    SnakeContainer mSnakeBody;
    int mSize;
    
    Direction mDirection;
    int mSpeed;
    int mLives;
    int mScore;
    bool mLost;
    sf::RectangleShape mBodyRect;
    
};

#endif /* SNAKE_H */

