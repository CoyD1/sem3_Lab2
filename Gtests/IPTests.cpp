#include <gtest/gtest.h>
#include "../Tasks/IpTask.h"

TEST(IPTask, ParseAndSort)
{
    std::vector<std::string> input = {"192.168.1.1\tabc\txyz", "10.0.0.1\tdaun\thz", "172.16.0.1\tIvan\tObuhov"};
    auto res = parseIPs(input);
    EXPECT_EQ(res[0], std::make_tuple(192, 168, 1, 1));
    EXPECT_EQ(res[2], std::make_tuple(10, 0, 0, 1));
}

TEST(IPTask, FilterByFirst)
{
    std::vector<std::tuple<int, int, int, int>> ips = {{1, 1, 1, 1}, {2, 0, 0, 1}, {1, 2, 3, 4}};
    auto res = filterByFirst(ips, 1);
    EXPECT_EQ(res.size(), 2);
}

TEST(IPTask, FilterByFirstSecond)
{
    std::vector<std::tuple<int, int, int, int>> ips = {{46, 70, 1, 1}, {46, 1, 2, 3}, {1, 46, 2, 3}};
    auto res = filterByFirstSecond(ips, 46, 70);
    EXPECT_EQ(res.size(), 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    std::cin.ignore();
    return 0;
}