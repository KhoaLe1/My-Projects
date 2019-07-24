// define and turn off for the rest of the test suite
#include <iostream>
#include "log.h"
loglevel_e loglevel = logERROR;

void logTest(void) {
    loglevel_e loglevel_save = loglevel;

    loglevel = logDEBUG;

    ofstream logfile;
    logfile.open("log.txt");
    log(logINFO) << " Error: using declaration requires a qualified name";
    logfile << log(logINFO);
    logfile.close();

    loglevel = loglevel_save;
}
int main()
{
  logTest();
  return 0;
}
