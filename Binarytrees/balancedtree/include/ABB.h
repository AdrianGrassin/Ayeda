//
// Created by grass on 17/05/2022.
//

#ifndef BALANCEDTREE_INCLUDE_ABB_H_
#define BALANCEDTREE_INCLUDE_ABB_H_
#include "binarytree.h"

template<class Key>
class ABB : public AB<Key> {
 public:
  bool insertar(const Key &k);
  void insertaraux(NodoB<Key> *&nodo, Key k);

  bool buscar(const Key &k) const override;
  bool auxbuscar(NodoB<Key> *nodo, Key k) const;

  bool eliminar(const Key &k);
  void eliminarnodo(NodoB<Key> *nodoEliminar);
  NodoB<Key> *getparentnode(NodoB<Key> *nodo, Key k);
  NodoB<Key> *getmenorenrama(NodoB<Key> *nodo); // a esta función hay que llamarla con el hijo derecho del nodo a eliminar

};

template<class Key>
bool ABB<Key>::insertar(const Key &k) {
  if (AB<Key>::root_ == nullptr) {
    AB<Key>::root_ = new NodoB<Key>(k);
    return true;
  }
  if (buscar(k))
    return false;

  insertaraux(AB<Key>::root_, k);
  return true;
}

template<class Key>
bool ABB<Key>::buscar(const Key &k) const {
  return auxbuscar(AB<Key>::root_, k);
}

template<class Key>
bool ABB<Key>::auxbuscar(NodoB<Key> *nodo, Key k) const {
  if (nodo == nullptr)
    return false;

  if (nodo->getdata() == k)
    return true;

  if (nodo->getdata() > k)
    return auxbuscar(nodo->getnode(IZQUIERDA), k);

  return auxbuscar(nodo->getnode(DERECHA), k);
}

// esta es una función auxiliar para encontrar el nodo a eliminar
template<class Key>
NodoB<Key> *ABB<Key>::getparentnode(NodoB<Key> *nodo, const Key k) {
  if (nodo == nullptr)
    return nullptr;

  if (nodo->getdata() == AB<Key>::root_->getdata())
    return nodo;

  if (nodo->getnode(IZQUIERDA) != nullptr) {
    if (nodo->getnode(IZQUIERDA)->getdata() == k) {
      return nodo;
    }
  }

  if (nodo->getnode(DERECHA) != nullptr) {
    if (nodo->getnode(DERECHA)->getdata() == k) {
      return nodo;
    }
  }

  if (nodo->getdata() > k)
    return getparentnode(nodo->getnode(IZQUIERDA), k);

  return getparentnode(nodo->getnode(DERECHA), k);
}

template<class Key>
NodoB<Key> *ABB<Key>::getmenorenrama(NodoB<Key> *nodo) {
  if (nodo->getnode(IZQUIERDA) != nullptr)
    return getmenorenrama(nodo->getnode(IZQUIERDA));
  else
    return nodo;
}

template<class Key>
void ABB<Key>::eliminarnodo(NodoB<Key> *nodoEliminar) {
  if (nodoEliminar->getnode(IZQUIERDA) && nodoEliminar->getnode(DERECHA)) {
    NodoB<Key> *min = getmenorenrama(nodoEliminar->getnode(DERECHA));
    nodoEliminar->getdata() = min->getdata();
    eliminarnodo(min);
  } else if (nodoEliminar == AB<Key>::root_) {
    if (AB<Key>::root_->getnode(IZQUIERDA)) {
      AB<Key>::root_ = AB<Key>::root_->getnode(IZQUIERDA);
    } else if (AB<Key>::root_->getnode(DERECHA))
      AB<Key>::root_ = AB<Key>::root_->getnode(DERECHA);
    else
      AB<Key>::root_ = nullptr;
  } else if (nodoEliminar->getnode(IZQUIERDA)) {
    NodoB<Key> *padre = getparentnode(AB<Key>::root_, nodoEliminar->getdata());
    if (nodoEliminar->getdata() == padre->getnode(IZQUIERDA)->getdata())
      padre->getnode(IZQUIERDA) = nodoEliminar->getnode(IZQUIERDA);
    else
      padre->getnode(DERECHA) = nodoEliminar->getnode(IZQUIERDA);
    delete nodoEliminar;
  } else if (nodoEliminar->getnode(DERECHA)) {
    NodoB<Key> *padre = getparentnode(AB<Key>::root_, nodoEliminar->getdata());
    if (nodoEliminar->getdata() == padre->getnode(IZQUIERDA)->getdata())
      padre->getnode(IZQUIERDA) = nodoEliminar->getnode(DERECHA);
    else
      padre->getnode(DERECHA) = nodoEliminar->getnode(DERECHA);
    delete nodoEliminar;
  } else {
    NodoB<Key> *padre = getparentnode(AB<Key>::root_, nodoEliminar->getdata());
    if (padre->getnode(IZQUIERDA) == nodoEliminar)
      padre->getnode(IZQUIERDA) = nullptr;
    else
      padre->getnode(DERECHA) = nullptr;

    delete nodoEliminar;
  }
}

template<class Key>
bool ABB<Key>::eliminar(const Key &k) {
  if (AB<Key>::root_ == nullptr)
    return false;

  if (!buscar(k))
    return false;

  if (AB<Key>::root_->getdata() == k) {
    eliminarnodo(AB<Key>::root_);
  } else {
    NodoB<Key> *parent = getparentnode(AB<Key>::root_, k);
    if (parent->getnode(IZQUIERDA)) {
      if (parent->getnode(IZQUIERDA)->getdata() == k)
        eliminarnodo(parent->getnode(IZQUIERDA));
    } else if (parent->getnode(DERECHA)->getdata() == k)
      eliminarnodo(parent->getnode(DERECHA));
  }
  return true;

}
template<class Key>
void ABB<Key>::insertaraux(NodoB<Key> *&nodo, Key k) {

  if (nodo->getdata() > k) {
    if (nodo->getnode(IZQUIERDA) != nullptr) {
      return insertaraux(nodo->getnode(IZQUIERDA), k);
    } else {
      nodo->getnode(IZQUIERDA) = new NodoB<Key>(k);
    }
  } else {
    if (nodo->getnode(DERECHA) != nullptr) {
      return insertaraux(nodo->getnode(DERECHA), k);
    } else {
      nodo->getnode(DERECHA) = new NodoB<Key>(k);
    }
  }

}
#endif //BALANCEDTREE_INCLUDE_ABB_H_
