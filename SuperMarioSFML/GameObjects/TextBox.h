/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextBox.h
 * Author: D000M
 *
 * Created on June 5, 2020, 3:51 PM
 */

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <System/Vector2.hpp>
#include <Graphics/RenderWindow.hpp>
#include <Graphics/RectangleShape.hpp>
#include <Graphics/Font.hpp>
#include <Graphics/Text.hpp>

using MessageContainer = std::vector<std::string>;

class TextBox {
public:
    TextBox();
    TextBox(int visible, int charSize, int width, sf::Vector2f screenPos);
    ~TextBox();
    
    void setup(int visible, int charSize, int width, sf::Vector2f screenPos);
    void addMessage(const std::string& msg);
    void clear();
    
    void renderer(sf::RenderWindow& window);
    
private:
    MessageContainer mMessages;
    int mNumVisible;
    
    sf::RectangleShape mBackDrop;
    sf::Font mFont;
    sf::Text mText;

};

#endif /* TEXTBOX_H */

