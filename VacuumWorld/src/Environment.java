import java.util.*;
public class Environment {
    public Environment(boolean pIsDirtyA, boolean pIsDirtyB, boolean pAgentLocation){
        this.isDirtyA = pIsDirtyA;
        this.isDirtyB = pIsDirtyB;
        this.agentLocation = pAgentLocation;
    }

    // Attributes
    private boolean isDirtyA;
    private boolean isDirtyB;
    private boolean agentLocation; // if true, then agent is in room A, else room B.

    // returns if a give room is dirty or not
    public boolean getRoomSituation(boolean room){
        if(room)
            return isDirtyA;

        return isDirtyB;
    }

    public void update(String action){
        
        switch (action){
            case "right":
                if(agentLocation){
                    agentLocation = false;
                    System.out.println("Moved to the right (room B).");
                }
                break;

            case "left":
                if(!agentLocation){
                    agentLocation = true;
                    System.out.println("Moved to the left (room A).");
                }
                break;

            case "aspire":
                if(agentLocation){
                    isDirtyA = false;
                    System.out.println("Aspire... Env. A is clean.");
                }else{
                    isDirtyB = false;
                    System.out.println("Aspire... Env. B is clean.");
                }
                break;

            default:
                System.out.println("Error!");

        }
        
    }
    
    // gets and sets
    public boolean getIsDirtyA() {
        return isDirtyA;
    }

    public void setIsDirtyA(boolean dirtyA) {
        isDirtyA = dirtyA;
    }

    public boolean getIsDirtyB() {
        return isDirtyB;
    }

    public void setIsDirtyB(boolean dirtyB) {
        isDirtyB = dirtyB;
    }

    public boolean getAgentLocation() {
        return agentLocation;
    }

    public void setAgentLocation(boolean agentLocation) {
        this.agentLocation = agentLocation;
    }

    @Override
    public String toString() {
        String location = agentLocation ? "room A" : "room B"; 
        
        return "Environment{" +
                "isDirtyA = " + isDirtyA +
                ", isDirtyB = " + isDirtyB +
                ", agentLocation = " + location +
                '}';
    }
}
