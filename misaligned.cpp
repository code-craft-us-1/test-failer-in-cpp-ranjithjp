#include <assert.h>
#include <iostream>
#include <string>
#include <vector>


const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
int noOfMajorColor = sizeof(majorColor) / sizeof(majorColor[0]);
const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
int noOfMinorColor = sizeof(majorColor) / sizeof(minorColor[0]);


std::vector<std::string> tokenize(const std::string& str, const std::string& token) {
    size_t start = str.find_first_not_of(token), end = start;
    std::vector<std::string> token_v;
    while (start != std::string::npos) {
        // Find next occurence of delimiter
        end = str.find(token, start);
        // Push back the token found into vector
        token_v.push_back(str.substr(start, end - start));
        // Skip all occurences of the delimiter to find new start
        start = str.find_first_not_of(token, end);
    }
    return token_v;
}

std::string BuildColorMap() {
    std::string colorMap;
    int i = 0, j = 0;
    for (i = 0; i < noOfMajorColor; i++) {
        for (j = 0; j < noOfMinorColor; j++) {
            colorMap.append(std::to_string(i * 5 + j) +
                " | " + majorColor[i] + " | " + minorColor[i] + "\n");
        }
    }
    return colorMap;
}

void TestColorMapEntryCount() {
    std::string colorMap = BuildColorMap();
    std::vector<std::string> eachLineColormap = tokenize(colorMap, "\n");
    assert(eachLineColormap.size() == 25);
}

void TestColorByIndex(int majorIndex, int minorIndex) {
    std::string colorMap = BuildColorMap();
    std::vector<std::string> eachLineColormap = tokenize(colorMap, "\n");
    int index = majorIndex * 5 + minorIndex;
    assert(eachLineColormap[index].find(std::to_string(index)) != std::string::npos);
    assert(eachLineColormap[index].find(majorColor[majorIndex]) != std::string::npos);
    assert(eachLineColormap[index].find(minorColor[minorIndex]) != std::string::npos);
}

void printColorMap() {
    std::string colorMap = BuildColorMap();
    std::cout << colorMap;
}


int main() {
    printColorMap();
    TestColorMapEntryCount();
    TestColorByIndex(0, 0);
    TestColorByIndex(1, 1);
    TestColorByIndex(1, 0);
    TestColorByIndex(0, 1);
    std::cout << "All is well\n";
    return 0;
}
