#if !defined(TAGGED)
#define TAGGED

#include <ostream>


enum class TaggedAccess{
   robot,
   person,
   alien,
   not_set
};



struct TaggedResult
{
   std::string value;
   bool status;
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

   bool set(std::string_view value);
   TaggedResult get() const;
   bool is_set();
   char type();

   friend std::ostream& operator<<(std::ostream& os, const Data& d);
   friend bool is_float(std::string_view input);
   friend bool is_int(std::string_view input);
};



#endif // TAGGED
