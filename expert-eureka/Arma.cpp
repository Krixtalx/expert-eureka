/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arma.cpp
 * Author: david
 * 
 * Created on 1 de marzo de 2019, 19:10
 */


#include <iostream>
#include "Arma.h"

Arma::Arma(std::string nombre, int damage) :
nombre(nombre), damage(damage) {

}

Arma::Arma(const Arma& orig) {

    throw std::string("Arma::Arma, llamando al constructor de copia no implementado");

}

Arma::~Arma() {
}

int Arma::getDamage() const {
    return damage;
}

std::string Arma::getNombre() const {
    return nombre;
}

/**
 * @brief Establecer el daño del arma. Se puede usar en cascada.
 * @param[in] damage
 * @return Devuelve el objeto.
 */
Arma& Arma::setDamage(int damage) {

    if (damage <= 0)
        throw std::string("Arma::setDamage, variable damage <= 0");

    this->damage = damage;
    return *this;
}

