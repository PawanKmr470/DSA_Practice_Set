def is_prime(num):
    if num <= 1:
        return False

    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True


def cal_prime(nums):
    result = []
    for x in nums:
        if is_prime(x):
            result.append(x)
    return result


arr = [45, 41, 33, 17, 66, 99, 19, 32, 2, -1, -67]

out = cal_prime(arr)
print(out)














