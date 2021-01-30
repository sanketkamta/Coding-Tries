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

    def search(self, item, root):
        n = len(item)
        pCrawl = root
        for i in range(n):
            index = ord(item[i]) - ord('a')
            if not pCrawl.children[index]:
                return False
            pCrawl = pCrawl.children[index]
        return pCrawl != None and pCrawl.isEndOfWord

    def checkWordBreak(self, root, strr):
        n = len(strr)
        if n == 0:
            return True
        for i in range(1, n+1):
            if(self.search(strr[:i], root) and self.checkWordBreak(root, strr[i:])):
                return True
        return False

    def wordBreak(self, s):
        pNode = self.root
        if self.checkWordBreak(pNode, s):
            return True
        else:
            return False


def main():
    keys = ["the", "quick", "fox", "brown"]
    s = "thequickthe"
    t = Trie()
    for key in keys:
        t.insert(key)
    # print(output[t.search("the")])
    # print(output[t.search("these")])
    if t.wordBreak(s):
        print("Yes")
    else:
        print("No")


if __name__ == '__main__':
    main()
