public class Sample {
    enum Direction { NORTH, SOUTH, EAST, WEST }

    public static void main(String[] args) {
        Direction direction = Direction.EAST;
        switch (direction) {
            case NORTH:
                System.out.println("N");
                break;
            case SOUTH:
                System.out.println("S");
                break;
            case WEST:
                System.out.println("W");
                break;
            case EAST:
                System.out.println("E");
                break;
        }
    }
}
