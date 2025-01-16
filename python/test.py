from itertools import permutations

MOD = 998244353

def calculate_lds(sequence):
    # Function to calculate the length of the Longest Decreasing Subsequence (LDS)
    n = len(sequence)
    dp = [1] * n  # dp[i] stores the length of the LDS ending at index i

    for i in range(1, n):
        for j in range(i):
            if sequence[j] > sequence[i]:
                dp[i] = max(dp[i], dp[j] + 1)

    # The LDS length is the maximum value in dp
    return max(dp)

def count_permutations_with_lds_less_than_2(n, counts):
    # Build the list of numbers based on counts
    sequence = []
    for i in range(1, n + 1):
        sequence.extend([i] * counts[i - 1])

    # Generate all unique permutations of the sequence
    permutations_list = set(permutations(sequence))
    valid_count = 0

    # Count permutations that have LDS < 2
    for perm in permutations_list:
        # print(perm, calculate_lds(perm))
        if calculate_lds(perm) <= 2:
            valid_count += 1
            print(perm)

    return valid_count % MOD

# Example Test Data
n = 3
counts = [2, 1, 1]
  # Example: sequence [1, 2, 2, 3, 4, 4, 4]
result = count_permutations_with_lds_less_than_2(n, counts)
print("Number of permutations with LDS < 2:", result)



"""
1: 3
3112
3121

2131
2113

2: 3
3: 2
4: 1


"""