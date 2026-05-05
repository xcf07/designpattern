#pragma once
#include <vector>
#include "Card.h"  // DITAMBAHKAN: include Card.h karena Hand sekarang menyimpan vector<Card>

// HandRank enum tetap dipertahankan dari versi temanmu
// DITAMBAHKAN: UNKNOWN sebagai nilai default jika tidak ada hand yang terdeteksi

enum class HandRank {
    HIGH_CARD,
    PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH,
    FIVE_OF_A_KIND,
    FLUSH_HOUSE,
    FLUSH_FIVE,
    UNKNOWN
};

struct Hand {
    // DIUBAH: sebelumnya 'int value = 0' yang hanya berupa angka dummy
    // Sekarang Hand menyimpan kartu-kartu sungguhan menggunakan vector<Card>
    // Setiap Card memiliki 'rank' (angka 2-14) dan 'suit' (H/D/C/S)
    // Contoh isi cards: { {10,'H'}, {11,'H'}, {12,'H'}, {13,'H'}, {14,'H'} }
    std::vector<Card> cards; 
};