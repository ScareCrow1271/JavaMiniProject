package RockPaperScissors;

import java.util.Random;
import java.util.Scanner;

public class RockPaperScissors {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random random = new Random();
        int random_number = random.nextInt(3);

        System.out.println("0. rock");
        System.out.println("1. paper");
        System.out.println("2. scissor");
        System.out.print("Give your try: ");
        int user_number = sc.nextInt();

        if(user_number==0) {
            System.out.println("You Choose Rock");
        }
        else if(user_number==1) {
            System.out.println("You Choose Paper");
        }
        else if(user_number==2) {
            System.out.println("You Choose Scissor");
        }

        if(user_number==0) {
            if(random_number==0) {
                System.out.println("Computer choose rock");
                System.out.println("it is a draw!!!");
            }
            else if(random_number==1) {
                System.out.println("Computer choose paper");
                System.out.println("Defeat!!!");
            }
            else if(random_number==2) {
                System.out.println("Computer choose scissor");
                System.out.println("Victory!!!");
            }
        }
        else if (user_number==1) {
            if(random_number==0) {
                System.out.println("Computer choose rock");
                System.out.println("Victory!!!");
            }
            else if (random_number==1) {
                System.out.println("Computer choose paper");
                System.out.println("it is a draw!!!");
            }
            else if(random_number==2) {
                System.out.println("Computer choose scissor");
                System.out.println("Defeat");
            }
        }
        else if(user_number==2) {
            if(random_number==0) {
                System.out.println("Computer choose rock");
                System.out.println("Defeat");
            }
            else if(random_number==1) {
                System.out.println("Computer choose paper");
                System.out.println("Victory");
            }
            else if(random_number==2) {
                System.out.println("Computer choose scissor");
                System.out.println("it is a draw!!!");
            }
        }

    }
}
