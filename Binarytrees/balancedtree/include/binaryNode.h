//
// Created by grass on 08/05/2022.
//

#ifndef BALANCEDTREE_INCLUDE_BINARYNODE_H_
#define BALANCEDTREE_INCLUDE_BINARYNODE_H_

template<class Key>
class NodoB {
 private:
  Key dato_;

  NodoB *izq_ = nullptr;
  NodoB *dcho_ = nullptr;

 public:
  NodoB(Key, NodoB *, NodoB *);
  explicit NodoB(Key);
  NodoB(NodoB *, bool);

  ~NodoB();

  Key &getdata();
  NodoB *&getnode(bool side);



};

template<class Key>
NodoB<Key>::NodoB(NodoB *node, bool side) {
  // 1 izquierda : 0 derecha
  (side) ? izq_ = node : dcho_ = node;
}

template<class Key>
NodoB<Key>::NodoB(Key dato) {
  dato_ = dato;
}

template<class Key>
NodoB<Key>::NodoB(Key dato, NodoB *izq, NodoB *dch) {
  dato_ = dato;
  izq_ = izq;
  dcho_ = dch;
}

template<class Key>
Key &NodoB<Key>::getdata() {
  if (this != nullptr)
    return dato_;

  throw std::invalid_argument("Not found");
}

template<class Key>
NodoB<Key> *&NodoB<Key>::getnode(bool side) {
  if (side)
    return izq_;
  return dcho_;
}

template<class Key>
NodoB<Key>::~NodoB() {
  izq_ = nullptr;
  dcho_ = nullptr;
}

#endif //BALANCEDTREE_INCLUDE_BINARYNODE_H_
