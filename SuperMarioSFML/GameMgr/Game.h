/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: D000M
 *
 * Created on June 5, 2020, 12:23 PM
 */

#ifndef GAME_H
#define GAME_H

#include <Graphics/Texture.hpp>
#include <Graphics/Sprite.hpp>

#include "GameWindow.h"
#include "../GameObjects/Snake.h"
#include "../GameObjects/World.h"
#include "../GameObjects/TextBox.h"

class Game {
public:
    Game();
    ~Game();
    
    void handleInput();
    void update();
    void render();
    GameWindow* getGameWindow();
    
    sf::Time getElapsedTime();
    void restartClock();
private:
    GameWindow mGameWindow;
    sf::Clock mClock;
    //sf::Time mTime;
    float mElapsed;
    
    World mWorld;
    Snake mSnake;
    
    TextBox mTextBox;
};

#endif /* GAME_H */

