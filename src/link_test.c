/** @file link_test.c
* @date 20/3/2017
* @author Jose Maria Castro
* @brief Testeo del módulo links. 
* Se incluyen las ficheros de cabecera stdio.h, stdlib.h, string.h, link_test.h e link.h 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/link_test.h"
#include "../include/link.h"
#include "../include/test.h"

#define MAX_TESTS 22


int main (int argc, char** argv) {

		int test = 0;
		int all = 1;

		if (argc < 2) {
				printf("Running all test for module Links:\n");
		} else {
				test = atoi(argv[1]);
				all = 0;
				printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
		printf("Error: unknown test %d\t", test);
		exit(EXIT_SUCCESS);
				}
		}


		if (all || test == 1) test1_link_create();
		if (all || test == 2) test2_link_create();
		if (all || test == 3) test1_link_destroy();
		if (all || test == 4) test2_link_destroy();
		if (all || test == 5) test1_link_get_id();
		if (all || test == 6) test2_link_get_id();
		if (all || test == 7) test1_link_set_name();
		if (all || test == 8) test2_link_set_name();
		if (all || test == 9) test1_link_get_name();
		if (all || test == 10) test2_link_get_name();
		if (all || test == 11) test1_link_set_id1();
		if (all || test == 12) test2_link_set_id1();
		if (all || test == 13) test1_link_set_id2();
		if (all || test == 14) test2_link_set_id2();
		if (all || test == 15) test1_link_get_id1();
		if (all || test == 16) test2_link_get_id1();
		if (all || test == 17) test1_link_get_id2();
		if (all || test == 18) test2_link_get_id2();
		if (all || test == 19) test1_link_set_state();
		if (all || test == 20) test2_link_set_state();
		if (all || test == 21) test2_link_get_state();
		if (all || test == 22) test2_link_get_state();

		PRINT_PASSED_PERCENTAGE;

		return 1;
}

void test1_link_create() {
		int result = link_create(5)!=NULL ;
		PRINT_TEST_RESULT(result);
}

void test2_link_create() {
		Link *l = NULL;
		l = link_create(4);
		PRINT_TEST_RESULT(link_get_id(l) == 4);
}

void test1_link_destroy(){
    Link *l;
    
    l= link_create(4);
    PRINT_TEST_RESULT(link_destroy(l)==OK);
}

void test2_link_destroy(){
  Link *l = NULL;
  
  PRINT_TEST_RESULT(link_destroy(l)==ERROR);
}

void test1_link_get_id() {
		Link *l;
		l = link_create(25);
		PRINT_TEST_RESULT(link_get_id(l) == 25);
}

void test2_link_get_id() {
		Link *l = NULL;
		PRINT_TEST_RESULT(link_get_id(l) == NO_ID);
}

void test1_link_set_name() {
		Link *l =  NULL;
		l = link_create(5);
		PRINT_TEST_RESULT(link_set_name(l, "hola") == OK);
}

void test2_link_set_name() {
		Link *l = NULL;
		PRINT_TEST_RESULT(link_set_name(l, "hola") == ERROR);
}

void test1_link_get_name() {
		Link *l;
		l = link_create(1);
		link_set_name(l, "adios");
		PRINT_TEST_RESULT(strcmp(link_get_name(l), "adios") == 0);
}

void test2_link_get_name() {
		Link *l = NULL;
		PRINT_TEST_RESULT(link_get_name(l) == NULL);
}

void test1_link_set_id1(){
    Link *l=NULL;
    PRINT_TEST_RESULT(link_set_id1(l,5) == ERROR);
}

void test2_link_set_id1(){
    Link *l;
    
    l = link_create(4);
    PRINT_TEST_RESULT(link_set_id1(l,4)==OK);
}

void test1_link_set_id2(){
    Link *l=NULL;
    PRINT_TEST_RESULT(link_set_id2(l,3) == ERROR);
}
void test2_link_set_id2(){
    Link *l;
    
    l = link_create(4);
    PRINT_TEST_RESULT(link_set_id2(l,4)==OK);
    
}
void test1_link_get_id1(){
     Link *l;
    
     l= link_create(4);
    link_set_id1(l,4);
    PRINT_TEST_RESULT(link_get_id1(l)==4);
}

void test2_link_get_id1(){
    Link *l=NULL;
    PRINT_TEST_RESULT(link_get_id1(l) == NO_ID);
}

void test1_link_get_id2(){
    Link *l;
    
    l= link_create(4);
    link_set_id2(l,4);
    PRINT_TEST_RESULT(link_get_id2(l)==4);
}

void test2_link_get_id2(){
    Link *l=NULL;
    PRINT_TEST_RESULT(link_get_id2(l) == NO_ID);
}

void test1_link_set_state(){
    Link *l;
    l = link_create(4);
    PRINT_TEST_RESULT(link_set_state(l,TRUE)==OK);
}

void test2_link_set_state(){
    Link *l = NULL;
    PRINT_TEST_RESULT(link_set_state(l, TRUE)==ERROR);
}

void test1_link_get_state(){
    Link *l;
    l = link_create(4);
    link_set_state(l,TRUE);
    PRINT_TEST_RESULT(link_get_state(l)==TRUE);
}

void test2_link_get_state(){
    Link *l = NULL;
    PRINT_TEST_RESULT(link_get_state(l)==FALSE);
}