#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class Mapa
{
public:
    Mapa(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(0, 0));
        shape.setPosition(position); // Posición inicial cuadro
        shape.setFillColor(color);

        // Cargar la imagen desde un archivo

        if (!texture.loadFromFile("assets/images/barril.png"))
        {
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
    }

    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow &window)
    {
        // window.draw(this->shape);
        window.draw(this->sprite);
    }

    void update()
    {
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 2), 0, 8, 12));
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
    int numFrames = 2; // Número total de frames en la animación
    int frameWidth = 8;
    int frameHeight = 12;
};
