<!-- Bootstrap Icons CSS (optional, for local preview) -->
<!-- <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.10.5/font/bootstrap-icons.css"> -->

<br />
<div align="center">
  <a href="https://github.com/XenoX352/discord-webhook-open.mp">
    <img src="https://media.discordapp.net/attachments/1508493991392313406/1521104425937272932/discord.png?ex=6a439e63&is=6a424ce3&hm=dc4efa22ed2fa37577292daa4bf7d7d357ed18a2f79b7c90b748eff45cab028c&=&format=webp&quality=lossless" alt="Logo" width="80" height="80">
  </a>

  <h3>Discord Webhook for SA:MP</h3>

  <p>
    Send rich embed messages to Discord from your SA:MP server.
    <br />
    <a href="https://github.com/Southclaws/pawn-requests"><i class="bi bi-plug"></i> Pawn Requests</a>
    ·
    <a href="#quick-start"><i class="bi bi-lightning-charge"></i> Quick Start</a>
    ·
    <a href="#installation"><i class="bi bi-download"></i> Installation</a>
  </p>
</div>

<p align="center">
  <img src="https://img.shields.io/badge/SA--MP-0.3.7%20%7C%20open.mp-blue" alt="SA-MP">
  <img src="https://img.shields.io/badge/plugin-requests-orange" alt="requests">
  <img src="https://img.shields.io/badge/license-MIT-green" alt="License">
</p>

---

## <i class="bi bi-info-circle"></i> About

**Discord Webhook** is a lightweight Pawn include that lets your SA:MP or open.mp server send beautifully formatted embed messages directly to a Discord channel.  
Powered by the [Pawn Requests](https://github.com/Southclaws/pawn-requests) plugin, it offers a clean and straightforward API with zero bloat.

Whether you need to log admin actions, announce server events, or display player statistics, this system gets the job done with minimal configuration.

---

## <i class="bi bi-stars"></i> Features

- <i class="bi bi-chat-dots"></i> Rich embed messages – title, description, colour, fields, footer.
- <i class="bi bi-person-circle"></i> Customisable **bot username** and **avatar** per request.
- <i class="bi bi-columns-gap"></i> Inline fields for compact information display.
- <i class="bi bi-speedometer"></i> Lightweight and fast – no extra dependencies besides Requests.
- <i class="bi bi-shield-check"></i> Compatible with SA:MP 0.3.7 and open.mp.
- <i class="bi bi-journal-code"></i> Clean, well‑documented code that’s easy to extend.

---

## <i class="bi bi-plug"></i> Requirements

- **Pawn Requests** plugin ([download](https://github.com/Southclaws/pawn-requests/releases))
- SA:MP server 0.3.7+ or open.mp
- Basic Pawn scripting knowledge

---

## <i class="bi bi-download"></i> Installation

### SA:MP (0.3.7 / 0.3.DL)
1. Download the latest **Pawn Requests** plugin.
2. Place `requests.dll` (Windows) or `requests.so` (Linux) into your server’s `plugins/` folder.
3. Place `requests.inc` into your `pawno/include/` folder.
4. Add `requests` to the `plugins` line in `server.cfg`.
5. Copy `discord-webhook.inc` into your `pawno/include/` folder.

### open.mp
1. Download the latest **Pawn Requests** plugin.
2. Place `requests.dll` / `requests.so` into your server’s `plugins/` folder.
3. Place `requests.inc` into your `qawno/include/` folder.
4. Add `requests` to the `legacy_plugins` array in `config.json`.
5. Copy `discord-webhook.inc` into your `qawno/include/` folder.

---

## <i class="bi bi-lightning-charge"></i> Quick Start

Include the library in your script and send an embed with one line:

```pawn
#include <discord-webhook>

public OnGameModeInit()
{
    SendDiscordEmbed(
        "https://discord.com/api/webhooks/1234567890/abcdef",
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
