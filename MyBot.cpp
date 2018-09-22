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
vector<node_id_t> starting_path = {10,16,12,22,21,20};
int start_path_idx = 0;
bool bool_starting_path = 1;

string attack_monster(node_id_t location, Game_Api * api){
	Monster m = api->get_monster(location);
	if(m._stance == "Rock") return "Paper";
	else if(m._stance == "Paper") return "Scissors";
	else  return "Rock"; //(m._stance == "Scissors")
}

string attack_player(node_id_t location, Game_Api * api){//counter opponent's last move
	Player p = api->get_opponent();
	if(p._stance == "Rock") return "Paper";
	else if(p._stance == "Paper") return "Scissors";
	else return "Rock"; //(p._stance == "Scissors")
}

void start_path_strats()

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

		//defaults
			 node_id_t destination_decision = 0;
			 string stance = "Rock";

			 if(bool_starting_path){//on starting path

			 }


								api->submit_decision(destination_decision,stance); //CHANGE THIS
             		fflush(stdout);
			free(buf);
	       }
	     }
	   }
