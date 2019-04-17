#include <SFML/Graphics.hpp>
#include <iostream>
#include "Jugador.h"
#include "Enemigo.h"
#include "Arma.h"
#include "Hud.h"
#include "Mapa.h"
#include "Consumible.h"

using namespace sf;

class Juego
{
    public:
        static Juego* Instance();
        Juego();
        void cargaPlayer();
        void cargaMapa();
        void cargarHUD();
        void gameLoop();

        void procesarEventos();
        void setView();
        void render();
        void changeMode();

        Vector2f generaPosicion();

        Vector2i dimensiones;
    private:
        static Juego* pinstance;

        void manejarIA();

        RenderWindow *window;
        RenderStates *states;
        Clock frameClock;
        Jugador *jugador;
        std::vector<Enemigo*> enemigos;
        Event *evento;
        Mapa *mapa;
        Hud *hud;
        Consumible *pocion;
        View view;

        bool centrado, godMode;
        float delta;
        int nEnemigos;
};
