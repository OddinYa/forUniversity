#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

bool isVowel(char c) {
    
    c = std::tolower(c);

    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    std::vector<std::string> words;

    if (input.is_open() && output.is_open()) {
        std::string line;
        while (std::getline(input, line)) {

            std::istringstream iss(line);
            std::string word;

            while (iss >> word) {
                // Проверяем, начинается и заканчивается ли слово на гласные буквы
                if (isVowel(word.front()) && isVowel(word.back())) {
                    words.push_back(word);
                }
            }
        }

        // Записываем отфильтрованные слова в файл
        for (const std::string& word : words) {
            output << word << " ";
        }

        input.close();
        output.close();
    }
    else {
        std::cout << "Error.\n";
    }

    return 0;
}