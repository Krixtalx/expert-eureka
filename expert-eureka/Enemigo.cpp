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

Enemigo::Enemigo(int vida, int mana, int damageBasico):
vida(vida), mana(mana), damageBasico(damageBasico) {
}

Enemigo::Enemigo(const Enemigo& orig) {
}

Enemigo::~Enemigo() {
}

int Enemigo::GetMana() const {
    return mana;
}

int Enemigo::GetVida() const {
    return vida;
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


