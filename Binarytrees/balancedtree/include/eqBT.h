//
// Created by grass on 08/05/2022.
//

#ifndef BALANCEDTREE_INCLUDE_EQBT_H_
#define BALANCEDTREE_INCLUDE_EQBT_H_
#include "binarytree.h"

template<class Key>
class ABE : public AB<Key> {
 public:
  ABE();
  bool insertar(const Key &k) override;
  bool buscar(const Key &k) const override;

  bool buscaraux(NodoB<Key> *node, Key k) const;
  void insertaraux(NodoB<Key> *&node, Key k) const;

  int tam_subarbol(NodoB<Key> *node) const;

};

template<class Key>
bool ABE<Key>::insertar(const Key &k) {
  if(AB<Key>::root_ == nullptr)
    AB<Key>::root_ = new NodoB<Key>(k);

  if (buscar(k))
    return false;

  insertaraux(AB<Key>::root_, k);

  return true;
}

template<class Key>
bool ABE<Key>::buscar(const Key &k) const {
  return buscaraux(AB<Key>::root_, k);
}

template<class Key>
ABE<Key>::ABE() {
  AB<Key>::root_ = nullptr;
}
template<class Key>
bool ABE<Key>::buscaraux(NodoB<Key> *node, Key k) const {
  if (node->getdata() == k) {
    return true;
  }
  if (node == nullptr)
    return false;

  if (k > node->getdata())
    return buscaraux(node->getnode(IZQUIERDA), k);
  else
    return buscaraux(node->getnode(DERECHA), k);


}
template<class Key>
void ABE<Key>::insertaraux(NodoB<Key> *&node, Key k) const {
  if (tam_subarbol(node->getnode(IZQUIERDA)) <= tam_subarbol(node->getnode(DERECHA))) {
    if (node->getnode(IZQUIERDA) != nullptr)
      insertaraux(node->getnode(IZQUIERDA), k);
    else
      node->getnode(IZQUIERDA) = new NodoB<Key>(k);
  }
  else {
    if (node->getnode(DERECHA) != nullptr)
      insertaraux(node->getnode(DERECHA), k);
    else
      node->getnode(DERECHA) = new NodoB<Key>(k);
  }
}

template<class Key>
int ABE<Key>::tam_subarbol(NodoB<Key> *node) const {
  if (node == NULL)
    return 0;

  return (1 + tam_subarbol(node->getnode(IZQUIERDA)) + tam_subarbol(node->getnode(DERECHA)));

}

#endif //BALANCEDTREE_INCLUDE_EQBT_H_
