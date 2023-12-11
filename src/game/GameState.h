//
// Created by keked on 11.12.2023.
//

#ifndef CHOTR_1_GAMESTATE_H
#define CHOTR_1_GAMESTATE_H


#include <SFML/Graphics.hpp>

class GameState {
public:
    virtual ~GameState() = default; // Wirtualny destruktor

    virtual void handleInput(sf::RenderWindow& window) = 0; // Obsługa zdarzeń wejściowych
    virtual void update(sf::Time deltaTime) = 0; // Aktualizacja stanu
    virtual void render(sf::RenderWindow& window) = 0; // Renderowanie stanu
};

#endif //CHOTR_1_GAMESTATE_H
