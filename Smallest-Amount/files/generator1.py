import random
import sys

def generate_random_tree(size, min_value, max_value, seed=None):
    random.seed(seed)
    return [round(random.uniform(min_value, max_value)) for _ in range(size)]

def print_input(tree, N):
    print(N)
    print(*tree)

if __name__ == "__main__":
    N = int(sys.argv[1])
    min_value = int(sys.argv[2])
    max_value = int(sys.argv[3])
    seed = int(sys.argv[4])

    tree = generate_random_tree(N, min_value, max_value, seed)
    print_input(tree, N)
