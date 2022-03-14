#include "Hash.h"
#include <fstream>




void readFromFile(Hash<string>& materias)
{

    ifstream file;

    string nombres;
    string titulo;
    string filename = "estudiantes.txt";

    file.open("estudiantes.txt");
    if (!file)
        cout << "no abre ";
    else
        while (!file.eof())
        {
            file >> titulo;

            do
            {
                file >> nombres;
                materias.insertToHash(titulo);
            } while (nombres != "#");
        }
    file.close();

    //materias.mostrar();
}

int testMenu()
{
    string materia;
    string estudiante;
    Hash<string> HashList;
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
            cout << "Materia: "; cin >> materia;
            cout << "Estudiante: "; cin >> estudiante;
            HashList.insertToHash(estudiante);
        }
        if (opcion == 2)
        {
            HashList.showHash();
        }
        if (opcion == 3)
        {
            cout << "Estudiante a eliminar: "; cin >> estudiante;
            HashList.deleteFromHash(estudiante);
            cout << "eliminado: " << endl;
        }
        if (opcion == 4)
        {
            cout << "Estudiante a Buscar: "; cin >> estudiante;
            string msg = HashList.findInHash(estudiante);
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

	