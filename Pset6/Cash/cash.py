from cs50 import get_float


change = get_float("Change owed: ")
while(change < 0):
    change = get_float("Change owed: ")

cents = round(change * 100)
coins = 0
q = int(cents / 25) #so that the result of the divison is the number of coins needed
cents %= 25  #the remainder of the division is the chnage needed to be formed with other coins

d = int(cents / 10)
cents %= 10

c = int(cents / 5)
cents %= 5

n = cents
coins = q + d + c + n
print(coins)