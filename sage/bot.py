import os
from dotenv import load_dotenv
import discord
import time

idc = 1354714288140583094

load_dotenv()
TOKEN = os.getenv("DISCORD_TOKEN")

intents = discord.Intents.default()
intents.message_content = True
client = discord.Client(intents=intents)


def send_msg(stuff):
    @client.event
    async def on_ready():
        channel = client.get_channel(idc)
        if channel:
            await channel.send(stuff)
            await client.close()
    client.run(TOKEN)
