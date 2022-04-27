//
// Created by grass on 26/04/2022.
//
#include <iostream>
#include <windows.h>
#include <iomanip>

#define MINRAND 1000
#define MAXRAND 9000

void menu() {
  std::cout << "╔═══════════════════════╗\n"
               "║ s. Seleccion          ║\n"
               "║ q. QuickSort          ║\n"
               "║ l. ShellSort          ║\n"
               "║ h. HeapSort           ║\n"
               "║ r. RadixSort          ║\n"
               "║ x. Exit               ║\n"
               "╚═══════════════════════╝\n"
               ">";
}

template<class Clave>
Clave *create_vec(int size) {

  char random;
  auto *vector = new Clave[size];

  std::cout << "Desea randomizar los valores del vector s ? n: ";
  std::cin >> random;

  if (random == 's') {
    srand(time(nullptr));
    for (int i = 0; i < size; i++)
      vector[i] = (rand() % MAXRAND) + MINRAND;

  } else {
    for (int i = 0; i < size; i++)
      std::cin >> vector[i];
  }

  for (int i = 0; i < size; i++)
    std::cout << std::setw(3) << i + 1  << ". [" << vector[i] << "]\n";


  system("pause");
  return vector;
}
