#include "Tasks/IpTask.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream> // Для работы с файлами

int main(int argc, char *argv[])
{
    std::vector<std::string> input;
    std::string line;

    // Если передан аргумент командной строки (путь к файлу), то считываем данные из файла
    if (argc > 1)
    {
        std::ifstream file(argv[1]); // Открытие файла по пути, переданному как аргумент
        if (!file.is_open())
        {
            std::cerr << "Не удалось открыть файл " << argv[1] << "!" << std::endl;
            return 1; // Завершаем программу с кодом ошибки
        }

        // Чтение строк из файла
        while (std::getline(file, line))
        {
            if (!line.empty())
            {
                input.push_back(line);
            }
        }

        // Закрытие файла
        file.close();
    }
    else
    {
        // Если аргумент не передан, считываем данные из стандартного ввода
        std::cout << "Введите IP-адреса (закончите ввод пустой строкой):" << std::endl;
        while (std::getline(std::cin, line))
        {
            if (line.empty())
            {
                break; // Прерывание ввода по пустой строке
            }
            input.push_back(line);
        }
    }

    // Обработка IP-адресов
    auto ips = parseIPs(input);

    // Вывод всех IP-адресов
    for (auto &ip : ips)
        printIP(ip);

    // Фильтрация и вывод IP-адресов
    for (auto &ip : filterByFirst(ips, 1))
        printIP(ip);

    for (auto &ip : filterByFirstSecond(ips, 46, 70))
        printIP(ip);

    for (auto &ip : filterAnyByte(ips, 46))
        printIP(ip);

    std::cout << "============================================================================================";

    // Ожидание нажатия клавиши (только для Windows)
#ifdef _WIN32
    system("pause");
#endif

    return 0;
}
