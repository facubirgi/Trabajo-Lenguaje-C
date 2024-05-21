#include <stdio.h>
#include <stdlib.h>

// Declaración de variables globales
int premios[15] = {100, 200, 300, 500, 1000, 2000, 4000, 8000, 16000, 32000, 64000, 125000, 250000, 500000, 1000000};
int checkpoint1 = 1000;
int checkpoint2 = 32000;
int respuestaUsuario;

// Prototipos de funciones
void limpiarPantalla();
int mostrarPregunta(int numeroPregunta, char *pregunta, char *opciones[4], int respuestaCorrecta, int premioAcumulado, int checkpoint);
void finalizarJuego(int premio);
void pantallaCompleta();

int main() {
    // Configurar pantalla completa
    pantallaCompleta();

    // Definición de preguntas y opciones
    char *preguntas[15] = {
        "Pregunta 1: Cuando fue la final de Madrid entre River y Boca?",
        "Pregunta 2: Cual es la capital de Francia?",
        "Pregunta 3: Cual es el equipo mas grande de Rafaela?",
        "Pregunta 4: Como se cayeron las torres gemelas?",
        "Pregunta 5: Messi es...?",
        "Pregunta 6: Cual es el planeta que esta mas cerca del sol?",
        "Pregunta 7: Pais mas grande del mundo?",
        "Pregunta 8: Es peor descender o ganarle una final a tu clasico rival?",
        "Pregunta 9: Cuantas copas America tiene Sudafrica?",
        "Pregunta 10: Messi jugo en...?",
        "Pregunta 11: Cuantas libertadores tiene Bayern Munich?",
        "Pregunta 12: Adonde se encuentra Rafaela?",
        "Pregunta 13: 3 x 4?",
        "Pregunta 14: Quien gano la 2da Guerra Mundial?",
        "Pregunta 15: Cuantos balones de Oro tiene Discoteca Nunez?"
    };

    char *opciones[15][4] = {
        {"1) 2010", "2) 2018", "3) 2000", "4) 2015"},
        {"1) Berlin", "2) Madrid", "3) Paris", "4) Roma"},
        {"1) Ferro", "2) 9 de Julio", "3) Atletico", "4) Ben Hur"},
        {"1) Las tumbaron", "2) Tenian sueno", "3) En un atentado", "4) Ninguna es correcta"},
        {"1) El mejor del planeta", "2) Un marciano", "3) El Goat", "4) Todas las anteriores y mas"},
        {"1) Tierra", "2) Venus", "3) Mercurio", "4) Marte"},
        {"1) China", "2) Rusia", "3) Estados Unidos", "4) Canadas"},
        {"1) La final", "2) Descender", "3) Ambas", "4) Peor es ser de Racing"},
        {"1) 1", "2) 4", "3) 0", "4) 2"},
        {"1) Psg", "2) Barcelona", "3) Inter Miami", "4) Todas"},
        {"1) 2", "2) 0", "3) 1", "4) 3"},
        {"1) Santa Fe", "2) Donde Siempre", "3) Cordoba", "4) Buenos Aires"},
        {"1) 12", "2) Llueve", "3) 12,4", "4) 10"},
        {"1) Napoleon", "2) Hitler", "3) Los Aliados", "4) Peron"},
        {"1) 1", "2) 0", "3) 2", "4) 3"}
    };

    int respuestasCorrectas[15] = {2, 3, 3, 3, 4, 3, 2, 4, 3, 4, 2, 1, 2, 3, 2};
    char continuar;
    int premioAcumulado = 0;
    int checkpoint = 0;

    // Bucle principal del juego
    for (int i = 0; i < 15; i++) {
        limpiarPantalla();
        premioAcumulado = mostrarPregunta(i + 1, preguntas[i], opciones[i], respuestasCorrectas[i], premioAcumulado, checkpoint);

        if (i+1 == 15) {
            printf("\nFelicidades! Has llegado a la pregunta final.\n");
            break;
        }

        printf("\n¿Desea continuar? (s/n): ");
        scanf(" %c", &continuar);
        fflush(stdin);

        if (continuar == 'n' || continuar == 'N') {
            printf("\nHa decidido retirarse con %d USD.\n", premioAcumulado);
            break;
        }
    }

    finalizarJuego(premioAcumulado);

    return 0;
}

// Definición de funciones

void limpiarPantalla() {
    system("cls");
}

int mostrarPregunta(int numeroPregunta, char *pregunta, char *opciones[4], int respuestaCorrecta, int premioAcumulado, int checkpoint) {
    printf("%d: %s\n", numeroPregunta, pregunta);

    for (int i = 0; i < 4; i++) {
        printf("%s\n", opciones[i]);
    }

    printf("\nIngrese su respuesta:(1, 2, 3, 4): ");
    scanf("%d", &respuestaUsuario);
    fflush(stdin);

    if (respuestaUsuario == respuestaCorrecta) {
        premioAcumulado += premios[numeroPregunta - 1];
        if (premioAcumulado >= checkpoint2) {
            checkpoint = checkpoint2;
        } else if (premioAcumulado >= checkpoint1) {
            checkpoint = checkpoint1;
        }
        printf("\nCorrecto! Ha ganado %d USD.\n", premioAcumulado);
    } else {
        if (premioAcumulado > checkpoint) {
            premioAcumulado = checkpoint + (premioAcumulado - checkpoint) / 2;
        }
        printf("\nRespuesta incorrecta. Se lleva %d USD.\n", premioAcumulado);
        finalizarJuego(premioAcumulado);
        exit(0);
    }

    if (premioAcumulado >= checkpoint2) {
        printf("\nHas alcanzado el segundo checkpoint con %d USD.\n", checkpoint2);
    } else if (premioAcumulado >= checkpoint1) {
        printf("\nHas alcanzado el primer checkpoint con %d USD.\n", checkpoint1);
    }

    return premioAcumulado;
}

void finalizarJuego(int premio) {
    printf("\nGracias por jugar. Ha ganado %d USD.\n", premio);
    exit(0);
}

void pantallaCompleta() {
    system("mode 650");
}
