#pragma once

#ifndef RULE_HPP
    #define RULE_HPP

    #include <string>

    namespace PrintQueue
    {
        class Rule
        {
            public:
                Rule(const std::string &line);
                ~Rule() = default;

                int getFirst() const;
                int getSecond() const;

            private:
                int first;
                int second;
        };
    }

#endif /* RULE_HPP */
