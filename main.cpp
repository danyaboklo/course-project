#include "DnaSequence.hpp"
#include "Gene.hpp"
#include "GeneticConstruction.hpp"

#include <iostream>


int main()
{
    std::cout << "=== Статический объект ===\n";

    static Gene staticGene(
        "StaticGene",
        "ATGC"
    );

    staticGene.PrintInfo();


    std::cout << "\n=== Композиция ===\n";

    // Демонстрация композиции:
    // DnaSequence является частью Gene и уничтожается вместе с ним.
    {
        Gene gene(
            "FluorescentProtein",
            "ATGC"
        );

        gene.PrintInfo();
        gene.ActivateExpression();
        gene.DeactivateExpression();
    }


    std::cout << "\n=== Агрегация ===\n";

    // Демонстрация агрегации:
    // Gene создаётся отдельно и передаётся в GeneticConstruction.
    Gene* externalGene = new Gene(
        "Insulin",
        "ATGC"
    );


    {
        GeneticConstruction construction(
            "Medical construction",
            externalGene
        );

        construction.CheckConstruction();
        construction.PrintInfo();
        construction.Simulate();
    }


    // После удаления GeneticConstruction объект Gene продолжает существовать.
    std::cout << "Ген всё ещё существует:\n";

    externalGene->PrintInfo();

    // Удаление объекта, созданного через new.
    delete externalGene;
    externalGene = nullptr;


    std::cout << "\n=== Проверка правила ===\n";

    // Корректная последовательность ДНК.
    DnaSequence correct("ATGC");

    std::cout << "Содержит TGC: "
              << (correct.ContainsMotif("TGC") ? "да" : "нет")
              << std::endl;

    // Некорректная последовательность ДНК.
    DnaSequence incorrect("ATGX");


    std::cout << "\n=== Нарушение правила конструкции ===\n";

    {
        GeneticConstruction invalidConstruction(
            "Invalid construction",
            nullptr
        );

        invalidConstruction.Simulate();
    }


    std::cout << "\n=== new/delete ===\n";

    // Динамическое создание и удаление объекта.
    Gene* dynamicGene = new Gene(
        "DynamicGene",
        "ATGC"
    );

    dynamicGene->PrintInfo();

    delete dynamicGene;
    dynamicGene = nullptr;


    std::cout << "\n=== Ссылка и указатель ===\n";

    Gene gene(
        "ReferenceGene",
        "ATGC"
    );


    // Работа с объектом через ссылку.
    Gene& reference = gene;
    reference.PrintInfo();


    // Работа с объектом через указатель.
    Gene* pointer = &gene;
    pointer->PrintInfo();


    std::cout << "\n=== Массив объектов ===\n";

    // Локальный массив объектов класса.
    Gene genes[2] =
    {
        {"Gene1", "ATGC"},
        {"Gene2", "ATGC"}
    };


    std::cout << "\n=== Динамический массив объектов ===\n";

    // Динамический массив объектов класса.
    Gene* dynamicArray = new Gene[2]
    {
        {"ArrayGene1", "ATGC"},
        {"ArrayGene2", "ATGC"}
    };

    dynamicArray[0].PrintInfo();
    dynamicArray[1].PrintInfo();

    delete[] dynamicArray;


    std::cout << "\n=== Массив динамических объектов ===\n";

    // Массив указателей на динамически созданные объекты.
    Gene** dynamicGenes = new Gene*[2];

    dynamicGenes[0] = new Gene("GeneA", "ATGC");
    dynamicGenes[1] = new Gene("GeneB", "ATGC");


    delete dynamicGenes[0];
    delete dynamicGenes[1];

    delete[] dynamicGenes;


    return 0;
}
