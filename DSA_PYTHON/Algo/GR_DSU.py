# REF : https://cp-algorithms.com/data_structures/disjoint_set_union.html#union-by-size-rank

class Solution:
    def countComponents(self, n: int, edges: list[list[int]]) -> int:
        parent = [i for i in range(n)]
        rank = [1] * n

        def find(n):
            res = n
            while res != parent[res]:
                parent[res] = parent[parent[res]]   # Path compresssion
                res = parent[res]
            return res

        def union(n1, n2):

            p1 = find(n1)
            p2 = find(n2)

            if p1 == p2:
                return 0

            if rank[p1] < rank[p2]:     # if p2's rank is greater, then assign p2 to p1 (swap)
                p1, p2 = p2, p1
            parent[p2] = p1             # making p1 parent as p1 has greater rank
            rank[p1] += rank[p2]        # whoever has become parent, increase rank. Here it's p1 as per prev line

            return 1

        result = n
        for n1, n2 in edges:
            result -= union(n1, n2)
        return result


def main():
    n = 5
    edges = [[0,1],[1,2],[3,4]]

    print("No of components : {}".format(Solution().countComponents(n, edges)))

if __name__ == '__main__':
    main()