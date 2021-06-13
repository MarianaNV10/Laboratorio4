#include <network.h>

int main()
{
    unsigned int op, opp;
    bool bandera=true, banE=true, banR=true;
    network Netw;

    while(bandera){
        cout << "\tMENU PRINCIPAL..." << endl;
        cout << "1. Enrutador" << endl;
        cout << "2. Red" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese la opcion a realizar: ";
        cin >> opp;
        system("CLS");
        switch (opp) {
            case 1: //Enrutador
                while(banE){
                    cout << "\tMENU ENRUTADOR..." << endl;
                    cout << "1. Agregar enrutador" << endl;
                    cout << "2. Eliminar enrutador" << endl;
                    cout << "3. Imprimir la tabla de un enrutador" << endl;
                    cout << "4. Mostrar Enrutadores existentes" << endl;
                    cout << "5. Salir" << endl;
                    cout << "Digite la opcion a realizar: ";
                    cin >> op;
                    system("CLS");
                    switch (op) {
                        case 1:{ //agregar ruter
                            char Nom;
                            cout << "Ingrese el nombre del enrutador: ";
                            cin >> Nom;
                            Netw.agregarRuter(Nom);
                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        case 2:{ //eliminar ruter
                            char Nmb;
                            cout << "Ingrese el nombre del enrutador: ";
                            cin >> Nmb;
                            Netw.eliminarRuter(Nmb);
                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        case 3:{ //tabla enrutamiento
                            char nom;
                            cout << "Digite el nombre del enrutador: ";
                            cin >> nom;
                            Netw.imprimirRuter(nom);
                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        case 4: //Mostrar los enrutadores
                            Netw.mostrarEnrutadores();
                            system("PAUSE");
                            system("CLS");
                            break;

                        case 5: //salir
                            banE=false;
                            system("CLS");
                            break;

                        default:
                            cout << "No se encontro la opcion ingresada. Digitela nuevamente" << endl;
                            system("PAUSE");
                            system("CLS");
                            break;
                    }
                }
                break;
            case 2: //red
                while(banR){
                    cout << "\tMENU DE LA RED..." << endl;
                    cout << "1. Agregar enlace a la red" << endl;
                    cout << "2. Eliminar enlace de la red" << endl;
                    cout << "3. Matriz de Adyacencia" << endl;
                    cout << "4. Leer Red" << endl;
                    cout << "5. Red aleatoria" << endl;
                    cout << "6. Camino mas corto" << endl;
                    cout << "7. Mostrar enrutadores existentes" << endl;
                    cout << "8. Salir" << endl;
                    cout << "Ingrese la opcion: ";
                    cin >> op;
                    system("CLS");

                    switch (op) {
                        case 1:{ //agregar enlace
                            char nom1, nom2;
                            int valor = 0;
                            do{
                                cout << "Digite el nombre del primer enrutador: ";
                                cin >> nom1;
                                cout << "Digite el nombre del segundo enrutador: ";
                                cin >> nom2;
                                if(nom1 == nom2) cout << "No se puede modificar el costo del enlace de un mismo nodo\n Por favor digitelos nuevamente" << endl;
                            }while(nom1==nom2);
                            do{
                                cout << "Ingrese el costo del enlace: ";
                                cin >> valor;
                                if(valor < 0) cout << "El costo del enlace debe ser un numero entero positivo" << endl;
                            }while(valor < 0);

                            Netw.agregarEnlace(nom1,nom2,valor);

                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        case 2:{ //eliminar enlace
                            char name1, name2;
                            do{
                                cout << "Digite el nombre del primer enrutador: ";
                                cin >> name1;
                                cout << "Digite el nombre del segundo enrutador: ";
                                cin >> name2;
                                if(name1 == name2) cout << "No se puede modificar el costo del enlace de un mismo nodo\n Por favor digitelos nuevamente" << endl;
                            }while(name1==name2);

                            Netw.eliminarEnlace(name1, name2);

                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        case 3:{ //matriz adyacencia
                            Netw.matrizadyacencia();
                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        case 4: //leer de un archivo la red ->Arreglarlo
                            Netw.leer();
                            system("PAUSE");
                            system("CLS");
                            break;
                        case 5: //Red aleatoria
                            Netw.red_aleatoria();
                            system("PAUSE");
                            system("CLS");
                            break;
                        case 6:{ //Camino mas corto
                            char Org, Dest;
                            cout << "Digite el enrutador de origen y el enrutador de destino: ";
                            cin >> Org >> Dest;
                            Netw.buscar_camino(Org, Dest);
                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        case 7: //Mostrar los enrutadores
                            Netw.mostrarEnrutadores();
                            system("PAUSE");
                            system("CLS");
                            break;
                        case 8: //salir
                            banR=false;
                            system("CLS");
                            break;

                        default:
                            cout << "No se encontro la opcion ingresada. Digitela nuevamente" << endl;
                            break;
                    }
                }
                break;
            case 3: //salir
                bandera=false;
                system("CLS");
                break;
            default:
                cout << "No se encontro la opcion ingresada. Digitela nuevamente" << endl;
                break;
        }
    }

    return 0;
}
