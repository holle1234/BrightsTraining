#if !defined(VECTOR)
#define VECTOR

#include <ostream>


namespace vector3D
{
    class Vector
    {
    private:
        Vector(unsigned int x, unsigned int y, unsigned int z);
        unsigned int _x {0};
        unsigned int _y {0};
        unsigned int _z {0};
    public:
        ~Vector() {}

        static Vector create(unsigned int x, unsigned int y, unsigned int z){
            return Vector{x, y ,z};
        }

        friend std::ostream& operator<<(std::ostream& os, const Vector& v);

        // declare and define these 
        Vector operator+(const Vector& another) const;
        Vector operator-(const Vector& another) const;
        Vector& operator+=(const Vector& another);
        Vector& operator-=(const Vector& another);

    };

    // prototype for ostream<<
    std::ostream& operator<<(std::ostream& os, const Vector& v);

} // namespace vector3D


#endif // VECTOR
