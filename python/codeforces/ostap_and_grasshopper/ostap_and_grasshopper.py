from collections import deque

if __name__ == '__main__':
    found = False
    num_cells, jump_length = tuple(map(int, input().strip().split()))
    line = input().strip()
    target = line.find('T')
    visited = set()
    queue = deque()
    queue.appendleft(line)
    while queue:
        line = queue.pop()
        visited.add(line)
        g_idx = line.find('G')
        if g_idx + jump_length == target or g_idx - jump_length == target:
            found = True
            break
        if g_idx + jump_length < len(line) and line[g_idx+jump_length] != '#':
            new_line = list(line)
            new_line[g_idx] = '.'
            new_line[g_idx+jump_length] = 'G'
            new_line = ''.join(new_line)
            if new_line not in visited:
                queue.appendleft(new_line)
        if g_idx - jump_length >= 0 and line[g_idx-jump_length] != '#':
            new_line = list(line)
            new_line[g_idx] = '.'
            new_line[g_idx-jump_length] = 'G'
            new_line = ''.join(new_line)
            if new_line not in visited:
                queue.appendleft(new_line)
    if found:
        print("YES")
    else:
        print("NO")
    
