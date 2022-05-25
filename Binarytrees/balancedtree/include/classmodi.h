//
// Created by grass on 11/05/2022.
//

#ifndef BALANCEDTREE_INCLUDE_CLASEPOCHA_H_
#define BALANCEDTREE_INCLUDE_CLASEPOCHA_H_
#include <iostream>

static unsigned int comp = 0;

class Key {
 private:
  int clave = 0;
  std::string data = " ";

 public:
  Key();
  Key(int a) : clave(a), data() {}
  Key(int a, std::string &dat) : clave(a), data(dat) {};
  bool operator==(const Key &key) const;
  bool operator<(const Key &key) const;
  bool operator>(const Key &key) const;
  bool operator<=(const Key &key) const;
  void operator=(const int &num);

  void modifydata();
  void readdata();
  void setcomp(unsigned &num);

  friend std::ostream &operator<<(std::ostream &os, const Key &key);
  friend std::istream &operator>>(std::istream &is, Key &key);
};

bool Key::operator==(const Key &key) const {
  ++comp;
  return clave == key.clave;
}

bool Key::operator<(const Key &key) const {
  ++comp;
  return clave < key.clave;
}

bool Key::operator>(const Key &key) const {
  ++comp;
  return clave > key.clave;
}

bool Key::operator<=(const Key &key) const {
  ++comp;
  return clave <= key.clave;
}

std::istream &operator>>(std::istream &is, Key &key) {
  std::cout << "\nvalor clave:";
  is >> key.clave;

  return is;
}

std::ostream &operator<<(std::ostream &os, const Key &key) {
  os << key.clave;
  return os;
}
void Key::modifydata() {
  std::cout << "Introduce la nueva data: ";
  std::cin >> data;
}
void Key::readdata() {
  std::cout << "\nData:" << data << "\n";
}

void Key::operator=(const int &num) {
  clave = num;
  comp = 0;
}
void Key::setcomp(unsigned &num) {
  comp = num;
}

Key::Key() {
  clave = 0;
  data = " ";
}

#endif //BALANCEDTREE_INCLUDE_CLASEPOCHA_H_
