/** @file game_reader.c
* @date 13/02/2017
* @author Jose Maria Castro
* @brief Implementación de las funciones para leer espacios, objetos y links
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/game_management.h"
#include "../include/game.h"

STATUS game_reader_load_spaces(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  char description[1000] = "", description2[1000] = "";
  Id id = NO_ID, north_link = NO_ID, east_link = NO_ID, south_link = NO_ID, west_link = NO_ID, up_link = NO_ID, down_link = NO_ID;
  Space* space = NULL;
  STATUS status = OK;
  BOOL lit = FALSE;
  
  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  
  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north_link = atol(toks);
      toks = strtok(NULL, "|");
      east_link = atol(toks);
      toks = strtok(NULL, "|");
      south_link = atol(toks);
      toks = strtok(NULL, "|");
      west_link = atol(toks);
      toks = strtok(NULL, "|");
      up_link = atol(toks);
      toks = strtok(NULL, "|");
      down_link = atol(toks);
      toks = strtok(NULL, "|");
	  strcpy(description, toks);
	  toks = strtok(NULL, "|");
	  strcpy(description2, toks);
	  toks = strtok(NULL, "|");
      lit = atol(toks);
   
   
      space = space_create(id);
      if (space != NULL) {
    	space_set_name(space, name);
	    space_set_north_link(space, north_link);
	    space_set_east_link(space, east_link);
	    space_set_south_link(space, south_link);
	    space_set_west_link(space, west_link);
	    space_set_up_link(space, up_link);
	    space_set_down_link(space, down_link);
        space_set_description(space,description);
        space_set_description2(space,description2);
        space_set_is_lit(space, lit);
	    game_add_space(game, space);
      }
    }
  }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}

STATUS game_reader_load_object(Game* game, char* filename) {
    
    FILE* file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char description[WORD_SIZE] = "";
    char description2[WORD_SIZE] = "";
    char* toks = NULL;
    Id id = NO_ID, space = NO_ID, opens = NO_ID;
    Object* object = NULL;
    STATUS status = OK;
    BOOL movable =FALSE, moved = FALSE, visible = FALSE, enciende = FALSE, encendido = FALSE;
    
    
    if (!filename) {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL) { 
        return ERROR;
    }


    while (fgets(line, WORD_SIZE, file)) {
        if (strncmp("#o:", line, 3) == 0) {
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            space = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(description, toks);
            toks = strtok(NULL, "|");
            strcpy(description2, toks);
            toks = strtok(NULL, "|");
            opens = atol(toks);
            toks = strtok(NULL, "|");
            movable = atol(toks);
            toks = strtok(NULL, "|");
            moved = atol(toks);
            toks = strtok(NULL, "|");
            visible = atol(toks);
            toks = strtok(NULL, "|");
            enciende = atol(toks);
            toks = strtok(NULL, "|");
            encendido = atol(toks);
            
#ifdef DEBUG
            printf("Leido: %ld|%s|\n", id, name);
#endif
            	object = object_create(id);
             if (object != NULL) {
                object_set_name(object, name);
                 object_set_description(object,description);
                 object_set_description2(object,description2);
                 object_set_opens(object,opens);
                 object_set_movable(object,movable);
                 object_set_moved(object,moved);
                 object_set_hidden(object,visible);
                 object_set_lights(object,enciende);
                 object_set_lit(object,encendido);
                space_add_object(game_get_space(game,game_get_space_id_at(game,space)), id);
                game_add_object(game, object);
            }
        }
    }

    if (ferror(file)) {
        status = ERROR;
    }

    fclose(file);

    return status;
}

STATUS game_reader_load_links(Game *game, char* filename){
    FILE* file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char* toks = NULL;
    Id id = NO_ID, id1=NO_ID, id2=NO_ID;
    Link* link = NULL;
    STATUS status = OK;
    int i;
    BOOL state;
    
    if (!filename) {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL) { 
        return ERROR;
    }
    
     for(i=0;fgets(line, WORD_SIZE, file);i++) {
        if (strncmp("#l:", line, 3) == 0) {
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            id1 = atol(toks);
            toks = strtok(NULL, "|");
            id2 = atol(toks);
            toks = strtok(NULL, "|");
            state = atoi(toks);

            	link = link_create(id);
            	
             if (link != NULL) {
                link_set_name(link, name);
                link_set_id1(link, id1);
                link_set_id2(link, id2);
                link_set_state(link, state);
                game_add_link(game, link);
                /*if(link_get_id1(link)!=NO_ID){
                    if(id>24){
                        space_set_east_link(game_get_space(game, link_get_id1(link)), link_get_id2(link));
                        space_set_west_link(game_get_space(game, link_get_id2(link)), link_get_id1(link));
                    }else{
                        space_set_north_link(game_get_space(game, link_get_id2(link)), link_get_id1(link));
                    }
                }
                if(link_get_id2(link)!=NO_ID){
                    space_set_south_link(game_get_space(game, id), link_get_id2(link));
                }
                */
            }
        }
    }
return status;
}



