import random
from collections import Counter
from typing import List, Tuple

class RangeModeGenerator:
    def __init__(self,
                 min_n: int = 1,
                 max_n: int = 100000,
                 min_m: int = 1,
                 max_m: int = 10000,
                 min_val: int = 1,
                 max_val: int = 1000):
        """
        Initialize the generator with constraints

        Args:
            min_n: Minimum length of sequence
            max_n: Maximum length of sequence
            min_m: Minimum number of queries
            max_m: Maximum number of queries
            min_val: Minimum value in sequence
            max_val: Maximum value in sequence
        """
        self.min_n = min_n
        self.max_n = max_n
        self.min_m = min_m
        self.max_m = max_m
        self.min_val = min_val
        self.max_val = max_val

    def generate_sequence(self) -> Tuple[int, List[int]]:
        """Generate a random sequence of integers"""
        n = random.randint(self.min_n, self.max_n)
        sequence = [random.randint(self.min_val, self.max_val) for _ in range(n)]
        return n, sequence

    def generate_queries(self, n: int) -> Tuple[int, List[Tuple[int, int]]]:
        """Generate random range queries"""
        m = random.randint(self.min_m, self.max_m)
        queries = []
        for _ in range(m):
            # Generate start and end points, ensuring start <= end
            start = random.randint(1, n)
            end = random.randint(start, n)
            queries.append((start, end))
        return m, queries

    def find_mode_in_range(self, sequence: List[int], start: int, end: int) -> int:
        """Find the most frequent element in the given range"""
        # Convert to 0-based indexing for slicing
        subsequence = sequence[start-1:end]
        # Count frequencies
        counter = Counter(subsequence)
        # Find the most frequent element
        # If there are multiple modes, return the smallest one
        mode = min(counter.items(), key=lambda x: (-x[1], x[0]))[0]
        return mode

    def generate_test_case(self) -> Tuple[str, str]:
        """Generate complete test case with input and output"""
        # Generate sequence
        n, sequence = self.generate_sequence()

        # Generate queries
        m, queries = self.generate_queries(n)

        # Prepare input string
        input_str = f"{n} {m}\n"
        input_str += " ".join(map(str, sequence)) + "\n"
        input_str += "\n".join(f"{start} {end}" for start, end in queries)

        # Generate answers
        answers = []
        for start, end in queries:
            mode = self.find_mode_in_range(sequence, start, end)
            answers.append(str(mode))

        # Prepare output string
        output_str = "\n".join(answers)

        return input_str, output_str

    def save_test_case(self, filename_prefix: str = "rangemode"):
        """Save generated test case to input and output files"""
        input_str, output_str = self.generate_test_case()

        # Save input file
        with open(f"{filename_prefix}.in", "w") as f:
            f.write(input_str)

        # Save output file
        with open(f"{filename_prefix}.out", "w") as f:
            f.write(output_str)

# Example usage
def generate_sample_cases(num_cases: int = 5):
    """Generate multiple test cases with different sizes"""
    generators = [
        # Small test case
        # RangeModeGenerator(min_n=5, max_n=10, min_m=3, max_m=5, min_val=1, max_val=10),
        # Medium test case
        # RangeModeGenerator(min_n=100, max_n=1000, min_m=10, max_m=50, min_val=1, max_val=100),
        # Large test case
        RangeModeGenerator(min_n=10000, max_n=100000, min_m=1000, max_m=10000, min_val=1, max_val=1000)
    ]

    for i in range(num_cases):
        generator = random.choice(generators)
        generator.save_test_case(f"rangemode{i+1}")

if __name__ == "__main__":
    # Generate sample test cases
    generate_sample_cases(1)
    print("Test cases generated successfully!")