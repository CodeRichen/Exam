import random
import string

def generate_random_string(length=8):
    return ''.join(random.choices(string.ascii_letters + string.digits, k=length))

def generate_data(entries=300):
    for _ in range(entries):
        rand_str = generate_random_string()
        rand_num = random.randint(0, 9999)
        print(f"{rand_str} {rand_num}")

generate_data()
