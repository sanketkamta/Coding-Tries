class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.isEndOfWord = False


class Trie:
    def __init__(self):
        self.root = self.getNode()

    def getNode(self):
        return TrieNode()

    def insert(self, key):
        pCrawl = self.root
        n = len(key)
        for i in range(n):
            index = ord(key[i]) - ord('a')
            if not pCrawl.children[index]:
                pCrawl.children[index] = self.getNode()
            pCrawl = pCrawl.children[index]
        pCrawl.isEndOfWord = True

    def search(self, item):
        n = len(item)
        pCrawl = self.root
        for i in range(n):
            index = ord(item[i]) - ord('a')
            if not pCrawl.children[index]:
                return False
            pCrawl = pCrawl.children[index]
        return pCrawl != None and pCrawl.isEndOfWord


def main():
    keys = ["the", "a", "there", "answer", "any", "by", "bye", "their"]
    output = ["No", "Yes"]
    t = Trie()
    for key in keys:
        t.insert(key)
    print(output[t.search("the")])
    print(output[t.search("these")])


if __name__ == '__main__':
    main()
