package com.datastructures.set;

import java.util.Objects;

public class Car implements Comparable<Car> {
    private String brand;

    public Car(String brand) {
        this.brand = brand;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    @Override
    public int compareTo(Car other) {
        return this.brand.compareTo(other.getBrand());
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Car)) return false;
        return Objects.equals(brand, ((Car) o).brand);
    }

    @Override
    public int hashCode() {
        return Objects.hash(brand);
    }

    @Override
    public String toString() {
        return "Car{brand='" + brand + "'}";
    }
}
