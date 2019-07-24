#include "BrowserHistory.h"

BrowserHistory::BrowserHistory()
{

}

BrowserHistory::~BrowserHistory()
{

}

void BrowserHistory::visitSite(Webpage newSite) {
  if(!curr_nav.empty()){
    list<Webpage>::iterator forward;
    forward = curr_position;
    forward++;
    curr_nav.erase(forward,curr_nav.end());
  }
  full_history.push_back(newSite);
  curr_nav.push_back(newSite);
  curr_position = curr_nav.end();
  curr_position--;

}
string BrowserHistory::getURL() {
  return curr_position->getURL();
}

size_t BrowserHistory::getNavSize() {
    return curr_nav.size();
}

string BrowserHistory::back() {
    if(curr_position != curr_nav.begin())
    {
      curr_position--;
    }
   return getURL();
  }

string BrowserHistory::forward() {
  if(curr_position != curr_nav.end())
  {
    curr_position++;
  }
  return getURL();
}

void BrowserHistory::readHistory(string fileName)
{
    ifstream myfile(fileName);
    if (myfile.is_open())
    {
      cout << " Succesfully opened file " << endl;
      string check;
      time_t Time;
      string URL_;
      while (myfile >> check ){
        if (check.compare("new") == 0){
          myfile >> URL_ >> Time;
          visitSite(Webpage(URL_, Time));
        }
        else if (check.compare("back") == 0){
          back();
        }
        else if (check.compare("forward") == 0){
          forward();
        }
      myfile.close();
    }
  }
}

void BrowserHistory::printBackSites() {
  for ( list<Webpage>::iterator temp = curr_nav.begin(); temp != curr_position; temp++)
        cout << temp->getURL() << endl;
}

void BrowserHistory::printForwardSites() {
  for ( list<Webpage>::iterator temp = curr_position; temp != curr_nav.end(); temp++)
        cout << curr_position->getURL() << endl;
}

void BrowserHistory::printFullHistory() {
  for(list<Webpage>::iterator temp = full_history.begin(); temp != full_history.end(); temp++)
  cout << curr_position->getURL() << endl;
}
