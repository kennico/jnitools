#pragma once
#include <string>
#include <memory>

namespace knylaw{
namespace util {

    template<typename InputIt1, typename InputIt2, typename Function>
    Function for_each(InputIt1 first1, InputIt1 last1, InputIt2 first2, Function f) {
        for (; first1 != last1; ++first1, ++first2) {
            f(*first1, *first2);
        }
        return f;
    }

    template<typename... Args>
    std::string format_str(const std::string& format, Args... args)
    {
        size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
        std::unique_ptr<char[]> buf(new char[size]);
        snprintf(buf.get(), size, format.c_str(), args ...);
        return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
    }

}
}