#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <regex>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input>" << std::endl;
        return (1);
    }

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Error: could not open file " << argv[1] << std::endl;
        return (1);
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(input, line)) {
        lines.push_back(line);
    }

    int index = 0;
    const std::regex pair_regex("([0-9]+)\\|([0-9]+)");
    std::smatch match;
    std::vector<std::pair<int, int>> rules;

    for (index = 0; index < lines.size(); index++) {
        if (lines[index].empty()) {
            break;
        }

        if (std::regex_match(lines[index], match, pair_regex)) {
            rules.push_back(std::make_pair(std::stoi(match[1]), std::stoi(match[2])));
        }
    }

    index++;

    std::vector<std::vector<int>> updates;
    // Regex that finds a list of integers separated by commas
    const std::regex list_regex("([0-9]+,?)+");
    for (; index < lines.size(); index++) {
        if (lines[index].empty()) {
            break;
        }

        if (std::regex_match(lines[index], match, list_regex)) {
            std::vector<int> update;
            std::string list = match[0];
            size_t start = 0;
            size_t end = list.find(',');
            while (end != std::string::npos) {
                update.push_back(std::stoi(list.substr(start, end - start)));
                start = end + 1;
                end = list.find(',', start);
            }
            update.push_back(std::stoi(list.substr(start, end)));
            updates.push_back(update);
        }
    }

    std::vector<std::pair<bool, std::vector<int>>> update_states;
    // Cycle through the numbers in the update vector
    // At each number, we need to check that the future numbers in the vector are not X related to the number

    for (const auto &update : updates)
    {
        bool valid = true;
        for (int i = 0; i < update.size(); i++)
        {
            for (int j = i + 1; j < update.size(); j++)
            {
                for (const auto &rule : rules)
                {
                    if (rule.first == update[j] && rule.second == update[i])
                    {
                        valid = false;
                        break;
                    }
                }
            }
        }
        update_states.push_back(std::make_pair(valid, update));
    }

    // Debug
    // Cycle through the update states and print the valid state and the vector
    for (const auto &update_state : update_states)
    {
        std::cout << "Valid: " << update_state.first << " ";
        for (const auto &update : update_state.second)
        {
            std::cout << update << " ";
        }
        std::cout << std::endl;
    }

    // We now make a new array with only the valid states
    std::vector<std::vector<int>> valid_updates;
    for (const auto &update_state : update_states)
    {
        if (update_state.first)
        {
            valid_updates.push_back(update_state.second);
        }
    }

    int result = 0;
    // We need to add the middle number of each valid update to the result
    for (const auto &valid_update : valid_updates)
    {
        int middle = valid_update[valid_update.size() / 2];
        result += middle;
    }

    std::cout << "Result: " << result << std::endl;

    return (0);
}
