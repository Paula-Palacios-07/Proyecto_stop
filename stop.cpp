#include <iomanip> // se utiliza para establecer el ancho de un campo con setw.
#include <iostream> // salida de datos
using namespace std;
int partidas;
float tiempoFinal = 0;
int puntajeFinal;

//funcion vacia mostrar_tabla
void mostrarTabla(string categorias[], string tabla[][10]);

int main() {
  int opcion, letras;
  string nombre_jugador;
  
  

cout <<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"<< endl;
cout << "\n"<<endl;
cout << "Hola, ¿como te llamas?: ";
cin >> nombre_jugador;
cout << "\n"<<endl;
  
cout <<"-----------------------------------------------------BIENVENIDOS A EL JUEGO STOP----------------------------------------------------------------------------------\n"<< endl;
  
// Reglas del juego
cout << nombre_jugador <<" Bienvenid@ al juego stop, a continuación te explicare las reglas del juego: " << endl;
cout << "El sistema te proporcionara una letra de manera aleatoria las veces que desees jugar, por cada letra debes escribir palabras que inicien con dicha letra que correspondan a:" << endl;
cout<< " " << endl;
cout<< " - Nombre - Apellido - Ciudad - Animal - Fruta - Color - Cosa" << endl;
cout<< " " << endl;
cout << " - Por cada palabra correcta se te sumaran 100 puntos. " << endl;
cout<< " " << endl;
cout << " - Por cada palabra incorrecta se te restaran 100 puntos. " << endl;
cout<< " " << endl;
cout << " - Si no sabes que responder en la categoria ingresa un '.' para continuar con la siguiente categoria, el sistema tomara esto como si no hubieras escrito nada, no se te restan ni suman puntos en este caso. " << endl;
cout<< " " << endl;
cout << " - La palabra a ingresar debe ser en mayuscula, de lo contrario el sistema no reconocera la palabra y por lo tanto se te restaran 100 puntos." << endl;
cout<< " " << endl;
  
cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
cout <<"¿Quieres continuar con el juego?, presiona 1 para SI o 2 para NO" << endl;
cin >> opcion; 

// Tomar la decision de continuar con el juego
  if ( opcion == 1) {
   
  } else if (opcion == 2 ) {
    cout << "Byee !";
    cout << " " << endl;
    return 0;
  } else {
    cout << "Error!, ingesa un valor valido\n" << endl;
    return 0;
  }

  string categorias[10] = {"LETRA", "NOMBRE", " APELLIDO", "CIUDAD",     "ANIMAL",
                       "FRUTA", " COLOR", "OBJETO",    "TIEMPOS", "TOTAL"};

// Nùmero de partidas y letra aleatoria
cout<<"¿Cuantas partidas quiere jugar?"<<endl;
cin>>partidas;

cout << "\n--------------------------------------------------------EL JUEGO INICIA AHORA-------------------------------------------------------------------------------------\n" << endl;

   string tabla[partidas][10];
   int puntajeFila;
   for (int fila = 0; fila < partidas; fila++) {
   srand(time(NULL));
   char letra[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R','S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
   char abecedario = letra[rand() % 26];
   tabla[fila][0] = char(abecedario);
    
    // ctime 1 - Inicia el tiempo
    clock_t tiempo_i = clock();
    
    // Inicio del juego 
    for (int columna = 1; columna < 8; columna++) {
      cout << "Letra " << char(abecedario) << ":" << " ingrese  " << categorias[columna];
      cout<<"  "<<endl;
      cin >> tabla[fila][columna];
      if (tabla[fila][columna].front() == char(abecedario)) {
        puntajeFila += 100;
      } else if (tabla[fila][columna] == ".") {
        puntajeFila += 0;
      } else {
        puntajeFila -= 100;
      } 
    }
    //Calculo puntaje final
    puntajeFinal += puntajeFila;
    cout << endl;
     
    // ctime 2 - Fin del tiempo
    clock_t tiempo_f = clock();
    float tiempo_u = (float)(tiempo_f - tiempo_i)/CLOCKS_PER_SEC;
    cout <<"El tiempo para esta ronda es de: " <<to_string((float)tiempo_u) << " s\n" << endl;
    tabla[fila][8] = to_string((float)tiempo_u);
    tabla[fila][9] = to_string(puntajeFila);
    puntajeFila = 0;
     
    //Calculo tiempo total
    tiempoFinal+=tiempo_u;

  }
  
  cout <<"\n------------------------------------------------------------------RESULTADOS---------------------------------------------------------------------------------------\n" << endl;
  
  mostrarTabla(categorias, tabla);
  }
      
//Mostrar la tabla con las categorias como encabezado
void mostrarTabla(string categorias[], string tabla[][10]) {
  for (int i = 0; i <= 9; i++) {
    cout << setw(15) << categorias[i];
  }

  
//Mostrar las palabras que ingreso el jugador dentro de la tabla
  cout << endl;
  for (int i = 0; i < partidas; i++) {
    for (int j = 0; j <= 9; j++) {
      cout << setw(15) << tabla[i][j];
    }
    cout << endl;
  }
  cout <<"\n--------------------------------------------------------------------TOTALES----------------------------------------------------------------------------------------\n" << endl;
  cout<<"\nEl tiempo total fue: "<< to_string((float)tiempoFinal)<<" segundos"<<endl;
  cout<<"\nEl puntaje final fue: "<<puntajeFinal<<" puntos"<<endl;
  cout<< " " <<endl;
  cout<<"\nGracias por participar :)"<<endl;
   
}



                                            // ALGUNAS DEFICIONES PARA RECORDAR QUE FUE LO QUE HICE//

//for (int i = 0; i <= 9; i++): el 9 indica el numero de las categorias, recordar que la numeracion inicia desde 0 y son de 10 categorias.
//for (int i = 0; i < partidas; i++): dependiendo el numero de partidas que el jugador alla jugado asi mismo mostrara los datos.
//for (int j = 0; j <= 9; j++): el 9 muestra en la tabla las 7 palabras que ingreso el jugador mas las columnas de tiempo y puntaje.

    
//tiempo_i = tiempo inicio
//tiempo_u= tiempo usado
//tiempo_f= tiempo final

// Tomar la decision de continuar con el juego 
// ahi que poner el return 0 si no el siglo continua. 

// cout: es para mostrar por pantalla cualquir tipo de dato.
// cin: es para ingresar datos desde el teclado. 

// areglo: Un arreglo es una colección de posiciones de almacenamiento de datos

//clock: La función "clock" retorna el tiempo consumido por el programa medido en ticks,  que junto con la macro "CLOCKS_PER_SEC" nos permite traducir los ticks a segundos.

// to_string: Para convertir un valor numerico en cadena.

//+=: suma una cantidad al valor de una variable.


// La funcion void no devuelve ningun valor, y los parametros son: 
// nombre de la funcion,tipo de dato, nombre del arreglo y el tamaño del arreglo.
    
//Srand: Usa el argumento como una semilla para una secuencia nueva de números pseudo-aleatorios para 
//ser retornados por llamadas posteriores a rand.

  