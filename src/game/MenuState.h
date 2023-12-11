#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "GameState.h"
#include "GameStateManager.h"
#include "../../ui/Button.h"

class MenuState : public GameState {
private:
    sf::RenderWindow& mWindow;
    GameStateManager& gameStateManager;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Texture buttonTexture; // Dodane
    sf::Font font; // Dodane
    std::vector<std::unique_ptr<Button>> buttons;

    void initButtons();

public:
    MenuState(sf::RenderWindow& window, GameStateManager& manager);
    ~MenuState() override;

    void handleInput(sf::RenderWindow& window) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;
};

#endif // MENUSTATE_H
