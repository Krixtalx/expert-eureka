/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

class PersonajeVideojuego {
public:
    PersonajeVideojuego();
    PersonajeVideojuego(std::string nombre, int x, int y, int vida, int mana, Arma* Arma);
    PersonajeVideojuego(const PersonajeVideojuego& orig);
    virtual ~PersonajeVideojuego();

    void movimiento(int x, int y);
    void ataqueBasico(Enemigo& golpeado);
    void hab1(Enemigo& golpeado);
    void hab2(Enemigo& golpeado);
    void equiparArma(Arma* arma);
    void incrementarVida(int cantidad);
    void incrementarMana(int cantidad);


    int getConsumoHab2() const;
    int getConsumoHab1() const;
    int GetManaMax() const;
    int GetManaAct() const;
    int GetVidaMax() const;
    int GetVidaAct() const;
    int GetPosY() const;
    int GetPosX() const;
    int GetDamage()const;
    PersonajeVideojuego& setNombre(std::string nombre);
    std::string getNombre() const;
    void setVidaAct(int vidaAct);

private:

    std::string nombre = "Izuku";
    int posX = 0;
    int posY = 0;
    int vidaAct = 100;
    int vidaMax = 100;
    int manaAct = 50;
    int manaMax = 50;
    Arma* armaEquipada;
    float damageHab1 = 1.2;
    int consumoHab1 = 10;
    float damageHab2 = 1.5;
    int consumoHab2 = 20;
};

#endif /* PERSONAJEVIDEOJUEGO_H */

