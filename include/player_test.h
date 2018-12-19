/** @file player_test.c
* @date 17/3/2017
* @author Jose Maria Castro
* @brief Testeo de los objetos. 
* Se incluyen las ficheros de cabecera stdio.h, stdlib.h, string.h, player_test.h y player.h
*/
#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H


/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al crear el player
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test1_player_create();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al destruir el player
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test1_player_destroy();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al destruir el player
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test2_player_destroy();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiarle el nombre al jugador
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test1_player_set_name();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiarle el nombre al jugadpr
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test2_player_set_name();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir el nombre
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test1_player_get_name();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir el nombre
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test2_player_get_name();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al obtener la id del jugador
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test1_player_get_id();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al obtener la id del jugador
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/


void test2_player_get_id();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiarle el espacio
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test1_player_set_location();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiarle el espacio
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test2_player_set_location();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al obtener el espacio del jugador
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test1_player_get_location();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al obtener el espacio del jugador
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test2_player_get_location();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiarle el inventario
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test1_player_set_inventory();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiarle el inventory
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test2_player_set_inventory();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al obtener el inventario del jugador
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test1_player_get_inventory();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al obtener el inventario del jugador
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test2_player_get_inventory();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al imprimir por pantalla un jugador
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test1_player_print();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al imprimir por pantalla un jugador
* @date 20/3/2017
* @file player_test.h
* @version 1.0
*/

void test2_player_print();

#endif