#ifndef GAME_H
#define GAME_H

#include "SFMLRenderer.h"

class Game {
private:
    b2World* world;           // Mundo f�sico de Box2D
    SFMLRenderer renderer;    // Renderizador
    b2Body* square;           // Cuadrado controlado por el usuario

public:
    Game();  // Constructor
    ~Game(); // Destructor
    void start(); // Inicia la simulaci�n y el renderizado
};

#endif // GAME_H
