#include "GeneticConstruction.hpp"

#include "Gene.hpp"

#include <iostream>


GeneticConstruction::GeneticConstruction(
    const std::string& name,
    Gene* gene)
    : name_{ name },
      gene_{ gene }
{
    if (name_.empty())
    {
        std::cout << "Ошибка: имя конструкции не может быть пустым"
                  << std::endl;
    }

    if (gene_ == nullptr)
    {
        std::cout << "Ошибка: конструкция не содержит ген"
                  << std::endl;
    }

    std::cout << "Создана генетическая конструкция: "
              << name_
              << std::endl;
}


GeneticConstruction::~GeneticConstruction()
{
    std::cout << "Удалена генетическая конструкция: "
              << name_
              << std::endl;
}


bool GeneticConstruction::CheckConstruction() const
{
    if (name_.empty())
    {
        std::cout << "Ошибка: имя конструкции не задано"
                  << std::endl;
        return false;
    }

    if (gene_ == nullptr)
    {
        std::cout << "Ошибка: конструкция не содержит ген"
                  << std::endl;
        return false;
    }

    if (!gene_->Validate())
    {
        std::cout << "Ошибка: ген не прошёл проверку"
                  << std::endl;
        return false;
    }

    std::cout << "Проверка конструкции пройдена"
              << std::endl;

    return true;
}


void GeneticConstruction::Simulate() const
{
    if (!CheckConstruction())
    {
        std::cout << "Моделирование конструкции не выполнено"
                  << std::endl;
        return;
    }

    std::cout << "Моделирование конструкции "
              << name_
              << " выполнено"
              << std::endl;
}


void GeneticConstruction::PrintInfo() const
{
    std::cout << "Конструкция: "
              << name_
              << std::endl;

    if (gene_ != nullptr)
    {
        gene_->PrintInfo();
    }
}
