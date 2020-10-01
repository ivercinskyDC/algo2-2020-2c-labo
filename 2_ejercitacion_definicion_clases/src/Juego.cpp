#include <utility>

using namespace std;

// Ejercicio 15

// Juego

using Pos = pair<int, int>;

const char ARRIBA = '^';
const char ABAJO = 'v';
const char DERECHA = '<';
const char IZQUIERDA = '>';

class Juego {
  // Completar
public:
  Juego(uint casilleros, Pos pos_inicial);
  Pos posicion_jugador();
  uint turno_actual();
  void mover_jugador(char dir);
  void ingerir_pocion(uint movimientos, uint turnos);

private:
    uint _casilleros;
    Pos _posicionActual;
    uint _turno;
    uint _turnoPocionRestantes;
    uint _movimientosPorTurnoPocionRestantes;
};

Juego::Juego(uint casilleros, Pos pos_inicial) :
    _casilleros(casilleros),
    _posicionActual(pos_inicial),
    _turnoPocionRestantes(0),
    _movimientosPorTurnoPocionRestantes(0),
    _turno(0) {}

void Juego::mover_jugador(char dir) {
    uint x, y;
    switch (dir) {
        case ARRIBA:
            x = -1; y = 0;
            break;
        case ABAJO:
            x = 1; y = 0;
            break;
        case DERECHA:
            x = 0; y = 1;
            break;
        case IZQUIERDA:
            x = 0; y = -1;
            break;
    }
    Pos posActual = posicion_jugador();
    if(posActual.first + x > _casilleros - 1) {
        return;
    }
    if (posActual.second + y > _casilleros -1 ) {
        return;
    }
    _posicionActual.first = _posicionActual.first + x;
    _posicionActual.second = _posicionActual.second + y;
    if(_movimientosPorTurnoPocionRestantes > 1 && _turnoPocionRestantes > 1) {
        _movimientosPorTurnoPocionRestantes--;
    } else {
        _turno++;
        _turnoPocionRestantes--;
    }


}

Pos Juego::posicion_jugador() {
    return _posicionActual;
}
uint Juego::turno_actual() {
    return _turno;
}
void Juego::ingerir_pocion(uint movimientos, uint turnos) {
    _turnoPocionRestantes += turnos;
    _movimientosPorTurnoPocionRestantes += movimientos;
}
