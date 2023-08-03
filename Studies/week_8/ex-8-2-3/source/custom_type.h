#if !defined(CUSTOM_TYPE)
#define CUSTOM_TYPE

#include <type_traits>
#include <vector>
#include <ostream>
#include <tuple>
#include <algorithm>
#include <iostream>


template<typename T>
class Point2D
{
private:
    unsigned int _x {0};
    unsigned int _y {0};
    T _value;
public:

    Point2D(unsigned int y, unsigned int x, T value) : _x(x), _y(y), _value(value) {}
    Point2D() = default;
    ~Point2D() {}

    template<typename U>
    friend std::ostream &operator<<(std::ostream &os, const Point2D<U> &cont);

    bool operator==(Point2D<T>& another){
        return _x == another.x() && _y == another.y();
    }

    unsigned int x() const {
        return _x;
    }

    unsigned int y() const {
        return _y;
    }

    T value() const {
        return _value;
    }

    Point2D<T>& operator=(const T value){
        this->_value = value;
        return *this;
    }

    Point2D<T>& operator=(const Point2D<T>& other){
        this->_value = other.value();
        this->_x = other.x();
        this->_y = other.y();
        return *this;
    }
};


class GridSize
{
protected:
    unsigned int  w, h;
public:
    GridSize(unsigned int width, unsigned int height) : w(width), h(height) {}
    ~GridSize() {}
    
    // move constructor
    GridSize(GridSize&& rhs) = default;

    // move-assignment
    GridSize& operator=(GridSize&& rhs) = default;
};


template<typename T>
class MyContainer : public GridSize

{
public:
    using storage_type = std::vector<Point2D<T>>;
    using value_type = Point2D<T>;
    using reference	= Point2D<T>&;
    using const_reference = const Point2D<T>&;	
    using iterator = typename storage_type::iterator;
    using const_iterator = typename storage_type::const_iterator;
    using difference_type = typename storage_type::difference_type;
    using size_type = typename storage_type::size_type;
    T initial_value;

    template<typename U>
    friend std::ostream &operator<<(std::ostream &os, const MyContainer<U> &cont);

private:
    storage_type data;
public:

    MyContainer& operator=(MyContainer&& rhs) noexcept {
        data = std::move(rhs.data);
        initial_value = std::move(rhs.initial_value);
        return *this;
    }

    MyContainer(MyContainer&& rhs) noexcept
        : data(std::move(rhs.data)),
          initial_value(std::move(rhs.initial_value)),
          GridSize(std::move(rhs)) {
    }

    MyContainer& operator=(const MyContainer& rhs){
        data = rhs.data;
        initial_value = rhs.initial_value;
        return *this;
    }

    MyContainer(unsigned int width, unsigned int height, T init_value) : GridSize(width, height) {
        initial_value = init_value;
        data.resize(width * height);
        for (unsigned int row = 0; row < height; row++){
            for (unsigned int col = 0; col < width; col++){
                data[row * width + col] = {row, col, init_value};
            }
        }
    }
    ~MyContainer() {};

    // Find element (not modifiable)
    const Point2D<T>& at(unsigned int y, unsigned int x) const {
        if (x < width() && x >= 0 && y < height() && y >= 0){
            return data[width() * y + x];
        }
        throw std::invalid_argument("coordinate out of range: got " + std::to_string(x) + ":" + std::to_string(y));
    }

    void update(unsigned int y, unsigned int x, T new_value){
        if (x < width() && x >= 0 && y < height() && y >= 0){
            data[width() * y + x] = new_value;
        }
        else throw std::invalid_argument("coordinate out of range: got " + std::to_string(x) + ":" + std::to_string(y));
    }

    iterator begin(){
        return data.begin();
    }

    iterator end(){
        return data.end();
    }

    const_iterator begin() const{
        return data.begin();
    }

    const_iterator end() const{
        return data.end();
    }

    std::tuple<unsigned int, unsigned int> grid_size(){
        return std::make_tuple(w, h);
    }

    unsigned int width() const {
        return w;
    }

    unsigned int height() const{
        return h;
    }

    // this is inefficient solution but removes the need to
    // manually shift and calculate insertions..
    void resize(unsigned int width, unsigned int height){
        storage_type new_data;
        new_data.resize(width * height);

        for (unsigned int row = 0; row < height; row++){
            for (unsigned int col = 0; col < width; col++){
                auto index = row * width + col;
                if (row < h && col < w){
                    new_data[index] = data[row * w + col];
                }
                else new_data[index] = {row, col, initial_value};
            }
        }
        data = new_data;
        w = width;
        h = height;
    }

    size_t size() const{
        return data.size();
    }

};

template<class T>
std::ostream &operator<<(std::ostream &os, const MyContainer<T> &cont)
{
    for (size_t row = 0; row < cont.height(); row++){
        for (size_t col = 0; col < cont.width(); col++){
            os << cont.at(row, col) << " ";
        }
        os << "\n";
    }
    return os;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const Point2D<T> &point)
{
    return os << point.value();
}


#endif // CUSTOM_TYPE