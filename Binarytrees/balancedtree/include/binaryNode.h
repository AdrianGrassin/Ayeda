//
// Created by grass on 08/05/2022.
//

#ifndef BALANCEDTREE_INCLUDE_BINARYNODE_H_
#define BALANCEDTREE_INCLUDE_BINARYNODE_H_

template<class Key>
class NodoB {
 private:
  Key dato_;

  NodoB *izq_;
  NodoB *dcho_;

 public:
  NodoB(Key, NodoB *, NodoB *);
  explicit NodoB(Key);
  NodoB(NodoB *, bool);

  ~NodoB();

  Key getdata() const;
  NodoB *getnode(bool side) const;

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
Key NodoB<Key>::getdata() const {
  return dato_;
}

template<class Key>
NodoB<Key>* NodoB<Key>::getnode(bool side) const {
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
