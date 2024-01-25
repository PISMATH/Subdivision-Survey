def find_and_print_combinations_for_total(total):
    # Initialize a list of lists where each sublist will hold combinations that sum to an index value
    dp = [[] for _ in range(total + 1)]
    dp[0] = [[]]  # Base case: one way to make a sum of 0 (with no numbers)

    # Iterate through each number from 1 to 9
    for num in range(1, 100):
        # Iterate through all possible totals from 'num' to 'total'
        for t in range(num, total + 1):
            # For each way to make a sum of t - num, add 'num' to that combination
            for prev in dp[t - num]:
                # Avoid duplicates by enforcing non-decreasing order in combinations
                if not prev or num >= prev[-1]:
                    dp[t].append(prev + [num])

    # Print combinations for the specific total
    print(f"Total = {total}: {len(dp[total])}")
    for combo in dp[total]:
        pass
        #print(f"  - {' + '.join(map(str, combo))}")
    #print()

def main():
    for total in range(1, 100):
        find_and_print_combinations_for_total(total)

main()
