#pragma once
#include <string>
#include <vector>

std::vector<std::tuple<int, int, int, int>> parseIPs(const std::vector<std::string> &input);
void printIP(const std::tuple<int, int, int, int> &ip);
std::vector<std::tuple<int, int, int, int>> filterByFirst(const std::vector<std::tuple<int, int, int, int>> &ips, int byte1);
std::vector<std::tuple<int, int, int, int>> filterByFirstSecond(const std::vector<std::tuple<int, int, int, int>> &ips, int byte1, int byte2);
std::vector<std::tuple<int, int, int, int>> filterAnyByte(const std::vector<std::tuple<int, int, int, int>> &ips, int byte);