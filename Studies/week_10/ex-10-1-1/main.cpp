#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <mutex>
#include <atomic>

//static int global_int {0};
//std::mutex global_int_mutex;

static std::atomic<int> global_int {0};
std::mutex global_int_mutex;


void printer(const std::string& msg){
    std::cout << msg << '\n';
}

void adder(int value, int n){
    std::lock_guard<std::mutex> th_lock(global_int_mutex);
    for (size_t i = 0; i < n; i++){
        global_int += value;
    }
}

void ex_1(){
    for (size_t i = 0; i < 3; i++){
        std::thread hello(printer, "hello");
        std::thread world(printer, "world");
        hello.join();
        world.join();
    }
}


int main(int argc, char const *argv[])
{
    // Ex 1.
    ex_1();

    // Ex 2.
    int n_threads = 100;
    int n_iters = 10;
    int value = 1;

    // thread solution begin
    auto th_begin = std::chrono::high_resolution_clock::now();

    std::vector<std::thread> ths;
    for (size_t i = 0; i < n_threads; i++){
        std::thread th(adder, value, n_iters);
        ths.push_back(std::move(th));
    }

    for (auto &&th : ths){
        th.join();
    }

    // thread solution end
    auto th_end = std::chrono::high_resolution_clock::now();

    std::cout << "global value: " << global_int << '\n';
    global_int = 0;

    // straight up calc solution begin
    auto calc_begin = std::chrono::high_resolution_clock::now();

    // calculation only
    global_int += (n_threads * n_iters * value);

    // straight up calc solution end
    auto calc_end = std::chrono::high_resolution_clock::now();

    std::cout << "global value: " << global_int << '\n';

    auto th_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(th_end - th_begin);
    auto calc_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(calc_end - calc_begin);

    std::cout << "threads took: " << th_elapsed.count() << '\n';
    std::cout << "calc took: " << th_elapsed.count() << '\n';

    // there is no difference in using threads vs straight calculation.
    // threads can access the value one by one, so there are no benefits in it.

    return 0;
}
