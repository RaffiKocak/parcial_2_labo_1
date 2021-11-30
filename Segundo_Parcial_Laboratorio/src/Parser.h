/*
 * Parser.h
 *
 *  Created on: 24 nov 2021
 *      Author: Raffi
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "Libro.h"

/// @brief Parsea los datos de los libros desde el archivo .csv
///
/// @param pFile
/// @param pArrayListBook
/// @return
int parser_BookFromText(FILE* pFile, LinkedList* pArrayListBook);

/// @brief Parsea los datos de las editoriales desde el archivo .csv
///
/// @param pFile
/// @param pArrayListEditorial
/// @return
int parser_EditorialFromText(FILE* pFile, LinkedList* pArrayListEditorial);


#endif /* PARSER_H_ */
