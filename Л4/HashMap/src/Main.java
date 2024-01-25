import myHash.HashTable;

import java.io.IOException;
import java.util.HashMap;
import java.util.Random;

public class Main {
    public static void main(String[] args) throws IOException {

       HashTable table = new HashTable();

         liteTest(table);

    }
    public static void testKeys(HashTable j) {

        try {

            Random random = new Random();

            for (int i = 0; i < 2000; i++) {
                StringBuilder stringBuilder = new StringBuilder();
                char firstChar = (char) (random.nextInt(26) + 'A');
                char secondChar = (char) (random.nextInt(26) + 'A');
                int number = random.nextInt(10000);
                String formattedNumber = String.format("%04d", number);


                stringBuilder.append(firstChar)
                        .append(formattedNumber)
                        .append(secondChar);

                j.put(stringBuilder.toString());

                String generatedStrings = stringBuilder.toString();
                System.out.println(generatedStrings);
            }
            j.printToFile();
            System.out.println("Test");

        } catch (Exception e) {
            System.out.println("ERROR " +e.getStackTrace());
        }
    }
    public static void liteTest(HashTable table) throws IOException {
        // tests актуальны для 2000

        table.put("A0001A");
        table.put("A2001A");
        table.put("A2000A");
        table.put("A2000A");
        table.put("A2002A");
        System.out.println(table.get("A2000A")); //test на получение с index = 131, где уже есть запись
        System.out.println(table.getSegment(133)); //test получение сигмента 133;
        table.remove("A2000A");// test бакет с ключем находиться в 133 - но у нас есть занятая ячейка в 134 которая по хешу занимать должна 133 - она встрает на место 133
        testKeys(table); // test на рехеш
        table.printTable();
    }
}