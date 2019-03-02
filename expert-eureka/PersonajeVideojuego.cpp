/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PersonajeVideojuego.cpp
 * Author: José Antonio
 * 
 * Created on 27 de febrero de 2019, 21:23
 */

#include "PersonajeVideojuego.h"
#include "Arma.h"
#include "Enemigo.h"
#include <string>

/**
 * @Brief Constructor por defecto de la clase PersonajeVideojuego
 */
PersonajeVideojuego::PersonajeVideojuego() :
posX(0), posY(0), vidaMax(100), manaMax(50) {

}

/**
 * @Brief Constructor parametrizado de la clase PersonajeVideojuego
 * @param x: Posicion x donde inicializar el objeto
 * @param y: Posicion y donde inicializar el objeto
 * @param vida: Vida con la que inicializar el objeto
 * @param mana: Mana con el que inicializar el objeto
 * @param Arma: Puntero a un objeto de la clase Arma (Arma.h) 
 */
PersonajeVideojuego::PersonajeVideojuego(std::string nombre, int x, int y, int vida, int mana, Arma* Arma) :
nombre(nombre), posX(x), posY(y), vidaMax(vida), manaMax(mana), armaEquipada(Arma) {

}

int PersonajeVideojuego::GetDamage() const {
    return this->armaEquipada->getDamage();
}

PersonajeVideojuego& PersonajeVideojuego::setNombre(std::string nombre) {

    if (nombre.length() == 0)
        throw std::string("PersonajeVideojuego::setNombre, variable nombre vacía");

    this->nombre = nombre;
}

std::string PersonajeVideojuego::getNombre() const {
    return nombre;
}

void PersonajeVideojuego::ataqueBasico(Enemigo& golpeado) {
    golpeado.SetVida(golpeado.getVida() - this->GetDamage());
}

void PersonajeVideojuego::hab1(Enemigo& golpeado) {
    if (manaAct >= consumoHab1) {
        golpeado.SetVida(golpeado.getVida() - this->GetDamage() * this->damageHab1);
        manaAct -= consumoHab1;
    }
}

void PersonajeVideojuego::hab2(Enemigo& golpeado) {
    if (manaAct >= consumoHab2) {
        golpeado.SetVida(golpeado.getVida() - this->GetDamage() * this->damageHab2);
        manaAct -= consumoHab2;
    }
}

PersonajeVideojuego::PersonajeVideojuego(const PersonajeVideojuego& orig) {
    throw std::string("Error en constructor de copia de PersonajeVideojuego: No implementado");
}

PersonajeVideojuego::~PersonajeVideojuego() {
}

int PersonajeVideojuego::GetManaMax() const {
    return manaMax;
}

int PersonajeVideojuego::GetManaAct() const {
    return manaAct;
}

int PersonajeVideojuego::GetVidaMax() const {
    return vidaMax;
}

int PersonajeVideojuego::GetVidaAct() const {
    return vidaAct;
}

int PersonajeVideojuego::GetPosY() const {
    return posY;
}

int PersonajeVideojuego::GetPosX() const {
    return posX;
}
