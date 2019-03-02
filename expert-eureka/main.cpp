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
#include "Enemigo.h"
#include "PersonajeVideojuego.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Arma arma1;
    PersonajeVideojuego Goku("Goku", 1, 1, 100, 100, &arma1);
    Enemigo Freezer("Freezer", 100, 50, 6);

    cout << "       " << Goku.getNombre() << "\n\n";
    cout << "Salud: " << Goku.GetVidaAct() << "\n"
         << "Daño: " << Goku.GetDamage() << "\n";
    
    cout << "       " << Freezer.getNombre() << "\n\n";
    cout << "Salud: " << Freezer.getVida() << "\n"
         << "Daño: " << Freezer.getDamage() << "\n";
    
    Goku.ataqueBasico(Freezer);
    
    cout << Freezer.getNombre() << " ha perdido vida, ahora tiene: " << Freezer.getVida() << endl;
    
    Goku.hab2(Freezer);
            
    cout << Freezer.getNombre() << " ha perdido vida, ahora tiene: " << Freezer.getVida() << endl;
    
    //    Arma arma1;
    //    PersonajeVideojuego heroe(5,6,200,0, &arma1);
    //    Enemigo Limo(25,0,10);
    //    
    //    std::cout << "Nombre: " << arma1.getNombre() << endl;
    //    std::cout << "Daño: " << arma1.getDamage() << endl<<endl;
    //    
    //    std::cout << "posX: " << heroe.GetPosX() << endl;
    //    std::cout << "posY: " << heroe.GetPosY() << endl;
    //    std::cout << "Vida: " << heroe.GetVidaMax() << endl;
    //    std::cout << "Mana: " << heroe.GetManaMax() << endl;
    //    std::cout << "Damage: " << heroe.GetDamage() << endl<<endl;
    //    heroe.hab2(Limo);
    //    
    //    std::cout << "Vida: " << Limo.GetVida() << endl;
    //    std::cout << "Mana: " << Limo.GetMana() << endl;

    return 0;
}

