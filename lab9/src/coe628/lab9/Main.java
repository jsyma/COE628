/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package coe628.lab9;

/**
 *
 * @author jsma
 */
public class Main {
    private static final int num_Philos = 5;
    
    public static void main(String[] args){
        Semaphore[] forks = new Semaphore[num_Philos];
        Philosopher[] philosophers = new Philosopher[num_Philos];
        for(int i = 0; i < num_Philos; i++){
            forks[i] = new Semaphore(0);
        }
        for(int i = 0; i < num_Philos; i++){
            philosophers[i] = new Philosopher(i, forks[i], forks[(i + 1) % num_Philos]);
            new Thread(philosophers[i]).start();
        }
    }
}
