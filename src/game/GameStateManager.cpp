#include "GameStateManager.h"
#include <cassert>

GameStateManager::GameStateManager() {
    // Konstruktor
}

GameStateManager::~GameStateManager() {
    // Usuń wszystkie stany przy zniszczeniu managera
    while (!states.empty()) {
        delete states.top();
        states.pop();
    }
}

void GameStateManager::addState(GameState* state) {
    states.push(state);
}

void GameStateManager::removeState() {
    if (!states.empty()) {
        delete states.top(); // Usuń obiekt stanu z pamięci
        states.pop(); // Usuń wskaźnik ze stosu
    }
}

void GameStateManager::changeState(GameState* state) {
    removeState();
    addState(state);
}

GameState* GameStateManager::getCurrentState() const {
    assert(!states.empty()); // Upewnij się, że stos nie jest pusty
    return states.top();
}
