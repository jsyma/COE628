/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package coe628.lab9;
import java.util.Random;
/**
 *
 * @author jsma
 */
public class Philosopher implements Runnable{
    private Random ran = new Random();
    private static int numCompleted = 0;
    private int semaphoreID;
    private Semaphore leftFork;
    private Semaphore rightFork;
    
    public Philosopher(int id, Semaphore leftFork, Semaphore rightFork){
        semaphoreID = id;
        this.leftFork = leftFork;
        this.rightFork = rightFork;
    }
    
    private void think() throws InterruptedException{
        System.out.flush();
        Thread.sleep(ran.nextInt(10));
    }
    
    private void get_left_fork(){
        leftFork.up();
        System.out.println("Fork  " + (semaphoreID % 5 + 1) + " taken by Philosopher" + semaphoreID + "\n");
        System.out.flush();
    }
    
    private void get_right_fork(){
        rightFork.up();
        System.out.println("Fork  " + ((semaphoreID + 1) % 5 + 1) + " taken by Philosopher" + semaphoreID + "\n");
    }
    
    private void eat() throws InterruptedException{
        System.out.println("Philosopher " + semaphoreID + " is eating.\n");
        System.out.flush();

    }
    
    private void put_left_fork() throws InterruptedException{
        leftFork.down();
    }
    
    private void put_right_fork() throws InterruptedException{
        rightFork.down();
    }
    
    private static synchronized void incrementCompleted(){
        numCompleted++;
        System.out.println("Till now num of philosophers completed dinner are " + numCompleted + "\n");
        if(numCompleted > 10){ //can change this, assumes completed dinners is 11
            System.exit(0); 
        }
    }
    
    @Override
    public void run(){
        try{
            while(true){
                think();
                get_left_fork();
                get_right_fork();
                eat();
                put_left_fork();
                put_right_fork();
                System.out.println("Philosopher " + semaphoreID + " is waiting for Fork " + (semaphoreID % 5 + 1) + "\n");
                incrementCompleted();
            }
        }
        catch(InterruptedException ex){
            System.out.println("Philosopher" + semaphoreID + "was interrupted.\n");
        }
    }
}
