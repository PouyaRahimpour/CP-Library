
#pragma once

#include <bits/stdc++.h>

namespace debug_util {

    inline constexpr std::string_view white = "\033[0m";
    inline constexpr std::string_view red   = "\033[0;31m";
    inline constexpr std::string_view blue  = "\033[0;34m";
    inline constexpr std::string_view green = "\033[0;32m";

    template <typename T>
    concept is_iterable =
        requires(T&& x) { std::begin(x); } &&
        !std::same_as<std::remove_cvref_t<T>, std::string> &&
        !std::same_as<std::remove_cvref_t<T>, std::string_view>;

    inline void print(const char* x) {
        std::cerr << x;
    }

    inline void print(char x) {
        std::cerr << '\'' << x << '\'';
    }

    inline void print(bool x) {
        std::cerr << (x ? "T" : "F");
    }

    inline void print(const std::string& x) {
        std::cerr << '"' << x << '"';
    }

    inline void print(const std::string_view& x) {
        std::cerr << '"' << x << '"';
    }

    inline void print(const std::vector<bool>& v) {
        int f = 0;
        std::cerr << "{";
        for (bool x : v) {
            std::cerr << (f++ ? "," : "") << (x ? "T" : "F");
        }
        std::cerr << "}";
    }

    template <typename T>
    void print(T&& x) {
        using U = std::remove_cvref_t<T>;

        if constexpr (is_iterable<T>) {
            if (std::size(x) &&
                is_iterable<decltype(*std::begin(x))>) {
                int f = 0;
                int w = std::max(
                    0, static_cast<int>(
                           std::log10(std::size(x) - 1)
                       )
                ) + 2;

                std::cerr << "\n~~~~~\n";
                for (auto&& i : x) {
                    std::cerr << std::setw(w) << std::left << f++;
                    print(i);
                    std::cerr << '\n';
                }
                std::cerr << "~~~~~\n";
            } else {
                int f = 0;
                std::cerr << "{";
                for (auto&& i : x) {
                    std::cerr << (f++ ? "," : "");
                    print(i);
                }
                std::cerr << "}";
            }
        } else if constexpr (requires(U y) { y.pop(); }) {
            auto temp = x;
            int f = 0;
            std::cerr << "{";

            if constexpr (requires(U y) { y.top(); }) {
                while (!temp.empty()) {
                    std::cerr << (f++ ? "," : "");
                    print(temp.top());
                    temp.pop();
                }
            } else {
                while (!temp.empty()) {
                    std::cerr << (f++ ? "," : "");
                    print(temp.front());
                    temp.pop();
                }
            }

            std::cerr << "}";
        } else if constexpr (requires { x.first; x.second; }) {
            std::cerr << "(";
            print(x.first);
            std::cerr << ",";
            print(x.second);
            std::cerr << ")";
        } else if constexpr (requires { std::get<0>(x); }) {
            int f = 0;
            std::cerr << "(";
            std::apply([&](auto&&... args) {
                ((std::cerr << (f++ ? "," : ""), print(args)), ...);
            }, x);
            std::cerr << ")";
        } else {
            std::cerr << x;
        }
    }

    template <typename T, typename... V>
    void printer(const char* names, T&& head, V&&... tail) {
        int i = 0;
        int bracket = 0;

        for (; names[i] != '\0' &&
               (names[i] != ',' || bracket != 0); ++i) {
            if (names[i] == '(' || names[i] == '<' ||
                names[i] == '{' || names[i] == '[') {
                ++bracket;
            } else if (names[i] == ')' || names[i] == '>' ||
                       names[i] == '}' || names[i] == ']') {
                --bracket;
            }
        }

        std::cerr << blue;
        std::cerr.write(names, i);
        std::cerr << red << " = " << green;
        print(std::forward<T>(head));

        if constexpr (sizeof...(tail) > 0) {
            std::cerr << red << " || ";
            printer(names + i + 1, std::forward<V>(tail)...);
        } else {
            std::cerr << red << "]\n" << white;
        }
    }

} // namespace debug_util

