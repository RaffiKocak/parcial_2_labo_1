/*
 ============================================================================
 Name        : Segundo_Parcial_Laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Controller.h"
#include "View.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	LinkedList* listaLibros;
	LinkedList* listaEditoriales;
	int flagLoadLibros;
	int flagLoadEditoriales;
	int retornoFuncion;
	int opcion;
	char confirmacion;

	listaLibros = ll_newLinkedList();
	listaEditoriales = ll_newLinkedList();
	flagLoadLibros = 0;
	flagLoadEditoriales = 0;

	do{
		ImprimirMenuPrincipal();

		opcion = PedirInt("Ingrese una opción: ");

		switch(opcion) {
			case 1:
				if (flagLoadLibros == 0) {
					retornoFuncion = controller_loadFromText(listaLibros, parser_BookFromText);
					view_returnsFromLoad(retornoFuncion);
					if (!retornoFuncion) {
						flagLoadLibros = 1;
					}
				} else {
					printf("El archivo ya se encuentra cargado.\n");
				}

				break;

			case 2:
				if (flagLoadEditoriales == 0) {
					retornoFuncion = controller_loadFromText(listaEditoriales, parser_EditorialFromText);
					view_returnsFromLoad(retornoFuncion);
					if (!retornoFuncion) {
						flagLoadEditoriales = 1;
					}
				} else {
					printf("El archivo ya se encuentra cargado.\n");
				}
				break;

			case 3:
				if (flagLoadLibros == 1) {
					retornoFuncion = controller_sortBook(listaLibros);
					view_returnsFromPrintSort(retornoFuncion, "SORT");
				} else {
					printf("Por favor cargue el archivo de libros primero.\n");
				}
				break;

			case 4:
				if (flagLoadLibros == 1 && flagLoadEditoriales == 1) {
					retornoFuncion = controller_printBook(listaLibros, listaEditoriales);;
					view_returnsFromPrintSort(retornoFuncion, "PRINT");
				} else {
					printf("Por favor cargue los archivos de libros y editoriales primero.\n");
				}
				break;

			case 5:
				if (flagLoadLibros == 1) {
					retornoFuncion = controller_filterBooks(listaLibros);
					view_returnsFromFilter(retornoFuncion);
				} else {
					printf("Por favor cargue el archivo de libros primero.\n");
				}
				break;

			case 6:
				controller_mapBooks(listaLibros);
				break;

			case 7:
				confirmacion = tolower(PedirCaracterSiONo("Está seguro que desea salir del programa?\n[S] Sí\n[N] No\n"));

				if (confirmacion == 's') {
					libro_deleteAll(listaLibros);
					editorial_deleteAll(listaEditoriales);
					ll_deleteLinkedList(listaEditoriales);
					ll_deleteLinkedList(listaLibros);
					printf("Nos vemos!");
				}

				break;

			default:
				printf("Por favor ingrese una opción válida!");
				break;
		}
	} while (confirmacion != 's');

	return EXIT_SUCCESS;
}
