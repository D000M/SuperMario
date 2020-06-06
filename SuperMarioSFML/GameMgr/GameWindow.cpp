/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameWindow.cpp
 * Author: D000M
 * 
 * Created on June 5, 2020, 12:04 PM
 */

#include <Window/Event.hpp>

#include "GameWindow.h"

GameWindow::GameWindow() {
    
    setupGameWindow("Default Window", sf::Vector2u{640, 480});
    
}

GameWindow::GameWindow(const std::string& title, const sf::Vector2u& size) {
    
    setupGameWindow(title, size);
    
}

GameWindow::~GameWindow() {
    
    destroyGameWindow();
    
}

void GameWindow::setupGameWindow(const std::string& title, const sf::Vector2u& size) {
    
    mRenderWindowTitle = title;
    mRenderWindowSize = size;
    mIsFullScreen = false;
    mIsDone = false;
    
    createGameWindow();
    
}

void GameWindow::createGameWindow() {
    
//    auto style = (mIsFullScreen ? sf::Style::Fullscreen : sf::Style::Default);
    sf::Uint32 style = (mIsFullScreen ? sf::Style::Fullscreen : sf::Style::Default);
    mRenderWindow.create( {mRenderWindowSize.x, mRenderWindowSize.y}, mRenderWindowTitle, style);
    mRenderWindow.setFramerateLimit(120);
}

void GameWindow::destroyGameWindow() {
    
    mRenderWindow.close();
    
}

void GameWindow::update() {
    
    sf::Event event;
    
    while(mRenderWindow.pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            mIsDone = true;
        }
        else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
            toggleFullScreen();
        }
    }
    
}

void GameWindow::toggleFullScreen() {
    
    mIsFullScreen = !mIsFullScreen;
    destroyGameWindow();
    createGameWindow();
    
}

void GameWindow::beginDraw() {
    
    mRenderWindow.clear(sf::Color::Black);
    
}

void GameWindow::endDraw() {
    
    mRenderWindow.display();
    
}

sf::Vector2u GameWindow::getGameWindowSize() {
    
    return mRenderWindowSize;
    
}

void GameWindow::draw(sf::Drawable& drawable) {
    
    mRenderWindow.draw(drawable);
    
}

bool GameWindow::isDone() {
    
    return mIsDone;
    
}

bool GameWindow::isFullScreen() {
    
    return mIsFullScreen;
    
}

sf::RenderWindow* GameWindow::getRenderWindow() {
    return &mRenderWindow;
}
