//
// Created by ivan on 30/9/20.
//

#ifndef ALGO2_LABO_CLASE4_PERIODO_H
#define ALGO2_LABO_CLASE4_PERIODO_H
using namespace std;

using uint = unsigned int;

class Periodo {

public:
    Periodo(int anios, int meses, int dias);

    int anios() const;
    int meses() const;
    int dias() const;

private:
    int anios_;
    int meses_;
    int dias_;
};

#endif //ALGO2_LABO_CLASE4_PERIODO_H
