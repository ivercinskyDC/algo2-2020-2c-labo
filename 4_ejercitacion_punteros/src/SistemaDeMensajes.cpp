#include <assert.h>
#include "SistemaDeMensajes.h"

// Completar...
SistemaDeMensajes::SistemaDeMensajes() {
    for(int i=0; i<4; i++) {
        _conns[i] = nullptr;
    }
}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    if(_conns[id] == nullptr) {
        _conns[id] = new ConexionJugador(ip);
    } else {
        desregistrarJugador(id);
        _conns[id] = new ConexionJugador(ip);
    }
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    if(_conns[id] != nullptr) {
        _conns[id]->enviarMensaje(mensaje);
    }
}

string SistemaDeMensajes::ipJugador(int id) const {
    assert(_conns[id] != nullptr);
    return _conns[id]->ip();
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;

}

void SistemaDeMensajes::desregistrarJugador(int id) {
    delete _conns[id];
    _conns[id] = nullptr;
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for(int i=0; i<4;i++) {
        delete _conns[i];
        _conns[i] = nullptr;
    }
    for (Proxy * p : _proxies) {
        delete p;
    }
}

Proxy * SistemaDeMensajes::obtenerProxy(int id) {
    Proxy* proxy =  new Proxy(&(_conns[id]));
    _proxies.push_back(proxy);
    return proxy;
}