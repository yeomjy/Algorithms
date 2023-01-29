import sys


def traverse(words, mapping, corpus):
    # Check that two different char maps to one char
    if len(mapping.keys()) != len(set(mapping.values())):
        return None
    if len(words) == 0:
        return [mapping]

    else:
        word = words[0]
        # print(word)
        map_list = []

        l = len(word)
        if l not in corpus:
            return None
        # print(mapping)
        for orig in corpus[l]:
            # Check that word -> orig success
            for i in range(len(word)):
                if word[i] in mapping and mapping[word[i]] != orig[i]:
                    continue
                elif word[i] not in mapping and orig[i] in mapping.values():
                    continue

            new_map = mapping.copy()
            success = True
            for i in range(len(word)):
                if word[i] in new_map and new_map[word[i]] != orig[i]:
                    success = False
                    break

                new_map[word[i]] = orig[i]

            if not success:
                continue

            # print(f"New map: {word} -> {orig}")

            next_ = traverse(words[1:], new_map, corpus)
            if next_ is not None:
                map_list += next_

        if len(map_list) == 0:
            return None
        else:
            return map_list


if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())

    dict_ = {}

    for i in range(n):
        word = sys.stdin.readline().strip()
        l = len(word)
        if l not in dict_:
            dict_[l] = set()
        dict_[l].add(word)

    while True:
        crypt_dict = {}
        line = sys.stdin.readline().strip()
        if not line:
            break

        words = line.split(" ")

        # Grouping words with key = length
        for word in words:
            l = len(word)
            if l not in crypt_dict:
                crypt_dict[l] = set()

            crypt_dict[l].add(word)

        crypted = True
        mapping = {}
        # print("END")
        # for l in crypt_dict.keys():
        #     crypt_set = crypt_dict[l]
        #     if l not in dict_:
        #         crypted = False
        #         break

        result = traverse(sorted(list(set(words)), reverse=True), mapping, dict_)
        if result is None or len(result) == 0:
            crypted = False
        else:
            mapping = result[0]

        if not crypted:
            ans = " ".join(["*" * len(i) for i in words])

        else:
            ans = " ".join(["".join([mapping[j] for j in i]) for i in words])

        print(ans)
