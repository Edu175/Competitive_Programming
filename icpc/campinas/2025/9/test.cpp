#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

template <typename T, typename = void>
struct is_container : std::false_type {};

template <typename T>
struct is_container<T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type {};

template <typename T>
void process(const T& x) {
    if constexpr (is_container<T>::value) {
        std::cout << "This is a container.\n";
		for(auto i:x)process(i);
    } else {
        std::cout << "This is NOT a container.\n";
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3};
    int x = 42;
	set<vector<int>>st={{1}};
    process(st); // This is a container.
    process(vec); // This is a container.
    process(x);   // This is NOT a container.

    return 0;
}
