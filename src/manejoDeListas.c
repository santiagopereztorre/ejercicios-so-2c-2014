/*
 ============================================================================
 Name        : Incrementales.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <commons/collections/list.h>

void mostrar(void* elemento) {
	char* cadena = (char*) elemento;
	printf("%s\n", cadena);
}

int main(void) {
	t_list* libros = list_create();
	char* libroNuevo = malloc(sizeof(char) * 50);

	while (true) {
		int opcion;
		printf("Elija una opcion\n0- Salir\n1- Listar libros\n2- Cargar un libro\n¿Que desea hacer': ");
		scanf("%d", &opcion);
		switch (opcion) {
		case 0:
			return EXIT_SUCCESS;
		case 1:
			list_iterate(libros, &mostrar);
			break;
		case 2:
			printf("¿Que libro quiere agregar?: ");
			scanf("%s", libroNuevo);
			list_add(libros, libroNuevo);
			break;
		}
	}
	free(libroNuevo);
	return EXIT_SUCCESS;
}
