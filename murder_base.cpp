#include<iostream>              // arrays passing in functions 
using namespace std;
int day=1;
int clues;
char choice;
int energy=100;
int progress=0;
int Day(int);
int checkEnergy(int);
int progression(int);
int main(){
	cout << "--------------------------------------------------------------------------\n";
    cout << "|                             HOUSE LAYOUT                                |\n";
    cout << "--------------------------------------------------------------------------\n";
    cout << "|  ENTRANCE |                  LIVING ROOM                  |   WINDOW    |\n";
    cout << "|-----------|-----------------------------------------------|-------------|\n";
    cout << "|           |                                               |             |\n";
    cout << "|           |                                               |             |\n";
    cout << "|  DOOR ->  |                 [ SOFA ]                      |             |\n";
    cout << "|           |                 [ TABLE ]                     |             |\n";
    cout << "|           |                                               |             |\n";
    cout << "|-----------|-----------------------------------------------|-------------|\n";
    cout << "|  BEDROOM 1               |  HALLWAY  |              BEDROOM 2           |\n";
    cout << "|--------------------------|           |----------------------------------|\n";
    cout << "|                        __|           |__                                |\n";
    cout << "|     [ BED ]                                       [ BED ]               |\n";
    cout << "|    [ CLOSET ]          __             __          [ DESK ]              |\n";
    cout << "|                          |           |                                  |\n";
    cout << "|--------------------------|           |----------------------------------|\n";
    cout << "|        (BATHROOM)        |           |             (KITCHEN)            |\n";
    cout << "|--------------------------|           |     [ FRIDGE ]  [ STOVE ]        |\n";
    cout << "|  [ SINK ]  [ TOILET ]    |           |                                  |\n";
    cout << "|   [ BATHTUB ]            |           |     [ TABLE ]   [ WINDOW ]       |\n";
    cout << "|--------------------------------------|----------------------------------|\n";
    cout << "|                        BACK DOOR -->                                    |\n";
    cout << "--------------------------------------------------------------------------\n";
    cout << "|                             O <-- This is you                           |\n";
    cout << "--------------------------------------------------------------------------\n";
    cout << "--------------------------------------------------------------------------\n";
	cout<<"Energy: "<<energy<<endl;
	cout<<"Start? (Y/N)\n";
	cin>>choice;
	if (choice=='Y') 
	Day(day);
	return 0;
}

void Bathroom (){
	int place;
	string action;
	cout<<"You have entered the Bathroom."<<endl;
	cout<<"Where do you wanna search?... "<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"|	1. Towel stand                    |"<<endl;
	cout<<"|	2. Toilet                         |"<<endl;
	cout<<"|	3. Bathtub                        |"<<endl;
	cout<<"|	4. Bathroom window                |"<<endl;
	cout<<"|	5. Door                           |"<<endl;
	cout<<"|	5. Exit                           |"<<endl;
	cout<<"----------------------------------------"<<endl;
	cin>>place;
	switch(place){
		case 1:{
			cout<<"You are seeing the towel stand. "<<endl;
			energy-=2;
			cout<<"Look behind? (Yes/No)"<<endl;
			cin>>action;
			if (action=="Yes"){
				energy-=2;
				cout<<"You see a red stain on the mirror."<<endl;
				progress++;
				cout<<"Clues found: "<<progress<<endl;
				cout<<"Good job!"<<endl;
			}
			break;
		}
		case 2:{
			cout<<"You are seeing the toilet"<<endl;
			cout<<"Bend down?"<<endl;
			cin>>action;
			if (action=="Yes"){
				energy-=2;
				cout<<"You see dried liquid and a hair"<<endl;
				progress++;
				cout<<"Clues found: "<<progress<<endl;
				cout<<"Good job!"<<endl;
			}
			break;
		}
		case 3:{
			cout<<" You are seeing the Bathtub"<<endl;
			cout<<"Look inside? (Yes/No)"<<endl;
			cin>>action;
			if (action=="Yes"){
				energy-=2;
				cout<<"You see water inside, but there's a necklace in it. "<<endl;
				progress++;
				cout<<"Clues found: "<<progress<<endl;
				cout<<"Good job!"<<endl;
			}
			break;
		}
	}
	cout<<"You are leaving the washroom"<<endl;
	cout<<"On the way out, you see the backdoor to the garage."<<endl;
	cout<<"Check backdoor?"<<endl;
	cin>>choice;
		if (choice=='Y') {
			cout<<"The backdoor is opened!"<<endl;
			progress++;
			cout<<"Clues found: "<<progress<<endl;
			cout<<"Good job!"<<endl;
		}
}

void bedroom (){
	int place;
	cout<<"You have entered bedroom"<<endl;
	cout<<"where do you wanna search... "<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"|	1. Bed                            |"<<endl;
	cout<<"|	2. Door                           |"<<endl;
	cout<<"|	3. Closet                         |"<<endl;
	cout<<"|	4. Window                         |"<<endl;
	cout<<"|	5. Exit                           |"<<endl;
	cout<<"----------------------------------------"<<endl;
	cin>>place;
	switch(place) {
		case 1:
			cout<<"You have checked bed"<<endl;
			energy-=5;
			cout<<"You find nothing"<<endl;
			break;
		case 2:
			cout<<"You have checked Door"<<endl;
			energy-=2;
			cout<<"You find the door lock broken"<<endl;
			progress++;
			cout<<"Clues found: "<<progress<<endl;
			cout<<"Good job!"<<endl;
			break;
		case 3:
			cout<<"You have checked Closet"<<endl;
			energy-=5;
			cout<<"You find clothes"<<endl;
			break;
		case 4:
			cout<<"You have checked window"<<endl;
			energy-=2;
			cout<<"You find it locked from the inside"<<endl;
			break;
		case 5:
			cout<<"You have left bedroom"<<endl;
			energy-=2;
			break;
		}
}
void garage (){
	int place;
	cout<<"You have entered Garage"<<endl;
	cout<<"where do you wanna search... "<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"|	1. Garage door                    |"<<endl;
	cout<<"|	2. Car                            |"<<endl;
	cout<<"|	3. Door leading inside            |"<<endl;
	cout<<"|	4. Exit                           |"<<endl;
	cout<<"----------------------------------------"<<endl;
	cin>>place;
	switch(place){
		case 1:{
			cout<<"You have checked Garage door"<<endl;
			energy-=5;
			cout<<"You find it locked"<<endl;
			break;
		}
		case 2:{
			cout<<"You have checked under the car"<<endl;
			energy-=5;
			cout<<"You find nothing"<<endl;
			cout<<"But you saw that the car handle is damaged!"<<endl;
			progress++;
			cout<<"Clues found: "<<progress<<endl;
			cout<<"Good job!"<<endl;
			break;
		}
		case 3:{
			cout<<"You have checked door leading inside"<<endl;
			energy-=10;
			cout<<"You find it open"<<endl;
			progress++;
			cout<<"Clues found: "<<progress<<endl;
			cout<<"Good job!"<<endl;
			break;
		}
		case 4:{
			cout<<"You have left the garage"<<endl;
			energy-=2;
			break;
		}
	}
}

int Day(int day) {
	int energy=100;
	for (;day<=5;) {
	cout<<"Day: "<<day<<endl;
	int room;
	cout<<" Enter which room you want to enter"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"|	1. Bathroom                       |"<<endl;
	cout<<"|	2. Garage                         |"<<endl;
	cout<<"|	3. Bedroom                        |"<<endl;
	cout<<"----------------------------------------"<<endl;
	cin>>room;
	switch (room) {
		case 1:
			cout<<"You have entered Bathroom"<<endl;
			energy-=10;
			cout<<"Energy: "<<energy<<endl;
			Bathroom();
			cout<<"Energy: "<<energy<<endl;
			break;
		case 2:
			cout<<"You have entered garage"<<endl;   
			energy-=10;
			cout<<"Energy: "<<energy<<endl;
			garage();
			cout<<"Energy: "<<energy<<endl;
			break;
		case 3:
			cout<<"You have entered bedroom"<<endl;
			energy-=10;
			cout<<"Energy: "<<energy<<endl;
			bedroom();
			cout<<"Energy: "<<energy<<endl;
			break;
}
int end=progression(progress);
if (end==1) {
	cout<<"You have won!"<<endl;
	break;
}
int check=checkEnergy(energy);
	if (check==-1) { //energy depleted
		day++; //new day, this day goes wasted
		continue;
	}
	else if (clues==3) { //all 3 clues for the day are found
		day++; //u advance to the next day, even if you have energy left
		continue;
	}
	else { //neither have the 3 clues been found, nor has the energy been depleted 
		continue; //you go to another room on the same day
	}
}
return day;
}

int progression (int progress) {
	if (progress==10) { 
		return 1;
	}
	if (progress<10) {
		return -1;
	}
}
int checkEnergy(int energy) {
	if (energy<=15) {
	cout<<"Energy very low\n";
	return 0;
	}
	else if (energy==0) {
		cout<<"Energy depleted."<<endl;
		cout<<"Day failed"<<endl;
		return -1;
	}
	else if (energy<30) {
		cout<<"Energy is low..";
	}
	else {
		return 0;
	}
}

