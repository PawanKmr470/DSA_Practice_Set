# REF : https://leetcode.com/problems/course-schedule/
# NOTES :
# DFS to visit every node
# If visited node is encountered again then it's a loop, so return false
# DFS needs to be applied for each node as we want to check for each course
# visited node is removed because when dfs will start from 1 then it will be filled again
# prerequisites adj list is updated once and for all when first iteration is run

# T: O(V + E)
# S: O(V) due to hash set - visited

from collections import defaultdict, deque

# Neetcode solution
class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:

        def dfs(crs):
            if crs in visited:
                return False

            if adj_list[crs] == []:
                return True

            visited.add(crs)
            for pre in adj_list[crs]:
                if not dfs(pre):
                    return False

            visited.remove(crs)     # why ? because we can come to this vertex from parent via another path
                                    # and this vertex should be available to explore.
            adj_list[crs] = []     # This is we are solving once and for all. updating the end result/adjlist.
            return True


        adj_list = { i:[] for i in range(numCourses)}
        for course, pre in prerequisites:   # [[1,0]] -> [[course1, prereq], [course2, prereq]]
            adj_list[course].append(pre)

        visited = set()
        for crs in range(numCourses):
            if not dfs(crs):
                return False
        return True

# Solved but TLE
# traverse set/list is for detecting cycle and it's for keeping track which the dfs is going
class Solution1:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:

        def dfs(crs):
            if crs in traverse:
                return False

            traverse.add(crs)

            for nei in adj_list[crs]:
                if not dfs(nei):
                    return False

            traverse.remove(crs)
            return True


        adj_list = {i:[] for i in range(numCourses)}
        for c, p in prerequisites:
            adj_list[c].append(p)

        traverse = set()
        for crs in range(numCourses):
            if not dfs(crs):
                return False
        return True

# Solved. no TLE
# traverse set/list is for detecting cycle and it's for keeping track which the dfs is going
# visited set/list is for maintaining if the given course can be completed or not.
#       Once it is marked True, that means this course(vertex) can be completed
#       If marked False, means course can't be completed.
#       In first iteration, this visited set will be updated for all vertices and
#       in second iteration, this information can be re-used.
class Solution2:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:

        def dfs(crs):
            if crs in traverse:
                return False

            traverse.add(crs)

            for nei in adj_list[crs]:
                if nei not in visited and not dfs(nei):
                    return False

            traverse.remove(crs)
            visited.add(crs)
            return True

        adj_list = {i: [] for i in range(numCourses)}
        for c, p in prerequisites:
            adj_list[c].append(p)

        traverse = set()
        visited = set()
        for crs in range(numCourses):
            if crs not in visited and not dfs(crs):
                return False
        return True


# It's Solutin2 but using traverse and visited as a list
class Solution21:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        def dfs(crs):
            if traverse[crs]:   # Means it was made True earlier and path has come again at this vertex
                return False

            traverse[crs] = True    # Making vertex True if traversing it

            for nei in adj_list[crs]:
                if not visited[nei] and not dfs(nei):
                    return False

            traverse[crs] = False   # Unvisit the path
            visited[crs] = True     # store 'can be completed' status for each vertex
            return True


        adj_list = {i:[] for i in range(numCourses)}
        for c, p in prerequisites:
            adj_list[c].append(p)

        traverse = [False] * numCourses
        visited = [False] * numCourses
        for crs in range(numCourses):
            if not visited[crs] and not dfs(crs):
                return False
        return True


# One array visit to store both status traverse + visited
# Hence we need three status -1, 0, 1 OR 0, 1, 2 OR white, grey, black
# if node v has not been visited, then mark it as -1.
# if node v is being visited, then mark it as 0.
#       If we find a vertex marked as 0 in DFS, then there is a ring.
# if node v has been visited, then mark it as 1. If a vertex was marked as 1,
#       then this vertex is not part of any ring. Means 'can be completed' staus
class Solution3:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:

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
            return True

        adj_list = defaultdict(list)
        for c, p in prerequisites:
            adj_list[c].append(p)

        visit = [-1 for _ in range(numCourses)]
        for crs in range(numCourses):
            if visit[crs] == -1 and not dfs(crs):   # Added later "visit[crs] == -1 and"
                return False
        return True


# It's Solution3 only difference is that conditions are inside the for loop
class Solution31:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:

        def dfs(crs):

            # visiting the vertex
            visit[crs] = 0

            # visiting neighbours
            for nei in adj_list[crs]:
                if visit[nei] == 1:
                    continue

                if visit[nei] == 0:
                    return False

                if not dfs(nei):
                    return False

            # done visiting
            visit[crs] = 1
            return True

        adj_list = defaultdict(list)
        for c, p in prerequisites:
            adj_list[c].append(p)

        visit = [-1 for _ in range(numCourses)]
        for crs in range(numCourses):
            if visit[crs] == -1 and not dfs(crs):
                return False
        return True


# Topological sort
# For cycle detection - there will be no vertex with 0 in-degree.
#       so queue will be empty
# NOTE : keeping track of visited vertices will give the topological sort order
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

    print("can finish : {}".format(Solution().canFinish(courses, pre_req)))
    print("can finish : {}".format(Solution1().canFinish(courses, pre_req)))
    print("can finish : {}".format(Solution2().canFinish(courses, pre_req)))
    print("can finish : {}".format(Solution21().canFinish(courses, pre_req)))
    print("can finish : {}".format(Solution3().canFinish(courses, pre_req)))
    print("can finish : {}".format(Solution31().canFinish(courses, pre_req)))
    print("can finish : {}".format(Solution4().canFinish(courses, pre_req)))

if __name__ == '__main__':
    main()