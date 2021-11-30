/*
 * Libro.c
 *
 *  Created on: 24 nov 2021
 *      Author: Raffi
 */

#include "Libro.h"

//----------------------------------------CONSTRUCTORES------------------------------------------------

eLibro* libro_new() {
	eLibro* pNuevoLibro;

	pNuevoLibro = NULL;
	pNuevoLibro = (eLibro*) calloc(sizeof(eLibro), 1);

	return pNuevoLibro;
}

eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* idEditorialStr) {

	eLibro* pNuevoLibro;
	eLibro* pLibroAux;
	int auxId;
	float auxPrecio;
	int auxIdEditorial;

	pNuevoLibro = NULL;
	pLibroAux = libro_new();

	if (pLibroAux != NULL && idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL
			&& idEditorialStr != NULL) {
		auxId = atoi(idStr);
		auxPrecio = atof(precioStr);
		auxIdEditorial = atoi(idEditorialStr);

		if (!libro_setAll(pLibroAux, auxId, tituloStr, autorStr, auxPrecio, auxIdEditorial)) {
			pNuevoLibro = pLibroAux;
		} else {
			libro_delete(pLibroAux);
		}

	}

	return pNuevoLibro;
}

//----------------------------------------DESTRUCTORES------------------------------------------------

void libro_delete(eLibro* this) {
	if (this != NULL) {
		free(this);
	}
}

void libro_deleteAll(LinkedList* pArrayListLibro) {
	eLibro* this;
	int longitud;

	if (pArrayListLibro != NULL) {
		longitud = ll_len(pArrayListLibro);
		for (int i = 0; i < longitud; i++) {
			this = (eLibro*) ll_get(pArrayListLibro, i);
			libro_delete(this);
		}
	}
}

//----------------------------------------GETTERS Y SETTERS------------------------------------------------

int libro_setId(eLibro* this, int id) {
	int retorno;

	retorno = -1;

	if (id >= 0 && this != NULL) {
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int libro_getId(eLibro* this, int* id) {
	int retorno;

	retorno = -1;

	if (id != NULL && this != NULL) {
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int libro_setTitulo(eLibro* this, char* titulo) {
	int retorno;

	retorno = -1;

	if (titulo != NULL && strlen(titulo) > 0 && this != NULL) {
		strncpy(this->titulo, titulo, LEN_AUTOR_TITULO);
		retorno = 0;
	}

	return retorno;
}

int libro_getTitulo(eLibro* this, char* titulo) {
	int retorno;

	retorno = -1;

	if (titulo != NULL && this != NULL) {
		strncpy(titulo, this->titulo, LEN_AUTOR_TITULO);
		retorno = 0;
	}

	return retorno;
}

int libro_setAutor(eLibro* this, char* autor) {
	int retorno;

	retorno = -1;

	if (autor != NULL && strlen(autor) > 0 && this != NULL) {
		strncpy(this->autor, autor, LEN_AUTOR_TITULO);
		retorno = 0;
	}

	return retorno;
}

int libro_getAutor(eLibro* this, char* autor) {
	int retorno;

	retorno = -1;

	if (autor != NULL && this != NULL) {
		strncpy(autor, this->autor, LEN_AUTOR_TITULO);
		retorno = 0;
	}

	return retorno;
}

int libro_setPrecio(eLibro* this, float precio) {
	int retorno;

	retorno = -1;

	if (precio >= 0 && this != NULL) {
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}

int libro_getPrecio(eLibro* this, float* precio) {
	int retorno;

	retorno = -1;

	if (precio != NULL && this != NULL) {
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

int libro_setIdEditorial(eLibro* this, int idEditorial) {
	int retorno;

	retorno = -1;

	if (idEditorial >= 0 && this != NULL) {
		this->idEditorial = idEditorial;
		retorno = 0;
	}

	return retorno;
}

int libro_getIdEditorial(eLibro* this, int* idEditorial) {
	int retorno;

	retorno = -1;

	if (idEditorial != NULL && this != NULL) {
		*idEditorial = this->idEditorial;
		retorno = 0;
	}

	return retorno;
}

int libro_setAll(eLibro* this, int id, char* titulo, char* autor, float precio, int idEditorial) {
	int retorno;

	retorno = -1;

	if (this != NULL &&
		!libro_setId(this, id) &&
		!libro_setTitulo(this, titulo) &&
		!libro_setAutor(this, autor) &&
		!libro_setPrecio(this,precio) &&
		!libro_setIdEditorial(this, idEditorial)) {
		retorno = 0;
	}

	return retorno;
}

int libro_getAll(eLibro* this, int* id, char* titulo, char* autor, float* precio, int* idEditorial) {
	int retorno;

	retorno = -1;

	if (this != NULL &&
		!libro_getId(this, id) &&
		!libro_getTitulo(this, titulo) &&
		!libro_getAutor(this, autor) &&
		!libro_getPrecio(this,precio) &&
		!libro_getIdEditorial(this, idEditorial)) {
		retorno = 0;
	}

	return retorno;
}

int libro_getNombreEditorial(eLibro* this, LinkedList* listaEditorial, char* nombreEditorial) {
	int retorno;
	eEditorial* pEditorial;
	int len;
	int idEditorial;
	int idEditorialLibro;

	retorno = -1;

	if (this != NULL && listaEditorial != NULL && nombreEditorial != NULL) {
		len = ll_len(listaEditorial);
		libro_getIdEditorial(this, &idEditorialLibro);
		//modularizar esto en una función
		for (int i = 0; i < len; i++) {
			pEditorial = (eEditorial*) ll_get(listaEditorial, i);
			if (pEditorial != NULL && !editorial_getIdEditorial(pEditorial, &idEditorial) && idEditorial == idEditorialLibro) {
				editorial_getNombre(pEditorial, nombreEditorial);
				retorno = 0;
				break;
			}
		}
		//hasta acá
	}

	return retorno;
}


//----------------------------------------PRINT------------------------------------------------

void libro_printLibro(eLibro* this, LinkedList* listaEditorial) {
	int auxId;
	char auxTitulo[LEN_AUTOR_TITULO];
	char auxAutor[LEN_AUTOR_TITULO];
	float auxPrecio;
	char nombreEditorial[50];

	if (!libro_getNombreEditorial(this, listaEditorial, nombreEditorial) && !libro_getId(this, &auxId) && !libro_getTitulo(this, auxTitulo) &&
			!libro_getAutor(this, auxAutor) && !libro_getPrecio(this, &auxPrecio)) {
		printf("%-7d %-15s %-23s %-10.2f %s\n", auxId, auxTitulo, auxAutor, auxPrecio, nombreEditorial);
		printf("------------------------------------------------------------------------------\n");
	}
}

//----------------------------------------COMPARACIONES Y CRITERIOS------------------------------------------------

int libro_compareByAutor(void* primerLibro, void* segundoLibro) {
	int comparacion;
	eLibro* pPrimerLibro;
	eLibro* pSegundoLibro;
	char primerAutor[LEN_AUTOR_TITULO];
	char segundoAutor[LEN_AUTOR_TITULO];

	comparacion = 0;

	if (primerLibro != NULL && segundoLibro != NULL) {
		pPrimerLibro = (eLibro*) primerLibro;
		pSegundoLibro = (eLibro*) segundoLibro;

		if (!libro_getAutor(pPrimerLibro, primerAutor) && !libro_getAutor(pSegundoLibro, segundoAutor)) {
			comparacion = strncmp(primerAutor, segundoAutor, LEN_AUTOR_TITULO);
		}
	}
	return comparacion;
}

int libro_verificarEditorialMinotauro(void* this) {
	int retorno;
	eLibro* pLibro;
	int idEditorial;

	retorno = 0;

	if (this != NULL) {

		pLibro = (eLibro*) this;
		if (!libro_getIdEditorial(pLibro, &idEditorial) && idEditorial == 4) {
			retorno = 1;
		}
	}

	return retorno;
}

int libro_ajustarPrecio (void* this) {
	int retorno;
	eLibro* auxLibro;
	float precio;
	int idEditorial;

	retorno = -1;

	if (this != NULL) {
		auxLibro = (eLibro*) this;
//		* PLANETA: 20% (si el monto es mayor o igual a $300)
//		* SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)
		if (!libro_getPrecio(auxLibro, &precio) && !libro_getIdEditorial(auxLibro, &idEditorial)) {
			if (precio >= 300 && idEditorial == 1) {
				precio = precio - precio * 20 / 100;
				libro_setPrecio(auxLibro, precio);
			} else if (precio <= 100 && idEditorial == 2) {
				precio = precio - precio * 10 / 100;
				libro_setPrecio(auxLibro, precio);
			}
			retorno = 0;
		}
	}
	return retorno;
}
