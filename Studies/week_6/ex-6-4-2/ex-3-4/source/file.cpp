#include "file.h"



int cfile::FileHandle::size(){
    if(state == FileState::error){
        return 0;
    }

    std::fseek(fp, 0L, SEEK_END);
    int size = std::ftell(fp);
    std::rewind(fp);
    return size;
}



bool cfile::FileHandle::is_open(){
    return state == FileState::open;
}



void cfile::FileHandle::set_state(){
    if(std::ferror(fp)){
        state = FileState::error;
    }
    else if(std::feof(fp)){
        state = FileState::eof;
    }
}



const std::string &cfile::FileHandle::readline()
{
    // move chunks from temp
    char buffer[100];
    while (std::fgets(buffer, 100, fp)){
        ss << buffer;

        set_state();
        if(!is_open() || sizeof(buffer) / sizeof(buffer[0]) < 100){
            break;
        }
    }

    row = ss.str();
    ss.clear();
    return row;
}


const std::string& cfile::FileHandle::last_row(){
    return row;
}


// read all lines from a file
std::vector<std::string> cfile::readlines(cfile::FileHandle& handle){
    std::vector<std::string> lines;
    while (handle.is_open()){
        lines.push_back(handle.readline());
    }
    return lines;
}