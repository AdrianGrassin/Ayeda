//
// Created by grass on 25/05/2022.
//

#ifndef BALANCEDTREE_INCLUDE_ARBOLAVL_H_
#define BALANCEDTREE_INCLUDE_ARBOLAVL_H_
#include "nodoAVL.h"

template<class Key>
class ArbolAVL {
 private:
  nodoAVL<Key> *raiz_;
 public:

  explicit ArbolAVL(nodoAVL<Key> *raiz = nullptr) : raiz_(raiz) {}

  bool buscar(const int &k) const;
  bool auxbuscar(nodoAVL<Key> *nodo, int k) const;

  void rotacion_II(nodoAVL<Key> *&nodo);
  void rotacion_DD(nodoAVL<Key> *&nodo);
  void rotacion_ID(nodoAVL<Key> *&nodo);
  void rotacion_DI(nodoAVL<Key> *&nodo);

  void insertar(int ClaveDada);

  void inserta_bal(nodoAVL<Key> *&nodo, nodoAVL<Key> *nuevo, bool &crece);
  void insert_re_balancea_izqda(nodoAVL<Key> *&nodo, bool &crece);
  void insert_re_balancea_dcha(nodoAVL<Key> *&nodo, bool &crece);

  void eliminar(int ClaveDada);

  void eliminar_rama(nodoAVL<Key> *&nodo, int ClaveDada, bool &decrece);
  void sustituye(nodoAVL<Key> *&eliminado, nodoAVL<Key> *&sust, bool &decrece);
  void eliminar_re_balancea_izda(nodoAVL<Key> *&nodo, bool &decrece);
  void eliminar_re_balancea_dcha(nodoAVL<Key> *&nodo, bool &decrece);

  void inorden(nodoAVL<Key> *nodo);
  void mostrar(nodoAVL<Key> *nodo);
  void write();
  void niveles(nodoAVL<Key> *nodo);

  nodoAVL<Key>* getroot(){ return raiz_;};
};

template<class Key>
void ArbolAVL<Key>::rotacion_II(nodoAVL<Key> *&nodo) {
  nodoAVL<Key>* nodo1 = nodo->getiz();
  nodo->getiz() = nodo1->getde();
  nodo1->getde() = nodo;
  if (nodo1->getbal() == 1) {
    nodo->getbal() = 0;
    nodo1->getbal() = 0;
  } else { // nodo1->bal == 0
    nodo->getbal() = 1;
    nodo1->getbal() = -1;
  }
  nodo = nodo1;
}

template<class Key>
void ArbolAVL<Key>::rotacion_DD(nodoAVL<Key> *&nodo) {
  nodoAVL<Key>* nodo1 = nodo->getde();
  nodo->getde() = nodo1->getiz();
  nodo1->getiz() = nodo;
  if (nodo1->getbal() == -1) {
    nodo->getbal() = 0;
    nodo1->getbal() = 0;
  } else { // nodo1->bal == 0
    nodo->getbal() = -1;
    nodo1->getbal() = 1;
  }
  nodo = nodo1;
}

template<class Key>
void ArbolAVL<Key>::rotacion_ID(nodoAVL<Key> *&nodo) {
  nodoAVL<Key> *nodo1 = nodo->getiz();
  nodoAVL<Key> *nodo2 = nodo1->getde();
  nodo->getiz() = nodo2->getde();
  nodo2->getde() = nodo;
  nodo1->getde() = nodo2->getiz();
  nodo2->getiz() = nodo1;
  if (nodo2->getbal() == -1)
    nodo1->getbal() = 1;
  else nodo1->getbal() = 0;
  if (nodo2->getbal() == 1)
    nodo->getbal() = -1;
  else nodo->getbal() = 0;
  nodo2->getbal() = 0;
  nodo = nodo2;
}

template<class Key>
void ArbolAVL<Key>::rotacion_DI(nodoAVL<Key> *&nodo) {
  nodoAVL<Key> *nodo1 = nodo->getde();
  nodoAVL<Key> *nodo2 = nodo1->getiz();
  nodo->getde() = nodo2->getiz();
  nodo2->getiz() = nodo;
  nodo1->getiz() = nodo2->getde();
  nodo2->getde() = nodo1;
  if (nodo2->getbal() == 1)
    nodo1->getbal() = -1;
  else nodo1->getbal() = 0;
  if (nodo2->getbal() == -1)
    nodo->getbal() = 1;
  else nodo->getbal() = 0;
  nodo2->getbal() = 0;
  nodo = nodo2;
}

template<class Key>
void ArbolAVL<Key>::insertar(int ClaveDada) {
  auto *nuevo = new nodoAVL<Key>(ClaveDada, 0);
  bool crece = false;
  inserta_bal(raiz_, nuevo, crece);
}

template<class Key>
void ArbolAVL<Key>::inserta_bal(nodoAVL<Key> *&nodo,
                                nodoAVL<Key> *nuevo, bool &crece) {
  if (nodo == nullptr) {
    nodo = nuevo;
    crece = true;
  } else if (nuevo->getclave() < nodo->getclave()) {
    inserta_bal(nodo->getiz(), nuevo, crece);
    if (crece) insert_re_balancea_izqda(nodo, crece);
  } else {
    inserta_bal(nodo->getde(), nuevo, crece);
    if (crece) insert_re_balancea_dcha(nodo, crece);
  }
}

template<class Key>
void ArbolAVL<Key>::insert_re_balancea_izqda(nodoAVL<Key> *&nodo, bool &crece) {

  switch (nodo->getbal()) {
    case -1: nodo->getbal() = 0;
      crece = false;
      break;
    case 0: nodo->getbal() = 1;
      break;
    case 1: nodoAVL<Key> *nodo1 = nodo->getiz();
      if (nodo1->getbal() == 1)
        rotacion_II(nodo);
      else rotacion_ID(nodo);
      crece = false;
  }
}

template<class Key>
void ArbolAVL<Key>::insert_re_balancea_dcha(nodoAVL<Key> *&nodo, bool &crece) {

  switch (nodo->getbal()) {
    case 1: nodo->getbal() = 0;
      crece = false;
      break;
    case 0: nodo->getbal() = -1;
      break;
    case -1: nodoAVL<Key> *nodo1 = nodo->getde();
      if (nodo1->getbal() == -1)
        rotacion_DD(nodo);
      else rotacion_DI(nodo);
      crece = false;
  }
}

template<class Key>
void ArbolAVL<Key>::eliminar(int clave_dada) {
  bool decrece = false;
  eliminar_rama(raiz_, clave_dada, decrece);
}

template<class Key>
void ArbolAVL<Key>::eliminar_rama(nodoAVL<Key> *&nodo, int ClaveDada, bool &decrece) {
  if (nodo == nullptr) return;
  if (ClaveDada < nodo->getclave()) {
    eliminar_rama(nodo->getiz(), ClaveDada, decrece);
    if (decrece)
      eliminar_re_balancea_izda(nodo, decrece);
  } else if (ClaveDada > nodo->getclave()) {
    eliminar_rama(nodo->getde(), ClaveDada, decrece);
    if (decrece)
      eliminar_re_balancea_dcha(nodo, decrece);
  } else { // nodo->clave == clave_dada(encontrado)
    nodoAVL<Key> *Eliminado = nodo;
    if (nodo->getiz() == nullptr) {
      nodo = nodo->getde();
      decrece = true;
    } else if (nodo->getde() == nullptr) {
      nodo = nodo->getiz();
      decrece = true;
    } else {
      sustituye(Eliminado, nodo->getiz(), decrece);
      if (decrece)
        eliminar_re_balancea_izda(nodo, decrece);
    }
    delete Eliminado;
  }
}

template<class Key>
void ArbolAVL<Key>::eliminar_re_balancea_izda(nodoAVL<Key> *&nodo, bool &decrece) {
  nodoAVL<Key> *nodo1;
  switch (nodo->getbal()) {
    case -1: nodo1 = nodo->getde();
      if (nodo1->getbal() > 0)
        rotacion_DI(nodo);
      else {
        if (nodo1->getbal() == 0)
          decrece = false;
        rotacion_DD(nodo);
      }
      break;
    case 0: nodo->getbal() = -1;
      decrece = false;
      break;
    case 1: nodo->getbal() = 0;
  }
}

template<class Key>
void ArbolAVL<Key>::eliminar_re_balancea_dcha(nodoAVL<Key> *&nodo, bool &decrece) {
  nodoAVL<Key> *nodo1;
  switch (nodo->getbal()) {
    case  1: nodo1 = nodo->getiz();
    if (nodo1->getbal() < 0)
      rotacion_ID(nodo);
    else {
      if (nodo1->getbal() == 0)
        decrece = false;
      rotacion_II(nodo);
    }
    break ;
    case  0: nodo->getbal() = 1;
    decrece = false;
    break;
    case -1: nodo->getbal() = 0;
  }
}

template<class Key>
void ArbolAVL<Key>::sustituye(nodoAVL<Key> *&eliminado,
                              nodoAVL<Key> *&sust, bool &decrece) {
  if (sust->getde() != nullptr) {
    sustituye(eliminado, sust->getde(), decrece);
    if (decrece)
      eliminar_re_balancea_dcha(sust, decrece);
  } else {
    eliminado->getclave() = sust->getclave();
    eliminado = sust;
    sust = sust->getiz();
    decrece = true;
  }
}

template <class Key>
void ArbolAVL<Key>::inorden(nodoAVL<Key> *nodo)
{
  if (nodo == nullptr)
    return;

  inorden(nodo->getiz());
  std::cout << "[";
  std::cout << nodo->getclave();
  std::cout << "]";
  inorden(nodo->getde());
}

template <class Key>
void ArbolAVL<Key>::mostrar(nodoAVL<Key> *nodo)
{
  if (nodo == nullptr)
    std::cout << "[.]";
  else
  {
    std::cout << "[";
    std::cout << nodo->getclave();
    std::cout << "]";
  }
}

template <class Key>
void ArbolAVL<Key>::write()
{
    niveles(raiz_);
}

template <class Key>
void ArbolAVL<Key>::niveles(nodoAVL<Key> *nodo)
{
  std::deque<std::pair<nodoAVL<Key> *, int>> Q;
  nodoAVL<Key> *aux;
  int nivel = 0, nivel_actual = 0;

  Q.push_back(std::pair<nodoAVL<Key> *, int>(nodo, 0));

  std::cout << "\nNivel 0: ";

  while (!Q.empty())
  {
    aux = (Q.front()).first;
    nivel = (Q.front()).second;
    Q.pop_front();

    if (nivel > nivel_actual)
    {
      nivel_actual = nivel;
      std::cout << "\nNivel " << nivel_actual << ": ";
    }

    mostrar(aux);
    if (aux != nullptr)
    {
      Q.push_back(std::pair<nodoAVL<Key> *, int>(aux->getiz(), nivel + 1));
      Q.push_back(std::pair<nodoAVL<Key> *, int>(aux->getde(), nivel + 1));
    }
  }
}
template<class Key>
bool ArbolAVL<Key>::buscar(const int &k) const {
  return auxbuscar(raiz_, k);
}
template<class Key>
bool ArbolAVL<Key>::auxbuscar(nodoAVL<Key> *nodo, int k) const {
  if (nodo == nullptr)
    return false;

  if (nodo->getclave() == k)
    return true;

  if (nodo->getclave() > k)
    return auxbuscar(nodo->getiz(), k);

  return auxbuscar(nodo->getde(), k);
}
#endif //BALANCEDTREE_INCLUDE_ARBOLAVL_H_
