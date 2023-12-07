//
// Created by marty on 11/17/23.
//

#include "day_01.h"
#include "../helpers/helpers.h"

#include <iostream>
#include <cctype>
#include <map>


uint32_t get_calibarion_a(const std::vector<std::string>& input)
{
    uint32_t result{0};


    for (const auto& row_string : input)
    {
        for (auto const& ch : row_string)
        {
            if (isdigit(ch))
            {
                result += 10 * (ch - '0');
                break;
            }
        }


        for( auto rit = std::rbegin(row_string); rit != std::rend(row_string); ++rit )
        {
            if (isdigit(*rit))
            {
                result += (*rit - '0');
                break;
            }
        }
    }
    return result;
};

uint32_t get_calibarion_b(const std::vector<std::string>& input)
{
    uint32_t result{0};

    std::map<std::string, uint8_t> value_map = {
        {"1", 1},
        {"2", 2},
        {"3", 3},
        {"4", 4},
        {"5", 5},
        {"6", 6},
        {"7", 7},
        {"8", 8},
        {"9", 9},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };

    for (const auto& row_string : input)
    {
        std::string::size_type n;
        std::map<size_t, uint8_t> result_map = {};

        for (auto [key,value] : value_map)
        {
            n = row_string.find(key);
            if (n != std::string::npos)
            {
                result_map.emplace(n, value);
            }

            n = row_string.rfind(key);
            if (n != std::string::npos)
            {
                result_map.emplace(n, value);
            }
        }
        result += 10 * result_map.begin()->second + result_map.rbegin()->second;
    }
    return result;
};

auto main() -> int
{
    const auto input = AdventHelper::get_input_vector("/home/marty/Documents/aoc_2023/cpp/day_01/day_01.txt");

    std::cout << "Calibration Result (A)= " << get_calibarion_a(input) << "\n";
    std::cout << "Calibration Result (B)= " << get_calibarion_b(input) << "\n";

    return 0;
}
