// Button.h
#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>

class Button {
public:
    // Konstruktor przycisku z parametrami dla tekstury, pozycji, rozmiaru i tekstu
    Button(const sf::Font& font, const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& text);

    // Obsługa zdarzeń wejściowych
    void handleInput(const sf::Event& event, const sf::RenderWindow& window);

    // Aktualizacja stanu przycisku
    void update(sf::Time deltaTime);

    // Rysowanie przycisku na ekranie
    void render(sf::RenderWindow& window);

    // Ustawienie funkcji callback, która zostanie wywołana po kliknięciu przycisku
    void setCallback(const std::function<void()>& callback);

private:
    sf::Sprite sprite;      // Grafika przycisku
    sf::Text text;          // Tekst na przycisku
    std::function<void()> callback; // Funkcja callback wywoływana po naciśnięciu przycisku

    // Metody pomocnicze
    bool isMouseOver(const sf::RenderWindow& window) const; // Sprawdza, czy myszka jest nad przyciskiem
};

#endif // BUTTON_H
