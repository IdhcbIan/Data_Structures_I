


def mult(a,b):
    if a == 0:
        return 0
    sum =  mult((a-1), b) + b
    
    return sum 

print(mult(4,6))




