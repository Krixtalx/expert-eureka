/* 
 * File:   main.cpp
 * Author: José Antonio
 *
 * Created on 27 de febrero de 2019, 21:11
 */

#include <iostream>
#include <time.h>

#include "Arma.h"
#include "Enemigo.h"
#include "PersonajeVideojuego.h"
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    const int TAMARMAS = 5;

    int enemigosDerrotados = 0;
    
    string nombre;
    Arma armaPorDefecto;

    Arma armas[TAMARMAS] = { {"Espada de madera", 6}, {"Espada de metal", 7}, 
    {"Bastón de caramelo", 3}, {"Absorbe espíritus", 8}, {"Varita de Sauco", 8} };
    
//    Arma bastonMagico("Baston Magico", 12);
//    Arma EspadaLegendaria("Excalibur", 25);
    Enemigo Limo("Limo", 100, 4);

    cout << "Introduzca el nombre del Héroe: ";
    getline(cin>>ws, nombre);

    PersonajeVideojuego Heroe(nombre, 0, 0, 100, 50, &armas[0]);

    bool fight = false;

    while (!fight && Heroe.GetVidaAct() > 0) {

        movimientoPersonaje(Heroe, enemigosDerrotados, armas, TAMARMAS);
        if (spawner()) {
            combate(Heroe, Limo, enemigosDerrotados);
        }
    }
    
    cout << "El juego ha terminado! :D" << endl;
    
    return 0;
}