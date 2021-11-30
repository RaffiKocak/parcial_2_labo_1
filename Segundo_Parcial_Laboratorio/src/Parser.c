/*
 * Parser.c
 *
 *  Created on: 24 nov 2021
 *      Author: Raffi
 */

#include "Parser.h"


int parser_BookFromText(FILE* pFile, LinkedList* pArrayListBook)
{
	int retorno;
	eLibro* nuevoLibro;
	char id[11];
	char titulo[128];
	char autor[128];
	char precio[100];
	char idEditorial[11];

	retorno = -1;

	if (pFile != NULL && pArrayListBook != NULL) {
		fscanf(pFile, "\n");
		while (!feof(pFile)) {

			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial) == 5 && VerificarInt(id) && VerificarNombre(autor)
					&& VerificarFloat(precio) && VerificarInt(idEditorial)) {

				nuevoLibro = libro_newParametros(id, titulo, autor, precio, idEditorial);

				if (nuevoLibro != NULL) {
					if (ll_add(pArrayListBook, nuevoLibro) != -1) {
						retorno = 0;
					} else {
						libro_delete(nuevoLibro);
					}
				}
			}
		}
	}
    return retorno;
}

int parser_EditorialFromText(FILE* pFile, LinkedList* pArrayListEditorial)
{
	int retorno;
	eEditorial* nuevaEditorial;
	char id[11];
	char nombre[128];

	retorno = -1;

	if (pFile != NULL && pArrayListEditorial != NULL) {
		fscanf(pFile, "\n");
		while (!feof(pFile)) {

			if (fscanf(pFile, "%[^,],%[^\n]\n", id, nombre) == 2 && VerificarInt(id)) {

				nuevaEditorial = editorial_newParametros(id, nombre);

				if (nuevaEditorial != NULL) {
					if (ll_add(pArrayListEditorial, nuevaEditorial) != -1) {
						retorno = 0;
					} else {
						editorial_delete(nuevaEditorial);
					}
				}
			}
		}
	}
    return retorno;
}
