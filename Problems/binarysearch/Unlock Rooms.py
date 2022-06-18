class Solution:
    def solve(self, rooms):
        visited = []
        def dfs(i):
            visited.append(i)
            for room in rooms[i]:
                if room not in visited:
                    dfs(room)
        dfs(0)
        return len(rooms) == len(visited)
