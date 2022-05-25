//
// Created by grass on 08/05/2022.
//
#include "../include/utilities.h"

void menu(int selector) {
  if(selector == -1) {
    system("cls");
    std::cout << "AYEDA 2022 - Adrián Grassin\n"
                 "ARBOL BINARIO EQUILIBRADO\n"
                 "[i] Insertar clave\n"
                 "[b] Buscar clave\n"
                 "[m] Mostrar árbol inorden\n"
                 "[s] Salir\n"
                 ">";
  }
  if(selector == -2) {
    system("cls");
    std::cout << "AYEDA 2022 - Adrián Grassin\n"
                 "ARBOL BINARIO DE BÚSQUEDA\n"
                 "[i] Insertar clave\n"
                 "[b] Buscar clave\n"
                 "[m] Mostrar árbol inorden\n"
                 "[e] Eliminar nodo\n"
                 "[s] Salir\n"
                 ">";
  }
}
