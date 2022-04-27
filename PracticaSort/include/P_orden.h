//
// Created by grass on 25/04/2022.
//

#ifndef PRACTICASORT_INCLUDE_P_ORDEN_H_
#define PRACTICASORT_INCLUDE_P_ORDEN_H_


template <class CLAVE>
class P_Ordenar {
 public:
  virtual void ordenar(CLAVE *vector, int n_) = 0;

};


#endif //PRACTICASORT_INCLUDE_P_ORDEN_H_
