package presentation;

import domain.room.Room;
import domain.room.RoomManager;

public class FogWar {
    private final FieldChars.TileVisibility[][] visibilityMap;
    private final int width;
    private final int height;
    private static final int VIEW_RANGE = 8;
    private final RoomManager roomManager;

    public FogWar(int width, int height, RoomManager roomManager) {
        this.width = width;
        this.height = height;
        this.visibilityMap = new FieldChars.TileVisibility[width][height];
        this.roomManager = roomManager;
        initializeMap();
    }

    private void initializeMap() {
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                visibilityMap[x][y] = FieldChars.TileVisibility.UNKNOWN;
            }
        }
    }

    public void updateVisibility(int playerX, int playerY, char[][] gameField) {
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                if (visibilityMap[x][y] == FieldChars.TileVisibility.VISIBLE) {
                    visibilityMap[x][y] = FieldChars.TileVisibility.REMEMBERED;
                }
            }
        }
        for (var r : roomManager.getRooms()) {
            if (isRoomContainsPlayer(playerX, playerY, r)) {
                for (int x = r.getStartX() + r.getRandomX(); x < r.getStartX() + r.getWidth() + r.getRandomX(); x++) {
                    for (int y = r.getStartY() + r.getRandomY(); y < r.getHeight() + r.getStartY() + r.getRandomY(); y++) {
                        visibilityMap[x][y] = FieldChars.TileVisibility.VISIBLE;
                    }
                }
            }
        }
        for (int angle = 0; angle < 360; angle += 2) {
            castRay(playerX, playerY, angle, gameField);
        }
    }

    private void castRay(int startX, int startY, int angle, char[][] gameField) {
        double radians = Math.toRadians(angle);
        double cos = Math.cos(radians);
        double sin = Math.sin(radians);
        double x = startX;
        double y = startY;
        for (int distance = 0; distance < VIEW_RANGE; distance++) {
            int currentX = (int) Math.round(x);
            int currentY = (int) Math.round(y);
            if (currentX < 0 || currentX >= width || currentY < 0 || currentY >= height) {
                break;
            }
            visibilityMap[currentX][currentY] = FieldChars.TileVisibility.VISIBLE;
            if (isWall(gameField[currentX][currentY])) {
                break;
            }
            x += cos;
            y += sin;
        }
    }

    private boolean isRoomContainsPlayer(int playerX, int playerY, Room r) {
        boolean isInXRange = playerX >= r.getStartX() + r.getRandomX() && playerX < r.getStartX() + r.getWidth() + r.getRandomX();
        boolean isInYRange = playerY >= r.getStartY() + r.getRandomY() && playerY < r.getHeight() + r.getStartY() + r.getRandomY();
        return isInXRange && isInYRange;
    }

    public boolean isWall(char tile) {
        return tile == FieldChars.WALL_HORIZONTAL ||
                tile == FieldChars.WALL_VERTICAL ||
                tile == FieldChars.WALL_CORNER_TOP_RIGHT ||
                tile == FieldChars.WALL_CORNER_BOTTOM_RIGHT ||
                tile == FieldChars.WALL_CORNER_BOTTOM_LEFT ||
                tile == FieldChars.WALL_CORNER_TOP_LEFT ||
                tile == 0;
    }

    public FieldChars.TileVisibility getVisibility(int x, int y) {
        return visibilityMap[x][y];
    }
}
