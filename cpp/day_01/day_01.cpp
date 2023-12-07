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
    // String is contiguoues memory of chars, so
    for (const auto& row_string : input)
    {
        //std::cout << "Row: " << row_string;
        for (auto const& ch : row_string)
        {
            if (isdigit(ch))
            {
                //std::cout << " First: " << (ch - '0');
                result += 10 * (ch - '0');
                break;
            }
        }

        for (int string_index = row_string.length() - 1; string_index >= 0; string_index--) // NOLINT(*-narrowing-conversions)
        {
            if (isdigit(row_string[string_index]))
            {
                //std::cout << " Last: " << atoi(&row_string.at(string_index)) << "\n";
                result += atoi(&row_string.at(string_index));
                break;
            }
        }
    }
    return result;
};

uint32_t get_calibarion_b(std::vector<std::string> input)
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

    for(const auto& row_string : input)
    {
        std::string::size_type n;
        std::map<size_t, uint8_t> result_map = {};

        for (auto [key,value] : value_map)
        {
            n = row_string.find(key);
            if(n!=std::string::npos)
            {
                result_map.emplace(n, value);
            }

            n = row_string.rfind(key);
            if(n!=std::string::npos)
            {
                result_map.emplace(n, value);
            }
        }

        for (auto [key,value] : result_map)
        {
            //std::cout << "key: " <<  key  << " value: "<< static_cast<size_t>(value) << "\n";
        }
        //std::cout << "Number: " <<  static_cast<u_int32_t>(result_map.begin()->second)  << static_cast<u_int32_t>(result_map.rbegin()->second) << "\n";
        result += 10*result_map.begin()->second + result_map.rbegin()->second;
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
