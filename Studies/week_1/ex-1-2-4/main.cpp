#include <iostream>
#include <string>
#include <array>


struct MyTime{

    int hour {0};
    int minute {0};
    int second {0};

    private:
        std::string timeDifference(int t1, int t2){
            return std::to_string(t1 - t2);
        }

    public:
        std::string getTimeDelta(MyTime t2){
            std::string _delta[3] {};
    
            _delta[0] = timeDifference(hour, t2.hour);
            _delta[1] = timeDifference(minute, t2.minute);
            _delta[2] = timeDifference(second, t2.second);

            std::string timeDelta {""};
            for (int i = 0; i < 3; i++){
                std::string s = _delta[i];

                if (s.length() < 2){
                    s = s.insert(0, "0");
                }

                if (i < 2){s += ":";}
                timeDelta += s;

            }

            return timeDelta;
            
        }
};


int main(){

    MyTime t1 {14, 0, 4};
    MyTime t2 {15, 50, 0};

    std::cout << t2.getTimeDelta(t1);

    return 0;
}

// todo kesken