class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:

        n = len(gas)

        remFuel, sm, start = 0, 0, 0

        for i in range(0, n):
            remFuel += gas[i]-cost[i]
            sm += gas[i]-cost[i]
            if remFuel < 0:
                start = i+1
                remFuel = 0

        return start if sm >= 0 else -1
