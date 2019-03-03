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

    try {
        
        Arma arma1;
        PersonajeVideojuego Goku("Goku", 1, 1, 100, 50, &arma1);
        PersonajeVideojuego* Trunks = new PersonajeVideojuego("Trunks", 1, 1, 100, 50, &arma1);
        PersonajeVideojuego Equipo[2] = { {"Vegeta", 1, 1, 100, 50, &arma1}, {"Son Goten", 1, 1, 100, 50, &arma1} };

        Enemigo Freezer("Freezer", 100, 50, 6);

        cout << Goku.getNombre() << " está siendo ayudado por: " << Trunks->getNombre() << ", " << Equipo[0].getNombre() << 
                " y " << Equipo[1].getNombre() << endl;

        cout << "El enemigo " << Freezer.getNombre() << " ha aparecido." << endl;

        cout << Goku.getNombre() << " se dispone a atacar." << endl;
        
        Goku.ataqueBasico(Freezer);
        
        cout << Freezer.getNombre() << " ha recibido daño, vida restante: " << Freezer.getVida() << endl;
        
        cout << Equipo[1].getNombre() << " se dispone a atacar." << endl;
        
        Equipo[1].hab1(Freezer);
        
        cout << Freezer.getNombre() << " ha sufrido un gran golpe, vida restante: " << Freezer.getVida() << endl;
        
        cout << Trunks->getNombre() << " se ha retirado del combate para ir al futuro" << endl;
                
        delete Trunks;
        
    }catch (std::string& error) {
        
        cerr << "Error: " + error;
        
    }
    
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

