/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: José Antonio
 * 
 * Created on 1 de marzo de 2019, 23:42
 */

#include "FuncionesAuxiliares.h"
#include <cstdlib>
#include <iostream>
#include "PersonajeVideojuego.h"

using std::cout;
using std::endl;
using std::cin;

void ScreenClear() {
    bool windows = false;

    if (windows) {
        system("cls");
    } else {
        system("clear");
    }
}

void movimientoPersonaje(PersonajeVideojuego& heroe) {
    ScreenClear();
    cout << "Actualmente se encuentra en la posicion x: " << heroe.GetPosX() << "  y: " << heroe.GetPosY() << endl;
    cout << endl << "1. Hacia la derecha";
    cout << endl << "2. Hacia arriba";
    if (heroe.GetPosX() != 0)
        cout << endl << "3. Hacia la izquierda";
    if (heroe.GetPosY() != 0)
        cout << endl << "4. Hacia abajo";
    cout <<endl<< "Hacia donde desea moverse?: ";
    int aux;
    bool opcionincorrecta(true);
    
    while (opcionincorrecta) {
        cin >>aux;
        switch (aux) {
            case 1:
                heroe.movimiento(1, 0);
                opcionincorrecta = false;
                break;
            case 2:
                heroe.movimiento(0, 1);
                opcionincorrecta = false;
                break;
            case 3:
                heroe.movimiento(-1, 0);
                opcionincorrecta = false;
                break;
            case 4:
                heroe.movimiento(0, -1);
                opcionincorrecta = false;
                break;
            default:
                cout<<"Introduzca una opcion correcta: ";
                break;
        }
    }

}
