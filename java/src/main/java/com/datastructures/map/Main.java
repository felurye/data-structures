package com.datastructures.map;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Map<String, String> student1 = new HashMap<>();
        student1.put("name", "João");
        student1.put("age", "17");
        student1.put("grade", "8.5");
        student1.put("class", "3A");

        System.out.println(student1);
        System.out.println("keys: " + student1.keySet());
        System.out.println("name: " + student1.get("name"));
        System.out.println("contains key 'grade': " + student1.containsKey("grade"));

        Map<String, String> student2 = new HashMap<>();
        student2.put("name", "Maria");
        student2.put("age", "18");
        student2.put("grade", "9.2");
        student2.put("class", "3B");

        List<Map<String, String>> students = new ArrayList<>();
        students.add(student1);
        students.add(student2);

        System.out.println("\nStudents:");
        for (Map<String, String> student : students) {
            System.out.println(student.get("name") + " - grade: " + student.get("grade"));
        }
    }
}
