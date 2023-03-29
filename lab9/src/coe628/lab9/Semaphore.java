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
public class Semaphore {
    private int value;
    
    public Semaphore(int value){
        this.value = value;
    }
    
    public synchronized void up(){
        this.value++;
        this.notify();
    }
    
    public synchronized void down() throws InterruptedException{
        while(this.value == 0){
            wait();
        }
        this.value--;
    }
}
