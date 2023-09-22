//
// Created by Shant Zargarian on 4/18/23.
//

#include "Screen.h"
sf::RenderWindow Screen::window;
std::vector<Component*> Screen::components;

void Screen::run() {
    Game game;
    sf::Font font;
    sf::Event event;

    font.loadFromFile("Poppins-SemiBold.ttf");
    std::list<sf::Text> wrappedText = game.outputWords(1);

    window.create({1920, 1080, 32}, "Typing Test");
    window.setFramerateLimit(60);

    sf::Text typeText;
    typeText.setFont(font);
    typeText.setFillColor(sf::Color::Green);
    typeText.setPosition(10.0f, 10.0f);
    typeText.setCharacterSize(24);

    sf::Text timerText;
    timerText.setFont(font);
    timerText.setFillColor(sf::Color::Yellow);
    timerText.setPosition(1300.0f, 25.0f);
    timerText.setCharacterSize(28);
    sf::Clock clock;

    sf::Text accuracyText;
    accuracyText.setFont(font);
    accuracyText.setFillColor(sf::Color::Yellow);
    accuracyText.setPosition(1300.0f, 65.0f);
    accuracyText.setCharacterSize(26);

    sf::Text wpmText;
    wpmText.setFont(font);
    wpmText.setFillColor(sf::Color::Yellow);
    wpmText.setPosition(1300.0f, 105.0f);
    wpmText.setCharacterSize(26);

    Screen::showSplashScreen();

    auto iter = game.getCharsBegin();
    auto wrappedTextIter = wrappedText.begin();

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace) {
                    if (wrappedTextIter != wrappedText.begin()) {
                        --wrappedTextIter;
                        wrappedTextIter->setFillColor(sf::Color::White);
                    }
                } else {
                    MatchStatus matchStatus = game.typingMatches(event, iter);
                    if (matchStatus == MATCH || matchStatus == MISMATCH) {
                        wrappedTextIter->setFillColor(matchStatus == MATCH ? sf::Color::Green : sf::Color::Red);
                        ++wrappedTextIter;
                    }
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace) {
                        if (iter != game.getCharsBegin()) {
                            --iter;
                            wrappedTextIter = std::prev(wrappedTextIter);
                            wrappedTextIter->setFillColor(sf::Color::White);
                        }
                    }

                }
            }
        }

        int timeLeft = static_cast<int>(clock.getElapsedTime().asSeconds());
        timerText.setString("Time: " + std::to_string(timeLeft));

        int acc = game.calculateAcc() * 100;
        accuracyText.setString("Accuracy: " + std::to_string(acc) + "%");

        double wpm = game.calculateWPM() * 100;
        wpmText.setString("Words Per Minute: " + std::to_string(wpm));

        window.clear(sf::Color(50, 50, 50));

        for (const sf::Text &text: wrappedText) {
            window.draw(text);
        }
        window.draw(timerText);
        window.draw(typeText);
        window.draw(wpmText);
        window.draw(accuracyText);
        window.display();
    }
}


void Screen::showSplashScreen() {
    sf::Font font;
    sf::Event event;
    sf::Texture splashScreenTexture;
    sf::Sprite splashScreenSprite;
    sf::RectangleShape startButton(sf::Vector2f(200, 50));
    startButton.setFillColor(sf::Color(50, 150, 50));
    startButton.setPosition(860, 1015);


    if (!splashScreenTexture.loadFromFile("SplashScreen.png")) {
        std::cerr << "Error loading SplashScreen.png" << std::endl;
    }

    splashScreenSprite.setTexture(splashScreenTexture);
    splashScreenSprite.setPosition(360, 185);

    sf::Text startButtonText;
    font.loadFromFile("Poppins-SemiBold.ttf");
    startButtonText.setFont(font);
    startButtonText.setString("Start Game");
    startButtonText.setCharacterSize(24);
    startButtonText.setFillColor(sf::Color::White);
    startButtonText.setPosition(895, 1020);


    sf::Text gameName;
    gameName.setFont(font);
    gameName.setString("SPEED TYPE");
    gameName.setCharacterSize(50);
    gameName.setFillColor(sf::Color::Black);
    gameName.setPosition(870,250);

    sf::Text personalInfo;
    personalInfo.setFont(font);
    personalInfo.setString("Shant Zargarian");
    personalInfo.setCharacterSize(50);
    personalInfo.setFillColor(sf::Color::Yellow);
    personalInfo.setPosition(0,0);

    bool splashScreenActive = true;

    while (window.isOpen() && splashScreenActive) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (MouseEvents::isHovered(startButton.getGlobalBounds(), window)) {
            startButton.setFillColor(sf::Color(100, 200, 100));

            if (MouseEvents::isClicked(startButton.getGlobalBounds(), window)) {
                splashScreenActive = false;
            }
        } else {
            startButton.setFillColor(sf::Color(50, 150, 50));
        }

        window.clear(sf::Color(50, 50, 50));
        window.draw(personalInfo);
        window.draw(splashScreenSprite);
        window.draw(gameName);
        window.draw(startButton);
        window.draw(startButtonText);
        window.display();
    }
}
