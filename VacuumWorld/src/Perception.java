public class Perception {
    public Perception(boolean pLocation, boolean pIsDirty){
        this.location = pLocation;
        this.isDirty = pIsDirty;
    }

    // Attributes
    private boolean location; // if true, then agent is in room A, else room B.
    private boolean isDirty;// if current room is dirty

    // gets and sets
    public boolean getLocation() {
        return this.location;
    }

    public void setLocation(boolean location) {
        this.location = location;
    }

    public boolean getIsDirty() {
        return this.isDirty;
    }

    public void setIsDirty(boolean dirty) {
        this.isDirty = dirty;
    }
}
