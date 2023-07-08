#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <codecvt>
#include <iomanip>

struct LeaderboardEntry {
    std::wstring name;
    int score1;
    int score2;

    // Конструктор для удобного создания объектов
    LeaderboardEntry(const std::wstring& n, int s1, int s2)
        : name(n), score1(s1), score2(s2) {}
    LeaderboardEntry() {
        name = L"";
        score1 = 0;
        score2 = 0;
    }
};

bool compareEntries(const LeaderboardEntry& entry1, const LeaderboardEntry& entry2) {
    // Сравниваем первое значение int
    if (entry1.score1 > entry2.score1)
        return true;
    else if (entry1.score1 < entry2.score1)
        return false;

    // Если первые значения int равны, сравниваем вторые значения int
    if (entry1.score2 > entry2.score2)
        return true;
    else if (entry1.score2 < entry2.score2)
        return false;

    return false;
}

void saveLeaderboard(const std::vector<LeaderboardEntry>& leaderboard, const std::string& filename) {
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Ошибка открытия файла для записи." << std::endl;
        return;
    }

    std::locale utf8_locale(std::locale(), new std::codecvt_utf8<wchar_t>);
    file.imbue(utf8_locale);

    for (const auto& entry : leaderboard) {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        std::string narrowName = converter.to_bytes(entry.name);

        file << narrowName << ' ' << entry.score1 << ' ' << entry.score2 << '\n';
    }

    file.close();
}

std::vector<LeaderboardEntry> loadLeaderboard(const std::string& filename) {
    std::vector<LeaderboardEntry> leaderboard;
    std::wifstream file(filename);

    if (!file) {
        std::cerr << "Ошибка открытия файла для чтения." << std::endl;
        return leaderboard;
    }

    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8_utf16<wchar_t>));

    std::wstring line;
    while (std::getline(file, line)) {
        std::wstringstream ss(line);
        std::wstring name;
        int score1, score2;
        if (ss >> name >> score1 >> score2) {
            leaderboard.emplace_back(name, score1, score2);
        }
    }

    file.close();
    return leaderboard;
}

void saveLeaderboard2(const std::vector<LeaderboardEntry>& leaderboard, const std::string& filename) {
    std::wofstream file(filename);

    if (!file) {
        std::cerr << "Ошибка открытия файла для записи." << std::endl;
        return;
    }

    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    file << std::left; // Устанавливаем выравнивание по левому краю
    file << std::setw(15) << L"Имя игрока" << std::setw(7) << L"Очки" << std::setw(15) << L"Время игры" << std::endl;

    for (const auto& entry : leaderboard) {
        file << std::setw(15) << entry.name << std::setw(10) << entry.score1 << std::setw(15) << entry.score2 << L'\n';
    }

    file.close();
}