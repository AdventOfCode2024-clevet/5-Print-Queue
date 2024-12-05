#include <regex>

#include "Rule.hpp"

PrintQueue::Rule::Rule(const std::string &line)
{
    const std::regex pair_regex("([0-9]+)\\|([0-9]+)");
    std::smatch match;

    if (std::regex_match(line, match, pair_regex))
    {
        first = std::stoi(match[1]);
        second = std::stoi(match[2]);
    }
}

int PrintQueue::Rule::getFirst() const
{
    return (first);
}

int PrintQueue::Rule::getSecond() const
{
    return (second);
}
