#include<bits/stdc++.h>
#include "Ladder.h"
#include "Snake.h"
#include "Player.h"
#include "DiceService.h"
using namespace std;

class SnakeAndLadderBoard{

	public:
		int size;
		vector<Snake> snakes;
		vector<Ladder> ladders;
		unordered_map<int,int> playerPieces;

		SnakeAndLadderBoard(int size){
			this->size=size;
		}

		int getSize(){
			return this->size;
		}

		vector<Snake> getSnakes(){
			return snakes;
		}

		vector<Ladder> getLadders(){
			return ladders;
		}

		unordered_map<int,int> getPlayerPieces(){
			return playerPieces;
		}

		void setSnakes(vector<Snake>snakes){
			this->snakes=snakes;
		}

		void setLadders(vector<Ladder>ladders){
			this->ladders=ladders;
		}

		void setPlayerPieces(unordered_map<int,int>playerPieces){
			this->playerPieces=playerPieces;
		}


};
