#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    return Catch::Session().run(argc, argv);
}

//// Declaración de funciones
//string ConvertirAMayusculas(string Texto);
//string ConvertirAMinusculas(string Texto);
//
//int main() {
//    string cadenaDeTexto;
//    string cadenaDeTextoConvertida;
//    bool opcionValida = false;
//    int opcion;
//
//    cout << "-------------------------------------" << endl;
//    cout << "Este programa convierte una cadena de \ncaracteres a mayusculas o "
//        "minusculas."
//        << endl
//        << endl;
//
//    cout << "Escribe una cadena de texto: ";
//    getline(cin, cadenaDeTexto);
//
//    cout << "\nConvertir la cadena de texto a:" << endl;
//    cout << "1 Mayusculas" << endl;
//    cout << "2 Minusculas" << endl;
//    cout << "Escribe 1 o 2 para convertir: ";
//    cin >> opcion;
//
//    if (opcion == 1) {
//        cadenaDeTextoConvertida = ConvertirAMayusculas(cadenaDeTexto);
//        opcionValida = true;
//    }
//    else if (opcion == 2) {
//        cadenaDeTextoConvertida = ConvertirAMinusculas(cadenaDeTexto);
//        opcionValida = true;
//    }
//
//    if (opcionValida) {
//        cout << "\n--- Conversion ---" << endl;
//        cout << "Original:   " << cadenaDeTexto << endl;
//        cout << "Convertida: " << cadenaDeTextoConvertida << endl << endl;
//    }
//    else {
//        cout << "\nLa opcion no es valida." << endl << endl;
//    }
//}

string ConvertirAMayusculas(string Texto) {

    for (int i = 0; i < Texto.length(); i++) {
        Texto[i] = toupper(Texto[i]);
    }

    return Texto;
}

string ConvertirAMinusculas(string Texto) {

    for (int i = 0; i < Texto.length(); i++) {
        Texto[i] = tolower(Texto[i]);
    }

    return Texto;
}

TEST_CASE("Converting to uppercase", "[uppercase]") {
    SECTION("Empty string") {
        REQUIRE(ConvertirAMayusculas("") == "");
    }

    SECTION("All lowercase") {
        REQUIRE(ConvertirAMayusculas("hola mundo") == "HOLA MUNDO");
    }

    SECTION("Mixed case") {
        REQUIRE(ConvertirAMayusculas("Hola MunDo") == "HOLA MUNDO");
    }

    SECTION("All uppercase") {
        REQUIRE(ConvertirAMayusculas("HOLA MUNDO") == "HOLA MUNDO");
    }

    SECTION("Combinar las letras mayúsculas y minúsculas") {
        REQUIRE(ConvertirAMayusculas("Hola Mundo") == "HOLA MUNDO");
    }
}

TEST_CASE("Converting to lowercase", "[lowercase]") {
    SECTION("Empty string") {
        REQUIRE(ConvertirAMinusculas("") == "");
    }

    SECTION("All uppercase") {
        REQUIRE(ConvertirAMinusculas("HOLA MUNDO") == "hola mundo");
    }

    SECTION("Mixed case") {
        REQUIRE(ConvertirAMinusculas("Hola MunDo") == "hola mundo");
    }

    SECTION("All lowercase") {
        REQUIRE(ConvertirAMinusculas("hola mundo") == "hola mundo");
    }
}
