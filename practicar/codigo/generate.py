from sympy import divisors, isprime
from sympy.ntheory.factor_ import divisor_count
import itertools
from math import factorial
from random import randint
# Function to generate highly composite numbers (approximation)
def generate_highly_composite_heuristic(limit, count):
    numbers = []
    
    # Known highly composite numbers (heuristic)
    highly_composite_approx = [1, 2, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360,
                               720, 840, 1260, 1680, 2520, 5040, 7560, 10080,
                               15120, 20160, 25200, 27720, 45360, 50400, 55440,
                               83160, 110880, 166320, 221760, 277200, 332640,
                               498960, 554400, 665280, 720720, 1081080, 1441440,
                               2162160, 2882880, 3603600, 4324320, 6486480,
                               7207200, 8648640]
    
    # Add factorials
    for i in range(1, 14):  # 13! is the largest factorial less than 10^9
        highly_composite_approx.append(factorial(i))
    
    # Generate products of small primes
    primes = [p for p in range(2, 30) if isprime(p)]
    for combo in itertools.product(primes, repeat=3):
        prod=limit+1
        while prod>limit:
            prod = combo[0]**randint(1,5) * combo[1]**randint(1,4) * combo[2]**randint(1,3)
            highly_composite_approx.append(prod)
    
    # Calculate the number of divisors for each number
    for num in highly_composite_approx:
        if num <= limit:
            numbers.append((num, divisor_count(num)))
    
    # Sort by number of divisors and get top `count`
    numbers = sorted(numbers, key=lambda x: x[1], reverse=True)[:count]
    
    return [num for num, _ in numbers]

# Parameters
limit = 10**9
top_n = 2000

# Generate the list
heuristic_numbers = generate_highly_composite_heuristic(limit, top_n)
print(1)
print(len(heuristic_numbers))
s=""
for i in heuristic_numbers:
	s+=str(i)+' '
print(s)

