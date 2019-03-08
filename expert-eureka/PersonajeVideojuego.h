/* 
 * File:   PersonajeVideojuego.h
 * Author: José Antonio
 *
 * Created on 27 de febrero de 2019, 21:23
 */



#ifndef PERSONAJEVIDEOJUEGO_H
#define PERSONAJEVIDEOJUEGO_H

#include <string>

#include "Arma.h"
#include "Enemigo.h"
#include "Pocion.h"

class PersonajeVideojuego {
public:
    PersonajeVideojuego();
    PersonajeVideojuego(std::string nombre, int x, int y, int vida, int mana, Arma* Arma);
    PersonajeVideojuego(std::string nombre, int x, int y, int vida, int mana, Arma* Arma, Pocion pociones[]);
    PersonajeVideojuego(const PersonajeVideojuego& orig);
    virtual ~PersonajeVideojuego();

    void movimiento(int x, int y);
    void ataqueBasico(Enemigo& golpeado);
    void hab1(Enemigo& golpeado);
    void hab2(Enemigo& golpeado);
    void equiparArma(Arma* arma);
    void incrementarVida(int cantidad);
    void incrementarMana(int cantidad);
    void tomarPocion(int tipoPocion);


    int getConsumoHab2() const;
    int getConsumoHab1() const;
    int GetManaMax() const;
    int GetManaAct() const;
    int GetVidaMax() const;
    int GetVidaAct() const;
    int GetPosY() const;
    int GetPosX() const;
    int GetDamage()const;
    Pocion* getPocion() const;
    PersonajeVideojuego& setNombre(std::string nombre);
    std::string getNombre() const;
    void setVidaAct(int vidaAct);

private:

    std::string nombre = "Izuku";
    int posX = 0;
    int posY = 0;
    
    int vidaAct = 120;
    int vidaMax = 120;
    int manaAct = 50;
    int manaMax = 50;
    
    Arma* armaEquipada;
    float damageHab1 = 1.3;
    int consumoHab1 = 8;
    float damageHab2 = 1.6;
    int consumoHab2 = 16;
    Pocion* pociones;
    
    int nivel = 1;
    int experiencia=0;
    
    int vitalidad=12;
    int inteligencia=10;
    int fuerza=12;
};

#endif /* PERSONAJEVIDEOJUEGO_H */