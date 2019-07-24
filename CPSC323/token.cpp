#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

bool reserved(string a){
  if (!a.compare("if") || !a.compare("else") ||
        !a.compare("while") || !a.compare("do") ||
        !a.compare("break") || !a.compare("continue") || !a.compare("int")
        || !a.compare("double") || !a.compare("float")
        || !a.compare("return") || !a.compare("char")
        || !a.compare("case") || !a.compare("char")
        || !a.compare("sizeof") || !a.compare("long")
        || !a.compare("short") || !a.compare("typedef")
        || !a.compare("switch") || !a.compare("unsigned")
        || !a.compare("void") || !a.compare("static")
        || !a.compare("struct") || !a.compare("goto"))

    return (true);

    return (false);
}
bool isequal(string e){
  for(int i=0;i<e.length();i++){
    if(e[i] == '='){
      return true;
      break;
    }
  }
  return false;
}
bool isvalid(string c){
  for(int i=0;i<c.length();i++)
  {
    if(!isalpha(c[i])){
      return false;
      break;
    }
  }
  return true;
}
void isreal(string b){
  int f=0;
  int p=0;
  for(int i=0;i<b.length();i++)
  {
    if(isdigit(b[i]))
    {
      f++;
    }
    if(b[i] == '.'){
      p++;
    }
  }
  if(p==1){
    cout << b << "          REAL NUMBER" << endl;
  }
  if(f==b.length())
  {
    cout << b << "          INTEGER NUMBER" << endl;
  }
  else if (p>1)
  {
    cout << b << "          NOT REAL NUMBER" << endl;
  }
}

void identifier()
{
  string word,new_str,str2;
  int c=0,g=0,k=0,p=word.length()-1;
  ifstream myfile ("test.txt");
   if (myfile.is_open())
   {
     while (myfile>>word )
     {
       int a = word.length() - 1;
      if(isalpha(word[0]))
      {
        if(reserved(word) == true)
        {
          {
            cout << word << "       RESERVED WORD" << endl;
          }
        }
        //Checking for punctuations
        else
        {
          if(word[a] == ',')
          {
            g++;
            if(g == 1)
            {
              cout << word[a] << "          SPECIAL CHARACTER" << endl;
              word.erase(remove(word.begin(),word.end(),';'),word.end());
            }
          }
          if(word[a] == ';')
          {
            c++;
            if(c==1)
            {
              cout << word[a] << "          SPECIAL CHARACTER" << endl;
              word.erase(remove(word.begin(),word.end(),';'),word.end());
            }
          }
          //delete all , and ;
          word.erase(remove(word.begin(),word.end(),','),word.end());
          word.erase(remove(word.begin(),word.end(),';'),word.end());
          // check if valid identifier/token
          if(isvalid(word) == false)
          {
            // if there is an equal sign then split the string
            if(isequal(word) == true)
            {
              size_t pos = word.rfind("=");
              new_str = word.substr(0, pos);
              str2 = word.substr(pos+1,word.length());

              word.erase(remove(word.begin(),word.end(),','),word.end());
              word.erase(remove(word.begin(),word.end(),';'),word.end());
              cout << new_str << "        INDENTIFIER" << endl;
              isreal(str2);
            }
            // if not, proceed
            else
            {
              word.erase(remove(word.begin(),word.end(),','),word.end());
              word.erase(remove(word.begin(),word.end(),';'),word.end());
              cout << word << "     INVALID TOKEN" << endl;
            }
          }
          else cout << word << "       INDENTIFIER" << endl;
        }
      }
      // if it starts with a digit, followed by letters
      else if(isdigit(word[0]))
      {
        if(!isdigit(word[1]))
        {
          word.erase(remove(word.begin(),word.end(),','),word.end());
          word.erase(remove(word.begin(),word.end(),';'),word.end());
          cout << word << "       INVALID TOKEN" << endl;
        } else isreal(word);
      }
    }
  }
     myfile.close();
}

int main(){
  ofstream myfile;
  myfile.open ("test.txt");
  myfile << "int Bob, 2you, john, Adam.Smith;\nfloat taxYear=2013, taxRate=29.2;\n";
  myfile.close();
  identifier();

  return 0;

}
