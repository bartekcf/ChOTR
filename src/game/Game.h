// Game.h
//
// Created by Bartek Kedziora on 26.11.2023.
//

#ifndef CHOTR_1_GAME_H
#define CHOTR_1_GAME_H

#include <SFML/Graphics.hpp>
#include "MenuState.h"
#include "GameStateManager.h"


class Game {
public:
    Game(); // Konstruktor
    ~Game(); // Destruktor
    void run(); // Uruchomienie głównej pętli gry

private:
    void processEvents(); // Przetwarzanie zdarzeń wejściowych
    void update(sf::Time deltaTime); // Aktualizacja stanu gry
    void render(); // Renderowanie sceny gry

    sf::RenderWindow mWindow; // Okno gry
    bool mIsRunning; // Status działania gry
    GameStateManager gameStateManager; // Dodanie stanu gry


};

#endif //CHOTR_1_GAME_H
