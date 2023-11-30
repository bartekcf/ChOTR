// MenuState.cpp
#include "MenuState.h"
#include <iostream>

MenuState::MenuState(sf::RenderWindow& window) : mWindow(window) {
    if (!backgroundTexture.loadFromFile("../assets/images/background.png")) {
        std::cout << "Nie udało się załadować pliku" << std::endl;
        return;
    }
    backgroundSprite.setTexture(backgroundTexture);

    // Inicjalizacja przycisków i innych elementów UI...
    initButtons();
}

void MenuState::initButtons() {
    // Załaduj tekstury przycisków
    if (!buttonTexture.loadFromFile("../assets/images/przy_2.jpg")) {
        std::cout << "Nie udało się załadować tekstury przycisku" << std::endl;
        return;
    }

    if (!font.loadFromFile("../assets/fonts/font_2.ttf")) {
        std::cout << "Nie udało się załadować tekstury przycisku" << std::endl;
        return;
    }

    buttons.push_back(std::make_unique<Button>(font, buttonTexture, sf::Vector2f(400, 300), sf::Vector2f(200, 50), "Nowa Gra"));
    buttons.push_back(std::make_unique<Button>(font, buttonTexture, sf::Vector2f(400, 400), sf::Vector2f(200, 50), "Wczytaj Gre"));
    buttons.push_back(std::make_unique<Button>(font, buttonTexture, sf::Vector2f(400, 500), sf::Vector2f(200, 50), "Opcje"));

// Ustawienie funkcji zwrotnych dla przycisków
    buttons[0]->setCallback([this]() {
        // Logika dla nowej gry
    });
    buttons[1]->setCallback([this]() {
        // Logika dla wczytania gry
    });
    buttons[2]->setCallback([this]() {
        // Logika dla opcji
    });

}

void MenuState::handleInput() {
    sf::Event event{};
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }

        // Obsługa zdarzeń dla przycisków
        for (auto& button : buttons) {
            button->handleInput(event, mWindow);
        }
    }
}

void MenuState::update(sf::Time deltaTime) {
    // Aktualizacja logiki menu
    // Tutaj możesz także dodać animacje lub inne efekty
}

void MenuState::render() {
    mWindow.clear();
    mWindow.draw(backgroundSprite); // Rysowanie tła

    // Rysowanie przycisków i innych elementów UI
    for (const auto& button : buttons) {
        button->render(mWindow);
    }

    mWindow.display();
}
