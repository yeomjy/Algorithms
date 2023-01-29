import sys
from collections import deque

inp = sys.stdin

if __name__ == "__main__":
    tc = int(inp.readline())

    for i in range(1, tc + 1):

        p, n = map(int, inp.readline().strip().split())

        adj = {}

        for _ in range(p):
            names = inp.readline().strip().split(",")
            n1 = []
            for j in range(len(names) // 2):
                if j == len(names) // 2 - 1:
                    name = (
                        names[2 * j].strip()
                        + ", "
                        + (names[2 * j + 1].split(":")[0]).strip()
                    )
                else:
                    name = names[2 * j].strip() + ", " + names[2 * j + 1].strip()

                n1.append(name)
                if name not in adj:
                    adj[name] = []
                for j in range(len(n1)):
                    for k in range(len(n1)):
                        name1 = n1[j]
                        name2 = n1[k]

                        if name1 != name2:
                            if name2 not in adj[name1]:
                                adj[name1].append(name2)
                            if name1 not in adj[name2]:
                                adj[name2].append(name1)

            # names = inp.readline().strip().split(".,")
            # n1 = []
            # for j in range(len(names)):
            #     name = names[j].strip()
            #     if j == len(names) - 1:
            #         name = name.split(".:")[0]

            #     name += "."
            #     if name not in adj:
            #         adj[name] = []

            #     n1.append(name)

        order = []

        for j in range(n):
            name = inp.readline().strip()
            order.append(name)

        inverted_idx = {}
        for j, name in enumerate(set(list(adj.keys()) + list(order))):
            inverted_idx[name] = j

        for n in order:
            if n not in adj:
                adj[n] = []

        # print(inverted_idx)

        q = deque()
        distq = deque()
        # dist = np.zeros(len(inverted_idx))
        # marked = np.zeros(len(inverted_idx), dtype=bool)
        dist = []
        marked = []

        for j in range(len(inverted_idx)):
            dist.append(10000000)
            marked.append(False)

        # dist[inverted_idx["Erdos, P."]] = 0
        q.append("Erdos, P.")
        distq.append(0)
        marked[inverted_idx["Erdos, P."]] = True

        while len(q) > 0:
            v = q.popleft()
            d = distq.popleft()
            dist[inverted_idx[v]] = d

            for w in adj[v]:
                if not marked[inverted_idx[w]]:
                    marked[inverted_idx[w]] = True
                    q.append(w)
                    distq.append(d + 1)

        print(f"Scenario {i}")
        for n in order:
            d = dist[inverted_idx[n]]
            if d == 10000000:
                d = "infinity"
            else:
                d = int(d)
            print(f"{n} {d}")
