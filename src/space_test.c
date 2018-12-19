/** @file space_test.c
* @date 20/3/2017
* @author Jose Maria Castro
* @brief Testeo del módulo space. 
* Se incluyen las ficheros de cabecera stdio.h, stdlib.h, string.h, space_test.h e space.h 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/space.h"
#include "../include/test.h"
#include "../include/set.h"
#include "../include/types.h"
#include "../include/space_test.h"
#define MAX_TESTS 47

int main(int argc, char **argv){
    int test = 0;
    int todas = 1;

    if (argc < 2) {
        printf("Running all tests for m odule space:\n");
    } else {
        test = atoi(argv[1]);
        todas = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }

    if (todas || test == 1) test1_space_create();
    if (todas || test == 2) test1_space_destroy();
    if (todas || test == 3) test2_space_destroy();
    if (todas || test == 4) test1_space_get_id();
    if (todas || test == 5) test2_space_get_id();
    if (todas || test == 6) test1_space_set_name();
    if (todas || test == 7) test2_space_set_name();
    if (todas || test == 8) test1_space_get_name();
    if (todas || test == 9) test2_space_get_name();
    if (todas || test == 10) test1_space_set_description1();
    if (todas || test == 11) test2_space_set_description1();
    if (todas || test == 12) test1_space_get_description1();
    if (todas || test == 13) test2_space_get_description1();
    if (todas || test == 14) test1_space_set_description2();
    if (todas || test == 15) test2_space_set_description2();
    if (todas || test == 16) test1_space_get_description2();
    if (todas || test == 17) test2_space_get_description2();
    if (todas || test == 18) test1_space_set_north_link();
    if (todas || test == 19) test2_space_set_north_link();
    if (todas || test == 20) test1_space_get_north_link();
    if (todas || test == 21) test2_space_get_north_link();
    if (todas || test == 22) test1_space_set_south_link();
    if (todas || test == 23) test2_space_set_south_link();
    if (todas || test == 24) test1_space_get_south_link();
    if (todas || test == 25) test2_space_get_south_link();
    if (todas || test == 26) test1_space_set_east_link();
    if (todas || test == 27) test2_space_set_east_link();
    if (todas || test == 28) test1_space_get_east_link();
    if (todas || test == 29) test2_space_get_east_link();
    if (todas || test == 30) test1_space_set_west_link();
    if (todas || test == 31) test2_space_set_west_link();
    if (todas || test == 32) test1_space_get_west_link();
    if (todas || test == 33) test2_space_get_west_link();
    if (todas || test == 34) test1_space_set_up_link();
    if (todas || test == 35) test2_space_set_up_link();
    if (todas || test == 36) test1_space_get_up_link();
    if (todas || test == 37) test2_space_get_up_link();
    if (todas || test == 38) test1_space_set_down_link();
    if (todas || test == 39) test2_space_set_down_link();
    if (todas || test == 40) test1_space_get_down_link();
    if (todas || test == 41) test2_space_get_down_link();
    if (todas || test == 42) test1_space_set_is_lit();
    if (todas || test == 43) test2_space_set_is_lit();
    if (todas || test == 44) test1_space_get_is_lit();
    if (todas || test == 45) test2_space_get_is_lit();
    if (todas || test == 46) test1_space_print();
    if (todas || test == 47) test2_space_print();
    
    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_space_create(){
    int result=space_create(4)!=NULL;
    PRINT_TEST_RESULT(result);
}

void test1_space_destroy(){
    Space *s;
    
    s = space_create(4);
    PRINT_TEST_RESULT(space_destroy(s)==OK);
}

void test2_space_destroy(){
  Space *s = NULL;
  
  PRINT_TEST_RESULT(space_destroy(s)==ERROR);
}

void test1_space_set_name(){
    Space *s;
    
    s = space_create(4);
    PRINT_TEST_RESULT(space_set_name(s, "algo")==OK);
}

void test2_space_set_name(){
    Space *s = NULL;
    
     PRINT_TEST_RESULT(space_set_name(s, "algo")==ERROR);
}

void test1_space_get_name(){
     Space *s;
    
    s = space_create(4);
    space_set_name(s, "algo");
    PRINT_TEST_RESULT(strcmp(space_get_name(s),"algo")== 0);
}

void test2_space_get_name(){
    Space *s = NULL;
    
    PRINT_TEST_RESULT(space_get_name(s)== NULL);
}

void test1_space_get_id(){
    Space *s;
    
    s = space_create(4);
    PRINT_TEST_RESULT(space_get_id(s)==4);
}

void test2_space_get_id(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_get_id(s)==-1);
}

void test1_space_set_description1(){
    Space *s;
    
    s = space_create(4);
    PRINT_TEST_RESULT(space_set_description(s, "algo")==OK);
}

void test2_space_set_description1(){
    Space *s = NULL;
    
     PRINT_TEST_RESULT(space_set_description(s, "algo")==ERROR);
}

void test1_space_get_description1(){
     Space *s;
    
    s = space_create(4);
    space_set_description(s, "algo");
    PRINT_TEST_RESULT(strcmp(space_get_description(s),"algo")== 0);
}

void test2_space_get_description1(){
    Space *s = NULL;
    
    PRINT_TEST_RESULT(space_get_description(s)== NULL);
}

void test1_space_set_description2(){
    Space *s;
    
    s = space_create(4);
    PRINT_TEST_RESULT(space_set_description2(s, "algo")==OK);
}

void test2_space_set_description2(){
    Space *s = NULL;
    
     PRINT_TEST_RESULT(space_set_description2(s, "algo")==ERROR);
}

void test1_space_get_description2(){
     Space *s;
    
    s = space_create(4);
    space_set_description2(s, "algo");
    PRINT_TEST_RESULT(strcmp(space_get_description2(s),"algo")== 0);
}

void test2_space_get_description2(){
    Space *s = NULL;
    
    PRINT_TEST_RESULT(space_get_description2(s)== NULL);
}

void test1_space_set_north_link(){
    Space *s;
    
    s = space_create(4);
    PRINT_TEST_RESULT(space_set_north_link(s,4)==OK);
}

void test2_space_set_north_link(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_get_north_link(s)==-1);
}

void test1_space_get_north_link(){
    Space *s;
    
    s = space_create(4);
    space_set_north_link(s,4);
    PRINT_TEST_RESULT(space_get_north_link(s)==4);
}

void test2_space_get_north_link(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_get_north_link(s)==-1);
}

void test1_space_set_south_link(){
    Space *s;
    
    s = space_create(4);
    PRINT_TEST_RESULT(space_set_south_link(s,4)==OK);
}

void test2_space_set_south_link(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_get_south_link(s)==-1);
}

void test1_space_get_south_link(){
    Space *s;
    
    s = space_create(4);
    space_set_south_link(s,4);
    PRINT_TEST_RESULT(space_get_south_link(s)==4);
}

void test2_space_get_south_link(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_get_south_link(s)==-1);
}

void test1_space_set_east_link(){
    Space *s;
    
    s = space_create(4);
    PRINT_TEST_RESULT(space_set_east_link(s,4)==OK);
}

void test2_space_set_east_link(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_get_east_link(s)==-1);
}

void test1_space_get_east_link(){
    Space *s;
    
    s = space_create(4);
    space_set_east_link(s,4);
    PRINT_TEST_RESULT(space_get_east_link(s)==4);
}

void test2_space_get_east_link(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_get_east_link(s)==-1);
}

void test1_space_set_west_link(){
    Space *s;
    
    s = space_create(4);
    PRINT_TEST_RESULT(space_set_west_link(s,4)==OK);
}

void test2_space_set_west_link(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_get_west_link(s)==-1);
}

void test1_space_get_west_link(){
    Space *s;
    
    s = space_create(4);
    space_set_west_link(s,4);
    PRINT_TEST_RESULT(space_get_west_link(s)==4);
}

void test2_space_get_west_link(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_get_west_link(s)==-1);
}

void test1_space_set_up_link(){
    Space *s;
    
    s = space_create(4);
    PRINT_TEST_RESULT(space_set_up_link(s,4)==OK);
}

void test2_space_set_up_link(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_get_up_link(s)==-1);
}

void test1_space_get_up_link(){
    Space *s;
    
    s = space_create(4);
    space_set_up_link(s,4);
    PRINT_TEST_RESULT(space_get_up_link(s)==4);
}

void test2_space_get_up_link(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_get_up_link(s)==-1);
}

void test1_space_set_down_link(){
    Space *s;
    
    s = space_create(4);
    PRINT_TEST_RESULT(space_set_down_link(s,4)==OK);
}

void test2_space_set_down_link(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_set_down_link(s,4)==ERROR);
}

void test1_space_get_down_link(){
    Space *s;
    
    s = space_create(4);
    space_set_down_link(s,4);
    PRINT_TEST_RESULT(space_get_down_link(s)==4);
}

void test2_space_get_down_link(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_get_down_link(s)==-1);
}

void test1_space_set_is_lit(){
    Space *s;
    
    s = space_create(4);
    PRINT_TEST_RESULT(space_set_is_lit(s,TRUE)==OK);
}

void test2_space_set_is_lit(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_set_is_lit(s, TRUE)==ERROR);
}

void test1_space_get_is_lit(){
    Space *s;
    
    s = space_create(4);
    space_set_is_lit(s,TRUE);
    PRINT_TEST_RESULT(space_get_is_lit(s)==TRUE);
}

void test2_space_get_is_lit(){
    Space *s = NULL;
   
    PRINT_TEST_RESULT(space_get_is_lit(s)==FALSE);
}

void test1_space_print() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_print(s) == ERROR);
}

void test2_space_print() {
    Space *s;
    s = space_create(3);
    
    PRINT_TEST_RESULT(space_print(s) == OK);
}