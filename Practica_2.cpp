#include <iostream>
using namespace std;

const int MAX_N = 5;

//llenar matriz
void llenarMatriz(int matriz[MAX_N][MAX_N], int n) {
    cout << "Ingrese los elementos de la Matriz " << n << ":" << endl;
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            cout << "Matriz " << n << "[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

//imprimir matrices NxN
void imprimirMatriz(int matriz[MAX_N][MAX_N]) {
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

//sumar N matrices compatibles
void sumarMatrices(int matrices[][MAX_N][MAX_N], int n, int resultado[MAX_N][MAX_N]) {
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            resultado[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                resultado[i][j] += matrices[k][i][j];
            }
        }
    }
}

//multiplicar dos matrices
void multiplicarMatrices(int matrizA[MAX_N][MAX_N], int matrizB[MAX_N][MAX_N], int resultado[MAX_N][MAX_N]) {
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            resultado[i][j] = 0;
            for (int k = 0; k < MAX_N; ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

//calcular la traspuesta de una matriz
void calcularTraspuesta(int matriz[MAX_N][MAX_N], int resultado[MAX_N][MAX_N]) {
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            resultado[j][i] = matriz[i][j];
        }
    }
}

//verificar si una matriz cuadrada es simétrica
bool esSimetrica(int matriz[MAX_N][MAX_N]) {
    int traspuesta[MAX_N][MAX_N];
    calcularTraspuesta(matriz, traspuesta);

    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            if (matriz[i][j] != traspuesta[i][j]) {
                return false;
            }
        }
    }
    return true;
}

//rotar una matriz 90 grados en sentido horario
void rotarMatriz90Grados(int matriz[MAX_N][MAX_N]) {
    int matrizRotada[MAX_N][MAX_N];
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            matrizRotada[i][j] = matriz[MAX_N - 1 - j][i];
        }
    }

    // Copiar la matriz rotada de vuelta a la original
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            matriz[i][j] = matrizRotada[i][j];
        }
    }
}

//calcular la suma de los elementos en la diagonal principal de una matriz cuadrada
int sumaDiagonalPrincipal(int matriz[MAX_N][MAX_N]) {
    int suma = 0;
    for (int i = 0; i < MAX_N; ++i) {
        suma += matriz[i][i];
    }
    return suma;
}

//verificar si una matriz cuadrada es una matriz identidad
bool esMatrizIdentidad(int matriz[MAX_N][MAX_N]) {
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            if ((i == j && matriz[i][j] != 1) || (i != j && matriz[i][j] != 0)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Pruebas de los procedimientos y funciones
    int matrizA[MAX_N][MAX_N], matrizB[MAX_N][MAX_N], matrizC[MAX_N][MAX_N],
        matrizD[MAX_N][MAX_N], matrizE[MAX_N][MAX_N];

    llenarMatriz(matrizA, 1);
    cout << "Matriz A:" << endl;
    imprimirMatriz(matrizA);

    llenarMatriz(matrizB, 2);
    cout << "Matriz B:" << endl;
    imprimirMatriz(matrizB);

    llenarMatriz(matrizC, 3);
    cout << "Matriz C:" << endl;
    imprimirMatriz(matrizC);

    llenarMatriz(matrizD, 4);
    cout << "Matriz D:" << endl;
    imprimirMatriz(matrizD);

    llenarMatriz(matrizE, 5);
    cout << "Matriz E:" << endl;
    imprimirMatriz(matrizE);

    int resultadoSuma[MAX_N][MAX_N];
    int matricesSuma[3][MAX_N][MAX_N];
    for (int i = 0; i < 3; ++i) {
        llenarMatriz(matricesSuma[i], i + 1);
    }
    sumarMatrices(matricesSuma, 3, resultadoSuma);
    cout << "Matriz Resultado de la Suma:" << endl;
    imprimirMatriz(resultadoSuma);

    int matrizResultadoMultiplicacion[MAX_N][MAX_N];
    int matrizMultiplicacionA[MAX_N][MAX_N], matrizMultiplicacionB[MAX_N][MAX_N];
    
    llenarMatriz(matrizMultiplicacionA, 1);
    llenarMatriz(matrizMultiplicacionB, 2);

    multiplicarMatrices(matrizMultiplicacionA, matrizMultiplicacionB, matrizResultadoMultiplicacion);
    cout << "Matriz Resultado de la Multiplicación:" << endl;
    imprimirMatriz(matrizResultadoMultiplicacion);

    int matrizTraspuesta[MAX_N][MAX_N];
    llenarMatriz(matrizTraspuesta, 1);
    int matrizTraspuestaResultado[MAX_N][MAX_N];
    calcularTraspuesta(matrizTraspuesta, matrizTraspuestaResultado);
    cout << "Matriz Traspuesta:" << endl;
    imprimirMatriz(matrizTraspuestaResultado);

    int matrizSimetrica[MAX_N][MAX_N];
    llenarMatriz(matrizSimetrica, 1);
    cout << "¿La Matriz es Simétrica? " << (esSimetrica(matrizSimetrica) ? "Sí" : "No") << endl;

    int matrizRotada[MAX_N][MAX_N];
    llenarMatriz(matrizRotada, 1);
    cout << "Matriz Original:" << endl;
    imprimirMatriz(matrizRotada);
    rotarMatriz90Grados(matrizRotada);
    cout << "Matriz Rotada 90 Grados:" << endl;
    imprimirMatriz(matrizRotada);

    int matrizIdentidad[MAX_N][MAX_N];
    llenarMatriz(matrizIdentidad, 1);
    cout << "¿La Matriz es Identidad? " << (esMatrizIdentidad(matrizIdentidad) ? "Sí" : "No") << endl;

    cout << "Suma Diagonal Principal de la Matriz Identidad: " << sumaDiagonalPrincipal(matrizIdentidad) << endl;

    return 0;
}