//*****************************************************************************************
//  Program Filename   : SoumenHangman.cpp
//  Version            : 1.0
//  Author             : Soumen Nath
//  Purpose            : To demonstrate the ability to create a hangman game using c++
//  Date               : December, 23
//  Input from         : Keboard
//  Output to          : Screen
//*****************************************************************************************


//Preprocessor Directives
#include <iostream>
#include <string>
#include <vector>
using namespace std;


//Function Declarations
void welcome();
void hangman(char);
char word(char);
char userGuess();
char wGuessed();
int strikes(char);


//Global Variables
const string pWord = "gravity"; //The predetermined word for this program
int strike = 7; //The value of this variable decreases each time a user guesses incorrectly
int win = 0; //The value of this variable increases each time a user guesses correctly
int counter = 0; //Variable that determines wheter or not a part is added to the visual hangman
vector<char> dWord(7); //stores the word so far 
vector<char> aGuessed; //stores the letters that were already guessed


//Name Constant Definitions
//*****************************************************************************************
// Function Name: main
// Purpose: main function of program
// Inputs to Function: N/A
// Outputs from Function: N/A
// External Inputs to Function: cin
// External Outputs from Function: cout
//*****************************************************************************************
int main()
{
	system ("color 89"); //Changes the background and text colour
    //Variable Declarations:
    int temVal; //Temporary variable that stores the the user's guess
    char space = ' '; //Variable that is just a space
    char option = 'y'; //Variable that stores the user's option when he or she loses
    //Function Body
    //Sets all the values of dWord into underscores
    for(int i=0; i<pWord.length(); i++)
	{
		dWord[i]='_';
	}
	do //Do the following while the user's option is set to y
	{
		do //Do the following while the user hasn't ran out of guesses and hasn't guessed the correct word
		{
			//Call on the following functions in this order
			welcome();
			//Pass the value in temVal to the following functions
		    hangman(temVal); 
		    word(temVal);
		    wGuessed();
		    temVal=userGuess(); //Make temVal equal to the value that is returned from userGuess
		    strikes(temVal);
		    //Add the user's guess and a space to the aGuessed vector 
		    aGuessed.push_back(temVal);
		    aGuessed.push_back(space);
		} while (strike>0 && win<7);
		//If the user guesses the correct word then the following statements in quotations are displayed and the program ends
		if (win==7)
		{
			system ("cls");
			cout<<"Congratulations. You have guessed the correct word and won the game!";
			cout<<endl;			
			break;
		}
		//If the user has ran out of guesses then the following statements in quotations are displayed and the user is able to choose whter or not to keep trying to guess the word
		if (strike==0)
		{
			cout<<"You lose! Better luck next time."<<endl;
			cout<<"Would you like to play again?";
			cout<<"\nPress y for yes or n for no: ";
			counter=0; //Resets the value of counter back to 0
			cin>>option; //Accepts user input
			//Asks the user to enter either y or n if they entered a different value
			while (option != 'y' && option !='n')
			{
				cout<<"Ivalid entry!"<<endl;
				cout<<"Please enter your option again: ";
				cin>>option;
			}
			system ("cls"); //Clears he screen
		}
		strike=7; //Resets the value of this variable to 7
		//If the user pressed n then the program terminates
		if (option=='n')
		{
			break;
		} 
	} while (option=='y');
	
    return 0;
}
//end function main


//Name Constant Definitions
//*****************************************************************************************
// Function Name: welcome
// Purpose: welcomes the user to the program
// Inputs to Function: N/A
// Outputs from Function: N/A
// External Inputs to Function: N/A
// External Outputs from Function: cout
//*****************************************************************************************
void welcome()
{
	//Displays the statements in quotations
	cout<<"Welcome to hangman"<<endl;
	cout<<"Your word is: "<<pWord.length()<<" characters long."<<endl;
}
//end function welcome


//Name Constant Definitions
//*****************************************************************************************
// Function Name: hangman
// Purpose: to provide a visual representation of how the user is doing to the user
// Inputs to Function: char
// Outputs from Function: N/A
// External Inputs to Function: N/A
// External Outputs from Function: cout
//*****************************************************************************************
void hangman(char temV) //temV is the variable that stores the temporary variable from main
{
	string hang = "  -------\n  |\t|\n  |\n  |\n  |\n  |\n__|__"; //String that contains the original hangman
	//If the user guessed an incorrect letter then the value of counter increases by the lenght of pWord
	//Otherwise if the user guessed correctly then the value of counter stays the same
	for(int j=0; j<pWord.length(); j++) 
	{
		if (pWord[j]!=temV)
	    {
	    	counter++;
		}
		else if (pWord[j]==temV)
		{
			counter-=6;
		}
	}
	//The hangman gets an additional part everytime the counter increases by the lenght of the predetermined word
	switch (counter)
	{
		case 14:
			hang = "  -------\n  |\t|\n  |\tO\n  |\n  |\n  |\n__|__";
			break;
		case 21:
			hang = "  -------\n  |\t|\n  |\tO\n  |    \\\n  |\n  |\n__|__";
			break;
		case 28:
			hang = "  -------\n  |\t|\n  |\tO\n  |    \\|\n  |\n  |\n__|__";
			break;
		case 35:
			hang = "  -------\n  |\t|\n  |\tO\n  |    \\|/\n  |\n  |\n__|__";
			break;
		case 42:
			hang = "  -------\n  |\t|\n  |\tO\n  |    \\|/\n  |\t|\n  |\n__|__";
			break;
		case 49:
			hang = "  -------\n  |\t|\n  |\tO\n  |    \\|/\n  |\t|\n  |    /\n__|__";
			break;
	}
	cout<<hang<<endl<<endl; //Displays the current hangman
}
//end function hangman


//Name Constant Definitions
//*****************************************************************************************
// Function Name: word
// Purpose: to display the word so far with __ or * in place of unguessed letters
// Inputs to Function: char
// Outputs from Function: N/A
// External Inputs to Function: N/A
// External Outputs from Function: cout
//*****************************************************************************************
char word(char temV)
{
	cout<<"Here is your word: "; //Displays the words in quotations
	//If the user guessed correctly than the a value of the dWord vector becomes the guessed letter
	for(int k=0; k<pWord.length(); k++)
	{
		if (pWord[k]==temV)
	    {
	    	dWord[k]=temV;
		}
		cout<<dWord[k]; //display the the word so far with __ or * in place of unguessed letters
	}
	cout<<endl<<endl;
}
//end function word


//Name Constant Definitions
//*****************************************************************************************
// Function Name: wGuessed
// Purpose: to display the letteres that have already been guessed
// Inputs to Function: N/A
// Outputs from Function: N/A
// External Inputs to Function: N/A
// External Outputs from Function: cout
//*****************************************************************************************
char wGuessed()
{
	cout<<"You have guessed the following letters: "; //Displays the statement in quotations
	//Displays the letters that have been guessed so far
	for(int l=0; l<aGuessed.size(); l++)
	{
		cout<<aGuessed[l];
	}
	cout<<endl<<endl;
}
//end function wGuessed


//Name Constant Definitions
//*****************************************************************************************
// Function Name: userGuess
// Purpose: to allow the user to guess a letter
// Inputs to Function: N/A
// Outputs from Function: return
// External Inputs to Function: cin
// External Outputs from Function: cout
//*****************************************************************************************
char userGuess()
{
	char guess; //Variable that temporarily stores the user's Guess
	cout<<"Guess a letter: "; //Displays the statement in quotations
	start: //notifies goto that start is here
	cin>>guess;	//Accepts the user's guess
	//Makes sures to accept only the first thing entred by the user and clear everything else
	cin.clear(); 
	cin.ignore(INT_MAX, '\n');
	//If the user's guess matches wih any of their previous guesses then he or she will be asked to enter another chracter
	for (int m=0; m<aGuessed.size(); m++)
	{
		while(aGuessed[m]==guess)
		{
			cout<<"\nYou have already pressed "<<guess<<". \nPlease try again: ";
			goto start; //makes the program go to the place laballed as start
		}
	}
	cout<<endl;
	return guess; //Returns the user's guess to main
}
//ends function userGuess


//Name Constant Definitions
//*****************************************************************************************
// Function Name: strikes 
// Purpose: to determine how many guesses the user has left
// Inputs to Function: char
// Outputs from Function: N/A
// External Inputs to Function: N/A
// External Outputs from Function: cout
//*****************************************************************************************
int strikes(char temV)
{
	int str=0; //Variable that is used to notify the user if he or she guessed incorrectly
	for(int n=0; n<pWord.length(); n++)
	{
		if (pWord[n]!=temV) //If the user guessed incorrectly then str increases by the length of the predetermined word 
	    {
	    	str++;
		}
		else //If the guessed coreectly then they will be notified and the value of win will increase by 1
		{
			cout<<temV<<" is in the word!"<<endl<<endl; 
			win++;
		}
	}
	//If the user guessed incorrectly than they will be notified of how many attempts (strikes) they have left
	if (str==7)
	{
		cout<<"Sorry "<<temV<<" is not in the word"<<endl<<endl;
		strike--;
		cout<<"You have "<<strike<<" strikes left."<<endl<<endl;	
	}
	system ("pause"); //Makes the user press a key to continue
	system ("cls"); //Clears the screen
}
