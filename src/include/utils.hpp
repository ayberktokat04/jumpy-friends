#ifndef __UTILS_HPP__
#define __UTILS_HPP__

template <typename T>
bool isbetween(T value, T min, T max) {
    return min < value && value <= max;
}

#endif