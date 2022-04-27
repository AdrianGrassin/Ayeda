//
// Created by grass on 27/04/2022.
//

#ifndef PRACTICASORT_INCLUDE_QUICKSORT_H_
#define PRACTICASORT_INCLUDE_QUICKSORT_H_

#include "P_orden.h"

template<class Clave>
class QuickSort : public P_Ordenar<Clave> {
 public:
  void ordenar(Clave *vector, int n) override;
  void auxiliarquicksort(Clave *vector, int left_lim, int right_lim);

};

template<class Clave>
void QuickSort<Clave>::ordenar(Clave *vector, int n) {
  auxiliarquicksort(vector, 0, n);
}

template<class Clave>
void QuickSort<Clave>::auxiliarquicksort(Clave *vector, int left_lim, int right_lim) {

  int izquierda(left_lim), derecha(right_lim);
  auto pivote = vector[(left_lim + right_lim) / 2];

  while (izquierda <= derecha) {
    while (vector[derecha] > pivote && derecha >= left_lim)
      derecha--;
    while (vector[izquierda] < pivote && izquierda <= right_lim)
      izquierda++;

    if (izquierda <= derecha) {
      auto buff = vector[derecha];
      vector[derecha] = vector[izquierda];
      vector[izquierda] = buff;
      derecha--;
      izquierda++;
    }
  }

  if( left_lim < derecha)
    auxiliarquicksort(vector, left_lim, derecha);
  if (izquierda < right_lim)
    auxiliarquicksort(vector, izquierda, right_lim);

}

#endif //PRACTICASORT_INCLUDE_QUICKSORT_H_
