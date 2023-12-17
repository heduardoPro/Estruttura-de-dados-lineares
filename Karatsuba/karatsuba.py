def Karatsuba(x, y):
    if (x < 10 or y < 10) or (x ):
        return x * y

    number = max(len(str(x)), len(str(y)))
                 
    result = number // 2

    x_high, x_low = divmod(x, 10**result)
    y_high, y_low = divmod(y, 10**result)

    z0 = Karatsuba(x_low, y_low)
    z1 = Karatsuba((x_low + x_high), (y_low + y_high))
    z2 = Karatsuba(x_high, y_high)

    return z2 * 10**(2 * result) + ((z1 - z2 - z0) * 10**result) + z0

    