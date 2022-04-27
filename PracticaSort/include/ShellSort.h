//
// Created by grass on 27/04/2022.
//

#ifndef PRACTICASORT_INCLUDE_SHELLSORT_H_
#define PRACTICASORT_INCLUDE_SHELLSORT_H_

#include "P_orden.h"

template <class Clave>
class ShellSort : public P_Ordenar<Clave> {
 private:
  float alfa_;

 public:
  ShellSort(float alfa) : alfa_(alfa) {}
  void ordenar(Clave *vector, int n);
  void deltasort(Clave *vector, int delta, int n);
};

template<class Clave>
void ShellSort<Clave>::ordenar(Clave *vector, int n) {
  int delta = n * alfa_;
  while (delta > 0)
  {
    delta = delta / 2;
    deltasort(vector, delta, n);
  }
}

template<class Clave>
void ShellSort<Clave>::deltasort(Clave *vector, int delta, int n) {
  bool indicado;
  Clave x;
  int j = 0;
  for (int i = delta; i < n; i++)
  {
    indicado = false;
    x = vector[i];
    j = i;
    while ((j >= delta) && (x < vector[j - delta]))
    {
      vector[j] = vector[j - delta];
      j = j - delta;
      indicado = true;
    }
    if (indicado)
      vector[j] = x;
  }
}
#endif //PRACTICASORT_INCLUDE_SHELLSORT_H_
