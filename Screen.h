//
// Created by Shant Zargarian on 4/18/23.
//

#ifndef TYPINGTEST_SCREEN_H
#define TYPINGTEST_SCREEN_H
#include "Component.h"
#include <SFML/Graphics.hpp>
#include "Game.h"

class Screen {
private:
    static sf::RenderWindow window;
    static std::vector<Component*> components;
public:
    static void run();
    static void showSplashScreen();
};


#endif //TYPINGTEST_SCREEN_H
