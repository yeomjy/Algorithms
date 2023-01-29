import sys
#import numpy as np
#canvas = np.chararray((250, 250))
#canvas[:, :] = 'O'
canvas = []

for i in range(250):
    arr = []
    for j in range(250):
        arr.append('O')
    canvas.append(arr)

m = n = x = y = x1 = y1 = x2 = y2 = 0
color = 'O'
cmd = ''
filename = ''


def find_region(x, y, color, s):
    s.add((x, y))

    if (0 < y and (x, y-1) not in s and canvas[y - 1][x] == color):
        find_region(x, y - 1, color, s)
    if (y < n-1 and (x, y+1) not in s and canvas[y + 1][x] == color):
        find_region(x, y + 1, color, s)
    if (0 < x and (x-1, y) not in s and canvas[y][x - 1] == color):
        find_region(x - 1, y, color, s)
    if (x < m - 1 and (x+1, y) not in s and canvas[y][x + 1] == color):
        find_region(x+1, y, color, s)

if __name__ == "__main__":


    while (True):
        cmd = input()
        command = cmd.split()[0]
        if (command == 'X'):
            print()
            break


        if command == 'I':
            m, n = map(int, cmd[1:].split())

            for j in range(n):
                for i in range(m):
                    canvas[j][i] = 'O'

        elif command == 'C':
            for j in range(n):
                for i in range(m):
                    canvas[j][i] = 'O';

        elif command == 'L':
            x, y, color = cmd[1:].split()
            x = int(x)
            y = int(y)
            canvas[y-1][x-1] = color;

        elif command == 'V':
            x, y1, y2, color = cmd[1:].split()
            x, y1, y2 = int(x), int(y1), int(y2)

            for j in range(y1-1, y2):
                canvas[j][x-1] = color


        elif command == 'H':
            x1, x2, y, color = cmd[1:].split()
            x1, x2, y = int(x1), int(x2), int(y)
            for i in range(x1-1, x2):
                canvas[y-1][i] = color
        elif command == 'K':
            x1, y1, x2, y2, color = cmd[1:].split()
            x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)
            
            for j in range(y1-1, y2):
                for i in range(x1-1, x2):
                    canvas[j][i] = color;

        elif command == 'F':
            x, y, color = cmd[1:].split()
            x, y = int(x), int(y)

            coord_set = set()
            find_region(x-1, y-1, canvas[y-1][x-1], coord_set)

            for xx, yy in coord_set:
                canvas[yy][xx] = color;

        elif command == 'S':
            filename = cmd[2:].strip()
            print(filename)
            for j in range(n):
                for i in range(m):
                    sys.stdout.write(canvas[j][i])
                    
                sys.stdout.write('\n')
                sys.stdout.flush()

            
