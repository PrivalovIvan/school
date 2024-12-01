package domain.room;

import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.ArrayList;
import java.util.List;

@Data
public class Room {
    private int width, height;
    private boolean hasTreasure;
    private int countTreasure;
    private boolean hasFood;
    private int countFood;
    private boolean hasEnemy;
    private int countEnemies;
    private int startX, startY;
    private int randomX, randomY;
    private int[][] doors;
    private List<int[]> treasureXY = new ArrayList<>();
    private List<int[]> foodXY = new ArrayList<>();
    private List<int[]> enemiesXY = new ArrayList<>();

    private Room(RoomBuilder builder) {
        this.hasTreasure = builder.hasTreasure;
        this.width = builder.width;
        this.height = builder.height;
        this.startX = builder.startX;
        this.startY = builder.startY;
        this.randomX = builder.randomDistanceX;
        this.randomY = builder.randomDistanceY;
        this.doors = builder.doors;
        this.countTreasure = builder.countTreasure;
        this.hasFood = builder.hasFood;
        this.countFood = builder.countFood;
        this.hasEnemy = builder.hasEnemy;
        this.countEnemies = builder.countEnemies;
    }

    @Data
    @NoArgsConstructor
    public static class RoomBuilder {
        private int width, height;
        private int startX, startY;
        private int randomDistanceX, randomDistanceY;
        private int[][] doors;
        /*          door1[0]
         *           ┌┐ door2[1]
         *  door4[3] └┘
         *          door3[2]
         * */
        private boolean hasTreasure;
        private int countTreasure;
        private boolean hasFood;
        private int countFood;
        private boolean hasEnemy;
        private int countEnemies;

        public RoomBuilder setWidth(int width) {
            this.width = width;
            return this;
        }

        public RoomBuilder setHeight(int height) {
            this.height = height;
            return this;
        }

        public RoomBuilder setHasTreasure(boolean hasTreasure) {
            this.hasTreasure = hasTreasure;
            return this;
        }

        public RoomBuilder setStartX(int startX) {
            this.startX = startX;
            return this;
        }

        public RoomBuilder setStartY(int startY) {
            this.startY = startY;
            return this;
        }

        public RoomBuilder setRandomDistanceX(int randomDistanceX) {
            this.randomDistanceX = randomDistanceX;
            return this;
        }

        public RoomBuilder setRandomDistanceY(int randomDistanceY) {
            this.randomDistanceY = randomDistanceY;
            return this;
        }

        public RoomBuilder setDoors(int[][] doors) {
            this.doors = doors;
            return this;
        }

        public RoomBuilder setCountTreasure(int countTreasure) {
            this.countTreasure = countTreasure;
            return this;
        }

        public RoomBuilder setHasFood(boolean hasFood) {
            this.hasFood = hasFood;
            return this;
        }

        public RoomBuilder setCountFood(int countFood) {
            this.countFood = countFood;
            return this;
        }

        public RoomBuilder setHasEnemy(boolean hasEnemy) {
            this.hasEnemy = hasEnemy;
            return this;
        }

        public RoomBuilder setCountEnemies(int countEnemies) {
            this.countEnemies = countEnemies;
            return this;
        }

        public Room build() {
            return new Room(this);
        }
    }
}

