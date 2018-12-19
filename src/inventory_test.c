/** @file inventory_test.c
* @date 20/3/2017
* @author Jose Maria Castro
* @brief Testeo del módulo inventory. 
* Se incluyen las ficheros de cabecera stdio.h, stdlib.h, string.h, inventory_test.h e inventory.h 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/inventory.h"
#include "../include/test.h"
#include "../include/set.h"
#include "../include/types.h"
#include "../include/inventory_test.h"

#define MAX_TESTS 16


int main(int argc, char **argv){
    int test = 0;
    int todas = 1;

    if (argc < 2) {
        printf("Running all tests for module inventory:\n");
    } else {
        test = atoi(argv[1]);
        todas = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (todas || test == 1) test1_inventory_create();
    if (todas || test == 2) test2_inventory_create();
    if (todas || test == 3) test1_inventory_add_object();
    if (todas || test == 4) test2_inventory_add_object();
    if (todas || test == 5) test3_inventory_add_object();
    if (todas || test == 6) test1_inventory_del_object();
    if (todas || test == 7) test2_inventory_del_object();
    if (todas || test == 8) test3_inventory_del_object();
    if (todas || test == 9) test1_inventory_get_n_objects();
    if (todas || test == 10) test2_inventory_get_n_objects();
    if (todas || test == 11) test1_inventory_get_capacity();
    if (todas || test == 12) test2_inventory_get_capacity();
    if (todas || test == 13) test1_inventory_set_capacity();
    if (todas || test == 14) test2_inventory_set_capacity();
    if (todas || test == 15) test1_inventory_print();
    if (todas || test == 16) test2_inventory_print();
    
    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_inventory_create(){
    int result=inventory_create(4)!=NULL;
    PRINT_TEST_RESULT(result);
}

void test2_inventory_create(){  /*No se muy bien como comprobar que esto lo hace bien*/
    Inventory *i;
    
    i=inventory_create(3);
    
    PRINT_TEST_RESULT(inventory_get_capacity(i)==3);
}


void test1_inventory_add_object(){
    Inventory *i;
    
    i=inventory_create(5);
    
    PRINT_TEST_RESULT(inventory_add_object(i, -1)==ERROR);
}

void test2_inventory_add_object(){
    Inventory *i;
    
    
    i=inventory_create(4);
    
    PRINT_TEST_RESULT(inventory_add_object(i, 3)==OK);
}

void test3_inventory_add_object(){
    Inventory *i;
    
    i=NULL;
    
    PRINT_TEST_RESULT(inventory_add_object(i, 5)==ERROR);

}

void test1_inventory_del_object(){
    Inventory *i;
    
    i=inventory_create(3);
    
    inventory_add_object(i, 0);
    
    PRINT_TEST_RESULT(inventory_del_object(i, 0)==OK);
}

void test2_inventory_del_object(){
    Inventory *i;
    
    i=NULL;
    
    PRINT_TEST_RESULT(inventory_del_object(i, 4)==ERROR);
}

void test3_inventory_del_object(){
    Inventory *i;
    
    i=inventory_create(5);
    
    PRINT_TEST_RESULT(inventory_del_object(i, -1)==ERROR);
}

void test1_inventory_get_n_objects(){
    Inventory *i;
    
    i=inventory_create(6);
    
    inventory_add_object(i, 3);
    
    PRINT_TEST_RESULT(inventory_get_n_objects(i)==1);
}

void test2_inventory_get_n_objects(){
    Inventory *i;
    
    i=NULL;
    
    PRINT_TEST_RESULT(inventory_get_n_objects(i)==-1);
}

void test1_inventory_get_capacity(){
    Inventory *i;
    
    i=inventory_create(5);
    
    inventory_set_capacity(i,6);
    
    PRINT_TEST_RESULT(inventory_get_capacity(i)==6);
}

void test2_inventory_get_capacity(){
    Inventory *i;
    
    i=NULL;
    
    PRINT_TEST_RESULT(inventory_get_capacity(i)==-1);
}

void test1_inventory_set_capacity(){ 
    Inventory *i;
    
    i=inventory_create(3);
    
    PRINT_TEST_RESULT(inventory_set_capacity(i, 7)==OK);
}

void test2_inventory_set_capacity(){
    
    Inventory *i;
    i = NULL;
    
    PRINT_TEST_RESULT(inventory_set_capacity(i, 3) ==ERROR );

}

void test1_inventory_print() {
    Inventory *i = NULL;
    PRINT_TEST_RESULT(inventory_print(i) == ERROR);

}

void test2_inventory_print() {
    Inventory *i;
    i = inventory_create(3);
    
    PRINT_TEST_RESULT(inventory_print(i) == OK);
}