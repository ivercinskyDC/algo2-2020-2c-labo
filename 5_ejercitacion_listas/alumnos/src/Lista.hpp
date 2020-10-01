#include "Lista.h"

Lista::Lista() {
    // Completar
    _longitud = 0;
    _head = nullptr;
    _tail = nullptr;
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    // Completar
    Nodo * current = this->_head;
    while (current != nullptr) {
        Nodo * aux = current;
        current = current->next;
        delete aux;
    }
}

Lista& Lista::operator=(const Lista& aCopiar) {
    // Completar
    while (this->longitud() > 0 ) {
        eliminar(0);
    }
    int i=0;
    while (i < aCopiar.longitud()) {
        agregarAtras(aCopiar.iesimo(i));
        i++;
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    // Completar
    Nodo* nuevo = new Nodo();
    nuevo->next = this->_head;
    if(this->_head != nullptr) {
        this->_head->prev = nuevo;
    }
    nuevo->prev = nullptr;
    nuevo->value = elem;
    this->_head = nuevo;
    _longitud++;
    if(this->_tail == nullptr) {
        this->_tail = nuevo;
    }
}

void Lista::agregarAtras(const int& elem) {
    // Completar
    Nodo* nuevo = new Nodo();
    nuevo->prev = this->_tail;
    if(this->_tail != nullptr) {
        this->_tail->next = nuevo;
    }
    nuevo->next = nullptr;
    nuevo->value = elem;
    this->_tail = nuevo;
    _longitud++;
    if(this->_head == nullptr) {
        this->_head = nuevo;
    }
}

void Lista::eliminar(Nat i) {
    // Completar
    //SI I ESTA MAS CERCA DEL FINAL CONVIENE IR DESDE EL FINAL.
    Nodo* current = this->_head;
    if(i == 0) {
        //ajustar la cabeza
        current = this->_head;
        this->_head = current->next;
        if(this->_head != nullptr) {
            this->_head->prev = nullptr;
        }
        delete current;
    } else if(i == longitud()-1) {
        //ajustar la cola
        current = this->_tail;
        this->_tail = current->prev;
        if(this->_tail != nullptr) {
            this->_tail->next = nullptr;
        }
        delete current;
    } else {
        while (i > 0 && current != nullptr) {
            current = current->next;
            i--;
        }
        Nodo* aux = current->prev;
        current->prev->next = current->next;
        current->next->prev = aux;
        delete current;
    }
    _longitud--;

}

int Lista::longitud() const {
    // Completar
    return _longitud;
}

const int& Lista::iesimo(Nat i) const {
    // Completar
    Nodo* current = this->_head;
    while (i > 0 ) {
        current = current->next;
        i--;
    }
    return current->value;
}

int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    Nodo* current = this->_head;
    while (i > 0 ) {
        current = current->next;
        i--;
    }
    return current->value;
}

void Lista::mostrar(ostream& o) {
    // Completar
    Nodo* current = this->_head;
    while (current != nullptr) {
        o << current->value;
        current->next;
    }
}
