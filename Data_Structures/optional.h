#ifndef OPTIONAL_H
#define OPTIONAL_H

#include <stdexcept>  

template <typename T>
class Optional {
private:
    bool valid; 
    T value; 

public:
    // Default constructor: invalid optional
    Optional() : valid(false), value(T()) {}  // Initialize with default value using T()

    // Constructor with a value
    Optional(const T& val) : valid(true), value(val) {}

    // Check if it's valid (has value)
    bool isValid() const {
        return valid;
    }

    // Get the value if valid, else throw an error
    T get() const {
        if (!valid) {
            throw std::runtime_error("Tried to get value but it's not valid!");
        }
        return value;
    }
};

#endif // OPTIONAL_H
