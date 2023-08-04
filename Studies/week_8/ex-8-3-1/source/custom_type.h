#if !defined(CUSTOM_TYPE)
#define CUSTOM_TYPE

#include <type_traits>
#include <vector>
#include <ostream>
#include <tuple>
#include <algorithm>
#include <iostream>
#include <iterator>


template<size_t S, typename T>
class MyContainer

{
public:
    using value_type = T;
    using reference	= T&;
    using const_reference = const T&;
    using iterator = T*;
    using const_iterator = const T*;
    using difference_type = std::ptrdiff_t;
    using size_type = size_t;
    const T initial_value {};

    template<size_t SF, typename TF>
    friend std::ostream &operator<<(std::ostream &os, const MyContainer<SF, TF> &cont);

private:
    T* data = new T [S];
    T* _end = data + S;
    
public:
    
    MyContainer(){
        for (size_t it = 0; it < S; it++){
            data[it] = initial_value;
        }
    }

    MyContainer(T initial_value) : initial_value(initial_value) {
        for (size_t it = 0; it < S; it++){
            data[it] = initial_value;
        }
    }
    ~MyContainer(){
        delete[] data;
        data = nullptr;
        _end = nullptr;
    }

    // copy constructor
    MyContainer(const MyContainer& rhs) : initial_value(rhs.initial_value) {
        for (size_t i = 0; i < rhs.size(); i++){
            data[i] = rhs.data[i];
        }
    }

    // move constructor
    MyContainer(MyContainer&& rhs) noexcept {
        delete[] data;

        data = std::exchange(rhs.data, nullptr);
        _end = std::exchange(rhs._end, nullptr);
    }

    // copy-assignment
    MyContainer& operator=(const MyContainer& rhs){
        for (size_t i = 0; i < rhs.size(); i++){
            data[i] = rhs.data[i];
        }
        return *this;
    }

    // move-assignment
    MyContainer& operator=(MyContainer&& rhs) noexcept {
        delete[] data;
        data = std::exchange(rhs.data, nullptr);
        _end = std::exchange(rhs._end, nullptr);
        return *this;
    }

    bool operator==(const MyContainer& b){
        return std::equal(begin(), end(), b.begin(), b.end());
    }

    bool operator!=(const MyContainer& b){
        return !(*this == b);
    }

    void swap(MyContainer& other){
        std::swap(data, other.data);
        std::swap(_end, other._end);
        std::swap(const_cast<T&>(initial_value), const_cast<T&>(other.initial_value));
    }

    T& operator[](unsigned int index){
        return data[index];
    }

    iterator begin(){
        return data;
    }

    iterator end(){
        return _end;
    }

    const_iterator begin() const{
        return data;
    }

    const_iterator end() const{
        return _end;
    }

    size_t size() const{
        return std::distance(begin(), end());
    }

    bool empty(){
        return begin() == end();
    }

    size_t max_size(){
        return sizeof(size_t);
    }

};

template<size_t SF, typename TF>
std::ostream &operator<<(std::ostream &os, const MyContainer<SF, TF> &cont)
{
    for (auto it = cont.begin(); it != cont.end(); it++){
        os << *it << " ";
    }

    return os << '\n';
}



#endif // CUSTOM_TYPE