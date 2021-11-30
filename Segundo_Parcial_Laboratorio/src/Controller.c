/*
 * Controller.c
 *
 *  Created on: 24 nov 2021
 *      Author: Raffi
 */

#include "Controller.h"

int controller_loadFromText(LinkedList* pArrayList, int (*pFunc)(FILE*, LinkedList*) )
{
	int retorno;
	FILE* pFile;
	char path[200];

	retorno = -3; //arraylist NULL

	if (pArrayList != NULL) {
		retorno = -2; // no pudo abrir el file (path NULL o no existe el archivo)
		if (PedirCadenaConReintentos(path, sizeof(path), "Ingrese nombre del archivo que desea abrir: ", 3)) {
			strcat(path, ".csv");
			pFile = fopen(path, "r");
			if (pFile != NULL) {
				retorno = pFunc(pFile, pArrayList); // -1 si no trajo nada, 0 si trajo al menos 1 elemento
				fclose(pFile);
			}
		}
	}
    return retorno;
}

int controller_sortBook(LinkedList* pArrayListBook)
{
	int retorno;

	retorno = -1; // LL nula
	if (pArrayListBook != NULL) {
		retorno = ll_sort(pArrayListBook, libro_compareByAutor, 1); // retorno cambia a 0. devolvería -1 si la lista fuera nula (atajado en linea 36)
	}

    return retorno;
}

int controller_printBook(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial) {
	int retorno;
	eLibro* auxLibro;
	int len;

	retorno = -1; // alguna LL NULA o VACÍA
	if (pArrayListBook != NULL && !ll_isEmpty(pArrayListBook) && pArrayListEditorial != NULL && !ll_isEmpty(pArrayListEditorial)) {
		len = ll_len(pArrayListBook);
		if (len > 0) {
			printf("ID\tTitulo\t\tAutor\t\t\tPrecio\t   Editorial\n"
					"------------------------------------------------------------------------------\n");
			for (int i = 0; i < len; i++) {
				auxLibro = (eLibro*) ll_get(pArrayListBook, i);
				libro_printLibro(auxLibro, pArrayListEditorial);
			}
			retorno = 0;
		}
	}
	return retorno;
}

int controller_filterBooks(LinkedList* pArrayListBook) {
	int retorno;
	LinkedList* pArrayListBookMinotauro;

	retorno = -2; // LL NULA

	if (pArrayListBook != NULL) {

		pArrayListBookMinotauro = ll_filter(pArrayListBook, libro_verificarEditorialMinotauro);
		retorno = controller_saveAsText("librosMinotauro.csv", pArrayListBookMinotauro);
		ll_deleteLinkedList(pArrayListBookMinotauro);
	}
	return retorno;
}

int controller_mapBooks(LinkedList* pArrayListBook) {
	int retorno;

	retorno = -3; // LL NULA

	if (pArrayListBook != NULL) {
		retorno = -2;

		if (!ll_map(pArrayListBook, libro_ajustarPrecio)) {
			retorno = controller_saveAsText("mapeado.csv", pArrayListBook);
		}
	}
	return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayListBook)
{
	int retorno;
	FILE* pFile;

	retorno = -3; // path o LL nulo

	if (path != NULL && pArrayListBook != NULL) {
		retorno = -2; // no se pudo abrir el archivo
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			retorno = saveAsText(pFile, pArrayListBook); // -1 si no pudo guardar nada, 0 si guardó al menos una vez
			fclose(pFile);
		}
	}
    return retorno;
}

int saveAsText(FILE* pFile, LinkedList* pArrayListBook) {
	int retorno;
	int longitud;
	eLibro* pLibro;
	int idAGuardar;
	char tituloAGuardar[LEN_AUTOR_TITULO];
	char autorAGuardar[LEN_AUTOR_TITULO];
	float precioAGuardar;
	int idEditorialAGuardar;

	retorno = -1;

	if (pFile != NULL && pArrayListBook != NULL) {
		longitud = ll_len(pArrayListBook);

		fprintf(pFile,"id,titulo,autor,precio,idEditorial\n");
		for (int i = 0; i < longitud; i++) {
			pLibro = (eLibro*) ll_get(pArrayListBook, i);
			if (!libro_getAll(pLibro, &idAGuardar, tituloAGuardar, autorAGuardar, &precioAGuardar, &idEditorialAGuardar) &&
				fprintf(pFile,"%d,%s,%s,%.2f,%d\n", idAGuardar, tituloAGuardar, autorAGuardar, precioAGuardar, idEditorialAGuardar)) {
				retorno = 0;
			}
		}
	}
	return retorno;
}
