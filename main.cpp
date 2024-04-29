#include <iostream>
#include <string>
#include <vector>
#include <random>

namespace tmp
{
    std::vector<std::string> loremIpsum = {
        "Lorem", "ipsum", "dolor", "sit", "amet,", "consectetur", "adipisicing", "elit,",
        "sed", "do", "eiusmod", "tempor", "incididunt", "ut", "labore", "et", "dolore", "magna",
        "aliqua.", "Ut", "enim", "ad", "minim", "veniam,", "quis", "nostrud", "exercitation",
        "ullamco", "laboris", "nisi", "ut", "aliquip", "ex", "ea", "commodo", "consequat.",
        "Duis", "aute", "irure", "dolor", "in", "reprehenderit", "in", "voluptate", "velit",
        "esse", "cillum", "dolore", "eu", "fugiat", "nulla", "pariatur.", "Excepteur", "sint",
        "occaecat", "cupidatat", "non", "proident,", "sunt", "in", "culpa", "qui", "officia",
        "deserunt", "mollit", "anim", "id", "est", "laborum."};
} // namespace tmp

class LoremIpsumGenerator
{
private:
    std::random_device rd;
    std::mt19937 gen;

public:
    LoremIpsumGenerator() : gen(rd()) {}

    auto generate(int numWords, bool startWithLoremIpsum = false) -> std::string
    {
        std::string loremText{};
        std::uniform_int_distribution<> dis(0, tmp::loremIpsum.size() - 1);

        if (startWithLoremIpsum)
        {
            loremText += "Lorem ipsum dolor sit amet ";
            numWords -= 4;
        }

        for (int i = 0; i < numWords; ++i)
        {
            int index = dis(gen);
            loremText += tmp::loremIpsum[index] + " ";
        }

        return loremText;
    }
};

auto main() -> int
{
    LoremIpsumGenerator generator;

    std::cout << "Enter the number of words of Lorem Ipsum text to generate: ";
    int numOfWords{0};
    std::cin >> numOfWords;

    std::cout << "Do you want to start your text with 'Lorem ipsum dolor sit amet...'? (1 - Yes, 0 - No):";
    bool startWithLoremIpsum{false};
    std::cin >> startWithLoremIpsum;

    std::string lorem = generator.generate(numOfWords, startWithLoremIpsum);
    std::cout << "\nGenerated Lorem Ipsum text:\n"
              << lorem << std::endl;

    return 0;
}
