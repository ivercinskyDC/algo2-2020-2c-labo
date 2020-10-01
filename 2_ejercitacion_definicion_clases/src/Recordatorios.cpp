#include <iostream>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    // Completar declaraciones funciones
    Fecha(int mes, int dia);
    int mes();
    int dia();
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif
    void incrementar_dia();

  private:
    int mes_;
    int dia_;
    //Completar miembros internos
};
Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia) {}
int Fecha::dia() {return this->dia_;}
int Fecha::mes() {return this->mes_;}

//Ejercicio 10
void Fecha::incrementar_dia() {
    int maxDias = dias_en_mes(this->mes());
    if(this->dia() + 1 > maxDias) {
        this->dia_ = 1;
        this->mes_++;
        if(this->mes_ > 12) {
            this->mes_ = 1;
        }
    } else {
        this->dia_++;
    }
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return igual_dia && igual_mes;
}
#endif

// Ejercicio 11, 12

// Clase Horario
class Horario {
    public:
        Horario(uint hora, uint min);
        uint hora();
        uint min();
        bool operator<(Horario h);
    private:
        uint hora_;
        uint min_;
};
Horario::Horario(uint hora, uint min) : hora_(hora), min_(min) {}
uint Horario::hora() {return this->hora_;}
uint Horario::min() {return this->min_;}

//Ejercicio 12
bool Horario::operator<(Horario h) {
    int difHora = this->hora() - h.hora();
    int difMin = this->min() - h.min();

    return difHora < 0 || (difHora == 0 && difMin < 0);

}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}

// Ejercicio 13

// Clase Recordatorio
class Recordatorio {
public:
    Recordatorio(Fecha f, Horario h, string msg);
    Fecha fecha();
    Horario horario();
    string msg();

private:
    Fecha f_;
    Horario h_;
    string msg_;
};
Recordatorio::Recordatorio(Fecha f, Horario h, string msg) : f_(f), h_(h), msg_(msg) {}
Fecha Recordatorio::fecha() {return this->f_;}
Horario Recordatorio::horario() {return this->h_;}
string Recordatorio::msg() {return this->msg_;}

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.msg() << " @ " << r.fecha() << " " << r.horario();
    return os;
}

// Ejercicio 14

// Clase Agenda



class Agenda {
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    vector<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();

private:
    vector<Recordatorio> recs_;
    Fecha f_;
};

Agenda::Agenda(Fecha fecha_inicial) : f_(fecha_inicial), recs_(vector<Recordatorio>{}) {}
Fecha Agenda::hoy() {return this->f_;}
void Agenda::incrementar_dia() {this->f_.incrementar_dia();}
void Agenda::agregar_recordatorio(Recordatorio rec) {recs_.push_back(rec);}

vector<Recordatorio> Agenda::recordatorios_de_hoy() {
    vector<Recordatorio> recsDeHoy = vector<Recordatorio>{};
    for(Recordatorio r : recs_) {
        if(r.fecha() == hoy()) {
            recsDeHoy.push_back(r);
        }
    }
    sort(recsDeHoy.begin(), recsDeHoy.end(), [](Recordatorio a, Recordatorio b) {
        return a.horario() < b.horario();
    });

    return recsDeHoy;
}

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy() << endl;
    os << "=====" << endl;
    for(Recordatorio r : a.recordatorios_de_hoy()) {
        os << r << endl;;
    }

    return os;
}

