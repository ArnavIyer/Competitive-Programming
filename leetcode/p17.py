class Solution:
    def __init__(self):
        self.key = [['a','b','c'],['d','e','f'],['g','h','i'],['j','k','l'],['m','n','o'],['p','q','r','s'],['t','u','v'],['w','x','y','z']]
        self.letterlist = []
    def recurse(self, count, word, numbah):
        if count==len(numbah):
            self.letterlist.append(word)
        else:
            for i in self.key[numbah[count]-2]:
                word2 =word+i
                self.recurse(count+1, word2, numbah)
    def letterCombinations(self, digits: str) -> List[str]:
        numbah = []
        for i in digits:
            numbah.append(int(i))
        if len(numbah)!=0:
            self.recurse(0,"", numbah)        
        return self.letterlist