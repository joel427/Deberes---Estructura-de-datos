#include <iostream>
#include <string>
#include <algorithm> // Necesario para la función max()

using namespace std;

// Estructura para almacenar los datos del empleado [cite: 36]
struct Empleado {
    int codigo;
    string nombre;
    string cargo;
};

// Estructura del Nodo del árbol [cite: 41]
struct Nodo {
    Empleado dato;
    Nodo* izquierdo;
    Nodo* derecho;

    // Constructor para inicializar el nodo [cite: 45]
    Nodo(Empleado emp) {
        dato = emp;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

class ArbolBST {
private:
    Nodo* raiz;

    // Función auxiliar para insertar un empleado [cite: 54]
    Nodo* insertar(Nodo* nodo, Empleado emp) {
        if (nodo == nullptr) {
            return new Nodo(emp);
        }
        if (emp.codigo < nodo->dato.codigo) {
            nodo->izquierdo = insertar(nodo->izquierdo, emp);
        } else if (emp.codigo > nodo->dato.codigo) {
            nodo->derecho = insertar(nodo->derecho, emp);
        } else {
            cout << "El codigo ya existe.\n"; 
        }
        return nodo;
    }

    // Función auxiliar para buscar por código [cite: 67]
    Nodo* buscar(Nodo* nodo, int codigo) {
        if (nodo == nullptr || nodo->dato.codigo == codigo) {
            return nodo;
        }
        if (codigo < nodo->dato.codigo) {
            return buscar(nodo->izquierdo, codigo);
        } else {
            return buscar(nodo->derecho, codigo);
        }
    }

    // Recorridos del árbol [cite: 77, 84, 91]
    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);
            mostrarEmpleado(nodo);
            inorden(nodo->derecho);
        }
    }

    void preorden(Nodo* nodo) {
        if (nodo != nullptr) {
            mostrarEmpleado(nodo);
            preorden(nodo->izquierdo);
            preorden(nodo->derecho);
        }
    }

    void postorden(Nodo* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo);
            postorden(nodo->derecho);
            mostrarEmpleado(nodo);
        }
    }

    // Cálculo de la altura del árbol [cite: 98]
    int altura(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        int alturaIzq = altura(nodo->izquierdo);
        int alturaDer = altura(nodo->derecho);
        return 1 + max(alturaIzq, alturaDer);
    }

    // Función para identificar y mostrar hojas [cite: 106]
    void mostrarHojas(Nodo* nodo) {
        if (nodo != nullptr) {
            if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
                mostrarEmpleado(nodo);
            }
            mostrarHojas(nodo->izquierdo);
            mostrarHojas(nodo->derecho);
        }
    }

    void mostrarEmpleado(Nodo* nodo) {
        cout << "Codigo: " << nodo->dato.codigo
             << " | Nombre: " << nodo->dato.nombre
             << " | Cargo: " << nodo->dato.cargo << endl; 
    }

public:
    ArbolBST() {
        raiz = nullptr; 
    }

    // Métodos públicos para interactuar con el árbol
    void insertarEmpleado(Empleado emp) { raiz = insertar(raiz, emp); }
    
    void buscarEmpleado(int codigo) {
        Nodo* resultado = buscar(raiz, codigo);
        if (resultado != nullptr) {
            cout << "\nEmpleado encontrado:\n";
            mostrarEmpleado(resultado);
        } else {
            cout << "\nEmpleado no encontrado.\n";
        }
    }

    void mostrarRaiz() {
        if (raiz != nullptr) {
            cout << "\nRaiz del arbol:\n";
            mostrarEmpleado(raiz);
        } else {
            cout << "El arbol esta vacio.\n";
        }
    }

    void mostrarInorden() { cout << "\nRecorrido Inorden:\n"; inorden(raiz); }
    void mostrarPreorden() { cout << "\nRecorrido Preorden:\n"; preorden(raiz); }
    void mostrarPostorden() { cout << "\nRecorrido Postorden:\n"; postorden(raiz); }
    void mostrarAltura() { cout << "\nAltura del arbol: " << altura(raiz) << endl; }
    void mostrarNodosHoja() { cout << "\nNodos hoja:\n"; mostrarHojas(raiz); }
};

int main() {
    ArbolBST arbol;
    int opcion;

    do {
        cout << "\n===== MENU ARBOL BST EMPRESARIAL =====\n";
        cout << "1. Insertar empleado\n2. Buscar empleado\n3. Mostrar raiz\n";
        cout << "4. Recorrido inorden\n5. Recorrido preorden\n6. Recorrido postorden\n";
        cout << "7. Mostrar altura\n8. Mostrar hojas\n0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Empleado emp;
            cout << "Codigo: "; cin >> emp.codigo;
            cin.ignore();
            cout << "Nombre: "; getline(cin, emp.nombre);
            cout << "Cargo: "; getline(cin, emp.cargo);
            arbol.insertarEmpleado(emp);
        } else if (opcion == 2) {
            int cod; cout << "Ingrese codigo a buscar: "; cin >> cod;
            arbol.buscarEmpleado(cod);
        } else if (opcion == 3) {
            arbol.mostrarRaiz();
        } else if (opcion == 4) {
            arbol.mostrarInorden();
        } else if (opcion == 5) {
            arbol.mostrarPreorden();
        } else if (opcion == 6) {
            arbol.mostrarPostorden();
        } else if (opcion == 7) {
            arbol.mostrarAltura();
        } else if (opcion == 8) {
            arbol.mostrarNodosHoja();
        }
    } while (opcion != 0);

    return 0;
}