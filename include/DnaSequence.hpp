#pragma once

#include <string>

/**
 * @brief Класс, представляющий последовательность ДНК.
 *
 * Ответственность класса:
 * хранение последовательности нуклеотидов,
 * проверка её корректности и поиск фрагментов последовательности.
 */
class DnaSequence
{
private:
    std::string sequence_;

public:
    DnaSequence(const std::string& sequence);

    ~DnaSequence();

    bool Validate() const;

    bool ContainsMotif(const std::string& motif) const;

    void PrintSequence() const;
};
