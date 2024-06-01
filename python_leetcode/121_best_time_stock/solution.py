"""
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and
choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.
"""


def maxprofit(prices):
    l, r = 0, 1  # left pointer buys, right pointer sells
    maxprofit = 0

    while r < len(prices):
        # is it profitable?
        if prices[r] > prices[l]:
            profit = prices[r] - prices[l]
            maxprofit = max(maxprofit, profit)
        else:
            l = r
        r += 1
    return maxprofit


prices1 = [7, 1, 5, 3, 6, 4]
print(maxprofit(prices1))
