#include <iostream>
#include "pieapple.h"

    int Creation::numberOfCreations = 0;
    Universe* Universe::instance = nullptr;
int main() {

    Universe* world = Universe::getInstance();

    //  invalid_argument (Date)
    try {
        Date badDate(2026, 13, 40);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[Date Error] " << e.what() << "\n";
    }

    //  invalid_argument
    try {
        Date d1(2026, 5, 25);

        Human* h1 = new Human("", d1); // ??? ???? ? invalid_argument
        world->addCreation(h1);
    }
    catch (const std::exception& e) {
        std::cout << "[Human Name Error] " << e.what() << "\n";
    }

    // length_error (Human)
    try {
        Date d2(2026, 5, 25);

        std::string longName(200, 'A');
        Human* h2 = new Human(longName, d2);

        world->addCreation(h2);
    }
    catch (const std::length_error& e) {
        std::cout << "[Human Length Error] " << e.what() << "\n";
    }

    //  logic_error (double death)
    try {
        Date d3(2026, 5, 25);

        Human* h3 = new Human("John", d3);
        h3->markAsDeceased();
        h3->markAsDeceased();
    }
    catch (const std::logic_error& e) {
        std::cout << "[Human Logic Error] " << e.what() << "\n";
    }

    // Apple invalid_argument (empty color)
    try {
        Date d4(2026, 5, 25);

        Apple* a1 = new Apple("", false, d4);
        world->addCreation(a1);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[Apple Error] " << e.what() << "\n";
    }

    //  invalid_argument (nullptr add)

    try {
        world->addCreation(nullptr);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[Universe Null Error] " << e.what() << "\n";
    }


    // runtime_error (no human/apple for pie)

    try {
        ApplePie* pie = world->bakeApplePie();
        if (pie) {
            std::cout << "Pie baked (unexpected)\n";
        }
    }
    catch (const std::runtime_error& e) {
        std::cout << "[Bake Error] " << e.what() << "\n";
    }

    // logic_error (invalid delete)
    try {
        world->deleteCreation(99999); // id ????????
    }
    catch (const std::logic_error& e) {
        std::cout << "[Delete Error] " << e.what() << "\n";
    }


    //  bad_alloc (optional stress test)

    try {
        while (true) {
            world->addCreation(new Human("Stress", Date(2026, 5, 25)));
        }
    }
    catch (const std::bad_alloc& e) {
        std::cout << "[Memory Error] " << e.what() << "\n";
    }

    world->delete_instance();

    return 0;
}