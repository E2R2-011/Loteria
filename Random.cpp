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
    cout << "     TABLA:\n   ";
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
        cout << "\nMANO ACTUAL: ";
        for (int i = 0; i < HandN; i++) {
            cout << cartas[i] << "  ";
        }

        cout << "\n\nQue quieres hacer?\n1.Jugar mano\n2.Eliminar carta\n3.Terminar\n";
        cin >> opc;

        switch (opc) {
            case 1:
                break;
            case 2: {
            static int DescardR = 5;
            int del;
            if (DescardR <= 0) {
            cout << "\nYa no tienes descartes disponibles\n";
                break;
            }
                do {
                    cout << "\nDescartes restantes: " << DescardR << "\n\nQue carta deseas eliminar? (1-6, negativo para salir): ";
                    cin >> del;

                    if (del < 0) break; // salir del descarte
                    if (del < 1 || del > HandN) {
                        cout << "\nOpcion invalida\n";
                    }

                    if (del > 0 && del >= 1 && del <= HandN) {
                        DescardR--;
                    }

                    if (DescardR > 0) {cout << "\nNUEVA MANO: ";}

                        for (int i = 0; i < HandN; i++) {
                            //CAMBIO
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
                            if (DescardR > 0) {cout << cartas[i] << "  ";}

                        }


                } while (del > 0 && DescardR > 0);
                /*cout << "\nNUEVA MANO: ";
                for (int i = 0; i<HandN; i++) {
                    cout << cartas[i] << "  ";
                }*/

                break;
            }

            case 3:
                kontinue = false;
                break;
        }

    } while (kontinue == true);


    //Reimprimir
    cout << "MANO FINAL: ";
    for (int i = 0; i < HandN; i++) {
            cout << cartas[i] << " ";
    } cout << "\n";

    return 0;
}
