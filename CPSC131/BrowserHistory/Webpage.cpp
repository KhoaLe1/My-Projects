#include "Webpage.h"

Webpage::Webpage() {
  URL = " ";
  Time = 0;
    // TO BE COMPLETED
}

Webpage::Webpage(const string& webpageURL, const time_t& timeVisited) {
    URL = webpageURL;
    Time = timeVisited;// TO BE COMPLETED
}

string Webpage::getURL() {
  return URL;
    // TO BE COMPLETED
}

time_t Webpage::getTime() {
  return Time;// TO BE COMPLETED
}
