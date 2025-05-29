#include "Game.h"

Game::Game() {
    // Crear el mundo físico sin gravedad (permitirá movimiento libre en cualquier dirección)
    b2Vec2 gravity(0.f, 0.f);
    world = new b2World(gravity);

    // Crear el cuadrado dinámico
    b2BodyDef squareDef;
    squareDef.type = b2_dynamicBody;      // El cuadrado es dinámico (puede moverse)
    squareDef.position.Set(10.f, 10.f);  // Posición inicial en metros
    square = world->CreateBody(&squareDef);

    // Definir la forma del cuadrado
    b2PolygonShape squareShape;
    squareShape.SetAsBox(0.5f, 0.5f);  // Cuadrado de 1x1 metros (0.5 en cada dirección)

    // Crear las propiedades físicas (fixture) del cuadrado
    b2FixtureDef squareFixture;
    squareFixture.shape = &squareShape;
    squareFixture.density = 1.f;      // Densidad para que responda a fuerzas
    squareFixture.friction = 0.3f;   // Fricción
    square->CreateFixture(&squareFixture);
}

Game::~Game() {
    delete world; // Limpiamos el mundo físico al finalizar
}

void Game::start() {
    renderer.run(world, square); // Inicia el renderizado y la simulación física
}
