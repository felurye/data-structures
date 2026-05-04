package com.datastructures.no;

public class Main {

	public static void main(String[] args) {
		No<String> no1 = new No<>("Primeiro");
		No<String> no2 = new No<>("Segundo");
		no1.setProximoNo(no2);
		No<String> no3 = new No<>("Terceiro");
		no2.setProximoNo(no3);

		System.out.println(no1.toString());
	}
}
