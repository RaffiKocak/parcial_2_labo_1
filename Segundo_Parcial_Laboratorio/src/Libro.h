/*
 * Libro.h
 *
 *  Created on: 24 nov 2021
 *      Author: Raffi
 */

#ifndef LIBRO_H_
#define LIBRO_H_

#include "Editorial.h"
#define LEN_AUTOR_TITULO 128

typedef struct
{
    int id;
    char titulo[LEN_AUTOR_TITULO];
    char autor[LEN_AUTOR_TITULO];
    float precio;
    int idEditorial;
}eLibro;

/// @brief Constructor por defecto de un libro en memoria dinámica
///
/// @return
eLibro* libro_new();

/// @brief Constructor parametrizado de un libro en memoria dinámica
///
/// @param idStr
/// @param tituloStr
/// @param autorStr
/// @param precioStr
/// @param idEditorialStr
/// @return
eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* idEditorialStr);

/// @brief Elimina los datos de un libro liberando su posición reservada en memoria RAM.
///
/// @param this
void libro_delete(eLibro* this);

/// @brief Elimina los datos de todos los libros liberando sus posiciones reservadas en memoria RAM.
///
/// @param pArrayListLibro
void libro_deleteAll(LinkedList* pArrayListLibro);

int libro_setId(eLibro* this, int id);
int libro_getId(eLibro* this, int* id);
int libro_setTitulo(eLibro* this, char* titulo);
int libro_getTitulo(eLibro* this, char* titulo);
int libro_setAutor(eLibro* this, char* autor);
int libro_getAutor(eLibro* this, char* autor);
int libro_setPrecio(eLibro* this, float precio);
int libro_getPrecio(eLibro* this, float* precio);
int libro_setIdEditorial(eLibro* this, int idEditorial);
int libro_getIdEditorial(eLibro* this, int* idEditorial);
int libro_setAll(eLibro* this, int id, char* titulo, char* autor, float precio, int idEditorial);
int libro_getAll(eLibro* this, int* id, char* titulo, char* autor, float* precio, int* idEditorial);
int libro_getAllButId(eLibro* this, int* id, char* titulo, char* autor, float* precio);

void libro_printLibro(eLibro* this, LinkedList* listaEditorial);

int libro_compareByAutor(void* primerLibro, void* segundoLibro);

int libro_verificarEditorialMinotauro(void* this);

int libro_ajustarPrecio(void* pLibro);


#endif /* LIBRO_H_ */
