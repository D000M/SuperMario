/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Snake.cpp
 * Author: D000M
 * 
 * Created on June 5, 2020, 1:27 PM
 */

#include "Snake.h"

Snake::Snake(int blockSize) {
    
    mSize = blockSize;
    mBodyRect.setSize(sf::Vector2f{static_cast<float>(mSize - 1), static_cast<float>(mSize - 1)});
    
    reset();
    
}

Snake::~Snake() {

}

void Snake::reset() {
    mSnakeBody.clear();
    
    mSnakeBody.push_back(SnakeSegment{5,7});
    mSnakeBody.push_back(SnakeSegment{5,6});
    mSnakeBody.push_back(SnakeSegment{5,5});
    
    setDirection(Direction::None);
    
    mSpeed = 15;
    mLives = 3;
    mScore = 0;
    mLost = false;
}

void Snake::setDirection(Direction newDir) {
    mDirection = newDir;
}

Direction Snake::getDirection() {
    return mDirection;
}

int Snake::getSpeed() {
    return mSpeed;
}

sf::Vector2i Snake::getPosition() {
    return (!mSnakeBody.empty() ? mSnakeBody.front().mPosition : sf::Vector2i{1, 1});
}

int Snake::getLives() {
    return mLives;
}

int Snake::getScore() {
    return mScore;
}

void Snake::increaseScore() {
    mScore += 10;
}

bool Snake::hasLost() {
    return mLost;
}

void Snake::lose() {
    mLost = true;
}

void Snake::toggleLost() {
    mLost = !mLost;
}

void Snake::extend() {
    
    if(mSnakeBody.empty()) {
        return;
    }
    
    SnakeSegment& tailHead = mSnakeBody[mSnakeBody.size() - 1];
    
    if(mSnakeBody.size() > 1) {
        SnakeSegment& tailBone = mSnakeBody[mSnakeBody.size() - 2];
        if(tailHead.mPosition.x == tailBone.mPosition.x) {
            if(tailHead.mPosition.y > tailBone.mPosition.y) {
                mSnakeBody.push_back(SnakeSegment{tailHead.mPosition.x, tailHead.mPosition.y + 1});
            }
            else {
                mSnakeBody.push_back(SnakeSegment{tailHead.mPosition.x, tailHead.mPosition.y - 1});
            }
        }
        else if(tailHead.mPosition.y == tailBone.mPosition.y) {
            if(tailHead.mPosition.x > tailBone.mPosition.x) {
                mSnakeBody.push_back(SnakeSegment{tailHead.mPosition.x + 1, tailHead.mPosition.y});
            }
            else {
                mSnakeBody.push_back(SnakeSegment{tailHead.mPosition.x - 1, tailHead.mPosition.y});
            }
        }
    }
    else {
        if(mDirection == Direction::Up) {
            mSnakeBody.push_back(SnakeSegment{tailHead.mPosition.x, tailHead.mPosition.y + 1});
        }
        else if(mDirection == Direction::Down) {
            mSnakeBody.push_back(SnakeSegment{tailHead.mPosition.x, tailHead.mPosition.y - 1});
        }
        else if(mDirection == Direction::Left) {
            mSnakeBody.push_back(SnakeSegment{tailHead.mPosition.x + 1, tailHead.mPosition.y});
        }
        else if(mDirection == Direction::Right) {
            mSnakeBody.push_back(SnakeSegment{tailHead.mPosition.x - 1, tailHead.mPosition.y});
        }
    }

}

void Snake::tick() {
    if(mSnakeBody.empty()) {
        return;
    }
    if(mDirection == Direction::None) {
        return;
    }
    move();
    checkCollision();
}

void Snake::move() {
    for(int i = mSnakeBody.size() - 1; i > 0; --i) {
        mSnakeBody[i].mPosition = mSnakeBody[i - 1].mPosition;
    }
    if(mDirection == Direction::Left) {
        --mSnakeBody[0].mPosition.x;
    }
    else if(mDirection == Direction::Right) {
        ++mSnakeBody[0].mPosition.x;
    }
    else if(mDirection == Direction::Down) {
        ++mSnakeBody[0].mPosition.y;
    }
    else if(mDirection == Direction::Up) {
        --mSnakeBody[0].mPosition.y;
    }
}

void Snake::checkCollision() {
    if(mSnakeBody.size() < 5) {
        return;
    }
    SnakeSegment& head = mSnakeBody.front();
    
    for(auto it = mSnakeBody.begin() + 1; it != mSnakeBody.end(); it++) {
        if(it->mPosition == head.mPosition) {
            int segments = mSnakeBody.end() - it;
            cut(segments);
            break;
        }
    }
}

void Snake::cut(int segments) {
    for(int i = 0; i < segments; i++) {
        mSnakeBody.pop_back();
    }
    --mLives;
    if(mLives == 0) {
        lose();
        return;
    }
}

void Snake::render(sf::RenderWindow& window) {
    if(mSnakeBody.empty()) {
        return;
    }
    
    auto head = mSnakeBody.begin();
    
    mBodyRect.setFillColor(sf::Color::Yellow);
    mBodyRect.setPosition(head->mPosition.x * mSize, head->mPosition.y * mSize);
    window.draw(mBodyRect);
    
    mBodyRect.setFillColor(sf::Color::Green);
    for(auto it = mSnakeBody.begin() + 1; it != mSnakeBody.end(); ++it) {
        mBodyRect.setPosition(it->mPosition.x * mSize, it->mPosition.y * mSize);
        window.draw(mBodyRect);
    }
}

Direction Snake::getPhysicalDirection() {
    if(mSnakeBody.size() <= 1) {
        return Direction::None;
    }
    
    SnakeSegment& head = mSnakeBody.at(0);
    SnakeSegment& neck = mSnakeBody.at(1);
    
    if(head.mPosition.x == neck.mPosition.x) {
        return (head.mPosition.y > neck.mPosition.y ? Direction::Down : Direction::Up);
    }
    else if(head.mPosition.y == neck.mPosition.y) {
        return (head.mPosition.x > neck.mPosition.x ? Direction::Right : Direction::Left);
    }
    
    return Direction::None;
}

