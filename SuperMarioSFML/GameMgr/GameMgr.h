/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameMgr.h
 * Author: D000M
 *
 * Created on June 5, 2020, 12:35 PM
 */

#ifndef GAMEMGR_H
#define GAMEMGR_H

#include "Game.h"


class GameMgr {
public:
    
    static void run();
private:
    static Game myGame;
};

#endif /* GAMEMGR_H */

