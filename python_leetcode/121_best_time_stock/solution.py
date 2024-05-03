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
