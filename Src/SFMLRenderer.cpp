#include "SFMLRenderer.h"

static const float SCALE = 30.f; // Factor de conversi�n metros -> p�xeles

void SFMLRenderer::run(b2World* world, b2Body* square) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cuadrado Controlado por el Usuario");

    // Representaci�n gr�fica del cuadrado
    sf::RectangleShape squareVisual(sf::Vector2f(30.f, 30.f)); // 30 p�xeles = 1 metro
    squareVisual.setFillColor(sf::Color::Red);
    squareVisual.setOrigin(15.f, 15.f); // Origen en el centro del cuadrado

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Captura de input del usuario para mover el cuadrado
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            square->ApplyForceToCenter(b2Vec2(0.f, -10.f), true); // Fuerza hacia arriba
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            square->ApplyForceToCenter(b2Vec2(0.f, 10.f), true); // Fuerza hacia abajo
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            square->ApplyForceToCenter(b2Vec2(-10.f, 0.f), true); // Fuerza hacia la izquierda
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            square->ApplyForceToCenter(b2Vec2(10.f, 0.f), true); // Fuerza hacia la derecha
        }

        // Actualizamos la simulaci�n f�sica
        float deltaTime = clock.restart().asSeconds();
        world->Step(deltaTime, 8, 3);

        // Sincronizar la posici�n visual del cuadrado con el mundo f�sico
        squareVisual.setPosition(square->GetPosition().x * SCALE, square->GetPosition().y * SCALE);

        // Renderizar la escena
        window.clear();
        window.draw(squareVisual);
        window.display();
    }
}
