#include <stdio.h>
#include <stdlib.h>
#include <commons/collections/list.h>

void mostrar(void* elemento) {
	char* cadena = (char*) elemento;
	printf("%s\n", cadena);
}

void mostrarLibro(t_list* libros) {
	list_iterate(libros, &mostrar);
}

void cargarLibro(t_list* libros) {
	char* libroNuevo = malloc(sizeof(char) * 50);
	printf("¿Que libro quiere agregar?: ");
	scanf("%s", libroNuevo);
	list_add(libros, libroNuevo);
	free(libroNuevo);
}

int preguntarOpcion(int opcion) {
	printf(
			"Elija una opcion\n0- Salir\n1- Listar libros\n2- Cargar un libro\n¿Que desea hacer': ");
	scanf("%d", &opcion);
	return opcion;
}

int main1(void) {
	t_list* libros = list_create();
	int opcion;

	while (true) {
		opcion = preguntarOpcion(opcion);
		switch (opcion) {
		case 0:
			return EXIT_SUCCESS;
		case 1:
			mostrarLibro(libros);
			break;
		case 2:
			cargarLibro(libros);
			break;
		}
	}
	return EXIT_SUCCESS;
}
