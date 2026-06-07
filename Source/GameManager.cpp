#include "GameManager.h"
#include <iostream>
#include <limits>

static void printActionMenu() {
    std::cout << "\n  Pilih aksi:\n";
    std::cout << "    [1] PLAY  - Mainkan blind ini\n";
    std::cout << "    [2] SKIP  - Lewati blind ini (dapat reward command)\n";
    std::cout << "    [0] QUIT  - Keluar dari permainan\n";
    std::cout << "  >> Pilihan kamu: ";
}

static void flushInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void GameManager::runSession() {
    std::cout << "\n";
    std::cout << "  ╔══════════════════════════════════════════╗\n";
    std::cout << "  ║     BALATRO - BLIND PROGRESSION SYSTEM   ║\n";
    std::cout << "  ║         Design Pattern : State           ║\n";
    std::cout << "  ╚══════════════════════════════════════════╝\n";

    // Set state awal: Small Blind Ante 1
    auto startState = std::make_shared<SmallBlindState>(1);
    runtime.setState(startState);

    while (!runtime.isGameOver()) {
        runtime.printStatus();

        BlindState* state = runtime.getState();
        if (!state) break;

        state->printInfo();
        printActionMenu();

        int choice = -1;
        std::cin >> choice;
        flushInput();

        switch (choice) {
            case 1: state->play(runtime); break;
            case 2: state->skip(runtime); break;
            case 0:
                std::cout << "\n  >> Permainan dihentikan. Sampai jumpa!\n\n";
                return;
            default:
                std::cout << "\n  [!] Pilihan tidak valid. Coba lagi.\n";
                break;
        }
    }

    std::cout << "\n  ============ RINGKASAN AKHIR ============\n";
    runtime.printStatus();
    std::cout << "\n  Terima kasih sudah bermain!\n\n";
}
