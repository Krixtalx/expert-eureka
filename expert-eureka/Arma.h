/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arma.h
 * Author: david
 *
 * Created on 1 de marzo de 2019, 19:10
 */


#ifndef ARMA_H
#define ARMA_H

#include <string>

class Arma {
public:
    Arma() = default;
    Arma(std::string nombre, int damage);
    Arma(const Arma& orig);
    virtual ~Arma();

    int getDamage() const;
    std::string getNombre() const;
    Arma& setDamage(int damage);



private:

    std::string nombre = "La Infernus beibe";
    int damage = 6;

};

#endif /* ARMA_H */

