#include <iostream>
#include <unistd.h>
#include "utilities.cpp"
#include "../include/eqBT.h"
#include "../include/clasepocha.h"

#pragma execution_character_set( "utf-8" )
#define Key Key



int main() {
  SetConsoleOutputCP(65001);
  // preconfiguraciones para la consola
  char option;
  Key dato;

  // instanciación del árbol binario
  AB<Key>* Abin = new ABE<Key>();

  while(option != 's'){
    menu();
    std::cin >> option;
    switch (option) {
      case 'i' :
        std::cout << "Introduzca la clave a insertar: ";
        std::cin >> dato;
        if(Abin->insertar(dato))
          std::cout << "nodo insertado!\n";
        else
          std::cout << "el nodo no se pudo insertar\n";

        Abin->write();
        break;
      case 'b' :
        std::cout << "Introduzca el dato a buscar: ";
        std::cin >> dato;
        Abin->buscar(dato);
        break;
      case 'm' :
        std::cout << "Imprimiendo el árbol en inorden: \n";
        Abin->inorden();
        break;
      case 's' :
        std::cout << "Saliendo del programa...";
        sleep(3);
        return 1;

      default:
        std::cout << "La opción introducida no es correcta, vuelve a introducir una opción\n";
        sleep(2);
        break;
    }
    system("pause");
  }
  return 0;
}

