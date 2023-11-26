// Game.cpp

//
// Created by Bartek Kedziora on 26.11.2023.
//


#include "Game.h"

Game::Game() : mWindow(sf::VideoMode(1000, 800), "Chronicles Of The Ringmasters"), mIsRunning(true), menuState(mWindow) {
    // Inicjalizacja zasobów gry
}
Game::~Game() {
    // Zwalnianie zasobów
}

void Game::run() {
    sf::Clock clock;
    while (mIsRunning && mWindow.isOpen()) {
        processEvents();
        update(clock.restart());
        render();
    }
}

void Game::processEvents() {
    sf::Event event{};
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }
        menuState.handleInput(); // Dodaj obsługę zdarzeń dla menu
    }
}

void Game::update(sf::Time deltaTime) {
    menuState.update(deltaTime); // Aktualizacja stanu menu
}

void Game::render() {
    mWindow.clear();
    menuState.render(); // Renderowanie stanu menu
//    mWindow.display(); // to narazie mi mryga ekran mocno
}
