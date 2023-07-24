#if !defined(CFILE)
#define CFILE

#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>


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

    FileHandle(std::string path, std::string mode = "r") : filepath(path), mode(mode) {
        fp = std::fopen(filepath.c_str(), mode.c_str());
        std::rewind(fp);
        state = FileState::open;
    }
    ~FileHandle() {std::fclose(fp); fp=nullptr; state = FileState::closed;}

    const std::string& readline();
    const std::string& last_row();
    int size();
    bool is_open();
    operator bool(){return is_open();}

};

// read all lines from a file
std::vector<std::string> readlines(FileHandle& handle);
        

} // namespace cfile


#endif // CFILE
