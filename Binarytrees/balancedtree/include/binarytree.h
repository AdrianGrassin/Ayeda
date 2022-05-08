//
// Created by grass on 08/05/2022.
//

#ifndef BALANCEDTREE_INCLUDE_BINARYTREE_H_
#define BALANCEDTREE_INCLUDE_BINARYTREE_H_

#include <iostream>
#include "binaryNode.h"

template<class Key>
class AB {
 protected:
  NodoB<Key>* root;

 public:


  virtual bool insertar(const Key& k) = 0;
  virtual bool buscar(const Key& k) const = 0;
  void inorden() const;

  std::ostream& operator<<(std::ostream& os);
};

template<class Key>
void AB<Key>::inorden() const {

}


template<class Key>
std::ostream &AB<Key>::operator<<(std::ostream &os) {
  return os;
}

#endif //BALANCEDTREE_INCLUDE_BINARYTREE_H_
