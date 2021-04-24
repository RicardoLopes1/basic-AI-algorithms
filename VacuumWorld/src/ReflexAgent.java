public class ReflexAgent extends Agent {
    
    // receives a perception of the environment and returns an action.
    public String act(Perception per){
        if(per.getIsDirty())
            return "aspire";
        else{
            if(per.getLocation())
                return "right";
            return "left";
        }

    }
}
