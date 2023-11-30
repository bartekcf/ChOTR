// MenuState.h
#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "../../ui/Button.h"

class MenuState {
public:
    MenuState(sf::RenderWindow& window);
    void handleInput();
    void update(sf::Time deltaTime);
    void render();

private:
    sf::RenderWindow& mWindow;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture; // Przeniesienie do składowych klasy
    std::vector<std::unique_ptr<Button>> buttons;
    sf::Texture buttonTexture;
    sf::Font font;

    void initButtons();
};

#endif // MENUSTATE_H
