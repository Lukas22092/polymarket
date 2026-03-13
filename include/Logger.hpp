#include <string>
#include <iostream>
#include <thread>
#include <queue>
#include <fstream>
class Logger
{
    private:
    const std::string file_name_;
    std::queue<std::string> queue_;
    std::ofstream stream;

    public:
    explicit Logger(const std::string &file_name_, std::queue<std::string> queue_);
    void log(std::string&& data);
    void write();

};