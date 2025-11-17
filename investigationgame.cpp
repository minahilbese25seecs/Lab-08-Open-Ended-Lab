#include<iostream>              // arrays passing in functions 
using namespace std;
int day=1;
int clues;
char choice;
int energy=100;
int progress=0;
bool backdoor=true;
int Day(int);
int checkEnergy(int);
int progression(int);
void layout();
int main(){
	layout();
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
	cout<<"Where do you wanna search?... "<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"|	1. Towel stand                    |"<<endl;
	cout<<"|	2. Toilet                         |"<<endl;
	cout<<"|	3. Bathtub                        |"<<endl;
	cout<<"|	4. Bathroom shelf                |"<<endl;
	cout<<"|	5. Door                           |"<<endl;
	cout<<"|	6. Exit                           |"<<endl;
	cout<<"----------------------------------------"<<endl;
	cin>>place;
	switch(place){
		case 1:{
			cout<<"You are seeing the towel stand. "<<endl;
			energy-=5;
			cout<<"Look behind? (Yes/No)"<<endl;
			cin>>action;
			if (action=="Yes"){
				energy-=5;
				cout<<"You see a red stain on the mirror."<<endl;
				progress++;
				clues++;
				cout<<"Clues found: "<<progress<<"/9"<<endl;
				cout<<"Good job!"<<endl;
			}
			break;
		}
		case 2:{
			cout<<"You are seeing the toilet"<<endl;
			cout<<"Bend down? (Yes/No)"<<endl;
			cin>>action;
			if (action=="Yes"){
				energy-=5;
				cout<<"You see dried liquid and a hair"<<endl;
				progress++;
				clues++;
				cout<<"Clues found: "<<progress<<"/9"<<endl;
				cout<<"Good job!"<<endl;
			}
			break;
		}
		case 3:{
			cout<<" You are seeing the Bathtub"<<endl;
			cout<<"Look inside? (Yes/No)"<<endl;
			cin>>action;
			if (action=="Yes"){
				energy-=5;
				cout<<"You see water inside, but there's a necklace in it. "<<endl;
				progress++;
				clues++;
				cout<<"Clues found: "<<progress<<"/9"<<endl;
				cout<<"Good job!"<<endl;
			}
			break;
		}
		case 4:
		cout<<"You move towards the bathroom shelf."<<endl;
		cout<<"Something alarms you. Want to check? (Yes/No)"<<endl;
		cin>>action;
		if (action=="Yes") {
			energy-=5;
			cout<<"There's a bloody razor and lots of tissue.."<<endl;
			clues++;
			progress++;
			cout<<"Clues found: "<<progress<<"/9"<<endl;
			cout<<"Good job!"<<endl;
		}
			break;
		case 5:
		cout<<"You head towards the bathroom door."<<endl;
		cout<<"Check for any damage? (Yes/No)"<<endl;
		cin>>action;
		if (action=="Yes") {
			energy-=5;
			cout<<"The door doesn't have any marks or damage.."<<endl;
		}
			break;
	}
	cout<<"You are leaving the washroom"<<endl;
	if (backdoor==true) {
		cout<<"On the way out, you see the backdoor to the garage."<<endl;
		cout<<"Check backdoor? (Yes/No)"<<endl;
		cin>>action;
		if (action=="Yes") {
			energy-=10;
			cout<<"The backdoor is opened!"<<endl;
			cout<<"The culprit seems to have escaped from here.."<<endl;
			progress++;
			clues++;
			cout<<"Clues found: "<<progress<<"/9"<<endl;
			cout<<"Good job!"<<endl;
		}
		backdoor=false;
	}
}

void bedroom (){
	int place;
	cout<<"What grabs your attention here? "<<endl<<endl;
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
			cout<<"You check the bed.."<<endl;
			energy-=5;
			cout<<"The bedsheet is dragged off the bed."<<endl;
            progress++;
			clues++;
            cout<<"Clues found: "<<progress<<"/9"<<endl;
			cout<<"Good job."<<endl;
			break;
		case 2:
			cout<<"You go to check the door."<<endl;
			energy-=5;
			cout<<"You discover that the door lock was broken from the outside.."<<endl;
			cout<<"You start to understand what happened.."<<endl;
			progress++;
			clues++;
			cout<<"Clues found: "<<progress<<"/9"<<endl;
			cout<<"Good job!"<<endl;
			break;
		case 3:
			cout<<"You go to check the closet."<<endl;
			energy-=5;
			cout<<"You open the closet, and something falls on you!"<<endl;
			cout<<"'Oh, just some clothes..'"<<endl;
			break;
		case 4:
			cout<<"You go to check the window."<<endl;
			energy-=5;
			cout<<"But it's locked from the inside."<<endl;
			cout<<"'Okay, no one came from here.', you think to yourself."<<endl;
			break;
		case 5:
			cout<<"You leave the bedroom."<<endl;
			energy-=5;
			break;
		}
}
void garage (){
	int place;
	cout<<"Where would you like to investigate? "<<endl<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"|	1. Garage door                    |"<<endl;
	cout<<"|	2. Car                            |"<<endl;
	cout<<"|	3. Door leading inside            |"<<endl;
	cout<<"|	4. Exit                           |"<<endl;
	cout<<"----------------------------------------"<<endl;
	cin>>place;
	cout<<endl;
	switch(place){
		case 1:{
			cout<<"You check the Garage door.."<<endl;
			energy-=5;
			cout<<"It's locked. All clear!"<<endl;
			break;
		}
		case 2:{
			cout<<"You check under the car.."<<endl;
			energy-=5;
			cout<<"You find nothing."<<endl;
			cout<<"..But you saw that the car handle is damaged!"<<endl;
			progress++;
			clues++;
			cout<<"Clues found: "<<progress<<"/9"<<endl;
			cout<<"Good job."<<endl;
			break;
		}
		case 3:{
			cout<<"You have checked door leading inside"<<endl;
			energy-=10;
			cout<<"You find it open! That explains it.."<<endl;
			progress++;
			clues++;
			cout<<"Clues found: "<<progress<<"/9"<<endl;
			cout<<"Good job!"<<endl;
			break;
		}
		case 4:{
			cout<<"You have left the garage."<<endl;
			energy-=2;
			break;
		}
	}
}

int Day(int day) {
	for (;day<=5;) {
	cout<<"Day: "<<day<<endl;
	int room;
	cout<<"Which room would you like to investigate?"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"|	1. Bathroom                       |"<<endl;
	cout<<"|	2. Garage                         |"<<endl;
	cout<<"|	3. Bedroom                        |"<<endl;
	cout<<"----------------------------------------"<<endl;
	cin>>room;
	switch (room) {
		case 1:
			cout<<"You are entering the bedroom."<<endl;
			energy-=10;
			Bathroom();
			cout<<"Today's clues: "<<clues<<endl;
			cout<<"Energy remaining: "<<energy<<endl;
			break;
		case 2:
			cout<<"You have entered The Garage"<<endl;   
			energy-=10;
			garage();
			cout<<"Energy: "<<energy<<endl;
			cout<<"Today's clues: "<<clues<<endl;
			break;
		case 3:
			cout<<"You have entered The Bedroom"<<endl;
			energy-=10;
			bedroom();
			cout<<"Energy: "<<energy<<endl;
			cout<<"Today's clues: "<<clues<<endl;
			break;
}
int end=progression(progress);
int check=checkEnergy(energy);
if (end==1) {
	cout<<"You have cracked the case!"<<endl;
    cout<<"Here's what you found.."<<endl;
    cout<<"Acoording to the clues, it was confirmed that the mysterious killer was the old woman's "<<endl;
    cout<<"grandson who entered her house by acting as an electrician. He was the same grandson "<<endl;
    cout<<"that the old woman kicked out of the house years ago. He first entered from the front "<<endl;
    cout<<"door, ran after the old woman, killed her in the bathroom using a razor and then escaped "<<endl;
    cout<<"through the garage."<<endl;
	break;
}
else if (check==-1) { //energy depleted
		cout<<"You ran out of energy. Come back tomorrow.."<<endl;
		day++; //new day, this day goes wasted
        energy=100;
		clues=0;
		cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~"<<endl;
		cout<<"The Next Day..\n";
		continue;
	}
	else if (clues==3) { //all 3 clues for the day are found
		cout<<"You've found 3 clues today, have some rest.\nCome back tomorrow!"<<endl;
		day++; //u advance to the next day, even if you have energy left
        energy=100;
		clues=0;
		cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~"<<endl;
		cout<<"The Next Day..\n";
		continue;
	}
	else { //neither have the 3 clues been found, nor has the energy been depleted 
		continue; //you go to another room on the same day
	}
}
return day;
}

int progression (int progress) {
	if (progress==9) { 
		return 1;
	}
	if (progress<9) {
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
		cout<<"Energy is low.."<<endl;
	}
	else {
		return 0;
	}
}
void layout () {
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
}

