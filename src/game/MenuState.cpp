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
    // Możesz tu także dodać animacje lub inne efekty
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
