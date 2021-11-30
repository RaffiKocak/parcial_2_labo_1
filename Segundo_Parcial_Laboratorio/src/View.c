/*
 * View.c
 *
 *  Created on: 8 nov 2021
 *      Author: Raffi
 */

#include "View.h"


void ImprimirMenuPrincipal() {
	printf("-----------------------------\n"
			"Menú principal\n"
			"-----------------------------\n"
			"[1] Cargar datos de libros a través de archivo tipo texto.\n"
			"[2] Cargar datos de editoriales a través de archivo tipo texto.\n"
			"[3] Ordenar los libros por autor en orden alfabético.\n"
			"[4] Mostrar lista de libros.\n"
			"[5] Guardar archivo de libros con editorial MINOTAURO.\n"
			"[6] Mapear archivo de libros con descuentos.\n"
			"[7] Salir.\n"
			"-----------------------------\n");
}

/// @brief Muestra mensajes determinados según el retorno del controller de carga de datos
/// @param output
/// @param loadType
void view_returnsFromLoad(int output) {
	switch(output) {
		case -3:
			printf("Path o ArrayList nulo.\n");
			break;

		case -2:
			printf("No se pudo abrir el archivo en carga.\n");
			break;

		case -1:
			printf("No se pudo rescatar ningún dato a la lista.\n");
			break;

		case 0:
			printf("Carga de datos ejecutada exitosamente.\n");
			break;
	}
}


/// @brief Muestra mensajes determinados según el retorno del controller de Sort que llama
///
/// @param output
/// @param ListOrSort
void view_returnsFromPrintSort(int output, char* PrintOrSort) {

	switch (output) {
		case -2:
			printf("LinkedList nula en operación: %s\n", PrintOrSort);
			break;

		case -1:
			printf("Operación de tipo %s falló\n", PrintOrSort);
			break;

		case 0:
			printf("Operación de tipo %s se realizó exitosamente\n", PrintOrSort);
			break;
	}
}

void view_returnsFromFilter(int output) {

	switch (output) {
		case -2:
			printf("LinkedList nula.\n");
			break;

		case -1:
			printf("No se pudo guardar la lista filtrada.\n");
			break;

		case 0:
			printf("Filtro realizado exitosamente.\n");
			break;
	}
}


/*
/// @brief Muestra mensajes determinados según el retorno del controller de guardado que llama
///
/// @param output
/// @param saveType
void view_returnsFromSave(int output, char* saveType) {

	switch(output) {
		case -3:
			printf("Path o ArrayList nulo en guardado de tipo: %s\n", saveType);
			break;

		case -2:
			printf("No se pudo abrir el archivo en guardado de tipo: %s\n", saveType);
			break;

		case -1:
			printf("No se pudo guardar empleados al archivo %s\n", saveType);
			break;

		case 0:
			printf("Guardado de datos a archivo de tipo %s ejecutada exitosamente\n", saveType);
			break;
	}

}*/
