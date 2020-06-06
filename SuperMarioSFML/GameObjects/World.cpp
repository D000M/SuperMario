/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   World.cpp
 * Author: D000M
 * 
 * Created on June 5, 2020, 2:33 PM
 */
#include "../utils/RNGGenerator.h"

#include "World.h"

World::World(const sf::Vector2u& windowSize) {
    mBlockSize = 16;
    
    mWindowSize = windowSize;
    respawnApple();
    
    mAppleShape.setFillColor(sf::Color::Red);
    mAppleShape.setRadius(mBlockSize / 2);
    
    for(int i = 0; i < mBounds.size(); i++) {
        mBounds.at(i).setFillColor(sf::Color{150, 0, 0});
        
        if(!((i + 1) % 2)) {
            mBounds.at(i).setSize(sf::Vector2f{static_cast<float>(mWindowSize.x), static_cast<float>(mBlockSize)});
        }
        else {
            mBounds.at(i).setSize(sf::Vector2f{static_cast<float>(mBlockSize), static_cast<float>(mWindowSize.y)});
        }
        
        if(i < 2) {
            mBounds.at(i).setPosition(0, 0);
        }
        else {
            mBounds.at(i).setOrigin(mBounds.at(i).getSize());
            mBounds.at(i).setPosition(sf::Vector2f{mWindowSize});
        }
    }
}

World::~World() {

}

void World::respawnApple() {
    int maxX = (mWindowSize.x / mBlockSize) - 2;
    int maxY = (mWindowSize.y / mBlockSize) - 2;
    
    mItem = sf::Vector2i{getRandomInteger(1, maxX), getRandomInteger(1, maxY)};
    
    mAppleShape.setPosition(mItem.x * mBlockSize, mItem.y * mBlockSize);
    
}

void World::update(Snake& snake) {
    if(snake.getPosition() == mItem) {
        snake.extend();
        snake.increaseScore();
        respawnApple();
    }
    
    int gridSizeX = mWindowSize.x / mBlockSize;
    int gridSizeY = mWindowSize.y / mBlockSize;
    
    if(snake.getPosition().x <= 0 || snake.getPosition().y <= 0 ||
            snake.getPosition().x >= gridSizeX - 1 ||  snake.getPosition().y >= gridSizeY - 1) {
        snake.lose();
    }
}

void World::render(sf::RenderWindow& window) {
    for(int i = 0; i < mBounds.size(); i++) {
        window.draw(mBounds.at(i));
    }
    window.draw(mAppleShape);
}

int World::getBlockSize() {
    return mBlockSize;
}
