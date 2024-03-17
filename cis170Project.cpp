//Luke Maxwell
//4 17 19
//CIS 170 Final Project

#include <iostream>
#include <thread> //millisecond timer
#include <fstream>
#include <string>
#include <stdio.h> //toupper
#include <cstdlib> //system is ambigious 
#include <time.h>  

using namespace std;
//void flashing(saveState saveClass, character steve);
//void menu(saveState saveClass, character steve, int secondTimeMenu);
//void type_text(const string& text, int time, bool borderBoolean, bool endline); //Ticker text
//void settings(saveState saveClass, character steve);
//void loadgame(saveState saveClass, character steve);
//void pause(bool ignore);



//OOP
//======================================================
class character {
public:
	void setHp(int health);
	void setLevel(int charLevel);
	void setSword(bool charSword);
	void setGreatsword(bool charGreatsword);
	void setPotion(int newPotion);
	void setKillcount(int newKillcount);

	int getHp();
	int getLevel();
	int getSword();
	int getPotion();
	int getKillcount();
	
	
private:
	int hp = 100;
	int level = 0;
	bool sword = true;
	bool greatsword = false;
	int potion = 0;
	int killCount = 0;
};

class saveState {
public:
	string getCode();
	void setCode(string codeSet);
	bool getBorder();
	void setBorder(bool border);
	char getColor();
	void setColor(char colorSet);
	bool getSave();
	void setSave(bool saveGame);
	char getMap(int x, int y);
	void setMap(char input, int x, int y);
	int getXlocation();
	void setXlocation(int newX);
	int getYlocation();
	void setYlocation(int newY);
	bool getWin();
	void setWin(bool winYorn);

	friend ostream& operator << (ostream&, saveState&);



private:
	string code = "aaa";
	bool borderBoolean = true;
	char color = ' ';
	bool save;
	char map[6][6] = { 'X', 'X', 'X', 'X', 'X', 'X',
						'X', 'X', 'X', 'X', 'X', 'X',
						'X', 'X', 'X', 'X', 'X', 'X',
						'X', 'X', 'X', 'X', 'X', 'X',
						'X', 'X', 'X', 'X', 'X', 'X',
						'X', 'X', 'X', 'X', 'X', 'X' };
	int xlocation;
	int ylocation;
	bool win = false;
	

};

ostream& operator << (ostream& out, saveState& saveClass) { //operator overloading

	out << endl << "Code: " <<saveClass.code << endl;
	out << "Border: " << saveClass.borderBoolean << endl;
	out << "Color: " << saveClass.color << endl;
	out << "Save: " << saveClass.save << endl;
	out << "Xlocation: " << saveClass.xlocation << endl;
	out << "Ylocation: " << saveClass.ylocation << endl;
	out << "Win? " << saveClass.win << endl;
	return out;
}

//Mutators
//====================================================
void character::setHp(int health) {
	hp = health;
}

void character::setLevel(int charLevel) {
	level = charLevel;
}

void character::setSword(bool charSword) {
	sword = charSword;
}

void character::setGreatsword(bool charGreatsword) {
	greatsword = charGreatsword;
}

void saveState::setCode(string codeSet){
	code = codeSet;
}

void saveState::setBorder(bool border) {
	borderBoolean = border;
}

void saveState::setColor(char colorSet) {
	color = colorSet;
}

void saveState::setSave(bool saveGame) {
	save = saveGame;
}

void saveState::setMap(char input, int x, int y) {
	map[x][y] = input; //character sent to array location replaces old character
}

void saveState::setXlocation(int newX) {
	xlocation = newX;
}

void saveState::setYlocation(int newY) {
	ylocation = newY;
}

void character::setPotion(int newPotion) {
	potion = newPotion;
}

void character::setKillcount(int newKillcount) {
	killCount = newKillcount;
}

void saveState::setWin(bool winYorn) {
	win = winYorn;
}



//Accessors
//====================================================

int character::getHp() {
	return hp;
}

int character::getLevel() {
	return level;
}

int character::getSword() {

	//returns 2 if greatsword, 1 if sword, 0 if none
	if (sword)
		if (greatsword)
			return 2;
		else return 1;
	else return 0;
}

string saveState::getCode() {
	return code;
}

bool saveState::getBorder() {
	return borderBoolean;
}

char saveState::getColor() {
	return color;
}

bool saveState::getSave() {
	return save;
}

char saveState::getMap(int x, int y) {
	return map[x][y];
}

int saveState::getXlocation() {
	return xlocation;
}

int saveState::getYlocation() {
	return ylocation;
}

int character::getPotion() {
	return potion;
}

int character::getKillcount() {
	return killCount;
}

bool saveState::getWin() {
	return win;
}



void flashing(saveState saveClass);
void menu(saveState saveClass, character steve, int secondTimeMenu);
void type_text(const string& text, int time, bool borderBoolean, bool endline); //Ticker text
void settings(saveState saveClass, character steve);
void loadgame(saveState saveClass, character steve);
void pause(bool ignore);
void game(saveState &saveClass, character steve);
void displayMap(saveState saveClass);
void movement(saveState &saveClass, char direction);
void encounter(saveState &saveClass, character &steve, bool &gameover);
void codeset(saveState saveClass, character &steve);
void about();
void status(saveState saveClass);


//MAIN
//==========================================================

int main() {
	saveState saveClass;
	character steve; //steve is the player


	saveClass.setXlocation(3);
	saveClass.setYlocation(3);
	saveClass.setMap('A', saveClass.getXlocation(), saveClass.getYlocation());

	int decision = NULL;
	//bool borderBoolean = true;
	//char color = ' ';
	


	menu(saveClass, steve, 0); //Sets decision to 1 if answer is play game, sets decision to 2 if answer is settings




	return 0;
}




void menu(saveState saveClass, character steve, int secondTimeMenu) {
	
	bool menuTest = false, secondTime = false;
	char junk;
	char choice;

	saveClass.setSave(false);  //Resets autosave to false
	do {

		cin.clear();
			

		system("CLS");
		type_text("| Steve vs the Skeleton Horde 1.0 |", 20, true, true);

		if (secondTimeMenu == 1) {
			type_text("Helpful tip: Sometimes when faced with an input error, enter it twice (aa), (bb), (cc)", 0, true, true);
		}

		if (!saveClass.getBorder())
			type_text("\nBorders turned off!\n\n", 100, saveClass.getBorder(), false);

		type_text("\nOptions:\n\n===========================\n", 40, false, true);

		cout << "A: Play game" << endl;
		cout << "B: Settings" << endl;
		cout << "C: Exit" << endl;
		cout << "D: About" << endl;
		cout << "E: Status" << endl;

		


		cout << endl << "Selection: ";

		//cin >> choice;
		cin.ignore(secondTimeMenu); //if I return to menu from somewhere, I need to cin.ignore or else itll read the endline as a character
		cin.get(choice);
		choice = toupper(choice);


		if (choice == 'A') {
			menuTest = false;
			loadgame(saveClass, steve);
			
		}
		else if (choice == 'B') {
			menuTest = false;
			settings(saveClass, steve);
		
		}
		else if (choice == 'C')
			menuTest = false;

		else if (choice == 'D') {
			about();
			menuTest = true;
		}

		else if (choice == 'E') {
			menuTest = true;
			status(saveClass);
		}

		else if (choice == 'F') //easter egg
		{
			menuTest = false;
			flashing(saveClass);
			cout << endl;
			type_text("| Cheat code activated! |", 40, saveClass.getBorder(), true);
			this_thread::sleep_for(std::chrono::milliseconds(1000));
			menu(saveClass, steve, 1);

			saveClass.setCode("hugehp");
		}


		else {

			
			menuTest = true;
			secondTime = true;
		
				cout << endl << "Invalid. Choice value: " << choice << "  Enter any key to restart menu...";
				if (secondTime) cin.ignore();
				cin.get(junk);
			
			}

	} while (menuTest);

}

//This was made on my car ride back from DC.  I took the core concept from stack overflow, 
//and heavily modified it to accept three other parameters, and code to determine length and implement a border based on it

void type_text(const string& text, int time, bool borderBoolean, bool endline)
{


	//determines length of border
	int stringLength = text.length();
	int count = 0;
	string border;

	if (stringLength > 100)	stringLength = 100;


	if (borderBoolean) {
		while (count != stringLength) {
			border += '=';
			count++;
		}
	}


	if (borderBoolean) cout << border << endl;

	// loop through each character in the text
	for (size_t i = 0; i < text.size(); ++i)
	{
		// outputs one character in C-string
		cout << text[i] << flush;

		// sleep for the amount of milliseconds in time
		this_thread::sleep_for(chrono::milliseconds(time));
	}
	if (borderBoolean) cout << endl << border;
	if (endline) cout << endl;
}

void flashing(saveState saveClass) {
	

	//I'm using system color commands, because this is a neat little feature I didn't really want to pour over.
	int time = 30;
	int loopTime = 5;
	char color = saveClass.getColor();

	for (int i = 0; i < loopTime; i++)
	{
		system("color 0A");
		this_thread::sleep_for(std::chrono::milliseconds(time));
		system("color 0B");
		this_thread::sleep_for(std::chrono::milliseconds(time));
		system("color 0C");
		this_thread::sleep_for(std::chrono::milliseconds(time));
		system("color 0D");
		this_thread::sleep_for(std::chrono::milliseconds(time));
		system("color 0E");
		this_thread::sleep_for(std::chrono::milliseconds(time));
		system("color 0F");
		this_thread::sleep_for(std::chrono::milliseconds(time));

	}

	if (color == 'R') {
		system("color 0C");
	
	}
	else if (color == 'G') {
		system("color 0A");

	}
	else if (color == 'B') {
		system("color 09");
	
	}
}

void settings(saveState saveClass, character steve)
{
	
	char yorn = ' ', junk; //yorn has to be seeded or else it'll give off an error. I've been running into this a lot for my project.
	bool yornTest = false;

	do {
		system("CLS");
		type_text("Do you want borders for the game? Y / N", 30, true, true);
		cout << endl << "Selection: ";
		cin.ignore();
		cin.get(yorn);

		yorn = toupper(yorn);

		if (yorn == 'Y') {
			yornTest = false;
			saveClass.setBorder(true);
		}
		else if (yorn == 'N') {
			yornTest = false;
			saveClass.setBorder(false);
	}
		else {
			yornTest = true;
			cout << "Error @ borderBoolean.  yorn: " << yorn;
			cin.ignore();
			cin.get(junk);
		}

	} while (yornTest);

	do {

		yornTest = false;
		yorn = ' '; //I know this is asking for R, G or B, but I'm commenting this out so everyone knows I recycled my function.

		cout << endl;

		type_text("Default text color:  | R | G | B ||", 30, true, true);
		cout << endl << "Selection: ";

		cin.ignore();
		cin.get(yorn);

		yorn = toupper(yorn);

		if (yorn == 'R') {
			system("color 0C");
			saveClass.setColor('R');
			yornTest = false;
		}
		else if (yorn == 'G') {
			system("color 0A");
			saveClass.setColor('G');
			yornTest = false;
		}
		else if (yorn == 'B') {
			system("color 09");
			saveClass.setColor('B');
			yornTest = false;
		}
		else {
			yornTest = true;
			cout << "Error @ borderBoolean q#2.  yorn: " << yorn;
			cin.ignore();
			cin.get(junk);
		}


	} while (yornTest);

	menu(saveClass, steve, 1);
}

void loadgame(saveState saveClass, character steve) {

	char choice = ' ', junk;
	bool test, fileTest1, fileTest2;
	char filename[30];
	string password, code=""; //code is the filesave, password just ensures the program is looking at the right txt file.
	ifstream fin;
	ofstream fout;
	string dirChecker = "";
	int menuIg = 1;
	

	do {
		fileTest1 = false;
		fileTest2 = false;
		test = false;


		cin.clear();
	
		system("CLS");
		
		cout << "File: " << endl;
		cout << "====================" << endl;
		cout << "A: Load game" << endl;
		cout << "B: New game" << endl;
		cout << "C: Main Menu" << endl << endl;
		//cout << endl << "Choice: =" << choice << "= (Debugging)" << endl << endl;
		cout << "Selection: ";
		
		


		cin.ignore(menuIg);
		cin.get(choice);

		choice = toupper(choice);

		if (choice == 'A') {
			saveClass.setSave(true);
			
			cout << endl << "====================" << endl << endl;
			cout << "Note: Path requires only one slash. . ." << endl << endl;
			cout << "Enter filepath: ";
			cin.ignore();
			cin.getline(filename, 30);
			cout << endl;
			menuIg = 0;

			
			for (int i = 0; i < 3; i++)
				dirChecker = dirChecker + filename[i];

			if (dirChecker != "C:/") {
				cout << "Invalid directory, remember that in this program paths must use this type of slash: /" << endl;
				pause(false);
				loadgame(saveClass, steve);
			}

			fin.open(filename, fstream::in);

			if (fin.fail()) {
				cout << "Error reading file!" << endl << endl;
				test = true;
			}
			else { 
				fileTest1 = true;
				cout << endl << "Success finding file!" << endl; }

			
			fin >> password;
			fin >> code;
			fin.close();

			cout << "Passcode: =" << password << "=" << endl;

			if (password == "tangosucka")
			{
				cout << "Passcode success!" << endl;
				fileTest2 = true;

				saveClass.setCode(code); //loads save code into class member
				cout << saveClass.getCode();  //This works, option B is kind of buggy

				game(saveClass, steve);
			}
			else { 
				cout << "Invalid passcode in file." << endl;
				test = true;
			}

			cout << endl << endl;

			
			//What I didn't realize is how the do-while encompassing this entire function could do everything below easily.

			//if (!fileTest1 || !fileTest2) {
			//	cout << "Error.  Returning to main menu.";
			//	cin.get(junk);
			//
			//	menu(borderBoolean, color, 0);
			//}

			

			//At this point, program should have checked the password at the start of the file, and taken the code delimited by a space.
			//cout << endl << endl << code;
			//system("pause");


			//game(code,true);

		}
		/*
		else if (choice == 'B') {
			bool ohHeckNo = false;
			string pass = "tangosucka";
			string genCode = "aaa";
			string password, code;
			//Vanilla passwords

			menuIg = 0;


			cout << endl << "====================" << endl << endl;
			cout << "Note: User must create/open .txt file. . ." << endl << endl;
			cout << "Enter filepath: ";

			cin.ignore();
			cin.getline(filename, 30);

			cout << endl;

			for (int i = 0; i < 3; i++)
				dirChecker = dirChecker + filename[i];

			if (dirChecker != "C:/") {
				ohHeckNo = true;
				cout << "Invalid directory, remember that in this program paths must use this type of slash: /" << endl;
				pause(false);
				loadgame(saveClass, steve);
			}

			//Checks passcode
			fin.open(filename, fstream::in);
			if (fin.fail()) {
				test = true;
				cout << "Failed to open file for reading passcode" << endl;
				ohHeckNo = true;
			}
			else {
				cout << "Successfully opened file for reading passcode" << endl;
			}

			fin >> password;
			fin >> code;
			fin.close();
			cout << "Passcode: =" << password << "=" << endl;

			
			//If passcode isnt found, file is given vanilla seed
			if (!ohHeckNo) {
				if (password != pass || !test) {
					cout << "Passcode invalid, giving file blank save." << endl;

					fout.open(filename);
					fout << pass << " " << genCode;
					fout.close(); 
				}
				else {
					cout << "Loaded save!" << endl;
					saveClass.setCode(code); //loads save code into class member
					cout << saveClass.getCode();
				}
			}
			
			//game(code,true);
			//true for save game
		}*/
		else if (choice == 'B') {
			saveClass.setSave(false);
			game(saveClass, steve);
			test = false;

			//game(code,false);
			//false for dont save game
		}
		else if (choice == 'C') {
			cin.ignore();
			menu(saveClass, steve, 1);
			test = false;
		}

		else {
			test = true;

			system("CLS");
			cout << "Error.  Enter any key to return to menu.";


			cin.ignore();
			cin.get(junk);

		}


	} while (test);

	pause(false);
}

void pause(bool ignore) {

	if (ignore) cin.ignore();
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}



void game(saveState &saveClass, character steve) {

	codeset(saveClass, steve);

	system("CLS");
	
	//GodMode for late-game testing
	/*
	steve.setKillcount(100);
	steve.setGreatsword(true);
	steve.setHp(10000);
	*/

	char direction = ' ';
	bool GAMEOVER = false, secondTime = false;
	string swordType;

	

	

	do{
		system("CLS");

		direction = ' ';
		
		//cout << "Color code: " << saveClass.getColor() << endl;

		if (steve.getSword() == 1) swordType = "Rusty Sword";
		else if (steve.getSword() == 2) swordType = "Greatsword";
		else if (steve.getSword() == 0) swordType = "Bloodied fists";

		cout << endl << " |Current HP: " + to_string(steve.getHp()) + " | Potions: " + to_string(steve.getPotion()) + " | Weapon: " + swordType + " | Killcount: " + to_string(steve.getKillcount()) + " | " << endl;

		displayMap(saveClass);

		if (saveClass.getCode() != "aaa") cout << endl << " |Code: " << saveClass.getCode() << " | " << endl; //displays code if there is one


	

		
		cout << endl << "\n |Input: D for Down, L for Left, U for Up, R for Right | \n |Player Character: A | \n";
		cout << endl << " Enter direction: ";

		

		//if secondtime, dont ignore
		if (!secondTime) cin.ignore();
		cin >> direction;
		direction = toupper(direction);

		movement(saveClass, direction);
		encounter(saveClass, steve, GAMEOVER);
		


		secondTime = true;
		if (direction == '\n') cin.ignore();



		if (steve.getHp() <= 0) {
			GAMEOVER = true; //checks HP
			system("CLS");
			type_text("You have died. . .", 100, false, false);
		}

		if (saveClass.getWin()) {
			system("CLS");
			type_text("A great evil has been vanquished from these lands. \n\nCongratulations on defeating the SPIDER QUEEN.\nThe inhabitants of Steveville are safe once again,\nand will never forget your sacrifice.\n\nCreated by Luke Maxwell\n4/17/19", 70, false, false);
			GAMEOVER = true;
		}

	} while (!GAMEOVER);

}

void movement(saveState &saveClass, char direction) {

	/*This function is supposed to get the indices of
	the map member from saveClass, stored at xlocation and ylocation.
	These two location variables remember where the "player" is in the
	game. 

	Determined by the input, it sets the player character (literal A) to a new spot
	by using tempX and tempY, before resetting the starting point back to the background (literal X).

	
	
	*/

	bool validator;


	do {
		
		validator = false;
		int tempX = saveClass.getXlocation();
		int tempY = saveClass.getYlocation();







		saveClass.setMap('X', saveClass.getXlocation(), saveClass.getYlocation()); //Sets old player character space back to X upon movement




		if (direction == 'U')
		{
			saveClass.setYlocation(--tempX);
			saveClass.setMap('A', tempX, tempY);
		}
		else if (direction == 'D')
		{
			saveClass.setYlocation(++tempX);
			saveClass.setMap('A', tempX, tempY);
		}
		else if (direction == 'L') {
			saveClass.setXlocation(--tempY);
			saveClass.setMap('A', tempX, tempY);
		}
		else if (direction == 'R') {
			saveClass.setXlocation(++tempY);
			saveClass.setMap('A', tempX, tempY);
		}
		else {

			cout << "Input error!" << endl;

			bool secondtime = true;
			pause(secondtime);
			secondtime = true;

		
		}



		saveClass.setXlocation(tempX);
		saveClass.setYlocation(tempY);
		saveClass.setMap('A', tempX, tempY);





		//Resets temps to new locations
		//tempX = saveClass.getXlocation();
		//tempY = saveClass.getYlocation();

		saveClass.setMap('A', saveClass.getXlocation(), saveClass.getYlocation()); //Sets player character to new space

		//cout << endl << endl<< tempX << " " << tempY << " " << direction << "\t"<< saveClass.getXlocation()<< "\t" << saveClass.getYlocation();
		//pause(true);

		//cout << endl << "xlocation: " << saveClass.getXlocation() << endl;
		//cout << "ylocation: " << saveClass.getYlocation() << endl;

		//cout << "Temp X: " << tempX << endl;
		//cout << "Temp Y: " << tempY << endl;

	} while (validator);
}

void displayMap(saveState saveClass) {
	for (int ycount = 0; ycount < 6; ycount++) {
		cout << endl << " . ";
		for (int xcount = 0; xcount < 6; xcount++)
			cout << saveClass.getMap(ycount, xcount) << " . ";
	}

}

void encounter(saveState &saveClass, character &steve, bool &gameover) {
	srand(time(NULL));
	int randNum = rand() % 100 + 1; //random number between 1 and 100


	bool validator, boss = false; //boss sets to true when player has killed 3 enemies, and will spawn in 1 in 5 or so many rolls
	char input = ' ';

	if (steve.getKillcount() >= 3) boss = true;

	//encounter, 3 in 10
	if (randNum >= 70) {
		string monsterType;

		if (randNum >= 85)
			monsterType = "Glib Glub";
		else if (randNum >= 70 && boss == true)
			monsterType = "Spider Queen";
		else if (randNum >= 70)
			monsterType = "Grob Grob";
		

		string textToDisplay = "A wild " + monsterType + " has appeared!";
		flashing(saveClass);

		system("CLS");

		type_text(textToDisplay, 30, saveClass.getBorder(), true);

		string tempHp = to_string(steve.getHp());
		string tempPotion = to_string(steve.getPotion());
	
		textToDisplay = "Options: A to ATTACK | F to FLEE | P to USE POTION | HP: " + tempHp + " | Potions: " + tempPotion + " | ";
		type_text(textToDisplay, 10, saveClass.getBorder(), true);


		if (randNum >= 85) {
			cout << R"(
			                  _.--""-._
  .                         ."         ".
 / \    ,^.         /(     Y             |      )\
/   `---. |--'\    (  \__..'--   -   -- -'""-.-'  )
|        :|    `>   '.     l_..-------.._l      .'
|      __l;__ .'      "-.__.||_.-'v'-._||`"----"
 \  .-' | |  `              l._       _.'
  \/    | |                   l`^^'^^'j
        | |                _   \_____/     _
        j |               l `--__)-'(__.--' |
        | |               | /`---``-----'"1 |  ,-----.
        | |               )/  `--' '---'   \'-'  ___  `-.
        | |              //  `-'  '`----'  /  ,-'   I`.  \
      _ L |_            //  `-.-.'`-----' /  /  |   |  `. \
     '._' / \         _/(   `/   )- ---' ;  /__.J   L.__.\ :
                   )";
		}

		else if (boss && randNum >= 70) {
			cout << R"(

     
          /---.'.__             ____//
               '--.\           /.---'
          _______  \\         //
        /.------.\  \|      .'/  ______
       //  ___  \ \ ||/|\  //  _/_----.\__
      |/  /.-.\  \ \:|< >|// _/.'..\   '--'
         //   \'. | \'.|.'/ /_/ /  \\
        //     \ \_\/" ' ~\-'.-'    \\
       //       '-._| :H: |'-.__     \\
      //           (/'==='\)'-._\     ||
      ||                        \\    \|
      ||                         \\    '
      |/                          \\
                                   ||
                                   ||
                                   \\
                                    ')";
		}
		else if (randNum >= 70) {
			cout << R"(
  _,_
  /7/Y/^\
  vuVV|C)|                        __ _
    \|^ /                       .'  Y '>,
    )| \)                      / _   _   \
   //)|\\                      )(_) (_)(|}
  / ^| \ \                     {  4A   } /
 //^| || \\                     \uLuJJ/\l
>//||| |\\\|                    |3    p)/
| """""  7/>l__ _____ ____      /nnm_n//
L>_   _-< 7/|_-__,__-)\,__)(".  \_>-<_/D
)D" Y "c)  9)       //V     \_"-._.__G G_c__.-__<"/ ( \
 | | |  |(|               < "-._"> _.G_.___)\   \7\
  \"=" // |              (,"-.__.|\ \<.__.-" )   \ \
   '---'  |              |,"-.__"| \!"-.__.-".\   \ \
     |_;._/              (_"-.__"'\ \"-.__.-".|    \_\
     )(" V                \"-.__"'|\ \-.__.-".)     \ \)";
		}
		

		

		do {
			cout << endl << "Selection: ";
			validator = false;

			cin.ignore();
			cin >> input;
			input = toupper(input);

			if (input == 'A') //attack
			{
	
				randNum = rand() % 100 + 1; //50/50 chance to kill
				int swordThreshold;

				if (steve.getSword() == 1)	swordThreshold = 50; //sword
				else if (steve.getSword() == 2) swordThreshold = 70; //greatsword
				else if (steve.getSword() == 0) swordThreshold = 20; //unarmed

				if (boss && monsterType == "Spider Queen") swordThreshold = swordThreshold - 20;

					if (randNum <= swordThreshold) {
						cout << "You killed the " + monsterType + "!" << endl;
						steve.setKillcount(steve.getKillcount() + 1); //increments killcount by 1

						if (monsterType == "Spider Queen") saveClass.setWin(true); //Victory
					}

					else if (randNum > swordThreshold) {
						randNum = rand() % 100 + 1; //damage taken generator

						if (boss && randNum >= 70 && randNum < 85) randNum = randNum * 3; //boss attack has x3 multiplier
						steve.setHp((steve.getHp() - randNum)); //Sets HP to original HP minus damage taken
						cout << "You took " + to_string(randNum) + " damage!" << endl;
					}
				
			}

			else if (input == 'P') {


				if (steve.getPotion() >= 1) {
					steve.setPotion(steve.getPotion() - 1); //if player has potions, reduce them by 1

					steve.setHp(steve.getHp() + 100);

					type_text("| HP increased by 100 |", 40, saveClass.getBorder(), true);
				}
				else type_text("| No potions in inventory |", 40, saveClass.getBorder(), true);
					validator = true;
				
			}


			else if (input != 'F') //flee
				validator = true;




			cout << "Enter any key to continue. . .";
			//secondtime false

			bool secondtime = true;
			pause(secondtime);
			secondtime = true;

		} while (validator);

	}

	//find sword, 1 in 10
	else if (randNum >= 60) {
		int swordCheck = steve.getSword();

		//if player has a sword, or somehow, has no sword, give greatsword
		if (swordCheck == 1 || swordCheck == 0) {
			steve.setGreatsword(true);

			cout << endl;

			type_text("| You've found the GREATSWORD |", 40, saveClass.getBorder(), true);
			cout << endl;
			if (saveClass.getCode() == "barefists") type_text("| . . . but passed it up. . . |", 70, saveClass.getBorder(), false);

			bool secondtime = true;
			pause(secondtime);
			secondtime = true;
		}
	}

	else if (randNum >= 50) {
	cout << endl;

	steve.setPotion(steve.getPotion() + 1); //adds one potion

	type_text("| You've found a POTION |", 40, saveClass.getBorder(), false);



	bool secondtime = true;
	pause(secondtime);
	secondtime = true;
}

	//nothing, 5 in 10

}

void codeset(saveState saveClass, character &steve) {

	if (saveClass.getCode() == "highhp")
		steve.setHp(1000);
	else if (saveClass.getCode() == "barefists") {
		steve.setSword(false);
		steve.setGreatsword(false);
	}

}

void about() {
	system("CLS");

	cout << "Created by Lucas Maxwell" << endl;
	cout << "Student @ Jackson College" << endl;
	cout << "4/16/2019" << endl;
	cout << endl << endl << "=====================" << endl << "User Guide: " << endl << "=====================" << endl;

	cout << "Game is designed to load files with a passcode followed by cheat-code, \nor launched as a new game.";
	cout << "\n\nUser input is finnicky, so you may have to enter AA for A and BB for B from time to time.\nThis has to do with cin.get being finnicky in the input stream.\nI'm not a master programmer so whatever :)\n\nEndgame: Kill 3 skeletons and the FINAL BOSS spawns into the map.  Kill the FINAL BOSS\nand evil will be vanquished from Steveville for good.\n\n Weapons:\n -Rusty Sword\n -Greatsword\n -Bloodied Fists...?\n\nThe true gaming experience is with a maximized window!";
	pause(true);
}

void status(saveState saveClass) {

	cout << saveClass;
	pause(true);


}