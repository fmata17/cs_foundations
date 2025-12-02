# Bessie likes to watch shows on Mooloo. Because Bessie is a busy cow, she has planned a schedule for the
# next N (1≤N≤105) days that she will watch Mooloo. Because Mooloo is a paid subscription service,
# she now needs to decide how to minimize the amount of money she needs to pay.

# Mooloo has an interesting subscription system: it costs d+K (1≤K≤109) moonies to subscribe to Mooloo
# for d consecutive days. You can start a subscription at any time, and you can start a new subscription
# as many times as you desire if your current subscription expires. Given this, figure out the minimum amount
# of moonies Bessie needs to pay to fulfill her schedule.

# INPUT FORMAT:
# The first line contains integers N and K.
# The second line contains N integers describing the days Bessie will watch Mooloo.

# OUTPUT FORMAT:
# Print the minimum amount of moonies Bessie needs to pay to fulfill her schedule.


def solution(n_days, K, days):
    total = 0

    start = days[0]
    prev = days[0]

    for i in range(1, n_days):
        gap = days[i] - prev - 1

        if gap > K:
            total += (prev - start + 1) + K
            start = days[i]

        prev = days[i]

    total += (prev - start + 1) + K
    return total


def main():
    n = 2
    k = 3
    days = [1, 10]
    s = solution(n, k, days)
    print(s)


if __name__ == "__main__":
    main()
