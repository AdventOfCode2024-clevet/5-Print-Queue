#pragma once

#ifndef UPDATECOUNTER_HPP
    #define UPDATECOUNTER_HPP

    #include <vector>

    #include "Rule.hpp"
    #include "Update.hpp"

    namespace PrintQueue
    {
        class UpdateCounter
        {
            public:
                static int countUpdatesPartOne(const std::vector<Rule> &rules, const std::vector<Update> &updates)
                {
                    std::vector<Update> valid_updates = getValidUpdates(rules, updates);
                    int count = 0;

                    for (const auto &valid_update : valid_updates)
                    {
                        count += valid_update.getMiddleValue();
                    }

                    return (count);
                }

                static int countUpdatesPartTwo(const std::vector<Rule> &rules, std::vector<Update> &updates)
                {
                    std::vector<Update> invalid_updates = getInvalidUpdates(rules, updates);
                    int count = 0;

                    for (auto &invalid_update : invalid_updates)
                    {
                        invalid_update.makeItValid(rules);
                        count += invalid_update.getMiddleValue();
                    }

                    return (count);
                }

            private:
                static std::vector<Update> getValidUpdates(const std::vector<Rule> &rules, std::vector<Update> updates)
                {
                    std::vector<Update> valid_updates;
                    for (auto &update : updates)
                    {
                        if (update.isValid(rules))
                        {
                            valid_updates.push_back(update);
                        }
                    }

                    return (valid_updates);
                }

                static std::vector<Update> getInvalidUpdates(const std::vector<Rule> &rules, std::vector<Update> updates)
                {
                    std::vector<Update> invalid_updates;
                    for (auto &update : updates)
                    {
                        if (!update.isValid(rules))
                        {
                            invalid_updates.push_back(update);
                        }
                    }

                    return (invalid_updates);
                }
        };
    }

#endif