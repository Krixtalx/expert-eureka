/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pocion.cpp
 * Author: José Antonio
 * 
 * Created on 6 de marzo de 2019, 13:27
 */

#include "Pocion.h"

Pocion::Pocion(std::string nombre, int vida, int mana, int npociones):
nombre(nombre), vida(vida), mana(mana), npociones(npociones){
}


Pocion::Pocion(const Pocion& orig) {
    throw std::string ("Constructor de copia de Pocion: No implementado");
}

Pocion::~Pocion() {
}

int Pocion::GetMana() const {
    return mana;
}

int Pocion::GetVida() const {
    return vida;
}

std::string Pocion::GetNombre() const {
    return nombre;
}

void Pocion::SetNpociones(int npociones) {
    this->npociones = npociones;
}

int Pocion::GetNpociones() const {
    return npociones;
}

