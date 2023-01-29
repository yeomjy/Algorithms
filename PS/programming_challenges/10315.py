import sys

debug = False


def make_int(a):
    if a == "T":
        a = 10
    elif a == "J":
        a = 11
    elif a == "Q":
        a = 12
    elif a == "K":
        a = 13
    elif a == "A":
        a = 14
    else:
        a = int(a)

    return a


def score(deck):
    deck.sort(key=lambda x: x[0])

    straight = True
    flush = True

    # hightest = deck[-1][0] if deck[0][0] != 1 else 15

    for i in range(4):
        if deck[i + 1][0] - deck[i][0] != 1:
            straight = False
            break

    first = deck[0][1]
    for i in range(4):
        if deck[i + 1][1] != first:
            flush = False
            break

    # if deck[0][0] == 1:
    #     deck[0] = (15, deck[0][1])
    #     deck.sort(key=lambda x: x[0])
    # for i in range(5):
    #     if deck[i][0] == 1:
    #         deck[i] = (15, deck[i][1])
    # deck.sort()
    highest = deck[-1][0]
    highcard = sum([deck[i][0] * (16**i) for i in range(5)])
    if straight and flush:
        if debug:
            print("Straight flush")
        return highest * (16**12)

    else:

        counter = {}
        for i in range(5):
            if deck[i][0] not in counter:
                counter[deck[i][0]] = 1
            else:
                counter[deck[i][0]] += 1
        three_ = None
        two_ = None

        for key, val in counter.items():
            if val >= 4:
                # Four Card
                # sc += key * (16**11)
                if debug:
                    print("Four card")
                return key * (16**11)

            elif val == 3:
                three_ = key

            elif val == 2:
                two_ = key

        # Full House
        if three_ is not None and two_ is not None:
            if debug:
                print("Full house")
            return three_ * (16**10)

        # Flush
        elif flush:
            if debug:
                print("Flush")
            return 1 * (16**9) + highcard

        elif straight:
            if debug:
                print("Straight")
            return highest * (16**8)

        # Three card
        elif three_ is not None:
            if debug:
                print("Three card")
            return three_ * (16**7)

        else:
            num_two = []
            for key, val in counter.items():
                if val == 2:
                    num_two.append(key)

            if len(num_two) == 2:
                # two_pair = (
                #     num_two[0]
                #     if num_two[0] == 1 or (num_two[0] > num_two[1] and num_two[1] != 1)
                #     else num_two[1]
                # )
                # two_pair = num_two[0] if num_two[0] > num_two[1] else num_two[1]
                two_pair = max(num_two)
                two_pair_low = min(num_two)
                if debug:
                    print("Two pair")
                return two_pair * (16**6) + two_pair_low * (16**5) + highcard
            elif len(num_two) == 1:
                if debug:
                    print("One pair")
                return num_two[0] * (16**5) + highcard
            else:
                if debug:
                    print("High card")
                return highcard


if __name__ == "__main__":

    while True:
        line = sys.stdin.readline().strip()
        if not line:
            break

        lines = line.strip().split()

        player_a = [(make_int(i[0]), i[1]) for i in lines[:5]]
        player_b = [(make_int(i[0]), i[1]) for i in lines[5:]]
        # print(player_a, player_b, sep=" | ")
        score_a = score(player_a)
        score_b = score(player_b)

        if score_a > score_b:
            print("Black wins.")
        elif score_a < score_b:
            print("White wins.")
        else:
            print("Tie.")
