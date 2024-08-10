# REF : https://leetcode.com/problems/meeting-rooms-ii/
# NOTES:
#       Min heap can also be brute force solution (sorting + heap = O(nlogn) + O(logn))

# T: O(nlogn)
# S: O(n)   due to start and end array

class Solution:
    def canAttendMeetings(self, intervals: list[list[int]]) -> bool:
        if not intervals:
            return False

        start = sorted([i[0] for i in intervals])
        end = sorted([i[1] for i in intervals])

        s, e = 0, 0
        count, result = 0, 0
        while s < len(intervals):
            if start[s] < end[e]:
                s += 1
                count += 1
            else:                   # in == case, next meeting can start. No extra room
                e += 1              # so reduce the counter
                count -= 1
            result = max(result, count)

        return result


def main():
    intervals = [[0,30],[5,10],[15,20]]
    print("min rooms required : {}".format(Solution().canAttendMeetings(intervals)))

if __name__ == "__main__":
    main()