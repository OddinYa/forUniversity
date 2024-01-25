package myHash;

import myHash.buket.Buket;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class HashTable {


    String filePath = "output.csv";
    private int length = 16;
    private Buket table[] = new Buket[length];
    private int capacity = 0;
    private BufferedWriter writer;
    

    public HashTable() throws IOException {
        try {

            writer = new BufferedWriter(new FileWriter(filePath));

            writer.write("Сollision,Segments");
            writer.newLine();

        } catch (IOException e) {
            System.out.println("Ошибка при записи в файл: " + e.getMessage());
        }
    }

    public void put(String key) throws IOException {
        boolean flagColl = false;
        if (!itsKey(key)) {
            System.out.println("Ключ не соответствует шаблону \"БццццБ\"");
        } else {
            int index = hashCode(key);

            if (table[index] == null) {
                table[index] = new Buket(key);
                capacity++;
            } else if (containsKey(key)) {

            } else {
                int temp = index;
                if (table[temp] != null) {
                    table[temp].addCollision();
                }
                while (table[index] != null) {

                    if (flagColl) {
                        if (table[temp] != null) {
                            table[temp].addCollision();
                        }
                    }
                    index++;
                    temp = index;
                    if (index == length - 1) {
                        index = 0;
                    }
                    flagColl = true;
                }
                table[temp] = new Buket(key);
                capacity++;
            }
            if (capacity > length * 0.8) {
                reHashTable();
            }


        }
    }

    private void reHashTable() throws IOException {
        this.length = length*3;
        this.capacity = 0;
        Buket temp[] = table;
        table = new Buket[this.length];
        for (Buket b : temp) {
            if (b != null) {
                put(b.getKey());
            }
        }

    }

    public void printToFile() throws IOException {

        int index = 0;
        while (index != length - 1) {
            if (table[index] != null) {
                writer.write(table[index].getCollision() + "," + index);
                writer.newLine();
            } else {
                writer.write("" + "," + index);
                writer.newLine();
            }
            index++;
        }
        writer.close();
    }

    private int hashCode(String key) {
        StringBuilder stringBuilder = new StringBuilder();
        int first = key.charAt(0);     // 100

        int last = key.charAt(5);   // 233
        String sub = key.substring(1, 5); //2330

        stringBuilder.append(first);  // 100
        stringBuilder.append(sub);   // 1002330


        int hash = Integer.parseInt(stringBuilder.toString())+last; // 1002330 + 233 // 1002563

        return hash % (length - 1);    //  1002563 % 15 = 13
    }

    private boolean itsKey(String key) {

        String pattern = "[A-Z]\\d{4}[A-Z]";

        Pattern regex = Pattern.compile(pattern);
        Matcher matcher = regex.matcher(key);

        return matcher.matches();
    }

    public void printTable() {
        for (int i = 0; i < length; i++) {
            if (table[i] == null) {
                System.out.println(i + " " + "NULL");
            } else {
                System.out.println(i + " " + table[i].toString());
            }
        }
    }

    public String get(String key) {
        if (containsKey(key)) {

            int index = hashCode(key);
            if (table[index].getKey() != key) {

                while (table[index].getKey() != key) {

                    index++;
                    if (index == length - 1) {
                        index = 0;
                    }
                }
                return table[index].getData();

            } else return table[index].getData();

        } else {
            return null;
        }
    }

    public boolean containsKey(String key) {

        int startIndex = hashCode(key);
        int counter = 0;
        if (table[startIndex] == null) {
            return false;
        } else {
            while (key != table[startIndex].getKey()) {
                startIndex++;
                counter++;
                if (startIndex == length - 1) {
                    startIndex = 0;
                }
                if (counter == length * 1.5) {
                    return false;
                }
                if (table[startIndex] == null) {
                    return false;
                }
            }
            return true;
        }
    }

    public void remove(String key) {

        int deleteIndex = hashCode(key);

        if (table[deleteIndex] == null) {
            return;
        }
        while (key != table[deleteIndex].getKey()) {
            deleteIndex++;

            if (deleteIndex == length - 1) {
                deleteIndex = 0;
            }
        }

        int temp = deleteIndex;

        while (hashCode(table[temp].getKey()) < deleteIndex) {
            temp++;
            if (temp == length - 1) {
                temp = 0;
            }
        }
        table[deleteIndex] = table[temp];
        table[temp] = null;
    }

    public String getSegment(int segment) {
        if (segment > length) {
            return null;
        }
        if (table[segment] == null) {
            return null;
        } else return table[segment].getData();
    }

}
