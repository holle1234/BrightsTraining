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
    ss.str("");
    ss.clear();

    char buffer[100];
    std::stringstream::pos_type cpb, cpa;
    while (std::fgets(buffer, 100, fp)){

        cpb = ss.tellp();
        ss << buffer;
        cpa = ss.tellp();

        set_state();
        auto size = ((cpa - cpb) / sizeof(char)) - 1;
        if (size < 100){
            break;
        }
    }

    set_state();
    row = ss.str();
    
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