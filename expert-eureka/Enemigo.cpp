/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemigo.cpp
 * Author: José Antonio
 * 
 * Created on 27 de febrero de 2019, 21:23
 */

#include "Enemigo.h"
#include "PersonajeVideojuego.h"

Enemigo::Enemigo(std::string nombre, int vida, int mana, int damageBasico) :
 nombre(nombre), vida(vida), mana(mana), damageBasico(damageBasico) {
}

Enemigo::Enemigo(const Enemigo& orig) {

    throw std::string("Enemigo::Enemigo, llamando al constructor de copia no implementado");

}

Enemigo::~Enemigo() {
}

int Enemigo::getMana() const {
    return mana;
}

int Enemigo::getVida() const {
    return vida;
}

int Enemigo::getDamage() const {
    return damageBasico;
}

/**
 * @brief Establece la posición del personaje. Se puede utilizar en cascada
 * @param[in] posX
 * @param[in] posY
 */
Enemigo& Enemigo::setPosicion(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;

    return *this;
}

void Enemigo::SetVida(int vida) {
    this->vida = vida;
}


/**
 * @brief Establece el nombre del personaje
 * @param[in] nombre, Nombre del personaje
 * @return Devuelve el objeto enemigo
 */
Enemigo& Enemigo::setNombre(std::string nombre) {

    if (nombre.length() == 0)
        throw std::string("Enemigo::setNombre, variable nombre vacía");

    this->nombre = nombre;
}

std::string Enemigo::getNombre() const {
    return nombre;
}



