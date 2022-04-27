//
// Created by grass on 25/04/2022.
//

#ifndef PRACTICASORT_INCLUDE_HEAPSORT_H_
#define PRACTICASORT_INCLUDE_HEAPSORT_H_

#include "P_orden.h"

// n -> tamaño del vector
// i -> apunta a la posición en la que se va a insertar el elemento. (empieza en n_ y acaba en 0)


template<class CLAVE>
class HeapSort : public P_Ordenar<CLAVE> {
 public:

  void ordenar(CLAVE *vector, int n_);
  void floyd(CLAVE *vector, int i_, int n_);

};

template<class CLAVE>
void HeapSort<CLAVE>::ordenar(CLAVE *vector, int n_) {
  CLAVE cambio;

  // primer ordenamiento de la lista
  // ((n / 2) - 1) corresponde al úlimo nodo padre
  for (int i = (n_ / 2) - 1; i >= 0; i--)
    floyd(vector, i, n_);

  for (int i = n_ - 1; i >= 0; i--) {
    // swap entre el elemento 0 que ya ha sido ordenado y i.
    cambio = vector[0];
    vector[0] = vector[i];
    vector[i] = cambio;

    // llama al algoritmo de floyd para ordenar desde 0 hasta i.
    floyd(vector, 0, i - 1);
  }
}

template<class CLAVE>
void HeapSort<CLAVE>::floyd(CLAVE *vector, int i_, int n_) {

  CLAVE cambio;
  cambio = vector[i_];
  int h = 0;
  while ((2 * i_) < n_) {
    int h1 = (2 * i_ + 1); // posicion de left child
    int h2 = h1 + 1; // posicion de right child

    if (h1 == n_)
      h = h1;
    else if ((h1 < n_) && (vector[h1] > vector[h2]))
      h = h1;
    else
      h = h2;

    if (vector[h] <= cambio)
      break;

    else {
      vector[i_] = vector[h];
      vector[h] = cambio;
      i_ = h;
    }
  }
}

#endif //PRACTICASORT_INCLUDE_HEAPSORT_H_
