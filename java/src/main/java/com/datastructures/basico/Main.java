package com.datastructures.basico;

public class Main {
	public static void main(String[] args) {
		passagemPorValor();
		passagemPorReferencia();
	}

	/**
	 * Na passagem por valor a variável recebe literalmente aquele valor que é
	 * alocado em algum espaço na memória, logo, quando a variável troca de valor,
	 * não é refretida na demais.
	 */
	public static void passagemPorValor() {
		String a = new String("AAAA");
		String b = a;
		System.out.println("==================================");
		System.out.println("------- Passagem por valor -------");
		System.out.println("A = \"AAAA\". B = A:");
		System.out.println("A= " + a + " B= " + b + ".\n");
		System.out.println("Alterado o valor de A. A = \"BBBB\":");
		a = "BBBB";
		System.out.println("A= " + a + " B= " + b + ".");
		System.out.println("==================================\n");
	}

	/**
	 * Na passagem de valor por refeência o valor atribuído passa o endereço da
	 * memoria onde o valor está alocado, sendo assim, quando o valor sofre
	 * alteração reflete em ambas as variáveis.
	 */
	public static void passagemPorReferencia() {
		Objeto<String> a = new Objeto<>("AAA");
		Objeto<String> b = a;

		System.out.println("==================================");
		System.out.println("---- Passagem por referência -----");
		System.out.println("A = \"AAAA\". B = A:");
		System.out.println("A= " + a.getValor() + " B= " + b.getValor() + ".\n");
		System.out.println("Alterado o valor de A. A = \"BBBB\":");
		a.setValor("BBBB");
		System.out.println("A= " + a.getValor() + " B= " + b.getValor() + ".");
		System.out.println("==================================");
	}

}
