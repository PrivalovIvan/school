package presentation;

public class FieldChars {
    public enum TileVisibility {
        UNKNOWN,
        REMEMBERED,
        VISIBLE
    }

    ;
    public static final char WALL_HORIZONTAL = '─';
    public static final char WALL_VERTICAL = '│';
    public static final char WALL_CORNER_TOP_RIGHT = '┐';
    public static final char WALL_CORNER_TOP_LEFT = '┌';
    public static final char WALL_CORNER_BOTTOM_RIGHT = '┘';
    public static final char WALL_CORNER_BOTTOM_LEFT = '└';
    public static final char FLOOR = '·';
    public static final char CORRIDOR = '#';
    public static final char DOOR = '+';
    public static final char PLAYER = '@';
    public static final char EXIT = '<';
    public static final char DEFAULT = ' ';
}
