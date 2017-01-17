#include <stdio.h>    
#include <stdlib.h>     
#include <time.h>
#include <iostream>
#include<string.h>
#include<string>

using namespace std;

int main() {
	int playerCards = 15, cpuCards = 15, pCard, cCard, pScore = 0, cScore = 0, stop = 0;
	string player;

	srand(time(NULL));

	cout << "Enter your name: ";
	cin >> player;

	while (stop == 0) {
		cout << "CPU - " << cpuCards << endl;
		cout << player << " - " << playerCards << endl;

		pCard = rand() % 13 + 1;
		cCard = rand() % 13 + 1;

		switch (pCard) {
		case 1:
			cout << "Player: A";
			break;
		case 11:
			cout << "Player: J";
			break;
		case 12:
			cout << "Player: Q";
			break;
		case 13:
			cout << "Player: K";
			break;
		default:
			cout << "Player: " << pCard << endl;
			break;
		}

		switch (cCard) {
		case 1:
			cout << "CPU: A";
			break;
		case 11:
			cout << "CPU: J";
			break;
		case 12:
			cout << "CPU: Q";
			break;
		case 13:
			cout << "CPU: K";
			break;
		default:
			cout << "CPU: " << cCard << endl;
			break;
		}

		if (pCard > cCard) {
			cout << "Player wins this round." << endl;
			pScore++;
		}
		else if (cCard > pCard) {
			cout << "CPU wins this round." << endl;
			cScore++;
		}
		else if (cCard == pCard) {
			pCard = rand() % 13 + 1;
			cCard = rand() % 13 + 1;

			if (pCard > cCard) {
				cout << "Player wins this round." << endl;
				pScore += 2;
			}
			else if (cCard > pCard) {
				cout << "CPU wins this round." << endl;
				cScore += 2;
			}

			playerCards -= 2;
			cpuCards -= 2;
		}

		//cout << "Player score: " << pScore << endl;
		//cout << "CPU score: " << cScore << endl;

		playerCards--;
		cpuCards--;

		if (playerCards == 0 || cpuCards == 0) {
			if (pScore > cScore) {
				cout << "Player wins the war." << endl;
			}
			else if (cScore > pScore) {
				cout << "CPU wins this war." << endl;
			}
			stop = 1;
		}

		for (int i = 0; i < 20; i++) {
			cout << "-";
		}
		cout << endl;
	}
	system("pause");
} 