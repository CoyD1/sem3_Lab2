
#include "Tasks/IpTask.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> input;
    std::string line;
    while (std::getline(std::cin, line))
    {
        if (!line.empty())
            input.push_back(line);
    }

    auto ips = parseIPs(input);

    for (auto &ip : ips)
        printIP(ip);
    for (auto &ip : filterByFirst(ips, 1))
        printIP(ip);
    for (auto &ip : filterByFirstSecond(ips, 46, 70))
        printIP(ip);
    for (auto &ip : filterAnyByte(ips, 46))
        printIP(ip);

    std::cout << "============================================================================================";
#ifdef _WIN32
    system("pause");
#endif
}
