//
// Created by Shant Zargarian on 4/20/23.
//

#include "Font.h"

sf::Font Font::font;
void Font::loadFont()
{
    font.loadFromFile("Poppins-SemiBold.ttf");
}

sf::Font& Font::getFont()
{
    loadFont();
    return font;
}