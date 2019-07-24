#include <iostream>
using namespace std;

void op1(string w1){
  int l = w1.length() - 1;
  int ch = w1.length()-2, ad = 0;

  for(int i=1;i<w1.length();i++)
  {
    if(w1[i] == 'a' && w1[l] == 'b')
    {
      ad += 1;
      //cout << w1  << " " << ch << " " << ad << " is valid, and will be accepted.\n";
    }
  }
  if (ad == ch){
    cout << w1  <<" is valid, and will be accepted.\n";
  } else cout << w1  <<" is invalid, and will not be accepted.\n";

}
void op2(string w2){
  int l = w2.length() - 1;
  int ch = w2.length(), ad = 1;

  for(int i=1;i<w2.length();i++){
    if(w2[i] == 'b'){
      ad += 1;
      //cout << w2  << " " << i << " is valid, and will be accepted.\n";
    }
  }
  if(ad == ch ){
    cout << w2 << " is valid, and will be accepted.\n";
  } else cout << w2 <<" is invalid, and will not be accepted.\n";
}
int main()
{
  string input;
  char c;
  cout << "L = aa*b|bb*\n";

  do {
  cout << "Enter word: ";
  cin >> input;

  for(int i=0;i < input.length(); i++)
  {
    if(input.find_first_not_of("ab") != string::npos)
    {
      cout << input << " is invalid, and will be rejected by the language.\n";
      goto cont;
    }
  }

  if(input[0] == 'a')
  {
    if(input.length() > 1)
    op1(input);
    else cout << input << " is invalid, and will be rejected by the language.\n";
  }
    else if (input[0] == 'b'){op2(input);}

    cont:cout << "Continue(y/n)? ";
    cin >> c;

}while(c=='Y' || c== 'y');

  return 0;
}
