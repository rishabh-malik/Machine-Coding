#include<bits/stdc++.h>
#include "SnakeAndLadderService.h"
using namespace std;

int main(){

	int noOfSnakes,noOfLadders,noOfPlayers;
	cin>>noOfSnakes;
	vector<Snake>snakes;

	for(int i=0;i<noOfSnakes;i++){
		int start,end;
		cin>>start>>end;
		snakes.push_back(Snake(start,end));
	}

	cin>>noOfLadders;
	vector<Ladder>ladders;

	for(int i=0;i<noOfLadders;i++){
		int start,end;
		cin>>start>>end;
		ladders.push_back(Ladder(start,end));
	}

	cin>>noOfPlayers;
	vector<Player>players;

	for(int i=0;i<noOfPlayers;i++){
		string name;
		cin>>name;
		players.push_back(Player(name));
	}

	SnakeAndLadderService snakeAndLadderService(100);
	snakeAndLadderService.setPlayers(players);
	snakeAndLadderService.setSnakes(snakes);
	snakeAndLadderService.setLadders(ladders);

	snakeAndLadderService.startGame();

	return 0;
}
