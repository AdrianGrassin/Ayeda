//
// Created by grass on 25/05/2022.
//

#ifndef BALANCEDTREE_INCLUDE_NODOAVL_H_
#define BALANCEDTREE_INCLUDE_NODOAVL_H_

template<class Key>
class nodoAVL {
 public:
  nodoAVL(int cl, Key dat);

  int& getclave(){ return clave;};

  nodoAVL* &getiz(){  return izdo;};

  nodoAVL* &getde(){  return dcho;};

  int& getbal(){ return bal;}


 private:
  Key dato;
  int clave;
  int bal;
  nodoAVL *izdo;
  nodoAVL *dcho;
};

template<class Key>
nodoAVL<Key>::nodoAVL(int cl, Key dat) {
  izdo = nullptr;
  dcho = nullptr;
  dato = dat;
  clave = cl;
  bal = 0;
}

#endif //BALANCEDTREE_INCLUDE_NODOAVL_H_
