#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int total = 54;
    int cartas[total], cont, opc;
    bool kontinue;
    for (int i = 0; i < total; i++) {
        cartas[i] = i + 1;
    }

    srand(time(0));

    for (int i = total - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(cartas[i], cartas[j]);
    }

    // TABLA
    cout << "TABLA:\n";
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            cout << "\n";
        }
        cout << cartas[i] << "  ";
        if (cartas[i] < 10) {
            cout << " ";
        }

    }

    cout << "\n\n";
    for (int i = total - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(cartas[i], cartas[j]);
    }

    // CARTAS
    kontinue = true;
    do {
        cout << "\nMANO: ";
        for (int i = 0; i < 6; i++) {
            cout << cartas[i] << " ";
        } cout << "\n\nQue quieres hacer?\n1.Jugar mano\n2.Eliminar carta\n3.Terminar\n";
        cin >> opc;

        switch (opc) {
            case 1:
                break;
            case 2:
                int del, DescardR;
                del = 0;
                DescardR = 5;
                do {
                    cout << "\nMANO: ";
                    for (int i = 0; i < 6; i++) {
                        //CAMBIO
                        if (cartas[i] == cartas[del - 1]) {
                                int nuevo, min = 1, max = 54;
                                bool repetido;
                                do {
                                    nuevo = rand() % (max - min + 1) + min;

                                    // Verificar si ya está en la mano
                                    repetido = false;
                                    for (int i = 0; i < 6; i++) {
                                        if (cartas[i] == nuevo) {
                                            repetido = true;
                                            break;
                                        }
                                    }
                                } while (repetido == true);
                                cartas[i] = nuevo;
                        }
                            cout << cartas[i] << " ";
                    }

                    cout << "\nDescartes restantes: " << DescardR << "\n\nQue carta desea eliminar? <negativo para salir> ";
                    cin >> del;

                    if (del > 0) {
                        DescardR--;
                    }

                    cout << "\n";
                } while (del > 0 && DescardR > 0);




                break;
            case 3:
                kontinue = false;
                break;
        }

    } while (kontinue == true);












    //Reimprimir
    cout << "MANO FINAL: ";
    for (int i = 0; i < 6; i++) {
            cout << cartas[i] << " ";
    } cout << "\n";

    return 0;
}
