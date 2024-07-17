#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <cmath>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

#define CONTRA 123
#define TAM 15
using namespace std;
void Menu();
void CargaPues(int vec[]);
void ordenarPues(int vec[]);
int getRandomNumber();
bool isNumber(int n, int vec[], int tam);
void isNumberInCard(int n, int vec[]);
bool isBingo(int vec[]);
void Menujugar();
void imprimir(int vec[], int numCard);
void presentacion();
void generator();
int cosos[60], veca[TAM], vecc[TAM], vecb[TAM], vecd[TAM];
void buy(int num, int& i);
void Imprbol(int lim);
void verNumero(int numero);
void gotoxy(short x, short y);
void uno(int x, int y);
void cero(int x, int y);
void tres(int x, int y);
void dos(int x, int y);
void cuatro(int x, int y);
void cinco(int x, int y);
void seis(int x, int y);
void siete(int x, int y);
void ocho(int x, int y);
void nueve(int x, int y);
char Detective();
void Login();
int StartCredits();
int CRED = StartCredits();
void SaveGame();






int main()
{
    system("cls");
    srand(time(NULL));
    Login();
}

void Menu()
{
    system("cls");

    int opi;
    if (CRED > 0)
    {
        do
        {
            cout << "Creditos: " << CRED << endl;
            std::cout.width(15);
            cout << "Menu" << endl;
            cout << "***El coste de cada partida es de 2 creditos***" << endl << "***cada numero extra cuesta 1 credito***" << endl;
            cout << "1. Generar cartones" << endl;
            cout << "2. Jugar" << endl;
            cout << "0.Salir" << endl;
            cin >> opi;

            switch (opi)
            {
            case 1:
                for (int i = 0; i < TAM; i++)
                {
                    veca[i] = 0;
                }
                for (int i = 0; i < TAM; i++)
                {
                    vecb[i] = 0;
                }
                for (int i = 0; i < TAM; i++)
                {
                    vecc[i] = 0;
                }
                for (int i = 0; i < TAM; i++)
                {
                    vecd[i] = 0;
                }
                CargaPues(veca);
                CargaPues(vecb);
                CargaPues(vecc);
                CargaPues(vecd);

                ordenarPues(veca);
                ordenarPues(vecb);
                ordenarPues(vecc);
                ordenarPues(vecd);

                system("cls");

                imprimir(veca, 1);
                imprimir(vecb, 2);
                imprimir(vecc, 3);
                imprimir(vecd, 4);

                break;
            case 2:
                CRED = CRED - 2;
                Menujugar();
                break;
            default:

                break;
            }
        } while (opi != 0);
    }
    else
        cout << "Te quedaste sin creditos, no puedes jugar." << endl;
}

void Menujugar()
{
    int num, counter = 0;
    int WIN = 0;
    int i, lim = 0;
    bool bingo = false, FinPartida = false;
    bool NewBingo = false;
    bool banda = true, bandb = true, bandc = true, bandd = true;
    generator();
    COORD pos = { 0, 50 };
    for (i = 0; i < 30; i++)
    {
        system("cls");
        isNumberInCard(cosos[i], veca);
        isNumberInCard(cosos[i], vecb);
        isNumberInCard(cosos[i], vecc);
        isNumberInCard(cosos[i], vecd);

        imprimir(veca, 1);
        imprimir(vecb, 2);
        imprimir(vecc, 3);
        imprimir(vecd, 4);

        Imprbol(lim);
        verNumero(cosos[i]);
        lim++;
        cin.get();
    }
    do
    {

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        cout << "Creditos: " << CRED << endl;
        cout << endl << "desea comprar un nuevo numero?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cin >> num;
        if (num == 2)
            FinPartida = true;
        buy(num, i);

        isNumberInCard(num, veca);
        isNumberInCard(num, vecb);
        isNumberInCard(num, vecc);
        isNumberInCard(num, vecd);

        system("cls");

        imprimir(veca, 1);
        imprimir(vecb, 2);
        imprimir(vecc, 3);
        imprimir(vecd, 4);
        Imprbol(lim);
        verNumero(cosos[i]);
        if (num == 1)
            lim++;

        if (isBingo(veca) || isBingo(vecb) || isBingo(vecc) || isBingo(vecd))
        {
            if (counter < 4)
            {
                if (isBingo(veca) && banda == true)
                {
                    WIN++;
                    banda = false;
                    NewBingo = true;
                    counter++;
                }
                if (isBingo(vecb) && bandb == true)
                {
                    WIN++;
                    bandb = false;
                    NewBingo = true;
                    counter++;
                }
                if (isBingo(vecc) && bandc == true)
                {
                    WIN++;
                    bandc = false;
                    NewBingo = true;
                    counter++;
                }
                if (isBingo(vecd) && bandd == true)
                {
                    WIN++;
                    bandd = false;
                    NewBingo = true;
                    counter++;
                }
            }

            if (!banda && !bandb && !bandc && !bandd)
            {
                bingo = true;
                presentacion();
            }
            else
            {
                if (NewBingo == true)
                {
                    presentacion();
                    system("pause");
                    NewBingo = false;
                    CRED = CRED + 10;
                    cout << "GANAS 10 CREDITOS" << endl << "CREDITOS:" << CRED << endl;
                }
            }
        }
        if (CRED < 1)
        {
            FinPartida = true;
            cout << "TE QUEDASTE SIN CREDITOS" << endl;
        }

    } while (bingo == false && FinPartida == false);
    cout << "GUARDANDO..." << endl;
    SaveGame();
    system("pause");
}

void buy(int num, int& i)
{
    if (num == 1)
    {
        isNumberInCard(cosos[i], veca);
        isNumberInCard(cosos[i], vecb);
        isNumberInCard(cosos[i], vecc);
        isNumberInCard(cosos[i], vecd);
        i++;
        CRED--;
    }
    if (num == 2)
    {
        cout << "FIN DE LA PARTIDA" << endl << "Creditos:" << CRED << endl;
        cin.get();
    }
}

void CargaPues(int vec[])
{

    int numero, indi = 0;
    while (indi < TAM)
    {
        numero = getRandomNumber();
        if (!isNumber(numero, veca, TAM) && !isNumber(numero, vecb, TAM) && !isNumber(numero, vecc, TAM) && !isNumber(numero, vecd, TAM))
        {
            vec[indi] = numero;

            indi = indi + 1;
        }
    }
}


int getRandomNumber() //genera un numero random
{
    return 1 + rand() % (60 - 1 + 1);
}

bool isNumber(int n, int vec[], int tam) //verifica si el numero existe dentro del vector
{
    for (int i = 0; i < tam; i++)
    {
        if (n == vec[i])
            return true;
    }
    return false;
}

void isNumberInCard(int n, int vec[])
{
    for (int i = 0; i < TAM; i++)
    {
        if (n == vec[i])
        {
            vec[i] = vec[i] * -1;
        }
    }
}

bool isBingo(int vec[])
{
    int count = 0;
    //int num1, num2;
    for (int i = 0; i < TAM; i++)
    {
        if (vec[i] < 0)
        {
            count++;
        }
    }

    if (count == 15)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ordenarPues(int vec[]) //ordena y muestra el vector, ordenamiento tipo burbuja
{
    int temp;

    for (int i = 1; i < TAM; i++)
    {
        for (int j = 0; j < TAM - i; j++) // for(j=0; j < Nelementos-i; j++) es menor y no menor igual brow
        {
            if (vec[j] > vec[j + 1]) //Condicion mayor-menor
            {
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
    //mostrarimeCase(vec);
}

void imprimir(int vec[], int numCard)
{
    std::cout.width(15);
    std::cout << "carton " << numCard << endl
        << endl;
    cout << " | " << vec[0];
    cout << " | " << vec[3];
    cout << " | " << vec[6];
    cout << " | " << vec[9];
    cout << " | " << vec[12] << endl;
    cout << " | " << vec[1];
    cout << " | " << vec[4];
    cout << " | " << vec[7];
    cout << " | " << vec[10];
    cout << " | " << vec[13] << endl;
    cout << " | " << vec[2];
    cout << " | " << vec[5];
    cout << " | " << vec[8];
    cout << " | " << vec[11];
    cout << " | " << vec[14] << endl;
}

void presentacion()
{

    cout << " " << endl;
    cout << " " << endl;
    cout << "     ***************  *****************  *******        ****   *****************   ***************                " << endl;
    cout << "     **************** *****************  ********       ****   *****************  *****************               " << endl;
    cout << "     ***         ****       *****        **** ****      ****   ****         ****  *****       *****               " << endl;
    cout << "     ***         ****       *****        ****  ****     ****   ****         ****  ****         ****               " << endl;
    cout << "     ***         ***        *****        ****   ****    ****   ****         ****  ***           ***               " << endl;
    cout << "     ***************        *****        ****    ****   ****   *****************  ***           ***               " << endl;
    cout << "     ***************        *****        ****     ****  ****   *****************  ***           ***               " << endl;
    cout << "     ***         ****       *****        ****      **** ****                ****  ***           ***               " << endl;
    cout << "     ***         ****       *****        ****       ********                ****  ***           ***               " << endl;
    cout << "     ***         ****       *****        ****        *******   ****         ****  ****         ****               " << endl;
    cout << "     ***         ****       *****        ****         ******   ****         ****  *****       *****               " << endl;
    cout << "     **************** *****************  ****          *****   *****************  *****************               " << endl;
    cout << "     ***************  *****************  ****           ****   *****************   ***************                " << endl;
}
void generator()
{
    for (int i = 0; i < 60; i++)
    {
        int num = getRandomNumber();
        if (!isNumber(num, cosos, 60))
        {
            cosos[i] = num;
        }
        else
            i--;
    }
}

void Imprbol(int lim)
{
    cout << "===========NUMEROS YA GENERADOS============" << endl;
    for (int i = 0; i < lim; i++)
    {
        cout << cosos[i] << " ";
    }

}

///////////////////////////////
void gotoxy(short x, short y)
{
    system("color 03");
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void cero(int x, int y)
{


    cout << "                  " << endl; gotoxy(x + 50, y + 11);
    cout << "    **********    " << endl; gotoxy(x + 50, y + 12);
    cout << "    **********    " << endl; gotoxy(x + 50, y + 13);
    cout << "    ***    ***    " << endl; gotoxy(x + 50, y + 14);
    cout << "    ***    ***    " << endl; gotoxy(x + 50, y + 15);
    cout << "    ***    ***    " << endl; gotoxy(x + 50, y + 16);
    cout << "    ***    ***    " << endl; gotoxy(x + 50, y + 17);
    cout << "    ***    ***    " << endl; gotoxy(x + 50, y + 18);
    cout << "    ***    ***    " << endl; gotoxy(x + 50, y + 19);
    cout << "    **********    " << endl; gotoxy(x + 50, y + 20);
    cout << "    **********    " << endl; gotoxy(x + 50, y + 21);
    cout << "                  " << endl;
}
void uno(int x, int y)
{
    cout << "                  " << endl; gotoxy(x + 50, y + 11);
    cout << "      *****       " << endl; gotoxy(x + 50, y + 12);
    cout << "     ******       " << endl; gotoxy(x + 50, y + 13);
    cout << "    *******       " << endl; gotoxy(x + 50, y + 14);
    cout << "   ********       " << endl; gotoxy(x + 50, y + 15);
    cout << "  **** ****       " << endl; gotoxy(x + 50, y + 16);
    cout << " ****  ****       " << endl; gotoxy(x + 50, y + 17);
    cout << "       ****       " << endl; gotoxy(x + 50, y + 18);
    cout << "       ****       " << endl; gotoxy(x + 50, y + 19);
    cout << "       ****       " << endl; gotoxy(x + 50, y + 20);
    cout << "       ****       " << endl; gotoxy(x + 50, y + 21);
    cout << "                  " << endl;
}
void dos(int x, int y)
{
    cout << "                  " << endl; gotoxy(x + 50, y + 11);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 12);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 13);
    cout << "           ****   " << endl; gotoxy(x + 50, y + 14);
    cout << "           ****   " << endl; gotoxy(x + 50, y + 15);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 16);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 17);
    cout << "   ****           " << endl; gotoxy(x + 50, y + 18);
    cout << "   ****           " << endl; gotoxy(x + 50, y + 19);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 20);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 21);
    cout << "                  " << endl;
}
void tres(int x, int y)
{
    cout << "                  " << endl; gotoxy(x + 50, y + 11);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 12);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 13);
    cout << "           ****   " << endl; gotoxy(x + 50, y + 14);
    cout << "           ****   " << endl; gotoxy(x + 50, y + 15);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 16);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 17);
    cout << "           ****   " << endl; gotoxy(x + 50, y + 18);
    cout << "           ****   " << endl; gotoxy(x + 50, y + 19);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 20);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 21);
    cout << "                  " << endl;
}
void cuatro(int x, int y)
{
    cout << "                  " << endl; gotoxy(x + 50, y + 11);
    cout << "   ****    ****   " << endl; gotoxy(x + 50, y + 12);
    cout << "   ****    ****   " << endl; gotoxy(x + 50, y + 13);
    cout << "   ****    ****   " << endl; gotoxy(x + 50, y + 14);
    cout << "   ****    ****   " << endl; gotoxy(x + 50, y + 15);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 16);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 17);
    cout << "           ****   " << endl; gotoxy(x + 50, y + 18);
    cout << "           ****   " << endl; gotoxy(x + 50, y + 19);
    cout << "           ****   " << endl; gotoxy(x + 50, y + 20);
    cout << "           ****   " << endl; gotoxy(x + 50, y + 21);
    cout << "                  " << endl;
}
void cinco(int x, int y)
{
    cout << "                  " << endl; gotoxy(x + 50, y + 11);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 12);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 13);
    cout << "   ****           " << endl; gotoxy(x + 50, y + 14);
    cout << "   ****           " << endl; gotoxy(x + 50, y + 15);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 16);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 17);
    cout << "           ****   " << endl; gotoxy(x + 50, y + 18);
    cout << "           ****   " << endl; gotoxy(x + 50, y + 19);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 20);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 21);
    cout << "                  " << endl;
}
void seis(int x, int y)
{
    cout << "                  " << endl; gotoxy(x + 50, y + 11);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 12);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 13);
    cout << "   ****           " << endl; gotoxy(x + 50, y + 14);
    cout << "   ****           " << endl; gotoxy(x + 50, y + 15);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 16);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 17);
    cout << "   ****    ****   " << endl; gotoxy(x + 50, y + 18);
    cout << "   ****    ****   " << endl; gotoxy(x + 50, y + 19);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 20);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 21);
    cout << "                  " << endl;
}
void siete(int x, int y)
{
    cout << "                  " << endl; gotoxy(x + 50, y + 11);
    cout << "    ***********   " << endl; gotoxy(x + 50, y + 12);
    cout << "    ***********   " << endl; gotoxy(x + 50, y + 13);
    cout << "            ***   " << endl; gotoxy(x + 50, y + 14);
    cout << "            ***   " << endl; gotoxy(x + 50, y + 15);
    cout << "       ********   " << endl; gotoxy(x + 50, y + 16);
    cout << "       ********   " << endl; gotoxy(x + 50, y + 17);
    cout << "       ***        " << endl; gotoxy(x + 50, y + 18);
    cout << "       ***        " << endl; gotoxy(x + 50, y + 19);
    cout << "       ***        " << endl; gotoxy(x + 50, y + 20);
    cout << "       ***        " << endl; gotoxy(x + 50, y + 21);
    cout << "                  " << endl;
}
void ocho(int x, int y)
{
    cout << "                  " << endl; gotoxy(x + 50, y + 11);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 12);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 13);
    cout << "   ****    ****   " << endl; gotoxy(x + 50, y + 14);
    cout << "   ****    ****   " << endl; gotoxy(x + 50, y + 15);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 16);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 17);
    cout << "   ****    ****   " << endl; gotoxy(x + 50, y + 18);
    cout << "   ****    ****   " << endl; gotoxy(x + 50, y + 19);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 20);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 21);
    cout << "                  " << endl;
}
void nueve(int x, int y)
{
    cout << "                  " << endl; gotoxy(x + 50, y + 11);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 12);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 13);
    cout << "   ****    ****   " << endl; gotoxy(x + 50, y + 14);
    cout << "   ****    ****   " << endl; gotoxy(x + 50, y + 15);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 16);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 17);
    cout << "           ****   " << endl; gotoxy(x + 50, y + 18);
    cout << "           ****   " << endl; gotoxy(x + 50, y + 19);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 20);
    cout << "   ************   " << endl; gotoxy(x + 50, y + 21);
    cout << "                  " << endl;
}
void mostrarNumero(int numero, int x, int y)
{

    if (numero == 0) {
        cero(x, y);
    }
    if (numero == 1) {
        uno(x, y);
    }
    if (numero == 2) {
        dos(x, y);
    }
    if (numero == 3) {
        tres(x, y);
    }
    if (numero == 4) {
        cuatro(x, y);
    }
    if (numero == 5) {
        cinco(x, y);
    }
    if (numero == 6) {
        seis(x, y);
    }
    if (numero == 7) {
        siete(x, y);
    }
    if (numero == 8) {
        ocho(x, y);
    }
    if (numero == 9) {
        nueve(x, y);
    }

}
void verNumero(int numero)
{
    int x, y;
    if (numero < 10)
    {
        mostrarNumero(numero, 0, 0);
    }
    else
    {
        x = numero % 100 / 10;
        mostrarNumero(x, 0, 0);
        y = numero % 10;
        mostrarNumero(y, 15, 0);
    }
}

/////////////////////////////////////////////////////////////////

char Detective()
{
    int num, intentos = 0;
    char res;
    do
    {

        cout << "Ingrese la clave : " << endl;
        cin >> num;

        intentos++;


    } while (num != CONTRA && intentos < 3);

    if (num == CONTRA)
    {
        res = 's';
    }
    else
    {
        res = 'n';
    }

    return res;
}
void Login()
{
    ifstream fin;
    fin.open("usuario.txt", ios_base::in);
    int num;
    char cntr;
    fin.seekg(0, fin.beg);
    char cadena1[10];
    fin.getline(cadena1, 10);
    char usuario[10];
    cout << "ingrese su nombre de usuario" << endl;
    cin >> usuario;
    num = strcmp(usuario, cadena1);
    if (num == 0)
    {
        cntr = Detective();
        if (cntr == 's')
        {
            Menu();
        }
        if (cntr == 'n')
        {
            cout << "La contraseña ingresada es erronea." << endl;
        }
    }
    else
        cout << "Usuario no existente" << endl;
}

int StartCredits()
{
    ifstream fin;
    int puntos;
    fin.open("puntos.txt", ios_base::in);
    fin.seekg(0, fin.beg);
    char cadena1[3];
    fin.getline(cadena1, 3);
    puntos = atoi(cadena1);
    return puntos;
}

void SaveGame()
{
    ifstream fin;
    ofstream fout;
    cout << "Tienes " << CRED << " creditos" << endl;
    fin.open("puntos.txt", ios_base::in);
    fout.open("temp.txt", ios_base::out | ios_base::app);
    fout << CRED;
    fin.close();
    fout.close();
    remove("puntos.txt");
    rename("temp.txt", "puntos.txt");

}