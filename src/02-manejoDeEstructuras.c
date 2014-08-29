#include <stdio.h>
#include <stdlib.h>
#include <commons/collections/list.h>

struct Libro {
	char nombre[20];
	char isbn[13];
	float precio;
	int stock;
};

void mostrar2(void* elemento) {
	struct Libro* libro = (struct Libro*) elemento;
	printf("%s, %s, %f, %d\n", libro->nombre, libro->isbn, libro->precio, libro->stock);
}

void mostrarLibro2(t_list* libros) {
	list_iterate(libros, &mostrar2);
}

void cargarLibro2(t_list* libros) {
	struct Libro* libro = malloc(sizeof(struct Libro));
	printf("¿Que libro quiere agregar?: ");
	scanf("%s", libro->nombre);
	printf("¿Cual es el isbn quiere agregar?: ");
	scanf("%s", libro->isbn);
	printf("¿Cual es el precio quiere agregar?: ");
	scanf("%f", &libro->precio);
	printf("¿Cual es el stock quiere agregar?: ");
	scanf("%d", &libro->stock);
	list_add(libros, libro);
}

int preguntarOpcion2(int opcion) {
	printf(
			"Elija una opcion\n0- Salir\n1- Listar libros\n2- Cargar un libro\n¿Que desea hacer': ");
	scanf("%d", &opcion);
	return opcion;
}

int main(void) {
	t_list* libros = list_create();
	int opcion;

	while (true) {
		opcion = preguntarOpcion2(opcion);
		switch (opcion) {
		case 0:
			return EXIT_SUCCESS;
		case 1:
			mostrarLibro2(libros);
			break;
		case 2:
			cargarLibro2(libros);
			break;
		}
	}
	return EXIT_SUCCESS;
}
