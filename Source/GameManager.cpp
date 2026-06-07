#include "GameManager.h"
#include "ConcreteBlindStates.h"

#include <iostream>
#include <limits>

static void flushInput()
{
    std::cin.clear();
    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n'
    );
}

void GameManager::runSession()
{
    while (true)
    {
        // =====================================
        // MAIN MENU
        // =====================================

        std::cout << "\n";
        std::cout << "=====================================\n";
        std::cout << "         BALATRO SIMULATION\n";
        std::cout << "=====================================\n";
        std::cout << "[1] Play\n";
        std::cout << "[0] Quit\n";
        std::cout << ">> ";

        int menuChoice;
        std::cin >> menuChoice;
        flushInput();

        if (menuChoice == 0)
        {
            std::cout
                << "\nTerima kasih sudah bermain!\n";
            return;
        }

        if (menuChoice != 1)
            continue;

        // =====================================
        // DECK SELECTION
        // =====================================

        bool deckSelected = false;

        while (!deckSelected)
        {
            std::cout << "\n";
            std::cout << "=========== DECK SELECTION ===========\n";
            std::cout << "[1] Red Deck (+1 Discard)\n";
            std::cout << "[0] Back\n";
            std::cout << ">> ";

            int deckChoice;
            std::cin >> deckChoice;
            flushInput();

            if (deckChoice == 0)
                break;

            if (deckChoice == 1)
            {
                std::cout
                    << "\nRed Deck dipilih! (+1 Discard)\n";

                deckSelected = true;
            }
        }

        if (!deckSelected)
            continue;

        // =====================================
        // START RUN
        // =====================================

        runtime = GameRuntime();

        auto startState =
            std::make_shared<SmallBlindState>(1);

        runtime.setState(startState);

        while (!runtime.isGameOver())
        {
            runtime.printStatus();

            BlindState* state =
                runtime.getState();

            if (!state)
                break;

            state->printInfo();

            std::cout << "\n";
            std::cout << "Pilih aksi:\n";
            std::cout << "[1] Play Blind\n";
            std::cout << "[2] Skip Blind\n";
            std::cout << "[0] Quit Run\n";
            std::cout << ">> ";

            int choice;
            std::cin >> choice;
            flushInput();

            switch (choice)
            {
            case 1:
            {
                state->play(runtime);

                if (!runtime.isGameOver())
                {
                    std::cout
                        << "\n=========== SHOP ===========\n";

                    std::cout
                        << "Money: $"
                        << runtime.getMoney()
                        << "\n";

                    std::cout
                        << "\nTekan ENTER untuk lanjut...";
                    std::cin.get();
                }

                break;
            }

            case 2:
            {
                state->skip(runtime);
                break;
            }

            case 0:
            {
                runtime.setGameOver(true);
                break;
            }

            default:
            {
                std::cout
                    << "\n[!] Pilihan tidak valid.\n";
                break;
            }
            }
        }

        std::cout << "\n";
        std::cout
            << "=====================================\n";
        std::cout
            << "           RUN SELESAI\n";
        std::cout
            << "=====================================\n";

        runtime.printStatus();

        std::cout
            << "\nKembali ke Main Menu...\n";
    }
}