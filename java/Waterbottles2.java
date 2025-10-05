public class Waterbottles2 {
    public static void main(String[] args) {
        int numBottles = 13;
        int numExchange = 6;
        System.out.println(maxBottlesDrunk(numBottles, numExchange));
    }
    public static int maxBottlesDrunk(int numBottles, int numExchange) {
        int sum = numBottles;
        int remain = numBottles;
        while (remain >= numExchange) {
            remain-=numExchange;
            remain++;
            sum++;
            numExchange++;
            }
        return sum;

    }
}
