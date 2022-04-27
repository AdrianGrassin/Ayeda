//
// Created by grass on 27/04/2022.
//

#ifndef PRACTICASORT_INCLUDE_SELECCIONSORT_H_
#define PRACTICASORT_INCLUDE_SELECCIONSORT_H_

#include "P_orden.h"

template <class Clave>
class Seleccion : public P_Ordenar<Clave> {
 public:
  void ordenar(Clave *vector, int n);

};

template<class Clave>
void Seleccion<Clave>::ordenar(Clave *vector, int n) {
  int currentminimum;
  Clave dummy;

  for(int orderedwallpointer = 0; orderedwallpointer < n; orderedwallpointer++) {
    currentminimum = orderedwallpointer;
    for(int j = orderedwallpointer; j < n; j++) {
      if(vector[j] < vector[currentminimum])
        currentminimum = j;
    }

    dummy = vector[orderedwallpointer];
    vector[orderedwallpointer] = vector[currentminimum];
    vector[currentminimum] = dummy;

  }


}

#endif //PRACTICASORT_INCLUDE_SELECCIONSORT_H_
