package myHash.buket;

public class Buket {

    private String key;
    private String data;


    private int collision = 0;

    @Override
    public String toString() {
        return "Buket{" +
                "key='" + key + '\'' +
                ", data='" + data + '\'' +
                ", collision=" + collision +
                '}';
    }

    public Buket(String key) {
        this.key = key;
        this.data = key;
    }

    public String getData() {
        return data;
    }

    public String getKey() {
        return key;
    }

    public int getCollision() {
        return collision;
    }

    public void addCollision() {
        this.collision++;
    }
}
