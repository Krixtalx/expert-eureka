/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pocion.h
 * Author: José Antonio
 *
 * Created on 6 de marzo de 2019, 13:27
 */

#ifndef POCION_H
#define POCION_H

#include <string>

class Pocion {
public:
    Pocion()=default;
    Pocion(std::string nombre, int vida, int mana, int npociones);
    Pocion(const Pocion& orig);
    virtual ~Pocion();
    int GetMana() const;
    int GetVida() const;
    std::string GetNombre() const;
    void SetNpociones(int npociones);
    int GetNpociones() const;
private:
    std::string nombre="Pocion de vida";
    int vida=50;
    int mana=0;
    int npociones=1;
    };

#endif /* POCION_H */

