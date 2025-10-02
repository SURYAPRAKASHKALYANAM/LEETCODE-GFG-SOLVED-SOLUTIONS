class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk = numBottles;
        int empty = numBottles;
        numBottles = 0;
        while (empty >= numExchange) {
            empty -= numExchange;
            numBottles++;
            numExchange++;
            if (numBottles) {
                empty += numBottles;
                drunk += numBottles;
                numBottles = 0;
            }
        }
        return drunk;
    }
};