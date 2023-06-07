#include <iostream>
#include <string>
#include <vector>
#include <cmath>


struct MyTime{

    int hour {0};
    int minute {0};
    int second {0};

    private:
        // timestamp in seconds
        int getTimeStamp(){
            int timeStamp {(hour * 3600) + (minute * 60) + second};
            return timeStamp;
        }

    public:
        // Convert MyTime to int holding seconds passed from 00:00:00
        // Calculate difference and convert it back to 00:00:00

        std::string getTimeDelta(MyTime t2){
            int timeStampT1 {getTimeStamp()};
            int timeStampT2 {t2.getTimeStamp()};
            int timeDelta {std::abs(timeStampT1 - timeStampT2)};

            int ds = timeDelta % (24 * 3600);
            int dh = std::floor(double(ds) / 3600);
            ds %= 3600;
            
            int dm = std::floor(double(ds) / 60);
            ds %= 60;

            std::string stringTimeDelta {""};
            stringTimeDelta += (std::to_string(dh) + " h ");
            stringTimeDelta += (std::to_string(dm) + " min ");
            stringTimeDelta += (std::to_string(ds) + " s ");

            return stringTimeDelta;
        
    }
};


int main(){

    std::vector<MyTime> MytimeVec;
        
    std::cout << "This program calculates abs time-diff" << "\n";
    for (size_t t = 0; t < 2; t++){
        std::cout << "\n" << t + 1 << " moment of time:" << "\n";

        MyTime mytime {};
        for (size_t i = 0; i < 3; i++){
            switch (i){
                case 0:
                    std::cout << "Give hour (0-24): ";
                    std::cin >> mytime.hour;
                    break;
                case 1:
                    std::cout << "Give minute (0-59): ";
                    std::cin >> mytime.minute;
                    break;
                case 2:
                    std::cout << "Give second (0-59): ";
                    std::cin >> mytime.second;
                    break;
                default: break;
            }
        }
        MytimeVec.push_back(mytime);
    }
    
    MyTime t1 {MytimeVec[0]};
    MyTime t2 {MytimeVec[1]};

    std::cout << "Time difference is: " << t2.getTimeDelta(t1) << "\n\n";

    return 0;
}

// todo kesken