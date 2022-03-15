#include "Hash.h"
#include <fstream>




void readFromFile(Hash<string>& hashList)
{

    ifstream file;

    string word;

    file.open("test.txt");
    if (!file)
        cout << "no abre ";
    else
        while (!file.eof())
        {
            file >> word;
            hashList.insertToHash(word);
        }
    file.close();

    //.mostrar();
}

int testMenu()
{
    string dato;
    Hash<string> HashList(60009);
    int opcion;
    do
    {
        cout << "MENU" << endl;
        cout << "1--Insertar---" << endl;
        cout << "2--Mostrar--" << endl;
        cout << "3--Eliminar--" << endl;
        cout << "4--Buscar--" << endl;
        cout << "5. leerDeArchivo" << endl;
        cout << "6. NOT DEFINED" << endl;
        cout << "7-Salir--" << endl;
        cin >> opcion;
        system("cls");


        if (opcion == 1)
        {
            cout << "dato: "; cin >> dato;
            HashList.insertToHash(dato);
        }
        if (opcion == 2)
        {
            HashList.showHash();
        }
        if (opcion == 3)
        {
            cout << "Estudiante a eliminar: "; cin >> dato;
            HashList.deleteFromHash(dato);
            cout << "eliminado: " << endl;
        }
        if (opcion == 4)
        {
            cout << "Estudiante a Buscar: "; cin >> dato;
            string msg = HashList.findInHash(dato);
            cout << "resultado : " << msg << endl;
        }
        if (opcion == 5)
        {
            readFromFile(HashList);

        }
        if (opcion == 6)
        {
            //sgnte requerimiento
        }

    } while (opcion != 7);
    return 0;
}

int main()
{

	testMenu();
}

	