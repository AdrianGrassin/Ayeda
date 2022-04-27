//
// Created by grass on 27/04/2022.
//

#ifndef PRACTICASORT_INCLUDE_KEY_H_
#define PRACTICASORT_INCLUDE_KEY_H_

static int comp = 0;

class Key {
 private:
  int numero;

 public:
  Key();

  void operator=(int n);
  bool operator==(const Key &key) const;
  bool operator<(const Key &key) const;
  bool operator>(const Key &key) const;
  bool operator<=(const Key &key) const;

  explicit operator int() const { return numero;}
  friend std::ostream& operator<<(std::ostream &os, const Key& key);
  friend std::istream& operator>>(std::istream& is, Key& key);

};


void Key::operator=(const int n) {
  numero = n;
}

Key::Key() {
  numero = 0;
}

std::ostream &operator<<(std::ostream &os, const Key& key)  {
  os << key.numero;
  return os;
}

std::istream &operator>>(std::istream &is, Key &key) {
  is >> key.numero;
  return is;
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




#endif //PRACTICASORT_INCLUDE_KEY_H_
