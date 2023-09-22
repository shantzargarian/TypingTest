#ifndef TYPINGTEST_GAME_H
#define TYPINGTEST_GAME_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Font.h"
#include <SFML/Graphics.hpp>
#include "MatchStatus.h"

class Game {

private:
    std::vector<char> charList;
    std::list<sf::Text> gameText;
    std::list<char> chars;
    Font font;
    sf::Font fontText;
    double _total;
    double _misses = 0;
    double _correct = 0;
    std::chrono::high_resolution_clock::time_point _startTime;

public:
    Game();
    void loadFromFile(const std::string& filename, std::vector<char>& charList);
    std::list<char> getChars();
    std::list<sf::Text> outputWords(int gameType);
    MatchStatus typingMatches(sf::Event event, std::list<char>::iterator& iter);
    std::list<char>::iterator getCharsBegin();
    double calculateAcc();
    double calculateWPM();
};
#endif //TYPINGTEST_GAME_H
