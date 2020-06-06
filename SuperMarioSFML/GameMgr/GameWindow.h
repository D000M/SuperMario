/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameWindow.h
 * Author: D000M
 *
 * Created on June 5, 2020, 12:04 PM
 */

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <string>
#include <System/Vector2.hpp>
#include <Graphics/Drawable.hpp>
#include <Graphics/RenderWindow.hpp>


class GameWindow {
public:
    GameWindow();
    GameWindow(const std::string& title, const sf::Vector2u& size);
    ~GameWindow();
    
    void beginDraw();   //Clear the Window
    void endDraw();     //Display Changes
    
    void update();
    
    bool isDone();
    bool isFullScreen();
    sf::Vector2u getGameWindowSize();
    
    void toggleFullScreen();
    
    void draw(sf::Drawable& drawable);
    
    sf::RenderWindow* getRenderWindow();
private:
    void setupGameWindow(const std::string& title, const sf::Vector2u& size);
    void destroyGameWindow();
    void createGameWindow();
    
    sf::RenderWindow mRenderWindow;
    sf::Vector2u mRenderWindowSize;
    std::string mRenderWindowTitle;
    
    bool mIsDone;
    bool mIsFullScreen;
};

#endif /* GAMEWINDOW_H */

