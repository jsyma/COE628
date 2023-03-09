/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package coe628.lab7;

/**
 *
 * @author jsma
 */
/** Maintains a count. */
public class Counter {
    int count = 0;
    /**
     * Add value to count.
     * @param value int to add to count
     */
    public synchronized void add(int value) {
        this.count += value;
        try {
            Thread.sleep(10);
        } catch (InterruptedException ex) {
            System.err.println("Should not get here!" + ex);
        }
    }
}

