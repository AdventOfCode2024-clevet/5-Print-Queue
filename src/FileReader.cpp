#include "FileReader.hpp"
#include "Rule.hpp"
#include "Update.hpp"

PrintQueue::FileReader::FileReader(const std::string &fileName)
{
    input.open(fileName);
    if (!input.is_open())
    {
        throw std::runtime_error("Error: could not open file " + fileName);
    }
    lines = readLines();
}

std::vector<PrintQueue::Rule> PrintQueue::FileReader::readRules()
{
    std::vector<Rule> rules;

    for (const auto &line : lines)
    {
        if (line.empty())
        {
            break;
        }
        rules.push_back(Rule(line));
    }

    return (rules);
}

std::vector<PrintQueue::Update> PrintQueue::FileReader::readUpdates()
{
    std::vector<Update> updates;

    int index = 0;
    for (; index < lines.size(); index++)
    {
        if (lines[index].empty())
        {
            break;
        }
    }

    index++;

    for (; index < lines.size(); index++)
    {
        if (lines[index].empty())
        {
            break;
        }
        updates.push_back(Update(lines[index]));
    }

    return (updates);
}

std::vector<std::string> PrintQueue::FileReader::readLines()
{
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(input, line))
    {
        lines.push_back(line);
    }
    return (lines);
}
