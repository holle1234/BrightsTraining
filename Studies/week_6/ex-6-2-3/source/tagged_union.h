#if !defined(TAGGED)
#define TAGGED

#include <string>


enum class TaggedAccess{
   robot,
   person,
   alien,
   not_set
};



struct Data{

private:
   
   TaggedAccess last {TaggedAccess::not_set};

   union{
      int robot;
      char person;
      float alien;
   };

   char TaggedAccess_to_char(TaggedAccess t);

public:

   // getters
   char get(char value);
   int get(int value);
   float get(float value);

   char type();

   // constructors
   explicit Data(int);
   Data(char);
   Data(float);
   Data(double);
   Data(std::string);
};


#endif // TAGGED
