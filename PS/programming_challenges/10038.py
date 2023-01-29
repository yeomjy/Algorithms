import sys

if __name__ == "__main__":
    while True:
        line = sys.stdin.readline()
        if not line:
            break
        s = set()
        l = list(map(int, line.split()))
        n = l[0]
        l = l[1:]
        count = 0

        for i in range(n - 1):

            diff = l[i + 1] - l[i]
            if diff < 0:
                diff = -diff

            if diff >= n or diff == 0:
                continue

            if diff not in s:
                s.add(diff)
                count += 1

        if count == n - 1:
            print("Jolly")

        else:
            print("Not Jolly")
