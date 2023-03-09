/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package coe628.lab7;

/**
 *
 * @author jsma
 */
/**
 * A Thread that increments a counter by 1, 2, 3, ... n.
 * 
 */
public class CounterThread extends Thread {

    Counter counter;
    int n = 0;

    public CounterThread(Counter counter, int n) {
        this.counter = counter;
        this.n = n;
    }

    @Override
    public void run() {
        for (int i = 0; i < n; i++) {
            counter.add(i);
        }
    }
}



