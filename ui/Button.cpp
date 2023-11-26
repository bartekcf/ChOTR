// Button.cpp

#include "Button.h"

Button::Button(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& buttonText)
{
    // Ustawienie tekstury i pozycji sprite'a
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(size.x / texture.getSize().x, size.y / texture.getSize().y);

    // Konfiguracja tekstu (możesz tutaj dodać więcej ustawień, jak czcionka, kolor itp.)
    text.setString(buttonText);
    text.setPosition(position);
    // text.setFont(...); // Ustaw czcionkę
    // text.setCharacterSize(...); // Ustaw rozmiar tekstu
}

void Button::handleInput(const sf::Event& event, const sf::RenderWindow& window)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left && isMouseOver(window))
        {
            if (callback) callback(); // Wywołanie funkcji callback, jeśli jest ustawiona
        }
    }
}

void Button::update(sf::Time deltaTime)
{
    // Tutaj możesz dodać logikę aktualizacji, na przykład zmianę wyglądu przycisku
}

void Button::render(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(text);
}

void Button::setCallback(const std::function<void()>& newCallback)
{
    callback = newCallback;
}

bool Button::isMouseOver(const sf::RenderWindow& window) const
{
    sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);
    return sprite.getGlobalBounds().contains(mousePos);
}
