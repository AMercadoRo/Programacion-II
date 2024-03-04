#include <iostream>
using namespace std;

// Funciones y procedimientos del ejercicio 1
int* crearVector(int N) {
    return new int[N];
}

void imprimirVector(int* vec, int N) {
    cout << "Vector: [";
    for (int i = 0; i < N; ++i) {
        cout << vec[i];
        if (i < N - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

bool ascendente(int a, int b) {
    return a < b;
}

bool descendente(int a, int b) {
    return a > b;
}

void ordenar(int* vec, int N, bool (*comparador)(int, int)) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (comparador(vec[j], vec[j + 1])) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// Funciones y procedimientos del ejercicio 2
int* fusionar(int* A, int* B, int NA, int NB, int& size) {
    int* res = new int[NA + NB];
    int i = 0, j = 0, k = 0;

    while (i < NA && j < NB) {
        if (A[i] < B[j]) {
            res[k++] = A[i++];
        } else {
            res[k++] = B[j++];
        }
    }

    while (i < NA) {
        res[k++] = A[i++];
    }

    while (j < NB) {
        res[k++] = B[j++];
    }

    size = k;
    return res;
}

// Funciones y procedimientos del ejercicio 3
int* noComunes(int* A, int* B, int NA, int NB, int& size) {
    int* res = crearVector(NA);
    size = 0;

    for (int i = 0; i < NA; ++i) {
        bool encontrado = false;
        for (int j = 0; j < NB; ++j) {
            if (A[i] == B[j]) {
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            res[size++] = A[i];
        }
    }

    return res;
}

// Funciones y procedimientos del ejercicio 4 y 5
int** crearMatriz(int N, int M) {
    int** mat = new int*[N];
    for (int i = 0; i < N; ++i) {
        mat[i] = new int[M];
    }
    return mat;
}

void llenarMatrizSecuencia(int** mat, int N, int M) {
    int count = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j <= i) {
                mat[i][j] = count++;
            } else {
                mat[i][j] = 0;
            }
        }
    }
}

// Funciones y procedimientos del ejercicio 6
char** crearMatrizChar(int N) {
    char** mat = new char*[N];
    for (int i = 0; i < N; ++i) {
        mat[i] = new char[N];
    }
    return mat;
}

void llenarMatrizSecuenciaChar(char** mat, int N) {
    char letra = 'a';
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            mat[i][j] = letra++;
        }
    }
}

int main() {
    // Ejercicio 1: Ordenar Vector
    int N;
    cout << "Ingrese tamaño del vector: ";
    cin >> N;

    int* vec = crearVector(N);

    // Ingresar elementos del vector manualmente
    cout << "Ingrese " << N << " elementos para el vector:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vec[i];
    }

    cout << "Seleccione orden (1: Ascendente, 2: Descendente): ";
    int opcion;
    cin >> opcion;

    if (opcion == 1) {
        ordenar(vec, N, ascendente);
    } else if (opcion == 2) {
        ordenar(vec, N, descendente);
    } else {
        cout << "Opción no válida." << endl;
    }

    imprimirVector(vec, N);
    delete[] vec;

    // Ejercicio 2: Fusionar Vectores Ordenados
    int NA, NB;

    cout << "Ingrese tamaño del primer vector: ";
    cin >> NA;
    int* A = crearVector(NA);

    cout << "Ingrese " << NA << " elementos para el primer vector:" << endl;
    for (int i = 0; i < NA; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> A[i];
    }

    cout << "Ingrese tamaño del segundo vector: ";
    cin >> NB;
    int* B = crearVector(NB);

    cout << "Ingrese " << NB << " elementos para el segundo vector:" << endl;
    for (int i = 0; i < NB; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> B[i];
    }

    int sizeRes;
    int* res = fusionar(A, B, NA, NB, sizeRes);

    imprimirVector(res, sizeRes);
    delete[] A;
    delete[] B;
    delete[] res;

    // Ejercicio 3: Elementos No Comunes
    cout << "Ingrese tamaño del primer vector: ";
    cin >> NA;
    int* vecA = crearVector(NA);

    cout << "Ingrese " << NA << " elementos para el primer vector:" << endl;
    for (int i = 0; i < NA; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vecA[i];
    }

    cout << "Ingrese tamaño del segundo vector: ";
    cin >> NB;
    int* vecB = crearVector(NB);

    cout << "Ingrese " << NB << " elementos para el segundo vector:" << endl;
    for (int i = 0; i < NB; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vecB[i];
    }

    int sizeResNoComunes;
    int* resNoComunes = noComunes(vecA, vecB, NA, NB, sizeResNoComunes);

    imprimirVector(resNoComunes, sizeResNoComunes);
    delete[] vecA;
    delete[] vecB;
    delete[] resNoComunes;

    // Ejercicio 4: Llenar Matriz Secuencia
    cout << "Ingrese valor de N para la matriz: ";
    cin >> N;

    int** matSecuencia = crearMatriz(N, N);
    llenarMatrizSecuencia(matSecuencia, N, N);

    cout << "Matriz Secuencia:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matSecuencia[i][j] << "\t";
        }
        cout << endl;
    }

    // Liberar memoria de la matriz
    for (int i = 0; i < N; ++i) {
        delete[] matSecuencia[i];
    }
    delete[] matSecuencia;

    // Ejercicio 5: Llenar Matriz Secuencia (N impar)
    cout << "Ingrese valor de N para la matriz (impar): ";
    cin >> N;

    int** matSecuenciaImpar = crearMatriz(N, N);
    llenarMatrizSecuencia(matSecuenciaImpar, N, N);

    cout << "Matriz Secuencia (N impar):" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matSecuenciaImpar[i][j] << "\t";
        }
        cout << endl;
    }

    // Liberar memoria de la matriz
    for (int i = 0; i < N; ++i) {
        delete[] matSecuenciaImpar[i];
    }
    delete[] matSecuenciaImpar;

    // Ejercicio 6: Llenar Matriz Secuencia con ceros en el triángulo superior
    cout << "Ingrese valor de N para la matriz: ";
    cin >> N;

    int** matSecuenciaCeros = crearMatriz(N, N);
    llenarMatrizSecuencia(matSecuenciaCeros, N, N);

    cout << "Matriz Secuencia con ceros en el triángulo superior:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matSecuenciaCeros[i][j] << "\t";
        }
        cout << endl;
    }

    // Liberar memoria de la matriz
    for (int i = 0; i < N; ++i) {
        delete[] matSecuenciaCeros[i];
    }
    delete[] matSecuenciaCeros;

    // Ejercicio 7: Llenar Matriz Secuencia (triángulo inferior sin ceros)
    cout << "Ingrese valor de N para la matriz: ";
    cin >> N;

    int** matSecuenciaSinCeros = crearMatriz(N, N);
    llenarMatrizSecuencia(matSecuenciaSinCeros, N, N);

    cout << "Matriz Secuencia (triángulo inferior sin ceros):" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matSecuenciaSinCeros[i][j] << "\t";
        }
        cout << endl;
    }

    // Liberar memoria de la matriz
    for (int i = 0; i < N; ++i) {
        delete[] matSecuenciaSinCeros[i];
    }
    delete[] matSecuenciaSinCeros;

    // Ejercicio 8: Llenar Matriz Secuencia con límite en M
    int M;
    cout << "Ingrese valor de N para la matriz: ";
    cin >> N;

    cout << "Ingrese valor de M (M < N): ";
    cin >> M;

    int** matSecuenciaLimite = crearMatriz(N, M);
    llenarMatrizSecuencia(matSecuenciaLimite, N, M);

    cout << "Matriz Secuencia con límite en M:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << matSecuenciaLimite[i][j] << "\t";
        }
        cout << endl;
    }

    // Liberar memoria de la matriz
    for (int i = 0; i < N; ++i) {
        delete[] matSecuenciaLimite[i];
    }
    delete[] matSecuenciaLimite;

    // Ejercicio 9: Llenar Matriz Secuencia con letras
    cout << "Ingrese valor de N para la matriz (impar): ";
    cin >> N;

    char** matSecuenciaLetras = crearMatrizChar(N);
    llenarMatrizSecuenciaChar(matSecuenciaLetras, N);

    cout << "Matriz Secuencia con letras:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << matSecuenciaLetras[i][j] << "\t";
        }
        cout << endl;
    }

    // Liberar memoria de la matriz
    for (int i = 0; i < N; ++i) {
        delete[] matSecuenciaLetras[i];
    }
    delete[] matSecuenciaLetras;

    return 0;
}