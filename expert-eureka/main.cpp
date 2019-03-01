/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: José Antonio
 *
 * Created on 27 de febrero de 2019, 21:11
 */

#include <iostream>

#include "Arma.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Arma arma1;
    Arma arma2 = arma1;
    
    std::cout << "Nombre: " << arma1.getNombre() << endl;
    std::cout << "Daño: " << arma1.getDamage() << endl;
    
    arma1.setDamage(10);
    
    std::cout << "Nombre: " << arma2.getNombre() << endl;
    std::cout << "Daño: " << arma2.getDamage() << endl;
    
    
    
    return 0;
}

