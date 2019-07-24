#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
//keeping track of lines/number of occurences
int a = 0, w = 0,
c = 0, d = 0, j = 0,
z = 0, g = 0,line_c = 0,
line = 0,u = 0;
// all declared variables
string myLine,strg;
string word,word_1;
vector<string> v1,variables,words;
string swapPlaceholder = "1";
int semiTracker = 0;
int whiteSpaceTracker = 0;
int commaTracker = 0;
int apostropheTracker = 0;
bool genericCommaChecker = false;
bool printEqualChecker = false;
bool apostropheChecker = true;
bool commaCheckerForPrint = false;
bool hasApostrophes = false;
ifstream myFile("newdata.txt");
ifstream myFile2("newdata.txt");
string reservedTypes[] = { "INTEGER", "FLOAT", "STRING", "WORD" };
size_t commaLineSaver, missingSemiLine;

//if any operators are used, an = sign must be present. Passed into this function to check if there is one.
void operators(string wd,int ln)
{
	int j = 0;
	for(int i = 0; i<wd.length();i++){
		if (wd[i] == '=') { j++;}
	}
	if(j == 0 && u == 0) {cout << "Expected equal sign on line " << ln << endl;u++;}

}
// DYLAN
bool myFunc(string s, int lineNumber1)
{
    int aposTrack = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] == '\'')
        {
            aposTrack++;
        }
    }
    int myFuncTrack = 0;
    if (aposTrack == 2)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ',')
            {
                myFuncTrack++;
                return true;
            }
        }
        if (myFuncTrack != 1)
        {
            cout << "missing a comma on PRINT line" << endl;
            return false;
        }
    }
    if (aposTrack == 1)
    {
        cout << " Missing an apostrophe " << endl;
    }
}
// Check for various things, such as declared variables and commas
bool commasChecker(string input)
{
  int c = 0,s = 0, word_c = 0,holder = 0,p = 0;
	// find : and INTEGER, if true these aren't variables no commas needed.
  size_t found = input.find(":"),cap = input.find("INTEGER");
  if(found != string::npos && cap != string::npos) {s++;}
  ifstream file("newdata.txt");
  string str,word;

  if(file.is_open())
  {
    while(getline(file,str))
    {
      line_c++;
			if(str == "VAR"){          // line after VAR is always variable declaration
				holder = line_c + 1;
			}
      if(line_c == holder)   // if so then it all into a vector and delete all excess punctuations
      {
        stringstream ss(str);
        while(ss >> word) {
					word_c++;
					if(isalpha(word[0])){
						for(int i = 0,len = word.size();i < len;i++)
						{
							if(ispunct(word[i]) || word[i] == ','){
								word.erase(i--,1);
								len = word.size();
							}
						}
					}
					if(word[0] != ',' && word != "INTEGER")
					variables.push_back(word);
				}
      }
			// after check for the use of operators then call operators to check for = sign
			if(isalpha(str[0]) && line_c != 1){
				for(int j = 0;j<str.length();j++)
				{
					if(str[j] == '*' || str[j] == '/' || str[j] == '+' || str[j] == '-')
					{
						operators(str,line_c);
					}
				}
				// here is passing in all of the variables ever used in the program into a vector
				stringstream sa(str);
				while(sa >> word_1)
				{
					for(int i = 0,len = word_1.size();i < len;i++)
					{
						if(ispunct(word_1[i]) || word_1[i] == ',' || word_1[1] == '=')
						{
							word_1.erase(i--,1);
							len = word_1.size();
						}
					}
					if(word_1[0] != ',' && isalpha(word_1[0]) && !isupper(word_1[0])){words.push_back(word_1);}
				}
			}
		}
	}
	// done with while loop
	// now checking the number of commas
	for (int i = 0; i < found; i++)
	{
      if(input[i] == ',')
      {
        c++;
      }
	}
	// the pattern is for every word, there is 1 comma until the last word so 4 words 3 commas.
  if(s == 1) {word_c = word_c - 2; c = c + 1;}
  else c = c + 1;
  if(word_c == c) return true;
  else return false;

}
// using the vector of all variables used earlier to check with the actual declared variables
// if any variable does not match then it is undeclared.
void declared(){
	for(int i = 0;i<words.size();i++)
	{
		if(find(variables.begin(),variables.end(),words[i]) != variables.end() ){}
		else cout << "Error: use of undeclared variable -> " << words[i] << endl;
	}
}
// function using boolean function commasChecker()
void check()
{
	string fname = "newdata.txt";
	int holder = 0;
  ifstream file(fname);
  string str;
  int pc = 0;
	if(file.is_open()){
  	while(getline(file,str))
  	{
    	line++;
			if(str == "VAR"){
				holder = line + 1;
			}
		if(line == holder)
			{
        if(commasChecker(str) == true){}
        else cout << "Missing commas on line " << line << ".\n";
      }
  	}
  }
}
//----------------------------------DYLAN's CODE

bool findSemi(string s)
{
	size_t foundSemi = s.find(";");
	if (foundSemi != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool programSemiChecker()
{
	for (int i = 0; i < v1.size(); i++)
	{
		size_t foundProgram = v1[i].find("PROGRAM");
		if (foundProgram != string::npos)
		{
			missingSemiLine = foundProgram;
			// LOGIC TO CHECK FOR VALID PROGRAM NAME HERE

			if (findSemi(v1[i]))
			{
				return true;
				semiTracker++;
			}
			else
				return false;
		}
	}
	return false;
}

bool commaChecker()
{
	for (int i = 0; i < v1.size(); i++)
	{
		size_t foundVar = v1[i].find("VAR"); // line 2
		if (foundVar != string::npos)
		{
			string parseThis = v1[i + 1];
			for (int j = 0; j < parseThis.length(); j++)
			{
				if (parseThis[j] == ' ')
				{
					whiteSpaceTracker++;
				}
				if (parseThis[j] == ',')
				{
					commaTracker++;
				}
			}
			if (commaTracker != whiteSpaceTracker - 2)
			{
				commaLineSaver = foundVar + 1;
				return false;
			}
			else
				commaCheckerForPrint = true;
			return true;
		}

	}

}

bool finalLineChecker(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
		{
			return true;
			break;
		}
	}
	return false;
}
//----------------------------KHOA's CODE-----------

// checking for missing reserved words
bool miss(string yname) {
	int p = 0, v = 0, b = 0, e = 0;
	ifstream myfile("newdata.txt");
	if (myfile.is_open()) {
		while (myfile >> yname)
		{
			if (!yname.compare("PROGRAM")) { p++; }
			if (!yname.compare("VAR")) { v++; }
			if (!yname.compare("BEGIN")) { b++; }
			if (!yname.compare("END")) { e++; }
		}
	}
	if (p == 0 || v == 0 || b == 0 || e == 0) return (true);
	else return (false);
}
// initial check to see if any reserved word is present
bool reserved(string a) {
	if (!a.compare("PROGRAM") || !a.compare("VAR") || !a.compare("BEGIN") || !a.compare("END."))
		return (true);
	else
		return (false);
}
// function to use the boolean function miss
void missing(string tname) {
	int p = 0, v = 0, b = 0, e = 0;
	ifstream myfile("newdata.txt");
	if (myfile.is_open()) {
		while (myfile >> tname) {
			if (!tname.compare("PROGRAM")) { p++; }
			if (!tname.compare("VAR")) { v++; }
			if (!tname.compare("BEGIN")) { b++; }
			if (!tname.compare("END.")) { e++; }
		}
	}


	if (p == 0 && a == 0) { cout << "PROGRAM IS MISSING.\n"; a++; }
	if (v == 0 && w == 0) { cout << "VAR IS MISSING.\n"; w++; }
	if (b == 0 && c == 0) { cout << "BEGIN IS MISSING.\n"; c++; }
	if (e == 0 && d == 0) { cout << "END IS MISSING.\n"; d++; }

}
// function to run all function above, just calling 1 function in main()
void expected(string fname) {
	string word, new_str, str2;
	ifstream myfile(fname);
	if (myfile.is_open())
	{
		while (myfile >> word) {
			if (reserved(word) == true) { continue; }
			if (reserved(word) == false)//if(isupper(word[0]) && word != "PRINT" && word != "INTEGER")
			{
				size_t pos = word.rfind("("), posi = word.rfind(";");
				new_str = word.substr(0, pos);
				str2 = word.substr(0, posi);
				if (isupper(word[0]) && new_str != "PRINT" && str2 != "INTEGER")
				{
					cout << "Error: " << word << " is misspelled.\n";
				}
				else if ((miss(word) == true)) missing(word);
			}
		}
	}
}
//---------------------------------------------------------------
int main() {

	ifstream myfile("newdata.txt"); // newcode

	if (myFile.is_open())
	{
		expected("newdata.txt");
		while (!myFile.eof())
		{
			getline(myFile, myLine);
			v1.push_back(myLine);
			g++; // newcode
		}

		if (programSemiChecker())
		{
			// do nothing
		}
		else
			cout << "SEMICOLON MISSING ON LINE " << missingSemiLine << endl;

		if (myfile.is_open())
		{

				check(); // calling check function here to check/do a handfull of things from missing commas to undeclared variables.

		}

		if (findSemi(v1[2]))
		{
			// do nothing
		}
		else
			cout << "Semi missing on line 3 " << v1[2] << endl;



		for (int i = 4; i < v1.size() - 2; i++)
		{
			string parsePrint;
			parsePrint = v1[i];

			if (findSemi(v1[i]))
			{
				//do nothing
			}
			else
			{
				missingSemiLine = i;
				//cout << g << endl;
				cout << "SEMICOLON MISSING ON LINE " << missingSemiLine << " " << v1[i] << endl;
			}
			size_t foundPrint = v1[i].find("PRINT");
			if (foundPrint != string::npos)
			{
				 //cout << v1[i] << endl;
				//apostropheTracker = 0;
				myFunc(parsePrint,i);
				bool frontParentTrackerChecker = false;
				bool backParentTrackerChecker = false;
				string myTemp = v1[i];

				for (int j = 0; j < myTemp.length(); j++)
				{
					int tempTrack = 0;
					for (int k = 0; k < myTemp.length(); k++)
					{
						if (myTemp[k] == ',')
						{
							tempTrack++;
						}
					}
					if (tempTrack == 0)
					{

					}

					if (myTemp[j] == '(')
					{
						frontParentTrackerChecker = true;
					}

					if (myTemp[j] == ')')
					{
						backParentTrackerChecker = true;
					}

					if (myTemp[j] == '\'')
					{
						//apostropheTracker++;
						apostropheTracker++;
						for (int k = j; k < myTemp.length(); k++)
						{
							if (myTemp[k] == ',')
							{
								commaCheckerForPrint = true;
							}
						}
					}
					if (myTemp[j] == '=')
					{
						printEqualChecker = true;
					}
				}
				if (apostropheTracker < 2)
				{
					apostropheChecker = false;
				}

				if (frontParentTrackerChecker != true)
				{
					cout << "missing front parend (" << endl;
				}
				if (backParentTrackerChecker != true)
				{
					cout << "missing back parend )" << endl;
				}
			}
		}

	}
	if (apostropheChecker == false)
	{
		cout << "missing an apostrophe ' " << endl;
	}
	if (commaCheckerForPrint == false)
	{
		cout << "missing a comma in variable declaration " << endl;
	}

	string finalLine = v1[v1.size() - 2];

	if (finalLineChecker(finalLine) != true)
	{
		cout << "missing a . " << endl;
	}
	declared(); // calling declared here print out any use of undeclared variables

	//system("PAUSE");
	return 0;


}
