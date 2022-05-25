#include <iostream>
#include <unistd.h>
#include "../include/utilities.h"
#include "../include/eqBT.h"
#include "../include/ABB.h"
#include "../include/classmodi.h"
#include "../include/ArbolAVL.h"

#pragma execution_character_set( "utf-8" )
#define Key Key

int main() {
  SetConsoleOutputCP(65001);
  // preconfiguraciones para la consola
  char option;
  int treesel, avlclave;
  Key dato;

  AB<Key> *equi = new ABE<Key>();
  AB<Key> *sear = new ABB<Key>();

  std::cout << "Se han creado 2 arboles: Un ABE y un ABB\n";

  srand(time(nullptr));
  for (int i = 0; i <= 500; i++) {
    dato = rand() % 1000;
    equi->insertar(dato);
  }

  srand(time(nullptr));
  comp = 0;
  dato = rand() % 1000;
  equi->buscar(dato);
  std::cout << "\nse comparó: " << comp << "veces en el ABE\n";

  for (int i = 0; i <= 500; i++) {
    dato = rand() % 1000;
    sear->insertar(dato);
  }

  comp = 0;
  dato = rand() % 1000;
  sear->buscar(dato);
  std::cout << "\nse comparó: " << comp << "veces en el ABB\n";

  system("pause");
  system("cls");

  std::cout << "Escoge el árbol a utilizar:\n"
               "1. AB_equilibrado\n"
               "2. AB_busqueda\n"
               "3. AB_AVL\n"
               ">";
  std::cin >> treesel;

  system("CLS");
  if (treesel == 3) {
    ArbolAVL<Key> tree;
    while (option != 's') {
      menu(treesel);
      std::cin >> option;
      switch (option) {
        case 'i' : std::cout << "introduzca la clave a insertar: ";
        std::cin >> avlclave;
        tree.insertar(avlclave);
        tree.write();
        break;
        case 'b' : std::cout << "introduce la clave a buscar: ";
        std::cin >> avlclave;
        if(tree.buscar(avlclave))
          std::cout << "se encontró el nodo\n";
        else
          std::cout << "no se encontró el nodo\n";
        break;
        case 'm' :std::cout << "Imprimiendo el árbol en inorden: \n";
          tree.inorden(tree.getroot());
          std::cout << std::endl;
          break;
        case 'e' :std::cout << "Introduce la clave a eliminar: ";
          std::cin >> avlclave;
          tree.eliminar(avlclave);
          tree.write();
          break;
        case 's' :std::cout << "saliendo del programa...\n";
          break;

        default: std::cout << "La opción introducida no es válida, por favor vuelve a introducir una letra";
          break;
      }
      system("pause");
      system("CLS");
    }
  return 0;
  } else {

    AB<Key> *Abin;
    while (treesel != -1 && treesel != -2)
      switch (treesel) {
        case 1:Abin = new ABE<Key>();
          treesel = -1;
          break;
        case 2:Abin = new ABB<Key>();
          treesel = -2;
          break;
        default:std::cout << "Numero incorrecto vuelva a introducir una opcion:\r";
          sleep(2);
          std::cout << "                                                 \r";
          std::cin >> treesel;
          break;
      }

    while (option != 's') {
      menu(treesel);
      std::cin >> option;
      switch (option) {
        case 'i' :std::cout << "Introduzca la clave a insertar: ";
          std::cin >> dato;
          if (Abin->insertar(dato)) {
            std::cout << "nodo insertado!\n";
          } else
            std::cout << "el nodo no se pudo insertar\n";

          Abin->write();
          break;
        case 'b' :
          try {
            std::cout << "Introduzca el dato a buscar: ";
            std::cin >> dato;
            if (Abin->buscar(dato))
              std::cout << "Se encontró el elemento buscado!\n";
            else
              std::cout << "No se encontró el elemento buscado!\n";
          } catch (std::invalid_argument &err) {
            std::cerr << err.what() << "\n";
          }

          break;
        case 'm' :std::cout << "Imprimiendo el árbol en inorden: \n";
          Abin->inorden();
          break;
        case 'e' :std::cout << "Introduzca la clave del nodo a eliminar: \n";
          std::cin >> dato;
          if (Abin->eliminar(dato)) {
            std::cout << "Nodo: " << dato << " ha sido eliminado!\n";
          } else {
            std::cout << "El nodo introducido no se encuentra en el árbol\n";
          }
          Abin->write();
          break;
        case 's' :std::cout << "Saliendo del programa...";
          sleep(3);
          return 1;

        default:std::cout << "La opción introducida no es correcta, vuelve a introducir una opción\n";
          sleep(2);
          break;
      }
      system("pause");
    }
  }
  return 0;
}

