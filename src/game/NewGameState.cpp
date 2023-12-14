#include "NewGameState.h"

NewGameState::NewGameState(sf::RenderWindow& window, GameStateManager& manager)
        : mWindow(window), gameStateManager(manager) {
    // Inicjalizacja stanu, ładowanie zasobów, ustawienia początkowe, itp.
}

NewGameState::~NewGameState() {
    // Czyszczenie zasobów, jeśli jest to konieczne
}

void NewGameState::handleInput(sf::RenderWindow& window) {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        // Obsługa innych zdarzeń wejściowych
    }
}

void NewGameState::update(sf::Time deltaTime) {
    // Logika aktualizacji stanu
}

void NewGameState::render(sf::RenderWindow& window) {
    window.clear();


    window.display();
}
