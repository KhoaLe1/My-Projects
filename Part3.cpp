#include <iostream>
#include <fstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void languageConverter()
{
	string line;
	ifstream myfile("final.txt");
	ofstream tempFile("temp.txt");
	string name;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (line.substr(0, 7) == "PROGRAM")    //Detects if the first word of the line is PROGRAM
			{
				size_t pos9 = line.find(";");
				name = line.substr(8, line.length()-9) + ".cpp";  //sets name as the following word with a .cpp added on at the end
				tempFile << "#include <iostream>" << endl;
				tempFile << "using namespace std;" << endl;
			}
			else if (line.substr(0, 3) == "VAR") //detects the word VAR at the start of line
			{
				tempFile << endl; //skips a line
			}
			else if (line.find("INTEGER") != string::npos)  //Detects if the word INTEGER is found in the line at all
			{
				cout << "found" << endl;
				size_t pos3 = line.find(":");   //finds the : in the line and sets that as pos3
				string variables = line.substr(0, pos3);      //declares variables at all things between the start of line and the length up to pos3
				tempFile << "int " << variables << ";" << endl;
			}
			else if (line.substr(0, 5) == "BEGIN") //detects the word BEGIN in the line
			{
				tempFile << "int main()" << endl;
				tempFile << "{" << endl;
			}
			else if (line.substr(0, 5) == "PRINT") //Detects PRINT as the first word of a line
			{
				char paren = 34;   //ascii value used for (
				size_t pos4 = line.find('(');   //find the position of the (
				size_t pos5 = line.find('=');		//find the position of the =
				size_t pos6 = line.find(';');		//find the position of the ;
				size_t pos10 = line.find(39);		// finds the position of the '
				string coutwithcomma = line.substr(pos4+2,pos5 - pos4-1);  //takes the position of ( moves up 2 jsut to have the words for the length of the string
				string coutwithcomma2 = line.substr(pos5 + 4, pos6-pos5-5);  //takes the position of = moves up 2 to find all words after the comma
				string coutnocomma = line.substr(pos4 + 1, pos6-pos4 -2);  //finds all words that fall between ( and the ; removing a few

				if (line.find(",") != string::npos)  //checks if a , is in the line at all
				{
					tempFile << "	cout << " << paren << coutwithcomma << paren << " << " << coutwithcomma2 << " << endl;" << endl;  //creates the c++ line for printing out if a comma is included
				}
				else
				{
					tempFile << "	cout << " << coutnocomma << " << endl;" << endl;  //creates a c++ print out if no comma is included
				}

			}
			else if (line.substr(0, 3) == "END")  //Detects if END is at the start of a line
			{
				tempFile << "	return 0;" << endl;
				tempFile << "}" << endl;
			}
			else
			{
				tempFile << "	" << line << endl;  //if no key words are detected then just print of the line word for word
			}
		}
	}
	ofstream finalFile(name);
	ifstream tempFile2("temp.txt");
	if (tempFile2.is_open())
	{
		while (getline(tempFile2, line))
		{
			finalFile << line << endl;  //transfers over from the temp file to a cpp file
		}
	}
}



int main()
{
	languageConverter();
	return 0;
}
