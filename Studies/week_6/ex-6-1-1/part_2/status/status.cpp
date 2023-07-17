#include "status.h"
#include <iostream>
#include <string>


void Order::advance(){

    switch (status)
    {

    case Status::ordered : {
        status = Status::received;
        istatus++;
        break;
    }
    case Status::received : {
        status = Status::processed;
        istatus++;
        break;
    }
    case Status::processed : {
        status = Status::packed;
        istatus++;
        break;
    }
    case Status::packed : {
        status = Status::delivered;
        istatus++;
        break;
    }
    case Status::delivered : {
        break;
    }
    }
}

Status Order::get_status(){
    return status;
}

std::string Order::get_status_str(){
    return StrStatus[istatus];
}
