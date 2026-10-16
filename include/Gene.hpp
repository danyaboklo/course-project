#pragma once

#include <string>

#include "DnaSequence.hpp"

/**
 * @brief Представляет генетический элемент.
 *
 * Содержит название гена и последовательность ДНК.
 * Использует композицию с классом DnaSequence.
 */
class Gene
{
private:
    std::string name_;
    DnaSequence dnaSequence_;
    bool expressionActive_;

public:
    Gene(const std::string& name, const std::string& sequence);

    ~Gene();

    bool Validate() const;

    void ActivateExpression();

    void DeactivateExpression();

    void PrintInfo() const;
};
