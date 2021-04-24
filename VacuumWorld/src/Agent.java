public class Agent {

    // Attributes
    private boolean locationSensor;
    private boolean dirtySensor;

    // Methods
    // receives an environment object and returns its perception of the environment.
    public Perception perceives(Environment env){
        this.locationSensor = env.getAgentLocation();
        this.dirtySensor = env.getRoomSituation(locationSensor);
        return new Perception(locationSensor, dirtySensor);
    }
    // receives a perception of the environment and returns an action.
    public String act(Perception per){
        return "";
    }


}
