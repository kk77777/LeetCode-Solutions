class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        min_diff=arr[1]-arr[0]
        diff=[[arr[0],arr[1]]]
        for i in range(1,len(arr)-1):
            if min_diff>(arr[i+1]-arr[i]):
                diff=[]
                temp=[arr[i],arr[i+1]]
                diff.append(temp)
                min_diff=arr[i+1]-arr[i]
            elif min_diff==arr[i+1]-arr[i]:
                temp=[arr[i],arr[i+1]]
                diff.append(temp)
        return diff
