/*
 * Editorial.h
 *
 *  Created on: 24 nov 2021
 *      Author: Raffi
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#include "Input.h"
#include "LinkedList.h"
#define LEN_NOMBRE 128

typedef struct
{
    int idEditorial;
    char nombre[LEN_NOMBRE];
}eEditorial;


/// @brief Constructor por defecto de una editorial en memoria dinámica
///
/// @return
eEditorial* editorial_new();

/// @brief Constructor parametrizado de una editorial en memoria dinámica
///
/// @param idStr
/// @param tituloStr
/// @param autorStr
/// @param precioStr
/// @param idEditorialStr
/// @return
eEditorial* editorial_newParametros(char* idEditorialStr, char* nombre);

/// @brief Elimina los datos de una editorial liberando su posición reservada en memoria RAM.
///
/// @param this
void editorial_delete(eEditorial* this);

/// @brief Elimina los datos de todas las editoriales liberando sus posiciones reservadas en memoria RAM.
///
/// @param pArrayListLibro
void editorial_deleteAll(LinkedList* pArrayListEditorial);

int editorial_setIdEditorial(eEditorial* this, int idEditorial);
int editorial_getIdEditorial(eEditorial* this, int* idEditorial);
int editorial_setNombre(eEditorial* this, char* nombre);
int editorial_getNombre(eEditorial* this, char* nombre);

int editorial_setAll(eEditorial* this, int idEditorial, char* nombre);
int editorial_getAll(eEditorial* this, int* idEditorial, char* nombre);


#endif /* EDITORIAL_H_ */
