#include <iostream>
#include <string>
#include <vector>


std::vector<int> kmp(const std::string &s) {
    size_t n = s.size();
    std::vector<int> p(n);

    for (size_t i = 1; i < n; i++) {
        size_t j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    return p;///
}

int main() {

    std::string s;
    std::cin >> s;

    std::vector<int> p = kmp(s);

    for (int i : p) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}
