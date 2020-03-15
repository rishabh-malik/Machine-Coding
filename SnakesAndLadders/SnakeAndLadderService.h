#include<bits/stdc++.h>
#include "SnakeAndLadderBoard.h"
using namespace std;

class SnakeAndLadderService{

	private:
		SnakeAndLadderBoard snakeAndLadderBoard;
		int initialNumberOfPlayers;
		vector<Player> players;
		bool isCompleted;
		int noOfDices;
		bool shouldGameContinueTillLastPlayer;
		bool shouldAllowMultipleDiceRollsOnSix;
		int DEFAULT_BOARD_SIZE;
		int DEFAULT_NO_OF_DICES;
		int currNoOfPlayers;

	public:
		SnakeAndLadderService(int boardSize):snakeAndLadderBoard(boardSize){
			DEFAULT_BOARD_SIZE=100;
			DEFAULT_NO_OF_DICES=1;
			this->noOfDices=this->DEFAULT_NO_OF_DICES;
		}

		void setNoOfDices(int noOfDices){
			this->noOfDices=noOfDices;
		}

		void setShouldGameContinueTillLastPlayer(bool shouldGameContinueTillLastPlayer){
			this->shouldGameContinueTillLastPlayer=shouldGameContinueTillLastPlayer;
		}

		void setShouldAllowMultipleDiceRollsOnSix(bool shouldAllowMultipleDiceRollsOnSix){
			this->shouldAllowMultipleDiceRollsOnSix=shouldAllowMultipleDiceRollsOnSix;
		}

		void setPlayers(vector<Player>players){
			this->currNoOfPlayers=players.size();
			this->initialNumberOfPlayers=players.size();
            this->players=players;
			unordered_map<int,int> playerPieces;
			for(Player player:players){
				playerPieces[player.getId()]=0;
			}

			snakeAndLadderBoard.setPlayerPieces(playerPieces);

		}

		void setSnakes(vector<Snake>snakes){
			snakeAndLadderBoard.setSnakes(snakes);
		}

		void setLadders(vector<Ladder>ladders){
			snakeAndLadderBoard.setLadders(ladders);
		}

		private:
		int getTotalValueAfterDiceRoll(){
		    DiceService d;
			return d.roll();
		}

		bool isGameCompleted(){
			return currNoOfPlayers<initialNumberOfPlayers;
		}

		int getNewPositionAfterGoingThroughSnakesAndLadders(int newPos){

			int prevPos;
			do{

				prevPos=newPos;
				for(Snake snake:snakeAndLadderBoard.getSnakes()){
					if(snake.getStart()==newPos){
						newPos=snake.getEnd();
					}
				}

				for(Ladder ladder:snakeAndLadderBoard.getLadders()){
					if(ladder.getStart()==newPos){
						newPos=ladder.getEnd();
					}
				}

			}while(newPos!=prevPos);
			return newPos;

		}

		void movePlayer(Player player,int positions){

			unordered_map<int,int>config=snakeAndLadderBoard.getPlayerPieces();
			int oldPos=config[player.getId()];
			int newPos=oldPos+positions;

			int boardSize=snakeAndLadderBoard.getSize();

			if(newPos>boardSize){
				newPos=oldPos;
			}else{

				newPos=getNewPositionAfterGoingThroughSnakesAndLadders(newPos);

			}

			config[player.getId()]=newPos;
			snakeAndLadderBoard.setPlayerPieces(config);
			cout<<player.getName()<<" rolled a "<<positions<<" and moved from "<<oldPos<<" to "<<newPos<<"\n";

		}

		bool hasPlayerWon(Player player){

			unordered_map<int,int>config=snakeAndLadderBoard.getPlayerPieces();
			int pos=config[player.getId()];
			int winningPos=snakeAndLadderBoard.getSize();
			return pos==winningPos;

		}

		public:
		void startGame(){
			int curr=0;

			while(!isGameCompleted()){

				int totalDiceValue=getTotalValueAfterDiceRoll();
				Player currPlayer=players[curr%initialNumberOfPlayers];
				curr++;
				movePlayer(currPlayer,totalDiceValue);
				if(hasPlayerWon(currPlayer)){

					cout<<currPlayer.getName()<<" wins the game ";
					currNoOfPlayers--;

				}

			}

		}

};
