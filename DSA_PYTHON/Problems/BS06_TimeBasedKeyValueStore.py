# REF : https://leetcode.com/problems/time-based-key-value-store/
# NOTES :
#       Get method will use binary search becasue as per timestamp property
#       list will in sorted order and what needs to find is given (<=timestamp)

# T: Set - O(1)
#    Get - O(logn)
# S: O(keys + values)

class TimeMap:

    def __init__(self):
        self.store = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.store:
            self.store[key] = []
        self.store[key].append([value, timestamp])

    def get(self, key: str, timestamp: int) -> str:

        if key not in self.store:
            return ""

        values = self.store.get(key, [])

        if not values:
            return ""

        res = ""
        l, r = 0, len(values) - 1
        while l <= r:
            m = (l + r) // 2
            if values[m][1] == timestamp:
                return values[m][0]
            if values[m][1] < timestamp:
                res = values[m][0]
                l = m + 1
            else:
                r = m - 1
        return res

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)


def main():
    pass


if __name__ == "__main__":
    main()