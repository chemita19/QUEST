/* Archivo : game.c
 Fecha: 20/02/2017
 Autor: Jose Maria Castro
 Descripción: Implementacion de las funciones de game.c que se encargan del juego.
 Se incluyen las librerias stdio.h, stdlib.h, string.h game.h y game_reader.h.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/game.h"
#include "../include/game_management.h"

#define N_CALLBACK 18
#define N_CALLBACK_ID 2
#define MAX_LINKS 100

/**
   Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game* game);



struct _Game{
  Player *player; /**!< Puntero a jugador*/
  Object *object[MAX_OBJECTS + 1]; /**!< Puntero a objetos*/
  Space *spaces[MAX_SPACES + 1]; /**!< Puntero a espacios*/
  T_Command last_cmd; /**!< Comandos*/
  Die *die;/**!< Puntero a dado*/
  Link *links[MAX_LINKS+1];/**!<Puntero a Links*/
  char last_description[1000];/**!<Descripción*/
  STATUS command_info;/*!<Estado del comando*/
};
/**
   List of callbacks for each command in the game 
*/
void game_callback_unknown(Game* game);
void game_callback_quit(Game* game);
void game_callback_next(Game* game);
void game_callback_back(Game* game);
void game_callback_ROLL(Game* game);
void game_callback_take(Game* game);
void game_callback_take_id(Game* game, Id id);
void game_callback_drop(Game* game);
void game_callback_drop_id(Game* game, Id id);
void game_callback_left(Game* game);
void game_callback_right(Game* game);
void game_callback_inspect(Game* game);
void game_callback_go(Game* game);
void game_callback_up(Game* game);
void game_callback_down(Game* game);
void game_callback_turnon(Game* game);
void game_callback_turnoff(Game* game);
void game_callback_open(Game* game);

static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_quit,
  game_callback_next,
  game_callback_back,
  game_callback_take,
  game_callback_drop,
  game_callback_ROLL,
  game_callback_left,
  game_callback_right,
  game_callback_inspect,
  game_callback_go,
  game_callback_up,
  game_callback_down,
  game_callback_turnon,
  game_callback_turnoff,
  game_callback_open,
};

/**
   Private functions
*/

STATUS game_load_spaces(Game* game, char* filename);
STATUS game_add_space(Game* game, Space* space);
Id     game_get_space_id_at(Game* game, int position);
STATUS game_set_player_location(Game* game, Id id);
STATUS game_set_object_location(Game* game, Id space, Id object);

/**
   Game interface implementation
 */

Game* game_create() {
  int i;
  Game* game = NULL;
  
  game = (Game*)malloc(sizeof(Game));
  
  if(!game){
  return NULL;
  }
  
  for (i = 0; i < MAX_SPACES; i++){
    game->spaces[i] = NULL;
  }
  for (i = 0; i < MAX_OBJECTS; i++){
    game->object[i] = NULL;
  }
  for (i = 0; i < MAX_LINKS; i++){
    game->links[i] = NULL;
  }
  
  game->player = NULL;
  game->die = NULL;
  game->last_cmd = NO_CMD;
  game->last_description[0]='\0';
  game->command_info = OK;
  
  return game;
}

Game* game_create_from_file(char* spaces_dat, char* objects_dat, char* links_dat){
  
  Game *game = NULL;
  int i;

  game = game_create();
  if(!game){
    return NULL;
  }
    
  if (game_reader_load_spaces(game, spaces_dat) == ERROR){
    return NULL;
  }
  if (game_reader_load_object(game, objects_dat) == ERROR){
    return NULL;
  }
  if (game_reader_load_links(game, links_dat) == ERROR){
    return NULL;
  }
  if (game->links[0] == NULL){
    return NULL;
  }
  
  game->player = player_create(1);
  if(!game->player){
    return NULL;
  }
  game_set_player_location(game, game_get_space_id_at(game, 0));
  for(i=0; game -> object[i] != NULL; i++){
    game_set_object_location(game, game_get_space_id_at(game, 0), object_get_id(game-> object[i]));
  }
  
  game->die= die_create(1);
  if(!game->die){
    return NULL;
  }
  
  return game;
}

STATUS game_destroy(Game* game) {
    int i = 0;

    for (i = 0; i < MAX_SPACES && (game->spaces[i] != NULL); i++) {
      space_destroy(game->spaces[i]);
    }
     
     i = 0;
     
     for (i = 0; i < MAX_OBJECTS && (game->object[i] != NULL); i++) {
      object_destroy(game->object[i]);
    }
    
    player_destroy(game->player);
    
    i=0;
    
    for (i = 0; i < MAX_LINKS && (game->links[i] != NULL); i++) {
      link_destroy(game->links[i]);
    }
    
    die_destroy(game->die);
        
    return OK;
}

STATUS game_add_space(Game* game, Space* space) {
    int i = 0;

    if (space == NULL) {
        return ERROR;
    }

    while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
        i++;
    }

    if (i >= MAX_SPACES) {
        return ERROR;
    }

    game->spaces[i] = space;

    return OK;
}

Id game_get_space_id_at(Game* game, int position) {

    if (position < 0 || position >= MAX_SPACES) {
        return NO_ID;
    }

    return space_get_id(game->spaces[position]);
}

Space* game_get_space(Game* game, Id id){
    int i = 0;

    if (id == NO_ID) {
      return NULL;
    }
    
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      if (id == space_get_id(game->spaces[i])){
      	return game->spaces[i];
      }
    }
    
    return NULL;
}

Die* game_get_die(Game* game){
    
  return game->die;
}

char* game_get_last_description(Game* game){
  if(!game){
    return NULL;
  }
  
  return game->last_description;
}

STATUS game_set_command_info(Game* game, STATUS info){
  if(!game){
    return ERROR;
  }
  
  game->command_info = info;
  
  return OK;
}

STATUS game_get_command_info(Game* game){
  if(!game){
    return ERROR;
  }
  
  return game->command_info;
}

STATUS game_set_player_location(Game* game, Id id) {
    
    if (id == NO_ID) {
        return ERROR;
    }

     if(player_set_location(game->player, id) == ERROR){
        return ERROR;
     }
    return OK;

}

STATUS game_set_object_location(Game* game, Id space, Id object) {
     
    if (space == NO_ID || object == NO_ID) {
        return ERROR;
    }
  
    space_add_object(game_get_space(game, space), object_get_id(game_get_object(game, object)));
    
    return OK;
}

Id game_get_player_location(Game* game) {
    return player_get_location(game->player);
}

Id game_get_object_location(Game* game) {
   int i = 0;

   for (i=0;(i<MAX_SPACES) && game->spaces[i] != NULL;i++){
        if (space_get_objects(game->spaces[i]) == NULL){
            return game_get_space_id_at(game, i);
        }
   }
   return NO_ID;
}

Object* game_get_object(Game* game, Id id) { 
    int i;
    if (id == NO_ID || !game) {
        return NULL;
    }

    for (i = 0; i < MAX_SPACES && game->object[i] != NULL; i++) {
        
        if (id == object_get_id(game->object[i])) {
             
            return game->object[i];
        }
    }

    return NULL;
}

Player* game_get_player(Game* game){
    
    if (!game){
        
        return NULL;
    }
    
    return game->player;
}

Link* game_get_link_from_name(Game *game, char* name){
  
  int i = 0;
  
  if(!game || !name){
    return NULL;
  }
  
  for(i=0; i < MAX_LINKS; i++){
    if(!game->links[i]){
      return NULL;
    }
    if (strcmp(name, link_get_name(game->links[i])) == 0){
      return game->links[i];
    }
  }
  
  return NULL;
}

Object* game_get_object_from_name(Game *game, char* name){
  
  int i = 0;
  
  if(!game || !name){
    return NULL;
  }
  
  for(i=0; i < MAX_OBJECTS; i++){
    if(!game->object[i]){
      return NULL;
    }
    if (strcmp(name, object_get_name(game->object[i])) == 0){
      return game->object[i];
    }
  }
  
  return NULL;
}

STATUS game_update(Game* game, T_Command cmd) {
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game);
  return OK;
}

T_Command game_get_last_command(Game* game){
  return game->last_cmd;
}

void game_print_data(Game* game) {
  int i = 0;
  
  printf("\n\n-------------\n\n");
  
  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }
  
  printf("=> Object location: %d\n", (int) game_get_object_location(game));    
  printf("=> Player location: %d\n", (int) game_get_player_location(game));
  printf("prompt:> ");
}

BOOL game_is_over(Game* game) {
 if(!game){
   return FALSE;
 }
 
 if(game_get_player_location(game) == 13 && inventory_find_object(player_get_inventory(game->player), 19) == TRUE){
   return TRUE;
 }
 
  return FALSE;
}

/**
   Callbacks implementation for each action 
*/

void game_callback_unknown(Game* game) {
}

void game_callback_quit(Game* game) {
}

void game_callback_next(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  
  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    game_set_command_info(game,ERROR);
    return;
  }
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      if(link_get_state(game_get_link(game, space_get_south_link(game->spaces[i]))) == TRUE){
         current_id = link_get_id2(game_get_link(game, space_get_south_link(game->spaces[i])));
          if (current_id != NO_ID ) {
	      game_set_player_location(game, current_id);
	      if(space_get_is_lit(game->spaces[current_id-1]) == TRUE){
	        strcpy(game->last_description,space_get_description(game->spaces[current_id-1]));
	      }
	     else{
	      strcpy(game->last_description,"El espacio está apagado");
	     } 
      }
      return;
      }
      else{
        strcpy(game->last_description,"Por aqui no puedes pasar");
        game_set_command_info(game,ERROR);
      }
    }
  }
}

void game_callback_go(Game* game){
  
  char input[20]= "";
  fscanf(stdin,"%s",input);
  
  if (!strcmp(input, "s") || !strcmp(input, "south")){
			game_callback_next(game);
			}
	else if (!strcmp(input, "n") || !strcmp(input, "north")){
			game_callback_back(game);
			}
	else if (!strcmp(input, "e") || !strcmp(input, "east")){
			game_callback_right(game);
			}
	else if (!strcmp(input, "w") || !strcmp(input, "west")){
			game_callback_left(game);
			}
	else if (!strcmp(input, "u") || !strcmp(input, "up")){
			game_callback_up(game);
			}
	else if (!strcmp(input, "d") || !strcmp(input, "down")){
			game_callback_down(game);
			}
	game_set_command_info(game,OK);	
	return;
}

void game_callback_take(Game* game) {
  
  char input[100]= "";
  int i = 0;
  Id object_id;
  Id space_id;
  char name[100] = "";
  
  space_id = game_get_player_location(game);
  fscanf(stdin,"%s",input);
  
  for(i = 0; i < MAX_OBJECTS && game->object[i] != NULL; i++){
    object_id = object_get_id(game->object[i]);
    strcpy(name,object_get_name(game->object[i]));
 
    if(!strcmp(input, name)){
      if(space_find_objects(game->spaces[space_id], object_id) == TRUE){
        if(object_get_movable(game->object[i])==TRUE){
          player_take_object(game->player, object_id);
          space_del_object(game->spaces[space_id],object_id);
       }
       else{
         strcpy(game->last_description, "No puedes coger este objeto");
         game_set_command_info(game,ERROR);
         return;
       }
      }
    }
  }
  
  game_set_command_info(game,OK);
	return;
  
}


void game_callback_drop(Game* game){ 
  
  char input[20]= "";
  int i = 0;
  Id object_id;
  Id space_id;
  char name[20] = "";
  
  space_id = game_get_player_location(game);
  fscanf(stdin,"%s",input);
  
  for(i = 0; i < MAX_OBJECTS && game->object[i] != NULL; i++){
    object_id = object_get_id(game->object[i]);
    strcpy(name,object_get_name(game->object[i]));
 
    if(!strcmp(input, name)){
      if(inventory_find_object(player_get_inventory(game->player), object_id) == TRUE){
        player_drop_object(game->player, object_id);
        space_add_object(game->spaces[space_id],object_id);
        object_set_moved((game_get_object(game,object_id)),TRUE);
      }
    }
  }
  game_set_command_info(game,OK);
	return;
}


void game_callback_ROLL(Game* game){
    int i;
    int value = 0;
    
    die_roll(game->die);
    value = die_get_num(game->die);
    
    for(i=0 ; i<value; i++){
      game_callback_next(game);
    }
    game_set_command_info(game,OK);
 return;
}

void game_callback_back(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  
  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    game_set_command_info(game,ERROR);
    return;
  }
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      if(link_get_state(game_get_link(game, space_get_north_link(game->spaces[i]))) == TRUE){
         current_id = link_get_id1(game_get_link(game, space_get_north_link(game->spaces[i])));
          if (current_id != NO_ID ) {
	      game_set_player_location(game, current_id);
	       if(space_get_is_lit(game->spaces[current_id-1]) == TRUE){
	        strcpy(game->last_description,space_get_description(game->spaces[current_id-1]));
	      }
	     else{
	       strcpy(game->last_description,"El espacio está apagado");
	     }
      }
      return;
      }
      else{
        strcpy(game->last_description, "No puedes pasar por aquí");
         game_set_command_info(game,ERROR);
         return;
      }
    }
  }
}

void game_callback_left(Game* game){
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  
  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    game_set_command_info(game,ERROR);
    return;
  }
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      if(link_get_state(game_get_link(game, space_get_west_link(game->spaces[i]))) == TRUE){
         current_id = link_get_id1(game_get_link(game, space_get_west_link(game->spaces[i])));
          if (current_id != NO_ID ) {
	      game_set_player_location(game, current_id);
	       if(space_get_is_lit(game->spaces[current_id-1]) == TRUE){
	        strcpy(game->last_description,space_get_description(game->spaces[current_id-1]));
	      }
	     else{
	       strcpy(game->last_description,"El espacio está apagado");
	     }
      }
      return;
      }
       else{
        strcpy(game->last_description, "No puedes pasar por aquí");
         game_set_command_info(game,ERROR);
         return;
      }
    }
  }
}

void game_callback_right(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  
  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    game_set_command_info(game,ERROR);
    return;
  }
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      if(link_get_state(game_get_link(game, space_get_east_link(game->spaces[i]))) == TRUE){
         current_id = link_get_id2(game_get_link(game, space_get_east_link(game->spaces[i])));
          if (current_id != NO_ID ) {
	      game_set_player_location(game, current_id);
	       if(space_get_is_lit(game->spaces[current_id-1]) == TRUE){
	        strcpy(game->last_description,space_get_description(game->spaces[current_id-1]));
	      }
	     else{
	       strcpy(game->last_description,"El espacio está apagado");
	     }
      }
      return;
      }
       else{
        strcpy(game->last_description, "No puedes pasar por aquí");
         game_set_command_info(game,ERROR);
         return;
      }
    }
  }
}

void game_callback_inspect(Game* game){
	
	char input[100] ="";
	char name[100] ="";
	Id object_id = NO_ID;
	Id current_id = NO_ID;
	int i=0;
	
	fscanf(stdin,"%s",input);
	
	current_id = game_get_player_location(game);
	if(current_id == NO_ID){
	  game_set_command_info(game,ERROR);
		return;
	}
	
	if (!strcmp(input, "s") || !strcmp(input, "space")){
			strcpy(game->last_description,space_get_description2(game->spaces[current_id-1]));
			return;
			}
	else{
	  for(i = 0; i < MAX_OBJECTS && game->object[i] != NULL; i++){
      object_id = object_get_id(game->object[i]);
      strcpy(name,object_get_name(game->object[i]));
 
      if(!strcmp(input, name)){
        if(space_find_objects(game->spaces[current_id], object_id) == TRUE){
          if(object_get_moved(game_get_object(game,object_id)) == TRUE){
            strcpy(game->last_description,object_get_description2(game->object[i]));
            return;
          }
          else{
            strcpy(game->last_description,object_get_description(game->object[i]));
            return;
          }
        }
        else if(inventory_find_object(player_get_inventory(game->player),object_get_id(game->object[i]))){
          strcpy(game->last_description,object_get_description(game->object[i]));
          game_set_command_info(game,OK);
          return;
        }
      }
    }
  }
}

void game_callback_up(Game* game){
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  
  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    game_set_command_info(game,ERROR);
    return;
  }
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      if(link_get_state(game_get_link(game, space_get_up_link(game->spaces[i]))) == TRUE){
         current_id = link_get_id1(game_get_link(game, space_get_up_link(game->spaces[i])));
          if (current_id != NO_ID ) {
	      game_set_player_location(game, current_id);
	       if(space_get_is_lit(game->spaces[current_id-1]) == TRUE){
	        strcpy(game->last_description,space_get_description(game->spaces[current_id-1]));
	      }
	     else{
	       strcpy(game->last_description,"El espacio está apagado");
	     }
      }
      return;
      }
       else{
        strcpy(game->last_description, "No puedes pasar por aquí");
         game_set_command_info(game,ERROR);
         return;
      }
    }
  }
}

void game_callback_down(Game* game){
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  
  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    game_set_command_info(game,ERROR);
    return;
  }
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      if(link_get_state(game_get_link(game, space_get_down_link(game->spaces[i]))) == TRUE){
         current_id = link_get_id2(game_get_link(game, space_get_down_link(game->spaces[i])));
          if (current_id != NO_ID ) {
	      game_set_player_location(game, current_id);
	       if(space_get_is_lit(game->spaces[current_id-1]) == TRUE){
	        strcpy(game->last_description,space_get_description(game->spaces[current_id-1]));
	      }
	     else{
	       strcpy(game->last_description,"El espacio está apagado");
	     }
      }
      return;
      }
       else{
        strcpy(game->last_description, "No puedes pasar por aquí");
         game_set_command_info(game,ERROR);
         return;
      }
    }
  }
}

void game_callback_turnon(Game* game){
  char input[100] ="";
	char name[100] ="";
	Id current_id = NO_ID;
	int i=0;
	int id = 2;
	
	current_id = game_get_player_location(game);
	  if(current_id== NO_ID){
	    game_set_command_info(game,ERROR);
	    return;
	  }
	
	
	fscanf(stdin,"%s", input);
	if(inventory_find_object(player_get_inventory(game->player),id) == TRUE){
	if (!strcmp(input, "s") || !strcmp(input, "space")){
			if(space_get_is_lit(game->spaces[current_id-1]) == TRUE){
			  strcpy(game->last_description, "El espacio ya esta ilumnado");
			  return;
			}
			else{
			  space_set_is_lit(game->spaces[current_id-1],TRUE);
			  strcpy(game->last_description,space_get_description(game->spaces[current_id-1]));
			}
	}
	else{
	  for(i = 0; i < MAX_OBJECTS && game->object[i] != NULL; i++){
      strcpy(name,object_get_name(game->object[i]));
      if(!strcmp(input, name)){
        if(object_get_hidden(game->object[i]) == TRUE){
          game_set_command_info(game,ERROR);
          return;
        }
        else{
          object_set_hidden(game->object[i], TRUE);
          game_set_command_info(game,OK);
          return;
        }
      }
    }
  }
	}
}

void game_callback_turnoff(Game* game){
  char input[100] ="";
	char name[100] ="";
	Id current_id = NO_ID;
	int i=0;
	
	
	current_id = game_get_player_location(game);
	  if(current_id== NO_ID){
	    game_set_command_info(game,ERROR);
	    return;
	  }
	
	fscanf(stdin,"%s", input);
	
	if (!strcmp(input, "s") || !strcmp(input, "space")){
			if(space_get_is_lit(game->spaces[current_id-1]) == FALSE){
			  strcpy(game->last_description,"El espacio ya esta apagado");
			  game_set_command_info(game,ERROR);
			  return;
			}
			else
			  space_set_is_lit(game->spaces[current_id-1],FALSE);
			  strcpy(game->last_description,"El espacio está apagado");
	}
	else{
	  for(i = 0; i < MAX_OBJECTS && game->object[i] != NULL; i++){
      strcpy(name,object_get_name(game->object[i]));
      if(!strcmp(input, name)){
        if(object_get_hidden(game->object[i]) == FALSE){
          game_set_command_info(game,ERROR);
          return;
        }
        else{
          object_set_hidden(game->object[i], FALSE);
          game_set_command_info(game,OK);
          return;
        }
      }
    }
  }
}

void game_callback_open(Game* game){
  Link *link = NULL;
	Object *object= NULL;
	char name[100] = "";
	char name2[100] = "";
	
	fscanf(stdin,"%s", name);
	fprintf(stdout,"with\n");
	fscanf(stdin,"%s", name2);
	
	link = game_get_link_from_name(game,name);
	
	object = game_get_object_from_name(game,name2);
	
	if(object_get_opens(object) == link_get_id(link)){
	  link_set_state(link, TRUE);
	}
	else{
	  game_set_command_info(game,ERROR);
	  return;
	}
	
	game_set_command_info(game,OK);
	return;
}

STATUS game_add_object(Game* game, Object* object){
	int i = 0;

    if (object == NULL || game == NULL) {
        return ERROR;
    }

    while ((i < MAX_OBJECTS) && (game->object[i] != NULL)) {
        i++;
    }

    if (i >= MAX_OBJECTS) {
        return ERROR;
    }

    game->object[i] = object; 

    return OK;
}

STATUS game_add_link(Game *g, Link *l){
int i = 0;

    if (l == NULL) {
        return ERROR;
    }

    while ( (i < MAX_LINKS) && (g->links[i] != NULL)){
        i++;
    }

    if (i >= MAX_LINKS) {
        return ERROR;
    }

    g->links[i] = l;
    
    return OK;
    
    
}

Link* game_get_link(Game *g, Id id){
    int i;
    if(!g || id==NO_ID){
        return NULL;
    }
    for(i=0;g->links[i]!=NULL;i++){
        if(link_get_id(g->links[i])==id){
            return g->links[i];
        }
    }
    
    return NULL;
}

