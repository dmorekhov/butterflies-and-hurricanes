#include "GameRules.h"

#include <iostream>
#include <ostream>

GameRules::GameRules(const string& birthRule, const string& survivalRule) {
    birthRules.fill(false);
    for (char symbol : birthRule) {
        if (symbol < '0' || symbol > '8' ) {
            cerr << "Birth rule symbol out of range" << endl;
            throw exception();
        }
        if (birthRules[symbol - '0']) {
            cerr << "Birth rule already exists" << endl;
            throw std::exception();
        }
        birthRules[symbol - '0'] = true;
    }

    survivalRules.fill(false);
    for (char symbol : survivalRule) {
        if (symbol < '0' || symbol > '8' ) {
            cerr << "Survival rule symbol out of range" << endl;
            throw std::exception();
        }
        if (survivalRules[symbol - '0']) {
            cerr << "Survival rule already exists" << endl;
            throw std::exception();
        }
        survivalRules[symbol - '0'] = true;
    }
}

GameRules::GameRules(string& rules) {
    bool met_slash = false;
    string birth_rule;
    string surv_rule;
    for (char symbol : rules) {
        if (!met_slash && symbol != '/') {
            birth_rule += symbol;
        } else if (symbol == '/') {
            met_slash = true;
        } else {
            surv_rule += symbol;
        }
    }
    birthRules.fill(false);
    for (char symbol : birth_rule) {
        if (symbol < '0' || symbol > '8' ) {
            throw std::exception();
        }
        if (birthRules[symbol - '0']) {
            throw std::exception();
        }
        birthRules[symbol - '0'] = true;
    }

    survivalRules.fill(false);
    for (char symbol : surv_rule) {
        if (symbol < '0' || symbol > '8' ) {
            throw std::exception();
        }
        if (survivalRules[symbol - '0']) {
            throw std::exception();
        }
        survivalRules[symbol - '0'] = true;
    }
}


bool GameRules::checkBirthRule(int& liveNeighbours) {
    return birthRules[liveNeighbours];
}

bool GameRules::checkSurvivalRule(int& liveNeighbours) {
    return survivalRules[liveNeighbours];
}

array<bool, 9> GameRules::getBirthRules() {
    return birthRules;
}

array<bool, 9> GameRules::getSurvivalRules() {
    return survivalRules;
}

string GameRules::getGameRules() {
    string game_rules = "#R B";
    for (int i = 0; i < 9; i++) {
        if (birthRules[i]) {
            game_rules += to_string(i + 1);
        }
    }
    game_rules += "/S";
    for (int i = 0; i < 9; i++) {
        if (survivalRules[i]) {
            game_rules += to_string(i + 1);
        }
    }
    return game_rules;
}

void GameRules::PrintBirthRules() {
    for (int i = 0; i < 9; i++) {
        cout << birthRules[i];
    }
    cout << endl;
}

void GameRules::PrintSurvivalRules() {
    for (int i = 0; i < 9; i++) {
        cout << survivalRules[i];
    }
    cout << endl;
}
