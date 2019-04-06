#ifndef ASTAR_H
#define ASTAR_H
#include <vector>
#include <string>
#include "Mapa.h"
#include "Posicion.h"

//TODO: convertir Posicion en clase
/*typedef struct Padre
{
    int x, y;
    int g, h, f;
    std::string tag;
};

typedef struct Posicion
{
    int x, y;
    int g, h, f;
    std::string tag;
    Padre padre;
};
*/

typedef struct comprobarListaAb
{
    bool status;
    int indice;
};

class Astar
{
    public:
        Astar(Posicion i, Posicion f, Mapa *m);
        virtual ~Astar();
        std::vector<Posicion> mapear();
        int obtenerMenorF();
        void removerLista(int indicePadre);
        bool finalizarLogica(std::vector<Posicion> &listaCerr);
        bool comprobarListaCerrada(Posicion caja, std::vector<Posicion> &listaCerr);
        comprobarListaAb comprobarListaAbierta(Posicion caja, std::vector<Posicion> &listaAbi);
        int G(Posicion player, int valor);
        int heuristica(Posicion inicio);
        //TODO::-------------------------------------------------------------
        std::vector<Posicion> comprobarVecinos(Posicion padre, Mapa mapa);
        //-------------------------------------------------------------------

    protected:

    private:
        std::vector<Posicion> *listaAbierta, *listaCerrada;
        bool **mapaArr;
        std::vector<Posicion> *vecinos;
        Posicion *ini;
        Posicion *fin;
};

#endif // ASTAR_H
