/** @file player_test.c
* @date 20/3/2017
* @author Jose Maria Castro
* @brief Testeo del módulo player. 
* Se incluyen las ficheros de cabecera stdio.h, stdlib.h, string.h, player_test.h e inventory.h 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/inventory.h"
#include "../include/test.h"
#include "../include/types.h"
#include "../include/player_test.h"
#include "../include/player.h"

#define MAX_TESTS 19


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


    if (todas || test == 1) test1_player_create();
    if (todas || test == 2) test1_player_destroy();
    if (todas || test == 3) test2_player_destroy();
    if (todas || test == 4) test1_player_set_name();
    if (todas || test == 5) test2_player_set_name();
    if (todas || test == 6) test1_player_get_name();
    if (todas || test == 7) test2_player_get_name();
    if (todas || test == 8) test1_player_get_id();
    if (todas || test == 9) test2_player_get_id();
    if (todas || test == 10) test1_player_set_location();
    if (todas || test == 11) test2_player_set_location();
    if (todas || test == 12) test1_player_get_location();
    if (todas || test == 13) test2_player_get_location();
    if (todas || test == 14) test1_player_set_inventory();
    if (todas || test == 15) test2_player_set_inventory();
    if (todas || test == 16) test1_player_get_inventory();
    if (todas || test == 17) test2_player_get_inventory();
    if (todas || test == 18) test1_player_print();
    if (todas || test == 19) test2_player_print();
    
    PRINT_PASSED_PERCENTAGE;
    
    
    return 1;
}

void test1_player_create(){
    Player *p;
    p=player_create(4);
    
    PRINT_TEST_RESULT(player_get_id(p)==4);
}

void test1_player_destroy(){
    Player *p;
    
    p = player_create(4);
    PRINT_TEST_RESULT(player_destroy(p)==OK);
}

void test2_player_destroy(){
  Player *p = NULL;
  
  PRINT_TEST_RESULT(player_destroy(p)==ERROR);
}

void test1_player_set_name(){
    Player *p;
    
    p = player_create(4);
    PRINT_TEST_RESULT(player_set_name(p, "algo")==OK);
}

void test2_player_set_name(){
    Player *p = NULL;
    
     PRINT_TEST_RESULT(player_set_name(p, "algo")==ERROR);
}

void test1_player_get_name(){
     Player *p;
    
    p = player_create(4);
    player_set_name(p, "algo");
    PRINT_TEST_RESULT(strcmp(player_get_name(p),"algo")== 0);
}

void test2_player_get_name(){
    Player *p = NULL;
    
    PRINT_TEST_RESULT(player_get_name(p)== NULL);
}

void test1_player_get_id(){
    Player *p;
    
    p = player_create(4);
    PRINT_TEST_RESULT(player_get_id(p)==4);
}

void test2_player_get_id(){
    Player *p = NULL;
   
    PRINT_TEST_RESULT(player_get_id(p)==-1);
}

void test1_player_set_location(){
    Player *p;
    
    p = player_create(4);
    PRINT_TEST_RESULT(player_set_location(p,3)==OK);
}

void test2_player_set_location(){
    Player *p = NULL;
    
    PRINT_TEST_RESULT(player_set_location(p,3)==ERROR);
}

void test1_player_get_location(){
    Player *p;
    
    p = player_create(4);
    player_set_location(p,3);
    PRINT_TEST_RESULT(player_get_location(p)==3);
}

void test2_player_get_location(){
    Player *p = NULL;
    
    PRINT_TEST_RESULT(player_get_location(p)==-1);
}

void test1_player_set_inventory(){
    Player *p;
    Inventory *i;
    
    p = player_create(4);
    i = inventory_create(4);
    PRINT_TEST_RESULT(player_set_inventory(p,i) == OK);
}

void test2_player_set_inventory(){
    Player *p = NULL;
    Inventory *i = NULL;
    
    PRINT_TEST_RESULT(player_set_inventory(p,i) == ERROR);
}

void test1_player_get_inventory(){
    Player *p;
    Inventory *i;
    
    p = player_create(4);
    i = inventory_create(4);
    
    player_set_inventory(p,i);
    
    PRINT_TEST_RESULT(player_get_inventory(p) == i);
}

void test2_player_get_inventory(){
    Player *p = NULL;
    
    PRINT_TEST_RESULT(player_get_inventory(p) == NULL);
}

void test1_player_print(){
    Player *p = NULL;
    PRINT_TEST_RESULT(player_print(p) == ERROR);
}

void test2_player_print(){
    Player *p;
    p = player_create(3);
    
    PRINT_TEST_RESULT(player_print(p) == OK);
}