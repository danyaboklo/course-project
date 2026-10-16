#include "Gene.hpp"

#include <iostream>


Gene::Gene(const std::string& name, const std::string& sequence)
    : name_{ name },
      dnaSequence_{ sequence },
      expressionActive_{ false }
{
    if (!Validate())
    {
        std::cout << "Ошибка: некорректный ген\n";
    }
    else
    {
        std::cout << "Создан ген: "
                  << name_
                  << std::endl;
    }
}


Gene::~Gene()
{
    std::cout << "Удалён ген: "
              << name_
              << std::endl;
}


bool Gene::Validate() const
{
    return !name_.empty() && dnaSequence_.Validate();
}


void Gene::ActivateExpression()
{
    if (!Validate())
    {
        std::cout << "Ошибка: экспрессия некорректного гена невозможна"
                  << std::endl;
        return;
    }

    expressionActive_ = true;

    std::cout << "Экспрессия гена "
              << name_
              << " активирована"
              << std::endl;
}


void Gene::DeactivateExpression()
{
    expressionActive_ = false;

    std::cout << "Экспрессия гена "
              << name_
              << " деактивирована"
              << std::endl;
}


void Gene::PrintInfo() const
{
    std::cout << "Ген: "
              << name_
              << std::endl;

    std::cout << "Экспрессия: "
              << (expressionActive_ ? "активна" : "неактивна")
              << std::endl;

    dnaSequence_.PrintSequence();
}
