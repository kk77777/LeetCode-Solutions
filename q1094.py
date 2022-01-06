class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        stops=[0]*1001
        for i in trips:
            stops[i[1]]+=i[0]
            stops[i[2]]-=i[0]
        j=0
        while j<1001 and capacity>=0:
            capacity-=stops[j]
            j+=1
        return capacity>=0
            
