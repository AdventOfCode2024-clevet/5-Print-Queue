#pragma once

#ifndef UPDATE_HPP
    #define UPDATE_HPP

    #include <string>
    #include <vector>

    enum Validity
    {
        VALID = 1,
        INVALID = 0,
        UNKNOWN = -1
    };

    namespace PrintQueue
    {
        class Rule;

        class Update
        {
            public:
                explicit Update(const std::string &line);
                ~Update() = default;

                bool isValid(const std::vector<Rule> &rules);
                int getMiddleValue() const;
                void makeItValid(const std::vector<Rule> &rules);

            private:
                std::vector<int> numbers;
                int valid;
        };
    }

#endif /* UPDATE_HPP */
