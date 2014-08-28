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
	char* librouno = "unods";
	int opcion;
	void (*punteroAFuncion)(void*);
	punteroAFuncion = &mostrar;
	t_list* libros = list_create();
	list_add(libros, librouno);
	printf(
			"Bienvenido!\n1- Listar libros\n2- Cargar un libro\n¿Que desea hacer': ");
	scanf("%d", &opcion);
	/*switch (opcion) {
	 case 1:
	 }*/
	if (opcion == 1) {
		list_iterate(libros, punteroAFuncion);
	}
	if (opcion == 2) {
		char* libroNuevo = malloc(sizeof(char) * 50);
		printf("¿Que libro quiere agregar?: ");
		scanf("%s", libroNuevo);
		printf("%s", libroNuevo);
		list_add(libros, libroNuevo);
	}
	return EXIT_SUCCESS;
}
