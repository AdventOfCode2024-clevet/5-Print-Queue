#include <iostream>

#include "ArgumentParser.hpp"
#include "FileReader.hpp"
#include "UpdateCounter.hpp"

int main(int argc, char* argv[]) {
    try {
        PrintQueue::ArgumentParser parser(argc, argv);

        PrintQueue::FileReader reader(parser.getInputFile());
        auto rules = reader.readRules();
        auto updates = reader.readUpdates();

        int result = 0;
        switch (parser.getPart())
        {
            case 1:
                result = PrintQueue::UpdateCounter::countUpdatesPartOne(rules, updates);
                std::cout << "Result (part 1): " << result << std::endl;
                break;
            case 2:
                result = PrintQueue::UpdateCounter::countUpdatesPartTwo(rules, updates);
                std::cout << "Result (part 2): " << result << std::endl;
                break;
            default:
                throw std::runtime_error("Error: part must be 1 or 2");
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}
