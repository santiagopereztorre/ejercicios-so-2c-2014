#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/collections/list.h>
#include <commons/string.h>

struct Libro {
	char nombre[20];
	char isbn[13];
	float precio;
	int stock;
};

void mostrar(void* elemento) {
	struct Libro* libro = (struct Libro*) elemento;
	printf("%s, %s, %f, %d\n", libro->nombre, libro->isbn, libro->precio, libro->stock);
}

void mostrarLibros(t_list* libros) {
	list_iterate(libros, &mostrar);
}

void cargarLibro(t_list* libros) {
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

void libro_destroy(struct Libro *self) {
    free(self);
}

void quitarLibro(t_list* libros) {
	char nombre[20];

	printf("¿Cual es el nombre del libro a quitar?: ");
	scanf("%s", nombre);

	bool comparador(struct Libro* libro) {
		return string_equals_ignore_case(libro->nombre, nombre);
	}

	list_remove_and_destroy_by_condition(libros, (void*) comparador, (void*) libro_destroy);
}

void aumentarStock(t_list* libros) {
	char nombre[20];
	int cantidad;

	printf("¿Cual es el nombre del libro a aumentar stock?: ");
	scanf("%s", nombre);

	printf("¿Cuanto stock desea aumentar?: ");
	scanf("%d", &cantidad);

	bool comparador(struct Libro* libro) {
		return string_equals_ignore_case(libro->nombre, nombre);
	}

	struct Libro* libro = list_find(libros, (void*) comparador);

	libro->stock = libro->stock + cantidad;
}

void disminuirStock(t_list* libros) {
	char nombre[20];
	int cantidad;

	printf("¿Cual es el nombre del libro a disminuir stock?: ");
	scanf("%s", nombre);

	printf("¿Cuanto stock desea disminuir?: ");
	scanf("%d", &cantidad);

	bool comparador(struct Libro* libro) {
		return string_equals_ignore_case(libro->nombre, nombre);
	}

	struct Libro* libro = list_find(libros, (void*) comparador);

	libro->stock = libro->stock - cantidad;
}

int preguntarOpcion(int opcion) {
	printf("Elija una opcion\n"
			"0- Salir\n"
			"1- Listar libros\n"
			"2- Cargar un libro\n"
			"3- Quitar un libro\n"
			"4- Aumentar stock\n"
			"5- Disminuir stock\n"
			"¿Que desea hacer': ");
	scanf("%d", &opcion);
	return opcion;
}

int main(void) {
	t_list* libros = list_create();
	int opcion;

	while (true) {
		opcion = preguntarOpcion(opcion);
		switch (opcion) {
		case 0:
			return EXIT_SUCCESS;
		case 1:
			mostrarLibros(libros);
			break;
		case 2:
			cargarLibro(libros);
			break;
		case 3:
			quitarLibro(libros);
			break;
		case 4:
			aumentarStock(libros);
			break;
		case 5:
			disminuirStock(libros);
			break;
		}
	}
	list_clean_and_destroy_elements(libros, (void*) libro_destroy);
	return EXIT_SUCCESS;
}
