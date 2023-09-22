//
// Created by Shant Zargarian on 4/19/23.
//

#include "MouseEvents.h"

bool MouseEvents::isHovered(const sf::FloatRect &bounds, sf::RenderWindow &window)
{
    sf::Vector2f mpos = (sf::Vector2f)sf::Mouse::getPosition(window);
    return bounds.contains(mpos);
}

bool MouseEvents::isClicked(const sf::FloatRect &bounds, sf::RenderWindow &window)
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) && isHovered(bounds, window);
}