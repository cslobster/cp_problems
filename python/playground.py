import random
import subprocess
import os
path = "/Users/melissa/cp_problems//cf/cmake-build-debug/"
def generate():
    s = ""
    n = random.randint(900, 1000)
    h = random.randint(5, 1000)
    w = random.randint(5, 1000)
    s = str(n) + " " + str(h) + " " + str(w) + "\n"
    for i in range(n):
        s += str(random.randint(1, h)) + " " + str(random.randint(1, w)) + "\n"
    f = open(path + "in.in", "w")
    f.write(s)


def redirect_output(executable_path, output_file_path, args=None):
    try:
        # Ensure args is a list, even if None
        args = args or []

        # Open the output file in write mode
        with open(output_file_path, 'w') as output_file:
            # Run the executable with arguments and redirect its standard output to the file
            process = subprocess.run([executable_path] + args, stdout=output_file, stderr=subprocess.PIPE)
            #print(process.stderr.decode())
        #print(f"Output successfully {output_file_path}")
    except FileNotFoundError:
        print(f"Error: The executable '{executable_path}' was not found.")
    except subprocess.CalledProcessError as e:
        print(f"Error: The executable returned a non-zero exit code: {e.returncode}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

def files_are_same(file1, file2):
    try:
        with open(file1, 'r') as f1, open(file2, 'r') as f2:
            for line1, line2 in zip(f1, f2):
                if line1 != line2:
                    return False
            # Ensure no extra lines in either file
            return f1.read() == "" and f2.read() == ""
    except FileNotFoundError:
        print("One or both files do not exist.")
        return False

def test():
    generate()
    outfile1 = path + 'out.out'
    outfile2 = path + 'golden.out'
    redirect_output(path + "559C", outfile1, [])
    redirect_output(path + "cf", outfile2, [])
    if (not files_are_same(outfile1, outfile2)):
        return False
    return True

for i in range(1000):
    if not test():
        print("WRONG ", i)
        break
    else:
        # print("FINISHED TEST: ", i)
        continue
