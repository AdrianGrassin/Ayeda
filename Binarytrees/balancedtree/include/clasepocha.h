//
// Created by grass on 11/05/2022.
//

#ifndef BALANCEDTREE_INCLUDE_CLASEPOCHA_H_
#define BALANCEDTREE_INCLUDE_CLASEPOCHA_H_
#include <iostream>

static int comp = 0;

class Key{
 private:
  int numero = 0;
 public:
  Key() = default;
  Key(int a) : numero(a) {};

  void operator=(int n);
  bool operator==(const Key &key) const;
  bool operator<(const Key &key) const;
  bool operator>(const Key &key) const;
  bool operator<=(const Key &key) const;

  friend std::ostream& operator<<(std::ostream &os, const Key& key);
  friend std::istream& operator>>(std::istream& is, Key& key);
};

void Key::operator=(const int n) {
  numero = n;
}

bool Key::operator==(const Key &key) const {
  ++comp;
  return numero == key.numero;
}

bool Key::operator<(const Key &key) const {
  ++comp;
  return numero < key.numero;
}

bool Key::operator>(const Key &key) const {
  ++comp;
  return numero > key.numero;
}

bool Key::operator<=(const Key &key) const {
  ++comp;
  return numero <= key.numero;
}

std::istream &operator>>(std::istream &is, Key &key) {
  is >> key.numero;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Key& key)  {
  os << key.numero;
  return os;
}

#endif //BALANCEDTREE_INCLUDE_CLASEPOCHA_H_
