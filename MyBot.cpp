#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "Game_Api.h"
using json = nlohmann::json;
using Player = Game_Api::Player;
using Monster = Game_Api::Monster;
using DeathEffects = Game_Api::DeathEffects;


#define RESPONSE_SECS 1
#define RESPONSE_NSECS 0

#include <iostream>
using namespace std;
//You may add global variables and helper functions

int main() {
	Game_Api * api;
	int my_player_num = 0;
	while(1){
		char* buf = NULL;
		size_t size = 0;
		getline(&buf, &size, stdin);
		json data = json::parse(buf);
		if(data["type"] == "map"){
			my_player_num = data["player_id"];
			api = new Game_Api(my_player_num, data["map"]);
		} else {
			api->update(data["game_data"]);

			 //YOUR CODE HERE
				Player me = api->get_self();
			  Player opponent = api->get_opponent();
			  node_id_t destination_decision = me._location;
			  string stance = "Paper";

								api->submit_decision(destination_decision,stance); //CHANGE THIS
             		fflush(stdout);
			free(buf);
	       }
	     }
	   }
