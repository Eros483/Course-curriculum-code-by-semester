import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.Scanner;
import java.util.Collections;
import java.util.Iterator;
import java.util.Map;
import java.util.HashMap;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;

public class q {
    public static void main(String[] args) {
        Analyzer a = new Analyzer();
        a.getReservedWords();
        a.getInputTextString();

        a.separateInputTextString();
        a.separateReservedWords();

        // textStringWords: original user input
        // reservedWords: original user reserved words input

        ArrayList<String> uniqueWords = Analyzer.removeDuplicates(a.textStringWords); // uniqueWords
        System.out.println("1.a) The unique words in the input in the order they appeared in the input String:\n");
        Analyzer.printArrayList(uniqueWords);

        ArrayList<String> uniqueWordsSortedLexo = Analyzer.sortStringsL(uniqueWords); // uniqueWords sorted lexicographically
        System.out.println("1.b) The unique words in the input in the alphabetical order:\n");
        Analyzer.printArrayList(uniqueWordsSortedLexo);

        ArrayList<String> uniqueWordsSortedLengthWise = Analyzer.ascendingArrayList(uniqueWords); // uniqueWords sorted lengthWise
        System.out.println("1.c) The unique words arranged on the basis of length:\n");
        Analyzer.printArrayList(uniqueWordsSortedLengthWise);

        ArrayList<String> increasingFrequencySort = Analyzer.sortFrequency(a.textStringWords);
        System.out.println("1.d) The unique words in the input in the order of frequency:\n"); //input words sorted by frequency
        Analyzer.printArrayList(increasingFrequencySort);

        System.out.println("2. The count of the words in the input text that start with each letter of the alphabet:\n"); //number of words beginning with each letter
        Analyzer.countWordsStartingWithLetters(a.textStringWords);

        ArrayList<String> inputOccurencesReserved=Analyzer.inputInReserved(a.textStringWords, a.reservedWords); //first instance of reserved in input
        System.out.println("\n3.a) The reserved occurences in the input words in order:\n");
        Analyzer.printArrayList(inputOccurencesReserved);

        ArrayList<String> reservedFreqInInputs=Analyzer.reservedFreqInInput(a.textStringWords, a.reservedWords); //freq of reserved words in input
        System.out.println("\n3.b) The reserved occurences in the input words in order:\n");
        Analyzer.printArrayList(reservedFreqInInputs);
    }
}

class Analyzer {
    public String inputTextString; // end returns textStringWords
    public String inputReservedWords; // end returns reservedWords
    ArrayList<String> textStringWords = new ArrayList<>();
    ArrayList<String> reservedWords = new ArrayList<>();

    Scanner s = new Scanner(System.in);

    // Clean the input string by removing symbols directly while scanning
    public String getInputTextString() {
        System.out.print("Enter text string: ");
        // Convert input to lowercase
        inputTextString = s.nextLine().replaceAll("[^a-zA-Z0-9 ]", "").toLowerCase(); // Remove all non-alphanumeric characters except space
        return inputTextString;

        s.nextLine()
    }

    public String getReservedWords() {
        System.out.print("Enter reserved words: ");
        // Convert input to lowercase
        inputReservedWords = s.nextLine().replaceAll("[^a-zA-Z0-9 ]", "").toLowerCase(); // Remove all non-alphanumeric characters except space
        return inputReservedWords;
    }

    public ArrayList<String> separateInputTextString() {
        String[] inputWordsSeparator = this.inputTextString.split(" ");
        for (String word : inputWordsSeparator) {
            if (!word.isEmpty()) {
                textStringWords.add(word);
            }
        }
        return textStringWords;
    }

    public ArrayList<String> separateReservedWords() {
        String[] reservedWordsSeparator = this.inputReservedWords.split(" "); //seperating input into seperate strings
        for (String word : reservedWordsSeparator) {
            if (!word.isEmpty()) {
                reservedWords.add(word);
            }
        }
        return reservedWords;
    }

    public static ArrayList<String> removeDuplicates(ArrayList<String> list) {
        LinkedHashSet<String> set = new LinkedHashSet<>(list); //preserving insertion order
        return new ArrayList<>(set);
    }

    public static ArrayList<String> sortStringsL(ArrayList<String> list) {
        Collections.sort(list); //basic stable sorting
        return list;
    }

    public static void printArrayList(ArrayList<String > list) {
        for (String word : list) {
            System.out.print(word + " ");
        }
        System.out.println("\n\n");
    }

    public static ArrayList<String> ascendingArrayList(ArrayList<String> list) {
        list.sort((s1, s2) -> Integer.compare(s1.length(), s2.length()));
        return list;
    }

    public static ArrayList<String> sortFrequency(ArrayList<String> words) {
        // Step 1: Count frequencies
        Map<String, Integer> frequencyMap = new HashMap<>();
        for (String word : words) {
            frequencyMap.put(word, frequencyMap.getOrDefault(word, 0) + 1);
        }

        // Step 2: Create a list of unique words while preserving original order
        ArrayList<String> uniqueWords = new ArrayList<>(new LinkedHashSet<>(words));

        // Step 3: Sort the list by frequency, maintaining original order for ties
        Collections.sort(uniqueWords, (word1, word2) -> {
            int freq1 = frequencyMap.get(word1);
            int freq2 = frequencyMap.get(word2);
            // Compare frequencies
            if (freq1 != freq2) {
                return Integer.compare(freq1, freq2);
            }
            // If frequencies are the same, maintain original order
            return Integer.compare(words.indexOf(word1), words.indexOf(word2));
        });

        return uniqueWords;
    }

    public static void countWordsStartingWithLetters(ArrayList<String> words) {
        // Initialize an array to hold counts for each letter (A-Z)
        int[] counts = new int[26];

        // Iterate through each word in the input list
        for (String word : words) {
            // Check if the word is not empty
            if (!word.isEmpty()) {
                // Get the first character of the word
                char firstChar = Character.toLowerCase(word.charAt(0));
                // Check if the character is a letter between 'a' and 'z'
                if (firstChar >= 'a' && firstChar <= 'z') {
                    // Increment the count for the corresponding letter
                    counts[firstChar - 'a']++;
                }
            }
        }

        // Print the counts for each letter
        for (int i = 0; i < counts.length; i++) {
            char letter = (char) (i + 'a');
            System.out.println(letter + ": " + counts[i]);
        }
    }

    public static ArrayList<String> inputInReserved(ArrayList<String> input, ArrayList<String> reserved) {
        // Create a HashSet to track printed words
        HashSet<String> printedWords = new HashSet<>();
        ArrayList<String> foundReservedWords = new ArrayList<>();

        // Iterate through the input ArrayList
        for (String word : input) {
            // Check if the word exists in the reserved ArrayList and hasn't been printed yet
            if (reserved.contains(word) && !printedWords.contains(word)) {
                // Add the word to the printedWords set
                printedWords.add(word);
                foundReservedWords.add(word);
            }
        }

        return foundReservedWords;
    }

    public static ArrayList<String> reservedFreqInInput(ArrayList<String> input, ArrayList<String> reserved) {
        // Step 1: Count frequency of each word in input
        Map<String, Integer> frequencyMap = new HashMap<>();
        for (String word : input) {
            frequencyMap.put(word, frequencyMap.getOrDefault(word, 0) + 1);
        }

        // Step 2: Create a list to hold reserved words and their frequencies
        List<Map.Entry<String, Integer>> reservedWordsWithFrequency = new ArrayList<>();
        for (String word : reserved) {
            if (frequencyMap.containsKey(word)) {
                reservedWordsWithFrequency.add(Map.entry(word, frequencyMap.get(word)));
            }
        }

        // Step 3: Sort the list by frequency in descending order, maintaining original order for ties
        reservedWordsWithFrequency.sort((entry1, entry2) -> {
            int frequencyComparison = entry2.getValue().compareTo(entry1.getValue());
            if (frequencyComparison == 0) {
                // If frequencies are equal, maintain original order (stable sort)
                return 0; // Return 0 to indicate they are equal
            }
            return frequencyComparison; // Otherwise, sort by frequency
        });

        // Step 4: Create the result list with sorted reserved words
        ArrayList<String> result = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : reservedWordsWithFrequency) {
            result.add(entry.getKey());
        }

        return result;
    }
}