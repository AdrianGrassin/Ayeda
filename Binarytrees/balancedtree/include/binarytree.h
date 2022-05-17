//
// Created by grass on 08/05/2022.
//

#ifndef BALANCEDTREE_INCLUDE_BINARYTREE_H_
#define BALANCEDTREE_INCLUDE_BINARYTREE_H_

#define IZQUIERDA 1
#define DERECHA 0

#include <iostream>
#include <queue>
#include <stack>
#include "binaryNode.h"

template<class Key>
class AB {
 public:

  NodoB<Key> *root_;

  virtual bool insertar(const Key &k) = 0;
  virtual bool buscar(const Key &k) const = 0;
  virtual void inorden() const;
  virtual void write() const;

  Key& search(NodoB<Key>* nodo, const Key& k);
  virtual Key& operator[](const Key&);

};

template<class Key>
void AB<Key>::inorden() const {
  std::vector<Key> inorden;
  std::stack<NodoB<Key> *> pila;
  NodoB<Key> *buff = root_;

  while (true) {
    if (buff != NULL) {
      pila.push(buff);
      buff = buff->getnode(IZQUIERDA);
    } else {
      if (pila.empty())
        break;
      buff = pila.top();
      pila.pop();
      inorden.push_back(buff->getdata());
      buff = buff->getnode(DERECHA);
    }
  }

  std::cout << "INORDEN: ";

  for (const auto &nodo : inorden) {
    std::cout << "[" << nodo << "] ";
  }

  std::cout << std::endl;

}

template<class Key>
void AB<Key>::write() const {
  std::queue<NodoB<Key> *> cola;
  cola.push(root_);

  unsigned piso = 1;
  unsigned siguientepiso = 0;
  unsigned distancia = 0;
  bool nextpiso = false;

  std::cout << "Nivel 0:";
  while (!cola.empty()) {

    NodoB<Key> *k = cola.front();
    cola.pop();
    if (k == nullptr && nextpiso) {
      cola.push(nullptr);
      cola.push(nullptr);
      siguientepiso++;
      siguientepiso++;
      std::cout << "[.]";
      piso--;
    }
    if (k == nullptr && !nextpiso){
      std::cout << "[.]";
      piso--;
    }
    if(k != nullptr) {
      std::cout << "[" << k->getdata() << "]";

      if (k->getnode(IZQUIERDA) != nullptr) {
        cola.push(k->getnode(IZQUIERDA));
        nextpiso = true;
      } else
        cola.push(nullptr);

      if (k->getnode(DERECHA) != nullptr) {
        cola.push(k->getnode(DERECHA));
        nextpiso = true;
      } else
        cola.push(nullptr);

      siguientepiso++;
      siguientepiso++;

      piso--;
    }
    if (piso == 0 && !cola.empty()) {
      distancia++;
      std::cout << "\nNivel " << distancia << ": ";
      piso = siguientepiso;
      siguientepiso = 0;
      nextpiso = false;
    }
  }
  std::cout << std::endl;
}

template<class Key>
Key& AB<Key>::operator[](const Key& k) {
  return search(root_, k);
}

template<class Key>
Key &AB<Key>::search(NodoB<Key> *nodo, const Key &k) {
  std::stack<NodoB<Key> *> pila;
  NodoB<Key> *buff = root_;

  while (true) {
    if (buff != NULL) {
      pila.push(buff);
      buff = buff->getnode(IZQUIERDA);
    } else {
      if (pila.empty())
        break;
      buff = pila.top();
      pila.pop();
      if (buff->getdata() == k)
        return buff->getdata();
      buff = buff->getnode(DERECHA);
    }
  }
  std::cout << "No se encontro el elemento\n";
}

#endif //BALANCEDTREE_INCLUDE_BINARYTREE_H_
