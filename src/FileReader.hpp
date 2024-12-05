#pragma once

#ifndef FILEREADER_HPP
    #define FILEREADER_HPP

    #include <fstream>
    #include <string>
    #include <vector>

    namespace PrintQueue
    {
        class Rule;
        class Update;

        class FileReader
        {
            public:
                explicit FileReader(const std::string &fileName);
                ~FileReader() = default;

                std::vector<Rule> readRules();
                std::vector<Update> readUpdates();

            private:
                std::ifstream input;

                std::vector<std::string> readLines();
                std::vector<std::string> lines;
        };
    }

#endif /* FILEREADER_HPP */
