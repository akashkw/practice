from collections import deque

if __name__ == '__main__':
    height, width, walls = tuple(map(int, input().split()))
    visited_nodes, open_spots = (0, 0)

    maze = [[None for j in range(width)] for i in range(height)]
    visited = [[False for j in range(width)] for i in range(height)]
    start = None

    for i in range(height):
        line = list(input())
        for j in range(width):
            if line[j] == '.':
                maze[i][j] = 'X'
                open_spots += 1
                start = (i, j)
            else:
                maze[i][j] = line[j]
    
    stack = deque()
    stack.append(start)
    
    while stack:
        i, j = stack.pop()
        if i < 0 or i >= height or j < 0 or j >= width or visited[i][j] or visited_nodes == open_spots - walls:
            continue
        if(maze[i][j] == 'X'):
            maze[i][j] = '.'
            visited[i][j] = True
            visited_nodes += 1
            stack.append((i, j-1))
            stack.append((i, j+1))
            stack.append((i-1, j))
            stack.append((i+1, j))
        
    for row in maze:
        print("".join(row))

