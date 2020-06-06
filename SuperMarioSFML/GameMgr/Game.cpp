/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: D000M
 * 
 * Created on June 5, 2020, 12:23 PM
 */

#include <Window/Keyboard.hpp>

#include "../utils/RNGGenerator.h"
#include "../utils/Utils.h"

#include "Game.h"



Game::Game() : 
    mGameWindow{"Chapter 2", sf::Vector2u{800, 600}},
    mWorld{sf::Vector2u{800, 600}},
    mSnake{mWorld.getBlockSize()} {
    mTextBox.setup(5, 14, 350, sf::Vector2f{225, 0});
    mTextBox.addMessage("Random Number Generator Seeded: " + toString(getSeed()));
    mClock.restart();
    mElapsed = 0.0f;
    restartClock();
}


Game::~Game() {

}

void Game::update() {
    mGameWindow.update();
    
    float timeStep = 1.0f / mSnake.getSpeed();
    
    if(mElapsed >= timeStep) {
        mSnake.tick();
        mWorld.update(mSnake);
        mElapsed -= timeStep;
        if(mSnake.hasLost()) {
            mSnake.reset();
            mWorld.respawnApple();
        }
    }
}


void Game::render() {
    
    mGameWindow.beginDraw();
    
    mWorld.render(*mGameWindow.getRenderWindow());
    mSnake.render(*mGameWindow.getRenderWindow());
    mTextBox.renderer(*mGameWindow.getRenderWindow());
    
    mGameWindow.endDraw();
    
}

void Game::handleInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && mSnake.getPhysicalDirection() != Direction::Down) {
        mSnake.setDirection(Direction::Up);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && mSnake.getPhysicalDirection() != Direction::Up) {
         mSnake.setDirection(Direction::Down);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && mSnake.getPhysicalDirection() != Direction::Right) {
         mSnake.setDirection(Direction::Left);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && mSnake.getPhysicalDirection() != Direction::Left) {
         mSnake.setDirection(Direction::Right);
    }
}

GameWindow* Game::getGameWindow() {
    return &mGameWindow;
}

sf::Time Game::getElapsedTime() {
//    return mTime;
    return mClock.getElapsedTime();
}

void Game::restartClock() {
//    mTime = mClock.restart();
    mElapsed += mClock.restart().asSeconds();
}
