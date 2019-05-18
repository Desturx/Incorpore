
#include <SFML/Graphics.hpp>
#include <vector>


using namespace std;
using namespace sf;

class Hud{
public:
    Hud(int vidas);
    ~Hud();

    void compruebaTeclas();
    void modificar_vida(int,int);
    void setHabilidad(int);
    void borradoHabilidades();

    void setPosicionVida(int, int);
    void setPosicionSwitch(int, int);
    void setPosicionHabilidades(int, int);
    void cambiaArma(int);

    Sprite getCorazon();
    Text getTextoVida();
    Sprite getPiezaVida();
    Sprite getPiezaHabilidades();
    vector<Sprite> getArrayVida();
    vector<Sprite> getArrayHabilidades();
    int getCantidadVida();
    int getCantidadHabilidades();

    void draw(RenderWindow&);
    void move(Vector2f);
private:
    Text *texto_vida;
//    Text *tecla_switch;
//    Text *tecla_esquivar;
    Texture* teclaEsquivar;
    Texture* teclaSwitch;

    Font *fuente;
    Sprite* pieza_habilidades;
    Texture* habilidades;
    Texture* baston;
    Texture* espada;
    Texture* textureSwitch;
    Texture* textureEsquivar;
    Sprite * pieza_vida;
    Texture* vida;
    //RectangleShape * pieza_habilidades;
    Sprite* tecla_esquivar;
    Sprite* tecla_switch;

    Texture *textura_vida;
    Sprite *corazon;
    Texture *textura_habilidades;
    Sprite *mejora_escudo;
    Sprite *mejora_ataque;
    Sprite *rompe_escudos;
    Sprite *mana;
    Sprite *mejora_cofre;
    Sprite *espada_magica;
    Sprite *sprite_switch;
    Sprite *sprite_esquivar;
    Sprite *arma;
    bool mejora_escudo_esta = false;
    bool mejora_ataque_esta = false;
    bool rompe_escudos_esta = false;
    bool mana_esta = false;
    bool mejora_cofre_esta = false;
    bool espada_magica_esta = false;

    int xVida, yVida, xHab, yHab;

    vector<Sprite> *cantidad_corazones;
    vector<Sprite> *vector_habilidades;

};
