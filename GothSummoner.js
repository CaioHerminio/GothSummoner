// 🐺 GOTH SUMMONER - JavaScript Edition

const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

function ask(question) {
  return new Promise((resolve) => rl.question(question, (answer) => resolve(answer)));
}

function capitalize(word) {
  return word.charAt(0).toUpperCase() + word.slice(1);
}

async function game() {
  // Select your emoji
  console.log("✨ Choose your summoner sigil:");
  console.log("1. Sword ⚔️");
  console.log("2. Shield 🛡️");
  console.log("3. Wizard 🧙‍♂️");
  console.log("4. Witch 🧙‍♀️");

  const emoji_choice = (await ask("Pick a number between 1 and 4 to select your sigil: ")).trim();

  let player_emoji;
  switch (emoji_choice) {
    case "1":
      player_emoji = "⚔️";
      break;
    case "2":
      player_emoji = "🛡️";
      break;
    case "3":
      player_emoji = "🧙‍♂️";
      break;
    case "4":
      player_emoji = "🧙‍♀️";
      break;
    default:
      console.log("Invalid choice! Defaulting to ⚔️ Sword.");
      player_emoji = "⚔️";
  }

  console.log(`\nYour sigil is ${player_emoji}.\n`);

  // Game starts
  console.log("💀 Welcome to the GOTH SUMMONING battle 💀");
  console.log("Summon your monster and defeat your enemy!\n");
  console.log("Choices: Werewolf 🐺 (beats Vampire), Vampire 🧛 (beats Zombie), Zombie 🧟 (beats Werewolf)\n");

  const choices = ["werewolf", "vampire", "zombie"];
  let wins = 0;
  let losses = 0;

  let turn = 1;
  while (turn <= 5) {
    console.log(`\n🌑 Turn ${turn}`);
    const player = (await ask("Summon your monster (werewolf/vampire/zombie): ")).trim().toLowerCase();

    if (!choices.includes(player)) {
      console.log("⚠️ Invalid choice! You wasted a turn summoning shadows.");
      turn++;
      continue;
    }

    const enemy = choices[Math.floor(Math.random() * choices.length)];

    console.log(`${player_emoji} You summoned: ${capitalize(player)}`);
    console.log(`👹 Enemy summoned: ${capitalize(enemy)}`);

    if (player === enemy) {
      console.log("⚔️ It's a draw. The monsters stare at each other and vanish.");
    } else if (
      (player === "werewolf" && enemy === "vampire") ||
      (player === "vampire" && enemy === "zombie") ||
      (player === "zombie" && enemy === "werewolf")
    ) {
      console.log("🔥 Your monster devoured the enemy! You win this round.");
      wins++;
    } else {
      console.log("💀 The enemy overpowered your monster. You lose this round.");
      losses++;
    }

    turn++;
  }

  // Final result
  console.log("\n🧙‍♂️ The ritual is complete...");
  console.log(`🏆 Victories: ${wins}`);
  console.log(`☠️ Losses: ${losses}`);

  if (wins > losses) {
    console.log(`${player_emoji} Congratulations! You are the Master Summoner!`);
  } else if (wins < losses) {
    console.log("👁️ The succubus of the dark dimension consume your weak soul tonight...");
  } else {
    console.log("🌫️ The veil between worlds remains... balanced. Your glory or shame shall be decided in the next battle.");
  }

  console.log("\n🌌 Farewell, spell caster. May the good shadows guide your path.");
  rl.close();
}

game();
