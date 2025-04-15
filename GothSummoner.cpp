// 🐺 GOTH SUMMONER - C++ Edition

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

std::string capitalize(const std::string& word) {
    if (word.empty()) return "";
    std::string result = word;
    result[0] = toupper(result[0]);
    return result;
}

std::string to_lower(const std::string& str) {
    std::string lowered = str;
    std::transform(str.begin(), str.end(), lowered.begin(), ::tolower);
    return lowered;
}

bool is_valid_choice(const std::string& choice) {
    return choice == "werewolf" || choice == "vampire" || choice == "zombie";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    std::string player_emoji;
    std::string emoji_choice;

    // Choose sigil
    std::cout << "✨ Choose your summoner sigil:\n";
    std::cout << "1. Sword ⚔️\n";
    std::cout << "2. Shield 🛡️\n";
    std::cout << "3. Wizard 🧙‍♂️\n";
    std::cout << "4. Witch 🧙‍♀️\n";

    std::cout << "Pick a number between 1 and 4 to select your sigil: ";
    std::getline(std::cin, emoji_choice);

    if (emoji_choice == "1") player_emoji = "⚔️";
    else if (emoji_choice == "2") player_emoji = "🛡️";
    else if (emoji_choice == "3") player_emoji = "🧙‍♂️";
    else if (emoji_choice == "4") player_emoji = "🧙‍♀️";
    else {
        std::cout << "Invalid choice! Defaulting to ⚔️ Sword.\n";
        player_emoji = "⚔️";
    }

    std::cout << "\nYour sigil is " << player_emoji << ".\n\n";

    // Game intro
    std::cout << "💀 Welcome to the GOTH SUMMONING battle 💀\n";
    std::cout << "Summon your monster and defeat your enemy!\n\n";
    std::cout << "Choices: Werewolf 🐺 (beats Vampire), Vampire 🧛 (beats Zombie), Zombie 🧟 (beats Werewolf)\n\n";

    std::string options[3] = { "werewolf", "vampire", "zombie" };
    int wins = 0, losses = 0;

    for (int turn = 1; turn <= 5; ++turn) {
        std::string player, enemy;

        std::cout << "\n🌑 Turn " << turn << "\n";
        std::cout << "Summon your monster (werewolf/vampire/zombie): ";
        std::getline(std::cin, player);
        player = to_lower(player);

        if (!is_valid_choice(player)) {
            std::cout << "⚠️ Invalid choice! You wasted a turn summoning shadows.\n";
            continue;
        }

        enemy = options[rand() % 3];

        std::cout << player_emoji << " You summoned: " << capitalize(player) << "\n";
        std::cout << "👹 Enemy summoned: " << capitalize(enemy) << "\n";

        if (player == enemy) {
            std::cout << "⚔️ It's a draw. The monsters stare at each other and vanish.\n";
        } else if (
            (player == "werewolf" && enemy == "vampire") ||
            (player == "vampire" && enemy == "zombie") ||
            (player == "zombie" && enemy == "werewolf")
        ) {
            std::cout << "🔥 Your monster devoured the enemy! You win this round.\n";
            ++wins;
        } else {
            std::cout << "💀 The enemy overpowered your monster. You lose this round.\n";
            ++losses;
        }
    }

    // Result
    std::cout << "\n🧙‍♂️ The ritual is complete...\n";
    std::cout << "🏆 Victories: " << wins << "\n";
    std::cout << "☠️ Losses: " << losses << "\n";

    if (wins > losses) {
        std::cout << player_emoji << " Congratulations! You are the Master Summoner!\n";
    } else if (wins < losses) {
        std::cout << "👁️ The succubus of the dark dimension consume your weak soul tonight...\n";
    } else {
        std::cout << "🌫️ The veil between worlds remains... balanced. Your glory or shame shall be decided in the next battle.\n";
    }

    std::cout << "\n🌌 Farewell, spell caster. May the good shadows guide your path.\n";
    return 0;
}
