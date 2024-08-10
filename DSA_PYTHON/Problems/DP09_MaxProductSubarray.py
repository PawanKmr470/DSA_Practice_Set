class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        res = max(nums)
        curMax = 1
        curMin = 1

        for n in nums:
            if n == 0:
                curMax, curMin = 1, 1
                continue

            tmp = n * curMax
            curMax = max(n * curMax, n * curMin) # why ,n was necessary in video
            curMin = min(tmp, n * curMin)

            res = max(res, curMax)

        print("Max product subarray : {}".format(res))
        return res


def main():
    s = Solution()
    s.maxProduct([2,3,-2,4])
    return


if __name__ == "__main__":
    main()