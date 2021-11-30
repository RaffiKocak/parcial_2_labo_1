/*
 * View.h
 *
 *  Created on: 8 nov 2021
 *      Author: Raffi
 */

#ifndef VIEW_H_
#define VIEW_H_

#include <stdio.h>
#include <String.h>

/// @brief Imprime el menú principal del programa
///
void ImprimirMenuPrincipal();

/// @brief Muestra mensajes determinados según el retorno del controller de carga de datos
///
/// @param output
void view_returnsFromLoad(int output);

/// @brief Muestra mensajes determinados según el retorno del controller de Print o Sort que llama
///
/// @param output
/// @param PrintOrSort
void view_returnsFromPrintSort(int output, char* PrintOrSort);

/// @brief Muestra mensajes determinados según el retorno del controller de Filter
///
/// @param output
void view_returnsFromFilter(int output);

#endif /* VIEW_H_ */
