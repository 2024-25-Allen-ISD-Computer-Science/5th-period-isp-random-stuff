import yfinance as yf
import math
import json
import os

TRADES_FILE = "trades.json"
MONEY_FILE = "money.json"

ORIGINAL = 8000
balance = ORIGINAL

if os.path.exists(MONEY_FILE):
    with open(MONEY_FILE, "r") as file:
        thing = json.load(file)
        ORIGINAL = thing[0]["original"]
        balance = thing[0]["balance"]
else:
    with open(MONEY_FILE, "w") as file:
        thing = [{"original": ORIGINAL, "balance": balance}]
        json.dump(thing, file, indent=4)

def load_trades():
    if os.path.exists(TRADES_FILE):
        with open(TRADES_FILE, "r") as file:
            return json.load(file)
    return []

def load_covered(fole="covers.json"):
    if os.path.exists(fole):
        with open(fole, "r") as file:
            return json.load(file)
    return []

def save_trades(trades):
    with open(TRADES_FILE, "w") as file:
        json.dump(trades, file, indent=4)

def get_stock_price(symbol):
    stock = yf.Ticker(symbol)
    return stock.history(period="1d")['Close'].iloc[-1]

def short_stock(symbol, percent, inot=8000):
    
    
    current_price = get_current_value(symbol)

    historical_prices = get_historical_data(symbol)
    
    
    history = list(historical_prices)

    price_change = (current_price - history[-1]) / history[-1] if len(history) > 1 else 0


    global balance
    price = get_stock_price(symbol)
    amount = math.floor((inot * percent) / price)
    balance -= amount * price
    if amount != 0:
        trade = {"symbol": symbol, "amount": amount, "price": price, "time": get_time(), "price_change": price_change}
        trades = load_trades()
        trades.append(trade)
        save_trades(trades)
    print(f"shorted {symbol} with {amount} stocks for ${round(price, 3)} per stock, spent ${round(amount * price, 3)} in total")

def check():
    trades = load_trades()
    total = balance

    for trade in trades:
        current = get_stock_price(trade["symbol"])
        initial = trade["price"]
        invested = trade["amount"] * trade["price"]
        invested += invested - (invested * (current / initial))
        total += invested
    
    
    print(f"{round(100 * ((total - ORIGINAL) / ORIGINAL), 3)}% return. your account is worth ${round(total, 3)}, you invested {ORIGINAL} initially")


def cover_stock(symbol, percent): # percent has to be < 1.0
    current_price = get_current_value(symbol)

    historical_prices = get_historical_data(symbol)
    
    
    history = list(historical_prices)

    price_change = (current_price - history[-1]) / history[-1] if len(history) > 1 else 0
    thng = {"symbol": symbol,"price": current_price, "time": get_time(), "price_change": price_change}
    arr = load_covered()
    arr.append(thng)
    with open("covers.json", "w") as file:
        json.dump(arr, file, indent=4)

    global balance
    trades = load_trades()
    symtrades = []
    current = get_stock_price(symbol)
    amount = 0

    for trade in trades:
        if trade["symbol"] == symbol:
            symtrades.append(trade)
            trades.remove(trade)

    for trade in symtrades:
        amount += trade["amount"]

    amount *= percent
    init = amount
    def sortByPrice(thing):
        thing = thing["price"]
        return thing
    
    symtrades = sorted(symtrades, key=sortByPrice, reverse=True)
    
    for trade in symtrades:
        if trade["amount"] >= amount: # amount is wholly removed from this trade, investment = amount*trade["price"]
            investment = amount * trade["price"]
            add = (2*investment) - (investment * (current / trade["price"]))
            balance += add
            trade["amount"] -= amount
            amount = 0
        else: # in this case, trade["amount"] is drained by amount meaning that the investment = trade["amount"]*trade["price"]
            investment = trade["amount"] * trade["price"]
            add = (2*investment) - (investment * (current / trade["price"]))
            balance += add
            amount -= trade["amount"]
            trade["amount"] = 0

        if trade["amount"] == 0:
            symtrades.remove(trade)

    for trade in symtrades:
        trades.append(trade)
    save_trades(trades)
    print(f"covered {init} of {symbol}")




