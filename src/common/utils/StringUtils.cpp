#include "StringUtils.h"

const std::string& utils::string::mult(
        const std::string& s,
        unsigned int k,
        const std::string& sep
) {
    std::string res;
    for (auto i = 0; i < k - 1; ++i) {
        res += s + sep;
    }
    if (k > 0) {
        res += s;
    }
    return res;
}

const std::string& utils::string::join(
        const std::vector<std::string>& v,
        const std::string& delimeter
) {
    std::string res;
    for (auto i = 0; i < v.size() - 1; ++i) {
        res += v[i] + delimeter;
    }
    if (v.size() > 0) {
        res += v[v.size() - 1];
    }
    return res;
}