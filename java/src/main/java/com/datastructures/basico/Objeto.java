package com.datastructures.basico;

public class Objeto<T> {

	T valor;

	public Objeto(T t) {
		this.valor = t;
	}

	public T getValor() {
		return valor;
	}

	public void setValor(T valor) {
		this.valor = valor;
	}
}
