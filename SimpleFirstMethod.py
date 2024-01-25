from itertools import combinations_with_replacement

def find_and_print_combinations_for_total(total):
    combinations = [combo for i in range(1, total + 1) 
                    for combo in combinations_with_replacement(range(1, 10), i)
                    if sum(combo) == total]
    print(f"Total = {total}: {len(combinations)}")
    for combo in combinations:
        formatted_combination = ' + '.join(map(str, combo))
        #print(f"  - {formatted_combination}")
    #print()

def main():
    for total in range(1, 100):
        find_and_print_combinations_for_total(total)

main()
