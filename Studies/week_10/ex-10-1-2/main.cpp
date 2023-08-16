#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <mutex>
#include <chrono>


static std::vector<std::string> log;
std::mutex log_mutex;

static bool running {true};
std::mutex running_mutex;


void auto_logger(){
    std::string prefix = "Runtime: ";
    auto begin = std::chrono::high_resolution_clock::now();
    while (running){
        std::this_thread::sleep_for(std::chrono::seconds(5));
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        log.push_back(prefix + std::to_string(elapsed.count()) + " ms");
    }
}

void user_logger(){
    std::string entry;
    while (running)
    {
        std::cout << "Log message: ";
        std::getline(std::cin, entry);

        log.push_back(entry);

        if (entry == "quit")
        {
            running = false;
            return;
        }
        else if(entry == "show"){
            for (auto &&line : log)
            {
                std::cout << "-" << line << '\n';
            }
        }
    }
}




int main(int argc, char const *argv[])
{
    
    std::thread auto_thread(auto_logger);
    std::thread user_thread(user_logger);
    auto_thread.join();
    user_thread.join();

    std::cout << "Both threads have terminated\n";
 
    return 0;
}
