#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res;
    for(int i = 0; i<s.size(); i++) {
        bool pertenece = false;
        for(int j=0;j<res.size() && !pertenece; j++) {
            if(res[j] == s[i]) {
                pertenece = true;
            }
        }
        if(!pertenece) {
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> res;
    set<int> vistos;
    for(int i = 0; i < s.size() ; i++) {
        auto found = vistos.find(s[i]);
        if(found == vistos.end()) {
            res.push_back(s[i]);
        }
        vistos.insert(s[i]);
    }
    return res;

}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> elemsA;
    set<int> elemsB;
    for(int & i : a) {
        elemsA.insert(i);
    }
    for(int & i : b) {
        elemsB.insert(i);
    }
    bool sonIguales = true;

    auto itA = elemsA.begin();
    while(itA != elemsA.end() && sonIguales) {
        auto itB = elemsB.begin();
        bool found = false;
        while (itB != elemsB.end() && !found) {
            if((*itA) == (*itB)) {
                found = true;
            }
            itB++;
        }
        sonIguales = found;
        itA++;
    }
    return sonIguales;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    //como lo hice con sets..reutilizo la solución anterior
    return mismos_elementos(a,b);
}


int cuantasVecesEsta(int a, vector<int> s) {
    int count = 0;
    for(int &elem: s) {
        if(elem == a) {
            count++;
        }
    }
    return count;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> apariciones;
    for(auto &ele: s) {
        apariciones.insert(pair<int, int>{ele, cuantasVecesEsta(ele, s)});
    }
    return apariciones;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    map<int, int> apariciones = contar_apariciones(s);
    vector<int> res;
    for(pair<int, int> apa : apariciones) {
        if(apa.second == 1) {
            res.push_back(apa.first);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> intersec;
    for(int elemA: a) {
        if(b.find(elemA) != b.end()) {
            intersec.insert(elemA);
        }
    }
    return intersec;
}

int dameUnidad(int i) {
    return i % 10;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> agrupUni;
    //inicializo el mapa.
    for(int i = 0; i < 10; i++) {
        agrupUni.insert(pair<int, set<int>>{i, set<int>()});
    }
    for(int &elem : s) {
        int uni = dameUnidad(elem);
        agrupUni.find(uni)->second.insert(elem);
    }
    //elimino grupos vacios
    for(int i = 0; i < 10; i++) {
        if(agrupUni.find(i)->second.size() == 0) {
            agrupUni.erase(i);
        }
    }
    return agrupUni;
}


map<char, char> armarDict(vector<pair<char, char>> tr) {
    map<char, char> dic;
    for(pair<char, char> t : tr) {
        dic.insert(t);
    }
    return dic;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    map<char, char> dict = armarDict(tr);
    vector<char> res;
    for(char &s : str) {
        auto traducido = dict.find(s);
        if(traducido == dict.end()) {
            res.push_back(s);
        } else {
            res.push_back(traducido->second);
        }
    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    map<LU, int> dictLibretaGrupo;
    map<int, set<LU>> grupos;
    bool repetidos = false;
    int grupoIdx = 1;
    for(Mail mail : s) {
        set<LU> miembros = mail.libretas();
        for(LU m : miembros) {
            if(dictLibretaGrupo.find(m) == dictLibretaGrupo.end()) {
                //creo el grupo
                grupos.insert(pair<int, set<LU>>{grupoIdx, miembros});
                for(LU e: miembros) {
                    // LU1, LU3, LU4
                    // LU2, LU3, LU4
                    //si algun miembro del nuevo grupo ya estaba en otro grupo..esta repetido.
                    //CUANDO CREO EL GRUPO DE LU1 lu3 y lu4 quedan asociados al grupo 1
                    //LUEGO LLEGA EL MAIL DE LU2 y al crear el grupo ..lu3 y lu4 quedarian repetidos en 2 grupos
                    if(dictLibretaGrupo.find(e) != dictLibretaGrupo.end()) {
                        repetidos = true;
                        break;
                    }
                    dictLibretaGrupo.insert(pair<LU, int>{e, grupoIdx});
                }
            } else {
                int grupo = dictLibretaGrupo.find(m)->second;
                set<LU> equipo = grupos.find(grupo)->second;
                //chequeo la doble inclusion de los miembros del asunto del mail y el equipo asociado a una libreta.
                for(LU e: miembros) {
                    if(equipo.find(e) == equipo.end()) {
                        repetidos = true;
                        break;
                    }
                }
                for(LU e: equipo) {
                    if(miembros.find(e) == miembros.end()) {
                        repetidos = true;
                        break;
                    }
                }
            }
        }
        grupoIdx++;
    }
    return repetidos;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<LU, int> dictLibretaGrupo;
    map<int, set<LU>> grupos;
    map<int, Mail> entregaFinalDelGrupo;
    map<set<LU>, Mail> entregaFinal;

    assert(!integrantes_repetidos(s));

    int grupoIdx = 1;
    for(Mail mail : s) {
        set<LU> miembros = mail.libretas();
        for (LU m : miembros) {
            if (dictLibretaGrupo.find(m) == dictLibretaGrupo.end()) {
                //creo el grupo
                grupos.insert(pair<int, set<LU>>{grupoIdx, miembros});
                for (LU e: miembros) {
                    //agrego los miembre del mail al mismo grupo
                    dictLibretaGrupo.insert(pair<LU, int>{e, grupoIdx});
                }
                //agrego el mail como la entrega final
                if (mail.adjunto()) {
                    entregaFinalDelGrupo.insert(pair<int, Mail>{grupoIdx, mail});
                }
            } else {
                //no es la primer entrega de un grupo.
                int grupoId = dictLibretaGrupo.find(m)->second;
                if (mail.adjunto()) {
                    //si el mail tiene adjunto. Me fijo si es mayor al ultimo registrado
                    if (entregaFinalDelGrupo.find(grupoId) == entregaFinalDelGrupo.end()) {
                        //es la primer entrega del grupo con adjunto
                        entregaFinalDelGrupo.insert(pair<int, Mail>{grupoId, mail});
                    } else {
                        //si es una entrega con adjunto y es mas reciente que la registrada. Actualizao las entregas.
                        entregaFinalDelGrupo.erase(grupoId);
                        entregaFinalDelGrupo.insert(pair<int, Mail>{grupoId, mail});
                    }
                }
            }
        }
        grupoIdx++;
    }

    for(pair<int, Mail> entrega: entregaFinalDelGrupo) {
        set<LU> miembros = grupos.find(entrega.first)->second;
        entregaFinal.insert(pair<set<LU>, Mail>{miembros, entrega.second});
    }


    return entregaFinal;
}
