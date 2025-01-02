import random
import subprocess
def generate_input(N, M, max_T, max_P):
    T = [random.randint(1, max_T) for _ in range(N)]
    P = [random.randint(1, max_P) for _ in range(N)]
    return N, M, T, P

def maximize_money(N, M, T, P):
    # Brute force solution
    def dfs(remaining_time, current_money, index):
        if index == N or remaining_time <= 0:
            return current_money

        # Skip the current job
        max_money = dfs(remaining_time, current_money, index + 1)

        # Take the current job as many times as possible within the remaining time
        if T[index] <= remaining_time:
            max_money = max(max_money, dfs(remaining_time - T[index], current_money + P[index], index))

        return max_money

    return dfs(M, 0, 0)

def main():
    # Input constraints
    N = random.randint(1, 10)   # Number of jobs (smaller for brute force)
    M = random.randint(1, 100)  # Max time Alex can work (smaller for brute force)
    max_T = 10                  # Max completion time for any job
    max_P = 100000000                 # Max payment for any job

    # Generate input
    N, M, T, P = generate_input(N, M, max_T, max_P)

    # Print input
    print(N, M)
    print(" ".join(list(map(str,T))))
    print(" ".join(list(map(str,P))))
    data = str(N) + " " + str(M) + "\n" + " ".join(list(map(str,T))) + "\n" + " ".join(list(map(str,P))) + "\n"
    subprocess.run("pbcopy", text=True, input=data)

    # Compute and print output
    result = maximize_money(N, M, T, P)
    print("Maximum money Alex can make:", result)

if __name__ == "__main__":
    main()
