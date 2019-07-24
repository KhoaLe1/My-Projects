#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <fstream>
using namespace std;
#define log(level) 
//if (level > loglevel) ;
//else logIt(level);
int i = 0;
enum loglevel_e
    {logERROR, logWARNING, logINFO, logDEBUG};
auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
class logIt
{
public:
    logIt(loglevel_e _loglevel = logERROR) {
      i++;
      ofstream logfile;
        logfile.open("log.txt");
        logfile << ctime(&timenow) << "[" << i << "]";
        logfile.close();
        _buffer << ctime(&timenow) << "[" << i << "]";
    }

    template <typename T>
    logIt & operator<<(T const & value)
    {
        _buffer << value;
        return *this;
    }

    ~logIt()
    {
        _buffer << std::endl;
        std::cerr << _buffer.str();
    }

private:
    std::ostringstream _buffer;
};

extern loglevel_e loglevel;
