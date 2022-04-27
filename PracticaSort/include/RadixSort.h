//
// Created by grass on 27/04/2022.
//

#ifndef PRACTICASORT_INCLUDE_RADIXSORT_H_
#define PRACTICASORT_INCLUDE_RADIXSORT_H_

#include "P_orden.h"

template<class Clave>
class RadixSort : public P_Ordenar<Clave> {
 public:
  void ordenar(Clave *vector, int n) override;
  void CountingSort(Clave *vector, int size, int div);
  int getMax(Clave *vector, int size);
};

template<class Clave>
void RadixSort<Clave>::CountingSort(Clave *vector, int size, int div) {
  Clave output[size];
  int count[10] = {0};

  for (int i = 0; i < size; i++)
    count[((int)vector[i] / div) % 10]++;

  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (int i = size - 1; i >= 0; i--) {
    output[count[((int)vector[i] / div) % 10] - 1] = vector[i];
    count[((int)vector[i] / div) % 10]--;
  }

  for (int i = 0; i < size; i++)
    vector[i] = output[i];
}

template<class Clave>
void RadixSort<Clave>::ordenar(Clave *vector, int n) {
  int m = getMax(vector, n);
  for (int div = 1; m / div > 0; div *= 10)
    CountingSort(vector, n, div);
}
template<class Clave>
int RadixSort<Clave>::getMax(Clave *vector, int size) {
  auto max = vector[0];
  for (int i = 0; i < size; i++)
    if ((int)vector[i] > (int)max)
      max = vector[i];
  return (int)max;
}

#endif //PRACTICASORT_INCLUDE_RADIXSORT_H_
