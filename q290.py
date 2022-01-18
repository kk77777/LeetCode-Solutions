class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(words) != len(pattern):
            return False
        if len(set(words)) != len(set(pattern)):
            return False
        x = {}
        for i, w in enumerate(words):
            if w in x:
                if x[w] != pattern[i]:
                    return False
            else:
                x[w] = pattern[i]

        return True
