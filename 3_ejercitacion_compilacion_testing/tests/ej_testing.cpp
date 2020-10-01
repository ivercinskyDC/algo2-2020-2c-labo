#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    EXPECT_EQ(22, 15 + 7);
}

// Ejercicio 5
TEST(Aritmetica, potencia ) {
    EXPECT_EQ(101.0, pow(10, 2));
}

// Ejercicios 6..9
TEST(Aritmetica, potencia_general) {
    for(int i = -5; i <= 5; i++) {
        EXPECT_EQ(pow(i, 2), i*i);
    }
}

TEST(Diccionario, obtener) {
    map<int, int> dicc;
    dicc.insert(pair<int,int>{1,2});
    EXPECT_EQ(dicc.at(1), 2);
}

TEST(Diccionario, definir) {
    map<int, int> dicc;
    EXPECT_EQ(dicc.find(1), dicc.end());
    dicc.insert(pair<int,int>{1,2});
    EXPECT_EQ(dicc.at(1), 2);
}

TEST(Truco, inicio) {
    Truco t;
    EXPECT_EQ(0, t.puntaje_j1());
    EXPECT_EQ(0, t.puntaje_j2());
}

TEST(Truco, buenas) {
    Truco t;
    EXPECT_EQ(false, t.buenas(1));
    for(int i=0; i<15;i++) {
        t.sumar_punto(1);
    }
    EXPECT_EQ(15, t.puntaje_j1());
    EXPECT_EQ(0, t.puntaje_j2());
    EXPECT_EQ(false, t.buenas(1));
    t.sumar_punto(1);
    EXPECT_EQ(true, t.buenas(1));
    t.sumar_punto(1);
    t.sumar_punto(1);
    EXPECT_EQ(true, t.buenas(1));
}
