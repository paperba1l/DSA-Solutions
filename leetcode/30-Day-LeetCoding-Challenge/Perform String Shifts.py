class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        amt = 0
        for e in shift:
            # print(e[0], s[1])
            if e[0]==0:
                amt += e[1]
            else:
                amt -= e[1]
        
        sht = (amt+len(s))%len(s)
        
        # print(sht)
        return s[sht:]+s[:sht]