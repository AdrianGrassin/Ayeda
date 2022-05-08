//
// Created by grass on 08/05/2022.
//

#ifndef BALANCEDTREE_INCLUDE_EQBT_H_
#define BALANCEDTREE_INCLUDE_EQBT_H_
#include "binarytree.h"

template<class Key>
class ABE : public AB<Key> {
 public:
  bool insertar(const Key &k) override;
  bool buscar(const Key &k) const override;
};


template<class Key>
bool ABE<Key>::insertar(const Key &k) {
  return false;
}

template<class Key>
bool ABE<Key>::buscar(const Key &k) const {
  return false;
}

#endif //BALANCEDTREE_INCLUDE_EQBT_H_
