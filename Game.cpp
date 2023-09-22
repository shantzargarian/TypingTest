#include <random>
#include "Game.h"


Game::Game()
{}

void Game::loadFromFile(const std::string& filename, std::vector<char>& charList)
{
    std::ifstream file(filename);
    std::string ch;
    std::vector<std::string> strList;
    while (file >> ch)
    {
        std::cout << "read word: " << ch << std::endl;
        ch.insert(ch.end(), ' ');
        strList.push_back(ch);
    }
    file.close();
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(strList.begin(), strList.end(), std::default_random_engine(seed));
    for(std::string& s : strList)
        for(char c : s)
            charList.push_back(c);
    std::cout << "charList size: " << charList.size() << std::endl;
}

std::list<char> Game::getChars()
{
    loadFromFile("Words.txt", charList);
    for (const auto& c : charList)
    {
        chars.push_back(c);
    }
    return chars;
}


std::list<sf::Text> Game::outputWords(int gameType)
{
    if (gameType == 1)
    {
        chars = getChars();
    }
    else if (gameType == 2)
    {
        //empty at the moment
    }

    std::cout << "chars size: " << chars.size() << std::endl;

    float x = 10.0f;
    float y = 10.0f;
    float lineHeight = 35.52f;
    float maxWidth = 1250.0f;

    for (char c : chars)
    {
        sf::Text text;
        text.setString(std::string(1, c));
        text.setFont(font.getFont());
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(x, y);

        float charWidth = text.getLocalBounds().width ;

        if (x + charWidth >= maxWidth)
        {
            x = 10.0f;
            y += lineHeight;
            text.setPosition(x, y);
        }
        x += charWidth +1.7f ;
        gameText.push_back(text);
    }

    return gameText;
}

MatchStatus Game::typingMatches(sf::Event event, std::list<char>::iterator& iter)
{
    if (event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode == *iter)
        {
            ++iter;
            _correct++;
            _total++;
            return MATCH;
        }
        else
        {
            ++iter;
            _misses++;
            _total++;
            return MISMATCH;
        }

    }
    return NONE;

}

std::list<char>::iterator Game::getCharsBegin()
{
    return chars.begin();
}

double Game::calculateAcc()
{
    double acc;

    acc = _correct / _total;
    return  acc;
}

double Game::calculateWPM()
{
    std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - _startTime).count();

    if (duration == 0)
    {
        return 0;
    }

    double wpm = (static_cast<double>(_total - _misses) / 5) / 60;
    return wpm;
}