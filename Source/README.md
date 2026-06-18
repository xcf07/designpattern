# TECHNICAL DESIGN DOCUMENT (TDD)

# 1. Project Overview

## Project Name

Balatro Blind Progression System

## Description

Balatro Blind Progression System merupakan simulasi permainan kartu berbasis Balatro yang dikembangkan menggunakan C++17 dengan pendekatan Object-Oriented Programming (OOP).

Sistem mengimplementasikan tiga design pattern utama:

* State Pattern
* Command Pattern
* Chain of Responsibility

Permainan mensimulasikan progression blind dari Small Blind menuju Boss Blind, evaluasi kombinasi kartu poker, sistem scoring, reward, dan progression ante.

---

# 2. Technology Stack

| Component      | Technology              |
| -------------- | ----------------------- |
| Language       | C++17                   |
| Paradigm       | OOP                     |
| Design Pattern | State Pattern           |
| Design Pattern | Command Pattern         |
| Design Pattern | Chain of Responsibility |
| Build Tool     | g++                     |

---

# 3. Folder Structure

```text
Source/
│
├── main.cpp
├── GameManager.*
├── GameRuntime.*
├── RuntimeState.*
│
├── BlindState.*
├── SmallBlindState.*
├── BigBlindState.*
├── BossBlindState.*
│
├── RewardCommand.h
├── BonusHandCommand.*
├── FreePlayingCardCommand.*
│
├── BlindRule.*
├── RewardRule.*
├── ScoringRule.*
│
├── Hand.*
├── HandGenerator.*
├── HandPlayer.*
├── ChosenHand.*
│
├── PokerHandChecker.*
├── IHandChecker.h
│
└── Checker/
    ├── FlushFiveChecker.*
    ├── FlushHouseChecker.*
    ├── FiveOfAKindChecker.*
    ├── RoyalFlushChecker.*
    ├── StraightFlushChecker.*
    ├── FourOfAKindChecker.*
    ├── FullHouseChecker.*
    ├── FlushChecker.*
    ├── StraightChecker.*
    ├── ThreeOfAKindChecker.*
    ├── TwoPairChecker.*
    ├── PairChecker.*
    └── HighCardChecker.*
```

---

# 4. System Architecture

```text
main.cpp
    │
    ▼
GameManager
    │
    ├── GameRuntime
    │
    ├── BlindState
    │      ├── SmallBlindState
    │      ├── BigBlindState
    │      └── BossBlindState
    │
    ├── PokerHandChecker
    │      └── Checker Chain
    │
    ├── ScoringRule
    │
    ├── BlindRule
    │
    └── RewardRule
```

---

# 5. Main Game Flow

```text
START
 │
 ▼
Main Menu
 │
 ├── Play
 │
 └── Quit
      ↓
     EXIT

Play
 │
 ▼
Deck Selection
 │
 ├── Red Deck
 └── Back
      ↓
   Main Menu

Red Deck
 │
 ▼
Initialize Runtime
 │
 ▼
Small Blind
 │
 ▼
Big Blind
 │
 ▼
Boss Blind
 │
 ▼
Ante + 1
 │
 ▼
Repeat
 │
 ▼
Victory / Game Over
```

---

# 6. State Pattern

## Purpose

Mengelola progression blind tanpa menggunakan banyak if-else.

## Abstract State

### BlindState

Method:

* play()
* skip()
* nextState()
* printInfo()

## Concrete State

### SmallBlindState

Tanggung Jawab:

* Menampilkan informasi Small Blind
* Menentukan target score Small Blind
* Berpindah ke BigBlindState

### BigBlindState

Tanggung Jawab:

* Menampilkan informasi Big Blind
* Menentukan target score Big Blind
* Berpindah ke BossBlindState

### BossBlindState

Tanggung Jawab:

* Menentukan kemenangan ante
* Menaikkan ante
* Mengakhiri permainan

---

# 7. Command Pattern

## Purpose

Mengelola reward hasil Skip Blind.

## Abstract Command

### RewardCommand

Method:

execute(RuntimeState&)

## Concrete Command

### BonusHandCommand

Effect:

+1 Hand

### FreePlayingCardCommand

Effect:

Free Playing Card

## Runtime Storage

RuntimeState menyimpan command menggunakan:

```cpp
std::vector<std::unique_ptr<RewardCommand>>
pendingCommands;
```

Flow:

```text
Skip Blind
    ↓
Create Command
    ↓
Store Command
    ↓
Execute Command
    ↓
Apply Reward
```

---

# 8. Chain of Responsibility

## Purpose

Mendeteksi kombinasi poker hand.

Urutan checker:

```text
FlushFiveChecker
 ↓
FlushHouseChecker
 ↓
FiveOfAKindChecker
 ↓
RoyalFlushChecker
 ↓
StraightFlushChecker
 ↓
FourOfAKindChecker
 ↓
FullHouseChecker
 ↓
FlushChecker
 ↓
StraightChecker
 ↓
ThreeOfAKindChecker
 ↓
TwoPairChecker
 ↓
PairChecker
 ↓
HighCardChecker
```

Setiap checker hanya bertanggung jawab terhadap satu kombinasi kartu.

---

# 9. Runtime Components

## GameRuntime

Menyimpan data permainan aktif:

* currentAnte
* money
* currentScore
* remainingPlays
* currentState
* gameOver

## RuntimeState

Menyimpan data command dan reward:

* ante
* remainingHands
* remainingDiscards
* pendingCommands

---

# 10. Hand System

## Card

Representasi kartu:

* rank
* suit

## Hand

Representasi 5 kartu yang dimainkan.

Field:

* cards
* detectedRank

## HandGenerator

Menghasilkan 5 kartu acak.

## HandPlayer

Mewakili kartu yang dimainkan pemain.

## ChosenHand

Menyimpan pilihan kartu pemain.

---

# 11. Scoring System

| Hand            | Score |
| --------------- | ----- |
| Flush Five      | 200   |
| Flush House     | 160   |
| Five of a Kind  | 140   |
| Royal Flush     | 120   |
| Straight Flush  | 100   |
| Four of a Kind  | 70    |
| Full House      | 60    |
| Flush           | 50    |
| Straight        | 40    |
| Three of a Kind | 30    |
| Two Pair        | 20    |
| Pair            | 10    |
| High Card       | 5     |

---

# 12. Blind System

## Ante 1

| Blind | Target | Reward |
| ----- | ------ | ------ |
| Small | 300    | $3     |
| Big   | 450    | $4     |
| Boss  | 600    | $5     |

## Ante 2

| Blind | Target | Reward |
| ----- | ------ | ------ |
| Small | 800    | $4     |
| Big   | 1200   | $5     |
| Boss  | 1600   | $6     |

## Ante 3

| Blind | Target | Reward |
| ----- | ------ | ------ |
| Small | 2000   | $5     |
| Big   | 3000   | $6     |
| Boss  | 4000   | $8     |

---

# 13. Design Principles

## Single Responsibility Principle

Setiap class memiliki satu tanggung jawab utama.

Contoh:

* HandGenerator → Generate kartu
* ScoringRule → Hitung skor
* BlindRule → Cek target blind

## Open Closed Principle

Sistem dapat diperluas tanpa mengubah kode lama.

Contoh:

* Menambah UltraBlindState
* Menambah RewardCommand baru
* Menambah Checker baru

## Encapsulation

Semua data runtime disimpan private dan diakses melalui method.

## Polymorphism

Menggunakan:

* BlindState*
* RewardCommand*
* IHandChecker*

---

# 14. Future Development

* Joker System
* Additional Deck
* Dynamic Blind Scaling
* Save & Load System
* GUI Interface
* Multiplayer Support
