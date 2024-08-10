# REF : https://leetcode.com/problems/course-schedule/
# Topological sort
# For cycle detection - there will be no vertex with 0 in-degree.
#       so queue will be empty
# NOTE : keeping track of visited vertices will give the topological sort order

from collections import defaultdict, deque
class Solution4:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:

        in_degree = {i: 0 for i in range(numCourses)}
        adj_list = defaultdict(list)

        for c, p in prerequisites:
            adj_list[c].append(p)
            in_degree[p] += 1

        q = deque()

        for key in in_degree:
            if in_degree[key] == 0:
                q.append(key)

        visited = 0
        while q:
            visited += 1
            vertex = q.popleft()
            for nei in adj_list[vertex]:
                in_degree[nei] -= 1
                if in_degree[nei] == 0:
                    q.append(nei)

        return visited == numCourses


def main():
    courses = 6
    pre_req = [[0,5], [0,1], [1,2], [1,3], [2,4], [3,4]]            # True
    # pre_req = [[0,5], [0,1], [1,2], [1,3], [2,4], [3,4], [3,0]]     # False, cycle is present

    print("can finish : {}".format(Solution4().canFinish(courses, pre_req)))

if __name__ == '__main__':
    main()