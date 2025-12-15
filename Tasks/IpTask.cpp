#include "IpTask.h"
#include <iostream>
#include <algorithm>

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);

    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));
    return r;
}

std::vector<std::tuple<int, int, int, int>> parseIPs(const std::vector<std::string> &input)
{
    std::vector<std::tuple<int, int, int, int>> ip_pool;
    for (auto &line : input)
    {
        auto parts = split(line, '\t');
        auto ip_str = parts[0];
        auto nums = split(ip_str, '.');
        ip_pool.emplace_back(std::stoi(nums[0]), std::stoi(nums[1]), std::stoi(nums[2]), std::stoi(nums[3]));
    }
    std::sort(ip_pool.begin(), ip_pool.end(),
              [](const auto &a, const auto &b)
              {
                  if (std::get<0>(a) != std::get<0>(b))
                      return std::get<0>(a) > std::get<0>(b);
                  if (std::get<1>(a) != std::get<1>(b))
                      return std::get<1>(a) > std::get<1>(b);
                  if (std::get<2>(a) != std::get<2>(b))
                      return std::get<2>(a) > std::get<2>(b);
                  if (std::get<3>(a) != std::get<3>(b))
                      return std::get<3>(a) > std::get<3>(b);
              });

    return ip_pool;
}

void printIP(const std::tuple<int, int, int, int> &ip)
{
    std::cout << std::get<0>(ip) << "." << std::get<1>(ip) << "." << std::get<2>(ip) << "." << std::get<3>(ip) << "\n";
}

std::vector<std::tuple<int, int, int, int>> filterByFirst(const std::vector<std::tuple<int, int, int, int>> &ips, int byte1)
{
    std::vector<std::tuple<int, int, int, int>> res;
    for (const auto &ip : ips)
    {
        if (std::get<0>(ip) == byte1)
            res.push_back(ip);
    }
    return res;
}

std::vector<std::tuple<int, int, int, int>> filterByFirstSecond(const std::vector<std::tuple<int, int, int, int>> &ips, int byte1, int byte2)
{
    std::vector<std::tuple<int, int, int, int>> res;
    for (const auto &ip : ips)
    {
        if (std::get<0>(ip) == byte1 && std::get<1>(ip) == byte2)
            res.push_back(ip);
    }
    return res;
}

std::vector<std::tuple<int, int, int, int>> filterAnyByte(const std::vector<std::tuple<int, int, int, int>> &ips, int byte)
{
    std::vector<std::tuple<int, int, int, int>> res;
    for (const auto &ip : ips)
    {
        if (std::get<0>(ip) == byte || std::get<1>(ip) == byte || std::get<2>(ip) == byte || std::get<3>(ip) == byte)
            res.push_back(ip);
    }
    return res;
}