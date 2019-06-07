#include <vector>
#include <string>
#include <sstream>

template<typename T>
std::string vec2str(const std::vector<T>& vec, std::string delim = " ") {
    std::ostringstream ss;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i == 0) {
            ss << vec[i];
        } else {
            ss << delim << vec[i];
        }
    }
    return ss.str();
}
