#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class MarioB
{
public:
    MarioB(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(0, 0));
        shape.setPosition(position); // Posición inicial cuadro
        shape.setFillColor(color);
        if (!texture.loadFromFile("assets/images/mario3.png"))
        {
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position);
    }
    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
    }
    void draw(sf::RenderWindow &window)
    {
        window.draw(this->sprite);
    }
    void update()
    {
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 6), 0, 35, 32));
            clock.restart();
        }
    }

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.5f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 3; // Número total de frames en la animación
    int frameWidth = 35;
    int frameHeight = 32;
};
