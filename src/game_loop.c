/** 
 * @brief It defines the game loop 
 * 
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "../include/graphic_engine.h"
#include "../include/game.h"
#include "../include/command.h"

void game_loop_start_menu() {
	    printf ("   *******    **     ** ********  ******** **********\n");
        printf ("  **/////**  /**    /**/**/////  **////// /////**/// \n");
        printf (" **     //** /**    /**/**      /**           /**   \n");
        printf ("/**      /** /**    /**/******* /*********    /**   \n");
        printf ("/**    **/** /**    /**/**////  ////////**    /**   \n");
        printf ("//**  // **  /**    /**/**             /**    /**   \n");
        printf (" //******* **//******* /******** ********     /**  \n");
        printf ("  /////// //  ///////  //////// ////////      //   \n");
        printf ("Bienvenido al juego QUEST, creado por Jose María Castro Palacios, nos encontramos en una versión muy simple\n ");
        printf ("con muy pocas funcionalidades por el momento, si quiere continuar pulse ''c'' o ''C''.\n ");
        printf ("                                                                           \n ");
        printf ("Pulse 'C' o 'c': ");
        
        return;
}

void game_loop_ending_menu(){



printf("\nTras tu llegada al trono, el reino de Boletaria vuelve a resplandecer y sigue creciendo con el reinado de tus hijos\n");
printf("Muchas gracias por jugar a QUEST, espero que te haya gustado\n");

printf("Pulse C o c para acabar:\n");
	return;
}

int main(int argc, char *argv[]){
	FILE *LOG = NULL;
	Game *game = NULL;
	T_Command command = NO_CMD; 
	Graphic_engine *gengine;
	char run, end;
	
	
	if (argc < 4){
		fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]); 
		return 1;
	}
	
	if ((game = game_create_from_file(argv[1], argv[2], argv[3])) == NULL){
		fprintf(stderr, "Error while initializing game.\n"); 
		return 1;
	}
	
	if ((gengine = graphic_engine_create()) == NULL){
		fprintf(stderr, "Error while initializing graphic engine.\n"); 
		game_destroy(game); 
		return 1;
	}
	while (run != 'c' && run != 'C') {
     		game_loop_start_menu();
     	    scanf ("%s", &run);
    }
    
    LOG=fopen(argv[4], "w");
    
	while ( (command != QUIT) && !game_is_over(game) ){
		graphic_engine_paint_game(gengine, game);
		command = get_user_input();
		if(game_get_command_info(game) == OK){
			fprintf(LOG,"%s : OK\n",command_to_string(command));
		}
		else{
			fprintf(LOG,"%s : ERROR\n",command_to_string(command));
		}
		game_update(game, command);
	} 
	
	
	if(game_is_over(game) == TRUE){
		while(end != 'c' && end != 'C'){
			game_loop_ending_menu();
			scanf("%s", &end);
		}
	}
	
	game_destroy(game);
	graphic_engine_destroy(gengine);
	fclose(LOG);
	return 0;
}
