#include <string>
#include <iostream>
#include <thread>
#include <queue>
#include <fstream>
#include "EnumTools.hpp"


#define LOG_ENTRY std::cout << "[" <<"Trace"<< "]" << " - " << __LINE__ << ": " << __PRETTY_FUNCTION__ << "\n"
#define LOG_THIS(LOG_MODE, log_message) std::cout << "[" << EnumTools::EnumToString(LOG_MODE) << "]"<< " " << log_message << "\n"

class Logger
{
    private:
    const std::string file_name_;
    std::queue<std::string> queue_; /* not thread safe....not implemented yet*/
    std::ofstream stream_;
    std::thread logger_thread_;

    public:
        /*std string constructor can throw,use char* instead maybe*/

    explicit Logger(const std::string &file_name_);
    void log(std::string&& data);
    void write();

};
