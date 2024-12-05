#include <regex>

#include "Update.hpp"
#include "Rule.hpp"

PrintQueue::Update::Update(const std::string &line) : valid(UNKNOWN)
{
    const std::regex list_regex("([0-9]+,?)+");
    std::smatch match;

    if (std::regex_match(line, match, list_regex))
    {
        std::string list = match[0];
        size_t start = 0;
        size_t end = list.find(',');

        while (end != std::string::npos)
        {
            numbers.push_back(std::stoi(list.substr(start, end - start)));
            start = end + 1;
            end = list.find(',', start);
        }

        numbers.push_back(std::stoi(list.substr(start, end)));
    }
}

bool PrintQueue::Update::isValid(const std::vector<Rule> &rules)
{
    if (valid != UNKNOWN)
    {
        return (valid);
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            for (const auto &rule : rules)
            {
                if (rule.getFirst() == numbers[j] && rule.getSecond() == numbers[i])
                {
                    valid = INVALID;
                    return (false);
                }
            }
        }
    }

    valid = VALID;
    return (true);
}

int PrintQueue::Update::getMiddleValue() const
{
    return (numbers[numbers.size() / 2]);
}

void PrintQueue::Update::makeItValid(const std::vector<Rule> &rules)
{
    if (valid == VALID)
    {
        return;
    }

    std::vector<int> ordered_update = numbers;
    bool changed;

    do
    {
        changed = false;

        for (int i = 0; i < ordered_update.size() - 1; i++)
        {
            for (const auto &rule : rules)
            {
                if (rule.getFirst() == ordered_update[i + 1] && rule.getSecond() == ordered_update[i])
                {
                    std::swap(ordered_update[i], ordered_update[i + 1]);
                    changed = true;
                }
            }
        }
    } while (changed);

    std::reverse(ordered_update.begin(), ordered_update.end());
    numbers = ordered_update;
    valid = VALID;
}
