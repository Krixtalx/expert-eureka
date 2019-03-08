/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: José Antonio
 * 
 * Created on 1 de marzo de 2019, 23:42
 */

#include "FuncionesAuxiliares.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include "PersonajeVideojuego.h"
#include "Enemigo.h"
#include "Pocion.h"

using std::cout;
using std::endl;
using std::cin;

/**
 * @brief Función encargada de limpiar la consola
 */
void ScreenClear() {
    bool windows = false;

    if (windows) {
        system("cls");
    } else {
        system("clear");
    }
}



//--------------------Aleatoriedad--------------------------------------------------------


/**
 * @brief Funcion encargada de decidir aleatoriamente si se genera un enemigo o no.
 * @return True si se genera, false si no
 */
bool  spawner(){
    
    //inicializarSemillaRandom();
    
    int aux=rand()%100;
    
    if(aux<45)
        return true;
    return false;
}

/**
 * 
 * @param[in] tamArmas, Tamaño del vector de la clase Arma
 * @return Devuelve la posición del arma elegida
 */
int armaAleatoria(int tamArmas) {
    
    return rand() % tamArmas;
    
}

/**
 * 
 * @param[in] tamEnemigos, Tamaño del vector de la clase Enemigo
 * @return Devuelve la posición del enemigo elegido
 */
int enemigoAleatorio(int tamEnemigos) {
    
    return rand() % tamEnemigos;
    
}



//-------------------------------COMBATE-------------------------------------------------------------------------


/**
 * @brief Funcion encargada del daño del Enemigo al PersonajeVideojuego
 * @param heroe: PersonajeVideojuego que recibirá el daño
 * @param malo: Enemigo que hará el daño
 */
void ataqueMalo(PersonajeVideojuego& heroe, Enemigo& malo){
    heroe.setVidaAct(heroe.GetVidaAct() - malo.getDamage());
}

/**
 * @brief Función encargada de mostrar la vida del enemigo
 * @param malo: Enemigo del que se mostrará la vida
 */
void mostrarVidaEnemigo(Enemigo& malo){
    cout << endl << "Vida " << malo.getNombre() << ": " << malo.getVida();
}

/**
 * @brief Función encargada de mostrar la vida y maná actual del personaje
 * @param heroe:
 */
void mostrarAtribHeroe(PersonajeVideojuego& heroe){
    cout<<endl<< "Vida de "<<heroe.getNombre()<<": "<<heroe.GetVidaAct();
    cout<<"        "<< "Mana de "<<heroe.getNombre()<<": "<<heroe.GetManaAct();
}

/**
 * @brief Función encargada de iniciar el combate 
 * @param heroe: PersonajeVideojuego con el que se interaccionará
 * @param malo: Enemigo con el que se interaccionará
 */
void combate(PersonajeVideojuego& heroe, Enemigo malo, int& enemigosDerrotados){
    ScreenClear();
    
    int opcionMenu = 0, probHuir = 0, probMinima = 65; //Cambiar la ult variable para cambiar la probabilidad de huir
    bool terminar = false, mana = true, noAtacar = false;
    
    cout <<malo.getNombre()<<" apareció en combate"<<endl;
    while (!terminar) {
        
        mostrarVidaEnemigo(malo);
        mostrarAtribHeroe(heroe);
        cout << "       Numero de pociones: " << heroe.getPocion()->GetNpociones();
        cout <<endl<<"1. Ataque básico";
        cout <<endl<<"2. Habilidad 1";
        cout <<endl<<"3. Habilidad 2";
        cout<<endl<<"4. Tomar pocion";
        cout <<endl<<"5. Huir del combate";
        cout <<endl<<"Que desea hacer?: ";
        cin >> opcionMenu;
        
        cout << "\n";
        
        if (heroe.GetManaAct() <= heroe.getConsumoHab1() && opcionMenu == 2) {
            ScreenClear();
            cout << "No tienes suficiente maná para usar esta habilidad" << endl;
            mana = false;
        
        }else if (heroe.GetManaAct() <= heroe.getConsumoHab2() && opcionMenu == 3) {
            ScreenClear();
            cout << "No tienes suficiente maná para usar esta habilidad" << endl;
            mana = false;
            
        }
        
        if (mana) {
            
            switch (opcionMenu) {

                case 1:
                    heroe.ataqueBasico(malo);
                    finCombate(heroe, malo, terminar, enemigosDerrotados);
                    ScreenClear();
                    cout << malo.getNombre() << " ha recibido un ataque básico" << endl;
                    break;

                case 2:
                    heroe.hab1(malo);
                    finCombate(heroe, malo, terminar, enemigosDerrotados);
                    ScreenClear();
                    cout << malo.getNombre() << " ha recibido daño de habilidad 1" << endl;
                    break;

                case 3:
                    heroe.hab2(malo);
                    finCombate(heroe, malo, terminar, enemigosDerrotados);
                    ScreenClear();
                    cout << malo.getNombre() << " ha recibido daño de habilidad 2" << endl;
                    break;
                    
                case 4:
                    ScreenClear();
                    heroe.tomarPocion(0);
                    break;
                    
                case 5:
                    //srand(time(NULL));
                    probHuir = rand() % 100;
                    ScreenClear();
                                        
                    if (probHuir >= probMinima) {
                        terminar = true;
                        cout << "Has logrado huir del combate" << endl;
                    }else {
                        cout << "Intento de huida fallido" << endl;
                    }
                    
                    break;
                    
                case 8085: //Shhhh... Esto es secreto :)
                    ScreenClear();
                    heroe.incrementarMana(50);
                    noAtacar = true;
                    break;
                    
                case 69: //Shhhh... Esto es secreto ;)
                    ScreenClear();
                    heroe.setVidaAct(100);
                    noAtacar = true;
                    break;
                    
                case 8086:
                    terminar=true;
                    break;
                    
                default:
                    cout << "Opción errónea, vuelva a introducir una" << endl;
                    break;
            }
        }
        
        if (!terminar && !noAtacar) {
            ataqueMalo(heroe, malo);
            cout << malo.getNombre() << " ha atacado a " << heroe.getNombre() << endl;
            finCombate(heroe, malo, terminar, enemigosDerrotados);
        }
        
        noAtacar = false;
        mana = true;       
    }
}

/**
 * @brief Función que determina si el combate ha finalizado o no
 * @param heroe: PersonajeVideojuego que está en combate
 * @param malo:Enemigo que está en combate
 * @param terminar: Bool donde se almacenará el resultado
 * @param enemigosDerrotados: int que se sumará 1 si el enemigo ha sido derrotado
 */
void finCombate(PersonajeVideojuego& heroe, Enemigo& malo, bool& terminar, int& enemigosDerrotados) {
    
        if(malo.getVida() <= 0) {

            malo.SetVida(0);
            terminar = true;
            cout <<heroe.getNombre()<<" ha vencido!" << endl;
            enemigosDerrotados++;
            
        }else if (heroe.GetVidaAct() <= 0) {
            
            heroe.setVidaAct(0);
            terminar = true;
            cout <<malo.getNombre() <<" ha vencido!" << endl;
            
        }
}




//------------------------Movimiento------------------------------------------


/**
 * @brief Función encargada del menu de movimiento de personaje
 * @param heroe:PersonajeVideojuego con el que se interaccionará
 * @param enemigosDerrotados, muestra la cantidad de enemigos derrotados
 * @param armas[] Vector de armas
 * @param tamArmas, Tamaño del vector armas
 */
void movimientoPersonaje(PersonajeVideojuego& heroe, int& enemigosDerrotados, Arma armas[], int tamArmas) {
    ScreenClear();
    
    int probEncontrarArma = 0, probMinima = 80; //Editar la ult variable para cambiar la probabilidad (Rango entre 0 y 10);
    
    cout << "Actualmente se encuentra en la posicion x: " << heroe.GetPosX() << "  y: " << heroe.GetPosY()
         << "       Enemigos derrotados: " << enemigosDerrotados << endl;
    cout << endl << "1. Hacia la derecha";
    cout << endl << "2. Hacia arriba";
    if (heroe.GetPosX() > 0)
        cout << endl << "3. Hacia la izquierda";
    if (heroe.GetPosY() > 0)
        cout << endl << "4. Hacia abajo";
    cout <<endl<< "Hacia donde desea moverse?: ";
    int aux;
    bool opcionincorrecta(true);
    
    while (opcionincorrecta) {
        cin >>aux;
        switch (aux) {
            case 1:
                //inicializarSemillaRandom();
                probEncontrarArma = rand() % 100;
                if(probEncontrarArma > probMinima)
                    armaEncontrada(heroe, armas, tamArmas);
                heroe.movimiento(1, 0);
                opcionincorrecta = false;
                break;
                
            case 2:
                //inicializarSemillaRandom();
                probEncontrarArma = rand() % 100;
                if(probEncontrarArma > probMinima)
                    armaEncontrada(heroe, armas, tamArmas);
                heroe.movimiento(0, 1);
                opcionincorrecta = false;
                break;
                
            case 3:
                //inicializarSemillaRandom();
                probEncontrarArma = rand() % 100;
                if(probEncontrarArma > probMinima)
                    armaEncontrada(heroe, armas, tamArmas);
                heroe.movimiento(-1, 0);
                opcionincorrecta = false;
                break;
                
            case 4:
                //inicializarSemillaRandom();
                probEncontrarArma = rand() % 100;
                if(probEncontrarArma > probMinima)
                    armaEncontrada(heroe, armas, tamArmas);
                heroe.movimiento(0, -1);
                opcionincorrecta = false;
                break;
                
            default:
                cout<<"Introduzca una opcion correcta: ";
                break;
        }
    }
}

/**
 * 
 * @param[in] armas, Vector de armas
 * @param[in] tamArmas, Tamaño del vector de armas
 */
void armaEncontrada(PersonajeVideojuego& heroe, Arma armas[], int tamArmas) {
    
    ScreenClear();
    
    char salir;
    int armaEncontrada = 0;
    
    armaEncontrada = armaAleatoria(tamArmas);
    
    cout << "Has encontrado el arma: " << armas[armaEncontrada].getNombre() << endl;
    cout << "Este arma tiene un daño de: " << armas[armaEncontrada].getDamage() << endl;
    
    if (armas[armaEncontrada].getDamage()<heroe.GetDamage()) {
        cout<<"Tiene menos daño que el arma equipada actualmente, por lo que se desecha"<<endl;
    }else{
        cout << "El arma ha sido equipada automáticamente" << endl;
        heroe.equiparArma(&armas[armaEncontrada]);
    }
    
    cout << "Introduzca un caracter para continuar: ";
    cin >> salir;
    
}