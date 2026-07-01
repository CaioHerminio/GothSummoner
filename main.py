import random

# Select your emoji
print("✨ Choose your summoner sigil:")
print("1. Sword ⚔️")
print("2. Shield 🛡️")
print("3. Wizard 🧙‍♂️")
print("4. Witch 🧙‍♀️")

emoji_choice = input("Pick a number between 1 and 4 to select your sigil: ").strip()

if emoji_choice == "1":
    player_emoji = "⚔️"
elif emoji_choice == "2":
    player_emoji = "🛡️"
elif emoji_choice == "3":
    player_emoji = "🧙‍♂️"
elif emoji_choice == "4":
    player_emoji = "🧙‍♀️"
else:
    print("Invalid choice! Defaulting to ⚔️ Sword.")
    player_emoji = "⚔️"

print(f"\nYour sigil is {player_emoji}.\n")

# Game starts
print("💀 Welcome to the GOTH SUMMONING battle 💀")
print("Summon your monster and defeat your enemy!\n")
print("Choices: Werewolf 🐺 (beats Vampire), Vampire 🧛 (beats Zombie), Zombie 🧟 (beats Werewolf)\n")

choices = ["werewolf", "vampire", "zombie"]
wins = 0
losses = 0

turn = 1
while turn <= 5:
    print(f"\n🌑 Turn {turn}")
    player = input("Summon your monster (werewolf/vampire/zombie): ").strip().lower()
    if player not in choices:
        print("⚠️ Invalid choice! You wasted a turn summoning shadows.")
        turn += 1
        continue

    enemy = random.choice(choices)
    print(f"{player_emoji} You summoned: {player.capitalize()}")
    print(f"👹 Enemy summoned: {enemy.capitalize()}")

    if player == enemy:
        print("⚔️ It's a draw. The monsters stare at each other and vanish.")
    elif (
        (player == "werewolf" and enemy == "vampire") or
        (player == "vampire" and enemy == "zombie") or
        (player == "zombie" and enemy == "werewolf")
    ):
        print("🔥 Your monster devoured the enemy! You win this round.")
        wins += 1
    else:
        print("💀 The enemy overpowered your monster. You lose this round.")
        losses += 1

    turn += 1

# Final result
print("\n🧙‍♂️ The ritual is complete...")
print(f"🏆 Victories: {wins}")
print(f"☠️ Losses: {losses}")

if wins > losses:
    print(f"{player_emoji} Congratulations! You are the Master Summoner!")
elif wins < losses:
    print("👁️ The succubus of the dark dimension consume your weak soul tonight...")
else:
    print("🌫️ The veil between worlds remains... balanced. Your glory or shame shall be decided in the next battle.")
print("\n🌌 Farewell, spell caster. May the good shadows guide your path.")
