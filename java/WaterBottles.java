public class WaterBottles {
    public static void main(String[] args) {
        int numBottles =9;
        int numExchange = 3;
        System.out.println(numWaterBottles(numBottles, numExchange));

    }
    public static int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
}
