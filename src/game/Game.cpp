#include "Game.h"
#include "MenuState.h" // Upewnij się, że masz taki plik i klasę

Game::Game() : mWindow(sf::VideoMode(1000, 800), "Chronicles Of The Ringmasters"), mIsRunning(true) {
    sf::Image cursorImage;
    if (cursorImage.loadFromFile("../assets/images/cursor.png")) {
        sf::Cursor cursor;
        if (cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), sf::Vector2u(0, 0))) {
            mWindow.setMouseCursor(cursor);
        }
    }
    gameStateManager.addState(new MenuState(mWindow, gameStateManager));
}

Game::~Game() {
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

        gameStateManager.getCurrentState()->handleInput(mWindow);
    }
}

void Game::update(sf::Time deltaTime) {
    gameStateManager.getCurrentState()->update(deltaTime); // Aktualizacja bieżącego stanu
}

void Game::render() {
    mWindow.clear();
    gameStateManager.getCurrentState()->render(mWindow);
}
