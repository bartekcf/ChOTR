#include "MenuState.h"
#include <iostream>

MenuState::MenuState(sf::RenderWindow& window, GameStateManager& manager)
        : mWindow(window), gameStateManager(manager) {
    if (!backgroundTexture.loadFromFile("../assets/images/background.png")) {
        std::cout << "Nie udało się załadować pliku" << std::endl;
        return;
    }
    backgroundSprite.setTexture(backgroundTexture);

    initButtons();
}

MenuState::~MenuState() {
    // Tutaj możesz umieścić logikę czyszczenia, jeśli jest potrzebna
}

void MenuState::initButtons() {
    if (!buttonTexture.loadFromFile("../assets/images/button.jpg")) {
        std::cout << "Nie udało się załadować tekstury przycisku" << std::endl;
        return;
    }

    if (!font.loadFromFile("../assets/fonts/font.ttf")) {
        std::cout << "Nie udało się załadować czcionki" << std::endl;
        return;
    }

    buttons.push_back(std::make_unique<Button>(font, buttonTexture, sf::Vector2f(400, 300), sf::Vector2f(200, 50), "Nowa Gra"));
    buttons.push_back(std::make_unique<Button>(font, buttonTexture, sf::Vector2f(400, 400), sf::Vector2f(200, 50), "Wczytaj Gre"));
    buttons.push_back(std::make_unique<Button>(font, buttonTexture, sf::Vector2f(400, 500), sf::Vector2f(200, 50), "Opcje"));

    buttons[0]->setCallback([this]() {
        // Tutaj implementacja przejścia do innego stanu, np. wyboru postaci
        // gameStateManager.changeState(new CharacterSelectionState(mWindow, gameStateManager));
    });

    // Dalsze callbacki dla innych przycisków...
}

void MenuState::handleInput(sf::RenderWindow& window) {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        for (auto& button : buttons) {
            button->handleInput(event, window);
        }
    }
}

void MenuState::update(sf::Time deltaTime) {
    // Tutaj możesz dodać logikę aktualizacji stanu menu
}

void MenuState::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(backgroundSprite); // Rysowanie tła

    for (const auto& button : buttons) {
        button->render(window); // Rysowanie przycisków
    }

    window.display();
}
