package com.datastructures.binaryTree.model;

import java.util.Objects;

public class IntValue extends ComparableValue<IntValue> {
    private Integer value;

    public IntValue(Integer value) {
        this.value = value;
    }

    public Integer getValue() {
        return value;
    }

    @Override
    public int compareTo(IntValue other) {
        return Integer.compare(this.value, other.value);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof IntValue)) return false;
        return Objects.equals(value, ((IntValue) o).value);
    }

    @Override
    public int hashCode() {
        return Objects.hash(value);
    }

    @Override
    public String toString() {
        return value.toString();
    }
}
