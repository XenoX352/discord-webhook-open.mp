/*
    Discord Webhook Include for SA:MP (San Andreas Multiplayer)
    Version: 1.0.0
    License: MIT
    
    This include provides an easy-to-use function `SendDiscordEmbed()`
    to send rich embed messages to a Discord channel via webhook URL.
    
    Requirements:
        - Pawn Requests plugin by Southclaws
          (https://github.com/Southclaws/pawn-requests)
        - `requests.inc` must be included before this file
    
    Usage:
        SendDiscordEmbed(
            webhook_url,    // Discord webhook URL (string)
            bot_name,       // Username for the bot (string)
            bot_avatar,     // Avatar URL for the bot (string)
            title,          // Embed title (string, can be empty)
            description,    // Embed description (string, can be empty)
            color,          // Color integer (optional, default 0xFF9900)
            fields,         // Field data in format "Name|Value\nName|Value" (optional)
            footer          // Footer text (string, optional)
        );
    
    Example:
        SendDiscordEmbed(
            "https://discord.com/api/webhooks/...",
            "My Bot",
            "https://i.imgur.com/avatar.png",
            "Server Restarted",
            "The server has been restarted successfully.",
            0x00FF00,
            "Action|Restart\nBy|xenox",
            "My SA:MP Server"
        );
*/

#if defined _discord_webhook_included
    #endinput
#endif
#define _discord_webhook_included

#include <requests>

forward OnDiscordEmbedResponse(Request:id, E_HTTP_STATUS:status, data[], dataLen);
public OnDiscordEmbedResponse(Request:id, E_HTTP_STATUS:status, data[], dataLen)
{
    // if (node != Node:-1)
    //     JsonCleanup(node);
}

stock SendDiscordEmbed(
    const webhook_url[],
    const bot_name[],
    const bot_avatar[],
    const title[],
    const description[],
    color = 0xFF9900,
    const fields[] = "",
    const footer[] = ""
)
{
    new RequestsClient:client = RequestsClient(webhook_url);

    new Node:embed = JsonObject();

    if (strlen(title) > 0)
    {
        new tmpTitle[256];
        strcat(tmpTitle, title);
        JsonSetString(embed, "title", tmpTitle);
    }

    if (strlen(description) > 0)
    {
        new tmpDesc[512];
        strcat(tmpDesc, description);
        JsonSetString(embed, "description", tmpDesc);
    }

    if (color != 0)
        JsonSetInt(embed, "color", color);

    if (strlen(fields) > 0)
    {
        new Node:fieldsArray = JsonArray();
        new buf[512], name[128], value[128];
        new idx = 0;
        strcat(buf, fields);

        while (idx < strlen(buf))
        {
            new line[256], pos;
            pos = strfind(buf, "\n", true, idx);
            if (pos == -1)
                strmid(line, buf, idx, strlen(buf));
            else
                strmid(line, buf, idx, pos);
            idx = (pos == -1) ? strlen(buf) : pos + 1;

            new split = strfind(line, "|", true);
            if (split != -1)
            {
                strmid(name,  line, 0, split);
                strmid(value, line, split + 1, strlen(line));

                new Node:field = JsonObject(
                    "name",   JsonString(name),
                    "value",  JsonString(value),
                    "inline", JsonBool(true)
                );
                fieldsArray = JsonAppend(fieldsArray, field);
            }
        }
        JsonSetObject(embed, "fields", fieldsArray);
    }

    if (strlen(footer) > 0)
    {
        new Node:footerObj = JsonObject();
        new tmpFooter[128];
        strcat(tmpFooter, footer);
        JsonSetString(footerObj, "text", tmpFooter);
        JsonSetObject(embed, "footer", footerObj);
    }
    new Node:root = JsonObject();
    JsonSetObject(root, "embeds", JsonArray(embed));

    if (strlen(bot_name) > 0)
    {
        new tmpBotName[64];
        strcat(tmpBotName, bot_name);
        JsonSetString(root, "username", tmpBotName);
    }

    if (strlen(bot_avatar) > 0)
    {
        new tmpAvatar[256];
        strcat(tmpAvatar, bot_avatar);
        JsonSetString(root, "avatar_url", tmpAvatar);
    }

    new payload[2048];
    JsonStringify(root, payload, sizeof(payload));
    JsonCleanup(root);

    Request(client, "", HTTP_METHOD_POST, "OnDiscordEmbedResponse", payload, RequestHeaders("Content-Type", "application/json"));
}
