#include <DonkeyKong.hpp>
#include <MarioB.hpp>
#include <Mapa.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

double velocidad = 0.1;
int main()
{
    int posicion;
    DonkeyKong donkey(sf::Vector2f(50, 103), sf::Color::Black);
    MarioB mario(sf::Vector2f(3, 445), sf::Color::Red);
    Mapa map(sf::Vector2f(50, 103), sf::Color::Red);
    sf::Texture texture;
    if (!texture.loadFromFile("./assets/images/mapad.png"))
    {
        // Manejar el error si no se puede cargar la imagen
        return -1;
    }
    // Crear un sprite y asignarle la textura
    sf::Sprite sprite(texture);

    sf::Music music;
    if (!music.openFromFile("./assets/music/theme.ogg"))
    {
        // Error al cargar el archivo de música
        return -1;
    }

    // Reproducir la música
    music.play();

    //  sf::Font font2;
    //  if (!font2.loadFromFile("./assets/fonts/Jumpman.ttf"))
    //  {
    // Manejar el error si no se puede cargar la fuente
    //      return -1;
    //  }
    // Crear un objeto de texto LOTR
    // sf::Text text2;
    // text2.setFont(font2);
    //  text2.setString("D");
    //  text2.setCharacterSize(30);
    //  text2.setPosition(50, 50);

    sf::RenderWindow window(sf::VideoMode(500, 512), "DONKEY KONG ARCADE");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            donkey.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            donkey.move(velocidad, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            mario.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            mario.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            mario.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            // mario.move(0, velocidad);
            //  if (mario.move(280,480)==)
            // {
            mario.move(0, velocidad);
            //  }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            map.move(0, velocidad);
        }
        // Actualizar animacion pikachu
        donkey.update();
        mario.update();
        map.update();

        window.clear();
        window.draw(sprite);
        donkey.draw(window);
        mario.draw(window);
        map.draw(window);
        // window.draw(text2);
        window.display();

        if (music.getStatus() != sf::Music::Playing)
        {
            window.close();
        }
    }

    return 0;
}