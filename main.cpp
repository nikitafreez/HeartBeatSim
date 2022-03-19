#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>

int RandomNumber(int, int);

float RandomNumberFloat(float, float);

void GenerateNumListInFile();

std::vector<int> intVector;

void ReadFromFile();

std::string filePath = "D:\\Random.txt";

int peakNum = 1000; //Количество ударов сердца
int sumOfAll = 0;
int main() {
    unsigned int start_time = clock();

    GenerateNumListInFile();

    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    std::cout << "Время: " << search_time / 1000.0 << " секунд" << std::endl;
    ReadFromFile();

    std::vector<int> maxElements;
    std::vector<int> maxElementsIndex;
    int j = 0;
    for (int i = 0; i < intVector.size(); i++) {

        if (intVector[i] > 90 && intVector[i] > intVector[i - 1] && intVector[i] > intVector[i + 1]) {
            maxElements.push_back(intVector[i]);
            maxElementsIndex.push_back(i);
        }
    }


    for (int i = 0; i < maxElements.size(); i++) {
        std::cout << "Пик №" << i + 1 << "\t Значение: " << maxElements[i] << std::endl;
        std::cout << "Индекс пика №" << i + 1 << ": " << maxElementsIndex[i] + 1 << std::endl;
    }
//        std::cout << "Макс элемент: " << maxListElement << std::endl;
//        std::cout << "Его индекс: " << maxIndex + 1 << std::endl;
//
//        std::cout << "Макс элемент 2: " << maxListElement2 << std::endl;
//        std::cout << "Его индекс 2: " << maxIndex2 + 1 << std::endl;

    std::cout << "Потеряно пиков: " << peakNum - maxElements.size() << std::endl;
    std::cout << "Линия, выше которой находятся пики: " << (sumOfAll / intVector.size()) * 0.80 << std::endl;
    return 0;
}

void ReadFromFile() {
    std::string line;
    std::string profile = getenv("USERPROFILE");
    std::ifstream in(filePath);
    if (in.is_open()) {
        while (std::getline(in, line)) {
            intVector.push_back(std::stoi(line));
            sumOfAll += std::stoi(line);
        }
    }
    in.close();
    std::cout << "ENDING" << std::endl;
}

float IncreaseMnozh() {
    float min = 1.13;
    float max = 1.15;
    float increased = RandomNumberFloat(min, max);
    return increased;
}

float DecreaseMnozh() {
    float min = 0.85;
    float max = 0.95;
    float decreased = RandomNumberFloat(min, max);
    return decreased;
}

void GenerateNumListInFile() {
    std::string profile = getenv("USERPROFILE");
    std::ofstream out;
    srand(time(NULL));
    out.open(filePath);
    int randNum;
    float increaseMnozh;
    float decreaseMnozh;
    if (out.is_open()) {
        for (int i = 0; i < RandomNumber(20, 35); i++) {
            randNum = RandomNumber(1, 20);
            out << randNum << std::endl;
        }
        for (int i = 0; i < peakNum; i++) {
            randNum = RandomNumber(14, 20);
            for (int i = 0; i < RandomNumber(18, 22); i++) {
                increaseMnozh = IncreaseMnozh();
                randNum *= increaseMnozh;
                out << randNum << std::endl;
            }
            for (int i = 0; i < RandomNumber(18, 22); i++) {
                decreaseMnozh = DecreaseMnozh();
                randNum *= decreaseMnozh;
                out << randNum << std::endl;
            }
            for (int i = 0; i < 60; i++) {
                randNum = RandomNumber(1, 20);
                out << randNum << std::endl;
            }
        }
        for (int i = 0; i < RandomNumber(20, 35); i++) {
            randNum = RandomNumber(1, 20);
            out << randNum << std::endl;
        }
    }
    out.close();
}

/// Рандомное число в диапазоне
/// \param min Нижняя граница рандома
/// \param max Верхняя граница рандома
/// \return Рандомное число
int RandomNumber(int min, int max) {
    int num = min + rand() % (max - min + 1);
    return num;
}

/// Рандомное число в диапазоне
/// \param min Нижняя граница рандома
/// \param max Верхняя граница рандома
/// \return Рандомное число
float RandomNumberFloat(float min, float max) {
    int randd = rand();
    float num = min + (randd * (max - min) / RAND_MAX);
    return num;
}