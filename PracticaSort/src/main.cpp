#include "utilities.cpp"
#include "../include/HeapSort.h"
#include "../include/SeleccionSort.h"
#include "../include/QuickSort.h"
#include "../include/key.h"
#include "../include/ShellSort.h"
#include "../include/RadixSort.h"

#pragma execution_character_set( "utf-8" )

#define CLAVE Key // escribir aquí el template class

int main() {
  SetConsoleOutputCP(65001);

  char selec;
  bool keeponloop = true;
  P_Ordenar<CLAVE> *metodo;

  system("cls");
  std::cout << "Introduce el algoritmo a ejecutar:\n";

  menu();
  std::cin >> selec;

  while (keeponloop) {
    switch (selec) {
      case 's' :
        metodo = new Seleccion<CLAVE>();
        keeponloop = false;
        break;
      case 'q' :
        metodo = new QuickSort<CLAVE>();
        keeponloop = false;
      break;
      case 'l' :
        float alph;
        std::cout << "Introduce un alfa entre [0.1 - 1]:  ";
        std::cin >> alph;
        metodo = new ShellSort<CLAVE>(alph);
        keeponloop = false;
        break;
      case 'h' :
        metodo = new HeapSort<CLAVE>();
        keeponloop = false;
        break;
      case 'r' :
        metodo = new RadixSort<CLAVE>();
        keeponloop = false;
        break;
      case 'x' : return 0;

      default:
        system("cls");
        std::cout << "La opción introducida introducida no es válida, introduce una letra valida\n";
        menu();
        std::cin >> selec;
        break;
    }
  }
  system("cls");
  int size;

  std::cout << "Introduce el tamaño de la secuencia: ";
  std::cin >> size;

  auto *vec = create_vec<CLAVE>(size);
  metodo->ordenar(vec, size);

  for (int i = 0; i < size; i++)
    std::cout << std::setw(3) << i + 1 << ". [" << vec[i] << "]\n";

  std::cout << "\nComparaciones realizadas: " << comp << "\n";

  system("pause");

  delete vec;

  return 0;
}

