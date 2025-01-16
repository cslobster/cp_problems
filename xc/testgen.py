import subprocess
import random
import time
from io import StringIO


def generate_test_input():
    n = 200000
    m = 200000
    k = 200000

    # Create a StringIO object to accumulate the test input as a string
    input_str = StringIO()
    input_str.write(f"{n} {m} {k}\n")

    for _ in range(k):
        p = random.randint(1, n)
        x = random.randint(1, m)

        # Ensure q is not equal to p
        while True:
            q = random.randint(1, n)
            if q != p:
                break

        y = random.randint(1, m)
        input_str.write(f"{p} {x} {q} {y}\n")

    # Get the accumulated input as a string
    return input_str.getvalue()

def run_test(executable, input_str):
    # Start the subprocess with subprocess.PIPE for stdin and stdout
    process = subprocess.Popen(
        [executable],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    # Send the input string to the subprocess's stdin
    stdout, stderr = process.communicate(input=input_str)

    return stdout

def main():
    executable1 = "./cmake-build-debug/w19p2"
    executable2 = "./cmake-build-debug/xc"
    test_count = 0

    while True:
        test_count += 1
        print(f"Running test #{test_count}")

        # Generate test input to file
        input = generate_test_input()

        # Run both executables using the input file
        output1 = run_test(executable1, input)
        output2 = run_test(executable2, input)

        # Compare outputs
        if output1 != output2:
            print("Found different outputs!")
            print("Check input.txt for the input that caused different outputs")
            print("\nOutput from program1:")
            print(output1)
            print("\nOutput from program2:")
            print(output2)
            with open("input.txt", "w") as f:
                f.write(input)
            # Save outputs to files
            with open("output1.txt", "w") as f:
                f.write(output1)
            with open("output2.txt", "w") as f:
                f.write(output2)
            break

        if test_count % 100 == 0:
            print(f"Completed {test_count} tests")

        time.sleep(0.01)


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nTesting stopped by user")
    except Exception as e:
        print(f"Error occurred: {e}")