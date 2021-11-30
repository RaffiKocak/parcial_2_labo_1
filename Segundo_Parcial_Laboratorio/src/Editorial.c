/*
 * Editorial.c
 *
 *  Created on: 24 nov 2021
 *      Author: Raffi
 */

#include "Editorial.h"

//----------------------------------------CONSTRUCTORES------------------------------------------------

eEditorial* editorial_new() {
	eEditorial* pNuevaEditorial;

	pNuevaEditorial = NULL;
	pNuevaEditorial = (eEditorial*) calloc(sizeof(eEditorial), 1);

	return pNuevaEditorial;
}

eEditorial* editorial_newParametros(char* idEditorialStr, char* nombreStr) {
	eEditorial* pNuevaEditorial;
	eEditorial* pEditorialAux;
	int auxId;

	pNuevaEditorial = NULL;
	pEditorialAux = editorial_new();

	if (pEditorialAux != NULL && idEditorialStr != NULL && nombreStr != NULL) {
		auxId = atoi(idEditorialStr);

		if (!editorial_setAll(pEditorialAux, auxId, nombreStr)) {
			pNuevaEditorial = pEditorialAux;
		} else {
			editorial_delete(pEditorialAux);
		}
	}

	return pNuevaEditorial;
}

//----------------------------------------DESTRUCTORES------------------------------------------------

void editorial_delete(eEditorial* this) {
	if (this != NULL) {
		free(this);
	}
}

void editorial_deleteAll(LinkedList* pArrayListEditorial) {
	eEditorial* this;
	int longitud;

	if (pArrayListEditorial != NULL) {
		longitud = ll_len(pArrayListEditorial);
		for (int i = 0; i < longitud; i++) {
			this = (eEditorial*) ll_get(pArrayListEditorial, i);
			editorial_delete(this);
		}
	}
}

//----------------------------------------GETTERS Y SETTERS------------------------------------------------


int editorial_setIdEditorial(eEditorial* this, int idEditorial) {
	int retorno;

	retorno = -1;

	if (idEditorial >= 0 && this != NULL) {
		this->idEditorial = idEditorial;
		retorno = 0;
	}
	return retorno;
}

int editorial_getIdEditorial(eEditorial* this, int* idEditorial) {
	int retorno;

	retorno = -1;

	if (idEditorial != NULL && this != NULL) {
		*idEditorial = this->idEditorial;
		retorno = 0;
	}

	return retorno;
}

int editorial_setNombre(eEditorial* this, char* nombre) {
	int retorno;

	retorno = -1;

	if (nombre != NULL && strlen(nombre) > 0 && this != NULL) {
		strncpy(this->nombre, nombre, LEN_NOMBRE);
		retorno = 0;
	}

	return retorno;
}

int editorial_getNombre(eEditorial* this, char* nombre) {
	int retorno;

	retorno = -1;

	if (nombre != NULL && this != NULL) {
		strncpy(nombre, this->nombre, LEN_NOMBRE);
		retorno = 0;
	}

	return retorno;
}

int editorial_setAll(eEditorial* this, int idEditorial, char* nombre) {
	int retorno;

	retorno = -1;

	if (this != NULL &&
		!editorial_setIdEditorial(this, idEditorial) &&
		!editorial_setNombre(this, nombre)) {
		retorno = 0;
	}

	return retorno;
}

int editorial_getAll(eEditorial* this, int* idEditorial, char* nombre) {
	int retorno;

	retorno = -1;

	if (this != NULL &&
		!editorial_getIdEditorial(this, idEditorial) &&
		!editorial_getNombre(this, nombre)) {
		retorno = 0;
	}

	return retorno;
}
