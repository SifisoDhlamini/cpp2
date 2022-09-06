#include<iostream>
#include <fmt/format.h>
#include<ranges>
#include<string_view>


int main()
{
    std::string_view str = "Hello, World!";
    auto words = str | std::views::split(' ');
    for (auto word : words)
    {
        std::cout << word << std::endl;
    }
    return 0;
}