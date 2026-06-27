# Discord Webhook for SA:MP

A lightweight SA:MP (San Andreas Multiplayer) include to send rich embed messages to Discord channels via webhook URLs. Powered by the **Pawn Requests** plugin.

---

## Features

- Send **rich embed messages** to Discord with a single function call.
- Supports **title**, **description**, **color**, **fields** (inline), and **footer**.
- Customizable **bot username** and **avatar** for each request.
- Fully compatible with **SA:MP 0.3.7** and above.
- No external dependencies besides the Requests plugin.
- Clean, well‑documented code ready for production.

---

## Requirements

- [Pawn Requests](https://github.com/Southclaws/pawn-requests) plugin (v0.11.1 or latest release)
- SA:MP server 0.3.7 or later
- Basic knowledge of Pawn scripting

---

## Installation

1. Download the latest release of **Pawn Requests** from [here](https://github.com/Southclaws/pawn-requests/releases).
2. Put `requests.dll` (Windows) or `requests.so` (Linux) into your server's `plugins/` folder.
3. Put `requests.inc` into your `pawno/include/` folder.
4. Add `requests` to the `plugins` line in your `server.cfg`.
5. Copy `discord-webhook.inc` into your `pawno/include/` folder.

---

## Installation for Open.MP

1. Download the latest release of **Pawn Requests** from [here](https://github.com/Southclaws/pawn-requests/releases).
2. Put `requests.dll` (Windows) or `requests.so` (Linux) into your server's `components/` folder.
3. Put `requests.inc` into your `qawno/include/` folder.
4. Add `requests` to the `legacy_plugins` line in your `config.json`.
5. Copy `discord-webhook.inc` into your `qawno/include/` folder.

---

## Quick Start

```pawn
#include <discord-webhook>

public OnGameModeInit()
{
    SendDiscordEmbed(
        "https://discord.com/api/webhooks/1234567890/abcdefghijklmnopqrstuvwxyz",
        "My SA:MP Bot",
        "https://i.imgur.com/myavatar.png",
        "Server Started",
        "The server is now online!",
        0x00FF00,
        "Info|Everything is running smoothly",
        "My SA:MP Server"
    );
    return 1;
}
