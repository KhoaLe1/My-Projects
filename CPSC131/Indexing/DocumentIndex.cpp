//****************************************************************************************
//
//	INCLUDE FILES
//
//****************************************************************************************
#include	<fstream>
#include	<iostream>
#include	<string>

//#include	<unistd.h>

#include	"DocumentIndex.h"
#include	"GetLine.h"

using namespace std;

//****************************************************************************************
//
//	CONSTANT DEFINITIONS
//
//****************************************************************************************

//****************************************************************************************
//
//	CLASSES, TYPEDEFS AND STRUCTURES
//
//****************************************************************************************
typedef	string::size_type	StringSize;

//****************************************************************************************
//
//	PUBLIC DATA
//
//****************************************************************************************

//****************************************************************************************
//
//	PRIVATE DATA
//
//****************************************************************************************

//****************************************************************************************
//
//	FUNCTION PROTOTYPES
//
//****************************************************************************************

//****************************************************************************************
//
//	DocumentFile::Close
//
//****************************************************************************************
void	DocumentFile::Close()
{
	//************************************************************************************
	//	LOCAL DATA

	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	file_.close();
	file_.clear();

	return;
}
//****************************************************************************************
//
//	DocumentFile::GetPageNumber
//
//****************************************************************************************
int	DocumentFile::GetPageNumber()
{
	//************************************************************************************
	//	LOCAL DATA
	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	return(pageNumber_);
}
//****************************************************************************************
//
//	DocumentFile::GetWord
//
//****************************************************************************************
string	DocumentFile::GetWord()
{
	//************************************************************************************
	//	LOCAL DATA
	string	word;
	bool isWord = false;
	int length;
	int i;
	int linein = 0; // linein is the number of spaces in the text.
	int start; // start of a word
	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	while( !isWord && text_.length()!=0)
		{ //loop until it receives an actual word or all of the words in string text_ is checked.
				linein = 0;
				if(text_.length() == 0) // if it reaches the end of text_ then return "".
			{
					return "";
			}
			while(text_[linein]==' ')
			// increase the linein for every blank space.
			{
					linein++;
			}
			start = linein;
			// start is equal to the number of spaces until there is a word.

			while(linein < text_.length() && text_[linein]!=' ')
			// increase linein when there is a word.
			{
					linein++;
			}
			// store the current word.
			word = text_.substr(start,linein-start);
			// start(beginning of a word), all the blank spaces until it reaches a word.
			// linein is all the blank spaces and letters, minus, start is the length of the current word.


			if(linein < text_.length()) // this is to store the remaining words in line in variable text_.
			{
				text_ = text_.substr(linein, text_.length() - linein);
			}
			else
			{
				text_ = "";
			}
			// This is the word checking process**************************************
			length = word.length(); // length of the current word

			// if statements checking for punctuations, quotations, parentheces, etc.
			 if(length > 1)
			 {
				 // if length is 1 or more check for " and '
					 if(word[length-1] == '"' || word[length-1] == '\'')
					 {

								word = word.substr(0,length-1);
								length--;
					 }
				// checking for parentheses
					 if( word[length-1] == ')' )
					 {
								word = word.substr(0,length-1);
								length--;

					 }
					 if( word[0] == '(' )
					 {
								word = word.substr(1,length-1);
								length--;
					 }
				// checking for punctuations
					 if(word[length-1]=='.'|| word[length-1]== ','|| word[length-1]==':'||word[length-1]==';'||word[length-1]=='?'||word[length-1]=='!')
					 {
								word = word.substr(0,length-1);
								length--;

					 }
				// checking for apostrophe and possessive s
					 if(word[length-2]=='\''&& word[length-1]=='s')
					 {
								word = word.substr(0, length-2);
								length -= 2;

					 }

				// if there is " or ' in front of a word
					 if(word[0]== '"' || word[0]== '\'')
					 {
								word = word.substr(1,length-1);
								length--;
					 }
			 }
			 // iterator to check for letters, making sure it is a word
			 i = 0;
			 while(i<length)
			 {
				 // if it does not contain letters a-z then bool isWord is false
						if((word[i] < 'a' || word[i] > 'z' )&& (word[i] < 'A' || word[i] > 'Z'))
						{
								isWord = false;
								break;
						}
						i++;
			 }
			 // if the condition above is not met then i will be equal to length
			 if(i==length)
			 {
				 isWord = true;
	 		 }

			 if(excluded_words.find(word) != excluded_words.end())
			 {
						isWord = false;
			 }

		 }
		 if(isWord == false)
		 	{
			 return "";
			}

	return(word);
}

//****************************************************************************************
//
//	DocumentFile::LoadExclusions
//
//****************************************************************************************
bool DocumentFile::LoadExclusions(const string& name)
{
	//************************************************************************************
	//	LOCAL DATA
	bool	success = true;
  string word;
	//************************************************************************************
	//	EXECUTABLE STATEMENTS
    ifstream myfile;
		// open name with exlusion words
    myfile.open(name);

    if(myfile.fail())
    {
        return false;
    }
		// stream it into word
    while(myfile >> word)
    {
			//	then insert exlusion words into a set
        excluded_words.insert(word);
    }
		return(success);
}
//****************************************************************************************
//
//	DocumentFile::Open
//
//****************************************************************************************
bool DocumentFile::Open(const string& name)
{
	//************************************************************************************
	//	LOCAL DATA

	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	file_.open(name, ios::in);

	if (!file_.fail())
	{
		//	You may add any useful initialization here.
		return(true);
	}
	else
	{
		return(false);
	}
}
//****************************************************************************************
//
//	DocumentFile::Read
//
//****************************************************************************************
bool	DocumentFile::Read()
{
	//************************************************************************************
	//	LOCAL DATA
	bool success = true;
	//************************************************************************************
	//	EXECUTABLE STATEMENTS
    getline(file_, text_); // get the line of text_ in file_
    if(text_.length()==0) // if the length of text_ is 0 that means its blank
    {
        getline(file_,text_); // then grab the next line
        if(text_.length()==0) // if that is also blank then new page
        {
            pageNumber_ +=1;
        }
        else // if not blank then continue getline
        {
            getline(file_,text_);
            return success;
        }
				// if end of file then done, if not then continue getline
        if(file_.eof())
        {
            success = false;
            return success;
        }
        else getline(file_,text_);
    }
		return(success);
}
//****************************************************************************************
//
//	DocumentIndex::Create
//
//****************************************************************************************
void	DocumentIndex::Create(DocumentFile& documentFile)
{
	//************************************************************************************
	//	LOCAL DATA
  string word = "";
	int size;
  //int update;
	//************************************************************************************
	//	EXECUTABLE STATEMENTS
		while(documentFile.Read())
    {
        while((word = documentFile.GetWord()) != "")
        {
					// the current word will be compared to the other words
					// if it matches the same word then the number of times that word appears will go up
            if(num_occurrences.find(word) != num_occurrences.end())
               {
								 num_occurrences[word]++;
							 }
							 else
							 {
								 // if it goes through and reaches the end without a match then there is only 1
								 num_occurrences[word] = 1;
							 }
						// if a word appears more than 10 times then delete the word
            if(num_occurrences[word]>10)
            {
                index.erase(word);
            }
						// Creating the index after checking how many times a word appears
           else
            {
							// if the word is in the map index
                if(index.find(word)!= index.end())
                {
									// index cannot be added by one but num_occurrences can, but doesn't work
									// cout index prints out the wrong values
									// size = index.at(word).size() + 1; plus one failed
									// cout << index[word][size]<< endl;
									// printing out 1s,2s,and 3s. Seems to be page numbers.
									size = index.at(word).size() - 1;
									// cout << index[word][size] << endl;
									// cout << documentFile.GetPageNumber() << endl;
									// size matches with page number, but not all
									// if doesn't match then insert the page number
                    if(index[word][size] != documentFile.GetPageNumber())
                    {
                  	 index[word].push_back(documentFile.GetPageNumber());
										}
                }
								// if it does match also insert, doesn't change the value but covers the other page num
								else {
									index[word].push_back(documentFile.GetPageNumber());
								}
            }
        }
    }
	return;
}
//****************************************************************************************
//
//	DocumentIndex::Write
//
//****************************************************************************************
void	DocumentIndex::Write(ostream& indexStream)
{

	//************************************************************************************
	//	LOCAL DATA
		int size;
		vector<int> page;
		map<string,vector<int>>::iterator it;
	//************************************************************************************
	//	EXECUTABLE STATEMENTS

    for(it = index.begin(); it!= index.end(); it++) // going through map index
    {
      indexStream << it -> first << ' '; // writing out iterator pointing to the first element which is a (word)
			page = it->second; // vector<int> page is equal to iterator pointing to the second element which is the (pageNumber_)
	 		for( int i = 0; i < page.size() - 1 ;i++)  // going through numbers in vector<int> and printing page num
       		{
         		indexStream << page[i] << ", ";
       		}
				// printing out the other pages
				size = page.size() - 1;
				// cout << page.size() << endl;
				// cout << size << endl;
				// similar in create, .size() is similar to page num but not quite correct
				indexStream << page[size] << endl;
    }
	return;
}
