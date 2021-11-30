/*
 * Controller.h
 *
 *  Created on: 24 nov 2021
 *      Author: Raffi
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Parser.h"

/// @brief Carga los datos de libros o editoriales desde un archivo .csv
///
/// @param pArrayList
/// @param pFunc
/// @return
int controller_loadFromText(LinkedList* pArrayList, int (*pFunc)(FILE*, LinkedList*));

/// @brief Ordena los libros según el autor, de manera creciente
///
/// @param pArrayListBook
/// @return
int controller_sortBook(LinkedList* pArrayListBook);

/// @brief Muestra el listado de libros con sus editoriales correspondiente
///
/// @param pArrayListBook
/// @param pArrayListEditorial
/// @return
int controller_printBook(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial);

/// @brief Guarda en un archivo .csv una lista filtrada con todos los libros que tengan la editorial MINOTAURO (idEditorial 4)
///
/// @param pArrayListEditorial
/// @return
int controller_filterBooks(LinkedList* pArrayListEditorial);

/// @brief Guarda los datos de los libros en un archivo .csv
///
/// @param path
/// @param pArrayListBook
/// @return
int controller_saveAsText(char* path , LinkedList* pArrayListBook);

/// @brief Guarda los datos de los libros en un archivo .csv
///
/// @param pFile
/// @param pArrayListBook
/// @return
int saveAsText(FILE* pFile, LinkedList* pArrayListBook);

int controller_mapBooks(LinkedList* pArrayListBook);

#endif /* CONTROLLER_H_ */
