#if !defined(ITERATORS)
#define ITERATORS

#include <string>


constexpr unsigned char kFirstBitMask   = 128; // 1000000


std::string::difference_type utf8_offset(const char first_byte){

    std::string::difference_type offset = 1;

    if(first_byte & kFirstBitMask){
        if(first_byte & (kFirstBitMask >> 2)){
            if(first_byte & (kFirstBitMask >> 3)) 
                offset = 4;
            else offset = 3;
        }
        else offset = 2;
    }
    return offset;

}


class MyIterator
{

public:

    using iterator_category = std::forward_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = std::string::value_type;
    using pointer           = std::string::const_iterator; 
    using reference         = char32_t;

    MyIterator(pointer ptr) : iter_ptr(ptr) {}

    pointer operator->() {return iter_ptr; }

    bool operator== (const MyIterator& b) {
        return iter_ptr == b.iter_ptr; 
    }
    bool operator!= (const MyIterator& b) {
        return iter_ptr != b.iter_ptr;
    }
    bool operator== (const std::string::iterator& b) {
        return iter_ptr == b; 
    }
    bool operator!= (const std::string::iterator& b) {
        return iter_ptr != b;
    }

    // Prefix increment
    MyIterator& operator++() {
        difference_type i = utf8_offset(*iter_ptr);
        iter_ptr += i;
        return *this; }  

    // Prefix decrement
    MyIterator& operator--(){
        --iter_ptr;
        if(*iter_ptr & kFirstBitMask){
            for (size_t i = 0; i < 2; i++){
                if((*iter_ptr & (kFirstBitMask >> 1)) == 1){
                    break;
                }
                --iter_ptr;
            }
        }
        return *this;
    }

    char32_t operator*() const {

        char firstByte = *iter_ptr;
        // get the size of the unicode (ascii,2,3,4)
        size_t offset = utf8_offset(firstByte) - 1;

        // only ascii byte
        if (offset == 0){
            return firstByte;
        }

        // unicode bytes (1-3)
        char32_t codePoint = 0;
        int shift = 0;
        for (auto i = offset; i >= 1; i--){
            codePoint += (*(iter_ptr + i) & 63) << shift;
            shift += 6;
        }

        // first byte in unicode
        codePoint += (firstByte & ((64 >> offset) - 1)) << shift;

        return codePoint;
    }

private:
    pointer iter_ptr;
};



#endif // ITERATORS
