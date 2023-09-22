//
// Created by Shant Zargarian on 4/19/23.
//

#ifndef TYPINGTEST_COMPONENT_H
#define TYPINGTEST_COMPONENT_H
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"

class Component : virtual public sf::Drawable{

public:
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) = 0;
    virtual void update() = 0;
};
#endif //TYPINGTEST_COMPONENT_H
