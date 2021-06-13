#include "router.h"

bool router::agregarEnrutador(char nom, int cost) //Esta función permite añadir un enrutador
{
    bool ban=false;
    if(ruter.find(nom)==ruter.end()){
        ruter.insert(pair<char,int>(nom,cost));
        ban=true;
    }
    return ban;
}

bool router::modificarEnrutador(char nom, int cost) //Esta funcion permite modificar el costo de un enrutador (enlace)
{
    bool ban=false;
    if(ruter.find(nom)!=ruter.end()){
        ruter[nom]=cost;
        ban=true;
    }
    return ban;
}

bool router::eliminarEnrutador(char nom) //Esta funcion permite eliminar un enrutador
{
    bool ban=false;
    if(ruter.find(nom)!=ruter.end()){
        ruter.erase(nom);
        ban=true;
    }
    return ban;
}

void router::imprimirTablaEnrutador() //Esta funcion permite imprimir la tabla de enrutamiento de un enrutador
{
    cout << "\t";
    for(itR=ruter.begin(); itR!=ruter.end(); itR++){
        cout << itR->first << "\t";
    }
    cout << endl;
    cout <<"\t";
    for(itR=ruter.begin(); itR!=ruter.end(); itR++){
        cout << itR->second << "\t";
    }
    cout << endl;
}

int router::costo(char name) //Esta funcion permite ver el costo
{
    return ruter[name];
}


