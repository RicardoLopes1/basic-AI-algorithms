import java.util.Hashtable;
import java.util.Vector;

public class TableDrivenAgent extends Agent {
    
    // attributes
    Hashtable<Vector<Perception>, String> table = new Hashtable<Vector<Perception>, String>();
    Vector<Perception> perceptionList = new Vector<Perception>();

    // methods
    public String act(Perception per){
        perceptionList.add(per);
        return table.get(perceptionList);
    }

    public void constructTable(){
        Vector<Perception> pList = new Vector<>();
        Perception pa = new Perception(true, false);
        Perception pb = new Perception(false, false);
        /* build the table by hand */
        pList.add(pa); // line 1
        table.put(pList, "right" );

        pa.setIsDirty(true); // line 2
        pList.set(0, pa);
        table.put(pList, "aspire" );

        pList.set(0, pb); // line 3
        table.put(pList, "left" );

        pb.setIsDirty(true); // line 4
        pList.set(0, pb);
        table.put(pList, "aspire" );

        pa.setIsDirty(false); // line 5
        pb.setIsDirty(false);
        pList.set(0, pa);
        pList.add(pb);
        table.put(pList, "stop" );
        /* ... */
    }
}
