/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextBox.cpp
 * Author: D000M
 * 
 * Created on June 5, 2020, 3:51 PM
 */

#include <Graphics/Transformable.hpp>
#include <Graphics/Shape.hpp>
#include <Graphics/RenderTarget.hpp>

#include "TextBox.h"

TextBox::TextBox() {
    setup(5, 9, 200, sf::Vector2f{0, 0});
}

TextBox::TextBox(int visible, int charSize, int width, sf::Vector2f screenPos) {
    setup(visible, charSize, width, screenPos);
}

TextBox::~TextBox() {
    clear();
}

void TextBox::setup(int visible, int charSize, int width, sf::Vector2f screenPos) {
    mNumVisible = visible;
    sf::Vector2f offset{2.0f, 2.0f};
    
    mFont.loadFromFile("fallout.ttf");
    mText.setFont(mFont);
    mText.setString("");
    mText.setCharacterSize(charSize);
    mText.setFillColor(sf::Color::Green);
    mText.setPosition(screenPos + offset);
    
    mBackDrop.setSize(sf::Vector2f(width, (visible * (charSize + 1.2f))));
    mBackDrop.setFillColor(sf::Color{90, 90, 90, 90});
    mBackDrop.setPosition(screenPos);
}

void TextBox::addMessage(const std::string& msg) {
    mMessages.push_back(msg);
    if(mMessages.size() < 6) {
        return;
    }
    mMessages.erase(mMessages.begin());
}

void TextBox::clear() {
    mMessages.clear();
}

void TextBox::renderer(sf::RenderWindow& window) {
    std::string content;
    
    for(auto& it : mMessages) {
        content.append(it + "\n");
    }
    
    if(content != "") {
        mText.setString(content);
        window.draw(mBackDrop);
        window.draw(mText);
    }
    
}
