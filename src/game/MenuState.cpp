#include "MenuState.h"
#include "NewGameState.h"
#include <filesystem>
#include <fmt/ranges.h>

MenuState::MenuState(sf::RenderWindow& window, GameStateManager& manager) : mWindow(window), gameStateManager(manager) {
//    std::cout << "Current path is_1 " << std::filesystem::current_path() << std::endl;

    if (!backgroundTexture.loadFromFile("../assets/images/background.png")) {
        return;
    }
    backgroundSprite.setTexture(backgroundTexture);

    initButtons();
}

MenuState::~MenuState() {
    // Tutaj możesz umieścić logikę czyszczenia, jeśli jest potrzebna
}


void MenuState::initButtons() {


    if (!buttonTexture.loadFromFile("../assets/images/img.png")) {
        return;
    }

    if (!font.loadFromFile("../assets/fonts/font.ttf")) {
        return;
    }

    buttons.push_back(std::make_unique<Button>(font, buttonTexture, sf::Vector2f(400, 280), sf::Vector2f(250, 150), "Nowa Gra"));
    buttons.push_back(std::make_unique<Button>(font, buttonTexture, sf::Vector2f(400, 380), sf::Vector2f(250, 150), "Wczytaj Gre"));
    buttons.push_back(std::make_unique<Button>(font, buttonTexture, sf::Vector2f(400, 480), sf::Vector2f(250, 150), "Opcje"));

    buttons[0]->setCallback([this]() {
          fmt::println("test");
//        gameStateManager.changeState(new NewGameState(mWindow, gameStateManager));
    });


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
