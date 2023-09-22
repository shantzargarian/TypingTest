//
// Created by Shant Zargarian on 4/19/23.
//

#ifndef TYPINGTEST_MOUSEEVENTS_H
#define TYPINGTEST_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>

class MouseEvents{
public:
    static bool isHovered(const sf::FloatRect& bounds, sf::RenderWindow& window);
    static bool isClicked(const sf::FloatRect& bounds, sf::RenderWindow& window);
};


#endif //TYPINGTEST_MOUSEEVENTS_H
