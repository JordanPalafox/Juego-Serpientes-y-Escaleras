README - JUEGO SERPIENTES Y ESCALERAS

Este es un programa de consola que implementa un juego simple de Serpientes y Escaleras para dos jugadores. El juego se juega en un tablero de 30 casillas y los jugadores deben avanzar por el tablero lanzando un dado.

Instrucciones de compilación:

El codigo fuente es el archivo snakes.cpp, para compilarlo sigue los siguientes pasos:

1. Asegurate de tener el compilador de c++
2. Entra a la carpeta src utilizando la terminal
3. Una vez dentro de la carpeta ejecuta el siguiente comando: g++ snakes.cpp -o snakes.exe
4. Se debera crear un archivo .exe dentro de la carpeta src, ejecutar este archivo inicializara el juego

Instrucciones de ejecución:

Para ejecutar el programa, sigue los siguientes pasos:

1. Asegurate de haber compilado el programa y tener el archivo .exe
2. Escribe el nombre del archivo .exe en la terminal, ejemplo: snakes.exe

Descripción del codigo:

El código se divide en las siguientes partes:

MyGame: Esta clase representa el juego de Serpientes y Escaleras. Contiene la lógica principal del juego, incluyendo la generación del tablero, la creación de jugadores, el lanzamiento de dados y el control del flujo del juego.

Jugador: Esta clase representa a un jugador del juego. Cada jugador tiene un número de jugador, una posición actual en el tablero, un turno y una posición final.

Dice: Esta clase representa un dado. Genera un número aleatorio entre 1 y 6 cada vez que se lanza.

Se hizo de esta manera para agilizar la progrmación del juego y por requisitos de la entrega.




