import timeit

def verification(value) -> int:
    values = 1

    while value > 1:
        if value % 2 == 0:
            value = value // 2
        else:
            value = ((3 * value) + 1)

        values += 1
    return values

max_length = 0
number = 0
    
for i in range(0, 1000000):
    length = verification(i)
    if length > max_length:
        max_length = length
        number = i


if __name__ == "__main__":
    execution_time = timeit.timeit("main()", setup="from __main__ import main", number=1)
    print(f"The number with the longest sequence is {number} with {max_length} items in the sequence.")
    print(f"Execution time: {execution_time:.2f} seconds")
