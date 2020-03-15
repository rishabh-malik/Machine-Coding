#include<bits/stdc++.h>
using namespace std;
class Player{

	public:

		static int counter;

		string name;
		int uid;

        static int helper(){
            counter++;
            return counter;
        }

		Player(string name){

			this->name=name;
			this->uid=helper();

		}

		string getName(){
			return this->name;
		}

		int getId(){
			return this->uid;
		}

};

int Player::counter = 0;
