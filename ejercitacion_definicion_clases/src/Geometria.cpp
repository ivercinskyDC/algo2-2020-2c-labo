#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : ancho_(ancho), alto_(alto) {};

uint Rectangulo::alto() {
    // Completar
    return this->alto_;
}

// Completar definición: ancho
uint Rectangulo::ancho() {
    return this->ancho_;
}

// Completar definición: area
float Rectangulo::area() {
    return 1.0f*ancho()*alto();
}

// Ejercicio 2

// Clase Elipse
class Elipse {
public:
    Elipse(float r_a, float r_b);
    float r_a();
    float r_b();
    float area();

private:
    float _r_a;
    float _r_b;
    float PI = 3.14f;

};

Elipse::Elipse(float r_a, float r_b) : _r_a(r_a), _r_b(r_b) {};

float Elipse::r_b() {
    return this->_r_b;
}

float Elipse::r_a() {
    return this->_r_a;
}

float Elipse::area() {
    return PI*r_a()*r_b();
}
// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
    // Completar
    this->r_.alto();
}

float Cuadrado::area() {
    // Completar
    this->r_.area();
}

// Ejercicio 4

// Clase Circulo
class Circulo {
public:
    Circulo(float r);
    float radio();
    float area();

private:
    Elipse e_;
};

Circulo::Circulo(float r): e_(r, r) {}

float Circulo::radio() {
    // Completar
    this->e_.r_b();
}

float Circulo::area() {
    // Completar
    this->e_.area();
}

// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

// ostream Elipse
ostream& operator<<(ostream& os, Elipse e) {
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}

// Ejercicio 6

ostream& operator<<(ostream& os, Cuadrado r) {
    os << "Cuad(" << r.lado() << ")";
    return os;
}

// ostream Elipse
ostream& operator<<(ostream& os, Circulo e) {
    os << "Circ(" << e.radio() << ")";
    return os;
}