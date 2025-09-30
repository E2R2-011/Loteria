#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int total = 54, totalTablas = 16;
    int cartas[total], tabla[totalTablas], cont, opc, HandN = 7;
    bool kontinue;
    for (int i = 0; i < total; i++) {
        tabla[i] = i + 1;
    }

    srand(time(0));

    for (int i = total - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(tabla[i], tabla[j]);
    }

    // TABLA
    cout << "=============================================================\n     TABLA:\n   ";
    for (int i = 0; i < totalTablas; i++) {
        if (i % 4 == 0 && i > 0) {
            cout << "\n   ";
        }
        cout << tabla[i] << "  ";
        if (tabla[i] < 10) {
            cout << " ";
        }
    }






    cout << "\n\n";
    for (int i = 0; i < total; i++) {
        cartas[i] = i + 1;
    }
    for (int i = total - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(cartas[i], cartas[j]);
    }

    // CARTAS
    kontinue = true;
    static int DescardR = 5;
    do {
        cout << "\n=============================================================\nMANO ACTUAL: ";
        for (int i = 0; i < HandN; i++) {
            cout << "(" << i+1 << ")" << cartas[i] << "  ";
        }
        cout << "\n=============================================================\n";
        cout << "\n\nQue quieres hacer?\n\n1.Jugar mano\n2.Eliminar carta\n3.Terminar\n\nIngrese la opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                break;
            case 2: {
            static int DescardR = 5;
            int del, deleteCards;
            if (DescardR <= 0) {
            cout << "\nYa no tienes descartes disponibles\n";
                break;
            }
            do {
                cout << "Cuantos numeros quiere eliminar? ";
                cin >> deleteCards;
                if (deleteCards < 1 || deleteCards > HandN) {
                    cout << "\n ! Opcion invalida\n\n";
                }
            } while (deleteCards < 1 || deleteCards > HandN);

            cout << "\nQue cartas deseas eliminar? (1 - " << HandN << ", negativo para salir): ";

            for (int i = 0; i<deleteCards; i++) {

                    //
                    do {
                        cin >> del;
                        if (del <= 0 || del > HandN) {
                            cout << "\n ! Opcion invalida\n\nQue cartas deseas eliminar? (1 - " << HandN << ", negativo para salir): ";
                        }
                    } while (del <= 0 || del > HandN);

                        for (int i = 0; i < HandN; i++) {
                            if (cartas[i] == cartas[del - 1]) {
                                    int nuevo, min = 1, max = 54;
                                    bool repetido;
                                    do {
                                        nuevo = rand() % (max - min + 1) + min;
                                        repetido = false;
                                        for (int i = 0; i < HandN; i++) {
                                            if (cartas[i] == nuevo) {
                                                repetido = true;
                                                break;
                                            }
                                        }
                                    } while (repetido == true);
                                cartas[i] = nuevo;
                            }
                        }
            }
            if (del >= 1 && del <= HandN) {
                DescardR--;
            }
            cout << "\nDescartes restantes: " << DescardR << "\n";

                break;
            }

            case 3:
                kontinue = false;
                break;
        }

    } while (kontinue == true);

    return 0;
}
