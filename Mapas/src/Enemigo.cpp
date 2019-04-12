#include "../include/Enemigo.h"

Enemigo::Enemigo(Vector2f pos){
    entityCenter = pos;
    entidadHitbox.setPosition(pos);
    setColisionadores();

    dirMov = 1.f;
    movement = Vector2f(0.f, 0.f);

    idle.setAnimacion("sprites/elfa.png", IntRect(0, 0, 16, 28), IntRect(48, 0, 16, 28), 16, 0.1f);
    idle.sprite.setOrigin(9,20);
    run.setAnimacion("sprites/elfa.png", IntRect(0, 28, 16, 28), IntRect(48, 28, 16, 28), 16, 0.1f);
    run.sprite.setOrigin(9,20);

    actual = &idle;
    actual->sprite.setPosition(pos);

    ataqueHitbox.setOutlineThickness(1);
    ataqueHitbox.setOutlineColor(Color::Blue);
    ataqueHitbox.setFillColor(Color::Transparent);
    ataqueHitbox.setSize(Vector2f(20.f, 12.f));
    ataqueHitbox.setOrigin(0,6.f);
    ataqueHitbox.setPosition(pos);
}

void Enemigo::setPath(std::vector<Posicion> p){
    path = p;
}

void Enemigo::update(float delta, RenderWindow& window, int nCol, FloatRect* colisiones, Posicion pos_a){
    entityCenter = Vector2f(entidadHitbox.getPosition().x, entidadHitbox.getPosition().y);

    // MOVIMIENTO
    seguirCamino(pos_a); // comprobar que el jugador se mueve
    entidadHitbox.move(movement * delta); // mover al jugador.
    ataqueHitbox.move(movement * delta);
    moverColisionadores(movement * delta);
    procesarColisiones(nCol, colisiones);

    actual->update(delta, movement);
}

void Enemigo::seguirCamino(Posicion a){
    //aqui el enemigo sigue el camino
    movement = Vector2f(0.f, 0.f);
    Posicion s = path.at(0);

    if (a.getY() < s.getY()){    // ARRIBA
        movement.y -= speed;
        if (actual != &run){
            cout << "CAMBIAMOS A RUN" << endl;
            actual = &run;
            actual->sprite.setPosition(entityCenter);
        }
    }

    if (a.getY() > s.getY()){   // ABAJO
        movement.y += speed;

        if (actual != &run){
            cout << "CAMBIAMOS A RUN" << endl;
            actual = &run;
            actual->sprite.setPosition(entityCenter);
        }
    }

    if(a.getX() < s.getX()){   // IZQUIERDA
        dirMov = -1.f;
        movement.x -= speed;

        if (actual != &run){
            cout << "CAMBIAMOS A RUN" << endl;
            actual = &run;
            actual->sprite.setPosition(entityCenter);
        }
        actual->sprite.setScale(1.f*dirMov, 1.f);
    }

    if (a.getX() > s.getX()){    // DERECHA
        dirMov = 1.f;
        movement.x += speed;

        if (actual != &run){
            cout << "CAMBIAMOS A RUN" << endl;
            actual = &run;
            actual->sprite.setPosition(entityCenter);
        }
        actual->sprite.setScale(1.f*dirMov, 1.f);
    }

    if(movement.x == 0 & movement.y == 0) {
        if (actual != &idle){
            cout << "CAMBIAMOS A IDLE" << endl;
            actual = &idle;
            actual->sprite.setPosition(entityCenter);
            actual->sprite.setScale(1.f*dirMov, 1.f);
        }
    }

    colisiona_abajo = false;
    colisiona_arriba = false;
    colisiona_derecha = false;
    colisiona_izquierda = false;
}
