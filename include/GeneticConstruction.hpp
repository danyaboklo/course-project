#pragma once

#include <string>

class Gene;

/**
 * @brief Представляет генетическую конструкцию.
 *
 * Использует внешний объект Gene.
 * Связь между классами реализована через агрегацию.
 */
class GeneticConstruction
{
private:
    std::string name_;
    Gene* gene_;

public:
    GeneticConstruction(const std::string& name, Gene* gene);

    ~GeneticConstruction();

    bool CheckConstruction() const;

    void Simulate() const;

    void PrintInfo() const;
};
