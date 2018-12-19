/** @file Inventory_test.c
* @date 17/3/2017
* @author Sergio Domínguez
* @brief Testeo del inventario. 
* Se incluyen las ficheros de cabecera stdio.h, stdlib.h, string.h, inventory_test.h y inventory.h
*/

#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H


/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al crear el inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/

void test1_inventory_create();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al crear el inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/

void test2_inventory_create();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al añadir un objeto al inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/

void test1_inventory_add_object();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al añadir un objeto al inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/

void test2_inventory_add_object();

/**
* @author Jose Maria Castro
* @brief comprobación del tercer caso posible al añadir un objeto al inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/

void test3_inventory_add_object();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al eliminar un objeto del inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/

void test1_inventory_del_object();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al eliminar un objeto del inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/

void test2_inventory_del_object();

/**
* @author Jose Maria Castro
* @brief comprobación del tercer caso posible al eliminar un objeto del inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/

void test3_inventory_del_object();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al obtener el numero de objetos que hay en un inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/

void test1_inventory_get_n_objects();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al obtener el numero de objetos que hay en un inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/


void test2_inventory_get_n_objects();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al obtener la capacidad de un inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/


void test1_inventory_get_capacity();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al obtener la capacidad de un inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/


void test2_inventory_get_capacity();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al establecer la capacidad de un inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/


void test1_inventory_set_capacity();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al establecer la capacidad de un inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/

void test2_inventory_set_capacity();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al imprimir por pantalla un inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/

void test1_inventory_print();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al imprimir por pantalla un inventory
* @date 20/3/2017
* @file inventory_test.h
* @version 1.0
*/

void test2_inventory_print();

#endif