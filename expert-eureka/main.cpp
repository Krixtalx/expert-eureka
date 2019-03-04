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
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    string nombre;
    Arma armaPorDefecto;
    Arma bastonMagico("Baston Magico", 12);
    Arma EspadaLegendaria("Excalibur", 25);
    Enemigo Limo("Limo", 100,0,5);

    cout << "Introduzca el nombre del Héroe: ";
    getline(cin>>ws, nombre);

    PersonajeVideojuego Heroe(nombre, 0, 0, 100, 50, &armaPorDefecto);

    bool fight = false;

    while (!fight) {

        movimientoPersonaje(Heroe);
        if (spawner()) {
            combate(Heroe, Limo);
        }
    }
    return 0;
}