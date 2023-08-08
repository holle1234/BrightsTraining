#if !defined(TAGGED)
#define TAGGED


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

   void set(char value);
   void set(int value);
   void set(float value);

   void get(char& value, bool& status);
   void get(int& value, bool& status);
   void get(float& value, bool& status);

   char type();
   bool is_set();
};



#endif // TAGGED
