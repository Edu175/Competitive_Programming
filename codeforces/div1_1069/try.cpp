#include <iostream>
#include <set>
#include <tuple>

// Traducción de la función 'ask'
// Calcula la suma de los dígitos de x en base b
int ask(int b, int x) {
    int r = 0;
    while (x > 0) {
        r += x % b;
        x /= b;
    }
    return r;
}

int main() {
    // Optimización para acelerar la entrada/salida en consola
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Usamos un set de tuplas (int, int, int)
    std::set<std::tuple<int, int>> st;

	int a=4,b=8;
	
    // Bucle hasta 10^7 (10,000,000)
    for (int i = b; i < 100; ++i) {
        // Creamos la tupla con los tres resultados
        auto tup = std::make_tuple(ask(a, i), ask(b, i));

        // Intentamos insertar en el set.
        // st.insert devuelve un par. El segundo elemento (.second) es un booleano:
        // true = se insertó (no existía antes)
        // false = no se insertó (ya existía, colisión)
        auto result = st.insert(tup);
        
        if (!result.second) { // Si ya existía (equivalente a "if tup in st")
            std::cout << "BAD " << i << " : ("
                      << std::get<0>(tup) << ", "
                    //   << std::get<1>(tup) << ", "
                      << std::get<1>(tup) << ")\n";
        }
    }

    return 0;
}