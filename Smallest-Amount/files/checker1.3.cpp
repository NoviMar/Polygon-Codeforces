#include "testlib.h"
#include <sstream>
#include <vector>
#include <cmath>
#include <queue>

int main(int argc, char* argv[]) {
    setName("сравнение DFS-обхода бинарного дерева");

    registerTestlibCmd(argc, argv);

    std::vector<double> expected_values;
    std::vector<double> actual_values;

    if (ouf.eof()) {
        quitf(_pe, "Вывод пустой или не может быть прочитан");
    }

    std::string expectedLine;
    try {
        expectedLine = ans.readString();
    } catch (const std::exception& e) {
        quitf(_fail, "Не удалось прочитать ожидаемый ответ: %s", e.what());
    }

    std::istringstream expectedIss(expectedLine);
    double value;
    while (expectedIss >> value) {
        expected_values.push_back(value);
    }

    std::string actualLine;
    try {
        actualLine = ouf.readString(); 
    } catch (const std::exception& e) {
        quitf(_pe, "Не удалось прочитать фактический ответ: %s", e.what());
    }

    std::istringstream actualIss(actualLine);
    while (actualIss >> value) {
        actual_values.push_back(value);
    }

    if (expected_values.size() != actual_values.size()) {
        quitf(_wa, "Ожидаемая длина DFS-обхода %d, фактическая длина %d", expected_values.size(), actual_values.size());
    }

    for (size_t i = 0; i < expected_values.size(); ++i) {
        if (std::abs(expected_values[i] - actual_values[i]) > 1e-9) {
            quitf(_wa, "Ожидаемое значение %lf, фактическое значение %lf", expected_values[i], actual_values[i]);
        }
    }

    quitf(_ok, "DFS-обход верен");
}
