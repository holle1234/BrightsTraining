#if !defined(CFILE)
#define CFILE

#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>


namespace cfile
{
    
enum class FileState{
    open,
    eof,
    error,
    closed,
};


class FileHandle
{

private:
    FILE* fp;
    const std::string filepath;
    const std::string mode;
    std::stringstream ss;
    std::string row;
    void set_state();
    FileState state {FileState::closed};

public:

    FileHandle(std::string path, std::string mode = "r");
    ~FileHandle();

    const std::string& readline();
    const std::string& last_row();
    int size();
    bool is_open();

    operator bool(){return is_open();}
};



} // namespace cfile


#endif // CFILE
