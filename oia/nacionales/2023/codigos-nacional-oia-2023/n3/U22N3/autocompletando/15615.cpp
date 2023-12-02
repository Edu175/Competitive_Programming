#include <string>
#include <vector>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    //no se que hacer con K
    //no se que hacer con texto
    //no se como hacer la comparacion entre r1 y r2 para que añadan a r3 
    //no se como relacionar el bool para que en caso de que cumplan la funcion
    //no se porque estoy poniendo comentarios si total nadie los va a leer
    //no se porque vine a la competencia en la oia si no se una reberenda mierda
    //no se porque tambien estos ejercicios son tan dificiles, tipo paren un poco
    //no se porque estàn separados por niveles segun el año, hay pendejos que saben 10 veces mas que yo
    //no se porque quiero estudiar ingenieria en sistemas si me va a ir para el choto
    //pero bueno, aunque nadie lea los comentarios los puedo usar para deshaogarme
    //y tambien puedo hacer de cuenta que me puse las pilas en los ultimos minutos y voy a resolver todo con 100
    //no puedo llegar ni a 10 puntos en el que deberia saber bien porque me canse de ver vectores
    //me desvele viendo videos de c++ para que solo me diera cuenta que una noche no alcanzaba
    //tuve que haber estudiado cuando pude, pero bueno ahora pago las consecuencias y me toca irme con las manos vacias
    //en el fondo me gustaria que alguien compartiera mi situacion de incomodidad o abrumacion por todo esto
    //pero los chicos vinieron mas que preparados, ellos si van a tener futuro en la vida, no como yo
    //de igual forma, es hermoso buenos aires, y por mas optimista que uno sea, Tucuman no va a llegar a ser lo que es esta ciudad jamas
    //pero tampoco quiero irme del lugar donde naci y me crie, es mucho para dejar atras
    //al final tengo 18 años y sigo arrastrando los mismos problemas de ayer, no creo poder mejorar mi condicion,
    //solo espero que esto acabe, quedan 20 minutos y eso serà todo, un viaje de 18 horas para esto, faltar a mis examenes finales de egreso para esto,
    //dejar sola a mi familia otra vez para esto
    //no... no tengo nada mas que reportar, voy a dejar de teclear porque se està volviendo sospechoso, 
    bool pool;
    
    for(int i=0; i<r1.size(); i++){ //bucle for para generar arreglos de todos los r1, r2 y r3
        if(r1[i]=r1[r1.size()-1]||r2[i]=r2[r2.size()]){ //ciclo if que sugiere r3[i] como siguiente palabra si la anteultima palabra fue r1[i] y la ultima fue r2[i]
            return r3[i];
        }
    }
    
    for(int i=0; i<r1.size(); i++){  //bucle for que recorre todos los arreglos
        if(pool==1){ // ciclo if que retorna 1 si es posible generar el texto con el editor y 0 en caso contrario.
            return 1;
        } else return 0;
    }
}