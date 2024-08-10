# REF : https://leetcode.com/problems/course-schedule-ii/
# NOTES : it is same as course schedule I but now we need to print order also.

from collections import defaultdict

class Solution3:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> list:

        def dfs(crs):
            if visit[crs] == 0:
                return False

            if visit[crs] == 1:
                return True

            visit[crs] = 0
            for nei in adj_list[crs]:
                if not dfs(nei):
                    return False

            visit[crs] = 1
            output.append(crs)                      # course schedule II
            return True

        output = []                                 # course schedule II
        adj_list = defaultdict(list)
        for c, p in prerequisites:
            adj_list[c].append(p)

        visit = [-1 for _ in range(numCourses)]
        for crs in range(numCourses):
            if visit[crs] == -1 and not dfs(crs):
                return []                           # course schedule II
        return output                               # course schedule II


def main():
    courses = 6
    pre_req = [[0,5], [0,1], [1,2], [1,3], [2,4], [3,4]]            # True
    # pre_req = [[0,5], [0,1], [1,2], [1,3], [2,4], [3,4], [3,0]]     # False, cycle is present

    print("can finish : {}".format(Solution3().canFinish(courses, pre_req)))


if __name__ == '__main__':
    main()