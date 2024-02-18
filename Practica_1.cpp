#include <iostream>
using namespace std;

bool esPerfecto(int num)
{
    int suma = 0;
    for (int i = 1; i <= num / 2; ++i)
    {
        if (num % i == 0)
        {
            suma += i;
        }
    }
    return suma == num;
}

int suma(int arr[], int size)
{
    int suma = 0;
    for (int i = 0; i < size; ++i)
    {
        suma += arr[i];
    }
    return suma;
}

float promedio(int arr[], int size)
{
    if (size == 0)
    {
        return 0.0;
    }
    return static_cast<float>(suma(arr, size)) / size;
}

void invertir(int arr[], int size, int arrInvertido[])
{
    for (int i = size - 1, j = 0; i >= 0; --i, ++j)
    {
        arrInvertido[j] = arr[i];
    }
}

int buscarElemento(int arr[], int size, int elemento)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == elemento)
        {
            return i;
        }
    }
    return -1;
}

int encontrarMenor(int arr[], int size)
{
    if (size == 0)
    {
        return -1;
    }
    int menor = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < menor)
        {
            menor = arr[i];
        }
    }
    return menor;
}

int main()
{
    cout << esPerfecto(6) << endl;
    int arrEjemplo[] = {1, 2, 3, 4, 5};
    int tamanoArr = sizeof(arrEjemplo) / sizeof(arrEjemplo[0]);

    cout << suma(arrEjemplo, tamanoArr) << endl;
    cout << promedio(arrEjemplo, tamanoArr) << endl;

    int arrInvertido[tamanoArr];
    invertir(arrEjemplo, tamanoArr, arrInvertido);
    for (int i = 0; i < tamanoArr; ++i)
    {
        cout << arrInvertido[i] << " ";
    }
    cout << endl;

    cout << buscarElemento(arrEjemplo, tamanoArr, 3) << endl;
    cout << encontrarMenor(arrEjemplo, tamanoArr) << endl;

    return 0;
}