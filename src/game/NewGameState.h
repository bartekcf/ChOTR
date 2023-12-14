#ifndef CHOTR_1_NEWGAMESTATE_H
#define CHOTR_1_NEWGAMESTATE_H

#include "GameState.h"
#include "GameStateManager.h"

class NewGameState : public GameState {
public:
    NewGameState(sf::RenderWindow& window, GameStateManager& manager);
    ~NewGameState() override;

    void handleInput(sf::RenderWindow& window) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& mWindow;
    GameStateManager& gameStateManager;

    // Tutaj możesz dodać inne zmienne członkowskie, takie jak tekstury, sprite'y, itp.
};

#endif //CHOTR_1_NEWGAMESTATE_H
