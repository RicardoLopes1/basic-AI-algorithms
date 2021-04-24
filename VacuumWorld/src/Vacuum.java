//
import java.util.*;

public class Vacuum {
    public static void main(String[] args) {
        /* The action taken by the agent
           The situation of the environment after such action has been carried out.
        * */
        Scanner scan = new Scanner(System.in);
        String opc; // go to...
        boolean envA, envB, agentLocation, next;
        System.out.println("How is the environment?");
        System.out.println("Environment A is dirty? (true or false):");
        envA = scan.nextBoolean();

        System.out.println("Environment B is dirty? (true or false):");
        envB = scan.nextBoolean();

        System.out.println("Is the agent's location environment A? (true or false):");
        agentLocation = scan.nextBoolean();

        Environment env = new Environment(envA, envB, agentLocation);
        System.out.println(env.toString());
        ReflexAgent reflexAgent = new ReflexAgent();
        Perception per; // = reflexAgent.perceives(env);
        
        while (true){
            next = false;
            per = reflexAgent.perceives(env);
            opc = reflexAgent.act(per);
            env.update(opc);
            System.out.println(env.toString());
            
            while(!next){
                System.out.println("Next step? (true or false):");
                next = scan.nextBoolean();
                System.out.println("");
            }

        }
    }
}
