/** @file set_test.c
* @date 17/3/2017
* @author Jose Maria Castro
* @brief Testeo de los objetos. 
* Se incluyen las ficheros de cabecera stdio.h, stdlib.h, string.h, set_test.h y set.h
*/
#ifndef SET_TEST_H
#define SET_TEST_H


/**
* @author Jose Maria Castro
* @brief comprobación al crear el set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/   
void test1_set_create();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al destruir el set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test1_set_destroy();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al destruir el set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test2_set_destroy();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al añadir un objeto el set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test1_set_add();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al añadir un objeto el set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test2_set_add();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al quitar un objeto el set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test1_set_del();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al quitar un objeto el set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test2_set_del();

/**
* @author Jose Maria Castro
* @brief comprobación del tercer caso posible al quitar un objeto el set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test3_set_del();

/**
* @author Jose Maria Castro
* @brief comprobación del cuarto caso posible al quitar un objeto el set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test4_set_del();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al quitar conseguir el número de objetos del set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test1_set_get_n_elements();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al quitar conseguir el número de objetos del set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test2_set_get_n_elements();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir un objeto del set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test1_set_get_element();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir un objeto del set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test2_set_get_element();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al encontrar un objeto del set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test1_set_find_id();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al encontrar un objeto del set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test2_set_find_id();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al imprimir por pantalla un set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test1_set_print();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al imprimir por pantalla un set
* @date 20/3/2017
* @file set_test.h
* @version 1.0
*/
void test2_set_print();
   
#endif   