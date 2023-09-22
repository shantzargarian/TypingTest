//
// Created by Shant Zargarian on 4/20/23.
//

#ifndef TYPINGTEST_FONT_H
#define TYPINGTEST_FONT_H
#include <SFML/Graphics.hpp>


class Font {
private:
    static sf::Font font;
    static void loadFont();

public:
    static sf::Font& getFont();
};


#endif //TYPINGTEST_FONT_H
