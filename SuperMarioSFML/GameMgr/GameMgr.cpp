/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameMgr.cpp
 * Author: D000M
 * 
 * Created on June 5, 2020, 12:35 PM
 */

#include "GameMgr.h"

Game GameMgr::myGame;

void GameMgr::run() {
    while(!myGame.getGameWindow()->isDone()) {
        myGame.handleInput();
        myGame.update();
        myGame.render();
        myGame.restartClock();
    }
}

